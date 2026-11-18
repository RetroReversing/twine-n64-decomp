#include "common_local_source_25769805594.h"

/* identical to osContStartReadData in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern char D_80100920[];
extern u8 D_80109E90;
s32 osRecvMesg(s32, s32, s32);
void func_800A23E4(void);
void func_800A2450(void);
void __osPackReadData(void);
s32 __osSiRawStartDma(s32, void *);

/* Starts a controller read: if the last PIF command was not a button read, sends the
   packed command first and waits for the reply. Then starts the PIF read DMA and
   returns its result. Holds the PIF lock for the whole sequence. */
s32 osContStartReadData(s32 mq)
{
    s32 ret;

    func_800A23E4();
    if (D_80109E90 != 1) {
        __osPackReadData();
        __osSiRawStartDma(1, D_80100920);
        osRecvMesg(mq, 0, 1);
    }
    ret = __osSiRawStartDma(0, D_80100920);
    D_80109E90 = 1;
    func_800A2450();
    return ret;
}
