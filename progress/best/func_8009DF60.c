/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 bzero();
s32 func_8009DBE8();

s32 func_8009DF60(void *arg0, s32 arg1) {
int __repair_literal;

    s32 sp50;
    int sp58;
    s32 sp60;
    s16 spC8;
    s16 spD0;
    s16 spD8;
    s16 spE0;
    s16 spE8;
    s16 spEA;
    s16 spEC;
    s16 spEE;
    s16 spF0;
    s16 spF2;
    s16 spF4;
    s16 spF6;
    s32 var_v1;
    char *var_a2;
    char *var_a3;
    char *var_t1;
    char *var_t2;
    s16 temp_t6;
    s16 temp_t6_2;
    s16 temp_t6_3;
    s16 temp_t6_4;
    s16 temp_t7;
    s16 temp_t7_2;
    s16 temp_t7_3;
    s16 temp_t7_4;
    s32 temp_a2;
    s32 temp_a3;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t3;
    char *var_a0;
    s32 var_v1_10;
    s32 var_v1_11;
    s32 var_v1_12;
    s32 var_v1_13;
    s32 var_v1_14;
    s32 var_v1_15;
    s32 var_v1_16;
    s32 var_v1_17;
    s32 var_v1_18;
    s32 var_v1_19;
    s32 var_v1_20;
    s32 var_v1_21;
    s32 var_v1_22;
    s32 var_v1_23;
    s32 var_v1_24;
    s32 var_v1_25;
    s32 var_v1_26;
    s32 var_v1_27;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    s32 var_v1_6;
    register s32 var_v1_7;
    s32 var_v1_8;
    s32 var_v1_9;
    u32 temp_v0;
    u32 temp_v0_10;
    u32 temp_v0_11;
    u32 temp_v0_12;
    u32 temp_v0_13;
    u32 temp_v0_14;
    u32 temp_v0_15;
    u32 temp_v0_16;
    u32 temp_v0_17;
    u32 temp_v0_18;
    u32 temp_v0_19;
    u32 temp_v0_20;
    u32 temp_v0_21;
    u32 temp_v0_22;
    u32 temp_v0_23;
    u32 temp_v0_24;
    u32 temp_v0_25;
    u32 temp_v0_26;
    u32 temp_v0_27;
    u32 temp_v0_28;
    u32 temp_v0_2;
    u32 temp_v0_3;
    u32 temp_v0_4;
    u32 temp_v0_5;
    u32 temp_v0_6;
    unsigned temp_v0_7;
    u32 temp_v0_8;
    u32 temp_v0_9;
    u32 var_v0;
    u32 var_v0_10;
    u32 var_v0_11;
    u32 var_v0_12;
    u32 var_v0_13;
    u32 var_v0_14;
    u32 var_v0_8;
    u32 var_v0_16;
    u32 var_v0_17;
    u32 var_v0_18;
    u32 var_v0_19;
    u32 var_v0_20;
    u32 var_v0_21;
    u32 var_v0_22;
    u32 var_v0_23;
    u32 var_v0_24;
    u32 var_v0_25;
    u32 var_v0_26;
    u32 var_v0_2;
    u32 var_v0_3;
    u32 var_v0_4;
    u32 var_v0_5;
    u32 var_v0_6;
    u32 var_v0_7;
    u32 var_v0_15;
    unsigned var_v0_9;

    var_t0 = (*(s32 *)((char *)(arg0) + 0x11C8));
    temp_a2 = var_t0 & 0x1F;
    temp_a3 = 0x20 - temp_a2;
    var_v1 = temp_a3;
    var_v0 = (u32) (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0)) >> temp_a2;
    if (((*(s16 *)((char *)(arg0) + 0x18A)) == 0) && ((*(s16 *)((char *)(arg0) + 0x18C)) == 0)) {
        if (temp_a3 >= 2) {
            var_t3 = var_v0 & 1;
            var_v0_2 = var_v0 >> 1;
            var_v1_2 = temp_a3 - 1;
        } else {
            var_t0 += 0x20;
            var_t3 = ((1 << var_v1) - 1) & var_v0;
            temp_v0 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
            if (var_v1 != 1) {
                var_t3 |= (temp_v0 & ((1 << (1 - var_v1)) - 1)) << var_v1;
            }
            var_v0_2 = temp_v0 >> (1 - var_v1);
            var_v1_2 = var_v1 + 0x1F;
        }
        if (var_t3 != 0) {
            if (var_v1_2 >= 5) {
                (*(s16 *)((char *)(arg0) + 0x18C)) = (s16) (var_v0_2 & 0xF);
                var_v0 = var_v0_2 >> 4;
                var_v1 = var_v1_2 - 4;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(arg0) + 0x18C)) = (s16) (((1 << var_v1_2) - 1) & var_v0_2);
__repair_literal = 4;

                temp_v0_2 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * __repair_literal))) + 0x1A0));
                if (var_v1_2 != 4) {
                    (*(s16 *)((char *)(arg0) + 0x18C)) |= ((temp_v0_2 & ((1 << (4 - var_v1_2)) - 1)) << var_v1_2);
                }
                var_v0 = temp_v0_2 >> (4 - var_v1_2);
                var_v1 = var_v1_2 + 0x1C;
            }
            (*(s16 *)((char *)(arg0) + 0x18C)) += 1;
        } else {
            if (var_v1_2 >= 8) {
                (*(s16 *)((char *)(arg0) + 0x18A)) = (s16) (var_v0_2 & 0x7F);
                var_v0 = var_v0_2 >> 7;
                var_v1 = var_v1_2 - 7;
            } else {
                (*(s16 *)((char *)(arg0) + 0x18A)) = (s16) (((1 << var_v1_2) - 1) & var_v0_2);
                var_t0 += 0x20;
                temp_v0_3 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_2 != 7) {
                    (*(s16 *)((char *)(arg0) + 0x18A)) |= ((temp_v0_3 & ((1 << (7 - var_v1_2)) - 1)) << var_v1_2);
                }
                var_v0 = temp_v0_3 >> (7 - var_v1_2);
                var_v1 = var_v1_2 + 0x19;
            }
            (*(s16 *)((char *)(arg0) + 0x18A)) += 1;
        }
    }
    if ((*(s16 *)((char *)(arg0) + 0x18C)) != 0) {
        sp58 = var_v1;
        sp50 = var_t0;
        bzero(arg1, 0x140, temp_a2, temp_a3);
        var_v1_3 = var_v1;
        var_t0_2 = var_t0;
        (*(s16 *)((char *)(arg0) + 0x18C)) -= 1;
    } else {
        var_a2 = &spE0;
        if (var_v1 >= 7) {
            spE8 = var_v0 & 0x3F;
            var_v0_3 = var_v0 >> 6;
            var_v1_4 = var_v1 - 6;
        } else {
            var_t0 += 0x20;
            temp_t7 = ((1 << var_v1) - 1) & var_v0;
            spE8 = temp_t7;
            temp_v0_4 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
            if (var_v1 != 6) {
                spE8 = temp_t7 | ((temp_v0_4 & ((1 << (6 - var_v1)) - 1)) << var_v1);
            }
            var_v0_3 = temp_v0_4 >> (6 - var_v1);
            var_v1_4 = var_v1 + 0x1A;
        }
        var_a3 = &spD0;
        if (var_v1_4 >= 7) {
            spEA = var_v0_3 & 0x3F;
            var_v0_4 = var_v0_3 >> 6;
            var_v1_5 = var_v1_4 - 6;
        } else {
            var_t0 += 0x20;
            temp_t6 = ((1 << var_v1_4) - 1) & var_v0_3;
            spEA = temp_t6;
            temp_v0_5 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
            if (var_v1_4 != 6) {
                spEA = temp_t6 | ((temp_v0_5 & ((1 << (6 - var_v1_4)) - 1)) << var_v1_4);
            }
            var_v0_4 = temp_v0_5 >> (6 - var_v1_4);
            var_v1_5 = var_v1_4 + 0x1A;
        }
        var_t1 = &spD8;
        if (var_v1_5 >= 6) {
            spEC = var_v0_4 & 0x1F;
            var_v0_5 = var_v0_4 >> 5;
            var_v1_6 = var_v1_5 - 5;
        } else {
            var_t0 += 0x20;
            temp_t7_2 = ((1 << var_v1_5) - 1) & var_v0_4;
            spEC = temp_t7_2;
            temp_v0_6 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
            if (var_v1_5 != 5) {
                spEC = temp_t7_2 | ((temp_v0_6 & ((1 << (5 - var_v1_5)) - 1)) << var_v1_5);
            }
            var_v0_5 = temp_v0_6 >> (5 - var_v1_5);
            var_v1_6 = var_v1_5 + 0x1B;
        }
        var_t2 = &spC8;
        if (var_v1_6 >= 6) {
            spEE = var_v0_5 & 0x1F;
            var_v0_6 = var_v0_5 >> 5;
            var_v1_7 = var_v1_6 - 5;
        } else {
            var_t0 += 0x20;
            temp_t6_2 = ((1 << var_v1_6) - 1) & var_v0_5;
            spEE = temp_t6_2;
            temp_v0_7 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
            if (var_v1_6 != 5) {
                spEE = temp_t6_2 | ((temp_v0_7 & ((1 << (5 - var_v1_6)) - 1)) << var_v1_6);
            }
            var_v0_6 = temp_v0_7 >> (5 - var_v1_6);
            var_v1_7 = var_v1_6 + 0x1B;
        }
        var_a0 = &sp60;
        if (var_v1_7 >= 5) {
            spF0 = var_v0_6 & 0xF;
            var_v0_7 = var_v0_6 >> 4;
            var_v1_8 = var_v1_7 - 4;
        } else {
            var_t0 += 0x20;
            temp_t7_3 = ((1 << var_v1_7) - 1) & var_v0_6;
            spF0 = temp_t7_3;
            temp_v0_8 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
            if (var_v1_7 != 4) {
                spF0 = temp_t7_3 | ((temp_v0_8 & ((1 << (4 - var_v1_7)) - 1)) << var_v1_7);
            }
            var_v0_7 = temp_v0_8 >> (4 - var_v1_7);
            var_v1_8 = var_v1_7 + 0x1C;
        }
        if (var_v1_8 >= 5) {
            spF2 = var_v0_7 & 0xF;
            var_v0_8 = var_v0_7 >> 4;
            var_v1_9 = var_v1_8 - 4;
        } else {
            var_t0 += 0x20;
            temp_t6_3 = ((1 << var_v1_8) - 1) & var_v0_7;
            spF2 = temp_t6_3;
            temp_v0_9 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
            if (var_v1_8 != 4) {
                spF2 = temp_t6_3 | ((temp_v0_9 & ((1 << (4 - (unsigned)var_v1_8)) - 1)) << var_v1_8);
            }
            var_v0_8 = temp_v0_9 >> (4 - var_v1_8);
            var_v1_9 = var_v1_8 + 0x1C;
        }
        if (var_v1_9 >= 4) {
            spF4 = var_v0_8 & 7;
            var_v0_9 = var_v0_8 >> 3;
            var_v1_10 = var_v1_9 - 3;
        } else {
            var_t0 += 0x20;
            temp_t7_4 = ((1 << var_v1_9) - 1) & var_v0_8;
            spF4 = temp_t7_4;
            temp_v0_10 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
            if (var_v1_9 != 3) {
                spF4 = temp_t7_4 | ((temp_v0_10 & ((1 << (3 - var_v1_9)) - 1)) << var_v1_9);
            }
            var_v0_9 = temp_v0_10 >> (3 - var_v1_9);
            var_v1_10 = var_v1_9 + 0x1D;
        }
        if (var_v1_10 >= 4) {
            var_v0_10 = var_v0_9 >> 3;
            spF6 = var_v0_9 & 7;
            var_v1_11 = var_v1_10 - 3;
        } else {
            var_t0 += 0x20;
            temp_t6_4 = ((1 << var_v1_10) - 1) & var_v0_9;
            spF6 = temp_t6_4;
            temp_v0_11 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
            if (var_v1_10 != 3) {
                spF6 = temp_t6_4 | ((temp_v0_11 & ((1 << (3 - var_v1_10)) - 1)) << var_v1_10);
            }
            var_v0_10 = temp_v0_11 >> (3 - var_v1_10);
            var_v1_11 = var_v1_10 + 0x1D;
        }
        do {
            if (8 <= var_v1_11) {
                *(s16 *)var_a2 = var_v0_10 & 0x7F;
                var_v1_12 = var_v1_11 - 7;
                var_v0_11 = var_v0_10 >> 7;
            } else {
                var_t0 += 0x20;
                temp_v0_12 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                *(s16 *)var_a2 = ((1 << var_v1_11) - 1) & var_v0_10;
                if (var_v1_11 != 7) {
                    *(s16 *)var_a2 |= (temp_v0_12 & ((1 << (7 - var_v1_11)) - 1)) << var_v1_11;
                }
                var_v0_11 = temp_v0_12 >> (7 - var_v1_11);
                var_v1_12 = var_v1_11 + 0x19;
            }
            var_a2 += 2;
            if (3 <= var_v1_12) {
                *(s16 *)var_a3 = var_v0_11 & 3;
                var_v0_12 = var_v0_11 >> 2;
                var_v1_13 = var_v1_12 - 2;
            } else {
                var_t0 += 0x20;
                *(s16 *)var_a3 = ((1 << var_v1_12) - 1) & var_v0_11;
                temp_v0_13 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_12 != 2) {
                    *(s16 *)var_a3 |= (temp_v0_13 & ((1 << (2 - var_v1_12)) - 1)) << var_v1_12;
                }
                var_v0_12 = temp_v0_13 >> (2 - var_v1_12);
                var_v1_13 = var_v1_12 + 0x1E;
            }
            var_a3 += 2;
            if (var_v1_13 >= 3) {
                *(s16 *)var_t1 = var_v0_12 & 3;
                var_v0_13 = var_v0_12 >> 2;
                var_v1_14 = var_v1_13 - 2;
            } else {
                var_t0 += 0x20;
                *(s16 *)var_t1 = ((1 << var_v1_13) - 1) & var_v0_12;
                temp_v0_14 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_13 != 2) {
                    *(s16 *)var_t1 |= (temp_v0_14 & ((1 << (2 - var_v1_13)) - 1)) << var_v1_13;
                }
                var_v0_13 = temp_v0_14 >> (2 - var_v1_13);
                var_v1_14 = var_v1_13 + 0x1E;
            }
            var_t1 += 2;
            if (var_v1_14 >= 7) {
                *(s16 *)var_t2 = var_v0_13 & 0x3F;
                var_v0_14 = var_v0_13 >> 6;
                var_v1_15 = var_v1_14 - 6;
            } else {
                var_t0 += 0x20;
                *(s16 *)var_t2 = ((1 << var_v1_14) - 1) & (int)var_v0_13;
                temp_v0_15 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_14 != 6) {
                    *(s16 *)var_t2 |= (temp_v0_15 & ((1 << (6 - var_v1_14)) - 1)) << var_v1_14;
                }
                var_v0_14 = temp_v0_15 >> (6 - var_v1_14);
                var_v1_15 = var_v1_14 + 0x1A;
            }
            if (var_v1_15 >= 4) {
                (*(s16 *)((char *)(var_a0) + 0)) = (s16) (var_v0_14 & 7);
                var_v0_15 = var_v0_14 >> 3;
                var_v1_16 = var_v1_15 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 0)) = (s16) (((1 << var_v1_15) - 1) & var_v0_14);
                temp_v0_16 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_15 != 3) {
                    (*(s16 *)((char *)(var_a0) + 0)) |= ((temp_v0_16 & ((1 << (3 - var_v1_15)) - 1)) << var_v1_15);
                }
                var_v0_15 = temp_v0_16 >> (3 - var_v1_15);
                var_v1_16 = var_v1_15 + 0x1D;
            }
            if (var_v1_16 >= 4) {
                (*(s16 *)((char *)(var_a0) + 2)) = (s16) (var_v0_15 & 7);
                var_v0_16 = var_v0_15 >> 3;
                var_v1_17 = var_v1_16 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 2)) = (s16) (((1 << var_v1_16) - 1) & var_v0_15);
                temp_v0_17 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_16 != 3) {
                    (*(s16 *)((char *)(var_a0) + 2)) |= ((temp_v0_17 & ((1 << (3 - var_v1_16)) - 1)) << var_v1_16);
                }
                var_v0_16 = temp_v0_17 >> (3 - var_v1_16);
                var_v1_17 = var_v1_16 + 0x1D;
            }
            if (var_v1_17 >= 4) {
                (*(s16 *)((char *)(var_a0) + 4)) = (s16) (var_v0_16 & 7);
                var_v0_17 = var_v0_16 >> 3;
                var_v1_18 = var_v1_17 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 4)) = (s16) (((1 << var_v1_17) - 1) & var_v0_16);
                temp_v0_18 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_17 != 3) {
                    (*(s16 *)((char *)(var_a0) + 4)) |= ((temp_v0_18 & ((1 << (3 - var_v1_17)) - 1)) << var_v1_17);
                }
                var_v0_17 = temp_v0_18 >> (3 - var_v1_17);
                var_v1_18 = var_v1_17 + 0x1D;
            }
            if (var_v1_18 >= 4) {
                (*(s16 *)((char *)(var_a0) + 6)) = (s16) (var_v0_17 & 7);
                var_v0_18 = var_v0_17 >> 3;
                var_v1_19 = var_v1_18 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 6)) = (s16) (((1 << var_v1_18) - 1) & var_v0_17);
                temp_v0_19 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_18 != 3) {
                    (*(s16 *)((char *)(var_a0) + 6)) |= ((temp_v0_19 & ((1 << (3 - var_v1_18)) - 1)) << var_v1_18);
                }
                var_v0_18 = temp_v0_19 >> (3 - var_v1_18);
                var_v1_19 = var_v1_18 + 0x1D;
            }
            if (var_v1_19 >= 4) {
                (*(s16 *)((char *)(var_a0) + 8)) = (s16) (var_v0_18 & 7);
                var_v0_19 = var_v0_18 >> 3;
                var_v1_20 = var_v1_19 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 8)) = (s16) (((1 << var_v1_19) - 1) & var_v0_18);
                temp_v0_20 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_19 != 3) {
                    (*(s16 *)((char *)(var_a0) + 8)) |= ((temp_v0_20 & ((1 << (3 - var_v1_19)) - 1)) << var_v1_19);
                }
                var_v0_19 = temp_v0_20 >> (3 - var_v1_19);
                var_v1_20 = var_v1_19 + 0x1D;
            }
            if (var_v1_20 >= 4) {
                (*(s16 *)((char *)(var_a0) + 0xA)) = (s16) (var_v0_19 & 7);
                var_v0_20 = var_v0_19 >> 3;
                var_v1_21 = var_v1_20 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 0xA)) = (s16) (((1 << var_v1_20) - 1) & var_v0_19);
                temp_v0_21 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_20 != 3) {
                    (*(s16 *)((char *)(var_a0) + 0xA)) |= ((temp_v0_21 & ((1 << (3 - var_v1_20)) - 1)) << var_v1_20);
                }
                var_v0_20 = temp_v0_21 >> (3 - var_v1_20);
                var_v1_21 = var_v1_20 + 0x1D;
            }
            if (var_v1_21 >= 4) {
                (*(s16 *)((char *)(var_a0) + 0xC)) = (s16) (var_v0_20 & 7);
                var_v0_21 = var_v0_20 >> 3;
                var_v1_22 = var_v1_21 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 0xC)) = (s16) (((1 << var_v1_21) - 1) & var_v0_20);
                temp_v0_22 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_21 != 3) {
                    (*(s16 *)((char *)(var_a0) + 0xC)) |= ((temp_v0_22 & ((1 << (3 - var_v1_21)) - 1)) << var_v1_21);
                }
                var_v0_21 = temp_v0_22 >> (3 - var_v1_21);
                var_v1_22 = var_v1_21 + 0x1D;
            }
            if (var_v1_22 >= 4) {
                (*(s16 *)((char *)(var_a0) + 0xE)) = (s16) (var_v0_21 & 7);
                var_v0_22 = var_v0_21 >> 3;
                var_v1_23 = var_v1_22 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 0xE)) = (s16) (((1 << var_v1_22) - 1) & var_v0_21);
                temp_v0_23 = (*(u32 *)((char *)((arg0 + ((((u32)var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_22 != 3) {
                    (*(s16 *)((char *)(var_a0) + 0xE)) |= ((temp_v0_23 & ((1 << (3 - var_v1_22)) - 1)) << var_v1_22);
                }
                var_v0_22 = temp_v0_23 >> (3 - var_v1_22);
                var_v1_23 = var_v1_22 + 0x1D;
            }
            if (var_v1_23 >= 4) {
                (*(s16 *)((char *)(var_a0) + 0x10)) = (s16) (var_v0_22 & 7);
                var_v0_23 = var_v0_22 >> 3;
                var_v1_24 = var_v1_23 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 0x10)) = (s16) (((1 << var_v1_23) - 1) & var_v0_22);
                temp_v0_24 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_23 != 3) {
                    (*(s16 *)((char *)(var_a0) + 0x10)) |= ((temp_v0_24 & ((1 << (3 - var_v1_23)) - 1)) << var_v1_23);
                }
                var_v0_23 = temp_v0_24 >> (3 - var_v1_23);
                var_v1_24 = var_v1_23 + 0x1D;
            }
            if (4 <= var_v1_24) {
                (*(s16 *)((char *)(var_a0) + 0x12)) = (s16) (var_v0_23 & 7);
                var_v0_24 = var_v0_23 >> 3;
                var_v1_25 = var_v1_24 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 0x12)) = (s16) (((1 << var_v1_24) - 1) & var_v0_23);
                temp_v0_25 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_24 != 3) {
                    (*(s16 *)((char *)(var_a0) + 0x12)) |= ((temp_v0_25 & ((1 << (3 - var_v1_24)) - 1)) << var_v1_24);
                }
                var_v0_24 = temp_v0_25 >> (3 - var_v1_24);
                var_v1_25 = var_v1_24 + 0x1D;
            }
            if (4 <= var_v1_25) {
                (*(s16 *)((char *)(var_a0) + 0x14)) = (s16) (var_v0_24 & 7);
                var_v0_25 = var_v0_24 >> 3;
                var_v1_26 = var_v1_25 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 0x14)) = (s16) (((1 << var_v1_25) - 1) & var_v0_24);
                temp_v0_26 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_25 != 3) {
                    (*(s16 *)((char *)(var_a0) + 0x14)) |= ((temp_v0_26 & ((1 << (3 - var_v1_25)) - 1)) << var_v1_25);
                }
                var_v0_25 = temp_v0_26 >> (3 - var_v1_25);
                var_v1_26 = var_v1_25 + 0x1D;
            }
            if (var_v1_26 >= 4) {
                (*(s16 *)((char *)(var_a0) + 0x16)) = (s16) (var_v0_25 & 7);
                var_v0_26 = var_v0_25 >> 3;
                var_v1_27 = var_v1_26 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 0x16)) = (s16) (((1 << var_v1_26) - 1) & var_v0_25);
                temp_v0_27 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_26 != 3) {
                    (*(s16 *)((char *)(var_a0) + 0x16)) |= ((temp_v0_27 & ((1 << (3 - var_v1_26)) - 1)) << var_v1_26);
                }
                var_v0_26 = temp_v0_27 >> (3 - var_v1_26);
                var_v1_27 = var_v1_26 + 0x1D;
            }
            if (var_v1_27 >= 4) {
                (*(s16 *)((char *)(var_a0) + 0x18)) = (s16) (var_v0_26 & 7);
                var_v0_10 = var_v0_26 >> 3;
                var_v1_11 = var_v1_27 - 3;
            } else {
                var_t0 += 0x20;
                (*(s16 *)((char *)(var_a0) + 0x18)) = (s16) (((1 << var_v1_27) - 1) & var_v0_26);
                temp_v0_28 = (*(u32 *)((char *)((arg0 + (((var_t0 >> 5) & 0x3FF) * 4))) + 0x1A0));
                if (var_v1_27 != 3) {
                    (*(s16 *)((char *)(var_a0) + 0x18)) |= (((u32)temp_v0_28 & ((1 << (3 - var_v1_27)) - 1)) << var_v1_27);
                }
                var_v0_10 = temp_v0_28 >> (3 - var_v1_27);
                var_v1_11 = var_v1_27 + 0x1D;
            }
            var_a0 += 0x1A;
            var_t2 += 2;
        } while (var_a0 != &spC8);
        (*(s16 *)((char *)(arg0) + 0x18A)) -= 1;
        sp50 = var_t0;
        sp58 = var_v1_11;
        do { func_8009DBE8(arg0,  &spE8,  &spE0,  &spD0,  &spD8,  &spC8); } while (0);
        var_v1_3 = sp58;
        var_t0_2 = (unsigned)sp50;
    }
    (*(s32 *)((char *)(arg0) + 0x11C8)) = (s32) (((sp50 & ~0x1F) - sp58) + 0x20);
    return 0;
}
