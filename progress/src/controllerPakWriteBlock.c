/* identical to pfs_write_block in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern void func_800A23E4(void);
extern void func_800A2450(void);
extern void __osPackEepWriteData(u8, u8 *);
extern s32 __osEepStatus(s32, u8 *);
extern s32 __osSiRawStartDma(s32, void *);
extern s32 osRecvMesg(s32, void *, s32);
extern u8 D_80106C1E[];
extern u8 D_80101390[];
typedef struct { u8 b[12]; } Blk12;

/* Writes an 8-byte block (data) to controller pak channel ch through the PIF
 * command buffer. Returns 0 on success, or the pak's error code. */
/* Writes an 8-byte block to controller pak channel through the PIF command buffer; returns 0 or the pak error code. */ s32 controllerPakWriteBlock(s32 msgQueue, u8 channel, u8 *blockData)
{
    s32 result = 0;
    u16 statusType;
    u8 *pifCmd = D_80101390 + 0x8660;
    Blk12 replyBlock;
    u8 statusBytes[4];

    func_800A23E4();
    result = __osEepStatus(msgQueue, statusBytes);
    statusType = *(u16 *)statusBytes & 0xC000;
    if (result == 0) {
        switch (statusType) {
        case 0x8000:
            if (channel >= 0x40) {
                result = -1;
            }
            break;
        case 0xC000:
            break;
        default:
            result = 8;
            break;
        }
    }
    if (result != 0) {
        func_800A2450();
        return result;
    }
    while (statusBytes[2] & 0x80) {
        __osEepStatus(msgQueue, statusBytes);
    }
    __osPackEepWriteData(channel, blockData);
    result = __osSiRawStartDma(1, D_80101390 + 0x8660);
    osRecvMesg(msgQueue, 0, 1);
    result = __osSiRawStartDma(0, D_80101390 + 0x8660);
    D_80106C1E[0x3272] = 5;
    osRecvMesg(msgQueue, 0, 1);
    pifCmd += 4;
    replyBlock = *(Blk12 *)pifCmd;
    result = (replyBlock.b[1] & 0xC0) >> 4;
    func_800A2450();
    return result;
}
