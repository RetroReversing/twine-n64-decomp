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
/* Polls PIF pak status until every channel is ready, then stores a bitmask of channels with a controller pak plugged in. */ s32 osPfsIsPlug(s32 mq, u8 *pattern) {
    s32 pifRet;
    s32 msgDummy;
    s32 chan;
    s32 pakMask = 0;
    u8 statusBits;
    CS chanStatus[4];
    s32 retriesLeft = 3;
    u8 *pifRam;
    func_800A23E4();
    pifRam = (u8*)(D_8010B15E + 0x7E82);
    do {
        __osPfsRequestData(0);
        __osSiRawStartDma(1, pifRam);
        osRecvMesg(mq, &msgDummy, 1);
        pifRet = __osSiRawStartDma(0, pifRam);
        osRecvMesg(mq, &msgDummy, 1);
        func_800AA1C0(&statusBits, chanStatus);
        for (chan = 0; chan < D_801083DC; chan++) {
            if (!(chanStatus[chan].status & 4)) { retriesLeft--; break; }
        }
        if (chan != D_801083DC) continue;
        retriesLeft = 0;
    } while (retriesLeft > 0);
    for (chan = 0; chan < D_801083DC; chan++) {
        if (chanStatus[chan].errno == 0 && (chanStatus[chan].status & 1)) pakMask |= 1 << chan;
    }
    func_800A2450();
    *pattern = pakMask;
    return pifRet;
}
