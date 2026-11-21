s32 workerLockAcquire(void);
s32 workerLockRelease(void);
void vec3Cross(void *, void *, void *);
s32 invertAffineTransform(void *, f32 *);
extern u8 gWorkerThreadActive;
typedef struct { s32 x,y,z; } Vec3s;
/* Stores three points and a negated offset into transform, derives the inverse 3x4 affine matrix and scale; returns 0 if the worker is inactive. */ s32 buildAxisTransform(void *transform, Vec3s *pointA, Vec3s *pointB, Vec3s *pointC, f32 *negOffset, u8 scaleByte) {
    s32 success;
    f32 matrix[12];
    if (!gWorkerThreadActive) {
        success = 0;
    } else {
        workerLockAcquire();
        *(Vec3s *)((s8 *)transform + 0xC) = *pointA;
        *(Vec3s *)((s8 *)transform + 0x18) = *pointB;
        *(Vec3s *)((s8 *)transform + 0x24) = *pointC;
        *(f32 *)((s8 *)transform + 0x3C) = -negOffset[0];
        *(f32 *)((s8 *)transform + 0x40) = -negOffset[1];
        *(f32 *)((s8 *)transform + 0x44) = -negOffset[2];
        vec3Cross((s8 *)transform + 0x30, (s8 *)transform + 0x3C, (s8 *)transform + 0x24);
        matrix[0] = *(f32 *)((s8 *)transform + 0x30);
        matrix[3] = *(f32 *)((s8 *)transform + 0x34);
        matrix[6] = *(f32 *)((s8 *)transform + 0x38);
        matrix[1] = *(f32 *)((s8 *)transform + 0x3C);
        matrix[4] = *(f32 *)((s8 *)transform + 0x40);
        matrix[7] = *(f32 *)((s8 *)transform + 0x44);
        matrix[2] = *(f32 *)((s8 *)transform + 0x24);
        matrix[5] = *(f32 *)((s8 *)transform + 0x28);
        matrix[8] = *(f32 *)((s8 *)transform + 0x2C);
        matrix[9] = *(f32 *)((s8 *)transform + 0xC);
        matrix[10] = *(f32 *)((s8 *)transform + 0x10);
        matrix[11] = *(f32 *)((s8 *)transform + 0x14);
        invertAffineTransform((s8 *)transform + 0x48, matrix);
        *(f32 *)((s8 *)transform + 0x84) = scaleByte * 0.007874016f;
        workerLockRelease();
        success = 1;
    }
    return success;
}
