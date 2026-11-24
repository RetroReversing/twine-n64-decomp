typedef struct { f32 x, y, z; } Vec3_60968;
typedef struct { s32 pad0; Vec3_60968 v[2]; s32 pad1C[3]; s32 f28; s32 f2C; s32 f30; f32 f34; } Sub60968;
typedef struct { u8 pad0[0x20]; s32 f20; Vec3_60968 pos; u8 pad30[0x28]; s32 f58; u8 pad5C[0x10]; Sub60968 *sub; u8 pad70[8]; s16 f78; s16 f7A; } Obj60968;
s32 actorUnlinkFromSurface(Obj60968 *);
s32 actorLinkToSurface(s32, Obj60968 *, s32);
s32 randomU32Next(void);
s32 func_80048F10(s32, Vec3_60968 *, Vec3_60968 *, Vec3_60968 *, f32, s32, s32, s32);
s32 objectUpdateAnimByState(Obj60968 *);
s32 clearObjectStateBits(Obj60968 *);
f32 absFloat(f32);
extern s32 *gDefaultOrderObj;

/* Moves an actor to one of two random spawn points, re-seats it on the surface and resets its state. */
void actorRespawnAtRandomPoint(Obj60968 *actor) {
    Sub60968 *spawnTable = actor->sub;
    Sub60968 *spawnPoint;
    Vec3_60968 surfacePos;
    Vec3_60968 probeOut;

    spawnPoint = (Sub60968 *)((randomU32Next() & 1) * 0xC + (s32)spawnTable);
    actor->pos = spawnPoint->v[0];
    surfacePos = spawnPoint->v[0];
    actorUnlinkFromSurface(actor);
    actorLinkToSurface(*gDefaultOrderObj, actor, 1);
    func_80048F10(actor->f20, &actor->pos, &surfacePos, &probeOut, 250.0f, 0, 0, 0);
    spawnTable->f34 = surfacePos.y;
    if (absFloat(surfacePos.y - actor->pos.y) > 1.0f) {
        actor->f7A = 0;
        actor->f78 = 0x28;
        actor->f58 |= 1;
        objectUpdateAnimByState(actor);
    } else {
        actor->f7A = 0;
        actor->f78 = 0x55;
        objectUpdateAnimByState(actor);
    }
    clearObjectStateBits(actor);
    spawnTable->f28 = 0;
    spawnTable->f2C = 0;
    spawnTable->f30 = 0;
}
