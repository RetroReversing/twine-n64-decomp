/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
s32 func_80091324();
s32 func_80091518();
s32 func_80091654();
s32 func_80092F9C();
s32 func_800930F4();
extern u8 D_800CF540;
extern char gSndEntities[];
extern char D_800E5BD4[];
extern char D_800E5BD8[];
extern char D_800E6A84[];
extern u8 D_800E6A85[];
extern char D_800E6A86[];
extern char D_800E6A8C[];
extern char D_800E6AA8[];
extern char D_800E6AAC[];
extern char D_800E6AB0[];
extern char D_800E6AB2[];
extern char D_800E6AB4[];
extern char D_800E6AB8[];

typedef struct { int value; } __repair_field_0;
void func_80091A24(void *arg0, s32 *arg1, s32 arg2) {
    s32 __repair_store_0;
    s32 __repair_store_1;
    s32 __repair_store_2;
    s32 sp18[3];
    u16 sp24;
    u16 sp26;
    u8 sp28;
    s8 sp30;
    volatile s64 reserve[2];
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
    u32 temp_v0_10;
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
    temp_a2 = ((__repair_field_0 *)arg0)->value;
    var_v1 = 0;
    temp_a1 = temp_a2 & 0x7FFFFFFF;
loop_1:
    if ((*(D_800E6A85 + var_v1) != 0) || (*(s32 *)(gSndEntities + var_v1) != temp_a1)) {
        var_a0 += 1;
        var_v1 += 0xFF8;
        if ((s32)var_a0 >= 8U) {
            var_t0 = -1;
        } else {
            goto loop_1;
        }
    } else {
        var_t0 = var_a0 | (temp_a2 & 0x7fffffff);
    }
    if (var_t0 != -1) {
        temp_v1 = (*(u8 *)((char *)(arg0) + 0x26));
        if (temp_v1 & 4) {
            var_a3 = (var_t0 * 0xFF8) + D_800E6A8C;
            var_a2 = arg0;
            do {
                ((__repair_field_0 *)var_a3)->value = (s32) ((__repair_field_0 *)var_a2)->value;
                __repair_store_0 = (s32) (*(s32 *)((char *)(var_a2) + 4));
                __repair_store_2 = (s32) (*(s32 *)((char *)(var_a2) + 0xC));
                (*(s32 *)((char *)(var_a3) + 4)) = __repair_store_0;
                __repair_store_1 = (s32) (*(s32 *)((char *)(var_a2) + 8));
                (*(s32 *)((char *)(var_a3) + 8)) = __repair_store_1;
                (*(s32 *)((char *)(var_a3) + 0xC)) = __repair_store_2;
                var_a2 += 0x10;
                var_a3 += 0x10;
            } while (var_a2 != (arg0 + 0x20));
            ((__repair_field_0 *)var_a3)->value = (s32) ((__repair_field_0 *)var_a2)->value;
            (*(s32 *)((char *)(var_a3) + 4)) = (s32) (*(s32 *)((char *)(var_a2) + 4));
            temp_v0 = var_t0 * 0xFF8;
            *(D_800E6AB8 + temp_v0) = 1;
            *(s32 *)(D_800E6AB4 + temp_v0) = arg1;
            *(D_800E6AB2 + temp_v0) = *(D_800E6AB2 + temp_v0) & 0xFB;
            *arg1 = ((__repair_field_0 *)arg0)->value | 0x80000000;
            return;
        }
        temp_v0_2 = temp_v1 & 1;
        if (arg2 & 0xFF) {
            if (temp_v0_2 != 0) {
                func_80091654(0U, (*(u16 *)((char *)(arg0) + 4)), ((__repair_field_0 *)arg0)->value, 2);
            } else if (!(temp_v1 & 0x40)) {
                func_80091654(0U, (*(u16 *)((char *)(arg0) + 4)), ((__repair_field_0 *)arg0)->value, 1);
            } else {
                func_80091654(0U, (*(u16 *)((char *)(arg0) + 4)), ((__repair_field_0 *)arg0)->value, 3);
            }
        } else if (temp_v0_2) {
            temp_s1 = (*(u16 *)((char *)(arg0) + 4));
            temp_s2 = ((__repair_field_0 *)arg0)->value;
            if (D_800CF540 != 0) {
                func_8008C0D4(var_a0, temp_a1, temp_a2);
                var_a1 = temp_s1;
                var_a2_2 = temp_s2;
                var_a3_2 = 2;
                func_80091654(0U, var_a1, var_a2_2, var_a3_2);
                func_8008C11C();
            }
        } else if (temp_v1 & 0x40) {
            temp_s1 = (*(u16 *)((char *)(arg0) + 4));
            temp_s2_2 = ((__repair_field_0 *)arg0)->value;
            if (D_800CF540 != 0) {
                func_8008C0D4(var_a0, temp_a1, temp_a2);
                var_a1 = temp_s1;
                var_a2_2 = temp_s2_2;
                var_a3_2 = 3;
                func_80091654(0U, var_a1, var_a2_2, var_a3_2);
                func_8008C11C();
            }
        } else {
            temp_s1 = (*(u16 *)((char *)(arg0) + 4));
            temp_s2_3 = ((__repair_field_0 *)arg0)->value;
            if (D_800CF540 != 0) {
                func_8008C0D4(var_a0, temp_a1, temp_a2);
                var_a1 = temp_s1;
                var_a2_2 = temp_s2_3;
                var_a3_2 = 1;
                func_80091654(0U, var_a1, var_a2_2, var_a3_2);
                func_8008C11C();
            }
        }
        if (arg1 != NULL) {
            var_a0_2 = 0;
            if ((*(u8 *)((char *)(arg0) + 0x26)) & 2) {
                temp_a2_2 = (*(s32 *)((char *)(arg0) + 8));
                temp_a1_2 = temp_a2_2 & 0x7FFFFFFF;
                var_v1_2 = 0;
loop_33:
                if ((*(D_800E6A85 + var_v1_2) != 0) || (*(s32 *)(gSndEntities + var_v1_2) != temp_a1_2)) {
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
                        temp_a1_3 = (*(s32 *)((char *)(arg0) + 8));
                        var_v1_4 = 0;
loop_40:
                        if ((*(D_800E6A85 + var_v1_4) != 0) || (*(s32 *)(gSndEntities + var_v1_4) != (temp_a1_3 & 0x7FFFFFFF))) {
                            var_a0_3 += 1;
                            var_v1_4 += 0xFF8;
                            if ((int)var_a0_3 >= 8U) {
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
                        func_80091654((*(u8 *)((char *)(arg0) + 0x18)), (*(u16 *)((char *)(arg0) + 0xC)), (*(s32 *)((char *)(arg0) + 8)), 0);
                        if ((*(u8 *)((char *)(arg0) + 0x26)) & 0x10) {
                            var_a0_4 = 0;
                            temp_a1_4 = (*(s32 *)((char *)(arg0) + 8));
                            temp_a3 = (*(s32 *)((char *)(arg0) + 0x1C));
                            temp_t0 = (*(s32 *)((char *)(arg0) + 0x20));
                            var_v1_5 = 0;
                            for (;;) {
                                if ((*(D_800E6A85 + var_v1_5) != 0) || (*(s32 *)(gSndEntities + var_v1_5) != (temp_a1_4 & 0x7FFFFFFF))) {
                                    var_a0_4 += 1;
                                    var_v1_5 += 0xFF8;
                                    if (var_a0_4 >= 8U) {
                                        var_v0_2 = -1;
                                    } else {
                                        continue;
                                    }
                                } else {
                                    var_v0_2 = var_a0_4 | (temp_a1_4 & 0x7fffffff);
                                }
                                break;
                            }
                            if (var_v0_2 != -1) {
                                if (var_v0_2 >= 0) {
                                    temp_v0_3 = var_v0_2 * 0xFF8;
                                    *(s32 *)(D_800E5BD4 + temp_v0_3) = temp_a3;
                                    *(s32 *)(D_800E5BD8 + temp_v0_3) = temp_t0;
                                } else {
                                    temp_v0_4 = (var_v0_2 & 0x7FFFFFFF) * 0xFF8;
                                    *(s32 *)(D_800E6AA8 + temp_v0_4) = temp_a3;
                                    *(s32 *)(D_800E6AAC + temp_v0_4) = temp_t0;
                                    *(D_800E6AB2 + temp_v0_4) = *(D_800E6AB2 + temp_v0_4) | 0x10;
                                }
                            }
                        }
                        var_a0_5 = 0;
                        if ((*(u8 *)((char *)(arg0) + 0x26)) & 0x20) {
                            temp_a1_5 = (*(s32 *)((char *)(arg0) + 8));
                            temp_a3_2 = (*(u16 *)((char *)(arg0) + 0x24));
                            var_v1_6 = 0;
                            for (;;) {
                                if ((*(D_800E6A85 + (s32)var_v1_6) != 0) || (*(s32 *)(gSndEntities + var_v1_6) != (temp_a1_5 & 0x7FFFFFFF))) {
                                    var_a0_5 += 1;
                                    var_v1_6 += 0xFF8;
                                    if (var_a0_5 >= 8U) {
                                        var_v0_3 = -1;
                                    } else {
                                        continue;
                                    }
                                } else {
                                    var_v0_3 = var_a0_5 | (temp_a1_5 & 0x80000000);
                                }
                                break;
                            }
                            if (var_v0_3 != -1) {
                                if (var_v0_3 >= 0) {
                                    *(s16 *)(D_800E6A86 + (var_v0_3 * 0xFF8)) = temp_a3_2;
                                } else {
                                    temp_v0_5 = (var_v0_3 & 0x7FFFFFFF) * 0xFF8;
                                    *(s16 *)(D_800E6AB0 + temp_v0_5) = temp_a3_2;
                                    *(D_800E6AB2 + temp_v0_5) = *(D_800E6AB2 + temp_v0_5) | 0x20;
                                }
                            }
                        }
                    } else {
                        func_80091324((*(s32 *)((char *)(arg0) + 8)), temp_a1_2, temp_a2_2);
                        temp_s3 = (*(u8 *)((char *)(arg0) + 0x18));
                        temp_s1_4 = (*(u16 *)((char *)(arg0) + 0xC));
                        temp_s2_4 = (*(s32 *)((char *)(arg0) + 8));
                        if (D_800CF540 != 0) {
                            func_8008C0D4();
                            func_80091654(temp_s3, temp_s1_4, temp_s2_4, 0);
                            func_8008C11C();
                        }
                        if ((*(u8 *)((char *)(arg0) + 0x26)) & 0x10) {
                            func_80091518((*(s32 *)((char *)(arg0) + 8)), (*(s32 *)((char *)(arg0) + 0x1C)), (*(s32 *)((char *)(arg0) + 0x20)));
                        }
                        if ((*(u8 *)((char *)(arg0) + 0x26)) & 0x20) {
                            temp_s1_5 = (*(s32 *)((char *)(arg0) + 8));
                            temp_s2_5 = (*(u16 *)((char *)(arg0) + 0x24));
                            if (D_800CF540 != 0) {
                                func_8008C0D4();
                                var_a0_6 = 0;
                                temp_a2_3 = temp_s1_5 & 0x7FFFFFFF;
                                var_v1_7 = 0;
loop_78:
                                if ((*(D_800E6A85 + var_v1_7) != 0) || (*(s32 *)(gSndEntities + var_v1_7) != temp_a2_3)) {
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
                                        *(s16 *)(D_800E6A86 + (var_a1_2 * 0xFF8)) = temp_s2_5;
                                    } else {
                                        var_a1_2 &= 0x7FFFFFFF;
                                        temp_v0_6 = var_a1_2 * 0xFF8;
                                        *(s16 *)(D_800E6AB0 + temp_v0_6) = temp_s2_5;
                                        *(D_800E6AB2 + temp_v0_6) = *(D_800E6AB2 + temp_v0_6) | 0x20;
                                    }
                                }
                                func_8008C11C(var_a0_6, var_a1_2, temp_a2_3);
                            }
                        }
                    }
                    *arg1 = (*(s32 *)((char *)(arg0) + 8));
                    return;
                }
                *arg1 = var_v1_3;
                return;
            }
            sp18[0] = 4;
            if ((*(u8 *)((char *)(arg0) + 0x26)) & 8) {
                sp18[0] = 0x14;
            }
            if ((*(u8 *)((char *)(arg0) + 0x26)) & 0x20) {
                sp18[0] |= 2;
                sp24 = (*(u16 *)((char *)(arg0) + 0x24));
            }
            if ((*(u8 *)((char *)(arg0) + 0x26)) & 0x10) {
                sp18[0] |= 1;
                sp18[1] = (*(s32 *)((char *)(arg0) + 0x1C));
                sp18[2] = (*(s32 *)((char *)(arg0) + 0x20));
            }
            sp26 = (*(u16 *)((char *)(arg0) + 0xC));
            sp30 = 0;
            sp28 = (*(u8 *)((char *)(arg0) + 0x18));
            if (arg2 & 0xFF) {
                temp_v0_7 = func_80092F9C((*(u16 *)((char *)(arg0) + 0x14)), (*(u16 *)((char *)(arg0) + 0x16)), (*(s32 *)((char *)(arg0) + 0x10)), sp18, 1);
                *arg1 = temp_v0_7;
                if ((temp_v0_7 != -1) && ((*(u8 *)((char *)(arg0) + 0x26)) & 0x80)) {
                    var_v1_8 = 0;
                    var_a0_7 = 0;
                    for (;;) {
                        if ((*(D_800E6A85 + var_v1_8) != 0) || (*(s32 *)(gSndEntities + var_v1_8) != (temp_v0_7 & 0x7FFFFFFF))) {
                            var_a0_7 += 1;
                            var_v1_8 += 0xFF8;
                            if (var_a0_7 >= 8U) {
                                var_v0_5 = -1;
                            } else {
                                continue;
                            }
                        } else {
                            var_v0_5 = var_a0_7 | (temp_v0_7 & 0x7fffffff);
                        }
                        break;
                    }
                    if (var_v0_5 != -1) {
                        if (var_v0_5 >= 0) {
                            temp_v0_8 = var_v0_5 * 0xFF8;
                            *(s32 *)(D_800E5BD4 + temp_v0_8) = 0;
                            *(s32 *)(D_800E5BD8 + temp_v0_8) = 0;
                            return;
                        }
                        temp_v0_9 = (var_v0_5 & 0x7FFFFFFF) * 0xFF8;
                        *(s32 *)(D_800E6AA8 + temp_v0_9) = 0;
                        *(s32 *)(D_800E6AAC + temp_v0_9) = 0;
                        *(D_800E6AB2 + temp_v0_9) = *(D_800E6AB2 + temp_v0_9) | 0x10;
                    }
                }
            } else {
                temp_v0_10 = func_800930F4((*(u16 *)((char *)(arg0) + 0x14)), (*(u16 *)((char *)(arg0) + 0x16)), (*(s32 *)((char *)(arg0) + 0x10)), sp18);
                *arg1 = temp_v0_10;
                if ((temp_v0_10 != -1) && ((*(u8 *)((char *)(arg0) + 0x26)) & 0x80)) {
                    func_80091518(temp_v0_10, 0, 0);
                }
            }
        }
    }
}
