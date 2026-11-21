extern f32 gSinCosTable[];

void func_80046648(f32 *arg0, f32 *arg1) {
    f32 x = arg0[0] * 0.0007669904f;
    f32 y = arg0[1] * 0.0007669904f;
    f32 z = arg0[2] * 0.0007669904f;
    s32 ix, iy, iz;
    f32 sx, cx, sy, cy, sz, cz;
    f32 a, b, c, d;
    x *= 651.8986f;
    z *= 651.8986f;
    y *= 651.8986f;
    ix = (s32) x;
    sx = gSinCosTable[ix & 0xFFF];
    iz = (s32) z;
    sz = gSinCosTable[iz & 0xFFF];
    a = sx * sz;
    cz = gSinCosTable[(iz - 0x400) & 0xFFF];
    b = sx * cz;
    cx = gSinCosTable[(ix - 0x400) & 0xFFF];
    c = cx * sz;
    d = cx * cz;
    iy = (s32) y;
    sy = gSinCosTable[iy & 0xFFF];
    cy = gSinCosTable[(iy - 0x400) & 0xFFF];
    arg1[0] = sy * c - cy * b;
    arg1[1] = sy * d + cy * a;
    arg1[2] = sy * b - cy * c;
    arg1[3] = sy * a + cy * d;
}
