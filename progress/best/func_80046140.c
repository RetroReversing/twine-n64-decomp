/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

f32 func_800828D0(f32);                             /* extern */

f32 func_80046140(f32 arg1) {
    f32 temp_fv0;
    f32 var_fa0;
    register f32 temp_fs2;
    f32 var_ft0;

    temp_fs2 = func_800828D0(arg1);
    temp_fv0 = func_800828D0(arg1);
    if (temp_fv0 < temp_fs2) {
        var_fa0 = temp_fs2;
        var_ft0 = temp_fv0;
    } else {
        register var_fa0 = temp_fv0;
        register var_ft0 = temp_fs2;
    }
    return (var_fa0 * 0.9604f) + (var_ft0 * 0.3978f);
}
