extern f32 gSinCosTable[];
#define SIN_OF(x) gSinCosTable[(x) & 0xFFF]
#define COS_OF(x) gSinCosTable[((x) - 0x400) & 0xFFF]

/* Same as buildRotationMatrix: builds a row-major 3x3 rotation matrix from s16 Euler angles
   eulerAngles[0]=X, [1]=Y, [2]=Z, each a 4096-step full turn. */
void buildRotationMatrixCopy(const s16 *eulerAngles, f32 *rotMtx) {
    s32 angX = eulerAngles[0];
    s32 angY = eulerAngles[1];
    s32 angZ = eulerAngles[2];
    s32 cosXIdx = (angX - 0x400) & 0xFFF;
    f32 sinY = SIN_OF(angY);
    f32 sinZ = SIN_OF(angZ);
    f32 cosX = gSinCosTable[cosXIdx];
    f32 xyTerm = sinY * sinZ;
    f32 cosY = COS_OF(angY);
    f32 cosXcosY = cosX * cosY;
    f32 cosZ = COS_OF(angZ);
    f32 sinX = SIN_OF(angX);
    f32 sinYnegCosZ = sinY * -cosZ;
    f32 cosXsinZ = cosXcosY * sinZ + sinX * cosZ;
    f32 sinXcosY;

    rotMtx[0] = xyTerm;
    rotMtx[1] = sinYnegCosZ;
    rotMtx[2] = cosY;
    rotMtx[3] = cosXsinZ;
    rotMtx[4] = sinX * sinZ - cosXcosY * cosZ;
    rotMtx[5] = -cosX * sinY;
    sinXcosY = sinX * -cosY;
    rotMtx[6] = sinXcosY * sinZ + cosX * cosZ;
    rotMtx[7] = cosX * sinZ - sinXcosY * cosZ;
    rotMtx[8] = sinX * sinY;
}
