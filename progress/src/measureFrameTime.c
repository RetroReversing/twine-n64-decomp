u64 func_800ABCB0(u64, u64);
u64 osGetTime(void);
s32 osRecvMesg(void *, void *, s32);
extern s32 osTvType;
extern u64 D_80108F88;
extern u8 gGfxSyncQueue[];
void measureFrameTime(void) {
    u64 t;

    while (osRecvMesg(gGfxSyncQueue, 0, 0) == 0) {
    }
    osRecvMesg(gGfxSyncQueue, 0, 1);
    t = osGetTime();
    osRecvMesg(gGfxSyncQueue, 0, 1);
    D_80108F88 = osGetTime() - t;
    if (osTvType == 0) {
        D_80108F88 = func_800ABCB0(D_80108F88 * 5 + 3, 6);
    }
}
