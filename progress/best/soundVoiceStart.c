/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8008E4A8();
s32 func_8008E594();
s32 func_8008E680();
s32 func_8008E96C();

void soundVoiceStart(void *arg0, f32 arg1, f32 arg2, s32 arg3, f32 arg4, f32 arg5) {
    u32 var_a1_3;
u32 __repair_phase_var_a1_3;
    f32 temp_fv1_2;
    f32 temp_fv1_3;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    s32 temp_s0;
    
    
    u32 var_a1_2;
    register f32 temp_fv1;
    
    u32 var_v0_2;
    
    u32 var_v1_2;
    s32 var_v1_3;

    temp_s0 = (*(s32 *)((char *)(arg0) + 0x34));
    if ((*(s32 *)((char *)(arg0) + 8)) & 0x100000) {
        temp_fv1 = (*(f32 *)((char *)(arg0) + 0x40)) * arg1 * 127.0f;
        __repair_phase_var_a1_3 = (u32) temp_fv1 & 0xFF;
        var_a1_3 = __repair_phase_var_a1_3 >= 0x80U ? 0x7F : __repair_phase_var_a1_3;
    } else {
        temp_fv1_2 = arg1 * 127.0f;
        var_a1_3 = (u8) (u32) temp_fv1_2;
        if (var_a1_3 >= 0x80U) {
            var_a1_3 = 0x7F;
        }
    }
    func_8008E96C(temp_s0, var_a1_3);
    temp_fv1_3 = (arg2 + 1.0f) * 64.0f;
    var_v1_2 = (u32) temp_fv1_3 & 0xFF;
    if (var_v1_2 < 0x80U) var_a1_2 = var_v1_2;
    else var_a1_2 = 0x7F;
    func_8008E4A8(temp_s0, var_a1_2);
    temp_fv1_4 = (1.0f - arg4) * 64.0f;
    var_v1_3 = (u32) temp_fv1_4 & 0xFF;
    var_a1_3 = var_v1_3;
    if (var_v1_3 >= 0x80U) {
        var_a1_3 = 0x7F;
    }
    func_8008E594(temp_s0, var_a1_3);
    temp_fv1_5 = arg5 * 8192.0f;
    var_v1_3 = (u32) temp_fv1_5;
    var_a1_3 = (u32)var_v1_3 < 0x4000U;
    var_v0_2 = var_v1_3;
    if (var_a1_3 == 0) {
        var_v0_2 = 0x3FFF;
    }
    func_8008E680(temp_s0, var_v0_2 & 0xFFFF);
}
