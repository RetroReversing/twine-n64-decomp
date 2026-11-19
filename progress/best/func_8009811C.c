/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008C0D4();                            /* extern */
s32 func_8008C11C();                            /* extern */
extern s32 D_800F8D5C;
extern s32 D_800F8D60;
extern s32 D_800F8D62;
extern s32 D_800F9560;
extern s32 D_800F9564;
extern s32 D_800F9566;

s32 func_8009811C(s32 arg0) {
    unsigned long temp_v0_3;
    s32 temp_a1;
s32 __repair_phase_temp_a1;
    s32 *var_a1;
    s16 temp_v0_2;
    s32 temp_v1_2;
    int temp_v0_4;
    register s32 temp_v0;
    
    
    s32 var_a2_2;
    s32 var_v0_2;
    u16 temp_t1;
    u16 temp_v1;
    u16 temp_v1_3;
    u16 var_v0;
    u32 temp_s0;
    u32 temp_t2;
    void *var_a3;
    void *var_t0;

    func_8008C0D4();
    temp_s0 = arg0 & 0xFFFF;
    temp_t2 = temp_s0 >> 6;
    __repair_phase_temp_a1 = temp_t2 * 4;
    temp_v1 = *((s32 *)((s8 *)&D_800F8D60 + __repair_phase_temp_a1));
    if ((unsigned)temp_v1 != 0) {
        register temp_t1 = *((s32 *)((s8 *)&D_800F8D62 + __repair_phase_temp_a1));
        __repair_phase_temp_a1 = 0;
        if (temp_v1 != 0) {
            register var_v0 = temp_t1;
loop_3:
            var_v0_2 = temp_t2 * 4;
            if (*((s32 *)((s8 *)&D_800F9564 + (temp_t1 * 8))) != temp_s0) {
                __repair_phase_temp_a1 += 1;
                var_v0 = temp_t1 + __repair_phase_temp_a1;
                if (__repair_phase_temp_a1 >= (s32) temp_v1) {
                    var_v0_2 = temp_t2 * 4;
                } else {
                    goto loop_3;
                }
            }
            temp_a1 = temp_t1 + __repair_phase_temp_a1;
            if (__repair_phase_temp_a1 < (s32) *((s32 *)((s8 *)&D_800F8D60 + var_v0_2))) {
                register temp_v1_2 = temp_a1 * 8;
                register temp_v0_2 = *((s32 *)((s8 *)&D_800F9566 + temp_v1_2)) - 1;
                *((s32 *)((s8 *)&D_800F9566 + temp_v1_2)) = temp_v0_2;
                var_a2_2 = temp_a1 + 1;
                if (!(temp_v0_2 & 0xFFFF)) {
                    if (var_a2_2 < D_800F8D5C) {
                        temp_v0_3 = var_a2_2 * 8;
                        var_t0 = temp_v0_3 + (&D_800F9560 - 8);
                        var_a3 = temp_v0_3 + &D_800F9560;
                        do {
                            (*(s32 *)((char *)(var_t0) + 0)) = (s32) (*(s32 *)((char *)((unsigned)var_a3) + 0));
                            var_t0 += 8;
                            (*(s32 *)((char *)(var_t0) + 4)) = (s32) (*(s32 *)((char *)(var_a3) + 4));
                            var_a2_2 += 1;
                            var_a3 += 8;
                        } while (var_a2_2 < D_800F8D5C);
                    }
                    var_a1 = &D_800F8D60;
                    __repair_phase_temp_a1 = 0;
                    do { {
                        temp_v1_3 = *((s32 *)((s8 *)&D_800F8D62 + __repair_phase_temp_a1));
                        if ((s32) temp_t1 < (s32) temp_v1_3) {
                            (*(s16 *)((char *)(var_a1) + 2)) = (s16) (temp_v1_3 - 1);
                        }
                        __repair_phase_temp_a1 += 4;
                        var_a1 += 4;
                    }
} while (0x800 > __repair_phase_temp_a1);
                    temp_v0_4 = temp_t2 * 4;
                    *((s32 *)((s8 *)&D_800F8D60 + temp_v0_4)) = *((s32 *)((s8 *)&D_800F8D60 + temp_v0_4)) - 1;
                    D_800F8D5C -= 1;
                }
            }
        }
    }
    func_8008C11C();
    return 0;
}
