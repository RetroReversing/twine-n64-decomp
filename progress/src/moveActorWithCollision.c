typedef struct { f32 x,y,z; } MoveVec;
typedef struct { char pad[0x1c]; f32 low; char pad20[0x20]; f32 high; } MoveBounds;
typedef struct { char pad[0xac]; f32 height; } MoveLimit;
typedef struct { MoveBounds *bounds; MoveLimit *limit; s32 unk; u16 flags; } MoveState;
typedef struct { char pad[0x24]; MoveVec pos; char direction[0x38]; MoveState *state; } MoveActor;
s8 sweepSphereAgainstSurfaces(MoveActor *, void *, void *, MoveVec *, void *, f32, f32, f32, s32, s32 *, s32 *, s32 *);

/* Moves the actor through the collision routine, using its bounds and height to find the floor and ceiling; the new position is stored only if the move succeeds. Returns the collision result. */
s32 moveActorWithCollision(void *arg0, MoveActor *actor, s32 *arg2, s32 *arg3, s32 arg4)
{
    MoveVec pos;
    f32 scratch[4];
    s32 result;
    MoveState *state;
    f32 y, bottom, top;
    pos = actor->pos;
    result = 0;
    *arg2 = 0;
    *arg3 = 0;
    state = actor->state;
    y = actor->pos.y;
    top = state->limit->height - y;
    bottom = y - (state->bounds->low + state->bounds->high) * 0.5f;
    state->flags &= ~0x30;
    if (sweepSphereAgainstSurfaces(actor, arg0, actor->direction, &pos, scratch, 0.55f, bottom, top, arg4, arg2, &result, arg3)) {
        actor->state->flags |= 0x10;
        actor->pos = pos;
    }
    return result;
}
