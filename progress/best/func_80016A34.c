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

s32 Probe_BoundsContainPoint(void *, s32);          /* extern */
s32 actorLinkToSurface(s32, void *, M2C_UNK);       /* extern */
M2C_UNK actorUnlinkFromSurface(void *);             /* extern */
void *func_80047B44(s32, void *, void *, M2C_UNK);  /* extern */
M2C_UNK markObjectsNearPos(s32, M2C_UNK, M2C_UNK, void *, s32, s32); /* extern */
M2C_UNK objectListInsert(void *, s32);              /* extern */
M2C_UNK prepareLinkedObjectPair(void *, void *, s32); /* extern */
extern s32 *gProbeObjectList;
extern u8 gTrackMarkerDone[];

typedef struct { s32 x, y, z; } ProbeVec;
typedef struct {
    u8 pad[0x20];
    s32 surface;
    ProbeVec pos, previousPos, angles, previousAngles;
    s32 pad54, flags, pad5C, state;
    u8 pad64[0x14];
    u16 type;
} SurfaceProbeActor;

#define RESTORE(a) ((a)->pos = (a)->previousPos, (a)->angles = (a)->previousAngles)
void func_80016A34(SurfaceProbeActor *actor) {
    ProbeVec *pos = &actor->pos;
    u8 *hit = func_80047B44(actor->surface, &actor->previousPos, pos, 0);
    s32 surface;
    u8 marker;
    if (hit != NULL) {
        if (*(u16 *)(hit + 0x26) & 0x1000) {
            markObjectsNearPos(actor->surface, 2, 0x20000, pos, 0, 1);
            prepareLinkedObjectPair(hit, pos, actor->surface);
        }
        if (actor->type == 2 && (hit[0x29] == 0 || gTrackMarkerDone[hit[0x29]])) {
            marker = hit[0x28];
            if (marker) gTrackMarkerDone[marker] = 1;
        }
        surface = *(s32 *)(hit + 8);
        actorUnlinkFromSurface(actor);
        objectListInsert(actor, surface);
        actor->surface = surface;
        actor->state |= 0x400;
        goto save;
    }

    surface = actor->surface;
    if (surface == 0) {
        switch (actor->type) {
        case 0x1F:
        case 0x46:
            goto relink;
        }
        goto done;
    }
    if ((s8)Probe_BoundsContainPoint(pos, surface)) goto save;
    actorUnlinkFromSurface(actor);
    switch (actor->type) {
    case 6:
    case 7:
        goto done;
    case 0x24:
        if ((s8)actorLinkToSurface(*gProbeObjectList, actor, 0)) goto save;
        RESTORE(actor);
        goto insert;
    default:
        if ((s8)actorLinkToSurface(*gProbeObjectList, actor, 0)) goto save;
        goto insert;
    case 1:
    case 0x4C:
        if (actor->flags & 0x80000) goto tryLink;
        RESTORE(actor);
        goto insert;
    case 2:
    case 3:
    case 0x4D:
    case 0x61:
        if (!(actor->flags & 0x80000)) goto restoreAndTest;
    tryLink:
        if (!(s8)actorLinkToSurface(*gProbeObjectList, actor, 0)) {
            objectListInsert(actor, surface);
        }
    save:
        actor->previousPos = actor->pos;
        actor->previousAngles = actor->angles;
        goto done;
    restoreAndTest:
        RESTORE(actor);
        if (!(s8)Probe_BoundsContainPoint(&actor->pos, surface)) goto relink;
    insert:
        objectListInsert(actor, surface);
        goto done;
    relink:
        actorLinkToSurface(*gProbeObjectList, actor, 0);
    }
done:
    actor->flags &= ~1;
}
