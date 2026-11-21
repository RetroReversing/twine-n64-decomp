/* identical to pakReadBlock in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern void func_800A23E4(void);
extern void func_800A2450(void);
extern void __osPackEepReadData(s32);
extern u32 __osEepStatus(s32, u16 *);
extern void __osSiRawStartDma(s32, void *);
extern s32 osRecvMesg(s32, void *, s32);
extern u8 D_80101390[];
extern u8 D_80106C1E[];
extern u8 D_801099F0[];

/* Reads one 32-byte block from the controller pak at page pageNum into dst. Polls the
 * pak status first and retries while it reports busy. Returns 0 on success or an error code. */
u32 osEepromRead(s32 msgQueue, u8 pageNum, u8 *dst) {
    u8 cmdBuf[20];
    s32 i;
    u16 statusType;
    u32 ret;
    u32 statusRet;
    u8 *outPtr = dst;
    u8 *srcPtr;
    u8 *eepData;
    func_800A23E4();
    statusRet = __osEepStatus(msgQueue, (u16 *)cmdBuf);
    statusType = (*(u16 *)cmdBuf & 0xC000) & 0xFFFF;
    eepData = D_801099F0;
    ret = statusRet;
    if (ret == 0) {
        if (statusType == 0x8000) {
            if (((u32)pageNum & 0xFF) >= 0x40U) ret = -1;
        } else if (statusType != 0xC000) ret = 8;
        if (ret == 0) {
            do {
                if ((cmdBuf[2] & 0x80) != 0)
                    __osEepStatus(msgQueue, (u16 *)cmdBuf);
            } while ((cmdBuf[2] & 0x80) != 0);
            __osPackEepReadData(pageNum & 0xFF);
            __osSiRawStartDma(1, D_801099F0);
            osRecvMesg(msgQueue, 0, 1);
            __osSiRawStartDma(0, D_801099F0);
            D_80106C1E[0x3272] = 4;
            osRecvMesg(msgQueue, 0, 1);
            i = 3;
            do { i--; eepData++; } while (i >= 0);
            __builtin_memcpy(cmdBuf + 8, eepData, 12);
            ret = (cmdBuf[9] & 0xC0) >> 4;
            srcPtr = &cmdBuf[12];
            if (ret == 0) {
                u8 *end = &cmdBuf[20];
#ifdef PORT
                do { *outPtr++ = *srcPtr++; } while (srcPtr < end);
#else
                do { *outPtr++ = *srcPtr++; } while ((s32)srcPtr < (s32)end);
#endif
            }
        }
    }
    func_800A2450();
    return ret;
}
