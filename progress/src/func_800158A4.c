extern u16 gSurfaceQueryStamp;
extern s32 func_8004D910;
extern f32 func_80045764(f32 *, f32 *);
extern f32 Vec3_DistanceSq(f32 *, f32 *);
extern s8 Ray_CastObjects(s32 *, void *, f32 *, f32 *, f32 *, f32, void *, s32, void *);
extern s32 findActorCapsuleHit(void *, f32 *, f32 *, s32, f32 *, s32, s32, void *);
extern void *func_80047B44(void *, f32 *, f32 *, f32 *);
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} RayVec3;
s32 func_800158A4(const RayVec3 *origin, const RayVec3 *endpoint, void *firstRoom, RayVec3 *hitPoint, s32 *hitKind, void *hitPlane, s32 actorMask, s8 includeActors, void *forcedActor)
{
  RayVec3 staticPoint;
  RayVec3 actorPoint;
  RayVec3 start;
  RayVec3 end;
  RayVec3 direction;
  RayVec3 portalPoint;
  f32 closest = 65536.0f;
  f32 distance;
  s32 kind;
  void *room = firstRoom;
  void *portal;
  kind = 0;
  gSurfaceQueryStamp++;
  start = *origin;
  end = *endpoint;
  actorPoint.x = 0.0f;
  if (room == 0)
  {
    *hitPoint = *origin;
    return 0;
  }
  do
  {
    direction.x = end.x - start.x;
    direction.y = end.y - start.y;
    direction.z = end.z - start.z;
    distance = func_80045764(&direction.x, &direction.x);
    if ((*((u16 *) (((char *) room) + 0x58))) == 0x46)
    {
      if (Ray_CastObjects(&func_8004D910, room, &start.x, &direction.x, &staticPoint.x, distance, hitPlane, includeActors, forcedActor))
      {
        closest = Vec3_DistanceSq(&start.x, &staticPoint.x);
        kind = 1;
      }
      if ((actorMask != 0) && findActorCapsuleHit(room, &start.x, &end.x, actorMask, &actorPoint.x, 0, 0, forcedActor))
      {
        if ((kind != 1) || (Vec3_DistanceSq(&start.x, &actorPoint.x) < closest))
        {
          if (kind || end.x)
          {
            kind = 2;
          }
          else
          {
            kind = 2;
          }
        }
      }
      if (kind != 0)
      {
        if (kind == 1)
        {
          *hitPoint = staticPoint;
        }
        if (kind == 2)
        {
          *hitPoint = actorPoint;
        }
        if (hitKind != 0)
        {
          *hitKind = kind;
        }
        return 0;
      }
    }
    portal = func_80047B44(room, &start.x, &end.x, &portalPoint.x);
    room = 0;
    if (portal != 0)
    {
      start = portalPoint;
      room = *((void **) (((char *) portal) + 8));
    }
  }
  while (room != 0);
  return 1;
}

