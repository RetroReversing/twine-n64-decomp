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

s32 boundsContainPoint(void *, s32);          /* extern */
s32 actorLinkToSurface(s32, void *, M2C_UNK);       /* extern */
M2C_UNK actorUnlinkFromSurface(void *);             /* extern */
void *raycastObjectMesh(s32, void *, void *, M2C_UNK);  /* extern */
M2C_UNK markObjectsNearPos(s32, M2C_UNK, M2C_UNK, void *, s32, s32); /* extern */
M2C_UNK objectListInsert(void *, s32);              /* extern */
M2C_UNK prepareLinkedObjectPair(void *, void *, s32); /* extern */
extern s32 *gDefaultOrderObj;
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
/* Re-links an actor to the surface it now stands on after moving; if it left its surface it tries to find a new one, or reverts to its previous position depending on actor type. */ void updateActorSurfaceLink(SurfaceProbeActor *actor) {
    ProbeVec *pos = &actor->pos;
    register u8 *hitSurface = raycastObjectMesh(actor->surface, &actor->previousPos, pos, 0);
    s32 previousSurface;
    u8 marker;
    if (hitSurface != NULL) {
        s32 newSurface;
        if (*(u16 *)(hitSurface + 0x26) & 0x1000) {
            markObjectsNearPos(actor->surface, 2, 0x20000, pos, 0, 1);
            prepareLinkedObjectPair(hitSurface, pos, actor->surface);
        }
        if (actor->type == 2 && (hitSurface[0x29] == 0 || gTrackMarkerDone[hitSurface[0x29]])) {
            marker = hitSurface[0x28];
            if (marker) gTrackMarkerDone[marker] = 1;
        }
        newSurface = *(s32 *)(hitSurface + 8);
        actorUnlinkFromSurface(actor);
        objectListInsert(actor, newSurface);
        actor->surface = newSurface;
        actor->state |= 0x400;
        goto save;
    }

    previousSurface = actor->surface;
    if (previousSurface == 0) {
        switch (actor->type) {
        case 0x1F:
        case 0x46:
            goto relink;
        }
        goto done;
    }
    if ((s8)boundsContainPoint(pos, previousSurface)) goto save;
    actorUnlinkFromSurface(actor);
    switch (actor->type) {
    case 6:
    case 7:
        goto done;
    case 0x24:
        if ((s8)actorLinkToSurface(*gDefaultOrderObj, actor, 0)) goto save;
        {
            volatile ProbeVec *p = &actor->previousPos;
            volatile ProbeVec *a = &actor->previousAngles;
            s32 x = p->x, y = p->y, z = p->z;
            ((volatile SurfaceProbeActor *)actor)->pos.x = x;
            ((volatile SurfaceProbeActor *)actor)->pos.y = y;
            ((volatile SurfaceProbeActor *)actor)->pos.z = z;
            x = a->x;
            y = a->y;
            z = a->z;
            ((volatile SurfaceProbeActor *)actor)->angles.x = x;
            ((volatile SurfaceProbeActor *)actor)->angles.y = y;
            ((volatile SurfaceProbeActor *)actor)->angles.z = z;
        }
        goto insert;
    default:
        if ((s8)actorLinkToSurface(*gDefaultOrderObj, actor, 0)) goto save;
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
        if (!(s8)actorLinkToSurface(*gDefaultOrderObj, actor, 0)) {
            objectListInsert(actor, previousSurface);
        }
    save:
        actor->previousPos = actor->pos;
        actor->previousAngles = actor->angles;
        goto done;
    restoreAndTest:
        RESTORE(actor);
        if (!(s8)boundsContainPoint(&actor->pos, previousSurface)) goto relink;
    insert:
        objectListInsert(actor, previousSurface);
        goto done;
    relink:
        actorLinkToSurface(*gDefaultOrderObj, actor, 0);
    }
done:
    actor->flags &= ~1;
}

