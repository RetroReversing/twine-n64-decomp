f32 approximate_hypot2(f32, f32);
f32 func_80082A70(f32, f32);

void func_80046424(f32 *arg0, f32 x, f32 y, f32 z) {
    arg0[0] = func_80082A70(y, approximate_hypot2(x, z)) * 651.8986f;
    arg0[1] = func_80082A70(x, z) * 651.8986f;
    ((s32 *)arg0)[2] = 0;
}
