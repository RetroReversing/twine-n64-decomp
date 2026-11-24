typedef struct { f32 x, y, z; } Vec3f;
typedef struct { u8 pad0[0x18]; Vec3f pos; } Obj81568;
typedef struct { u8 pad0[0x24]; Vec3f pos; } Cam81568;
typedef struct { u8 pad0[0x60]; s32 flags; u8 pad64[8]; Obj81568 *obj; } Ent81568;

extern Cam81568 *sBonusObjectTable;
s8 playTrackMarkerCue(Ent81568 *, Cam81568 *, s32);
s8 isActorFacingTarget(Ent81568 *, Vec3f *, s32 *);
void easeActorAngle(Ent81568 *, s32, f32);

/* While the actor's 0x3000 flags are set, copies the bonus object's position to the actor's object and steers toward it; returns 1 if a helper reports completion. */ s32 snapActorToBonusObject(Ent81568 *actor) {
    Obj81568 *obj;
    s32 targetIndex;

    if (actor->flags & 0x3000) {
        obj = actor->obj;
        if (playTrackMarkerCue(actor, sBonusObjectTable, 0)) {
            return 1;
        }
        obj->pos = sBonusObjectTable->pos;
        if (isActorFacingTarget(actor, &obj->pos, &targetIndex)) {
            return 1;
        }
        easeActorAngle(actor, targetIndex, 0.1f);
    }
    return 0;
}
