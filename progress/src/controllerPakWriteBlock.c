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
s32 osEepromWrite(s32 mq, u8 ch, u8 *data)
{
    s32 ret = 0;
    u16 type;
    u8 *pif = D_80101390 + 0x8660;
    Blk12 reply;
    u8 status[4];

    func_800A23E4();
    ret = __osEepStatus(mq, status);
    type = *(u16 *)status & 0xC000;
    if (ret == 0) {
        switch (type) {
        case 0x8000:
            if (ch >= 0x40) {
                ret = -1;
            }
            break;
        case 0xC000:
            break;
        default:
            ret = 8;
            break;
        }
    }
    if (ret != 0) {
        func_800A2450();
        return ret;
    }
    while (status[2] & 0x80) {
        __osEepStatus(mq, status);
    }
    __osPackEepWriteData(ch, data);
    ret = __osSiRawStartDma(1, D_80101390 + 0x8660);
    osRecvMesg(mq, 0, 1);
    ret = __osSiRawStartDma(0, D_80101390 + 0x8660);
    D_80106C1E[0x3272] = 5;
    osRecvMesg(mq, 0, 1);
    pif += 4;
    reply = *(Blk12 *)pif;
    ret = (reply.b[1] & 0xC0) >> 4;
    func_800A2450();
    return ret;
}
