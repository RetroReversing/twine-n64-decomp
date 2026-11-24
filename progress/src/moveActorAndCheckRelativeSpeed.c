typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} Vec3f;
typedef struct 
{
  u8 pad0[0x1C];
  f32 minY;
  u8 pad20[0x20];
  f32 maxY;
} CollisionBounds;
typedef struct 
{
  u8 pad0[0xAC];
  f32 topY;
} CollisionLimit;
typedef struct 
{
  CollisionBounds *bounds;
  CollisionLimit *limit;
  u8 pad8[4];
  u16 flags;
} CollisionState;
typedef struct 
{
  u8 pad0[0x24];
  Vec3f position;
  Vec3f previous;
  u8 pad3C[0x2C];
  CollisionState *collision;
  u8 pad6C[8];
  f32 correction;
} MovingActor;
extern MovingActor *gReferenceActor;
extern s8 sweepActorCollision(MovingActor *, s32, Vec3f *, Vec3f *, Vec3f *, f32, f32, f32, s32, s32 *, s32 *, s32 *);
extern void vec3Subtract(void *, void *, void *);
extern f32 vec3Length(const void *);
/* Sweeps the actor's position through collision, snaps it to the hit, and flags it if its motion differs sharply from the reference actor's. */ s32 moveActorAndCheckRelativeSpeed(s32 mode, MovingActor *actor, s32 *outHitA, s32 *outHitB, s32 sweepFlags)
{
  Vec3f next;
  Vec3f hitPoint;
  volatile s32 hitResult;
  Vec3f delta;
  Vec3f otherDelta;
  Vec3f difference;
  CollisionState *collision;
  CollisionBounds *bounds;
  f32 y;
  if (mode)
  {
    next = actor->position;
    hitResult = 0;
  }
  else
  {
    next = actor->position;
    hitResult = 0;
  }
  if (1)
  {
    do {*outHitA = 0;}while(0);
    *outHitB = 0;
    collision = actor->collision;
    y = actor->position.y;
    bounds = collision->bounds;
    {
      f32 upper = collision->limit->topY;
      f32 lower = bounds->minY + bounds->maxY;
      collision->flags &= ~0x30;
      if (sweepActorCollision(actor, mode, &actor->previous, &next, &hitPoint, 0.55f, y - (lower * 0.5f), upper - y, sweepFlags, outHitA, &hitResult, outHitB))
      {
        actor->collision->flags |= 0x10;
        actor->position.x = next.x;
        if (next.y < actor->position.y)
        {
          actor->position.y = next.y;
        }
        actor->position.z = next.z;
      }
    }
    if (gReferenceActor != NULL)
    {
      delta.x = actor->position.x - actor->previous.x;
      delta.y = actor->position.y - actor->previous.y;
      delta.z = actor->position.z - actor->previous.z;
      otherDelta.x = gReferenceActor->position.x - gReferenceActor->previous.x;
      otherDelta.y = gReferenceActor->position.y - gReferenceActor->previous.y;
      otherDelta.z = gReferenceActor->position.z - gReferenceActor->previous.z;
      vec3Subtract(&delta, &otherDelta, &difference);
      if (vec3Length(&difference) > 2.0f)
      {
        actor->correction = -1.0f;
      }
    }
    return hitResult;
  }
}


