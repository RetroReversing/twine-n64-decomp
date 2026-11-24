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
extern s32 rayTriangleIntersect(void *, void *, void *, void *, void *, f32 *);
extern s32 castRayAgainstObjectsAndRooms(ProbeTest, ProbeObject *, ProbeVector *, ProbeVector *, void *, f32, s32, s32, s32);
extern ProbeObject **gDefaultOrderObj;
extern ProbeVector gProbeDirDown, gProbeDirAlt;

/* Finds the nearest type-0x46 object whose bounds contain the position and that a downward or alternate ray hits; returns it, or the last candidate checked if none is closer. */
ProbeObject *probeFindNearestObject(ProbeVector *position)
{
    ProbeVector dirDown, dirAlt;
    u8 hitInfo[16];
    ProbeObject *lastCandidate;
    ProbeObject *candidate;
    ProbeObject *nearest;
    f32 nearestDist;
    ProbeObject *result;

    nearest = NULL;
    candidate = *gDefaultOrderObj;
    nearestDist = 65536.0f;
    lastCandidate = NULL;

    if (candidate != NULL) {
        do {
            if (candidate->type == 0x46) {
                f32 x = position->x;
                ProbeBounds *bounds = candidate->bounds;
                if (bounds->minX <= x) {
                    f32 y = position->y;
                    if (bounds->minY <= y) {
                        f32 z = position->z;
                        if (bounds->minZ <= z && x <= bounds->maxX &&
                            y <= bounds->maxY && z <= bounds->maxZ) {
                    dirDown = gProbeDirDown;
                    dirAlt = gProbeDirAlt;
                    lastCandidate = candidate;
                    if (candidate->distance < nearestDist &&
                        (((u32)castRayAgainstObjectsAndRooms(rayTriangleIntersect, lastCandidate, position, &dirDown, hitInfo, 256.0f, 0, 1, 0) << 24) ||
                         ((u32)castRayAgainstObjectsAndRooms(rayTriangleIntersect, lastCandidate, position, &dirAlt, hitInfo, 256.0f, 0, 1, 0) << 24))) {
                        nearest = lastCandidate;
                        nearestDist = lastCandidate->distance;
                    }
                        }
                    }
                }
            }
            candidate = candidate->next;
        } while (candidate != NULL);
    }
    if (nearest != NULL) {
        return nearest;
    }
    return lastCandidate;
}
