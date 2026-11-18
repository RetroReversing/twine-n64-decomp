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

M2C_UNK func_80011950();                            /* extern */
M2C_UNK func_80081D50(M2C_UNK *, s32, u16, void *); /* extern */
s32 func_800828D8(s16);                             /* extern */
s32 func_800828EC(s32);                             /* extern */
M2C_UNK func_80087A80();                            /* extern */
M2C_UNK func_80087B04();                            /* extern */
M2C_UNK memset(M2C_UNK *, M2C_UNK, M2C_UNK);        /* extern */
extern M2C_UNK D_800C9D70;
extern M2C_UNK D_800C9DF8;
extern M2C_UNK D_800C9E80;
extern M2C_UNK D_800C9F08;
extern M2C_UNK D_800C9F90;
extern M2C_UNK D_800C9FC8;
extern M2C_UNK D_800CA068;
extern M2C_UNK D_800CA108;
extern M2C_UNK D_800CA1A8;
extern M2C_UNK D_800CA248;
extern M2C_UNK D_800CA278;
extern u8 D_800CEEB0;
extern M2C_UNK D_800E1A80;
extern u8 D_801002AE;
extern u16 D_801002BA;
extern s32 D_80102ED8;
extern M2C_UNK D_8010A500;
extern M2C_UNK D_8010D430;
extern M2C_UNK D_8010D434;
extern s16 D_8010D436;
extern M2C_UNK D_8010D456;
extern M2C_UNK D_80112E98;
extern s32 D_80112E9C;
extern s32 D_80112EA0;
extern s32 D_80112EAC;
extern M2C_UNK D_80112EB0;
extern M2C_UNK D_80115091;
extern M2C_UNK D_80115094;
extern M2C_UNK D_80115108;
extern s32 D_8011510C;
extern M2C_UNK D_80115110;
extern M2C_UNK D_80115114;
extern M2C_UNK D_80115118;
extern M2C_UNK D_8011511C;
extern M2C_UNK D_80115120;
extern M2C_UNK D_80115124;

void func_800821B4(void) {
    u16 sp16;
    s32 sp24;
    s32 sp2C;
    M2C_UNK *var_a0_2;
    M2C_UNK *var_a0_3;
    s16 *var_s2;
    s16 temp_s0;
    s16 temp_s0_2;
    s16 temp_s0_3;
    s16 temp_s0_4;
    s16 var_a0;
    s32 *var_s3;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s0_8;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s0_5;
    s32 var_s1;
    s32 var_s4;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s8 var_s3_2;
    s8 var_s6;
    u16 var_s2_2;
    u16 var_t8;
    u8 temp_fp;
    u8 temp_v1;
    void *temp_s1;
    void *temp_s5;

    func_80011950();
    temp_v1 = D_800CEEB0;
    if (temp_v1 == 1) {
        func_80087A80();
    }
    if (temp_v1 == 2) {
        func_80087B04();
    }
    var_s2 = &D_8010D436;
    var_s4 = 0;
    var_s3 = &D_8011510C;
    var_s1 = 0;
    __repair_rows: {
        temp_s0 = *(&D_8010D434 + var_s4);
        if (temp_s0 < 0) {
            var_s0 = temp_s0 + 4;
            var_v0 = -(var_s0 < 1);
        } else {
            var_s0 = temp_s0 - 4;
            var_v0 = (s32) ~var_s0 >> 0x1F;
        }
        var_s0_2 = ((var_s0 & var_v0) << 0x10) / 76;
        if (var_s0_2 < 0xFFFF0000) {
            var_s0_2 = -0x10000;
        } else if (var_s0_2 > 0x10000) {
            var_s0_2 = 0x10000;
        }
        *(&D_80115108 + var_s1) = var_s0_2;
        *(&D_80115110 + var_s1) = var_s0_2 - *(&D_80115108 + var_s1);
        temp_s0_2 = *(&D_8010D434 + var_s4);
        temp_v0 = func_800828EC(temp_s0_2 & -(func_800828D8(temp_s0_2) >= 0x21));
        if (temp_v0 != *(&D_80115120 + var_s1)) {
            *(&D_80115120 + var_s1) = temp_v0;
            *(&D_80115118 + var_s1) = temp_v0;
        } else {
            *(&D_80115118 + var_s1) = 0;
        }
        temp_s0_3 = *var_s2;
        if (temp_s0_3 < 0) {
            var_s0_3 = temp_s0_3 + 4;
            var_v0_2 = -(var_s0_3 < 1);
        } else {
            var_s0_3 = temp_s0_3 - 4;
            var_v0_2 = (s32) ~var_s0_3 >> 0x1F;
        }
        var_s0_4 = ((var_s0_3 & var_v0_2) << 0x10) / 76;
        if (var_s0_4 < 0xFFFF0000) {
            var_s0_4 = -0x10000;
        } else if (var_s0_4 > 0x10000) {
            var_s0_4 = 0x10000;
        }
        *(&D_80115114 + var_s1) = var_s0_4 - *var_s3;
        *var_s3 = var_s0_4;
        temp_s0_4 = *var_s2;
        temp_v0_2 = func_800828EC(temp_s0_4 & -(func_800828D8(temp_s0_4) >= 0x21));
        var_s2 += 8;
        if (temp_v0_2 != *(&D_80115124 + var_s1)) {
            *(&D_80115124 + var_s1) = temp_v0_2;
            *(&D_8011511C + var_s1) = temp_v0_2;
        } else {
            *(&D_8011511C + var_s1) = 0;
        }
        var_s4 += 8;
        var_s3 += 0xA0;
        var_s1 += 0xA0;
    }
if ((s32) var_s2 < (s32) &D_8010D456) goto __repair_rows;
    var_t8 = 4;
    if (D_80102ED8 != 0) {
        var_t8 = D_801002BA;
    }
    sp16 = var_t8;
    var_s6 = 0;
    if ((var_t8 << 0x10) > 0) {
        var_s7 = 0;
        sp24 = 0;
        sp2C = 0;
        do {
            memset(&D_80112E98, 0, 0x24);
            temp_s5 = *(&D_8010A500 + sp24);
            temp_fp = *(&D_80115091 + var_s7);
            var_a1 = 1;
            if (temp_s5 != NULL) {
                var_s3_2 = M2C_FIELD(M2C_FIELD(temp_s5, void **, 0x6C), s8 *, 0x183);
                var_s2_2 = *(&D_8010D430 + (var_s3_2 * 8));
                var_a0 = *((var_s3_2 * 2) + &D_800E1A80);
                temp_a2 = var_s2_2 & 0x2000;
                temp_a3 = var_s2_2 & 0x4000;
                temp_t2 = -(temp_a3 != 0);
                temp_t0 = var_s2_2 & 0x8000;
                temp_t1 = -(temp_t0 != 0);
                var_v0_3 = var_a0 & 7;
                do {
                    switch (var_v0_3) {             /* switch 1 */
                    default:                        /* switch 1 */
                        if (temp_a2 != 0) {
                            var_a0 = 1;
                        } else if (temp_a3 != 0) {
                            var_a0 = 2;
                        } else if (temp_t0 != 0) {
                            var_a0 = 3;
                        } else {
block_75:
                            var_a1 = 0;
                        }
                        break;
                    case 1:                         /* switch 1 */
                        if (temp_a2 == 0) {
                            var_a0 = 0;
                        } else {
                            D_80112E9C = 1;
                            var_a1 = 0;
                            if (temp_a3 != 0) {
                                D_80112EA0 = 1;
                            }
                        }
                        break;
                    case 2:                         /* switch 1 */
                        if (temp_a3 != 0) {
                            if (temp_a2 != 0) {
                                D_80112EAC = 1;
                                var_a0 = 4;
                            } else if (temp_t0 != 0) {
                                M2C_FIELD(&D_80112EB0, s32 *, 0) = 1;
                                var_a0 = 5;
                            } else {
                                goto block_75;
                            }
                        } else if (!(var_a0 & 8)) {
                            *(&D_80112EB0 - 0x10) = 1;
block_65:
                            var_a0 = 0;
                        } else {
                            var_a0 = 0;
                        }
                        break;
                    case 3:                         /* switch 1 */
                        if (temp_t0 != 0) {
                            if (temp_a2 != 0) {
                                *(&D_80112EB0 - 0xC) = 1;
                                var_a0 = 6;
                            } else if (temp_a3 != 0) {
                                M2C_FIELD(&D_80112EB0, s32 *, 4) = 1;
                                var_a0 = 7;
                            } else {
                                goto block_75;
                            }
                        } else {
                            if (!(var_a0 & 8)) {
                                *(&D_80112EB0 - 8) = 1;
                            }
                            goto block_65;
                        }
                        break;
                    case 4:                         /* switch 1 */
                        if (temp_a2 == 0) {
                            var_a0 = temp_t2 & 0xA;
                        } else {
                            goto block_75;
                        }
                        break;
                    case 5:                         /* switch 1 */
                        if (temp_t0 == 0) {
                            var_a0 = temp_t2 & 0xA;
                        } else {
                            goto block_75;
                        }
                        break;
                    case 6:                         /* switch 1 */
                        if (temp_a2 == 0) {
                            var_a0 = temp_t1 & 0xB;
                        } else {
                            goto block_75;
                        }
                        break;
                    case 7:                         /* switch 1 */
                        if (temp_a3 == 0) {
                            var_a0 = temp_t1 & 0xB;
                        } else {
                            goto block_75;
                        }
                        break;
                    }
                    var_v0_3 = var_a0 & 7;
                } while (var_a1 != 0);
                *((var_s3_2 * 2) + &D_800E1A80) = var_a0;
            } else {
                var_s3_2 = var_s6;
                var_s2_2 = *(&D_8010D430 + sp2C);
            }
            var_s0_5 = var_s3_2 & 0xFF;
            temp_s1 = var_s7 + &D_80115094;
            func_80081D50(&D_800CA278, var_s0_5, var_s2_2, temp_s1);
            if ((temp_s5 != NULL) && (D_801002AE == 0)) {
                switch (temp_fp) {                  /* switch 2 */
                case 0:                             /* switch 2 */
                    temp_s0_5 = var_s3_2 & 0xFF;
                    func_80081D50(&D_800C9D70, temp_s0_5, var_s2_2, temp_s1);
                    var_a0_2 = &D_800C9F90;
                    var_a1_2 = temp_s0_5;
                    break;
                case 1:                             /* switch 2 */
                    temp_s0_6 = var_s3_2 & 0xFF;
                    func_80081D50(&D_800C9DF8, temp_s0_6, var_s2_2, temp_s1);
                    var_a0_2 = &D_800C9F90;
                    var_a1_2 = temp_s0_6;
                    break;
                case 2:                             /* switch 2 */
                    var_a0_3 = &D_800C9FC8;
                    var_s0_5 = var_s3_2 & 0xFF;
block_91:
                    func_80081D50(var_a0_3, var_s0_5, var_s2_2, temp_s1);
                    var_a0_2 = &D_800CA248;
                    var_a1_2 = var_s0_5;
                    break;
                case 3:                             /* switch 2 */
                    var_a0_3 = &D_800CA068;
                    var_s0_5 = var_s3_2 & 0xFF;
                    goto block_91;
                case 4:                             /* switch 2 */
                    temp_s0_7 = var_s3_2 & 0xFF;
                    func_80081D50(&D_800C9E80, temp_s0_7, var_s2_2, temp_s1);
                    var_a0_2 = &D_800C9F90;
                    var_a1_2 = temp_s0_7;
                    break;
                case 5:                             /* switch 2 */
                    temp_s0_8 = var_s3_2 & 0xFF;
                    func_80081D50(&D_800C9F08, temp_s0_8, var_s2_2, temp_s1);
                    var_a0_2 = &D_800C9F90;
                    var_a1_2 = temp_s0_8;
                    break;
                case 6:                             /* switch 2 */
                    var_a0_3 = &D_800CA108;
                    var_s0_5 = var_s3_2 & 0xFF;
                    goto block_91;
                default:                            /* switch 2 */
                    var_a0_3 = &D_800CA1A8;
                    goto block_91;
                }
                func_80081D50(var_a0_2, var_a1_2, var_s2_2, temp_s1);
            }
            sp24 += 4;
            sp2C += 8;
            var_s6 += 1;
            var_s7 += 0xA0;
        } while (var_s6 < (s16) sp16);
    }
}
