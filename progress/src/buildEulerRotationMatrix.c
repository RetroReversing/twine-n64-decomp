f32 __cosf(f32);
f32 sinApprox(f32);

/* Builds a 4x4 rotation matrix (no translation) from three Euler angles. */ void buildEulerRotationMatrix(f32 *matrix, f32 angleX, f32 angleY, f32 angleZ) {
    f32 cx = __cosf(angleX);
    f32 sx = sinApprox(angleX);
    f32 cz = __cosf(angleZ);
    f32 sz = sinApprox(angleZ);
    f32 cy = __cosf(angleY);
    f32 sy = sinApprox(angleY);
    f32 a = cx * sz;
    f32 b = cz * sx;
    f32 c = cz * cx;
    f32 d = sz * sx;
    f32 zero = 0.0f;

    matrix[1] = a * sy + b;
    matrix[14] = zero;
    matrix[13] = zero;
    matrix[12] = zero;
    matrix[11] = zero;
    matrix[15] = 1.0f;
    matrix[2] = d - c * sy;
    matrix[3] = zero;
    matrix[7] = zero;
    matrix[8] = sy;
    matrix[4] = -cy * sx;
    matrix[9] = -cy * sz;
    matrix[5] = c - d * sy;
    matrix[0] = cy * cx;
    matrix[10] = cz * cy;
    matrix[6] = a + b * sy;
}
