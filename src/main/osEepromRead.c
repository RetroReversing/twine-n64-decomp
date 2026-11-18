#include "common.h"

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

/* Reads one 32-byte block from the controller pak at page arg1 into dst (arg2). Polls the
 * pak status first and retries while it reports busy. Returns 0 on success or an error code. */
u32 osEepromRead(s32 mq, u8 page, u8 *dst) {
    u8 pkt[20];
    s32 var_v0;
    u16 temp_v1;
    u32 err;
    u32 result;
    u8 *var_s3 = dst;
    u8 *var_v1;
    u8 *var_s2;
    func_800A23E4();
    result = __osEepStatus(mq, (u16 *)pkt);
    temp_v1 = (*(u16 *)pkt & 0xC000) & 0xFFFF;
    var_s2 = D_801099F0;
    err = result;
    if (err == 0) {
        if (temp_v1 == 0x8000) {
            if (((u32)page & 0xFF) >= 0x40U) err = -1;
        } else if (temp_v1 != 0xC000) err = 8;
        if (err == 0) {
            do {
                if ((pkt[2] & 0x80) != 0)
                    __osEepStatus(mq, (u16 *)pkt);
            } while ((pkt[2] & 0x80) != 0);
            __osPackEepReadData(page & 0xFF);
            __osSiRawStartDma(1, D_801099F0);
            osRecvMesg(mq, 0, 1);
            __osSiRawStartDma(0, D_801099F0);
            D_80106C1E[0x3272] = 4;
            osRecvMesg(mq, 0, 1);
            var_v0 = 3;
            do { var_v0--; var_s2++; } while (var_v0 >= 0);
            __builtin_memcpy(pkt + 8, var_s2, 12);
            err = (pkt[9] & 0xC0) >> 4;
            var_v1 = &pkt[12];
            if (err == 0) {
                u8 *end = &pkt[20];
#ifdef PORT
                do { *var_s3++ = *var_v1++; } while (var_v1 < end);
#else
                do { *var_s3++ = *var_v1++; } while ((s32)var_v1 < (s32)end);
#endif
            }
        }
    }
    func_800A2450();
    return err;
}
