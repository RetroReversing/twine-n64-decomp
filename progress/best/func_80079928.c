typedef struct { f32 x, y, z; } Vec3f;

typedef struct {
    u8 pad0[0x1C];
    f32 minY;
    u8 pad20[0x20];
    f32 maxY;
} CollisionBounds;

typedef struct {
    u8 pad0[0xAC];
    f32 topY;
} CollisionLimit;

typedef struct {
    CollisionBounds *bounds;
    CollisionLimit *limit;
    u8 pad8[4];
    u16 flags;
} CollisionState;

typedef struct {
    u8 pad0[0x24];
    Vec3f position;
    Vec3f previous;
    u8 pad3C[0x2C];
    CollisionState *collision;
    u8 pad6C[8];
    f32 correction;
} MovingActor;

extern MovingActor *D_80108404;
extern s8 func_80053940(MovingActor *, s32, Vec3f *, Vec3f *, Vec3f *, f32, f32, f32, s32, s32 *, s32 *, s32 *);
extern void func_800452E0(void *, void *, void *);
extern f32 func_8004572C(const void *);

s32 func_80079928(s32 arg0, MovingActor *actor, s32 *arg2, s32 *arg3, s32 arg4)
{
    Vec3f next;
    Vec3f scratch;
    volatile s32 result;
    Vec3f delta;
    Vec3f otherDelta;
    Vec3f difference;
    CollisionState *collision;
    CollisionBounds *bounds;
    f32 y;

    next = actor->position;
    result = 0;
    *arg2 = 0;
    *arg3 = 0;
    collision = actor->collision;
    y = actor->position.y;
    bounds = collision->bounds;
    { f32 upper = collision->limit->topY;
    f32 lower = bounds->minY + bounds->maxY;
    collision->flags &= ~0x30;
    if (func_80053940(actor, arg0, &actor->previous, &next, &scratch, 0.55f,
                     y - lower * 0.5f, upper - y, arg4, arg2, &result, arg3)) {
        actor->collision->flags |= 0x10;
        actor->position.x = next.x;
        if (next.y < actor->position.y) {
            actor->position.y = next.y;
        }
        actor->position.z = next.z;
    }

    }
    if (D_80108404 != NULL) {
        delta.x = actor->position.x - actor->previous.x;
        delta.y = actor->position.y - actor->previous.y;
        delta.z = actor->position.z - actor->previous.z;
        otherDelta.x = D_80108404->position.x - D_80108404->previous.x;
        otherDelta.y = D_80108404->position.y - D_80108404->previous.y;
        otherDelta.z = D_80108404->position.z - D_80108404->previous.z;
        func_800452E0(&delta, &otherDelta, &difference);
        if (func_8004572C(&difference) > 2.0f) {
            actor->correction = -1.0f;
        }
    }
    return result;
}
