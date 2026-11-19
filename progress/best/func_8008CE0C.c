/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern char D_800E4290[];

s32 func_8008CE0C(void *arg0) {
    char *__base_D_800E4290;
    s32 *var_v0;
    u8 temp_v1;

    temp_v1 = (*(u8 *)((char *)(arg0) + 0x4B));
    if (temp_v1 != 0xFF) {
        var_v0 = (temp_v1 * 4) + __base_D_800E4290;
        __base_D_800E4290 = D_800E4290;
    } else {
        var_v0 = __base_D_800E4290 + 0x20;
    }
    return *var_v0;
}
