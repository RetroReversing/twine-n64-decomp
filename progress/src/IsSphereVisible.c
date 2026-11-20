f32 planeDotPoint(f32 *, s32);
f32 absFloat(f32);
s32 rotateVec3ByMat3(void *, f32 *);
extern f32 gCullFarDistance;
typedef struct { u8 pad[0x20]; s32 planes; } B14C10;
typedef struct { u8 pad0[0x10]; f32 pos[3]; u8 pad1c[0x30]; f32 r; u8 pad50[0x18]; f32 f68, f6C; u8 pad70[0x18]; u8 m[0x18]; f32 a0, a4, a8; u8 padAC[8]; f32 b4; } C14C10;

/* Tests whether a bounding sphere at center is inside the camera frustum (depth and side planes). */
s32 IsSphereVisible(f32 *center, f32 radiusScale, B14C10 *frustum, C14C10 *camera) {
    f32 viewPos[3];
    f32 viewDepthTerms[3];
    f32 radius = radiusScale * camera->r;
    f32 negRadius;

    viewPos[0] = center[0] - camera->pos[0];
    viewPos[1] = center[1] - camera->pos[1];
    viewPos[2] = center[2] - camera->pos[2];
    rotateVec3ByMat3(camera->m, viewPos);
    if (gCullFarDistance < viewPos[2] - radius) {
        return 0;
    }
    if (viewPos[2] + radius < 0.2f) {
        return 0;
    }
    negRadius = -radius;
    if (planeDotPoint(viewPos, frustum->planes + 0x10) < negRadius) {
        return 0;
    }
    if (radius < planeDotPoint(viewPos, frustum->planes + 0x20)) {
        return 0;
    }
    if (radius < planeDotPoint(viewPos, frustum->planes + 0x30)) {
        return 0;
    }
    if (planeDotPoint(viewPos, frustum->planes + 0x40) < negRadius) {
        return 0;
    }
    if (radius > 0.5f) {
        viewDepthTerms[2] = camera->a0 * center[0] + camera->a4 * center[1] + camera->a8 * center[2];
        viewDepthTerms[2] = viewDepthTerms[2] + camera->b4;
        if (absFloat((camera->f68 / viewDepthTerms[2] * radius + camera->f6C / viewDepthTerms[2] * radius) * 0.5f) < 2.0f) {
            return 0;
        }
    }
    return 1;
}
