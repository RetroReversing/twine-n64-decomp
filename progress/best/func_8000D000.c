/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 activateIdList();
s32 collectObjectRecordIds();
s32 dmaRomToRamUnaligned();
s32 func_80001D80();
s32 func_80008154();
s32 func_8000A2B8();
s32 func_8000A2F4();
s32 func_8000A310();
s32 func_8000CC38();
s32 func_8000CF14();
s32 func_8003C710();
s32 func_80042CFC();
s32 func_80044BE4();
s32 func_80044D84();
s32 func_80044FF0();
s32 func_8004505C();
s32 func_80048794();
void *heapAllocTagged();
s32 memset();
s32 updateTransitionState();
extern char D_54D910[];
extern char D_800B2640[];
extern void *D_800B2718;
extern s8 D_800CA338;
extern s16 D_800E0740;
extern s8 D_800E0744;
extern s8 D_800E0745;
extern s32 D_800E0748;
extern s32 D_800E074C;
extern s8 D_800E0758;
extern u8 D_80102EE0;
extern void *D_80109690;
extern u8 D_80109E68;
extern void *gObjectRecords;
extern u8 gPendingMenuCommand;
extern s32 gProbeObjectList;
extern u8 gSceneFlagsB;
extern s8 gSceneObjectsLoaded;
extern s8 gSceneSkipLoad;
extern u8 gTrackMarkerActiveMask;
extern s8 gTransitionEnabled;
extern s8 gTransitionPhase;
extern s32 sObjectIdList;
extern void *sTrackMarkerTable;

s32 func_8000D000(void) {
    void *volatile *scene;
    u8 *markerMask;
    s32 temp_v0_6;
    s32 var_a0_2;
    s32 var_a2;
    s32 temp_s1;
    s8 var_a0;
    u8 temp_s0;
    u8 temp_v0_5;
    u8 temp_v1_3;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1;
    void *temp_v1_2;
    void *temp_v1_4;

    temp_s0 = D_80109E68;
    temp_s1 = gSceneObjectsLoaded;
    var_a0 = 0;
    if (D_80102EE0 == 0x24) {
        var_a0 = gPendingMenuCommand != 0x1F;
    }
    gSceneSkipLoad = var_a0;
    func_80008154(var_a0);
    if (!temp_s1) {
        func_8000A310();
        func_80044BE4(D_800E0740);
    } else {
        func_8000A2B8();
        func_8000A2F4();
    }
    temp_v0 = heapAllocTagged(0x2E74, 0x33);
    gObjectRecords = temp_v0;
    memset(temp_v0, 0, 0x2E74);
    (*(s16 *)((char *)(gObjectRecords) + 0x10)) = (s16) temp_s0;
    temp_v0_2 = heapAllocTagged(0x8000, 0x33);
    {
        void *volatile *records = gObjectRecords;
        records[1] = temp_v0_2;
        records[0] = temp_v0_2;
        dmaRomToRamUnaligned(records[1], *(s32 *)(D_800B2640 + (temp_s0 * 4)) + D_54D910, 0x8000);
    }
    var_a2 = 0;
    var_a0_2 = 0;
    do {
        temp_v0_3 = gObjectRecords + var_a0_2;
        (*(s8 *)((char *)(temp_v0_3) + 0x9A)) = 0;
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
        temp_v1 = gObjectRecords + var_a0_2;
        (*(s16 *)((char *)(temp_v0_3) + 0x90)) = -1;
        (*(f32 *)((char *)(temp_v1) + 0x38)) = 999.0f;
        (*(u8 *)((char *)(temp_v1) + 0x99)) = 0xFF;
        temp_v0_4 = gObjectRecords + var_a0_2;
        (*(u8 *)((char *)(temp_v0_4) + 0x98)) = 0xFF;
        temp_v1_2 = gObjectRecords + var_a0_2;
        var_a2 += 1;
        (*(s32 *)((char *)(temp_v0_4) + 0x7C)) = -1;
        var_a0_2 += 0xD4;
        (*(s16 *)((char *)(temp_v1_2) + 0x96)) = 0;
        (*(s16 *)((char *)(temp_v1_2) + 0xE0)) = 0;
    } while (var_a2 < 0x38);
    D_800E0748 = 0;
    D_800E074C = 0;
    collectObjectRecordIds(var_a0_2);
    D_800CA338 = 1;
    if (temp_s1 == 0) {
        func_80044D84(D_800E0740);
        activateIdList(&sObjectIdList);
        func_80044FF0();
        func_80042CFC((*(s32 *)((char *)(sTrackMarkerTable) + 8)), D_800E0740);
        func_8004505C();
    } else {
        activateIdList(&sObjectIdList);
        func_8000CF14(0);
    }
    func_80048794(2, gProbeObjectList);
    scene = &D_80109690;
    func_8003C710(*scene);
    func_8004844C(*scene, 160.0f, 120.0f, 320.0f, 180.0f, 0.0f, 0.0f);
    (*(s32 *)((char *)(D_80109690) + 0x100)) |= 0x10;
    markerMask = &gTrackMarkerActiveMask;
    temp_v0_5 = *markerMask | 4;
    temp_v1_3 = gSceneFlagsB | 4;
    *markerMask = temp_v0_5;
    gSceneFlagsB = temp_v1_3;
    *markerMask = temp_v0_5 & 0xFE;
    gSceneFlagsB = temp_v1_3 & 0xFE;
    (*(s32 *)((char *)(gObjectRecords) + 0x2B30)) = 0;
    (*(s32 *)((char *)(gObjectRecords) + 0x2B3C)) = 0;
    func_8000CC38(0x34, markerMask, gObjectRecords);
    gTransitionEnabled = 1;
    gTransitionPhase = 0;
    D_800E0744 = 0;
    D_800E0745 = 0;
    D_800E0758 = 0;
    (*(s16 *)((char *)(gObjectRecords) + 0x12)) = 1;
    func_80001D80(1);
    temp_v1_4 = D_800B2718;
    if (temp_v1_4 != NULL) {
        temp_v0_6 = (*(s32 *)((char *)(temp_v1_4) + 0x60));
        D_800B2718 = NULL;
        (*(s32 *)((char *)(temp_v1_4) + 0x60)) = (s32) (temp_v0_6 | 1);
    }
    updateTransitionState();
    (*(s32 *)((char *)(sTrackMarkerTable) + 0x100)) |= 0x40;
    (*(s8 *)((char *)(*(void *volatile *)&sTrackMarkerTable) + 0x142)) = 7;
    (*(s32 *)((char *)(sTrackMarkerTable) + 0x100)) |= 0x100;
    return 1;
}
