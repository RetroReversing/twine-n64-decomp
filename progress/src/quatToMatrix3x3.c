typedef struct { f32 x, y, z, w; } RotationQuat;
/* Converts a quaternion into a 3x3 rotation matrix. */ void quatToMatrix3x3(const RotationQuat *quat, f32 matrix[3][3]) {
    f32 y = quat->y;
    register f32 y2 = y + y;
    f32 x = quat->x;
    f32 z = quat->z;
    f32 xy = y2 * x;
    f32 z2 = z + z;
    f32 xz = z2 * x;
    f32 yy = y2 * y;
    f32 zz = z2 * z;
    f32 w = quat->w;
    f32 yw = y2 * w;
    f32 zw = z2 * w;
    f32 x2 = x + x;
    f32 xx = x2 * x;
    f32 yz = z2 * y;
    f32 xw = x2 * w;
    matrix[0][0] = 1.0f - (yy + zz);
    matrix[0][1] = (xy - zw);
    matrix[0][2] = (xz + yw);
    matrix[1][0] = (xy + zw);
    matrix[1][1] = 1.0f - (xx + zz);
    matrix[1][2] = (yz - xw);
    matrix[2][0] = (xz - yw);
    matrix[2][1] = (yz + xw);
    matrix[2][2] = 1.0f - (xx + yy);
}
