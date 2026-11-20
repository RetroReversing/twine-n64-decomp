/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

f32 absFloat(f32);
f32 func_80082908(f32);

/* Computes the min/max bounds of a vertex array and a bounding-sphere radius from its largest extent. */ void computeVertexBounds(s32 vertexCount, void *verts, void *sphere, void *bounds) {
    f32 x;
    f32 y;
    f32 z;
    f32 minX;
    f32 maxX;
    f32 absMaxZ;
    f32 minY;
    f32 absMaxY;
    f32 maxY;
    f32 absMaxX;
    f32 maxZ;
    f32 minZ;
    void *end;
    void *cursor;

    cursor = verts;
    if (sphere != NULL) {
        maxX = M2C_FIELD(cursor, f32 *, 0);
        maxY = M2C_FIELD(cursor, f32 *, 4);
        maxZ = M2C_FIELD(cursor, f32 *, 8);
        minX = maxX;
        minY = maxY;
        minZ = maxZ;
        if (vertexCount != 0) {
            end = (void *) (((vertexCount * 0xC)) + (s32) cursor);
            do {
                x = M2C_FIELD(cursor, f32 *, 0);
                if (x < minX) {
                    minX = x;
                } else if (maxX < x) {
                    maxX = x;
                }
                y = M2C_FIELD(cursor, f32 *, 4);
                if (y < minY) {
                    minY = y;
                } else if (maxY < y) {
                    maxY = y;
                }
                z = M2C_FIELD(cursor, f32 *, 8);
                if (z < minZ) {
                    minZ = z;
                } else if (maxZ < z) {
                    maxZ = z;
                }
                cursor += 0xC;
            } while ((u32) cursor < (u32) end);
        }
        M2C_FIELD(bounds, f32 *, 4) = maxX;
        M2C_FIELD(bounds, f32 *, 0xC) = maxY;
        M2C_FIELD(bounds, f32 *, 0x14) = maxZ;
        M2C_FIELD(bounds, f32 *, 0) = minX;
        M2C_FIELD(bounds, f32 *, 8) = minY;
        M2C_FIELD(bounds, f32 *, 0x10) = minZ;
        absMaxX = absFloat(minX);
        if (absMaxX < absFloat(maxX)) {
            absMaxX = maxX;
        }
        absMaxY = absFloat(minY);
        if (absMaxY < absFloat(maxY)) {
            absMaxY = maxY;
        }
        absMaxZ = absFloat(minZ);
        if (absMaxZ < absFloat(maxZ)) {
            absMaxZ = maxZ;
        }
        M2C_FIELD(sphere, f32 *, 0xC) = func_80082908((absMaxX * absMaxX) + (absMaxY * absMaxY) + (absMaxZ * absMaxZ));
        M2C_FIELD(sphere, s32 *, 0) = 0;
        M2C_FIELD(sphere, s32 *, 4) = 0;
        M2C_FIELD(sphere, s32 *, 8) = 0;
    }
}
