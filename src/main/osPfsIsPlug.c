#include "common_local_source_25769805743.h"

/* identical to osPfsIsPlug in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
typedef struct { u16 type; u8 status; u8 errno; } CS;
extern u8 D_801083DC;
extern char D_8010B15E[];
s32 __osPfsRequestData(s32);
void func_800AA1C0();
void func_800A23E4();
void func_800A2450();
s32 __osSiRawStartDma();
s32 osRecvMesg(s32, s32 *, s32);

/* Polls the controller pak status for every channel until all of them report
 * ready, then stores a bitmask of the channels with a pak plugged in. */
s32 osPfsIsPlug(s32 queue, u8 *pattern) {
    s32 ret;
    s32 dummy;
    s32 channel;
    s32 cntrlrs = 0;
    u8 bitpattern;
    CS data[4];
    s32 crap = 3;
    u8 *pif;
    func_800A23E4();
    pif = (u8*)(D_8010B15E + 0x7E82);
    do {
        __osPfsRequestData(0);
        __osSiRawStartDma(1, pif);
        osRecvMesg(queue, &dummy, 1);
        ret = __osSiRawStartDma(0, pif);
        osRecvMesg(queue, &dummy, 1);
        func_800AA1C0(&bitpattern, data);
        for (channel = 0; channel < D_801083DC; channel++) {
            if (!(data[channel].status & 4)) { crap--; break; }
        }
        if (channel != D_801083DC) continue;
        crap = 0;
    } while (crap > 0);
    for (channel = 0; channel < D_801083DC; channel++) {
        if (data[channel].errno == 0 && (data[channel].status & 1)) cntrlrs |= 1 << channel;
    }
    func_800A2450();
    *pattern = cntrlrs;
    return ret;
}
