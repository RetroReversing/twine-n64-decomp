f32 func_800A08C0(f32);
f32 func_800A0E00(f32);

void func_8000BBB4(f32 *m, f32 x, f32 y, f32 z) {
    f32 cx = func_800A08C0(x);
    f32 sx = func_800A0E00(x);
    f32 cz = func_800A08C0(z);
    f32 sz = func_800A0E00(z);
    f32 cy = func_800A08C0(y);
    f32 sy = func_800A0E00(y);
    f32 a = cx * sz;
    f32 b = cz * sx;
    f32 c = cz * cx;
    f32 d = sz * sx;
    f32 zero = 0.0f;

    m[8] = sy;
    m[14] = zero;
    m[13] = zero;
    m[12] = zero;
    m[11] = zero;
    m[3] = zero;
    m[7] = zero;
    m[15] = 1.0f;
    m[0] = cy * cx;
    m[10] = cz * cy;
    m[4] = -cy * sx;
    m[9] = -cy * sz;
    m[1] = a * sy + b;
    m[2] = d - c * sy;
    m[5] = c - d * sy;
    m[6] = a + b * sy;
}
