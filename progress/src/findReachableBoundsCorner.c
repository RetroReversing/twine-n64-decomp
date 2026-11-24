s32 castRayAgainstObjectsAndRooms(s32 *, s32, f32 *, f32 *, s32, f32, s32, s32, s32);
s32 setActorCommandState(void *, s32);
s32 isPointInsideBoundsXZ(f32 *, void *);
f32 vec3NormalizeLength(f32 *, f32 *);
f32 approxDistanceXZ(f32 *, f32 *);
void func_80047E4C(void *, void *, void *);
s32 raycastObjectParts(void *, void *, void *, f32);
s32 setActorAnimation(void *, s32);
s32 resetActorActionState(void *);
void rotateVec3InPlaceByMat3(void *, void *);
extern void *gSweepHitObject;
extern s32 rayTriangleIntersect;
typedef struct 
{
  f32 coord[3];
} RoutePoint;
/* Builds the target object's padded bounding-box corners and picks one the actor can reach with line of sight to the goal, storing it as the route waypoint. */ s32 findReachableBoundsCorner(void *actor, f32 *goalPos, s32 successArg, s32 fallbackArg)
{
  struct 
  {
    RoutePoint dir;
    u32 padDir;
    RoutePoint local;
    u32 padLocal;
    u32 transform[10];
    u32 inverse[10];
  } frame;
  RoutePoint corners[8];
  f32 *temp_s4;
  f32 *var_s0;
  f32 *var_s0_2;
  f32 dist;
  f32 temp_fv0_11;
  f32 temp_fv0_12;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f32 temp_fv0_4;
  f32 temp_fv0_5;
  f32 temp_fv0_6;
  f32 temp_fv0_7;
  f32 bestFallbackDist;
  f32 bestPathDist;
  s32 temp_a1;
  s32 temp_a1_2;
  s32 temp_a2;
  s32 temp_a2_2;
  s32 world;
  s32 var_a1;
  s32 var_s1;
  s32 cornerIndex;
  s32 bestCorner;
  s32 bestFallbackCorner;
  s32 var_v0;
  void *temp_a2_3;
  void *route;
  void *temp_v0;
  void *temp_v0_2;
  route = *((void **) (((char *) actor) + 0x6C));
  world = *((s32 *) (((char *) actor) + 0x20));
  frame.dir.coord[0] = (*((f32 *) (((char *) goalPos) + 0))) - (*((f32 *) (((char *) actor) + 0x24)));
  frame.dir.coord[1] = (*((f32 *) (((char *) goalPos) + 4))) - (*((f32 *) (((char *) actor) + 0x28)));
  frame.dir.coord[2] = (*((f32 *) (((char *) goalPos) + 8))) - (*((f32 *) (((char *) actor) + 0x2C)));
  dist = vec3NormalizeLength(&frame.dir.coord[0], &frame.dir.coord[0]);
  var_v0 = 0;
  if (!(dist < 0.01f))
  {
    if ((raycastObjectParts((void *) world, actor + 0x24, &frame.dir.coord[0], dist) << 0x18) != 0)
    {
      temp_fv0_2 = (*((f32 *) (((char *) (*((void **) (((char *) gSweepHitObject) + 0x3C)))) + 0x18))) - 0.55f;
      corners[7].coord[0] = temp_fv0_2;
      corners[4].coord[0] = temp_fv0_2;
      corners[3].coord[0] = temp_fv0_2;
      corners[0].coord[0] = temp_fv0_2;
      temp_fv0_3 = (*((f32 *) (((char *) (*((void **) (((char *) gSweepHitObject) + 0x3C)))) + 0x1C))) + 0.55f;
      corners[6].coord[0] = temp_fv0_3;
      corners[5].coord[0] = temp_fv0_3;
      corners[2].coord[0] = temp_fv0_3;
      corners[1].coord[0] = temp_fv0_3;
      temp_fv0_4 = (*((f32 *) (((char *) (*((void **) (((char *) gSweepHitObject) + 0x3C)))) + 0x20))) - 0.55f;
      corners[5].coord[1] = temp_fv0_4;
      corners[4].coord[1] = temp_fv0_4;
      corners[1].coord[1] = temp_fv0_4;
      corners[0].coord[1] = temp_fv0_4;
      temp_fv0_5 = (*((f32 *) (((char *) (*((void **) (((char *) gSweepHitObject) + 0x3C)))) + 0x24))) + 0.55f;
      corners[7].coord[1] = temp_fv0_5;
      corners[6].coord[1] = temp_fv0_5;
      corners[3].coord[1] = temp_fv0_5;
      corners[2].coord[1] = temp_fv0_5;
      temp_fv0_6 = (*((f32 *) (((char *) (*((void **) (((char *) gSweepHitObject) + 0x3C)))) + 0x28))) - 0.55f;
      corners[3].coord[2] = temp_fv0_6;
      corners[2].coord[2] = temp_fv0_6;
      corners[1].coord[2] = temp_fv0_6;
      corners[0].coord[2] = temp_fv0_6;
      temp_fv0_7 = (*((f32 *) (((char *) (*((void **) (((char *) gSweepHitObject) + 0x3C)))) + 0x2C))) + 0.55f;
      corners[7].coord[2] = temp_fv0_7;
      corners[6].coord[2] = temp_fv0_7;
      corners[5].coord[2] = temp_fv0_7;
      corners[4].coord[2] = temp_fv0_7;
      func_80047E4C(gSweepHitObject, frame.transform, frame.inverse);
      frame.local = *((RoutePoint *) goalPos);
      frame.local.coord[0] -= *((f32 *) (((char *) gSweepHitObject) + 0x24));
      frame.local.coord[1] -= *((f32 *) (((char *) gSweepHitObject) + 0x28));
      bestFallbackDist = 65536.0f;
      frame.local.coord[2] -= *((f32 *) (((char *) gSweepHitObject) + 0x2C));
      rotateVec3InPlaceByMat3(frame.inverse, &frame.local.coord[0]);
      bestPathDist = bestFallbackDist;
      if (((isPointInsideBoundsXZ(&frame.local.coord[0], gSweepHitObject) << 0x18) == 0) || (fallbackArg == 0))
      {
        var_s1 = 0;
        var_s0 = &corners[0].coord[0];
        __repair_rows:
        {
          rotateVec3InPlaceByMat3(frame.transform, var_s0);
          {
            void *object = gSweepHitObject;
            f32 x = var_s0[0] + (*((f32 *) (((char *) object) + 0x24)));
            f32 z = var_s0[2];
            var_s0[0] = x;
            var_s0[1] = *((f32 *) (((char *) actor) + 0x28));
            z += *((f32 *) (((char *) object) + 0x2C));
            var_s1++;
            var_s0[2] = z;
          }
          var_s0 += 3;
        }

        if (var_s1 < 8)
        {
          goto __repair_rows;
        }
        bestCorner = -1;
        bestFallbackCorner = -1;
        cornerIndex = 0;
        temp_s4 = actor + 0x24;
        var_s0_2 = &corners[0].coord[0];
        do
        {
          frame.dir.coord[0] = (*((f32 *) (((char *) var_s0_2) + 0))) - (*((f32 *) (((char *) actor) + 0x24)));
          frame.dir.coord[1] = (*((f32 *) (((char *) var_s0_2) + 4))) - (*((f32 *) (((char *) actor) + 0x28)));
          frame.dir.coord[2] = (*((f32 *) (((char *) var_s0_2) + 8))) - (*((f32 *) (((char *) actor) + 0x2C)));
          dist = vec3NormalizeLength(&frame.dir.coord[0], &frame.dir.coord[0]);
          if (((raycastObjectParts((void *) world, temp_s4, &frame.dir.coord[0], dist) << 0x18) == 0) && ((castRayAgainstObjectsAndRooms(&rayTriangleIntersect, world, temp_s4, &frame.dir.coord[0], 0, dist, 0, 1, 0) << 0x18) == 0))
          {
            frame.dir.coord[0] = (*((f32 *) (((char *) goalPos) + 0))) - (*((f32 *) (((char *) var_s0_2) + 0)));
            frame.dir.coord[1] = (*((f32 *) (((char *) goalPos) + 4))) - (*((f32 *) (((char *) var_s0_2) + 4)));
            frame.dir.coord[2] = (*((f32 *) (((char *) goalPos) + 8))) - (*((f32 *) (((char *) var_s0_2) + 8)));
            dist = vec3NormalizeLength(&frame.dir.coord[0], &frame.dir.coord[0]);
            if (((raycastObjectParts((void *) world, var_s0_2, &frame.dir.coord[0], dist) << 0x18) == 0) && ((castRayAgainstObjectsAndRooms(&rayTriangleIntersect, world, var_s0_2, &frame.dir.coord[0], 0, dist, 0, 1, 0) << 0x18) == 0))
            {
              dist = approxDistanceXZ(temp_s4, var_s0_2) + approxDistanceXZ(goalPos, var_s0_2);
              if (dist < bestPathDist)
              {
                bestCorner = cornerIndex;
                bestPathDist = dist;
              }
            }
            else
            {
              dist = approxDistanceXZ(goalPos, var_s0_2);
              if (dist < bestFallbackDist)
              {
                bestFallbackCorner = cornerIndex;
                bestFallbackDist = dist;
              }
            }
          }
          __repair_rows_:
          {
            cornerIndex += 1;
          }

          if (0)
          {
            goto __repair_rows_;
          }
          var_s0_2 += 3;
        }
        while (cornerIndex < 8);
        if (bestCorner != (-1))
        {
          *((RoutePoint *) (((char *) route) + 0x18)) = corners[bestCorner];
          temp_fv0_11 = approxDistanceXZ(actor + 0x24, corners[bestCorner].coord);
          *((f32 *) (((char *) route) + 0x38)) = temp_fv0_11;
          *((f32 *) (((char *) route) + 0x34)) = temp_fv0_11;
          setActorAnimation(actor, successArg);
          return 1;
        }
        if (bestFallbackCorner != bestCorner)
        {
          *((RoutePoint *) (((char *) route) + 0x18)) = corners[bestFallbackCorner];
          temp_fv0_12 = approxDistanceXZ(actor + 0x24, corners[bestFallbackCorner].coord);
          *((f32 *) (((char *) route) + 0x38)) = temp_fv0_12;
          *((f32 *) (((char *) route) + 0x34)) = temp_fv0_12;
          setActorAnimation(actor, successArg);
          return 1;
        }
        var_v0 = 0;
        if (fallbackArg != 0)
        {
          temp_a2_3 = *((void **) (((char *) route) + 0x40));
          var_v0 = 1;
          if (temp_a2_3 != NULL)
          {
            *((RoutePoint *) (((char *) route) + 0x18)) = *((RoutePoint *) (((char *) temp_a2_3) + 0x24));
            if ((resetActorActionState(actor) << 0x18) != 0)
            {
              setActorCommandState(actor, 0x14D);
              setActorAnimation(actor, fallbackArg);
            }
            return 1;
          }
        }
        return var_v0;
      }
      setActorAnimation(actor, fallbackArg);
      return 1;
    }
    var_v0 = 0;
    return var_v0;
  }
  return var_v0;
}
