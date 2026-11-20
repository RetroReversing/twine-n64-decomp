typedef struct { f32 x, y, z; } ProbeVector;
typedef struct {
    u8 pad[0x18];
    f32 minX, maxX, minY, maxY, minZ, maxZ;
} ProbeBounds;
typedef struct ProbeObject {
    u8 pad0[0x10];
    struct ProbeObject *next;
    u8 pad14[0x28];
    ProbeBounds *bounds;
    u8 pad40[0xC];
    f32 distance;
    u8 pad50[8];
    u16 type;
} ProbeObject;

typedef s32 (*ProbeTest)(void *, void *, void *, void *, void *, f32 *);
extern s32 Ray_TriangleIntersect(void *, void *, void *, void *, void *, f32 *);
extern s32 Ray_CastObjects(ProbeTest, ProbeObject *, ProbeVector *, ProbeVector *, void *, f32, s32, s32, s32);
extern ProbeObject **D_800CA31C;
extern ProbeVector D_800D2FB0, D_800D2FBC;

/* Finds the nearest type-0x46 object whose bounds contain the position and that a downward or alternate ray hits; returns it, or the last candidate checked if none is closer. */ ProbeObject *func_8003D848(ProbeVector *position)
{
    ProbeVector direction1, direction2;
    u8 hitBuf[16];
    ProbeObject *fallback;
    ProbeObject *object;
    ProbeObject *closest;
    f32 closestDist;
    ProbeObject *result;

    closest = NULL;
    object = *D_800CA31C;
    closestDist = 65536.0f;
    fallback = NULL;

    if (object != NULL) {
        do {
            if (object->type == 0x46) {
                f32 x = position->x;
                ProbeBounds *bounds = object->bounds;
                if (bounds->minX <= x) {
                    f32 y = position->y;
                    if (bounds->minY <= y) {
                        f32 z = position->z;
                        if (bounds->minZ <= z && x <= bounds->maxX &&
                            y <= bounds->maxY && z <= bounds->maxZ) {
                    direction1 = D_800D2FB0;
                    direction2 = D_800D2FBC;
                    fallback = object;
                    if (object->distance < closestDist &&
                        (((u32)Ray_CastObjects(Ray_TriangleIntersect, fallback, position, &direction1, hitBuf, 256.0f, 0, 1, 0) << 24) ||
                         ((u32)Ray_CastObjects(Ray_TriangleIntersect, fallback, position, &direction2, hitBuf, 256.0f, 0, 1, 0) << 24))) {
                        closest = fallback;
                        closestDist = fallback->distance;
                    }
                        }
                    }
                }
            }
            object = object->next;
        } while (object != NULL);
    }
    if (closest != NULL) {
        return closest;
    }
    return fallback;
}
