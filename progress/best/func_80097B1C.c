/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();
s32 func_8008C11C();
s32 func_8008C7C0();
extern char D_800F38E4[];
extern s32 D_800F38EC;
extern char D_800F38F0[];

s32 func_80097B1C(s32 arg0) {
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_v1;
    s32 var_s4;
    s32 var_v0;
    char *var_s1;
    u16 **var_s2;
    u16 *temp_a1;
    s32 var_s0_2;
    u16 temp_v0;
    u16 var_a0;
    u32 var_s3;
    void *var_a3;
    void *var_s0;
    void *var_t0;

    var_s3 = 0;
    var_a1 = 0;
    if (D_800F38EC != 0) {
        var_s2 = D_800F38E4 + 0xC;
loop_2:
        var_s1 = *var_s2;
        var_a0 = *(u16 *)var_s1;
        var_s4 = 0;
        if ((var_a0 & 0xFFFF) != 0xFFFF) {
            var_s0 = var_s1 + 2;
            do {
                if (var_a0 == (arg0 & 0xFFFF)) {
                    temp_v0 = (*(u16 *)((char *)(var_s0) + 0)) - 1;
                    (*(u16 *)((char *)(var_s0) + 0)) = temp_v0;
                    if (!(temp_v0 & 0xFFFF)) {
                        func_8008C7C0(var_s1 + 0xC, (*(s32 *)((char *)(var_s0) + 2)));
                    }
                    var_a1 = 1;
                }
                if ((*(u16 *)((char *)(var_s0) + 0)) != 0) {
                    var_s4 = 1;
                }
                var_s1 += 0x1C;
                var_a0 = *(u16 *)var_s1;
                var_s0 += 0x1C;
            } while (var_a0 != 0xFFFF);
        }
        if (var_a1 & 0xFF) {
            if (var_s4 & 0xFF) {
                return 1;
            }
            temp_a1 = *var_s2;
            var_s0_2 = 0;
            if (D_800F38EC > 0) {
                var_v1 = 0;
loop_16:
                if (*(s32 *)(D_800F38F0 + var_v1) != temp_a1) {
                    var_s0_2 += 1;
                    var_v1 += 0xC;
                    if (var_s0_2 < D_800F38EC) {
                        goto loop_16;
                    }
                }
            }
            var_v0 = 1;
            if (var_s0_2 != D_800F38EC) {
                func_8008C0D4(D_800F38EC, temp_a1);
                var_a2 = var_s0_2 + 1;
                if (var_a2 < D_800F38EC) {
                    temp_v0_2 = var_a2 * 0xC;
                    var_t0 = temp_v0_2 + D_800F38E4;
                    var_a3 = temp_v0_2 + D_800F38F0;
                    __repair_rows: {
                        (*(s32 *)((char *)(var_t0) + 0)) = (s32) (*(s32 *)((char *)(var_a3) + 0));
                        var_t0 += 0xC;
                        (*(s32 *)((char *)(var_t0) + 4)) = (s32) (*(s32 *)((char *)(var_a3) + 4));
                        (*(s32 *)((char *)(var_t0) + 8)) = (s32) (*(s32 *)((char *)(var_a3) + 8));
                        var_a3 += 0xC;
                        var_a2 += 1;
                    }
if (var_a2 < D_800F38EC) goto __repair_rows;
                }
                D_800F38EC -= 1;
                func_8008C11C();
                return 1;
            }
            /* Duplicate return node #25. Try simplifying control flow for better match */
            return var_v0;
        }
        var_s3 += 1;
        var_s2 += 0xC;
        if (var_s3 >= (u32) D_800F38EC) {
            goto block_24;
        }
        goto loop_2;
    }
block_24:
    var_v0 = 0;
    return var_v0;
}
