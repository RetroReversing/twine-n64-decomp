/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern char D_800D1450[];

s32 func_800746A8(s8 *arg0) {
    s32 var_a2;
    s8 temp_v0_2;
    char *var_a0;
    s8 *var_v0;
    char *var_v1;
    s8 temp_v0;
    s32 var_a1;
    s8 temp_v0_3;

    temp_v0 = *arg0;
    var_a1 = 0;
    var_a2 = 0;
    if (!temp_v0) {
        return 0;
    }
    var_v0 = arg0;
    if (*(D_800D1450 + (temp_v0 & 0xFF)) & 1) {
        var_v1 = arg0;
        do {
            if (*(s8 *)var_v1 == (unsigned)0xA) {
                *(s8 *)var_v1 = 0x20;
            }
            ++var_v1;
            ++var_a1;
            ++var_a2;
        } while (*(D_800D1450 + *(s8 *)var_v1) & 1);
        var_v0 = arg0 + var_a1;
    }
    temp_v0_2 = *var_v0;
    if (((int)temp_v0_2 != 0) && !(*(D_800D1450 + (temp_v0_2 & (unsigned)0xFF)) & 1)) {
        var_a0 = var_a1 + 1 + arg0;
loop_11:
        temp_v0_3 = *(s8 *)var_a0;
        ++var_a2;
        if (temp_v0_3 != 0) {
            var_a0 += 1;
            if (!(*(D_800D1450 + (temp_v0_3 & 0xFF)) & 1)) {
                goto loop_11;
            }
        }
    }
    return var_a2;
}
