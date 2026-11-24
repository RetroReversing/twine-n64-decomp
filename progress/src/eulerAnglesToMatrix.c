f32 __cosf(f32);
f32 sinApprox(f32);

/* Builds a 3x3 rotation matrix (row-major) from three s16 Euler angles (4096 units per turn). */ void eulerAnglesToMatrix(const s16 *angles, f32 *matrix) {
    register f32 radX;
    register f32 temp_ft1;
    f32 temp_ft0_2;
    f32 temp_ft0;
    register f32 radY;
    f32 cosY;
    f32 temp_fv1_2;
    f32 cosZ;
    f32 radZ;
    f32 cosX;
    f32 sinZ;
    f32 temp_ft2;
    f32 temp_fv0_2;
    register f32 sinY;
    register f32 temp_fv1;
    register f32 sinX;


    radX = (f32) angles[0] * 0.0015339808f;
    cosX = __cosf(radX);
    sinX = sinApprox(radX);
    radY = (f32) angles[1] * 0.0015339808f;
    cosY = __cosf(radY);
    sinY = sinApprox(radY);
    radZ = (f32) angles[2] * 0.0015339808f;
    cosZ = __cosf(radZ);
    sinZ = sinApprox(radZ);

    matrix[0] = (cosZ * cosY);
    matrix[1] = (cosZ * sinY) * sinX - (sinZ * cosX);
    matrix[2] = (cosZ * sinY) * cosX + (sinZ * sinX);
    matrix[3] = (sinZ * cosY);
    matrix[4] = (sinZ * sinY) * sinX + (cosZ * cosX);
    matrix[5] = (sinZ * sinY) * cosX - (cosZ * sinX);
    matrix[6] = -sinY;
    matrix[7] = (cosY * sinX);
    matrix[8] = (cosY * cosX);
}
