static __inline__ s16 __repair_inline(s16 a) { return a; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern s16 *D_800AE724;
extern s16 D_800C2B28;
extern s16 D_800C2B32;
extern char D_800D1E58[];

s32 func_80001F40(s16 arg0, s8 arg1, s32 *arg2) {
    s16 **__base_D_800AE724;
short __repair_constant = 4;

    s32 unused[2];
    s16 **var_t1;
    s32 temp_a1;
    s32 var_a3;
    u32 var_t2;
    s32 var_t3;
    s32 var_v0;
    u8 var_v1;

    var_t3 = 0;
    var_a3 = 0;
    __base_D_800AE724 = &D_800AE724;
    if ((*__base_D_800AE724) != NULL) {
        var_t2 = 0;
        var_t1 = __base_D_800AE724;
        for (;;) {
            temp_a1 = **var_t1;
            if (arg0 == temp_a1) {
                var_t3 = 1;
            }
            var_v1 = *(D_800D1E58 + var_a3);
            if (*(D_800D1E58 + var_a3) >= 0) {
                for (;;) {
                    if (arg0 != temp_a1) {
                        var_a3 += 1;
                        goto block_25;
                    }
                    if (arg1 == (s8) var_v1) {
                        break;
                    }
                    var_a3 += 1;
block_25:
                    var_v1 = *(D_800D1E58 + var_a3);
                    if (*(u16 *)(D_800D1E58 + var_a3) < 0) {
                        goto block_26;
                    }
                }
                if (arg0 == D_800C2B32) {
                    if (arg1 == 2) {
                        *arg2 = 0;
                    }
                    if (arg1 == 0x1E) {
                        *arg2 = 1;
                    }
                }
                if (arg0 != D_800C2B28) {
                    return 1;
                }
                if (arg1 == 2) {
                    *arg2 = 0;
                }
                if (arg1 != 0x16) {
                    return 1;
                }
                *arg2 = 1;

            }
block_26:
            var_t2 += 4;
            var_a3 += 1;
            var_t1 += 1;
            if (*(s16 **)((char *)&D_800AE724 + var_t2) == 0) {
                goto block_27;
            }
            continue;
            break;
        }
    }
block_27:
    var_v0 = 0;
    if (!var_t3) {
        if (arg1 < 0x25) {
            if (arg1 == 2) {
                *arg2 = 0;
            }
            var_v0 = 1;
            if (arg1 == 0x14) {
                *arg2 = 1;
                return 1;
            }
            /* Duplicate return node #35. Try simplifying control flow for better match */
            return var_v0;
        }
        var_v0 = 0;
        /* Duplicate return node #35. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
