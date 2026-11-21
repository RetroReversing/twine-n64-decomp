/* Returns 1 when triangle v0/v1/v2 overlaps the box range [minA, maxA] on coordinate A (offset 0) and [minB, maxB] on coordinate B (offset 8); 0 when it lies fully outside either range. */
#define VERT_F32(p, off) (*(f32 *)((s8 *)(p) + (off)))

s32 triangleOverlapsBounds(void *v0, void *v1, void *v2, f32 minA, f32 minB, f32 maxA, f32 maxB) {
    s32 overlaps;

    if (VERT_F32(v0, 8) < minB) {
        if (!(VERT_F32(v1, 8) < minB) || (overlaps = 0, !(VERT_F32(v2, 8) < minB))) {
            goto block_4;
        }
    } else {
block_4:
        if (!(maxB < VERT_F32(v0, 8)) || !(maxB < VERT_F32(v1, 8)) || (overlaps = 0, !(maxB < VERT_F32(v2, 8)))) {
            if (VERT_F32(v0, 0) < minA) {
                if (!(VERT_F32(v1, 0) < minA) || !(VERT_F32(v2, 0) < minA)) {
                    goto block_11;
                }
                goto block_14;
            }
block_11:
            overlaps = 1;
            if ((maxA < VERT_F32(v0, 0)) && (maxA < VERT_F32(v1, 0)) && (maxA < VERT_F32(v2, 0))) {
block_14:
                overlaps = 0;
            }
        }
    }
    return overlaps;
}
