/* Returns 1 when the triangle v0/v1/v2 lies entirely outside the bounds [minA, maxA] on coordinate A (offset 0) or [minB, maxB] on coordinate B (offset 8), else 0. */
#define VERT_F32(p, off) (*(f32 *)((s8 *)(p) + (off)))

s32 triangleOutsideBounds(void *v0, void *v1, void *v2, f32 minA, f32 minB, f32 maxA, f32 maxB) {
    s32 outside;

    if (VERT_F32(v0, 8) < minB) {
        if (!(VERT_F32(v1, 8) < minB) || (outside = 0, !(VERT_F32(v2, 8) < minB))) {
            goto block_4;
        }
    } else {
block_4:
        if (!(maxB < VERT_F32(v0, 8)) || !(maxB < VERT_F32(v1, 8)) || (outside = 0, !(maxB < VERT_F32(v2, 8)))) {
            if (VERT_F32(v0, 0) < minA) {
                if (!(VERT_F32(v1, 0) < minA) || !(VERT_F32(v2, 0) < minA)) {
                    goto block_11;
                }
                goto block_14;
            }
block_11:
            outside = 1;
            if ((maxA < VERT_F32(v0, 0)) && (maxA < VERT_F32(v1, 0)) && (maxA < VERT_F32(v2, 0))) {
block_14:
                outside = 0;
            }
        }
    }
    return outside;
}
