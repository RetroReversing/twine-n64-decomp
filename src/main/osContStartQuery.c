#include "common_local_source_25769805592.h"

/* identical to osContStartQuery in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern s32 __osPackRequestData(s32);
extern s32 osRecvMesg(s32, s32, s32);
extern s32 func_800A23E4();
extern s32 func_800A2450();
extern s32 __osSiRawStartDma(s32, void *);
extern u8 D_80100920[];
extern u8 D_80109E90;

/* Starts a controller status query on the message queue mq. If D_80109E90 is set, it first
 * packs and writes a request to PIF RAM and waits for the reply on mq. Then it reads the
 * PIF RAM result, clears D_80109E90, and returns the read's status. */
s32 osContStartQuery(s32 mq)
{
    s32 result;

    func_800A23E4();
    if (D_80109E90 != 0) {
        __osPackRequestData(0);
        __osSiRawStartDma(1, D_80100920);
        osRecvMesg(mq, 0, 1);
    }
    result = __osSiRawStartDma(0, D_80100920);
    D_80109E90 = 0;
    func_800A2450();
    return result;
}
