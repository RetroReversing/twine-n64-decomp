typedef struct { f32 x, y, z, w; } RotationQuat;
void func_800468E4(const RotationQuat *q, f32 m[3][3]) {
    f32 y = q->y;
    register f32 y2 = y + y;
    f32 x = q->x;
    f32 z = q->z;
    f32 xy = y2 * x;
    f32 z2 = z + z;
    f32 xz = z2 * x;
    f32 yy = y2 * y;
    f32 zz = z2 * z;
    f32 w = q->w;
    f32 yw = y2 * w;
    f32 zw = z2 * w;
    f32 x2 = x + x;
    f32 xx = x2 * x;
    f32 yz = z2 * y;
    f32 xw = x2 * w;
    m[0][0] = 1.0f - (yy + zz);
    m[0][1] = (xy - zw);
    m[0][2] = (xz + yw);
    m[1][0] = (xy + zw);
    m[1][1] = 1.0f - (xx + zz);
    m[1][2] = (yz - xw);
    m[2][0] = (xz - yw);
    m[2][1] = (yz + xw);
    m[2][2] = 1.0f - (xx + yy);
}
