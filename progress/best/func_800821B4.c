/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80011950();                            /* extern */
s32 func_80081D50(s32 *, s32, u16, void *); /* extern */
s32 func_800828D8(s16);                             /* extern */
s32 func_800828EC(s32);                             /* extern */
                            /* extern */
s32 func_80087B04();                            /* extern */
s32 memset(s32 *, s32, s32);        /* extern */
extern s32 D_800C9D70;
extern s32 D_800C9DF8;
extern s32 D_800C9E80;
extern s32 D_800C9F08;
extern s32 D_800C9F90;
extern s32 D_800C9FC8;
extern s32 D_800CA068;
extern s32 D_800CA108;
extern s32 D_800CA1A8;
extern s32 D_800CA248;
extern s32 D_800CA278;
extern u8 D_800CEEB0;
extern s32 D_800E1A80;
extern u8 D_801002AE;
extern u16 D_801002BA;
extern s32 D_80102ED8;
extern s32 D_8010A500;
extern s32 D_8010D430;
extern s32 D_8010D434;
extern s16 D_8010D436;
extern s32 D_8010D456;
extern s32 D_80112E98;
extern s32 D_80112E9C;
extern s32 D_80112EA0;
extern s32 D_80112EAC;
extern s32 D_80112EB0;
extern s32 D_80115091;
extern s32 D_80115094;
extern s32 D_80115108;
extern s32 D_8011510C;
extern s32 D_80115110;
extern s32 D_80115114;
extern s32 D_80115118;
extern s32 D_8011511C;
extern s32 D_80115120;
extern s32 D_80115124;

void func_800821B4(void) {
    volatile u64 frame_pad;
    s32 sp2C;
    u16 sp16;
    s32 *var_a0_2;
    unsigned sp24;
    
    s16 *var_s2;
    s16 temp_s0;
    s16 temp_s0_2;
    s16 temp_s0_3;
    s16 temp_s0_4;
    int var_a0;
    
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_s0_5;
    s32 temp_s0_6;
    register s32 temp_s0_7;
    unsigned int temp_s0_8;
    long temp_t0;
    s32 temp_t1;
    u32 temp_t2;
    unsigned int temp_v0;
    s32 temp_v0_2;
    long var_a1;
    s32 var_a1_2;
    s32 var_s0;
    s32 var_s0_2;
    register s32 var_s0_3;
    u32 var_s0_4;
    s32 var_s0_5;
    s32 var_s1;
    s32 var_s4;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    register s32 var_s3_2;
    s32 var_s6;
    s32 var_s2_2;
    u16 var_t8;
    u8 temp_fp;
    register u8 temp_v1;
    void *temp_s1;
    register void *temp_s5;

    func_80011950();
    temp_v1 = D_800CEEB0;
    if ((s32)temp_v1 == 1) {
        func_80087A80();
    }
    if (D_800CEEB0 == 2) {
        func_80087B04();
    }
    var_s2 = &D_8010D436;
    var_s4 = 0;
    var_a0_2 = &D_8011510C;
    var_s1 = 0;
    do { {
        temp_s0 = *(&(*(s32 *)0x8010d436) + var_s4);
        if (temp_s0 >= 0) {
            var_s0 = temp_s0 - 4;
            var_v0 = (s32) ~var_s0 >> 0x1F;
        } else {
            var_s0 = temp_s0 + 4;
            var_v0 = -(var_s0 < 1);
        }
        var_s0_2 = ((var_s0 & var_v0) << 0x10) / 76;
        if (var_s0_2 < 0xFFFF0000) {
            var_s0_2 = -0x10000;
        } else if (var_s0_2 > 0x10000) {
            var_s0_2 = 0x10000;
        }
        *(&(*(s32 *)0x8011510c) + var_s1) = var_s0_2;
        *(&D_80115110 + (int)var_s1) = var_s0_2 - *(&D_80115108 + var_s1);
        var_s0_2 = (s16)(*(&D_8010D434 + var_s4));
        temp_v0 = func_800828EC(var_s0_2 & -(func_800828D8((s32)var_s0_2) >= 0x21));
        if (temp_v0 != *(&D_80115120 + (s32)var_s1)) {
            *(&D_80115120 + var_s1) = temp_v0;
            *(&D_80115118 + var_s1) = temp_v0;
        } else {
            *(&D_80115118 + var_s1) = 0;
        }
        temp_s0_3 = *var_s2;
        if (temp_s0_3 < 0) {
            var_v0_2 = -(1 > var_s0_3);
            var_s0_3 = temp_s0_3 + 4;
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
        *(&D_80115114 + var_s1) = var_s0_4 - *var_a0_2;
        *var_a0_2 = var_s0_4;
        var_s0_4 = (s16)(*var_s2);
        temp_v0_2 = func_800828EC(var_s0_4 & -(func_800828D8(var_s0_4) >= 0x21));
        var_s2 += 4;
        if (temp_v0_2 != *(&D_80115124 + var_s1)) {
            *(&D_80115124 + var_s1) = temp_v0_2;
            *(&D_8011511C + var_s1) = temp_v0_2;
        } else {
            *(&D_8011511C + var_s1) = 0;
        }
        var_s4 += 8;
        var_a0_2 += 40;
        var_s1 += 0xA0;
    }
} while ((s32) var_s2 < (s32) &D_8010D456);
    var_t8 = 4;
    if (D_80102ED8 != 0) {
        var_t8 = D_801002BA;
    }
    sp16 = var_t8;
    if ((var_t8 << 0x10) > 0) {
        var_s6 = 0;
        var_s7 = 0;
        sp24 = 0;
        
        do {
            memset((sp2C = 0, &D_80112E98), 0, 0x24);
            temp_s5 = *(&D_8010A500 + sp24);
            temp_fp = *(&D_80115091 + var_s7);
            var_a1 = 1;
            if (temp_s5 != NULL) {
                var_s3_2 = (*(s8 *)((char *)((*(void **)((char *)(temp_s5) + 0x6C))) + 0x183));
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
                        } else if ((int)temp_a3 != 0) {
                            var_a0 = 2;
                        } else if (temp_t0 != 0) {
                            var_a0 = 3;
                        } else {
block_75:
                            var_a1 = 0;
                        }
                        break;
                    case 1:                         /* switch 1 */
                        if (!temp_a2) {
                            var_a0 = 0;
                        } else {
                            D_80112E9C = 1;
                            var_a1 = 0;
                            if ((u32)temp_a3 != 0) {
                                D_80112EA0 = 1;
                            }
                        }
                        break;
                    case 2:                         /* switch 1 */
                        if (temp_a3) {
                            if (temp_a2 != 0) {
                                D_80112EAC = 1;
                                var_a0 = 4;
                            } else if (temp_t0 != 0) {
                                (*(s32 *)((char *)(&D_80112EB0) + 0)) = 1;
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
                        if (temp_t0) {
                            if ((u32)temp_a2 != 0) {
                                *(&D_80112EB0 - 0xC) = 1;
                                var_a0 = 6;
                            } else if (temp_a3 != 0) {
                                (*(s32 *)((char *)(&D_80112EB0) + 4)) = 1;
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
            temp_s1 = var_s7 + &D_80115094;
            var_s0_5 = var_s6 & 0xFF;
            func_80081D50(&D_800CA278, var_s0_5, var_s2_2, temp_s1);
            if ((temp_s5 != NULL) && (D_801002AE == 0)) {
                switch (temp_fp) {                  /* switch 2 */
                case 0:                             /* switch 2 */
                    temp_s0_5 = var_s3_2 & 0xFF;
                    var_a0_2 = &D_800C9F90;
                    var_a1_2 = (s32)temp_s0_5;
                    func_80081D50(&D_800C9D70, temp_s0_5, var_s2_2, temp_s1);
                    break;
                case 1:                             /* switch 2 */
                    temp_s0_6 = var_s3_2 & 0xFF;
                    func_80081D50(&D_800C9DF8, temp_s0_6, var_s2_2, temp_s1);
                    var_a0_2 = &D_800C9F90;
                    var_a1_2 = temp_s0_6;
                    break;
                case 2:                             /* switch 2 */
                    var_a0_2 = &D_800C9FC8;
                    var_s0_5 = var_s3_2 & 0xFF;
block_91:
                    func_80081D50(var_a0_2, var_s0_5, var_s2_2, temp_s1);
                    var_a0_2 = &D_800CA248;
                    var_a1_2 = var_s0_5;
                    break;
                case 3:                             /* switch 2 */
                    var_a0_2 = &D_800CA068;
                    var_s0_5 = var_s3_2 & 0xFF;
                    goto block_91;
                case 4:                             /* switch 2 */
                    temp_s0_7 = var_s3_2 & 0xFF;
                    var_a1_2 = temp_s0_7;
                    func_80081D50(&D_800C9E80, temp_s0_7, var_s2_2, temp_s1);
                    var_a0_2 = &D_800C9F90;
                    break;
                case 5:                             /* switch 2 */
                    func_80081D50(&D_800C9F08, temp_s0_8, var_s2_2, temp_s1);
                    var_a1_2 = var_s3_2 & 0xFF;
    temp_s0_8 = var_a1_2;
                    var_a0_2 = &D_800C9F90;
                    var_a1_2 = temp_s0_8;
                    break;
                case 6:                             /* switch 2 */
                    var_a0_2 = &D_800CA108;
                    var_s0_5 = var_s3_2 & 0xFF;
                    goto block_91;
                default:                            /* switch 2 */
                    var_a0_2 = &D_800CA1A8;
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
