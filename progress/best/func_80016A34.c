typedef struct { s32 x,y,z; } ProbeVec;
typedef struct {
    char pad[0x20];
    s32 surface;
    ProbeVec pos, oldPos, angles, oldAngles;
    char pad54[4];
    u32 flags;
    char pad5c[4];
    u32 state;
    char pad64[0x14];
    u16 type;
} SurfaceUpdateActor;
typedef struct {
    char pad[8];
    s32 surface;
    char pad0c[0x1a];
    u16 flags;
    u8 marker, prerequisite;
} ProbeHit;
extern ProbeHit *func_80047B44(s32, ProbeVec *, ProbeVec *, s32);
extern s32 Probe_BoundsContainPoint(ProbeVec *, s32);
extern s32 actorLinkToSurface(s32, SurfaceUpdateActor *, s32);
extern void actorUnlinkFromSurface(SurfaceUpdateActor *);
extern void objectListInsert(SurfaceUpdateActor *, s32);
extern void markObjectsNearPos(s32, s32, s32, ProbeVec *, s32, s32);
extern void func_80073304(ProbeHit *, ProbeVec *, s32);
extern s32 *gProbeObjectList;
extern u8 gTrackMarkerDone[];

void func_80016A34(SurfaceUpdateActor *actor) {
    union { ProbeHit *hit; s32 surface; } collision;
    u8 marker;
    ProbeVec *pos = &actor->pos;
    collision.hit = func_80047B44(actor->surface, &actor->oldPos, pos, 0);
    if (collision.hit) {
        if (collision.hit->flags & 0x1000) {
            markObjectsNearPos(actor->surface, 2, 0x20000, pos, 0, 1);
            func_80073304(collision.hit, pos, actor->surface);
        }
        if (actor->type == 2 &&
            ((marker = collision.hit->prerequisite) == 0 || gTrackMarkerDone[marker])) {
            marker = collision.hit->marker;
            if (marker) {
                gTrackMarkerDone[marker] = 1;
            }
        }
        collision.surface = collision.hit->surface;
        actorUnlinkFromSurface(actor);
        objectListInsert(actor, collision.surface);
        actor->surface = collision.surface;
        actor->state |= 0x400;
        goto save;
    }

    collision.surface = actor->surface;
    if (collision.surface == 0) {
        u16 type = actor->type;
        if (type == 0x1F) goto link;
        if (type == 0x46) goto link;
        goto done;
    }
    if (((u32)Probe_BoundsContainPoint(pos, collision.surface) << 24)) {
        goto save;
    }
    actorUnlinkFromSurface(actor);
    switch (actor->type) {
    case 0x24:
        if (((u32)actorLinkToSurface(*gProbeObjectList, actor, 0) << 24)) {
            goto save;
        }
        actor->pos = actor->oldPos;
        actor->angles = actor->oldAngles;
        goto insert;
    default:
        if (((u32)actorLinkToSurface(*gProbeObjectList, actor, 0) << 24)) {
            goto save;
        }
        goto insert;
    case 1:
    case 0x4C:
        if (actor->flags & 0x80000) {
            goto relink;
        }
        actor->pos = actor->oldPos;
        actor->angles = actor->oldAngles;
        goto insert;
    case 2:
    case 3:
    case 0x4D:
    case 0x61:
        if (!(actor->flags & 0x80000)) {
            goto restore;
        }
relink:
        if (!((u32)actorLinkToSurface(*gProbeObjectList, actor, 0) << 24)) {
            objectListInsert(actor, collision.surface);
        }
save:
        actor->oldPos = actor->pos;
        actor->oldAngles = actor->angles;
        break;
restore:
        actor->pos = actor->oldPos;
        actor->angles = actor->oldAngles;
        if (((u32)Probe_BoundsContainPoint(&actor->pos, collision.surface) << 24)) {
insert:
            objectListInsert(actor, collision.surface);
            break;
        }
link:
        actorLinkToSurface(*gProbeObjectList, actor, 0);
        break;
    case 6:
    case 7:
        break;
    }
done:
    actor->flags &= ~1;
}
