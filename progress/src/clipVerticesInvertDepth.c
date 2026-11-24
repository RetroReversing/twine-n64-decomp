s32 clipVertices(s32);
extern void *clip_result_verts;
extern char clip_buffer_a[];
extern char D_800E177C[];
extern char D_800E1780[];
#define FIELD(p, offset) (*(f32 *)((char *)(p) + (offset)))

/* Copies input vertices into the clip buffer with reciprocal depth, clips them, and writes the clipped vertices out with reciprocal depth again; returns the clipped vertex count. */ s32 clipVerticesInvertDepth(void *outVerts, void *inVerts, s32 vertCount) {
    f32 invZ;
    f32 one;
    s32 clippedCount;
    s32 i;
    s32 offset;
    char *dst;
    char *src;
    char *clipped;
    char frame[16];

    src = inVerts;
    i = 0;
    if (vertCount > 0) {
        one = 1.0f;
        offset = 0;
        do {
            *(f32 *)(clip_buffer_a + offset) = FIELD(src, 0);
            *(f32 *)(D_800E177C + offset) = FIELD(src, 4);
            invZ = one / FIELD(src, 8);
            i++;
            src += 0x24;
            *(f32 *)(D_800E1780 + offset) = invZ;
            offset += 0x24;
        } while (i < vertCount);
    }
    clippedCount = clipVertices(vertCount);
    i = 0;
    if (clippedCount > 0) {
        one = 1.0f;
        dst = outVerts;
        clipped = clip_result_verts;
        do {
            FIELD(dst, 0) = FIELD(clipped, 0);
            FIELD(dst, 4) = FIELD(clipped, 4);
            invZ = one / FIELD(clipped, 8);
            i++;
            clipped += 0x24;
            FIELD(dst, 8) = invZ;
            dst += 0x24;
        } while (i < clippedCount);
    }
    return clippedCount;
}
