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
extern s8 D_800C42B0[14][8], D_800C42B1[14][8], D_800C42B2[14][8];
extern f32 D_800C42B4[14][2];
extern Vec D_800D3E50;
extern f64 D_800D3E60;
extern Actor *gPlayerActor;
extern s32 gGameMode, D_80108F84;

f32 Vec3_DistanceSq(Vec *, Vec *);
void segmentClosestPoint(Vec *, Vec *, Vec *, Vec *);
f32 func_80045764(Vec *, Vec *);
f32 approxDistance(Vec *, Vec *);
s32 func_80047998(void *, void *, void *, void *, void *, void *, f32, f32);

Actor *func_8004F990(Actor **list, Vec *start, Vec *end, s32 mask, Vec *result, u8 update, u8 mark, Actor *skip)
{
    Vec direction, axis, bestPoint, closest, a, b, hit, other;
    Actor *best, *actor;
    f32 bestDistance, length, scale, dx, dy, dz, radius, factor, x, y, z, axisLength, distance;
    u32 bestPart, found, part;

    bestPoint = D_800D3E50;
    direction.x = end->x - start->x;
    direction.y = end->y - start->y;
    best = NULL;
    bestDistance = 65536.0f;
    bestPart = 0;
    direction.z = end->z - start->z;
    length = func_80045764(&direction, &direction);
    D_80108F84 = 0;
    gPlayerActor = NULL;
    if (list != NULL) {
        f32 maxSquared = 4.0f;
        actor = *list;
        if (actor != NULL) {
        do {
            if (actor != skip && (actor->active & 0x400) &&
                (actor->mask & 0x400) && (actor->mask & mask)) {
                scale = 1.5f;
                if (gGameMode == 0x19 && actor->type == 1)
                    scale = 2.5f;
                segmentClosestPoint(&closest, start, end, &actor->pos);
                dx = closest.x - actor->pos.x;
                dy = closest.y - actor->pos.y;
                dz = closest.z - actor->pos.z;
                found = -1;
                if (dx * dx + dy * dy + dz * dz < maxSquared) {
                    for (part = 0; part < 14; part++) {
                        if (D_800C42B0[part][0] != -1) {
                            s32 index = D_800C42B1[part][0];
                            if (index == *(s8 *)((s32)(part * 8) + (s32)D_800C42B2))
                                a = actor->points[0][index];
                            else
                                a = actor->points[1][index];
                            b = actor->points[1][D_800C42B2[part][0]];
                            axis.x = b.x - a.x;
                            axis.y = b.y - a.y;
                            axis.z = b.z - a.z;
                            axisLength = func_80045764(&axis, &axis);
                            radius = D_800C42B4[part][0] * scale;
                            factor = (f32)((f64)radius * D_800D3E60);
                            x = axis.x * factor;
                            y = axis.y * factor;
                            axisLength -= radius;
                            z = axis.z * factor;
                            a.x += x;
                            a.y += y;
                            a.z += z;
                            b.x -= x;
                            b.y -= y;
                            b.z -= z;
                            if ((func_80047998(&hit, &other, start, &direction, &a, &axis, length, axisLength) << 24) &&
                                Vec3_DistanceSq(&hit, &other) < radius) {
                                *result = hit;
                                found = part;
                                break;
                            }
                        }
                    }
                    if (found != (u32)-1) {
                        distance = approxDistance(start, result);
                        if (distance < bestDistance) {
                            best = actor;
                            bestPart = found;
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
                    s32 id = D_800C42B0[bestPart][0];
                    WORD(extra, 0x88) = (flags & 0xFFE1FFFF) | ((id & 0xF) << 17);
                }
                type = best->type;
                if (((type == 2) | (type == 0x4D)) || type == 3) {
                    void *extra = best->extra;
                    u32 flags = WORD(extra, 0x18C);
                    s32 id = D_800C42B0[bestPart][0];
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

