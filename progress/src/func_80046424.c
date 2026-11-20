f32 approximate_hypot2(f32, f32);
f32 approximateAtan2(f32, f32);

void func_80046424(f32 *arg0, f32 x, f32 y, f32 z) {
    arg0[0] = approximateAtan2(y, approximate_hypot2(x, z)) * 651.8986f;
    arg0[1] = approximateAtan2(x, z) * 651.8986f;
    ((s32 *)arg0)[2] = 0;
}
