static __inline__ int __repair_inline(s32 a, s32 b) { return a > b; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
extern s32 D_800F8158;
extern char D_800F815C[];
extern char D_800F8160[];
extern char D_800F8162[];
extern char D_800F8164[];
extern char D_800F8168[];

s32 func_800972A4(u16 arg0, s32 arg1, s16 arg2) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a0;
    s32 var_a3;
    s32 var_t1;
    s32 var_v0;
    s32 var_v1;
    u32 temp_a1;
    void *var_a2;
    void *var_t0;

    func_8008C0D4();
    var_a0 = D_800F8158;
    var_t1 = 0;
    if (__repair_inline(var_a0, 0)) {
        temp_a1 = arg0;
        var_v1 = 0;
loop_2:
        if ((u16) *(u16 *)(D_800F8160 + var_v1) < temp_a1) {
            var_t1 += 1;
            var_v1 += 0xC;
            if (var_t1 < var_a0) {
                goto loop_2;
            }
        }
        var_a0 = D_800F8158;
        if (var_t1 < var_a0) {{ s32 __repair_value; __repair_value = var_t1 * 0xC; temp_v1 = __repair_value; }
            if (*(u16 *)(D_800F8160 + temp_v1) != temp_a1) {
                var_a3 = var_a0 - 1;
                if (var_a0 < 0x100) {
                    if (var_a3 >= var_t1) {
                        var_a0 = var_a3 * 0xC;
                        var_t0 = var_a0 + D_800F8168;
                        var_a2 = var_a0 + (D_800F8168 - 0xC);
                        __repair_rows: {
                            var_a0 = (*(s32 *)((char *)(var_a2) + 8));
                            (*(s32 *)((char *)(var_t0) + 0)) = (s32) (*(s32 *)((char *)(var_a2) + 0));
                            (*(s32 *)((char *)(var_t0) + 8)) = var_a0;
                            (*(s32 *)((char *)(var_t0) + 4)) = (s32) (*(s32 *)((char *)(var_a2) + 4));
                            var_t0 -= 0xC;
                            var_a3 -= 1;
                            var_a2 -= 0xC;
                        }
if (var_a3 >= var_t1) goto __repair_rows;
                    }
                    var_v0 = D_800F8158 + 1;
                    goto block_14;
                }
                goto block_13;
            }
            *(u16 *)(D_800F8164 + temp_v1) = *(u16 *)(D_800F8164 + temp_v1) + 1;
            goto block_13;
        }
        goto block_12;
    }
block_12:
    var_v0 = D_800F8158 + 1;
    if (D_800F8158 >= 0x100) {
block_13:
        func_8008C11C(var_a0);
        return 0;
    }
block_14:
    D_800F8158 = var_v0;
    temp_v0_2 = var_t1 * 0xC;
    *(u16 *)(D_800F8160 + temp_v0_2) = arg0;
    *(s32 *)(D_800F815C + temp_v0_2) = arg1;
    *(s16 *)(D_800F8162 + (var_t1 * 0xC)) = arg2;
    *(u16 *)(D_800F8164 + temp_v0_2) = 1;
    func_8008C11C(var_a0);
    return 1;
}
