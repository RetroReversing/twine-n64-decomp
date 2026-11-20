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
extern s32 func_8004DBD8(void *, void *, void *, void *, void *, f32 *);
extern s32 func_8004E6E4(ProbeTest, ProbeObject *, ProbeVector *, ProbeVector *, void *, f32, s32, s32, s32);
extern ProbeObject **D_800CA31C;
extern ProbeVector D_800D2FB0, D_800D2FBC;

ProbeObject *func_8003D848(ProbeVector *position)
{
    ProbeVector direction1, direction2;
    u8 hit[16];
    ProbeObject *fallback;
    ProbeObject *object;
    ProbeObject *closest;
    f32 closestDistance;
    ProbeObject *result;

    closest = NULL;
    object = *D_800CA31C;
    closestDistance = 65536.0f;
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
                    if (object->distance < closestDistance &&
                        (((u32)func_8004E6E4(func_8004DBD8, fallback, position, &direction1, hit, 256.0f, 0, 1, 0) << 24) ||
                         ((u32)func_8004E6E4(func_8004DBD8, fallback, position, &direction2, hit, 256.0f, 0, 1, 0) << 24))) {
                        closest = fallback;
                        closestDistance = fallback->distance;
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
