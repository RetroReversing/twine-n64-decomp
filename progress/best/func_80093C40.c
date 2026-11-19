/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008E4A8();
s32 func_8008E594();
s32 func_8008E680();
s32 func_8008E96C();

void func_80093C40(void *arg0, f32 arg1, f32 arg2, s32 arg3, f32 arg4, f32 arg5) {
    f32 temp_fv1;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    s32 temp_s0;
    s32 var_v0;
    u32 var_a1;
    u32 var_a1_2;
    long var_a1_4;
    u32 var_a1_3;
    u32 var_v0_2;
    u32 var_v1;
    u32 var_v1_2;
    u32 var_v1_3;

    temp_s0 = (*(s32 *)((char *)(arg0) + 0x34));
    if ((*(s32 *)((char *)(arg0) + 8)) & 0x100000) {
        temp_fv1 = (*(f32 *)((char *)(arg0) + 0x40)) * arg1 * 127.0f;
        if (temp_fv1 >= 2.1474836e9f) {
            var_v1 = ((s32) (temp_fv1 - 2.1474836e9f) | 0x80000000) & 0xFF;
        } else {
            var_v1 = (s32) temp_fv1 & 0xFF;
        }
        var_a1 = var_v1;
        if (var_v1 < 0x80U) {

        } else {
            goto block_14;
        }
    } else {
        temp_fv1_2 = arg1 * 127.0f;
        if (temp_fv1_2 >= 2.1474836e9f) {
            var_a1 = ((s32) (temp_fv1_2 - 2.1474836e9f) | 0x80000000) & 0xFF;
        } else {
            var_a1 = (s32) temp_fv1_2;
var_a1 = var_a1 & 0xFF;
        }
        if (var_a1 >= 0x80U) {
block_14:
            var_a1 = 0x7F;
        }
    }
    func_8008E96C(temp_s0, var_a1);
    temp_fv1_3 = (arg2 + 1.0f) * 64.0f;
    if (temp_fv1_3 >= 2.1474836e9f) {
        var_v1_2 = ((s32) (temp_fv1_3 - 2.1474836e9f) | 0x80000000) & 0xFF;
    } else {
        var_v1_2 = (s32) temp_fv1_3 & 0xFF;
    }
    var_a1_2 = var_v1_2;
    if (var_v1_2 >= 0x80U) {
        register var_a1_2 = 0x7F;
    }
    func_8008E4A8(temp_s0, var_a1_2);
    temp_fv1_4 = (1.0f - arg4) * 64.0f;
    if (temp_fv1_4 >= 2.1474836e9f) {
        var_v1_3 = ((s32) (temp_fv1_4 - 2.1474836e9f) | 0x80000000) & 0xFF;
    } else {
        var_v1_3 = (s32) temp_fv1_4 & 0xFF;
    }
    var_a1_3 = var_v1_3;
    if (0x80U <= var_v1_3) {
        var_a1_3 = 0x7F;
    }
    func_8008E594(temp_s0, var_a1_3);
    temp_fv1_5 = arg5 * 8192.0f;
    if (temp_fv1_5 >= 2.1474836e9f) {
        var_a1_4 = (s32) (temp_fv1_5 - 2.1474836e9f); var_a1_4 = var_a1_4 | 0x80000000;
        var_v0 = var_a1_4 < 0x4000U;
    } else {
        var_a1_4 = (u32) (s32) temp_fv1_5;
        var_v0 = var_a1_4 < 0x4000U;
    }
    var_v0_2 = var_a1_4;
    if (var_v0 == 0) {
        register var_v0_2 = 0x3FFF;
    }
    func_8008E680(temp_s0, var_v0_2 & 0xFFFF);
}
