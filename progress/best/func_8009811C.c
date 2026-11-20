/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */

s32 func_8008C0D4();                            /* extern */
s32 func_8008C11C();                            /* extern */
extern s32 D_800F8D5C;
extern s32 D_800F8D60;
extern s32 D_800F8D62;
extern s32 D_800F9560;
extern s32 D_800F9564;
extern s32 D_800F9566;

s32 func_8009811C(s32 arg0) {
    s32 *__base_D_800F9560;
int __repair_literal;

    s32 *var_a1;
    u16 temp_v0_2;
    register s32 var_v0;
    u32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    register s32 temp_v1_2;
    s32 var_a0;
    s32 var_a2;
    s32 temp_a1;
    s32 var_v0_2;
    s32 var_a2_2;
    void *var_a3;
    s32 temp_v1_3;
    u32 temp_s0;
    register s32 temp_t1;
    u32 temp_t2;
    u16 temp_v1;
    void *var_t0;

    func_8008C0D4();
    temp_s0 = arg0 & 0xFFFF;
    temp_t2 = temp_s0 >> 6;
    var_a2 = temp_t2 * 4;
    temp_v1 = *((s32 *)((s8 *)&D_800F8D60 + var_a2));
    if (temp_v1 != 0) {
        temp_t1 = *((u16 *)((s8 *)&D_800F8D62 + var_a2));
        var_a2 = 0;
        if (temp_v1 != 0) {
            var_v0 = temp_t1;
loop_3:
            var_v0_2 = temp_t2 * 4;
            if (*((u16 *)((s8 *)&D_800F9564 + (var_v0 * 8))) != temp_s0) {
                var_a2 += 1;
                var_v0 = temp_t1 + var_a2;
                if (var_a2 >= temp_v1) {
__repair_literal = 4;

                    var_v0_2 = temp_t2 * __repair_literal;
                } else {
                    goto loop_3;
                }
            }
            temp_a1 = temp_t1 + var_a2;
            if (var_a2 < (s32) *((u16 *)((s8 *)&D_800F8D60 + var_v0_2))) {
                temp_v1_2 = temp_a1 * 8;
                temp_v0_2 = *((u16 *)((s8 *)&D_800F9566 + temp_v1_2)) - 1;
                temp_a1 = temp_a1 + 1;
                *((u16 *)((s8 *)&D_800F9566 + temp_v1_2)) = temp_v0_2;
                if (!(temp_v0_2 & 0xFFFF)) {
                    if (temp_a1 < D_800F8D5C) {
                        temp_v0_3 = temp_a1 * 8;
                        __base_D_800F9560 = &D_800F9560;
                        var_t0 = temp_v0_3 + (__base_D_800F9560 - 8);
                        var_a3 = temp_v0_3 + __base_D_800F9560;
                        do {
                            (*(s32 *)((char *)(var_t0) + 0)) = (s32) (*(s32 *)((char *)(var_a3) + 0));
                            temp_a1 += 1;
                            (*(s32 *)((char *)(var_t0) + 4)) = (s32) (*(s32 *)((char *)(var_a3) + 4));
                            var_t0 += 8;
                            var_a3 += 8;
                        } while (temp_a1 < D_800F8D5C);
                    }
                    var_a1 = &D_800F8D60;
                    var_a0 = 0;
                    do {
                        temp_v1_3 = *((u16 *)((s8 *)&D_800F8D62 + var_a0));
                        if (temp_t1 < (s32) temp_v1_3) {
                            (*(s16 *)((char *)(var_a1) + 2)) = (s16) (temp_v1_3 - 1);
                        }
                        var_a0 += 4;
                        ++var_a1;
                    } while (var_a0 < 0x800);
                    temp_v0_4 = temp_t2 * 4;
                    *((u16 *)((s8 *)&D_800F8D60 + temp_v0_4)) = *((u16 *)((s8 *)&D_800F8D60 + temp_v0_4)) - 1;
                    D_800F8D5C -= 1;
                }
            }
        }
    }
    func_8008C11C();
    return 0;
}
