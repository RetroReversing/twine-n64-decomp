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

extern int D_800E157C;
extern int D_800E1580;
u32 randomU32Next();
extern s32 D_800E1564;
extern s32 D_800E1568;
extern s32 D_800E156C;
extern s32 D_800E1570;
extern s32 D_800E1574;
extern s32 D_800E1578;

void func_8002FBE4(s8 *arg0, u16 *arg1, u16 *arg2) {
    int *__base_D_800E157C;
    f32 temp_fv1;
    s32 *temp_s1;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s8 *var_a0;
    u16 *temp_s2;
    u16 *var_a1;
    u16 var_a0_2;
    u8 temp_v1;

    var_a0 = arg0;
    var_a1 = arg1;
    temp_s2 = var_a1;
    if (var_a0 != NULL) {
        temp_s0 = M2C_FIELD(var_a0, s32 *, 8);
        D_800E156C = (s32) M2C_FIELD(var_a0, u16 *, 0x24);
        D_800E1570 = (s32) M2C_FIELD(var_a0, u8 *, 0x28);
        D_800E1580 = 0;
        if (*temp_s2 != 0) {
            temp_s1 = &D_800E1580 - 4;
            __repair_rows: {
                if (*arg2 == 0) {
                    var_a0_2 = ((s32) D_800E156C >> 2) + (randomU32Next((s32) var_a0, (s32) var_a1) % (u32) ((s32) D_800E156C >> 1));
                } else {
                    var_a0_2 = *temp_s2;
                }
                D_800E1564 = (s32) var_a0_2;
                D_800E1568 = (randomU32Next((s32) var_a0_2) & 3) + 0x1C;
                var_a1 = (u16 *) (D_800E1568 * D_800E156C);
                temp_v0_2 = (randomU32Next() % 255) - 0x80;
                M2C_FIELD(temp_s1, s32 *, 0) = temp_v0_2;
                var_a0 = temp_s0 + (D_800E1564 + var_a1);
                temp_v0_2 = (s32) (temp_v0_2 + *var_a0) >> 1;
                M2C_FIELD(temp_s1, s32 *, 0) = temp_v0_2;
                *var_a0 = (s8) temp_v0_2;
                temp_v0 = M2C_FIELD(temp_s1, s32 *, 4) + 1;
                M2C_FIELD(temp_s1, s32 *, 4) = temp_v0;
            }
if (temp_v0 < (s32) *temp_s2) goto __repair_rows;
        }
        D_800E1568 = 0;
        if (D_800E1570 > 0) {
            do {
                var_a0_3 = D_800E1568 + 1;
                if (D_800E1568 >= 0x1D) {
                    var_a0_3 = D_800E1568 - 1;
                }
                D_800E1574 = var_a0_3;
                if (var_a0_3 < 0) {
                    var_v0 = var_a0_3 - 1 + D_800E1570;
                } else if ((D_800E1570 - 1) >= var_a0_3) {
                    var_v0 = var_a0_3;
                } else {
                    var_v0 = (var_a0_3 + 1) - D_800E1570;
                }
                D_800E1574 = var_v0;
                D_800E1564 = 0;
                if (D_800E156C > 0) {
                    do {
                        if (((s32) D_800E156C >> 1) >= D_800E1564) {
                            var_v1 = D_800E1564 + 1;
                        } else {
                            var_v1 = D_800E1564 - 1;
                        }
                        D_800E1578 = var_v1;
                        var_a0_4 = var_v1;
                        if (var_v1 < 0) {
                            var_a0_4 = var_v1 + D_800E156C;
                        } else if (D_800E156C < var_a0_4) {
                            var_a0_4 -= D_800E156C;
                        }
                        temp_lo = D_800E1574 * D_800E156C;
                        temp_lo_2 = D_800E1568 * D_800E156C;
                        D_800E1578 = var_a0_4;
                        temp_v1 = *(u8 *)(temp_s0 + (var_a0_4 + temp_lo));
                        __base_D_800E157C = &D_800E157C;
                        (*__base_D_800E157C) = (s32) temp_v1;
                        temp_v1_2 = temp_v1 + *(s32 *)(temp_s0 + (var_a0_4 + temp_lo_2));
                        (*__base_D_800E157C) = temp_v1_2;
                        temp_v1_3 = temp_v1_2 + *(s32 *)(temp_s0 + (D_800E1564 + temp_lo));
                        (*__base_D_800E157C) = temp_v1_3;
                        temp_v1_4 = temp_v1_3 + *(s32 *)(temp_s0 + (D_800E1564 + temp_lo_2));
                        temp_fv1 = (f32) temp_v1_4 * 0.24691357f;
                        (*__base_D_800E157C) = temp_v1_4;
                        if (!(temp_fv1 >= 2.1474836e9f)) {
                            var_v1_2 = (s32) temp_fv1;
                        } else {
                            var_v1_2 = (s32) (temp_fv1 - 2.1474836e9f) | 0x80000000;
                        }
                        temp_v1_5 = var_v1_2 & 0xFF;
                        D_800E1580 = temp_v1_5;
                        *(s32 *)(temp_s0 + (D_800E1564 + (D_800E1568 * D_800E156C))) = (s8) temp_v1_5;
                        temp_v0_5 = D_800E1564 + 1;
                        D_800E1564 = temp_v0_5;
                    } while (temp_v0_5 < D_800E156C);
                }
                temp_v0_4 = D_800E1568 + 1;
                D_800E1568 = temp_v0_4;
            } while (temp_v0_4 < D_800E1570);
        }
    }
}
