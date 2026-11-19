/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern u8 D_800E2CC0[];
extern char D_800E2CE4[];
extern s32 D_800E3F10;

s32 func_80087F60(s32 arg0) {
    s32 temp_a0;
s32 __repair_phase_temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    
    register u32 var_v1;

loop_1:
    var_v1 = 0;
loop_2:
    temp_a0 = 0;
loop_3:
    if ((*(D_800E2CC0 + temp_a0) == 0) || ((short)var_v1 == arg0) || (*(s32 *)(D_800E2CE4 + temp_a0) != (short)D_800E3F10)) {
        ++var_v1;
        temp_a0 += 0x1228;
        if (var_v1 < 2U) {
            goto loop_3;
        }
    }
    if (var_v1 != 2) {
        temp_a0 = D_800E3F10 + 1;
        D_800E3F10 = temp_a0;
        var_v1 = 0;
        if (temp_a0 == -1) {
            D_800E3F10 = 0;
            goto loop_1;
        }
        goto loop_2;
    }
    __repair_phase_temp_a0 = arg0 * 0x1228;
    temp_v1 = D_800E3F10 + 1;
    *(s32 *)(D_800E2CE4 + __repair_phase_temp_a0) = D_800E3F10;
    D_800E3F10 = temp_v1;
    if (temp_v1 == -1) {
        D_800E3F10 = 0;
    }
    return *(s32 *)(D_800E2CE4 + __repair_phase_temp_a0);
}
