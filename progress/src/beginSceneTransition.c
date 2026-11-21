void func_80001D80(s32 arg0);
void func_8000C8BC(s32 arg0);
void func_8000C97C(void);
void func_8000CF14(s32 arg0);
void func_8000DBBC(s32 arg0);
void func_80064780(s32 arg0);
void func_80084048(void *arg0, s32 arg1);
extern void *gObjectRecords;
extern s8 D_800B2715;
extern s8 gSceneObjectsLoaded;
extern u8 gSceneSkipLoad;
extern void *gTrackMarkers;
extern void *D_80109690;
extern u8 D_8010A4C1;
extern u8 gSceneFlagsB;
extern s32 D_8010A500;

/* Frees the current scene objects, sets exit flags and picks the next scene id to load */ /* Frees the current scene's objects, sets the scene-exit flags, and picks the next scene id to load. */ void beginSceneTransition(void) {
    void **pendingObjectSlot;
    s32 currentSceneId;
    s32 nextSceneId;
    s32 var_v0;
    register long isNotScene20;

    currentSceneId = *(s16 *)((char *)gObjectRecords + 0x10);
    if (gSceneObjectsLoaded != 0) {
        pendingObjectSlot = &D_80109690;
        func_80084048(*pendingObjectSlot, 0xE);
        *pendingObjectSlot = NULL;
        func_80084048(*(void **)((char *)gObjectRecords + 4), 0x33);
        func_80084048(gObjectRecords, 0x33);
        func_8000CF14(1);
    }
    {
        u8 *sceneFlagsPtr = &D_8010A4C1;
        *sceneFlagsPtr |= 1;
    }
    gSceneFlagsB |= 1;
    *(s32 *)((char *)gTrackMarkers + 0x100) &= ~0x100;
    func_80001D80(0);
    gObjectRecords = NULL;
    if (currentSceneId == 0x26 && D_8010A500) {
        func_80064780(D_8010A500);
    }
    isNotScene20 = currentSceneId != 0x20;
    nextSceneId = -isNotScene20 | 0x1C;
    if (currentSceneId == 0x1C) {
        nextSceneId = 0x1D;
    }
    if (currentSceneId == 0xA) {
        nextSceneId = 0xB;
    }
    if (currentSceneId == 0x11) {
        nextSceneId = 0x13;
    }
    if (currentSceneId == 5) {
        nextSceneId = 0x33;
    }
    if ((gSceneSkipLoad != 0) && (!D_800B2715)) {
        func_8000C8BC(currentSceneId);
        return;
    }
    if (nextSceneId >= 0) {
        if (!D_800B2715) {
            func_8000C8BC(nextSceneId);
            return;
        }
        if (nextSceneId != 0x13) {
            func_8000DBBC(8);
        }
        goto block_22;
    }
block_22:
    func_8000C97C();
}


