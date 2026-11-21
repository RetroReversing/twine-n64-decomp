/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_80001D80();
s32 func_80008154();
s32 func_8000A2B8();
s32 func_8000A2F4();
s32 func_8000A310();
s32 func_8000B9B8();
s32 func_8000CC38();
s32 func_8000CD8C();
s32 func_8000CF14();
s32 func_8003C710();
s32 func_80042CFC();
s32 func_80044BE4();
s32 activateIdList();
s32 func_80044D84();
s32 func_80044FF0();
s32 func_8004505C();
s32 func_80048794();
void *func_80083E90();
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
extern char D_80100B60[];
extern u8 D_80102EDE;
extern u8 D_80102EE0;
extern void *D_80109690;
extern u8 D_80109E68;
extern void *gObjectTable;
extern s32 gProbeObjectList;
extern u8 gSceneFlagsA;
extern u8 gSceneFlagsB;
extern s8 gSceneObjectsLoaded;
extern s8 gSceneSkipLoad;
extern void *gTrackMarkerTable;
extern s8 gTransitionEnabled;
extern s8 gTransitionPhase;

typedef struct { unsigned char pad_0[56]; float field_38; unsigned char pad_3C[93]; unsigned char field_99; } __repair_record_temp_v1;
s32 func_8000D000(void) {
    s32 temp_v0_6;
    s32 var_a0_2;
    s32 var_a2;
    s8 temp_s1;
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
        var_a0 = D_80102EDE != 0x1F;
    }
    gSceneSkipLoad = var_a0;
    func_80008154(var_a0);
    if (temp_s1 == 0) {
        func_8000A310();
        func_80044BE4(D_800E0740);
    } else {
        func_8000A2B8();
        func_8000A2F4();
    }
    temp_v0 = func_80083E90(0x2E74, 0x33);
    gObjectTable = temp_v0;
    memset(temp_v0, 0, 0x2E74);
    M2C_FIELD(gObjectTable, s16 *, 0x10) = (s16) temp_s0;
    temp_v0_2 = func_80083E90(0x8000, 0x33);
    M2C_FIELD(gObjectTable, void **, 4) = temp_v0_2;
    M2C_FIELD(gObjectTable, void **, 0) = temp_v0_2;
    func_8000B9B8(M2C_FIELD(gObjectTable, void **, 4), *(s32 *)(D_800B2640 + (temp_s0 * 4)) + D_54D910, 0x8000);
    var_a2 = 0;
    var_a0_2 = 0;
    do {
        temp_v0_3 = gObjectTable + var_a0_2;
        M2C_FIELD(temp_v0_3, s8 *, 0x9A) = 0;
        M2C_FIELD(temp_v0_3, s16 *, 0x80) = 1;
        M2C_FIELD(temp_v0_3, s16 *, 0x82) = 1;
        M2C_FIELD(temp_v0_3, s16 *, 0x84) = 1;
        M2C_FIELD(temp_v0_3, s16 *, 0x86) = 1;
        M2C_FIELD(temp_v0_3, s16 *, 0x88) = 1;
        M2C_FIELD(temp_v0_3, s16 *, 0x8A) = 1;
        M2C_FIELD(temp_v0_3, f32 *, 0x6C) = 1.0f;
        M2C_FIELD(temp_v0_3, f32 *, 0x70) = 1.0f;
        M2C_FIELD(temp_v0_3, s16 *, 0x8C) = 1;
        M2C_FIELD(temp_v0_3, s16 *, 0x8E) = 1;
        M2C_FIELD(temp_v0_3, f32 *, 0x74) = 255.0f;
        M2C_FIELD(temp_v0_3, f32 *, 0x78) = 255.0f;
        M2C_FIELD(temp_v0_3, s16 *, 0x90) = -1;
        temp_v1 = gObjectTable + var_a0_2;
        ((__repair_record_temp_v1*)temp_v1)->field_99 = 0xFF;
        ((__repair_record_temp_v1*)temp_v1)->field_38 = 999.0f;
        temp_v0_4 = gObjectTable + var_a0_2;
        M2C_FIELD(temp_v0_4, u8 *, 0x98) = 0xFF;
        var_a2 += 1;
        M2C_FIELD(temp_v0_4, s32 *, 0x7C) = -1;
        temp_v1_2 = gObjectTable + var_a0_2;
        var_a0_2 += 0xD4;
        M2C_FIELD(temp_v1_2, s16 *, 0x96) = 0;
        M2C_FIELD(temp_v1_2, s16 *, 0xE0) = 0;
    } while (var_a2 < 0x38);
    D_800E0748 = 0;
    D_800E074C = 0;
    func_8000CD8C(var_a0_2, 1, var_a2, -1);
    D_800CA338 = 1;
    if (temp_s1 == 0) {
        func_80044D84(D_800E0740);
        activateIdList(D_80100B60);
        func_80044FF0();
        func_80042CFC(M2C_FIELD(gTrackMarkerTable, s32 *, 8), D_800E0740);
        func_8004505C();
    } else {
        activateIdList(D_80100B60);
        func_8000CF14(0);
    }
    func_80048794(2, gProbeObjectList);
    func_8003C710(D_80109690);
    func_8004844C(D_80109690, 160.0f, 120.0f, 320.0f, 180.0f, 0.0f, 0.0f);
    M2C_FIELD(D_80109690, s32 *, 0x100) |= 0x10;
    temp_v0_5 = gSceneFlagsA | 4;
    temp_v1_3 = gSceneFlagsB | 4;
    gSceneFlagsA = temp_v0_5;
    gSceneFlagsB = temp_v1_3;
    gSceneFlagsA = temp_v0_5 & 0xFE;
    gSceneFlagsB = temp_v1_3 & 0xFE;
    M2C_FIELD(gObjectTable, s32 *, 0x2B30) = 0;
    M2C_FIELD(gObjectTable, s32 *, 0x2B3C) = 0;
    func_8000CC38(0x34, &gSceneFlagsA, gObjectTable);
    gTransitionEnabled = 1;
    gTransitionPhase = 0;
    D_800E0744 = 0;
    D_800E0745 = 0;
    D_800E0758 = 0;
    M2C_FIELD(gObjectTable, s16 *, 0x12) = 1;
    func_80001D80(1);
    temp_v1_4 = D_800B2718;
    if (temp_v1_4 != NULL) {
        temp_v0_6 = M2C_FIELD(temp_v1_4, s32 *, 0x60);
        D_800B2718 = NULL;
        M2C_FIELD(temp_v1_4, s32 *, 0x60) = (s32) (temp_v0_6 | 1);
    }
    updateTransitionState();
    M2C_FIELD(gTrackMarkerTable, s32 *, 0x100) |= 0x40;
    M2C_FIELD(gTrackMarkerTable, s8 *, 0x142) = 7;
    M2C_FIELD(gTrackMarkerTable, s32 *, 0x100) |= 0x100;
    return 1;
}
