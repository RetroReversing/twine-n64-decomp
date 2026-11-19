/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80087100();
s16 strlen();

void func_80074FD4(void *arg0) {
    
    s16 temp_a0;
    s32 temp_a1;
s32 __repair_phase_temp_a1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a1;
    s32 var_s1;
    u8 temp_v1;
    void *temp_s0;

    temp_s0 = (*(void **)((char *)((*(void **)((char *)(arg0) + 0x6C))) + 4));
    temp_a1 = (u8)((*(u8 *)((char *)(temp_s0) + 0x13)));
    temp_a0 = (*(s16 *)((char *)(arg0) + 0x7A));
    if (temp_a0 != 0) {
        temp_v0 = temp_a1 - 8;
        if (temp_a0 != 1) {
            var_a1 = temp_a1 << 0x10;
        } else {
            var_s1 = temp_v0;
            if (temp_v0 < 0) {
                (*(s16 *)((char *)(arg0) + 0x7A)) = 0;
                var_s1 = 0;
                temp_v0 = 0xF8;
                if ((*(s32 *)((char *)(temp_s0) + 0x18)) == func_80087100(0xF8, arg0)) {
                    temp_v0 = 0x2AB;
                }
                (*(s16 *)((char *)(temp_s0) + 0x1C)) = strlen((*(s32 *)((char *)(temp_s0) + 0x18)));
                (*(s32 *)((char *)((short)temp_s0) + 0x18)) = func_80087100(temp_v0);
            }
            goto block_9;
        }
    } else {
        temp_v0_2 = temp_a1 + 8;
        var_s1 = temp_v0_2;
        if (temp_v0_2 >= 0x100) {
            (*(s16 *)((char *)(arg0) + 0x7A)) = 1;
            var_s1 = 0xFF;
        }
block_9:
        var_a1 = var_s1 << 0x10;
    }
    __repair_phase_temp_a1 = var_a1 >> 0x10;
    (*(s32 *)((char *)(temp_s0) + 0x10)) = (s32) ((__repair_phase_temp_a1 << 0x10) | ((__repair_phase_temp_a1 << 8) | 0xFF000000) | __repair_phase_temp_a1);
}
