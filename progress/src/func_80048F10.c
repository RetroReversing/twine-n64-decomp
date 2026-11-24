#define sp18 stack_sp18[0]
#define sp1C stack_sp18[1]
#define sp20 stack_sp18[2]
#define sp28 stack_sp28[0]
#define sp2C stack_sp28[1]
#define sp30 stack_sp28[2]
#define sp38 stack_sp38[0]
#define sp3C stack_sp38[1]
#define sp40 stack_sp38[2]
#define sp48 stack_sp48[0]
#define sp4C stack_sp48[1]
#define sp50 stack_sp48[2]
#define sp58 stack_sp58[0]
#define sp5C stack_sp58[1]
#define sp60 stack_sp58[2]
#define sp98 angleOrPoint.angles[0]
#define sp9A angleOrPoint.angles[1]
#define sp9C angleOrPoint.angles[2]
#define spA0 stack_spA0[0]
#define spA4 stack_spA0[1]
#define spA8 stack_spA0[2]
#define spB8 stack_spB8[0]
#define spBC stack_spB8[1]
#define spC0 stack_spB8[2]
#define spC8 stack_spC8[0]
#define spCC stack_spC8[1]
#define spD0 stack_spC8[2]
#define stack_spD8 u_d8.d8
#define stack_spE0 u_d8.o.e0
#define spF0 hpF0.hit
#define stack_spF8 hpF0.plane
#define sp178 hp178.hit
#define stack_sp180 hp178.v
#define spD8 stack_spD8[0]
#define spDC stack_spD8[1]
#define spE0 stack_spE0[0]
#define spE4 stack_spE0[1]
#define spE8 stack_spE0[2]
#define spF8 stack_spF8[0]
#define spFC stack_spF8[1]
#define sp100 stack_spF8[2]
#define sp104 stack_spF8[3]
#define sp108 stack_sp108[0]
#define sp10C stack_sp108[1]
#define sp110 stack_sp108[2]
#define sp118 stack_sp118[0]
#define sp11C stack_sp118[1]
#define sp120 stack_sp118[2]
#define sp128 stack_sp128[0]
#define sp12C stack_sp128[1]
#define sp130 stack_sp128[2]
#define sp138 stack_sp138[0]
#define sp13C stack_sp138[1]
#define sp140 stack_sp138[2]
#define sp148 stack_sp148[0]
#define sp14C stack_sp148[1]
#define sp150 stack_sp148[2]
#define sp158 stack_sp158[0]
#define sp15C stack_sp158[1]
#define sp160 stack_sp158[2]
#define sp168 stack_sp168[0]
#define sp16C stack_sp168[1]
#define sp170 stack_sp168[2]
#define sp180 stack_sp180[0]
#define sp184 stack_sp180[1]
#define sp188 stack_sp180[2]
#define spB0 stack_spB0[0]
#define spB4 stack_spB0[1]
#define matrix scratch.rotation
#define angleOrPoint scratch.vector
#define stack_spA0 scratch.vector.overlap.vec
s32 sphereContainsPoint(void **, void *, f32);
f32 absFloat(f32);
s32 applyObjectRotation(void **, s32, f32 *);
s32 boxTestPointPair(s32, f32 *, f32 *);
s32 buildPlaneFromPoints(f32 *, s32, s32, s32);
s32 buildRotationMatrix(s16 *, s32 *);
void buildRotationMatrixS16(const s16 *, f32 *);
f32 distanceSquared3D(f32 *, f32 *);
void *raycastObjectMesh(void **, f32 *, f32 *, f32 *);
s32 isPointOutsideActorSphere(void *, void *, f32);
s32 rayTriangleIntersectDistance(f32 *, f32 *, s32, s32, s32, f32 *);
s32 computeGridCellMask(s32, f32 *, f32 *);
s32 multiplyMat3ByVec3(s32 *, f32 *, f32 *);
s32 rotateVec3InPlaceByMat3(f32 *, f32 *);
s32 prepareLinkedObjectPair(void *, void *, void **);
s32 rayHitsTriangleXZ(f32 *, f32 *, s32, s32, s32, f32 *);
s32 rotateVec3ByMat3(s32 *, f32 *);
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} CollisionVec;
f32 segmentClosestPoint(CollisionVec *, const CollisionVec *, const CollisionVec *, const CollisionVec *);
s32 segmentOverlapsBox(s32, f32 *, f32 *);
extern CollisionVec D_800D3E18;
extern void **D_80103F00;
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
inline static u16 *inline_fn(u16 **arg0)
{
  return *arg0;
}

typedef struct { f32 v[4]; } PlaneCopy;
s32 func_80048F10(void **arg0, void *arg1, void *arg2, void *arg3, f32 arg4, void *arg5, void *arg6, void *arg7)
{
  u32 guard_value;
  u32 guard_value_2;
  f32 *sp118_arg;
  f32 *sp108_arg;
  f32 stack_sp18[3];
  f32 stack_sp28[3];
  f32 stack_sp38[3];
  f32 stack_sp48[3];
  f32 stack_sp58[3];
  struct 
  {
    f32 rotation[12];
    union 
    {
      s16 angles[3];
      CollisionVec point;
      struct 
      {
        f32 prefix[2];
        f32 vec[3];
      } overlap;
    } vector;
  } scratch;
  f32 stack_spB0[2];
  f32 stack_spB8[3];
  f32 stack_spC8[3];
  union { f32 d8[3]; struct { f32 pad[2]; f32 e0[3]; } o; } u_d8;
  struct { f32 hit; f32 unused; f32 plane[4]; } hpF0;
  f32 stack_sp108[3];
  f32 stack_sp118[3];
  f32 stack_sp128[3];
  f32 stack_sp138[3];
  f32 stack_sp148[3];
  f32 stack_sp158[3];
  f32 stack_sp168[3];
  struct { f32 hit; f32 unused; f32 v[3]; } hp178;
  void *sp1AC;
  void *phase;
  s32 *sp1BC;
  f32 *sp1C4;
  f32 *sp1CC;
  f32 *sp1D4;
  f32 *sp1DC;
  f32 *sp1E4;
  f32 *sp1EC;
  register u16 sp1F6;
  u16 sp1FE;
  f32 *sp204;
  f32 *sp20C;
  f32 *sp214;
  f32 *sp21C;
  f32 *sp224;
  s32 hitIndex;
  f32 *sp234;
  f32 temp_fs1;
  f32 temp_fs1_2;
  f32 temp_fs1_3;
  f32 temp_fs1_4;
  f32 temp_ft1;
  f32 temp_fv0;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f32 temp_fv0_4;
  f32 temp_fv0_5;
  f32 temp_fv0_6;
  f32 temp_fv0_7;
  f32 temp_fv0_8;
  f32 temp_fv0_9;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 var_fs0;
  f32 best;
  f32 best_2;
  f32 best_3;
  f32 best_4;
  f32 var_fs0_2;
  f32 var_fs0_3;
  f32 var_fs0_4;
  f32 var_fs2;
  s32 temp_s0;
  s32 temp_s0_2;
  u16 temp_s1_2;
  long temp_s1_3;
  s32 temp_s1_4;
  s32 temp_s1_5;
  s32 temp_s5;
  s32 temp_s5_2;
  unsigned int temp_t2;
  unsigned long temp_t3;
  u32 temp_v0;
  register s32 temp_v0_2;
  s32 var_a1;
  unsigned int var_a2;
  unsigned var_s0;
  long var_s0_2;
  s32 var_s3_3;
  
  s32 var_s4;
  
  u16 var_s4_3;
  s32 var_s6;
  register s32 var_v0;
  s32 var_v0_10;
  s32 var_v0_11;
  s32 var_v0_2;
  s32 var_v0_3;
  register s32 var_v0_4;
  unsigned var_v0_6;
  int var_v0_7;
  s32 var_v0_8;
  unsigned long var_v0_9;
  s32 var_v1;
  s32 var_v1_10;
  s32 var_v1_2;
  s32 var_v1_3;
  s32 var_v1_4;
  s32 var_v1_5;
  unsigned long var_v1_6;
  s32 var_v1_7;
  unsigned int var_v1_8;
  s32 var_v1_9;
  u16 *var_s3;
  u8 *var_s3_2;
  u16 *var_s3_5;
  u8 *var_s3_6;
  s32 temp_v1_11;
  u16 var_v0_5;
  u32 temp_s1;
  unsigned long temp_s2;
  u32 temp_v1;
  u32 temp_v1_19;
  u32 temp_v1_22;
  u32 temp_v1_29;
  void **var_a0;
  void **var_s7;
  void *temp_s0_3;
  void *temp_s0_4;
  void *temp_s2_2;
  void *temp_s4;
  void *temp_v0_3;
  void *temp_v1_17;
  void *temp_v1_18;
  void *var_s0_3;
  void *var_s0_4;
  void *var_s1;
  void *var_s2;
  void *var_s2_2;
  void *found;
  s32 verts;
  u16 *tri16;
  u8 *tri8;
  gSweepHitActor = NULL;
  gSweepHitObject = NULL;
  D_80103F00 = NULL;
  var_fs2 = arg4;
  found = NULL;
  if (arg0 == NULL)
  {
    goto ret0;
  }
  {
    sp18 = 0.0f;
    sp1C = 0.0f;
    sp20 = 0.0f;
    *((CollisionVec *) (&sp38)) = *((CollisionVec *) arg1);
    sp28 = ((Field_f32 *) (((char *) arg1) + 0))->v;
    sp1BC = (s32 *) matrix;
    sp2C = ((Field_f32 *) (((char *) arg1) + 4))->v - var_fs2;
    sp1C4 = &sp48;
    sp1CC = &sp58;
    sp30 = ((Field_f32 *) (((char *) arg1) + 8))->v;
    do
    {
      var_s7 = arg0;
      var_a0 = arg0;
      sp1AC = inline_fn((void **) (((char *) inline_fn((void **) (((char *) arg0) + 0x20))) + 0x58));
      phase = sp1AC;
      if (var_a0 != NULL)
      {
        sp1D4 = &spA0;
        sp1DC = &spB0;
        do
        {
          var_s1 = inline_fn(var_a0);
          if (var_s1 != NULL)
          {
            sp1E4 = &spB4;
            do
            {
              if (inline_fn((void **) (((char *) var_s1) + 0x70)) != NULL)
              {
                temp_s2 = ((Field_s32 *) (((char *) var_s1) + 0x58))->v & 0x400;
                if (((temp_s2 == 0) && (((Field_s32 *) (((char *) var_s1) + 0x5C))->v & 0x200)) && ((isPointOutsideActorSphere(var_s1, arg1, arg4) << 0x18) != 0))
                {
                  temp_s4 = inline_fn((void **) (((char *) var_s1) + 0x70));
                  sp98 = (s16) ((s32) (-((Field_f32 *) (((char *) var_s1) + 0x3C))->v));
                  sp9A = (s16) ((s32) (-((Field_f32 *) (((char *) var_s1) + 0x40))->v));
                  sp9C = (s16) ((s32) (-((Field_f32 *) (((char *) var_s1) + 0x44))->v));
                  buildRotationMatrix(&sp98, sp1BC);
                  sp48 = ((Field_f32 *) (((char *) arg1) + 0))->v - ((Field_f32 *) (((char *) var_s1) + 0x24))->v;
                  sp4C = ((Field_f32 *) (((char *) arg1) + 4))->v - ((Field_f32 *) (((char *) var_s1) + 0x28))->v;
                  sp50 = ((Field_f32 *) (((char *) arg1) + 8))->v - ((Field_f32 *) (((char *) var_s1) + 0x2C))->v;
                  sp58 = sp28 - ((Field_f32 *) (((char *) var_s1) + 0x24))->v;
                  sp5C = sp2C - ((Field_f32 *) (((char *) var_s1) + 0x28))->v;
                  sp60 = sp30 - ((Field_f32 *) (((char *) var_s1) + 0x2C))->v;
                  rotateVec3ByMat3(sp1BC, sp1C4);
                  rotateVec3ByMat3(sp1BC, sp1CC);
                  temp_s0 = temp_s4 + 0x18;
                  if ((segmentOverlapsBox(temp_s0, sp1C4, sp1CC) << 0x18) != 0)
                  {
                    *((CollisionVec *) (&spA0)) = D_800D3E18;
                    temp_v0 = (u16) computeGridCellMask(temp_s0, sp1C4, sp1CC); temp_v0 = (u16) temp_v0;
                    temp_t3 = temp_v0 & 0xFF;
                    temp_t2 = temp_v0 & 0xFF00;
                    rotateVec3ByMat3(sp1BC, sp1D4);
                    sp18 = sp48;
                    sp20 = sp50;
                    temp_v1 = ((Field_u8 *) (((char *) temp_s4) + 0x48))->v & 4;
                    var_s6 = -1;
                    if (((int) temp_v1) != 0)
                    {
                      var_s3 = inline_fn((u16 **) (((char *) temp_s4) + 0x3C));
                      guard_value = (temp_s2 < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v));
                      do { do { var_s0 = 0; } while (0); } while (0);
                      if (guard_value)
                      {
                        var_s2 = var_s3 + 2;
                        do
                        {
                          temp_s5 = var_s0 & 0xFFFF;
                          if ((temp_t3 & (*((u16 *) ((temp_s5 * 2) + ((Field_s32 *) (((char *) temp_s4) + 0x38))->v)))) && (temp_t2 & (*((u16 *) ((temp_s5 * 2) + ((Field_s32 *) (((char *) temp_s4) + 0x38))->v)))))
                          {
                            if (rayTriangleIntersectDistance(&sp48, &spA0, (((Field_s32 *) (((char *) temp_s4) + 0x34))->v) + ((*var_s3) * 0xC), (((Field_s32 *) (((char *) temp_s4) + 0x34))->v) + ((*((u16 *) (((char *) var_s2) + (-2)))) * 0xC), ((((Field_s32 *) (((char *) temp_s4) + 0x34))->v)) + (((Field_u16 *) (((char *) var_s2) + 0))->v * 0xC), sp1DC) & 0xFF)
                            {
                              f32 distance = spB0;
                              if (distance >= 0.0f)
                              {
                                if (distance < var_fs2)
                                {
                                var_fs2 = distance;
                                var_s6 = temp_s5;
                              }
                              }
                            }
                          }
                          var_s2 = ((u16 *) var_s2) + 3;
                          var_s3 += 3;
                          var_s0 += 1;
                        }
                        while (((u32) (var_s0 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v));
                      }
                    }
                    else
                    {
                      var_s3_2 = inline_fn((u8 **) (((char *) temp_s4) + 0x3C));
                      guard_value_2 = (temp_v1 < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v));
                      do { do { var_s0_2 = 0; } while (0); } while (0);
                      if (guard_value_2)
                      {
                        var_s2_2 = var_s3_2 + 2;
                        do
                        {
                          temp_s5_2 = ((u32) var_s0_2) & 0xFFFF;
                          if ((temp_t3 & (*((u16 *) ((temp_s5_2 * 2) + ((Field_s32 *) (((char *) temp_s4) + 0x38))->v)))) && ((temp_v0 = temp_t2 & (*((u16 *) ((temp_s5_2 * 2) + ((Field_s32 *) (((char *) temp_s4) + 0x38))->v)))) != 0))
                          {
                            if (((rayTriangleIntersectDistance(&sp48, &spA0, (((Field_s32 *) (((char *) temp_s4) + 0x34))->v) + ((*((u8 *) var_s3_2)) * 0xC), (((Field_s32 *) (((char *) temp_s4) + 0x34))->v) + ((*((u8 *) (((char *) var_s2_2) + (-1)))) * 0xC), (((Field_s32 *) (((char *) temp_s4) + 0x34))->v) + (((Field_u8 *) (((char *) var_s2_2) + 0))->v * 0xC), sp1E4) & 0xFF) && (spB4 >= 0.0f)) && (spB4 < var_fs2))
                            {
                              var_fs2 = spB4;
                              var_s6 = temp_s5_2;
                            }
                          }
                          var_s2_2 += 3;
                          var_s3_2 += 3;
                          var_s0_2 += 1;
                        }
                        while (((u32) (var_s0_2 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v));
                      }
                    }
                    if (var_s6 != (-1))
                    {
                      gSweepHitActor = var_s1;
                      gSweepHitObject = NULL;
                      sp1C = sp4C - var_fs2;
                    }
                  }
                }
              }
              var_s1 = inline_fn((void **) (((char *) var_s1) + 0));
            }
            while (var_s1 != NULL);
          }
          var_a0 = NULL;
          if (phase != NULL)
          {
            var_a0 = *((void ***) (((char *) phase) + 8));
            phase = inline_fn((void **) (((char *) phase) + 0));
          }
        }
        while (var_a0 != NULL);
      }
      if (var_s7 != NULL)
      {
        sp1EC = &angleOrPoint.point.x;
        sp204 = &sp128;
        sp108_arg = &sp108;
        sp20C = &sp138;
        sp214 = &sp148;
        sp118_arg = &sp118;
        do
        {
          if (((Field_s32 *) (((char *) var_s7) + 0x50))->v & 0x200)
          {
            temp_s1 = (((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 4;
            if (temp_s1)
            {
              temp_fv1 = ((Field_f32 *) (((char *) arg1) + 4))->v - (*((f32 *) (((char *) inline_fn((void **) (((char *) var_s7) + 0x3C))) + 0x20)));
              var_v0_10 = 1;
              if (!(temp_fv1 >= 0.0f))
              {
                var_v0_10 = 0;
              }
              var_v1_9 = 1;
              if (!(temp_fv1 < var_fs2))
              {
                var_v1_9 = 0;
              }
              if (var_v0_10 & var_v1_9)
              {
                var_fs2 = temp_fv1;
                goto block_199;
              }
            }
            else
            {
              if ((sphereContainsPoint((void **) (((u8 *) var_s7) + 0x40), arg1, arg4) << 0x18) != 0)
              {
                temp_s2_2 = inline_fn((void **) (((char *) var_s7) + 0x3C));
                *((CollisionVec *) (&sp58)) = *((CollisionVec *) arg1);
                angleOrPoint.point = *((CollisionVec *) (&sp28));
                if ((((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 1)
                {
                  sp58 -= ((Field_f32 *) (((char *) var_s7) + 0x24))->v;
                  sp5C -= ((Field_f32 *) (((char *) var_s7) + 0x28))->v;
                  sp60 -= ((Field_f32 *) (((char *) var_s7) + 0x2C))->v;
                  angleOrPoint.point.x -= ((Field_f32 *) (((char *) var_s7) + 0x24))->v;
                  angleOrPoint.point.y -= ((Field_f32 *) (((char *) var_s7) + 0x28))->v;
                  angleOrPoint.point.z -= ((Field_f32 *) (((char *) var_s7) + 0x2C))->v;
                }
                if ((((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 2)
                {
                  applyObjectRotation(var_s7, 0, &spB8);
                  rotateVec3InPlaceByMat3(&spB8, sp1CC);
                  rotateVec3InPlaceByMat3(&spB8, (f32 *) sp1EC);
                }
                temp_s0_2 = temp_s2_2 + 0x18;
                if ((boxTestPointPair(temp_s0_2, sp1CC, sp1EC) << 0x18) != 0)
                {
                  *((CollisionVec *) (&spE0)) = D_800D3E18;
                  temp_v0_2 = computeGridCellMask(temp_s0_2, sp1CC, (f32 *) sp1EC);
                  sp1F6 = temp_v0_2 & 0xFF;
                  sp1FE = temp_v0_2 & 0xFF00;
                  if ((!((((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 2)) || ((rotateVec3InPlaceByMat3(&spB8, &spE0), ((((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 2) == 0)))
                  {
                    var_s4 = -1;
                    if (((Field_u8 *) (((char *) temp_s2_2) + 0x48))->v & 4)
                    {
                      var_s3_3 = 0;
                      if (temp_s1 < ((u16) ((Field_u16 *) (((char *) temp_s2_2) + 0x40))->v))
                      {
                        do
                        {
                          temp_s1_2 = var_s3_3 & 0xFFFF;
                          temp_s0_3 = (char *) inline_fn((u16 **) (((char *) temp_s2_2) + 0x3C)); temp_s0_3 += ((unsigned) temp_s1_2) * 6;
                          if (((*((u16 *) ((temp_s1_2 * 2) + ((Field_s32 *) (((char *) temp_s2_2) + 0x38))->v))) & sp1F6) && ((*((u16 *) ((temp_s1_2 * 2) + ((Field_s32 *) (((char *) temp_s2_2) + 0x38))->v))) & sp1FE))
                          {
                            if (rayHitsTriangleXZ(&sp58, &spE0, (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 0))->v * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 2))->v * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 4))->v * 0xC), &spF0) & 0xFF)
                            {
                              f32 distance = spF0; if (distance >= 0.0f)
                              {
                                if (distance < var_fs2)
                              {
                                if ((((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 0x20)
                                {
                                  if (arg3 != NULL)
                                  {
                                    ((Field_f32 *) (((char *) arg3) + 0))->v = (f32) ((Field_f32 *) (((char *) arg1) + 0))->v;
                                    ((Field_f32 *) (((char *) arg3) + 4))->v = (f32) (((Field_f32 *) (((char *) arg1) + 4))->v - distance);
                                    D_80103F00 = var_s7;
                                    ((Field_f32 *) (((char *) arg3) + 8))->v = (f32) ((Field_f32 *) (((char *) arg1) + 8))->v;
                                  }
                                }
                                else
                                {
                                  var_fs2 = distance;
                                  var_s4 = (s32) temp_s1_2;
                                }
                              }
                              }
                            }
                            else
                              if (!((((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 0x20))
                            {
                              buildPlaneFromPoints(&spF8, (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 0))->v * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 2))->v * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 4))->v * 0xC));
                              if (spFC > 0.5f)
                              {
                                temp_fv0 = (((spF8 * sp58) + (spFC * sp5C)) + (sp100 * sp60)) + sp104;
                                spF0 = temp_fv0;
                                if (temp_fv0 >= 0.0f)
                                {
                                  if (temp_fv0 < var_fs2)
                                {
                                  sp108 = sp58 - (temp_fv0 * spF8);
                                  sp10C = sp5C - (temp_fv0 * spFC);
                                  sp110 = sp60 - (temp_fv0 * sp100);
                                  segmentClosestPoint((CollisionVec *) sp204, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 0))->v * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 2))->v * 0xC)), (CollisionVec *) sp108_arg);
                                  var_fs0 = distanceSquared3D(sp204, sp108_arg);
                                  segmentClosestPoint((CollisionVec *) sp20C, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 2))->v * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 4))->v * 0xC)), (CollisionVec *) sp108_arg);
                                  temp_fs1 = distanceSquared3D(sp20C, sp108_arg);
                                  segmentClosestPoint((CollisionVec *) sp214, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 4))->v * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u16 *) (((char *) temp_s0_3) + 0))->v * 0xC)), (CollisionVec *) sp108_arg);
                                  temp_fv0_2 = distanceSquared3D(sp214, sp108_arg);
                                  *((CollisionVec *) (&sp118)) = *((CollisionVec *) (&sp128));
                                  best = var_fs0;
                                  var_v0 = 1;
                                  if (!(temp_fs1 < var_fs0))
                                  {
                                    var_v0 = 0;
                                  }
                                  var_v1 = 1;
                                  if (!(temp_fs1 < temp_fv0_2))
                                  {
                                    var_v1 = 0;
                                  }
                                  if (var_v0 & var_v1)
                                  {
                                    *((CollisionVec *) (&sp118)) = *((CollisionVec *) (&sp138));
                                    best = temp_fs1;
                                  }
                                  else
                                  {
                                    var_v0_2 = 1;
                                    if (!(temp_fv0_2 < var_fs0))
                                    {
                                      var_v0_2 = 0;
                                    }
                                    var_v1_2 = 1;
                                    if (!(temp_fs1 > temp_fv0_2))
                                    {
                                      var_v1_2 = 0;
                                    }
                                    if (var_v0_2 & var_v1_2)
                                    {
                                      *((CollisionVec *) (&sp118)) = *((CollisionVec *) (&sp148));
                                      best = temp_fv0_2;
                                    }
                                  }
                                  if (best < 0.040000003f)
                                  {
                                    var_fs2 = spF0;
                                    var_s4 = var_s3_3 & 0xFFFF;
                                  }
                                }
                                }
                              }
                            }
                          }
                          var_s3_3 += 1;
                        }
                        while (((u32) (var_s3_3 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s2_2) + 0x40))->v));
                      }
                    }
                    else
                    {
                      var_s3_3 = 0;
                      if (temp_s1 < ((u16) ((Field_u16 *) (((char *) temp_s2_2) + 0x40))->v))
                      {
                        sp21C = &sp158;
                        sp224 = &sp168;
                        do
                        {
                          temp_s1_3 = ((s32) var_s3_3) & 0xFFFF;
                          temp_s0_4 = (char *) inline_fn((u16 **) (((char *) temp_s2_2) + 0x3C)); temp_s0_4 += ((unsigned) temp_s1_3) * 3; if (((*((u16 *) ((temp_s1_3 * 2) + ((Field_s32 *) (((char *) temp_s2_2) + 0x38))->v))) & sp1F6) && ((*((u16 *) ((temp_s1_3 * 2) + ((Field_s32 *) (((char *) temp_s2_2) + 0x38))->v))) & sp1FE)) {
                            if (rayHitsTriangleXZ(&sp58, &spE0, (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 0))->v * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 1))->v * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 2))->v * 0xC), &spF0) & 0xFF)
                            {
                              f32 distance = spF0; if (distance >= 0.0f)
                              {
                                if (distance < var_fs2)
                              {
                                if ((((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 0x20)
                                {
                                  if (arg3 != NULL)
                                  {
                                    ((Field_f32 *) (((char *) arg3) + 0))->v = (f32) ((Field_f32 *) (((char *) arg1) + 0))->v;
                                    ((Field_f32 *) (((char *) arg3) + 4))->v = (f32) (((Field_f32 *) (((char *) arg1) + 4))->v - distance);
                                    D_80103F00 = var_s7;
                                    ((Field_f32 *) (((char *) arg3) + 8))->v = (f32) ((Field_f32 *) (((char *) arg1) + 8))->v;
                                  }
                                }
                                else
                                {
                                  var_fs2 = distance;
                                  var_s4 = temp_s1_3;
                                }
                              }
                              }
                            }
                            else
                              if (!((((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 0x20))
                            {
                              buildPlaneFromPoints(&spF8, (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 0))->v * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 1))->v * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 2))->v * 0xC));
                              if (spFC > 0.5f)
                              {
                                temp_fv0_3 = (((spF8 * sp58) + (spFC * sp5C)) + (sp100 * sp60)) + sp104;
                                spF0 = temp_fv0_3;
                                if (temp_fv0_3 >= 0.0f)
                                {
                                  if (temp_fv0_3 < var_fs2)
                                {
                                  sp118 = sp58 - (temp_fv0_3 * spF8);
                                  sp11C = sp5C - (temp_fv0_3 * spFC);
                                  sp120 = sp60 - (temp_fv0_3 * sp100);
                                  segmentClosestPoint((CollisionVec *) sp20C, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 0))->v * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 1))->v * 0xC)), (CollisionVec *) sp118_arg);
                                  var_fs0_2 = distanceSquared3D(sp20C, sp118_arg);
                                  segmentClosestPoint((CollisionVec *) sp21C, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 1))->v * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 2))->v * 0xC)), (CollisionVec *) sp118_arg);
                                  temp_fs1_2 = distanceSquared3D(sp21C, sp118_arg);
                                  segmentClosestPoint((CollisionVec *) sp224, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 2))->v * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (((Field_u8 *) (((char *) temp_s0_4) + 0))->v * 0xC)), (CollisionVec *) sp118_arg);
                                  temp_fv0_4 = distanceSquared3D(sp224, sp118_arg);
                                  *((CollisionVec *) (&sp128)) = *((CollisionVec *) (&sp138));
                                  best_2 = var_fs0_2;
                                  var_v0_3 = 1;
                                  if (!(temp_fs1_2 < var_fs0_2))
                                  {
                                    var_v0_3 = 0;
                                  }
                                  var_v1_3 = 1;
                                  if (!(temp_fs1_2 < temp_fv0_4))
                                  {
                                    var_v1_3 = 0;
                                  }
                                  if (var_v0_3 & var_v1_3)
                                  {
                                    *((CollisionVec *) (&sp128)) = *((CollisionVec *) (&sp158));
                                    best_2 = temp_fs1_2;
                                  }
                                  else
                                  {
                                    var_v0_4 = 1;
                                    if (!(var_fs0_2 > temp_fv0_4))
                                    {
                                      var_v0_4 = 0;
                                    }
                                    var_v1_4 = 1;
                                    if (!(temp_fs1_2 > temp_fv0_4))
                                    {
                                      var_v1_4 = 0;
                                    }
                                    if (var_v0_4 & var_v1_4)
                                    {
                                      *((CollisionVec *) (&sp128)) = *((CollisionVec *) (&sp168));
                                      best_2 = temp_fv0_4;
                                    }
                                  }
                                  if (best_2 < 0.040000003f)
                                  {
                                    var_fs2 = spF0;
                                    var_s4 = var_s3_3 & 0xFFFF;
                                  }
                                }
                                }
                              }
                            }
                          }
                          var_s3_3 += 1;
                        }
                        while (((u32) (var_s3_3 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s2_2) + 0x40))->v));
                      }
                    }
                    do
                    {
                      if (var_s4 != (-1))
                      {
                        gSweepHitActor = NULL; gSweepHitObject = var_s7;
                        if (arg7 != NULL)
                        {
                          if (((Field_u8 *) (((char *) temp_s2_2) + 0x48))->v & 4)
                          {
                            tri16 = (u16 *) (((char *) inline_fn((u16 **) (((char *) temp_s2_2) + 0x3C))) + (var_s4 * 6));
                            buildPlaneFromPoints(&spF8, ((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v + (tri16[0] * 0xC), ((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v + (tri16[1] * 0xC), ((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v + (tri16[2] * 0xC));
                          }
                          else
                          {
                            tri8 = ((u8 *) inline_fn((u16 **) (((char *) temp_s2_2) + 0x3C))) + (var_s4 * 3);
                            buildPlaneFromPoints(&spF8, ((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v + (tri8[0] * 0xC), ((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v + (tri8[1] * 0xC), ((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v + (tri8[2] * 0xC));
                          }
                          *((PlaneCopy *) arg7) = *((PlaneCopy *) (&spF8));
                        }
                      }
                    }
                    while (0);
                  }
                  else
                  {
                    temp_v1_19 = ((Field_u8 *) (((char *) temp_s2_2) + 0x48))->v & 4;
                    hitIndex = -1;
                    if (temp_v1_19 != 0)
                    {
                      var_s3_5 = inline_fn((u16 **) (((char *) temp_s2_2) + 0x3C));
                      var_s4_3 = 0;
                      if (temp_s1 < ((u16) ((Field_u16 *) (((char *) temp_s2_2) + 0x40))->v))
                      {

                        do
                        {
                          temp_s1_4 = var_s4_3 & 0xFFFF;
                          if (((*((u16 *) ((temp_s1_4 * 2) + ((Field_s32 *) (((char *) temp_s2_2) + 0x38))->v))) & sp1F6) && ((*((u16 *) ((temp_s1_4 * 2) + ((Field_s32 *) (((char *) temp_s2_2) + 0x38))->v))) & sp1FE))
                          {
                            if (rayTriangleIntersectDistance(&sp58, &spE0, (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + ((*var_s3_5) * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_5[1] * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_5[2] * 0xC), &sp178) & 0xFF)
                            {
                              f32 distance = sp178; if (distance >= 0.0f)
                              {
                                if (distance < var_fs2)
                              {
                                if ((((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 0x20)
                                {
                                  if (arg3 != NULL)
                                  {
                                    ((Field_f32 *) (((char *) arg3) + 0))->v = (f32) ((Field_f32 *) (((char *) arg1) + 0))->v;
                                    ((Field_f32 *) (((char *) arg3) + 4))->v = (f32) (((Field_f32 *) (((char *) arg1) + 4))->v - distance);
                                    D_80103F00 = var_s7;
                                    ((Field_f32 *) (((char *) arg3) + 8))->v = (f32) ((Field_f32 *) (((char *) arg1) + 8))->v;
                                  }
                                }
                                else
                                {
                                  var_fs2 = distance;
                                  hitIndex = temp_s1_4;
                                }
                              }
                              }
                            }
                            else
                            {
                              temp_v1_22 = ((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17;
                              if (!(temp_v1_22 & 0x80))
                              {
                              if (!(temp_v1_22 & 0x20))
                              {
                                buildPlaneFromPoints(&spF8, (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + ((*var_s3_5) * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_5[1] * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_5[2] * 0xC));
                                if (spFC > 0.5f)
                                {
                                  temp_fv0_5 = (((spF8 * sp58) + (spFC * sp5C)) + (sp100 * sp60)) + sp104;
                                  sp178 = temp_fv0_5;
                                  if (temp_fv0_5 >= 0.0f)
                                  {
                                    if (temp_fv0_5 < var_fs2)
                                  {
                                    sp108 = sp58 - (temp_fv0_5 * spF8);
                                    sp10C = sp5C - (temp_fv0_5 * spFC);
                                    sp110 = sp60 - (temp_fv0_5 * sp100);
                                    segmentClosestPoint((CollisionVec *) sp204, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + ((*var_s3_5) * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_5[1] * 0xC)), (CollisionVec *) sp108_arg);
                                    var_fs0_3 = distanceSquared3D(sp204, sp108_arg);
                                    segmentClosestPoint((CollisionVec *) sp20C, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_5[1] * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_5[2] * 0xC)), (CollisionVec *) sp108_arg);
                                    temp_fs1_3 = distanceSquared3D(sp20C, sp108_arg);
                                    segmentClosestPoint((CollisionVec *) sp214, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_5[2] * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + ((*var_s3_5) * 0xC)), (CollisionVec *) sp108_arg);
                                    temp_fv0_6 = distanceSquared3D(sp214, sp108_arg);
                                    *((CollisionVec *) (&sp118)) = *((CollisionVec *) (&sp128));
                                    best_3 = var_fs0_3;
                                    var_v0_6 = 1;
                                    if (!(temp_fs1_3 < var_fs0_3))
                                    {
                                      var_v0_6 = 0;
                                    }
                                    var_v1_5 = 1;
                                    if (!(temp_fs1_3 < temp_fv0_6))
                                    {
                                      var_v1_5 = 0;
                                    }
                                    if (var_v0_6 & var_v1_5)
                                    {
                                      *((CollisionVec *) (&sp118)) = *((CollisionVec *) (&sp138));
                                      best_3 = temp_fs1_3;
                                    }
                                    else
                                    {
                                      var_v0_7 = 1;
                                      if (!(temp_fv0_6 < var_fs0_3))
                                      {
                                        var_v0_7 = 0;
                                      }
                                      var_v1_6 = 1;
                                      if (!(temp_fs1_3 > temp_fv0_6))
                                      {
                                        var_v1_6 = 0;
                                      }
                                      if (var_v0_7 & var_v1_6)
                                      {
                                        *((CollisionVec *) (&sp118)) = *((CollisionVec *) (&sp148));
                                        best_3 = temp_fv0_6;
                                      }
                                    }
                                    if (best_3 < 0.040000003f)
                                    {
                                      var_fs2 = sp178;
                                      hitIndex = var_s4_3 & 0xFFFF;
                                    }
                                  }
                                  }
                                }
                              }
                              }
                            }
                          }

                          var_s3_5 += 3;
                          var_s4_3 += 1;
                        }
                        while (((u32) (var_s4_3 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s2_2) + 0x40))->v));
                      }
                    }
                    else
                    {
                      var_s3_6 = (u8 *) inline_fn((u16 **) (((char *) temp_s2_2) + 0x3C));
                      var_s4_3 = 0;
                      if (var_s4_3 < ((u16) ((Field_u16 *) (((char *) temp_s2_2) + 0x40))->v))
                      {
                        sp234 = &sp180;

                        do
                        {
                          temp_s1_5 = var_s4_3;
                          if (((*((u16 *) ((temp_s1_5 * 2) + ((Field_s32 *) (((char *) temp_s2_2) + 0x38))->v))) & sp1F6) && ((*((u16 *) ((temp_s1_5 * 2) + ((Field_s32 *) (((char *) temp_s2_2) + 0x38))->v))) & sp1FE))
                          {
                            if (rayTriangleIntersectDistance(&sp58, &spE0, (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + ((*var_s3_6) * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_6[1] * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_6[2] * 0xC), &sp178) & 0xFF)
                            {
                              f32 distance = sp178; if (distance >= 0.0f)
                              {
                                if (distance < var_fs2)
                              {
                                if ((((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17) & 0x20)
                                {
                                  if (arg3 != NULL)
                                  {
                                    *((f32 *) (((char *) arg3) - (-0))) = (f32) ((Field_f32 *) (((char *) arg1) + 0))->v;
                                    ((Field_f32 *) (((char *) arg3) + 4))->v = (f32) (((Field_f32 *) (((char *) arg1) + 4))->v - distance);
                                    D_80103F00 = var_s7;
                                    ((Field_f32 *) (((char *) arg3) + 8))->v = (f32) ((Field_f32 *) (((char *) arg1) + 8))->v;
                                  }
                                }
                                else
                                {
                                  var_fs2 = distance;
                                  hitIndex = temp_s1_5;
                                }
                              }
                              }
                            }
                            else
                            {
                              temp_v1_29 = ((u32) ((Field_u32 *) (((char *) var_s7) + 0x5C))->v) >> 0x17;
                              if (!(temp_v1_29 & 0x80))
                              {
                              if (!(temp_v1_29 & 0x20))
                              {
                                buildPlaneFromPoints(&spF8, (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + ((*var_s3_6) * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_6[1] * 0xC), (((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_6[2] * 0xC));
                                if (spFC > 0.5f)
                                {
                                  temp_fv0_7 = (((spF8 * sp58) + (spFC * sp5C)) + (sp100 * sp60)) + sp104;
                                  sp178 = temp_fv0_7;
                                  if (temp_fv0_7 >= 0.0f)
                                  {
                                    if (temp_fv0_7 < var_fs2)
                                  {
                                    sp118 = sp58 - (temp_fv0_7 * spF8);
                                    sp11C = sp5C - (temp_fv0_7 * spFC);
                                    sp120 = sp60 - (temp_fv0_7 * sp100);
                                    segmentClosestPoint((CollisionVec *) sp20C, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + ((*var_s3_6) * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_6[1] * 0xC)), (CollisionVec *) sp118_arg);
                                    var_fs0_4 = distanceSquared3D(sp20C, sp118_arg);
                                    segmentClosestPoint((CollisionVec *) sp214, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_6[1] * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_6[2] * 0xC)), (CollisionVec *) sp118_arg);
                                    temp_fs1_4 = distanceSquared3D(sp214, sp118_arg);
                                    segmentClosestPoint((CollisionVec *) sp234, (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + (var_s3_6[2] * 0xC)), (CollisionVec *) ((((Field_s32 *) (((char *) temp_s2_2) + 0x34))->v) + ((*var_s3_6) * 0xC)), (CollisionVec *) sp118_arg);
                                    temp_fv0_8 = distanceSquared3D(sp234, sp118_arg);
                                    *((CollisionVec *) (&sp128)) = *((CollisionVec *) (&sp138));
                                    best_4 = var_fs0_4;
                                    var_v0_8 = 1;
                                    if (!(temp_fs1_4 < var_fs0_4))
                                    {
                                      var_v0_8 = 0;
                                    }
                                    var_v1_7 = 1;
                                    if (!(temp_fs1_4 < temp_fv0_8))
                                    {
                                      var_v1_7 = 0;
                                    }
                                    if (var_v0_8 & var_v1_7)
                                    {
                                      *((CollisionVec *) (&sp128)) = *((CollisionVec *) (&sp148));
                                      best_4 = temp_fs1_4;
                                    }
                                    else
                                    {
                                      var_v0_9 = 1;
                                      if (!(temp_fv0_8 < var_fs0_4))
                                      {
                                        var_v0_9 = 0;
                                      }
                                      var_v1_8 = 1;
                                      if (!(temp_fv0_8 < temp_fs1_4))
                                      {
                                        var_v1_8 = 0;
                                      }
                                      if (var_v0_9 & var_v1_8)
                                      {
                                        *((CollisionVec *) (&sp128)) = *((CollisionVec *) (&sp180));
                                        best_4 = temp_fv0_8;
                                      }
                                    }
                                    if (best_4 < 0.040000003f)
                                    {
                                      var_fs2 = sp178;
                                      hitIndex = var_s4_3;
                                    }
                                  }
                                  }
                                }
                              }
                              }
                            }
                          }
                          var_s3_6 += 3;
                          ++var_s4_3;

                        }
                        while (var_s4_3 < ((u16) ((Field_u16 *) (((char *) temp_s2_2) + 0x40))->v));
                      }
                    }
                    if (hitIndex != (-1))
                    {
                      block_199:
                      gSweepHitActor = NULL;
                      gSweepHitObject = var_s7;
                    }
                  }
                }
              }
            }
          }
          var_s7 = *((void ***) (((char *) var_s7) + 0x14));
        }
        while (var_s7 != NULL);
      }
      if (sp1AC == NULL)
      {
        arg0 = NULL;
      }
      else
        if (gSweepHitActor != NULL)
      {
        arg0 = NULL;
      }
      else
        if (!(gSweepHitObject != NULL))
      {
        temp_v0_3 = raycastObjectMesh(arg0, &sp38, &sp28, &sp180);
        if (temp_v0_3 == NULL)
        {
          arg0 = NULL;
        }
        else
        {
          if (((Field_u16 *) (((char *) temp_v0_3) + 0x26))->v & 0x1000)
          {
            temp_fv1_2 = ((Field_f32 *) (((char *) arg1) + 4))->v - sp184;
            var_v0_11 = 1;
            if (!(temp_fv1_2 >= 0.0f))
            {
              var_v0_11 = 0;
            }
            var_v1_10 = 1;
            if (!(temp_fv1_2 < var_fs2))
            {
              var_v1_10 = 0;
            }
            if (var_v0_11 & var_v1_10)
            {
              gSweepHitActor = NULL;
              gSweepHitObject = NULL;
              var_fs2 = temp_fv1_2;
              if (absFloat(((Field_f32 *) (((char *) temp_v0_3) + 0x10))->v) < 0.5f)
              {
                prepareLinkedObjectPair(temp_v0_3, arg1, arg0);
              }
            }
          }
          sp3C = sp184 - 0.01f;
          arg0 = *((void ***) (((char *) temp_v0_3) + 8));
        }
      }
      else
      {
        arg0 = NULL;
      }
    }
    while (arg0 != NULL);
    if (var_fs2 == arg4)
    {
      goto check;
    }
    if (gSweepHitActor == NULL)
    {
      if (arg5 != NULL)
      {
        ((Field_f32 *) (((char *) arg5) + 0))->v = 0.0f;
        ((Field_f32 *) (((char *) arg5) + 4))->v = 0.0f;
        ((Field_f32 *) (((char *) arg5) + 8))->v = 0.0f;
        if (gSweepHitObject != NULL)
        {
          if (((Field_s32 *) (((char *) gSweepHitObject) + 0x50))->v & 0x02000000)
          {
            ((Field_f32 *) (((char *) arg5) + 0))->v = (f32) (((Field_f32 *) (((char *) arg5) + 0))->v - 0.1f);
            ((Field_f32 *) (((char *) arg5) + 4))->v = (f32) (((Field_f32 *) (((char *) arg5) + 4))->v - 0.05f);
          }
          if (((Field_s32 *) (((char *) gSweepHitObject) + 0x50))->v & 0x04000000)
          {
            ((Field_f32 *) (((char *) arg5) + 0))->v = (f32) (((Field_f32 *) (((char *) arg5) + 0))->v + 0.1f);
            ((Field_f32 *) (((char *) arg5) + 4))->v = (f32) (((Field_f32 *) (((char *) arg5) + 4))->v - 0.05f);
          }
          if (((Field_s32 *) (((char *) gSweepHitObject) + 0x50))->v & 0x08000000)
          {
            ((Field_f32 *) (((char *) arg5) + 8))->v = (f32) (((Field_f32 *) (((char *) arg5) + 8))->v - 0.1f);
            ((Field_f32 *) (((char *) arg5) + 4))->v = (f32) (((Field_f32 *) (((char *) arg5) + 4))->v - 0.05f);
          }
          if (((Field_s32 *) (((char *) gSweepHitObject) + 0x50))->v & 0x10000000)
          {
            ((Field_f32 *) (((char *) arg5) + 8))->v = (f32) (((Field_f32 *) (((char *) arg5) + 8))->v + 0.1f);
            ((Field_f32 *) (((char *) arg5) + 4))->v = (f32) (((Field_f32 *) (((char *) arg5) + 4))->v - 0.05f);
          }
        }
      }
      do
      {
        if (arg6 != NULL)
        {
          ((Field_f32 *) (((char *) arg6) + 0))->v = 0.0f;
          ((Field_f32 *) (((char *) arg6) + 4))->v = 0.0f;
          ((Field_f32 *) (((char *) arg6) + 8))->v = 0.0f;
        }
      }
      while (0);
      ((Field_f32 *) (((char *) arg2) + 0))->v = (f32) ((Field_f32 *) (((char *) arg1) + 0))->v;
      ((Field_f32 *) (((char *) arg2) + 4))->v = (f32) (((Field_f32 *) (((char *) arg1) + 4))->v - var_fs2);
      ((Field_f32 *) (((char *) arg2) + 8))->v = (f32) ((Field_f32 *) (((char *) arg1) + 8))->v;
      goto __shared_return_1;

    }
    sp180 = ((Field_f32 *) (((char *) gSweepHitActor) + 0x3C))->v - ((Field_f32 *) (((char *) gSweepHitActor) + 0x48))->v;
    sp184 = ((Field_f32 *) (((char *) gSweepHitActor) + 0x40))->v - ((Field_f32 *) (((char *) gSweepHitActor) + 0x4C))->v;
    sp188 = ((Field_f32 *) (((char *) gSweepHitActor) + 0x44))->v - ((Field_f32 *) (((char *) gSweepHitActor) + 0x50))->v;
    ((Field_f32 *) (((char *) arg2) + 0))->v = (f32) ((Field_f32 *) (((char *) arg1) + 0))->v;
    ((Field_f32 *) (((char *) arg2) + 4))->v = (f32) (((Field_f32 *) (((char *) arg1) + 4))->v - var_fs2);
    ((Field_f32 *) (((char *) arg2) + 8))->v = (f32) ((Field_f32 *) (((char *) arg1) + 8))->v;
    if (arg5 != NULL)
    {
      spB8 = sp18;
      spBC = sp1C;
      spC0 = sp20;
      sp98 = (s16) ((s32) ((Field_f32 *) (((char *) gSweepHitActor) + 0x3C))->v);
      sp9A = (s16) ((s32) ((Field_f32 *) (((char *) gSweepHitActor) + 0x40))->v);
      sp9C = (s16) ((s32) ((Field_f32 *) (((char *) gSweepHitActor) + 0x44))->v);
      buildRotationMatrixS16(&sp98, matrix);
      multiplyMat3ByVec3((s32 *) matrix, &spB8, &spC8);
      sp98 = (s16) ((s32) (((Field_f32 *) (((char *) gSweepHitActor) + 0x3C))->v + sp180));
      sp9A = (s16) ((s32) (((Field_f32 *) (((char *) gSweepHitActor) + 0x40))->v + sp184));
      sp9C = (s16) ((s32) (((Field_f32 *) (((char *) gSweepHitActor) + 0x44))->v + sp188));
      buildRotationMatrixS16(&sp98, matrix);
      multiplyMat3ByVec3((s32 *) matrix, &spB8, &spD8);
      temp_ft1 = ((Field_f32 *) (((char *) gSweepHitActor) + 0x24))->v - ((Field_f32 *) (((char *) gSweepHitActor) + 0x30))->v;
      spF8 = temp_ft1;
      spFC = ((Field_f32 *) (((char *) gSweepHitActor) + 0x28))->v - ((Field_f32 *) (((char *) gSweepHitActor) + 0x34))->v;
      sp100 = ((Field_f32 *) (((char *) gSweepHitActor) + 0x2C))->v - ((Field_f32 *) (((char *) gSweepHitActor) + 0x38))->v;
      ((Field_f32 *) (((char *) arg5) + 0))->v = (f32) (temp_ft1 + (spD8 - spC8));
      ((Field_f32 *) (((char *) arg5) + 4))->v = (f32) (spFC + (spDC - spCC));
      ((Field_f32 *) (((char *) arg5) + 8))->v = (f32) (sp100 + (stack_spD8[2] - spD0));
    }
    if (arg6 != NULL)
    {
      ((Field_f32 *) (((char *) arg6) + 0))->v = sp180;
      ((Field_f32 *) (((char *) arg6) + 4))->v = sp184;
      ((Field_f32 *) (((char *) arg6) + 8))->v = sp188;
      goto __shared_return_1;
    }
    goto __shared_return_1;
  }
  check:
  if (found == NULL)
  {
    ret0:
    return 0;
  }
  *((CollisionVec *) arg2) = *((CollisionVec *) (&sp28));
  __shared_return_1:
    return 1;

}



