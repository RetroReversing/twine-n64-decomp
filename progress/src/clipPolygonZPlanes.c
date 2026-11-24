/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce -fno-schedule-insns, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 clip_verts_z_planes();
extern void *clip_result_verts;
extern char clip_buffer_a[];
extern char D_800E177C[];
extern char D_800E1780[];

/* Copies vertex positions into the clip buffer, clips against the Z planes, and copies the resulting vertices back out; returns the new count. */ s32 clipPolygonZPlanes(void *outVerts, void *inVerts, s32 vertCount) {
    f32 z;
    f32 clippedZ;
    s32 clippedCount;
    s32 index;
    
    s32 byteOffset;
    void *dst;
    void *src;
    void *clipped;
/* Inferred frame reservation; original purpose unknown. */
char __repair_stack_padding[16];

    src = inVerts;
    index = 0;
    if (vertCount > 0) {
        byteOffset = 0;
        do {
            *(f32 *)(clip_buffer_a + byteOffset) = M2C_FIELD(src, f32 *, 0);
            index += 1;
            *(f32 *)(D_800E177C + byteOffset) = M2C_FIELD(src, f32 *, 4);
            z = M2C_FIELD(src, f32 *, 8);
            src += 0x24;
            *(f32 *)(D_800E1780 + byteOffset) = z;
            byteOffset += 0x24;
        } while (index < vertCount);
    }
    clippedCount = clip_verts_z_planes(vertCount, src);
    index = 0;
    if (clippedCount > 0) {
        dst = outVerts;
        clipped = clip_result_verts;
        do {
            M2C_FIELD(dst, f32 *, 0) = (f32) M2C_FIELD(clipped, f32 *, 0);
            index += 1;
            M2C_FIELD(dst, f32 *, 4) = (f32) M2C_FIELD(clipped, f32 *, 4);
            clippedZ = M2C_FIELD(clipped, f32 *, 8);
            clipped += 0x24;
            M2C_FIELD(dst, f32 *, 8) = clippedZ;
            dst += 0x24;
        } while (index < clippedCount);
    }
    return clippedCount;
}
