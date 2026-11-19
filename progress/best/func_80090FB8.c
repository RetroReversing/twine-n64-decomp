/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */

extern u8 D_800CF540;
extern char D_800E5AC4[];
extern u8 D_800E6A85[];
extern char D_800E6A89[];

s32 func_80090FB8(s32 arg0, s32 arg1) {
    u32 var_a0;
    s32 var_a2;
    u32 var_v1;

    var_v1 = 0;
    if (D_800CF540 != 0) {
        var_a2 = 0;
        for (;;) {
            if ((*(D_800E6A85 + var_a2) != 0) || (*(s32 *)(D_800E5AC4 + var_a2) != (arg0 & 0x7FFFFFFF))) {
                var_v1 += 1;
                var_a2 += 0xFF8;
                if (var_v1 >= 8U) {
                    var_a0 = -1;
                } else {
                    continue;
                }
            } else {
                var_a0 = var_v1 | (arg0 & 0x7fffffff);
            }
            break;
        }
        if ((var_a0 != -1) && (var_a0 >= 0)) {
            *(D_800E6A89 + (var_a0 * 0xFF8)) = (arg1 & 0xFF) == 0;
            return 1;
        }
        goto block_10;
    }
block_10:
    return 0;
}
