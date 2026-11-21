f32 __cosf(f32);
f32 sinApprox(f32);

void func_8000BBB4(f32 *m, f32 x, f32 y, f32 z) {
    f32 cx = __cosf(x);
    f32 sx = sinApprox(x);
    f32 cz = __cosf(z);
    f32 sz = sinApprox(z);
    f32 cy = __cosf(y);
    f32 sy = sinApprox(y);
    f32 a = cx * sz;
    f32 b = cz * sx;
    f32 c = cz * cx;
    f32 d = sz * sx;
    f32 zero = 0.0f;

    m[1] = a * sy + b;
    m[14] = zero;
    m[13] = zero;
    m[12] = zero;
    m[11] = zero;
    m[15] = 1.0f;
    m[2] = d - c * sy;
    m[3] = zero;
    m[7] = zero;
    m[8] = sy;
    m[4] = -cy * sx;
    m[9] = -cy * sz;
    m[5] = c - d * sy;
    m[0] = cy * cx;
    m[10] = cz * cy;
    m[6] = a + b * sy;
}
