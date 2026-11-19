/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80087100();
s32 memset();
s32 sprintf();
extern char D_800B2750[];

void func_800103B0(u8 *arg0, s8 *arg1, u8 arg2) {
    s32 temp_a2;
    s32 temp_s0;
    char *var_a1;
    u8 *temp_a2_2;
    s8 temp_v1;
    char *var_v1;
    char *var_a0;

    temp_s0 = arg2 & 0xFF;
    memset(arg0, 0, temp_s0);
    if (temp_s0 != 0) {
        var_v1 = arg1;
        for (;;) {
            if (((short)temp_s0 != 4) || (*(s8 *)var_v1 != 0)) {
                var_v1 += 1;
                if ((u8) *(s8 *)var_v1 >= 0x42U) {
                    __repair_rows: { sprintf(arg0, func_80087100(arg0, 0x3003)); }
if (0) goto __repair_rows;
                    return;
                }
                if ((s32) var_v1 >= (temp_s0 + arg1)) {
                    goto block_7;
                }
                continue;
            }
            break;
        }
        goto block_7;
    }
block_7:
    temp_a2 = arg2 & 0xFF;
    if ((int)temp_a2 != 0) {
        var_a0 = arg0;
        var_a1 = arg1;
        temp_a2_2 = &var_a0[temp_a2];
        do {
            temp_v1 = *(s8 *)var_a1;
            if (temp_v1 == 0) {
                *(u8 *)var_a0 = 0x20;
            } else if ((u32) temp_v1 < 0x42U) {
                *(u8 *)var_a0 = *(D_800B2750 + (temp_v1 & 0xFFFF));
            }
            var_a0 += 1;
            var_a1 += 1;
        } while ((s32) var_a0 < (s32) temp_a2_2);
    }
}
