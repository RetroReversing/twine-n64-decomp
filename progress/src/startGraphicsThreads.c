s32 func_8000B580();
s32 func_8000B79C();
s32 func_8009D090();
s32 osCreateThread();
s32 osStartThread();
extern char D_800B2598[];
extern char gfxSyncThread[];
extern s16 gExpansionPakPresent;
extern char rspTaskOsThread[];
extern char D_80115040[];
extern char D_80117330[];
extern s32 gfxSyncThreadEntry;
extern s32 rspTaskThread;

/* Sizes a buffer by expansion pak presence, initializes subsystems, then creates and starts the graphics sync and RSP task threads. */
s32 startGraphicsThreads(s32 param) {
    s32 bufferSize;

    bufferSize = 0x4B000;
    if (gExpansionPakPresent != 0) {
        bufferSize = 0xAA000;
    }
    func_8000B580(param, bufferSize);
    func_8000B79C();
    func_8009D090(D_800B2598);
    osCreateThread(gfxSyncThread, 8, &gfxSyncThreadEntry, 0, D_80117330, 0x75);
    osStartThread(gfxSyncThread);
    osCreateThread(rspTaskOsThread, 7, &rspTaskThread, 0, D_80115040, 0x7A);
    osStartThread(rspTaskOsThread);
    return 0;
}
