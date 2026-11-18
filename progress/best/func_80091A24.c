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

s32 func_8008C0D4();
s32 func_8008C11C();
s32 func_80091324();
s32 func_80091518();
s32 func_80091654();
s32 func_80092F9C();
s32 func_800930F4();
extern u8 D_800CF540;
extern char D_800E5AC4[];
extern char D_800E5BD4[];
extern char D_800E5BD8[];
extern char D_800E6A84[];
extern char D_800E6A85[];
extern char D_800E6A86[];
extern char D_800E6A8C[];
extern char D_800E6AA8[];
extern char D_800E6AAC[];
extern char D_800E6AB0[];
extern char D_800E6AB2[];
extern char D_800E6AB4[];
extern char D_800E6AB8[];

void func_80091A24(void *arg0, s32 *arg1, s32 arg2) {
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    u16 sp24;
    u16 sp26;
    u8 sp28;
    s8 sp30;
    s32 var_a3_2;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a1_5;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a3;
    s32 temp_s1_5;
    s32 temp_s2;
    s32 temp_s2_2;
    s32 temp_s2_3;
    s32 temp_s2_4;
    s32 temp_t0;
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_2;
    s32 var_a1_2;
    s32 var_a2_2;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    s32 var_v1_6;
    s32 var_v1_7;
    s32 var_v1_8;
    u16 temp_a3_2;
    u16 temp_s1;
    u16 temp_s1_2;
    u16 temp_s1_3;
    u16 temp_s1_4;
    u16 temp_s2_5;
    u16 var_a1;
    u32 var_a0;
    u32 var_a0_2;
    u32 var_a0_3;
    u32 var_a0_4;
    u32 var_a0_5;
    u32 var_a0_6;
    u32 var_a0_7;
    u8 temp_s3;
    u8 temp_v1;
    void *var_a2;
    void *var_a3;

    var_a0 = 0;
    temp_a2 = M2C_FIELD(arg0, s32 *, 0);
    var_v1 = 0;
    temp_a1 = temp_a2 & 0x7FFFFFFF;
loop_1:
    if ((*(D_800E6A85 + var_v1) != 0) || (*(D_800E5AC4 + var_v1) != temp_a1)) {
        var_a0 += 1;
        var_v1 += 0xFF8;
        if (var_a0 >= 8U) {
            var_t0 = -1;
        } else {
            goto loop_1;
        }
    } else {
        var_t0 = var_a0 | (temp_a2 & 0x80000000);
    }
    if (var_t0 != -1) {
        temp_v1 = M2C_FIELD(arg0, u8 *, 0x26);
        if (temp_v1 & 4) {
            var_a3 = (var_t0 * 0xFF8) + D_800E6A8C;
            var_a2 = arg0;
            do {
                M2C_FIELD(var_a3, s32 *, 0) = (s32) M2C_FIELD(var_a2, s32 *, 0);
                M2C_FIELD(var_a3, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 4);
                M2C_FIELD(var_a3, s32 *, 8) = (s32) M2C_FIELD(var_a2, s32 *, 8);
                M2C_FIELD(var_a3, s32 *, 0xC) = (s32) M2C_FIELD(var_a2, s32 *, 0xC);
                var_a2 += 0x10;
                var_a3 += 0x10;
            } while (var_a2 != (arg0 + 0x20));
            M2C_FIELD(var_a3, s32 *, 0) = (s32) M2C_FIELD(var_a2, s32 *, 0);
            M2C_FIELD(var_a3, s32 *, 4) = (s32) M2C_FIELD(var_a2, s32 *, 4);
            temp_v0 = var_t0 * 0xFF8;
            *(D_800E6AB8 + temp_v0) = 1;
            *(D_800E6AB4 + temp_v0) = arg1;
            *(D_800E6AB2 + temp_v0) = *(D_800E6AB2 + temp_v0) & 0xFB;
            *arg1 = M2C_FIELD(arg0, s32 *, 0) | 0x80000000;
            return;
        }
        temp_v0_2 = temp_v1 & 1;
        if (arg2 & 0xFF) {
            if (temp_v0_2 != 0) {
                func_80091654(0U, M2C_FIELD(arg0, u16 *, 4), M2C_FIELD(arg0, s32 *, 0), 2);
            } else if (!(temp_v1 & 0x40)) {
                func_80091654(0U, M2C_FIELD(arg0, u16 *, 4), M2C_FIELD(arg0, s32 *, 0), 1);
            } else {
                func_80091654(0U, M2C_FIELD(arg0, u16 *, 4), M2C_FIELD(arg0, s32 *, 0), 3);
            }
        } else if (temp_v0_2 != 0) {
            temp_s1 = M2C_FIELD(arg0, u16 *, 4);
            temp_s2 = M2C_FIELD(arg0, s32 *, 0);
            if (D_800CF540 != 0) {
                func_8008C0D4(var_a0, temp_a1, temp_a2);
                var_a1 = temp_s1;
                var_a2_2 = temp_s2;
                var_a3_2 = 2;
                goto block_29;
            }
        } else if (temp_v1 & 0x40) {
            temp_s1_2 = M2C_FIELD(arg0, u16 *, 4);
            temp_s2_2 = M2C_FIELD(arg0, s32 *, 0);
            if (D_800CF540 != 0) {
                func_8008C0D4(var_a0, temp_a1, temp_a2);
                var_a1 = temp_s1_2;
                var_a2_2 = temp_s2_2;
                var_a3_2 = 3;
                goto block_29;
            }
        } else {
            temp_s1_3 = M2C_FIELD(arg0, u16 *, 4);
            temp_s2_3 = M2C_FIELD(arg0, s32 *, 0);
            if (D_800CF540 != 0) {
                func_8008C0D4(var_a0, temp_a1, temp_a2);
                var_a1 = temp_s1_3;
                var_a2_2 = temp_s2_3;
                var_a3_2 = 1;
block_29:
                func_80091654(0U, var_a1, var_a2_2, var_a3_2);
                func_8008C11C();
            }
        }
        if (arg1 != NULL) {
            var_a0_2 = 0;
            if (M2C_FIELD(arg0, u8 *, 0x26) & 2) {
                temp_a2_2 = M2C_FIELD(arg0, s32 *, 8);
                var_v1_2 = 0;
                temp_a1_2 = temp_a2_2 & 0x7FFFFFFF;
loop_33:
                if ((*(D_800E6A85 + var_v1_2) != 0) || (*(D_800E5AC4 + var_v1_2) != temp_a1_2)) {
                    var_a0_2 += 1;
                    var_v1_2 += 0xFF8;
                    if (var_a0_2 >= 8U) {
                        var_v1_3 = -1;
                    } else {
                        goto loop_33;
                    }
                } else {
                    var_v1_3 = var_a0_2 | (temp_a2_2 & 0x80000000);
                }
                if (var_v1_3 != -1) {
                    var_a0_3 = 0;
                    if (arg2 & 0xFF) {
                        temp_a1_3 = M2C_FIELD(arg0, s32 *, 8);
                        var_v1_4 = 0;
loop_40:
                        if ((*(D_800E6A85 + var_v1_4) != 0) || (*(D_800E5AC4 + var_v1_4) != (temp_a1_3 & 0x7FFFFFFF))) {
                            var_a0_3 += 1;
                            var_v1_4 += 0xFF8;
                            if (var_a0_3 >= 8U) {
                                var_v0 = -1;
                            } else {
                                goto loop_40;
                            }
                        } else {
                            var_v0 = var_a0_3 | (temp_a1_3 & 0x80000000);
                        }
                        if (var_v0 != -1) {
                            if (var_v0 >= 0) {
                                *(D_800E6A84 + (var_v0 * 0xFF8)) = 1;
                            } else {
                                temp_v1_2 = (var_v0 & 0x7FFFFFFF) * 0xFF8;
                                *(D_800E6AB2 + temp_v1_2) = *(D_800E6AB2 + temp_v1_2) & 0xF7;
                            }
                        }
                        func_80091654(M2C_FIELD(arg0, u8 *, 0x18), M2C_FIELD(arg0, u16 *, 0xC), M2C_FIELD(arg0, s32 *, 8), 0);
                        var_a0_4 = 0;
                        if (M2C_FIELD(arg0, u8 *, 0x26) & 0x10) {
                            temp_a1_4 = M2C_FIELD(arg0, s32 *, 8);
                            temp_a3 = M2C_FIELD(arg0, s32 *, 0x1C);
                            temp_t0 = M2C_FIELD(arg0, s32 *, 0x20);
                            var_v1_5 = 0;
loop_51:
                            if ((*(D_800E6A85 + var_v1_5) != 0) || (*(D_800E5AC4 + var_v1_5) != (temp_a1_4 & 0x7FFFFFFF))) {
                                var_a0_4 += 1;
                                var_v1_5 += 0xFF8;
                                if (var_a0_4 >= 8U) {
                                    var_v0_2 = -1;
                                } else {
                                    goto loop_51;
                                }
                            } else {
                                var_v0_2 = var_a0_4 | (temp_a1_4 & 0x80000000);
                            }
                            if (var_v0_2 != -1) {
                                if (var_v0_2 >= 0) {
                                    temp_v0_3 = var_v0_2 * 0xFF8;
                                    *(D_800E5BD4 + temp_v0_3) = temp_a3;
                                    *(D_800E5BD8 + temp_v0_3) = temp_t0;
                                } else {
                                    temp_v0_4 = (var_v0_2 & 0x7FFFFFFF) * 0xFF8;
                                    *(D_800E6AA8 + temp_v0_4) = temp_a3;
                                    *(D_800E6AAC + temp_v0_4) = temp_t0;
                                    *(D_800E6AB2 + temp_v0_4) = *(D_800E6AB2 + temp_v0_4) | 0x10;
                                }
                            }
                        }
                        var_a0_5 = 0;
                        if (M2C_FIELD(arg0, u8 *, 0x26) & 0x20) {
                            temp_a1_5 = M2C_FIELD(arg0, s32 *, 8);
                            temp_a3_2 = M2C_FIELD(arg0, u16 *, 0x24);
                            var_v1_6 = 0;
loop_62:
                            if ((*(D_800E6A85 + var_v1_6) != 0) || (*(D_800E5AC4 + var_v1_6) != (temp_a1_5 & 0x7FFFFFFF))) {
                                var_a0_5 += 1;
                                var_v1_6 += 0xFF8;
                                if (var_a0_5 >= 8U) {
                                    var_v0_3 = -1;
                                } else {
                                    goto loop_62;
                                }
                            } else {
                                var_v0_3 = var_a0_5 | (temp_a1_5 & 0x80000000);
                            }
                            if (var_v0_3 != -1) {
                                if (var_v0_3 >= 0) {
                                    *(D_800E6A86 + (var_v0_3 * 0xFF8)) = temp_a3_2;
                                } else {
                                    temp_v0_5 = (var_v0_3 & 0x7FFFFFFF) * 0xFF8;
                                    *(D_800E6AB0 + temp_v0_5) = temp_a3_2;
                                    *(D_800E6AB2 + temp_v0_5) = *(D_800E6AB2 + temp_v0_5) | 0x20;
                                }
                            }
                        }
                    } else {
                        func_80091324(M2C_FIELD(arg0, s32 *, 8), temp_a1_2, temp_a2_2);
                        temp_s3 = M2C_FIELD(arg0, u8 *, 0x18);
                        temp_s1_4 = M2C_FIELD(arg0, u16 *, 0xC);
                        temp_s2_4 = M2C_FIELD(arg0, s32 *, 8);
                        if (D_800CF540 != 0) {
                            func_8008C0D4();
                            func_80091654(temp_s3, temp_s1_4, temp_s2_4, 0);
                            func_8008C11C();
                        }
                        if (M2C_FIELD(arg0, u8 *, 0x26) & 0x10) {
                            func_80091518(M2C_FIELD(arg0, s32 *, 8), M2C_FIELD(arg0, s32 *, 0x1C), M2C_FIELD(arg0, s32 *, 0x20));
                        }
                        if (M2C_FIELD(arg0, u8 *, 0x26) & 0x20) {
                            temp_s1_5 = M2C_FIELD(arg0, s32 *, 8);
                            temp_s2_5 = M2C_FIELD(arg0, u16 *, 0x24);
                            if (D_800CF540 != 0) {
                                func_8008C0D4();
                                var_a0_6 = 0;
                                temp_a2_3 = temp_s1_5 & 0x7FFFFFFF;
                                var_v1_7 = 0;
loop_78:
                                if ((*(D_800E6A85 + var_v1_7) != 0) || (*(D_800E5AC4 + var_v1_7) != temp_a2_3)) {
                                    var_a0_6 += 1;
                                    var_v1_7 += 0xFF8;
                                    if (var_a0_6 >= 8U) {
                                        var_v0_4 = -1;
                                    } else {
                                        goto loop_78;
                                    }
                                } else {
                                    var_v0_4 = var_a0_6 | (temp_s1_5 & 0x80000000);
                                }
                                var_a1_2 = var_v0_4;
                                if (var_a1_2 != -1) {
                                    if (var_a1_2 >= 0) {
                                        *(D_800E6A86 + (var_a1_2 * 0xFF8)) = temp_s2_5;
                                    } else {
                                        var_a1_2 &= 0x7FFFFFFF;
                                        temp_v0_6 = var_a1_2 * 0xFF8;
                                        *(D_800E6AB0 + temp_v0_6) = temp_s2_5;
                                        *(D_800E6AB2 + temp_v0_6) = *(D_800E6AB2 + temp_v0_6) | 0x20;
                                    }
                                }
                                func_8008C11C(var_a0_6, var_a1_2, temp_a2_3);
                            }
                        }
                    }
                    *arg1 = M2C_FIELD(arg0, s32 *, 8);
                    return;
                }
                *arg1 = var_v1_3;
                return;
            }
            sp18 = 4;
            if (M2C_FIELD(arg0, u8 *, 0x26) & 8) {
                sp18 = 0x14;
            }
            if (M2C_FIELD(arg0, u8 *, 0x26) & 0x20) {
                sp18 |= 2;
                sp24 = M2C_FIELD(arg0, u16 *, 0x24);
            }
            if (M2C_FIELD(arg0, u8 *, 0x26) & 0x10) {
                sp18 |= 1;
                sp1C = M2C_FIELD(arg0, s32 *, 0x1C);
                sp20 = M2C_FIELD(arg0, s32 *, 0x20);
            }
            sp26 = M2C_FIELD(arg0, u16 *, 0xC);
            sp30 = 0;
            sp28 = M2C_FIELD(arg0, u8 *, 0x18);
            if (arg2 & 0xFF) {
                temp_v0_7 = func_80092F9C(M2C_FIELD(arg0, u16 *, 0x14), M2C_FIELD(arg0, u16 *, 0x16), M2C_FIELD(arg0, s32 *, 0x10), &sp18, 1);
                *arg1 = temp_v0_7;
                if ((temp_v0_7 != -1) && (M2C_FIELD(arg0, u8 *, 0x26) & 0x80)) {
                    var_a0_7 = 0;
                    var_v1_8 = 0;
loop_100:
                    if ((*(D_800E6A85 + var_v1_8) != 0) || (*(D_800E5AC4 + var_v1_8) != (temp_v0_7 & 0x7FFFFFFF))) {
                        var_a0_7 += 1;
                        var_v1_8 += 0xFF8;
                        if (var_a0_7 >= 8U) {
                            var_v0_5 = -1;
                        } else {
                            goto loop_100;
                        }
                    } else {
                        var_v0_5 = var_a0_7 | (temp_v0_7 & 0x80000000);
                    }
                    if (var_v0_5 != -1) {
                        if (var_v0_5 >= 0) {
                            temp_v0_8 = var_v0_5 * 0xFF8;
                            *(D_800E5BD4 + temp_v0_8) = 0;
                            *(D_800E5BD8 + temp_v0_8) = 0;
                            return;
                        }
                        temp_v0_9 = (var_v0_5 & 0x7FFFFFFF) * 0xFF8;
                        *(D_800E6AA8 + temp_v0_9) = 0;
                        *(D_800E6AAC + temp_v0_9) = 0;
                        *(D_800E6AB2 + temp_v0_9) = *(D_800E6AB2 + temp_v0_9) | 0x10;
                    }
                }
            } else {
                temp_v0_10 = func_800930F4(M2C_FIELD(arg0, u16 *, 0x14), M2C_FIELD(arg0, u16 *, 0x16), M2C_FIELD(arg0, s32 *, 0x10), &sp18);
                *arg1 = temp_v0_10;
                if ((temp_v0_10 != -1) && (M2C_FIELD(arg0, u8 *, 0x26) & 0x80)) {
                    func_80091518(temp_v0_10, 0, 0);
                }
            }
        }
    }
}
