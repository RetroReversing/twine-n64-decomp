/* identical to __osDevMgrMain in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef struct OSMesgQueue_s OSMesgQueue;
typedef void *OSMesg;
typedef s32 OSPri;
typedef s32 OSId;
typedef struct OSThread_s OSThread;
extern void     osYieldThread(void);
extern s32      osSendMesg(OSMesgQueue *, OSMesg, s32);
extern s32      osRecvMesg(OSMesgQueue *, OSMesg *, s32);
extern void     __osSetGlobalIntMask(u32);
extern void     __osResetGlobalIntMask(u32);
extern s32 func_800A7EC0 (struct OSPiHandle_s *, u32 , u32);
extern s32 func_800A7D50 (struct OSPiHandle_s *, u32 , u32 *);

typedef struct {
    u32      errStatus;
    void    *dramAddr;
    void    *C2Addr;
    u32      sectorSize;
    u32      C1ErrNum;
    u32      C1ErrSector[4];
} __OSBlockInfo;

typedef struct {
    u32             cmdType;
    u16             transferMode;
    u16             blockNum;
    s32             sectorNum;
    u32             devAddr;
    u32             bmCtlShadow;
    u32             seqCtlShadow;
    __OSBlockInfo   block[2];
} __OSTranxInfo;

typedef struct OSPiHandle_s {
    struct OSPiHandle_s *next;
    u8                   type;
    u8                   latency;
    u8                   pageSize;
    u8                   relDuration;
    u8                   pulse;
    u8                   domain;
    u32                  baseAddress;
    u32                  speed;
    __OSTranxInfo        transferInfo;
} OSPiHandle;

typedef struct {
    u16          type;
    u8           pri;
    u8           status;
    OSMesgQueue *retQueue;
} OSIoMesgHdr;

typedef struct {
    OSIoMesgHdr  hdr;
    void        *dramAddr;
    u32          devAddr;
    u32          size;
    OSPiHandle  *piHandle;
} OSIoMesg;

typedef struct {
    s32          active;
    OSThread    *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    s32         (*dma)(s32, u32, void *, u32);
    s32         (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;

/* Register addresses and bits used by the 64DD (LeoDisk) block-transfer path. */
#define PI_STATUS_REG_ADDR   (0x04600000 + 0x10)
#define PI_STATUS_CLR_INTR   (1 << 1)
#define LEO_STATUS_REG       (0x05000000 + 0x508)
#define LEO_BM_CTL_REG       (0x05000000 + 0x510)
#define LEO_INTR_MASK       0x00100401
#define LEO_ERR_SECTOR_SKIP  29
#define LEO_BM_CTL_RESET     0x10000000
#define LEO_BM_CTL_STOP      0x01000000
#define LEO_BM_CTL_FAST      0x80000000
#define LEO_BM_STAT_BUSY     0x02000000
#define OS_MESG_TYPE_LOOPBACK  (10 + 0)
#define OS_MESG_TYPE_DMAREAD   (10 + 1)
#define OS_MESG_TYPE_DMAWRITE  (10 + 2)
#define OS_MESG_TYPE_EDMAREAD  (10 + 5)
#define OS_MESG_TYPE_EDMAWRITE (10 + 6)

/* Device manager thread: takes PI requests off the command queue. 64DD (type 2) block
   transfers run here, with retries and the access-queue handshake; everything else goes
   through the dma/edma hooks of the device manager. Replies go to each request's queue. */
/* Device manager thread: services PI requests from the command queue, running 64DD block transfers with retries and DMA/EDMA requests through the device hooks. */ void __osDevMgrMain(void* arg) {
    OSIoMesg* io_msg;
    OSMesg event_msg;
    OSMesg acs_msg;
    s32 result;
    OSDevMgr* devmgr;
    s32 retry_read = 0;

    devmgr = (OSDevMgr*)arg;
    io_msg = 0;
    result = 0;

    while (1) {
        osRecvMesg(devmgr->cmdQueue, (OSMesg)&io_msg, 1);

        if (io_msg->piHandle != 0 && io_msg->piHandle->type == 2 &&
            (io_msg->piHandle->transferInfo.cmdType == 0 ||
             io_msg->piHandle->transferInfo.cmdType == 1)) {
            __OSBlockInfo* blockInfo;
            __OSTranxInfo* info;
            info = &io_msg->piHandle->transferInfo;
            blockInfo = &info->block[info->blockNum];
            info->sectorNum = -1;

            if (info->transferMode != 3) {
                blockInfo->dramAddr = (void*)((u32)blockInfo->dramAddr - blockInfo->sectorSize);
            }

            if (info->transferMode == 2 && io_msg->piHandle->transferInfo.cmdType == 0) {
                retry_read = 1;
            } else {
                retry_read = 0;
            }

            osRecvMesg(devmgr->acsQueue, &acs_msg, 1);
            __osResetGlobalIntMask(LEO_INTR_MASK);
            func_800A7EC0(io_msg->piHandle, LEO_BM_CTL_REG, (info->bmCtlShadow | LEO_BM_CTL_FAST));

        readblock1:
            osRecvMesg(devmgr->evtQueue, &event_msg, 1);
            info = &io_msg->piHandle->transferInfo;
            blockInfo = &info->block[info->blockNum];

            if (blockInfo->errStatus == LEO_ERR_SECTOR_SKIP) {
                u32 piStat;
                func_800A7EC0(io_msg->piHandle, LEO_BM_CTL_REG, info->bmCtlShadow | LEO_BM_CTL_RESET);
                func_800A7EC0(io_msg->piHandle, LEO_BM_CTL_REG, info->bmCtlShadow);
                func_800A7D50(io_msg->piHandle, LEO_STATUS_REG, &piStat);

                if (piStat & LEO_BM_STAT_BUSY) {
                    func_800A7EC0(io_msg->piHandle, LEO_BM_CTL_REG, info->bmCtlShadow | LEO_BM_CTL_STOP);
                }

                blockInfo->errStatus = 4;
                (*(volatile u32 *)((u32)(PI_STATUS_REG_ADDR) | 0xA0000000) = (u32)(PI_STATUS_CLR_INTR));
                __osSetGlobalIntMask(LEO_INTR_MASK | 0x00000800);
            }

            osSendMesg(io_msg->hdr.retQueue, io_msg, 0);

            if (retry_read == 1 && io_msg->piHandle->transferInfo.block[0].errStatus == 0) {
                retry_read = 0;
                goto readblock1;
            }

            osSendMesg(devmgr->acsQueue, 0, 0);
            if (io_msg->piHandle->transferInfo.blockNum == 1) {
                osYieldThread();
            }
        } else {
            switch (io_msg->hdr.type) {
                case OS_MESG_TYPE_DMAREAD:
                    osRecvMesg(devmgr->acsQueue, &acs_msg, 1);
                    result = devmgr->dma(0, io_msg->devAddr, io_msg->dramAddr, io_msg->size);
                    break;
                case OS_MESG_TYPE_DMAWRITE:
                    osRecvMesg(devmgr->acsQueue, &acs_msg, 1);
                    result = devmgr->dma(1, io_msg->devAddr, io_msg->dramAddr, io_msg->size);
                    break;
                case OS_MESG_TYPE_EDMAREAD:
                    osRecvMesg(devmgr->acsQueue, &acs_msg, 1);
                    result = devmgr->edma(io_msg->piHandle, 0, io_msg->devAddr, io_msg->dramAddr, io_msg->size);
                    break;
                case OS_MESG_TYPE_EDMAWRITE:
                    osRecvMesg(devmgr->acsQueue, &acs_msg, 1);
                    result = devmgr->edma(io_msg->piHandle, 1, io_msg->devAddr, io_msg->dramAddr, io_msg->size);
                    break;
                case OS_MESG_TYPE_LOOPBACK:
                    osSendMesg(io_msg->hdr.retQueue, io_msg, 0);
                    result = -1;
                    break;
                default:
                    result = -1;
                    break;
            }

            if (result == 0) {
                osRecvMesg(devmgr->evtQueue, &event_msg, 1);
                osSendMesg(io_msg->hdr.retQueue, io_msg, 0);
                osSendMesg(devmgr->acsQueue, 0, 0);
            }
        }
    }
}
