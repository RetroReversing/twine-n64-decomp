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

extern s32 D_800CE800;
extern s32 D_800CE804;
extern s32 D_800CE808;
extern s32 D_800CE80C;
extern s32 D_800CE810;
extern s32 D_800CE814;
extern s32 D_800CE818;
extern s32 D_800CE81C;
extern s32 D_800CE820;
extern s32 D_800CE824;
extern s32 D_800CE828;
extern s32 D_800CE82C;
extern char D_8010A960[];

void *func_80087100(s32 arg0, s32 arg1) {
    s32 *var_v0;
    s32 temp_a0_2;
    s32 temp_v1;
    s32 var_a1;
    u32 temp_a0;
    u32 temp_a0_3;
    u32 temp_a0_4;
    u32 temp_a0_5;
    u32 temp_a0_6;
    u32 var_v1;

    var_a1 = arg1;
    temp_v1 = arg0 & 0xFFF;
    temp_a0_2 = arg0 & 0xF000;
    if (temp_a0_2 != 0x6000) {
        if (temp_a0_2 < 0x6001) {
            if (temp_a0_2 != 0x2000) {
                if (temp_a0_2 >= 0x2001) {
                    if (temp_a0_2 != 0x3000) {
                        temp_a0 = temp_v1 & 0xFFFF;
                        if (temp_a0_2 != 0x4000) {
                            goto block_54;
                        }
                        if (temp_a0 < 0x23U) {
                            return (temp_a0 * 0x12C) + D_8010A960;
                        }
                        goto block_54;
                    }
                    temp_a0_3 = temp_v1 & 0xFFFF;
                    if ((temp_a0_3 < 0x25U) && (D_800CE810 != 0)) {
                        var_v0 = (temp_a0_3 * 4) + D_800CE810;
                        goto block_53;
                    }
                    goto block_54;
                }
                if (temp_a0_2 != 0) {
                    temp_a0_4 = temp_v1 & 0xFFFF;
                    if (temp_a0_2 != 0x1000) {
                        goto block_54;
                    }
                    if ((temp_a0_4 < 0x92U) && (D_800CE808 != 0)) {
                        var_v0 = (temp_a0_4 * 4) + D_800CE808;
                        goto block_53;
                    }
                    goto block_54;
                }
                temp_a0_5 = temp_v1 & 0xFFFF;
                if ((temp_a0_5 < 0x2EAU) && (D_800CE804 != 0)) {
                    var_v0 = (temp_a0_5 * 4) + D_800CE804;
                    goto block_53;
                }
                goto block_54;
            }
            temp_a0_6 = temp_v1 & 0xFFFF;
            if ((temp_a0_6 < 0x2CU) && (D_800CE80C != 0)) {
                var_v0 = (temp_a0_6 * 4) + D_800CE80C;
                goto block_53;
            }
            goto block_54;
        }
        if (temp_a0_2 != 0x9000) {
            if (temp_a0_2 <= 0x9000) {
                if (temp_a0_2 != 0x7000) {
                    var_v1 = temp_v1 & 0xFFFF;
                    if (temp_a0_2 != 0x8000) {
                        goto block_54;
                    }
                    if (var_v1 < 0x17U) {
                        var_a1 = D_800CE820;
                        goto block_51;
                    }
                    goto block_54;
                }
                var_v1 = temp_v1 & 0xFFFF;
                if (var_v1 < 0x1EU) {
                    var_a1 = D_800CE81C;
                    goto block_51;
                }
                goto block_54;
            }
            if (temp_a0_2 != 0xB000) {
                if (temp_a0_2 <= 0xB000) {
                    var_v1 = temp_v1 & 0xFFFF;
                    if (temp_a0_2 != 0xA000) {
                        goto block_54;
                    }
                    if (var_v1 < 0x38U) {
                        var_a1 = D_800CE818;
                        goto block_51;
                    }
                    goto block_54;
                }
                var_v1 = temp_v1 & 0xFFFF;
                if (temp_a0_2 != 0xC000) {
                    goto block_54;
                }
                if (var_v1 < 0x78U) {
                    var_a1 = D_800CE82C;
                    goto block_51;
                }
                goto block_54;
            }
            var_v1 = temp_v1 & 0xFFFF;
            if (var_v1 < 0x6DU) {
                var_a1 = D_800CE828;
                goto block_51;
            }
            goto block_54;
        }
        var_v1 = temp_v1 & 0xFFFF;
        if (var_v1 < 0x21U) {
            var_a1 = D_800CE824;
            goto block_51;
        }
        goto block_54;
    }
    var_v1 = temp_v1 & 0xFFFF;
    if (var_v1 < 0x38U) {
        var_a1 = D_800CE814;
block_51:
        if (var_a1 != 0) {
            var_v0 = (var_v1 * 4) + var_a1;
block_53:
            return D_800CE800 + *var_v0;
        }
        goto block_54;
    }
block_54:
    return func_80087100(3, var_a1);
}
