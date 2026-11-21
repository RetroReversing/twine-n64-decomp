f64 applyFadeCurve(f64, f64);
extern u8 gColorFadeLevel;

/* Packs three 5-bit color channels into an RGB5A1 pixel, dimmed by the global fade level. */
s32 packFadedRgb5A1(s32 red, s32 green, s32 blue) {
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fs3;
    f64 temp_fs0;

    var_fs0 = (200.0f - (2.0f * (f32) gColorFadeLevel)) * 0.005f;
    if (var_fs0 > 1.0f) var_fs0 = 1.0f;
    temp_fs0 = (f64) var_fs0;
    var_fs3 = (f32) red * 0.032258064f;
    var_fs2 = (f32) green * 0.032258064f;
    var_fs1 = (f32) blue * 0.032258064f;
    var_fs3 = (f32) applyFadeCurve((f64)var_fs3, temp_fs0);
    var_fs2 = (f32) applyFadeCurve((f64)var_fs2, temp_fs0);
    var_fs1 = (f32) applyFadeCurve((f64)var_fs1, temp_fs0);
    if (var_fs3 > 1.0f) var_fs3 = 1.0f;
    if (var_fs2 > 1.0f) var_fs2 = 1.0f;
    if (var_fs1 > 1.0f) var_fs1 = 1.0f;
    red = var_fs3 * 31.0f;
    green = var_fs2 * 31.0f;
    blue = var_fs1 * 31.0f;
    return ((red & 31) << 11) | ((green & 31) << 6) | ((blue & 31) << 1);
}
