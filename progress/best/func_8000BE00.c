f64 func_8000BD08(f64, f64);
extern u8 D_8010A4FC;
s32 func_8000BE00(s32 arg0, s32 arg1, s32 arg2) {
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fs3;
    f64 temp_fs0;
    var_fs0 = (200.0f - (2.0f * (f32) D_8010A4FC)) * 0.005f;
    if (var_fs0 > 1.0f) var_fs0 = 1.0f;
    temp_fs0 = (f64) var_fs0;
    var_fs3 = (f32) arg0 * 0.032258064f;
    var_fs2 = (f32) arg1 * 0.032258064f;
    var_fs1 = (f32) arg2 * 0.032258064f;
    var_fs3 = (f32) func_8000BD08((f64)var_fs3, temp_fs0);
    var_fs2 = (f32) func_8000BD08((f64)var_fs2, temp_fs0);
    var_fs1 = (f32) func_8000BD08((f64)var_fs1, temp_fs0);
    if (var_fs3 > 1.0f) var_fs3 = 1.0f;
    if (var_fs2 > 1.0f) var_fs2 = 1.0f;
    if (var_fs1 > 1.0f) var_fs1 = 1.0f;
    { s32 r = var_fs3 * 31.0f; s32 g = var_fs2 * 31.0f; s32 b = var_fs1 * 31.0f; return ((r & 0x1F) << 0xB) | ((g & 0x1F) << 6) | ((b & 0x1F) * 2); }
}
