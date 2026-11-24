/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 loadTrackIdList();
s32 collectObjectRecordIds();
s32 dmaRomToRamUnaligned();
s32 setRotationInterpolationMode();
s32 waitForPendingFrames();
s32 releaseMusicStream();
s32 releaseSoundRequestQueue();
s32 stopAllAudio();
s32 updateObjectBlendFactor();
s32 applyStatusToSceneObjects();
s32 resetSceneObjectState();
s32 spawnSceneObjectsFromSlot();
s32 setGameModeAndResetLevel();
s32 initSceneForTrack();
s32 resetSceneObjectPools();
s32 copyDefaultObjToOrderContext();
s32 registerTrackMarkerParent();
void *heapAllocTagged();
s32 memset();
s32 updateTransitionState();
extern char D_54D910[];
extern char D_800B2640[];
extern void *D_800B2718;
extern s8 gSkipActorSpawns;
extern s16 D_800E0740;
extern s8 D_800E0744;
extern s8 D_800E0745;
extern s32 D_800E0748;
extern s32 D_800E074C;
extern s8 D_800E0758;
extern u8 gCurrentItemId;
extern void *gSceneState;
extern u8 gPendingSceneParam;
extern void *gCutscene;
extern u8 gPendingMenuCommand;
extern s32 gDefaultOrderObj;
extern u8 gSceneFlagsB;
extern s8 gSceneObjectsLoaded;
extern s8 gSceneSkipLoad;
extern u8 gTrackMarkerActiveMask;
extern s8 gTransitionEnabled;
extern s8 gTransitionPhase;
extern s32 sObjectIdList;
extern void *volatile gTrackMarkerParents;

/* Initializes a scene: allocates and resets the object records, loads the scene's data from ROM, activates its objects and sets up the camera and transition state. */ s32 initSceneObjects(void) {
    void *recordsBase;
    f32 farDistance;
    void *volatile *scene;
    u8 *markerMask;
    s32 temp_v0_6;
    s32 recordIndex;
    s32 alreadyLoaded;
    s8 skipLoad;
    u8 sceneIndex;
    u8 temp_v0_5;
    u8 temp_v1_3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_4;

    sceneIndex = gPendingSceneParam;
    alreadyLoaded = gSceneObjectsLoaded;
    skipLoad = 0;
    if (gCurrentItemId == 0x24) {
        skipLoad = gPendingMenuCommand != 0x1F;
    }
    gSceneSkipLoad = skipLoad;
    waitForPendingFrames(skipLoad);
    if (!alreadyLoaded) {
        stopAllAudio();
        setGameModeAndResetLevel(D_800E0740);
    } else {
        releaseMusicStream();
        releaseSoundRequestQueue();
    }
    temp_v0 = heapAllocTagged(0x2E74, 0x33);
    gCutscene = temp_v0;
    memset(temp_v0, 0, 0x2E74);
    (*(s16 *)((char *)(gCutscene) + 0x10)) = (s16) sceneIndex;
    temp_v0_2 = heapAllocTagged(0x8000, 0x33);
    {
        void *volatile *records = gCutscene;
        records[1] = temp_v0_2;
        records[0] = temp_v0_2;
        dmaRomToRamUnaligned(records[1], *(s32 *)(D_800B2640 + (sceneIndex * 4)) + D_54D910, 0x8000);
    }
    recordIndex = 0;
    do {
        temp_v0_3 = gCutscene + (recordIndex * 0xD4);
        (*(s8 *)((char *)(temp_v0_3) + 0x9A)) = 0;
        temp_v1 = gCutscene + (recordIndex * 0xD4);
        (*(s16 *)((char *)(temp_v0_3) + 0x80)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x82)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x84)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x86)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x88)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x8A)) = 1;
        (*(f32 *)((char *)(temp_v0_3) + 0x6C)) = 1.0f;
        (*(f32 *)((char *)(temp_v0_3) + 0x70)) = 1.0f;
        (*(s16 *)((char *)(temp_v0_3) + 0x8C)) = 1;
        (*(s16 *)((char *)(temp_v0_3) + 0x8E)) = 1;
        (*(f32 *)((char *)(temp_v0_3) + 0x74)) = 255.0f;
        (*(f32 *)((char *)(temp_v0_3) + 0x78)) = 255.0f;
        (*(s16 *)((char *)(temp_v0_3) + 0x90)) = -1;
        farDistance = 999.0f;
        (*(u8 *)((char *)(temp_v1) + 0x99)) = 0xFF;
        temp_v0_4 = gCutscene + (recordIndex * 0xD4);
        (*(f32 *)((char *)(temp_v1) + 0x38)) = farDistance;
        (*(u8 *)((char *)(temp_v0_4) + 0x98)) = 0xFF;
        temp_v1_2 = gCutscene + (recordIndex * 0xD4);
        recordIndex += 1;
        (*(s32 *)((char *)(temp_v0_4) + 0x7C)) = -1;
        (*(s16 *)((char *)(temp_v1_2) + 0x96)) = 0;
        (*(s16 *)((char *)(temp_v1_2) + 0xE0)) = 0;
    } while (recordIndex < 0x38);
    D_800E0748 = 0;
    D_800E074C = 0;
    collectObjectRecordIds();
    gSkipActorSpawns = 1;
    if (alreadyLoaded == 0) {
        initSceneForTrack(D_800E0740);
        loadTrackIdList(&sObjectIdList);
        resetSceneObjectPools();
        spawnSceneObjectsFromSlot((*(s32 *)((char *)(gTrackMarkerParents) + 8)), D_800E0740);
        copyDefaultObjToOrderContext();
    } else {
        loadTrackIdList(&sObjectIdList);
        applyStatusToSceneObjects(0);
    }
    registerTrackMarkerParent(2, gDefaultOrderObj);
    scene = &gSceneState;
    resetSceneObjectState(*scene);
    setViewportRect(*scene, 160.0f, 120.0f, 320.0f, 180.0f, 0.0f, 0.0f);
    recordsBase = gCutscene;
    (*(s32 *)((char *)(gSceneState) + 0x100)) |= 0x10;
    markerMask = &gTrackMarkerActiveMask;
    temp_v0_5 = *markerMask | 4;
    temp_v1_3 = gSceneFlagsB | 4;
    *markerMask = temp_v0_5;
    gSceneFlagsB = temp_v1_3;
    *markerMask = temp_v0_5 & 0xFE;
    gSceneFlagsB = temp_v1_3 & 0xFE;
    (*(s32 *)((char *)(recordsBase) + 0x2B30)) = 0;
    (*(s32 *)((char *)(recordsBase) + 0x2B3C)) = 0;
    updateObjectBlendFactor(0x34, markerMask, recordsBase);
    gTransitionEnabled = 1;
    gTransitionPhase = 0;
    D_800E0744 = 0;
    D_800E0745 = 0;
    D_800E0758 = 0;
    (*(s16 *)((char *)(gCutscene) + 0x12)) = 1;
    setRotationInterpolationMode(1);
    temp_v1_4 = D_800B2718;
    if (temp_v1_4 != NULL) {
        temp_v0_6 = (*(s32 *)((char *)(temp_v1_4) + 0x60));
        D_800B2718 = NULL;
        (*(s32 *)((char *)(temp_v1_4) + 0x60)) = (s32) (temp_v0_6 | 1);
    }
    updateTransitionState();
    (*(s32 *)((char *)(gTrackMarkerParents) + 0x100)) |= 0x40;
    (*(s8 *)((char *)gTrackMarkerParents + 0x142)) = 7;
    (*(s32 *)((char *)(gTrackMarkerParents) + 0x100)) |= 0x100;
    return 1;
}
