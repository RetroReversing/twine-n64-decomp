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

extern float D_800D3E24;
extern int D_800D3E28;
extern int D_800D3E2C;
s32 func_80047E4C();
s32 func_800487F0();
s32 func_8004886C();
s32 func_800488D4();
s32 func_80048CC0();
s32 func_8004D910();
s32 func_8004E418();
s32 func_80082D24();
s32 func_80083A6C();
s32 func_80083B64();
extern void *D_80108788;
extern void **D_80108F84;

s32 func_8004BCC0(void **arg0, void *arg1, void *arg2, f32 arg3) {
    f32 sp28;
    f32 sp2C;
    f32 sp30;
    f32 sp38;
    f32 sp3C;
    f32 sp40;
    f32 sp48;
    f32 sp4C;
    f32 sp50;
    s32 sp58;
    s16 sp88;                                       /* compiler-managed */
    s16 sp8A;
    s16 sp8C;                                       /* compiler-managed */
    f32 sp90;
    s32 sp94;
    s32 sp98;
    f32 spA0;
    f32 spA4;
    s32 spA8;
    f32 spD0;
    f32 spD4;
    f32 spD8;
    f32 spE0;
    s32 spE4;
    s32 spE8;
    f32 spF0;
    void *spFC;
    s32 *sp104;
    f32 *sp10C;
    f32 *sp114;
    f32 *sp11C;
    f32 *sp124;
    f32 *sp12C;
    s16 *sp134;
    f32 *sp13C;
    f32 *sp144;
    f32 temp_fs2;
    f32 var_fs0;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s3_2;
    s32 temp_s4;
    s32 temp_s6;
    s32 temp_s7;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1_11;
    s32 temp_v1_13;
    s32 temp_v1_3;
    s32 temp_v1_5;
    s32 temp_v1_7;
    s32 temp_v1_9;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s2_4;
    char *var_s4;
    char *var_s4_2;
    u16 temp_v1_10;
    u16 temp_v1_12;
    u16 temp_v1_2;
    u16 temp_v1_4;
    u16 temp_v1_6;
    u16 temp_v1_8;
    u32 temp_s3;
    u32 temp_v1;
    u32 var_s0_3;
    u32 var_s0_4;
    u32 var_s0_5;
    u32 var_s0_6;
    void **var_s5;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_a0_4;
    void *temp_s1;
    void *temp_s2;
    void *var_s1;
    void *var_s3;
    void *var_s3_2;

    var_fs0 = arg3;
    var_s5 = arg0;
    spFC = arg2;
    temp_fs2 = var_fs0;
    if (var_s5 != NULL) {
        var_s1 = *var_s5;
        sp28 = M2C_FIELD(arg1, f32 *, 0);
        sp2C = M2C_FIELD(arg1, f32 *, 4) + var_fs0;
        D_80108788 = NULL;
        D_80108F84 = NULL;
        sp30 = M2C_FIELD(arg1, f32 *, 8);
        if (var_s1 != NULL) {
            sp104 = &sp58;
            sp10C = &sp38;
            sp114 = &sp48;
            sp11C = &sp90;
            sp124 = &spA0;
            sp12C = &spA4;
            do {
                if (M2C_FIELD(var_s1, void **, 0x70) != NULL) {
                    temp_s3 = M2C_FIELD(var_s1, s32 *, 0x58) & 0x400;
                    if ((temp_s3 == 0) && (M2C_FIELD(var_s1, s32 *, 0x5C) & 0x200) && ((func_800487F0(var_s1, arg1, temp_fs2) << 0x18) != 0)) {
                        temp_s2 = M2C_FIELD(var_s1, void **, 0x70);
                        sp88 = (s16) (s32) -M2C_FIELD(var_s1, f32 *, 0x3C);
                        sp8A = (s16) (s32) -M2C_FIELD(var_s1, f32 *, 0x40);
                        sp8C = (s16) (s32) -M2C_FIELD(var_s1, f32 *, 0x44);
                        func_80082D24(&sp88, sp104);
                        sp38 = M2C_FIELD(arg1, f32 *, 0) - M2C_FIELD(var_s1, f32 *, 0x24);
                        sp3C = M2C_FIELD(arg1, f32 *, 4) - M2C_FIELD(var_s1, f32 *, 0x28);
                        sp40 = M2C_FIELD(arg1, f32 *, 8) - M2C_FIELD(var_s1, f32 *, 0x2C);
                        sp48 = sp28 - M2C_FIELD(var_s1, f32 *, 0x24);
                        sp4C = sp2C - M2C_FIELD(var_s1, f32 *, 0x28);
                        sp50 = sp30 - M2C_FIELD(var_s1, f32 *, 0x2C);
                        func_80083A6C(sp104, sp10C);
                        temp_s0 = temp_s2 + 0x18;
                        func_80083A6C(sp104, sp114);
                        if ((func_800488D4(temp_s0, sp10C, sp114) << 0x18) != 0) {
                            sp90 = D_800D3E24;
                            sp94 = D_800D3E28;
                            sp98 = D_800D3E2C;
                            temp_v0 = func_8004E418(temp_s0, sp10C, sp114) & 0xFFFF;
                            temp_s7 = temp_v0 & 0xFF;
                            temp_s6 = temp_v0 & 0xFF00;
                            func_80083A6C(sp104, sp11C);
                            temp_v1 = M2C_FIELD(temp_s2, u8 *, 0x48) & 4;
                            if (temp_v1 != 0) {
                                var_s4 = M2C_FIELD(temp_s2, u16 **, 0x3C);
                                var_s0 = 0;
                                if (temp_s3 < (u16) M2C_FIELD(temp_s2, u16 *, 0x40)) {
                                    var_s3 = var_s4 + 4;
                                    do {
                                        temp_v1_2 = *(u16 *)(((var_s0 & 0xFFFF) * 2) + M2C_FIELD(temp_s2, s32 *, 0x38));
                                        if ((temp_s7 & temp_v1_2) && (temp_s6 & temp_v1_2)) {
                                            temp_v1_3 = M2C_FIELD(temp_s2, s32 *, 0x34);
                                            if ((func_80048CC0(&sp38, &sp90, temp_v1_3 + (*(u16 *)var_s4 * 0xC), temp_v1_3 + (M2C_FIELD(var_s3, u16 *, -2) * 0xC), temp_v1_3 + (M2C_FIELD(var_s3, u16 *, 0) * 0xC), sp124) & 0xFF) && (spA0 >= 0.0f) && (spA0 < var_fs0)) {
                                                var_fs0 = spA0;
                                                D_80108788 = var_s1;
                                                D_80108F84 = NULL;
                                            }
                                        }
                                        var_s3 += 6;
                                        var_s0 += 1;
                                        var_s4 += 6;
                                    } while ((u32) (var_s0 & 0xFFFF) < (u16) M2C_FIELD(temp_s2, u16 *, 0x40));
                                }
                            } else {
                                var_s4_2 = M2C_FIELD(temp_s2, u16 **, 0x3C);
                                var_s0_2 = 0;
                                if (temp_v1 < (u16) M2C_FIELD(temp_s2, u16 *, 0x40)) {
                                    var_s3_2 = var_s4_2 + 2;
                                    do {
                                        temp_v1_4 = *(u16 *)(((var_s0_2 & 0xFFFF) * 2) + M2C_FIELD(temp_s2, s32 *, 0x38));
                                        if ((temp_s7 & temp_v1_4) && (temp_s6 & temp_v1_4)) {
                                            temp_v1_5 = M2C_FIELD(temp_s2, s32 *, 0x34);
                                            if ((func_80048CC0(&sp38, &sp90, temp_v1_5 + (*(u16 *)var_s4_2 * 0xC), temp_v1_5 + (M2C_FIELD(var_s3_2, u8 *, -1) * 0xC), temp_v1_5 + (M2C_FIELD(var_s3_2, u8 *, 0) * 0xC), sp12C) & 0xFF) && (spA4 >= 0.0f) && (spA4 < var_fs0)) {
                                                var_fs0 = spA4;
                                                D_80108788 = var_s1;
                                                D_80108F84 = NULL;
                                            }
                                        }
                                        var_s3_2 += 3;
                                        var_s0_2 += 1;
                                        var_s4_2 += 3;
                                    } while ((u32) (var_s0_2 & 0xFFFF) < (u16) M2C_FIELD(temp_s2, u16 *, 0x40));
                                }
                            }
                        }
                    }
                }
                var_s1 = M2C_FIELD(var_s1, void **, 0);
            } while (var_s1 != NULL);
        }
        if (var_s5 != NULL) {
            sp134 = &sp88;
            sp13C = &spD0;
            sp144 = &spE0;
            do {
                if ((M2C_FIELD(var_s5, s32 *, 0x50) & 0x200) && ((func_8004886C(var_s5 + 0x40, arg1, temp_fs2) << 0x18) != 0)) {
                    temp_s1 = M2C_FIELD(var_s5, void **, 0x3C);
                    sp88 = M2C_FIELD(arg1, f32 *, 0);
                    sp8C = M2C_FIELD(arg1, f32 *, 4);
                    sp90 = M2C_FIELD(arg1, f32 *, 8);
                    spD0 = sp28;
                    spD4 = sp2C;
                    spD8 = sp30;
                    if (((u32) M2C_FIELD(var_s5, u32 *, 0x5C) >> 0x17) & 1) {
                        sp88 -= M2C_FIELD(var_s5, f32 *, 0x24);
                        sp8C -= M2C_FIELD(var_s5, f32 *, 0x28);
                        sp90 -= M2C_FIELD(var_s5, f32 *, 0x2C);
                        spD0 -= M2C_FIELD(var_s5, f32 *, 0x24);
                        spD4 -= M2C_FIELD(var_s5, f32 *, 0x28);
                        spD8 -= M2C_FIELD(var_s5, f32 *, 0x2C);
                    }
                    if (((u32) M2C_FIELD(var_s5, u32 *, 0x5C) >> 0x17) & 2) {
                        func_80047E4C(var_s5, 0, &spA8);
                        func_80083B64(&spA8, sp134);
                        func_80083B64(&spA8, (s16 *) sp13C);
                    }
                    temp_s0_2 = temp_s1 + 0x18;
                    if ((func_800488D4(temp_s0_2, (f32 *) sp134, sp13C) << 0x18) != 0) {
                        spE0 = D_800D3E24;
                        spE4 = D_800D3E28;
                        spE8 = D_800D3E2C;
                        temp_v0_2 = func_8004E418(temp_s0_2, (f32 *) sp134, sp13C);
                        temp_s4 = temp_v0_2 & 0xFF;
                        temp_s3_2 = temp_v0_2 & 0xFF00;
                        if (!(((u32) M2C_FIELD(var_s5, u32 *, 0x5C) >> 0x17) & 2) || (func_80083B64(&spA8, (s16 *) sp144), ((((u32) M2C_FIELD(var_s5, u32 *, 0x5C) >> 0x17) & 2) == 0))) {
                            if (M2C_FIELD(temp_s1, u8 *, 0x48) & 4) {
                                var_s0_3 = 0;
                                if (M2C_FIELD(temp_s1, u16 *, 0x40) != 0) {
                                    var_s2 = 0;
                                    do {
                                        temp_v1_6 = *(u16 *)((var_s0_3 * 2) + M2C_FIELD(temp_s1, s32 *, 0x38));
                                        temp_a0 = M2C_FIELD(temp_s1, s32 *, 0x3C) + var_s2;
                                        if ((temp_s4 & temp_v1_6) && (temp_s3_2 & temp_v1_6)) {
                                            temp_v1_7 = M2C_FIELD(temp_s1, s32 *, 0x34);
                                            if ((func_8004D910(&sp88, &spE0, temp_v1_7 + (M2C_FIELD(temp_a0, u16 *, 0) * 0xC), temp_v1_7 + (M2C_FIELD(temp_a0, u16 *, 2) * 0xC), temp_v1_7 + (M2C_FIELD(temp_a0, u16 *, 4) * 0xC), &spF0) & 0xFF) && (spF0 >= 0.0f) && (spF0 < var_fs0)) {
                                                var_fs0 = spF0;
                                                D_80108788 = NULL;
                                                D_80108F84 = var_s5;
                                            }
                                        }
                                        var_s0_3 += 1;
                                        var_s2 += 6;
                                    } while (var_s0_3 < (u16) M2C_FIELD(temp_s1, u16 *, 0x40));
                                }
                            } else {
                                var_s0_4 = 0;
                                if (M2C_FIELD(temp_s1, u16 *, 0x40) != 0) {
                                    var_s2_2 = 0;
                                    do {
                                        temp_v1_8 = *(u16 *)((var_s0_4 * 2) + M2C_FIELD(temp_s1, s32 *, 0x38));
                                        temp_a0_2 = M2C_FIELD(temp_s1, s32 *, 0x3C) + var_s2_2;
                                        if ((temp_s4 & temp_v1_8) && (temp_s3_2 & temp_v1_8)) {
                                            temp_v1_9 = M2C_FIELD(temp_s1, s32 *, 0x34);
                                            if ((func_8004D910(&sp88, &spE0, temp_v1_9 + (M2C_FIELD(temp_a0_2, u8 *, 0) * 0xC), temp_v1_9 + (M2C_FIELD(temp_a0_2, u8 *, 1) * 0xC), temp_v1_9 + (M2C_FIELD(temp_a0_2, u8 *, 2) * 0xC), &spF0) & 0xFF) && (spF0 >= 0.0f) && (spF0 < var_fs0)) {
                                                var_fs0 = spF0;
                                                D_80108788 = NULL;
                                                D_80108F84 = var_s5;
                                            }
                                        }
                                        var_s0_4 += 1;
                                        var_s2_2 += 3;
                                    } while (var_s0_4 < (u16) M2C_FIELD(temp_s1, u16 *, 0x40));
                                }
                            }
                        } else if (M2C_FIELD(temp_s1, u8 *, 0x48) & 4) {
                            var_s0_5 = 0;
                            if (M2C_FIELD(temp_s1, u16 *, 0x40) != 0) {
                                var_s2_3 = 0;
                                do {
                                    temp_v1_10 = *(u16 *)((var_s0_5 * 2) + M2C_FIELD(temp_s1, s32 *, 0x38));
                                    temp_a0_3 = M2C_FIELD(temp_s1, s32 *, 0x3C) + var_s2_3;
                                    if ((temp_s4 & temp_v1_10) && (temp_s3_2 & temp_v1_10)) {
                                        temp_v1_11 = M2C_FIELD(temp_s1, s32 *, 0x34);
                                        if ((func_8004D910(&sp88, &spE0, temp_v1_11 + (M2C_FIELD(temp_a0_3, u16 *, 0) * 0xC), temp_v1_11 + (M2C_FIELD(temp_a0_3, u16 *, 2) * 0xC), temp_v1_11 + (M2C_FIELD(temp_a0_3, u16 *, 4) * 0xC), &spF0) & 0xFF) && (spF0 >= 0.0f) && (spF0 < var_fs0)) {
                                            var_fs0 = spF0;
                                            D_80108788 = NULL;
                                            D_80108F84 = var_s5;
                                        }
                                    }
                                    var_s0_5 += 1;
                                    var_s2_3 += 6;
                                } while (var_s0_5 < (u16) M2C_FIELD(temp_s1, u16 *, 0x40));
                            }
                        } else {
                            var_s0_6 = 0;
                            if (M2C_FIELD(temp_s1, u16 *, 0x40) != 0) {
                                var_s2_4 = 0;
                                do {
                                    temp_v1_12 = *(u16 *)((var_s0_6 * 2) + M2C_FIELD(temp_s1, s32 *, 0x38));
                                    temp_a0_4 = M2C_FIELD(temp_s1, s32 *, 0x3C) + var_s2_4;
                                    if ((temp_s4 & temp_v1_12) && (temp_s3_2 & temp_v1_12)) {
                                        temp_v1_13 = M2C_FIELD(temp_s1, s32 *, 0x34);
                                        if ((func_8004D910(&sp88, &spE0, temp_v1_13 + (M2C_FIELD(temp_a0_4, u8 *, 0) * 0xC), temp_v1_13 + (M2C_FIELD(temp_a0_4, u8 *, 1) * 0xC), temp_v1_13 + (M2C_FIELD(temp_a0_4, u8 *, 2) * 0xC), &spF0) & 0xFF) && (spF0 >= 0.0f) && (spF0 < var_fs0)) {
                                            var_fs0 = spF0;
                                            D_80108788 = NULL;
                                            D_80108F84 = var_s5;
                                        }
                                    }
                                    var_s0_6 += 1;
                                    var_s2_4 += 3;
                                } while (var_s0_6 < (u16) M2C_FIELD(temp_s1, u16 *, 0x40));
                            }
                        }
                    }
                }
                var_s5 = M2C_FIELD(var_s5, void ***, 0x14);
            } while (var_s5 != NULL);
        }
        if (var_fs0 == temp_fs2) {
            goto block_83;
        }
        M2C_FIELD(spFC, f32 *, 0) = (f32) M2C_FIELD(arg1, f32 *, 0);
        M2C_FIELD(spFC, f32 *, 4) = (f32) (M2C_FIELD(arg1, f32 *, 4) + var_fs0);
        M2C_FIELD(spFC, f32 *, 8) = (f32) M2C_FIELD(arg1, f32 *, 8);
        return 1;
    }
block_83:
    return 0;
}
