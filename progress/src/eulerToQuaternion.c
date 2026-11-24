extern f32 gSinCosTable[];

inline static float __repair_float_mul(f32 lhs, f32 rhs) { return lhs * rhs; }

/* Converts Euler angles into a quaternion using half-angle sin/cos lookups in the 4096-entry sine table. */ void eulerToQuaternion(f32 *euler, f32 *quat) {
    f32 x = __repair_float_mul(euler[0], 0.0007669904f);
    f32 y = __repair_float_mul(euler[1], 0.0007669904f);
    f32 z = __repair_float_mul(euler[2], 0.0007669904f);
    s32 ix, iy, iz;
    f32 sx, cx, sy, cy, sz, cz;
    f32 a, b, c, d;
    z *= 651.8986f;
    y *= 651.8986f;
    x *= 651.8986f;
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
    quat[0] = sy * c - cy * b;
    quat[1] = sy * d + cy * a;
    quat[2] = sy * b - cy * c;
    quat[3] = sy * a + cy * d;
}
