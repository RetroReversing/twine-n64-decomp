extern f32 gSinCosTable[];
#define COS(x) gSinCosTable[(x) & 0xFFF]
#define SIN(x) gSinCosTable[((x) - 0x400) & 0xFFF]

/* Builds a 3x3 row-major rotation matrix from Euler angles: angles[0] = X, angles[1] = Y, angles[2] = Z, 4096 units per turn. */
void buildRotationMatrixS16(const s16 *angles, f32 *matrix, s32 arg2) {
    s32 angleY = angles[1];
    s32 angleZ = angles[2];
    f32 cosY = COS(angleY);
    f32 cosZ = COS(angleZ);
    f32 sinY = SIN(angleY);
    s32 angleX = angles[0];
    f32 cosX = COS(angleX);
    f32 sinZ = SIN(angleZ);
    f32 sinX = SIN(angleX);
    matrix[0] = cosZ * cosY;
    matrix[1] = cosZ * sinY * sinX - sinZ * cosX;
    matrix[2] = cosZ * sinY * cosX + sinZ * sinX;
    matrix[3] = sinZ * cosY;
    matrix[4] = sinZ * sinY * sinX + cosZ * cosX;
    matrix[5] = sinZ * sinY * cosX - cosZ * sinX;
    matrix[6] = -sinY;
    matrix[7] = cosY * sinX;
    matrix[8] = cosY * cosX;
}
