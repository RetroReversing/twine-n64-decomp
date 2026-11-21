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

s32 actorInitFromSpawn();
s32 func_80001D80();
s32 func_8003C710();
s32 func_80047F50();
s32 func_80048794();
s32 func_800658C0();
s32 updateSplinePosition();
s32 func_80084048();
extern u32 gTrackMarkerCount;
extern char D_80100BE0[];
extern s8 D_80103EB0;
extern char gTrackMarkerRotTable[];
extern void *D_80109690;
extern char gTrackMarkerPosTable[];
extern s32 gBonusObjects;
extern s32 gProbeObjectList;
extern u8 gTrackMarkerActiveMask;
extern u8 gSceneFlagsB;
extern s32 sTrackDoneFlags;

void func_80076838(void *arg0) {
    s16 temp_v1;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;
    u32 var_v1;
    void *temp_s1;
    void *var_a2;
    void *var_a3;

    temp_v1 = M2C_FIELD(arg0, s16 *, 0x7A);
    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        if (*(&sTrackDoneFlags + M2C_FIELD(temp_s1, u8 *, 0)) != 0) {
            if (D_80103EB0 == 0) {
                var_v0 = M2C_FIELD(arg0, s32 *, 0x60) | 1;
block_24:
                M2C_FIELD(arg0, s32 *, 0x60) = var_v0;
            } else {
                temp_s0 = gBonusObjects;
                D_80103EB0 = 0;
                var_a3 = temp_s0 + 0x24;
                if (func_800658C0(temp_s0) != 0) {
                    var_a2 = temp_s0 + 0x3C;
                    var_v1 = 0;
                    if (gTrackMarkerCount != 0) {
loop_16:
                        if (*(D_80100BE0 + var_v1) != M2C_FIELD(temp_s1, u8 *, 0)) {
                            var_v1 += 1;
                            if (var_v1 < (u32) gTrackMarkerCount) {
                                goto loop_16;
                            }
                        } else {
                            temp_v0 = var_v1 * 0xC;
                            var_a3 = temp_v0 + gTrackMarkerPosTable;
                            var_a2 = temp_v0 + gTrackMarkerRotTable;
                        }
                    }
                    do { actorInitFromSpawn(temp_s0, var_a3, var_a2, var_a3); } while (0);
                    func_80001D80(1);
                    M2C_FIELD(arg0, s16 *, 0x7A) = 1;
                    return;
                }
            }
        } else {
            return;
        }
        break;
    case 1:
        func_80048794(2, gProbeObjectList);
        func_8003C710(D_80109690);
        func_8004844C(D_80109690, 160.0f, 120.0f, 320.0f, 180.0f, 0.0f, 0.0f);
        func_80047F50(arg0, D_80109690);
        M2C_FIELD(D_80109690, s32 *, 0x100) |= 0x10;
        gTrackMarkerActiveMask = (gTrackMarkerActiveMask | 4) & 0xFE;
        gSceneFlagsB &= 0xFE;
        M2C_FIELD(temp_s1, s16 *, 0x12) = -1;
        M2C_FIELD(temp_s1, f32 *, 8) = 0.01f;
        func_80047F50(arg0, D_80109690);
        M2C_FIELD(arg0, s16 *, 0x7A) = 2;
        return;
    case 2:
        M2C_FIELD(arg0, s32 *, 0x58) |= 1;
        M2C_FIELD(temp_s1, f32 *, 8) += M2C_FIELD(temp_s1, f32 *, 0xC);
        updateSplinePosition(arg0, temp_s1 + 4);
        func_80047F50(arg0, D_80109690);
        if ((*(&sTrackDoneFlags + M2C_FIELD(temp_s1, u8 *, 0)) == 0) || (M2C_FIELD(temp_s1, s16 *, 0x12) >= (M2C_FIELD(temp_s1, s16 *, 0x10) - 4))) {
            M2C_FIELD(arg0, s16 *, 0x7A) = 3;
            return;
        }
        break;
    case 3:
        *(&sTrackDoneFlags + M2C_FIELD(temp_s1, u8 *, 1)) = 1;
        gTrackMarkerActiveMask |= 1;
        gSceneFlagsB |= 1;
        func_80084048(D_80109690, 0xE, &gTrackMarkerActiveMask);
        D_80109690 = NULL;
        func_80001D80(0);
        D_80103EB0 = 1;
        var_v0 = M2C_FIELD(arg0, s32 *, 0x60) | 1;
        goto block_24;
    }
}
