/* Partial candidate from function #30064772280 in project #7; rechecked locally. */
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -g3, tried by autopilot */

s32 func_800A81E0(s8 *a, s8 *b, s32 n) {
    s16 temp_v0_11;
    
    s16 temp_v1;
    s16 temp_v1_5;
    s32 temp_t0;
    s32 temp_t0_2;
    s32 temp_t0_3;
    s32 temp_t0_4;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_t1_3;
    u32 temp_t1_4;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_t3;
    s32 temp_t3_2;
    s32 temp_t4;
    s32 temp_t4_2;
    s32 temp_t5;
    s32 temp_t5_2;
    s32 temp_v0;
    s32 temp_v0_13;
    s32 temp_v0_14;
    s32 temp_v0_15;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    unsigned long temp_v0_9;
    unsigned long temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 var_a2;
s32 __repair_phase_var_a2;
    s8 *temp_a3;
    s8 *temp_v1_8;
    s8 *var_a0;
    s8 *var_a0_2;
    s8 *var_a0_3;
    s8 *var_a1;
    s8 *var_a1_2;
    s8 *var_a1_3;
    s8 temp_v0_10;
    s8 temp_v0_12;
    s8 temp_v0_16;
    s8 temp_v0_2;
    s8 temp_v0_4;
    s8 temp_v0_8;

    var_a0 = a;
    var_a1 = b;
    var_a2 = n;
    temp_a3 = var_a1;
    if (!var_a2) return temp_a3;
    if (var_a0 == var_a1) return (s32)temp_a3;
    {
        if (((s32) var_a1 >= (s32) var_a0) && ((s32) var_a1 < (s32) &var_a0[var_a2])) {
            var_a0_2 = &var_a0[var_a2];
            var_a1_2 = &var_a1[var_a2];
            if (var_a2 >= 0x10) {
                temp_v0 = (s32) var_a0_2 & 3;
                if (temp_v0 == ((s32) var_a1_2 & 3)) {
                    switch (temp_v0) {              /* switch 2; irregular */
                    case 0:                         /* switch 2 */
                        break;
                    default:                        /* switch 2 */
                        temp_v0_2 = (*(s8 *)((char *)(var_a0_2) + -1));
                        var_a0_2--;
                        (*(s8 *)((char *)(var_a1_2) + -1)) = temp_v0_2;
                        var_a1_2 -= 1;
                        var_a2 -= 1;
                        break;
                    case 2:                         /* switch 2 */
                        temp_v0_11 = (*(s16 *)((char *)(var_a0_2) + -2));
                        var_a0_2 -= 2;
                        (*(s16 *)((char *)(var_a1_2) + -2)) = temp_v0_11;
                        var_a1_2 -= 2;
                        var_a2 -= 2;
                        break;
                    case 3:                         /* switch 2 */
                        temp_v0_4 = (*(s8 *)((char *)(var_a0_2) + -1));
                        temp_v0 = (s16)((*(s16 *)((char *)(var_a0_2) + -3)));
                        var_a0_2 -= 3;
                        (*(s8 *)((char *)(var_a1_2) + -1)) = temp_v0_4;
                        (*(s16 *)((char *)(var_a1_2) + -3)) = temp_v0;
                        var_a1_2 -= 3;
                        var_a2 -= 3;
                        break;
                    }
loop_35:
                    if (var_a2 >= 0x20) {
                        temp_v0_5 = (*(s32 *)((char *)(var_a0_2) + -4));
                        temp_v1_2 = (*(s32 *)((char *)(var_a0_2) + -8));
                        temp_t0 = (*(s32 *)((char *)(var_a0_2) + -0xC));
                        temp_t1 = (*(s32 *)((char *)(var_a0_2) + -0x10));
                        temp_t2 = (*(s32 *)((char *)(var_a0_2) + -0x14));
                        temp_t3 = (*(s32 *)((char *)(var_a0_2) + -0x18));
                        temp_t4 = (*(s32 *)((char *)(var_a0_2) + -0x1C));
                        temp_t5 = (*(s32 *)((char *)(var_a0_2) + -0x20));
                        var_a0_2 -= 0x20;
                        (*(s32 *)((char *)(var_a1_2) + -4)) = temp_v0_5;
                        (*(s32 *)((char *)(var_a1_2) + -8)) = temp_v1_2;
                        (*(s32 *)((char *)(var_a1_2) + -0x10)) = temp_t1;
                        (*(s32 *)((char *)(var_a1_2) + -0xC)) = temp_t0;
                        (*(s32 *)((char *)(var_a1_2) + -0x14)) = temp_t2;
                        (*(s32 *)((char *)(var_a1_2) + -0x18)) = temp_t3;
                        (*(s32 *)((char *)(var_a1_2) + -0x1C)) = temp_t4;
                        (*(s32 *)((char *)(var_a1_2) + -0x20)) = temp_t5;
                        var_a1_2 -= 0x20;
                        var_a2 -= 0x20;
                        goto loop_35;
                    }
loop_37:
                    if (var_a2 >= 0x10) {
                        temp_v0_6 = (*(s32 *)((char *)(var_a0_2) + -4));
                        temp_v1_3 = (*(s32 *)((char *)(var_a0_2) + -8));
                        temp_t0_2 = (*(s32 *)((char *)(var_a0_2) + -0xC));
                        temp_t1_2 = (*(s32 *)((char *)(var_a0_2) + -0x10));
                        var_a0_2 -= 0x10;
                        (*(s32 *)((char *)(var_a1_2) + -4)) = temp_v0_6;
                        (*(s32 *)((char *)(var_a1_2) + -8)) = temp_v1_3;
                        (*(s32 *)((char *)(var_a1_2) + -0xC)) = temp_t0_2;
                        (*(s32 *)((char *)(var_a1_2) + -0x10)) = temp_t1_2;
                        var_a1_2 -= 0x10;
                        var_a2 -= 0x10;
                        goto loop_37;
                    }
loop_39:
                    if (var_a2 >= 4) {
                        temp_v0_7 = (*(s32 *)((char *)(var_a0_2) + -4));
                        var_a0_2 -= 4;
                        (*(s32 *)((char *)(var_a1_2) + -4)) = temp_v0_7;
                        var_a1_2 -= 4;
                        var_a2 -= 4;
                        goto loop_39;
                    }
                }
            }
            if (var_a2 != 0) {
                var_a0_3 = var_a0_2 - 1;
                var_a1_3 = var_a1_2 - 1;
                temp_v1_4 = var_a0_3 - var_a2;
                do {
                    __repair_phase_var_a2 = (s8)(*var_a0_3);
                    var_a0_3 -= 1;
                    *var_a1_3 = __repair_phase_var_a2;
                    var_a1_3 -= 1;
                } while (var_a0_3 != temp_v1_4);
                return (s32) temp_a3;
            }
            /* Duplicate return node #10. Try simplifying control flow for better match */
            return (s32) temp_a3;
        }
        if (var_a2 >= 0x10) {
            temp_v0_9 = (s32) var_a0 & 3;
            if (temp_v0_9 == ((s32) var_a1 & 3)) {
                switch (temp_v0_9) {                /* switch 1; irregular */
                case 0:                             /* switch 1 */
                    break;
                default:                            /* switch 1 */
                    temp_v0_10 = (*(s8 *)((char *)(var_a0) + 0));
                    var_a0 += 1;
                    (*(s8 *)((char *)(var_a1) + 0)) = temp_v0_10;
                    var_a1 += 1;
                    var_a2--;
                    break;
                case 2:                             /* switch 1 */
                    temp_v0_11 = (*(s16 *)((char *)(var_a0) + 0));
                    var_a0 += 2;
                    (*(s16 *)((char *)(var_a1) + 0)) = temp_v0_11;
                    var_a1 += 2;
                    var_a2 -= 2;
                    break;
                case 1:                             /* switch 1 */
                    temp_v0_12 = (*(s8 *)((char *)(var_a0) + 0));
                    temp_v0 = (s16)((*(s16 *)((char *)(var_a0) + 1)));
                    var_a0 += 3;
                    (*(s8 *)((char *)(var_a1) + 0)) = temp_v0_12;
                    (*(s16 *)((char *)(var_a1) + 1)) = temp_v0;
                    var_a1 += 3;
                    var_a2 -= 3;
                    break;
                }
loop_17:
                if (var_a2 >= 0x20) {
                    temp_v0_13 = (*(s32 *)((char *)(var_a0) + 0));
                    temp_v1_6 = (*(s32 *)((char *)(var_a0) + 4));
                    temp_t0_3 = (*(s32 *)((char *)(var_a0) + 8));
                    temp_t1_3 = (*(s32 *)((char *)(var_a0) + 0xC));
                    temp_t2_2 = (*(s32 *)((char *)(var_a0) + 0x10));
                    temp_t3_2 = (*(s32 *)((char *)(var_a0) + 0x14));
                    temp_t4_2 = (*(s32 *)((char *)(var_a0) + 0x18));
                    temp_t5_2 = (*(s32 *)((char *)(var_a0) + 0x1C));
                    var_a0 += 0x20;
                    (*(s32 *)((char *)(var_a1) + 0)) = temp_v0_13;
                    (*(s32 *)((char *)(var_a1) + 4)) = temp_v1_6;
                    (*(s32 *)((char *)(var_a1) + 8)) = temp_t0_3;
                    (*(s32 *)((char *)(var_a1) + 0xC)) = temp_t1_3;
                    (*(s32 *)((char *)(var_a1) + 0x10)) = temp_t2_2;
                    (*(s32 *)((char *)(var_a1) + 0x14)) = temp_t3_2;
                    (*(s32 *)((char *)(var_a1) + 0x18)) = temp_t4_2;
                    (*(s32 *)((char *)(var_a1) + 0x1C)) = temp_t5_2;
                    var_a1 += 0x20;
                    var_a2 -= 0x20;
                    goto loop_17;
                }
loop_19:
                if (var_a2 >= 0x10) {
                    register temp_v0_14 = (*(s32 *)((char *)(var_a0) + 0));
                    temp_v1_7 = (*(s32 *)((char *)(var_a0) + 4));
                    temp_t0_4 = (*(s32 *)((char *)(var_a0) + 8));
                    temp_t1_4 = (*(s32 *)((char *)(var_a0) + 0xC));
                    var_a0 += 0x10;
                    (*(s32 *)((char *)(var_a1) + 4)) = temp_v1_7;
                    (*(s32 *)((char *)(var_a1) + 0)) = temp_v0_14;
                    (*(s32 *)((char *)(var_a1) + 8)) = temp_t0_4;
                    (*(s32 *)((char *)(var_a1) + 0xC)) = temp_t1_4;
                    var_a1 += 0x10;
                    var_a2 -= 0x10;
                    goto loop_19;
                }
loop_21:
                if (var_a2 >= 4) {
                    temp_v0_15 = *(s32*)var_a0;
                    var_a0 += 4;
                    *(s32*)var_a1 = temp_v0_15;
                    var_a1 += 4;
                    var_a2 -= 4;
                    goto loop_21;
                }
            }
        }
        if (var_a2 != 0) {
            temp_v1_8 = &var_a0[var_a2];
            do {
                temp_v0_16 = *var_a0;
                var_a0 += 1;
                *var_a1 = temp_v0_16;
                var_a1 += 1;
            } while (var_a0 != temp_v1_8);
        }
        /* Duplicate return node #10. Try simplifying control flow for better match */
        return (s32) temp_a3;
    }
    return (s32) temp_a3;
}
