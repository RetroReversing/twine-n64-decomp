typedef struct { f32 x, y, z; } Vec;
typedef struct Actor Actor;
struct Actor {
    Actor *next;
    u8 pad04[0x20];
    Vec pos;
    u8 pad30[0x28];
    u32 active, mask, state;
    u8 pad64[4];
    Vec **points;
    void *extra;
    u8 pad70[8];
    u16 type;
};
#define WORD(p, o) (*(u32 *)((u8 *)(p) + (o)))
extern s8 sCapsulePartId[14][8], sCapsulePointA[14][8], sCapsulePointB[14][8];
extern f32 sCapsuleRadius[14][2];
extern Vec sZeroVec;
extern f64 gCapsuleEndInsetScale;
extern Actor *gPlayerActor;
extern s32 gGameMode, D_80108F84;

f32 Vec3_DistanceSq(Vec *, Vec *);
void segmentClosestPoint(Vec *, Vec *, Vec *, Vec *);
f32 func_80045764(Vec *, Vec *);
f32 approxDistance(Vec *, Vec *);
s32 testRayCapsulePart(void *, void *, void *, void *, void *, void *, f32, f32);

/* Tests segment start..end against actors' capsule parts in list, returns the nearest actor hit (or NULL) and writes the hit point to result. */
Actor *findActorCapsuleHit(Actor **list, Vec *start, Vec *end, s32 mask, Vec *result, u8 update, u8 mark, Actor *skip)
{
    Vec rayDir, partAxis, bestPoint, closestPoint, partStart, partEnd, hitPoint, otherPoint;
    Actor *best, *actor;
    f32 bestDistance, rayLength, sizeScale, dx, dy, dz, partRadius, endInset, insetX, insetY, insetZ, partLength, distance;
    u32 bestPart, hitPart, part;

    bestPoint = sZeroVec;
    rayDir.x = end->x - start->x;
    rayDir.y = end->y - start->y;
    best = NULL;
    bestDistance = 65536.0f;
    bestPart = 0;
    rayDir.z = end->z - start->z;
    rayLength = func_80045764(&rayDir, &rayDir);
    D_80108F84 = 0;
    gPlayerActor = NULL;
    if (list != NULL) {
        f32 maxSquared = 4.0f;
        actor = *list;
        if (actor != NULL) {
        do {
            if (actor != skip && (actor->active & 0x400) &&
                (actor->mask & 0x400) && (actor->mask & mask)) {
                sizeScale = 1.5f;
                if (gGameMode == 0x19 && actor->type == 1)
                    sizeScale = 2.5f;
                segmentClosestPoint(&closestPoint, start, end, &actor->pos);
                dx = closestPoint.x - actor->pos.x;
                dy = closestPoint.y - actor->pos.y;
                dz = closestPoint.z - actor->pos.z;
                hitPart = -1;
                if (dx * dx + dy * dy + dz * dz < maxSquared) {
                    for (part = 0; part < 14; part++) {
                        if (sCapsulePartId[part][0] != -1) {
                            s32 index = sCapsulePointA[part][0];
                            if (index == *(s8 *)((s32)(part * 8) + (s32)sCapsulePointB))
                                partStart = actor->points[0][index];
                            else
                                partStart = actor->points[1][index];
                            partEnd = actor->points[1][sCapsulePointB[part][0]];
                            partAxis.x = partEnd.x - partStart.x;
                            partAxis.y = partEnd.y - partStart.y;
                            partAxis.z = partEnd.z - partStart.z;
                            partLength = func_80045764(&partAxis, &partAxis);
                            partRadius = sCapsuleRadius[part][0] * sizeScale;
                            endInset = (f32)((f64)partRadius * gCapsuleEndInsetScale);
                            insetX = partAxis.x * endInset;
                            insetY = partAxis.y * endInset;
                            partLength -= partRadius;
                            insetZ = partAxis.z * endInset;
                            partStart.x += insetX;
                            partStart.y += insetY;
                            partStart.z += insetZ;
                            partEnd.x -= insetX;
                            partEnd.y -= insetY;
                            partEnd.z -= insetZ;
                            if ((testRayCapsulePart(&hitPoint, &otherPoint, start, &rayDir, &partStart, &partAxis, rayLength, partLength) << 24) &&
                                Vec3_DistanceSq(&hitPoint, &otherPoint) < partRadius) {
                                *result = hitPoint;
                                hitPart = part;
                                break;
                            }
                        }
                    }
                    if (hitPart != (u32)-1) {
                        distance = approxDistance(start, result);
                        if (distance < bestDistance) {
                            best = actor;
                            bestPart = hitPart;
                            bestPoint = *result;
                            bestDistance = distance;
                        }
                    } else if ((update != 0) & (mark != 0)) {
                        actor->state |= 4;
                    }
                }
            }
            actor = actor->next;
        } while (actor != NULL);
        }
    }
    if (best != NULL) {
        {
            u16 type;
            gPlayerActor = best;
            *result = bestPoint;
            if (update != 0) {
                type = best->type;
                if ((type == 1) | (type == 0x4C)) {
                    void *extra = best->extra;
                    u32 flags = WORD(extra, 0x88);
                    s32 id = sCapsulePartId[bestPart][0];
                    WORD(extra, 0x88) = (flags & 0xFFE1FFFF) | ((id & 0xF) << 17);
                }
                type = best->type;
                if (((type == 2) | (type == 0x4D)) || type == 3) {
                    void *extra = best->extra;
                    u32 flags = WORD(extra, 0x18C);
                    s32 id = sCapsulePartId[bestPart][0];
                    WORD(extra, 4) = mask;
                    WORD(extra, 0x18C) = (flags & 0xFFFF0FFF) |
                        ((id & 0xF) << 12);
                }
            }
        }
        return best;
    }
    return NULL;
}
