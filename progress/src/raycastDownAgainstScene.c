s32 sphereContainsPoint(s32, void *, f32);
s32 func_80047E4C();
s32 isPointOutsideActorSphere(void *, void *, f32);
s32 func_800488D4();
s32 rayTriangleIntersectDistance();
s32 computeGridCellMask();
s32 func_80082D24();
s32 rotateVec3InPlaceByMat3();
s32 rayHitsTriangleXZ();
s32 rotateVec3ByMat3();
typedef struct 
{
  f32 v[3];
} RayVec;
extern RayVec D_800D3E24;
extern void **gSweepHitObject;
extern void *gSweepHitActor;
typedef struct 
{
  f32 v;
} Field_f32;
typedef struct 
{
  s32 v;
} Field_s32;
typedef struct 
{
  u16 v;
} Field_u16;
typedef struct 
{
  u32 v;
} Field_u32;
typedef struct 
{
  u8 v;
} Field_u8;
/* Casts a vertical ray from rayOrigin through actors and objects, records the nearest hit in gSweepHitActor/gSweepHitObject and writes the hit point; returns 1 on hit. */ s32 raycastDownAgainstScene(void **objectList, RayVec *rayOrigin, void *outHit, f32 maxDistance)
{
  volatile struct 
  {
    f32 x;
    f32 y;
    f32 z;
    u32 pad;
  } projected;
  RayVec endpoint;
  f32 actorStart[3];
  f32 actorEnd[3];
  s32 actorMatrix[12];
  union 
  {
    RayVec start;
    struct 
    {
      s16 angles[4];
      RayVec direction;
      u32 gap;
      f32 hitWide;
      f32 hitNarrow;
    } actor;
  } scratch;
  s32 objectMatrix[10];
  RayVec objectEnd;
  RayVec objectDirection;
  f32 hitd;
  void *outHitPoint;
  f32 initialDist;
  f32 nearestDist;
  s32 temp_s0;
  s32 temp_s0_2;
  s32 temp_s3_2;
  s32 temp_s4;
  long temp_s6;
  s32 temp_s7;
  s32 temp_v0;
  s32 temp_v0_2;
  s32 temp_v1_11;
  s32 temp_v1_13;
  s32 temp_v1_3;
  s32 temp_v1_5;
  s32 temp_v1_7;
  s32 temp_v1_9;
  s32 var_s0;
  s32 var_s0_2;
  int var_s2;
  s32 var_s2_2;
  s32 var_s2_3;
  s32 var_s2_4;
  char *var_s4;
  char *var_s4_2;
  u16 temp_v1_10;
  u16 temp_v1_12;
  u16 temp_v1_2;
  u16 temp_v1_4;
  u16 temp_v1_6;
  u16 temp_v1_8;
  u32 temp_s3;
  u32 condA;
  u32 condB;
  f32 fz;
  u32 firstVertex;
  RayVec *rayStart;
  u32 temp_v1;
  u32 var_s0_3;
  register u32 var_s0_4;
  register u32 var_s0_5;
  u32 var_s0_6;
  register void **sceneObject;
  void *temp_a0;
  void *temp_a0_2;
  void *temp_a0_3;
  void *temp_a0_4;
  void *actorNode;
  void *collisionData;
  register void *var_s3;
  void *var_s3_2;

  nearestDist = maxDistance;
  sceneObject = objectList;
  rayStart = rayOrigin;
  outHitPoint = outHit;
  initialDist = nearestDist;
  if (sceneObject == NULL)
  {
    return 0;
  }
  {
    actorNode = *sceneObject;
    endpoint.v[0] = ((Field_f32 *) (((char *) rayStart) + 0))->v;
    endpoint.v[1] = ((Field_f32 *) (((char *) rayStart) + 4))->v + nearestDist;
    gSweepHitActor = NULL;
    gSweepHitObject = NULL;
    endpoint.v[2] = ((Field_f32 *) (((char *) rayStart) + 8))->v;
    if (actorNode != NULL)
    {
      s32 *sp104;
      f32 *sp10C;
      f32 *sp114;
      f32 *sp11C;
      f32 *sp124;
      f32 *sp12C;
      sp104 = actorMatrix;
      sp10C = actorStart;
      sp114 = actorEnd;
      sp11C = scratch.actor.direction.v;
      sp124 = &scratch.actor.hitWide;
      sp12C = &scratch.actor.hitNarrow;
      do
      {
        if ((*((void **) (((char *) actorNode) + 0x70))) != NULL)
        {
          temp_s3 = ((Field_u32 *) (((char *) actorNode) + 0x58))->v & 0x400;
          if (((!temp_s3) && (((Field_s32 *) (((char *) actorNode) + 0x5C))->v & 0x200)) && ((isPointOutsideActorSphere(actorNode, rayStart, initialDist) << 0x18) != 0))
          {
            collisionData = *((void **) (((char *) actorNode) + 0x70));
            scratch.actor.angles[0] = (s16) ((s32) (-((Field_f32 *) (((char *) actorNode) + 0x3C))->v));
            scratch.actor.angles[1] = (s16) ((s32) (-((Field_f32 *) (((char *) actorNode) + 0x40))->v));
            scratch.actor.angles[2] = (s16) ((s32) (-((Field_f32 *) (((char *) actorNode) + 0x44))->v));
            func_80082D24(scratch.actor.angles, sp104);
            actorStart[0] = ((Field_f32 *) (((char *) rayStart) + 0))->v - ((Field_f32 *) (((char *) actorNode) + 0x24))->v;
            actorStart[1] = ((Field_f32 *) (((char *) rayStart) + 4))->v - ((Field_f32 *) (((char *) actorNode) + 0x28))->v;
            actorStart[2] = ((Field_f32 *) (((char *) rayStart) + 8))->v - ((Field_f32 *) (((char *) actorNode) + 0x2C))->v;
            actorEnd[0] = endpoint.v[0] - ((Field_f32 *) (((char *) actorNode) + 0x24))->v;
            actorEnd[1] = endpoint.v[1] - ((Field_f32 *) (((char *) actorNode) + 0x28))->v;
            actorEnd[2] = endpoint.v[2] - ((Field_f32 *) (((char *) actorNode) + 0x2C))->v;
            rotateVec3ByMat3(sp104, sp10C);
            temp_s0 = collisionData + 0x18;
            rotateVec3ByMat3(sp104, sp114);
            if ((func_800488D4(temp_s0, sp10C, sp114) << 0x18) != 0)
            {
              scratch.actor.direction = D_800D3E24;
              temp_v0 = (u16) computeGridCellMask(temp_s0, sp10C, sp114); temp_v0 = (u16) temp_v0;
              temp_s7 = temp_v0 & 0xFF;
              temp_s6 = temp_v0 & 0xFF00;
              rotateVec3ByMat3(sp104, sp11C);
              temp_v1 = ((Field_u8 *) (((char *) collisionData) + 0x48))->v & 4;
              if (temp_v1 != 0)
              {
                projected.x = actorStart[0];
                projected.z = actorStart[2];
                var_s4 = *((u16 **) (((char *) collisionData) + 0x3C));
                condA = temp_s3 < ((u16) ((Field_u16 *) (((char *) collisionData) + 0x40))->v);
                var_s0_2 = 0;
                if (condA)
                {
                  var_s3 = ((u8 *) var_s4) + 4;
                  do
                  {
                    temp_v1_2 = *((u16 *) (((char *) (*((u8 **) (((char *) collisionData) + 0x38)))) + ((var_s0_2 & 0xFFFF) * 2)));
                    if ((temp_s7 & temp_v1_2) && (temp_s6 & temp_v1_2))
                    {
                      if (((rayHitsTriangleXZ(actorStart, scratch.actor.direction.v, ((Field_s32 *) (((char *) collisionData) + 0x34))->v + ((*((u16 *) var_s4)) * 0xC), ((Field_s32 *) (((char *) collisionData) + 0x34))->v + ((*((u16 *) (((char *) var_s3) + (-2)))) * 0xC), ((Field_s32 *) (((char *) collisionData) + 0x34))->v + (((Field_u16 *) (((char *) var_s3) + 0))->v * 0xC), sp124) & 0xFF)))
                      {
                        fz = 0.0f;
                        if ((scratch.actor.hitWide >= fz) && (scratch.actor.hitWide < nearestDist))
                        {
                        nearestDist = scratch.actor.hitWide;
                        gSweepHitActor = actorNode;
                        gSweepHitObject = NULL;
                        }
                      }
                    }
                    var_s3 += 6;
                    var_s4 += 6;
                    ++var_s0_2;
                  }
                  while (((u32) (var_s0_2 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) collisionData) + 0x40))->v));
                }
              }
              else
              {
                projected.x = actorStart[0];
                projected.z = actorStart[2];
                var_s4_2 = *((u8 **) (((char *) collisionData) + 0x3C));
                condB = temp_v1 < ((u16) ((Field_u16 *) (((char *) collisionData) + 0x40))->v);
                var_s0_2 = 0;
                if (condB)
                {
                  var_s3_2 = var_s4_2 + 2;
                  do
                  {
                    temp_v1_4 = *((u16 *) (((char *) (*((u8 **) (((char *) collisionData) + 0x38)))) + ((var_s0_2 & 0xFFFF) * 2)));
                    if ((temp_s7 & temp_v1_4) && (temp_s6 & temp_v1_4))
                    {
                      if (((rayHitsTriangleXZ(actorStart, scratch.actor.direction.v, ((Field_s32 *) (((char *) collisionData) + 0x34))->v + ((*((u8 *) var_s4_2)) * 0xC), ((Field_s32 *) (((char *) collisionData) + 0x34))->v + ((*((u8 *) (((char *) var_s3_2) + (-1)))) * 0xC), ((Field_s32 *) (((char *) collisionData) + 0x34))->v + (((Field_u8 *) (((char *) var_s3_2) + 0))->v * 0xC), sp12C) & 0xFF)))
                      {
                        fz = 0.0f;
                        if ((scratch.actor.hitNarrow >= fz) && (scratch.actor.hitNarrow < nearestDist))
                        {
                        nearestDist = scratch.actor.hitNarrow;
                        gSweepHitActor = actorNode;
                        gSweepHitObject = NULL;
                        }
                      }
                    }
                    var_s3_2 += 3;
                    var_s4_2 += 3;
                    var_s0_2 += 1;
                  }
                  while (((u32) (var_s0_2 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) collisionData) + 0x40))->v));
                }
              }
            }
          }
        }
        actorNode = *((void **) (((char *) actorNode) + 0));
      }
      while (actorNode != NULL);
    }
    if (sceneObject != NULL)
    {
      s16 *sp134;
      f32 *sp13C;
      f32 *sp144;
      s32 *spMat;
      f32 *spHit;
      sp134 = (s16 *) scratch.start.v;
      sp13C = objectEnd.v;
      spMat = objectMatrix;
      sp144 = objectDirection.v;
      spHit = &hitd;
      do
      {
        if (1)
        {
          if ((((Field_s32 *) (((char *) sceneObject) + 0x50))->v & 0x200) && ((sphereContainsPoint(((u8 *) sceneObject) + 0x40, rayStart, initialDist) << 0x18) != 0))
          {
            actorNode = *((void **) (((char *) sceneObject) + 0x3C));
            scratch.start = *rayStart;
            objectEnd = endpoint;
            if ((((u32) ((Field_u32 *) (((char *) sceneObject) + 0x5C))->v) >> 0x17) & 1)
            {
              scratch.start.v[0] -= ((Field_f32 *) (((char *) sceneObject) + 0x24))->v;
              scratch.start.v[1] -= ((Field_f32 *) (((char *) sceneObject) + 0x28))->v;
              scratch.start.v[2] -= ((Field_f32 *) (((char *) sceneObject) + 0x2C))->v;
              objectEnd.v[0] -= ((Field_f32 *) (((char *) sceneObject) + 0x24))->v;
              objectEnd.v[1] -= ((Field_f32 *) (((char *) sceneObject) + 0x28))->v;
              objectEnd.v[2] -= ((Field_f32 *) (((char *) sceneObject) + 0x2C))->v;
            }
            if ((((u32) ((Field_u32 *) (((char *) sceneObject) + 0x5C))->v) >> 0x17) & 2)
            {
              func_80047E4C(sceneObject, 0, spMat);
              rotateVec3InPlaceByMat3(spMat, sp134);
              rotateVec3InPlaceByMat3(spMat, (s16 *) sp13C);
            }
            temp_s0_2 = actorNode + 0x18;
            if ((func_800488D4(temp_s0_2, (f32 *) sp134, sp13C) << 0x18) != 0)
            {
              objectDirection = D_800D3E24;
              temp_v0_2 = computeGridCellMask(temp_s0_2, (f32 *) sp134, sp13C);
              temp_s4 = temp_v0_2 & 0xFF;
              temp_s3_2 = temp_v0_2 & 0xFF00;
              if ((!((((u32) ((Field_u32 *) (((char *) sceneObject) + 0x5C))->v) >> 0x17) & 2)) || ((rotateVec3InPlaceByMat3(objectMatrix, (s16 *) sp144), ((((u32) ((Field_u32 *) (((char *) sceneObject) + 0x5C))->v) >> 0x17) & 2) == 0)))
              {
                if (((Field_u8 *) (((char *) actorNode) + 0x48))->v & 4)
                {
                  var_s0_3 = 0;
                  if (((Field_u16 *) (((char *) actorNode) + 0x40))->v > var_s0_3)
                  {
                    var_s2 = 0;
                    do
                    {
                      temp_a0 = ((Field_s32 *) (((char *) actorNode) + 0x3C))->v;

                      temp_a0 += var_s2;
                      temp_v1_6 = *((u16 *) (((char *) (*((u8 **) (((char *) actorNode) + 0x38)))) + (var_s0_3 * 2)));
                      if ((temp_s4 & temp_v1_6) && (temp_s3_2 & temp_v1_6))
                      {
                        if (((rayTriangleIntersectDistance(scratch.start.v, objectDirection.v, ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u16 *) (((char *) temp_a0) + 0))->v * 0xC), ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u16 *) (((char *) temp_a0) + 2))->v * 0xC), ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u16 *) (((char *) temp_a0) + 4))->v * 0xC), spHit) & 0xFF) && (hitd >= 0.0f)) && (hitd < nearestDist))
                        {
                          nearestDist = hitd;
                          gSweepHitActor = NULL;
                          gSweepHitObject = sceneObject;
                        }
                      }
                      var_s2 += 6;
                      var_s0_3 += 1;
                    }
                    while (var_s0_3 < ((u16) ((Field_u16 *) (((char *) actorNode) + 0x40))->v));
                  }
                }
                else
                {
                  var_s0_4 = 0;
                  if (((Field_u16 *) (((char *) actorNode) + 0x40))->v > var_s0_4)
                  {
                  var_s2_2 = 0;
                  do
                  {
                    temp_a0_2 = ((Field_s32 *) (((char *) actorNode) + 0x3C))->v;

                    temp_a0_2 += var_s2_2;
                    temp_v1_8 = *((u16 *) (((char *) (*((u8 **) (((char *) actorNode) + 0x38)))) + (var_s0_4 * 2)));
                    if ((temp_s4 & temp_v1_8) && (temp_s3_2 & temp_v1_8))
                    {
                      if (((rayTriangleIntersectDistance(scratch.start.v, objectDirection.v, ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u8 *) (((char *) temp_a0_2) + 0))->v * 0xC), ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u8 *) (((char *) temp_a0_2) + 1))->v * 0xC), ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u8 *) (((char *) temp_a0_2) + 2))->v * 0xC), spHit) & 0xFF) && (hitd >= 0.0f)) && (hitd < nearestDist))
                      {
                        nearestDist = hitd;
                        gSweepHitActor = NULL;
                        gSweepHitObject = sceneObject;
                      }
                    }
                    ++var_s0_4;
                    var_s2_2 += 3;
                  }
                  while (var_s0_4 < ((u16) ((Field_u16 *) (((char *) actorNode) + 0x40))->v));
                }
                }
              }
              else
                if (((Field_u8 *) (((char *) actorNode) + 0x48))->v & 4)
              {
                var_s0_5 = 0;
                if (((Field_u16 *) (((char *) actorNode) + 0x40))->v > var_s0_5)
                {
                  var_s2_3 = 0;
                  do
                  {
                    temp_a0_3 = ((Field_s32 *) (((char *) actorNode) + 0x3C))->v;

                    temp_a0_3 += var_s2_3;
                    temp_v1_10 = *((u16 *) (((char *) (*((u8 **) (((char *) actorNode) + 0x38)))) + (var_s0_5 * 2)));
                    if ((temp_s4 & temp_v1_10) && (temp_s3_2 & temp_v1_10))
                    {
                      if (((rayTriangleIntersectDistance(scratch.start.v, objectDirection.v, ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u16 *) (((char *) temp_a0_3) + 0))->v * 0xC), ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u16 *) (((char *) temp_a0_3) + 2))->v * 0xC), ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u16 *) (((char *) temp_a0_3) + 4))->v * 0xC), spHit) & 0xFF) && (hitd >= 0.0f)) && (hitd < nearestDist))
                      {
                        nearestDist = hitd;
                        gSweepHitActor = NULL;
                        gSweepHitObject = sceneObject;
                      }
                    }
                    var_s0_5 += 1;
                    var_s2_3 += 6;
                  }
                  while (var_s0_5 < ((u16) ((Field_u16 *) (((char *) actorNode) + 0x40))->v));
                }
              }
              else
              {
                var_s0_6 = 0;
                if (((Field_u16 *) (((char *) actorNode) + 0x40))->v > var_s0_6)
                {
                  var_s2_4 = 0;
                  do
                  {
                    temp_v1_12 = *((u16 *) (((char *) (*((u8 **) (((char *) actorNode) + 0x38)))) + (var_s0_6 * 2)));
                    temp_a0_4 = ((Field_s32 *) (((char *) actorNode) + 0x3C))->v;
                    temp_a0_4 += var_s2_4;
                    if ((temp_s4 & temp_v1_12) && ((temp_v0 = temp_s3_2 & temp_v1_12) != 0))
                    {
                      if (((rayTriangleIntersectDistance(scratch.start.v, objectDirection.v, ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u8 *) (((char *) temp_a0_4) + 0))->v * 0xC), ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u8 *) (((char *) temp_a0_4) + 1))->v * 0xC), ((Field_s32 *) (((char *) actorNode) + 0x34))->v + (((Field_u8 *) (((char *) temp_a0_4) + 2))->v * 0xC), spHit) & 0xFF) && (hitd >= 0.0f)) && (hitd < nearestDist))
                      {
                        nearestDist = hitd;
                        gSweepHitActor = NULL;
                        gSweepHitObject = sceneObject;
                      }
                    }
                    ++var_s0_6;
                    var_s2_4 += 3;
                  }
                  while (var_s0_6 < ((u16) ((Field_u16 *) (((char *) actorNode) + 0x40))->v));
                }
              }
            }
          }
        }
        sceneObject = *((void ***) (((char *) sceneObject) + 0x14));
      }
      while (sceneObject != NULL);
    }
    if (nearestDist != initialDist)
    {
      ((Field_f32 *) (((char *) outHitPoint) + 0))->v = (f32) ((Field_f32 *) (((char *) rayStart) + 0))->v;
      ((Field_f32 *) (((char *) outHitPoint) + 4))->v = (f32) (((Field_f32 *) (((char *) rayStart) + 4))->v + nearestDist);
      ((Field_f32 *) (((char *) outHitPoint) + 8))->v = (f32) ((Field_f32 *) (((char *) rayStart) + 8))->v;
      return 1;
    }
  }
  block_83:
  return 0;

}


