#define spB0Buf bbox.lower
    #define spC0Buf bbox.upper
s32 sphereContainsPoint(void *, void *, f32);
f32 absFloat(f32);
s32 applyObjectRotation(void *, f32 *, s32 *);
s32 buildPlaneFromPoints(f32 *, void *, void *, void *);
s32 buildRotationMatrix(s16 *, s32 *);
s32 buildRotationMatrixS16(s16 *, f32 *);
f32 distanceXZ(void *, void *);
s32 vec3NormalizeLength(f32 *, f32 *);
s32 isPointOutsideActorSphere(void *, void *, f32);
s32 computeGridCellMask(void *, f32 *, f32 *);
s32 rotateVec3InPlaceByMat3(s32 *, f32 *);
s32 rotateVec3ByMat3(s32 *, f32 *);
s32 triangleContainsPoint(void *, void *, void *, void *, f32 *);
extern f64 kActorPushRadiusScale;
extern void *gReferenceActor;
extern void *gSweepHitActor;
extern u16 gSurfaceQueryStamp;
typedef struct 
{
  f32 __repair_v[3];
} __repair_vec3;
typedef struct 
{
  void *field_0;
  unsigned char pad_4[32];
  float field_24;
  float field_28;
  float field_2C;
  unsigned char pad_30[12];
  float field_3C;
  float field_40;
  float field_44;
  unsigned char pad_48[16];
  int field_58;
  int field_5C;
  int field_60;
  unsigned char pad_64[12];
  void *field_70;
  unsigned char pad_74[4];
  unsigned short field_78;
} __repair_record_var_s0_2;
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
/* Sweeps a sphere (radius arg5) at arg3 against nearby actors and scene objects: pushes overlapping actors apart, then collides with object meshes triangle by triangle. It moves the position out of penetration, records the hit actor and surface flags, and returns nonzero on a hit. */ s8 sweepActorCollision(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, f32 arg5, f32 arg6, f32 arg7, s32 arg8, s32 *arg9, void **arg10, void **arg11)
{
  u16 *__base_gSurfaceQueryStamp;
  f32 sp18Buf[3];
  f32 sp28Buf[3];
  s32 sp38[6];
  s32 sp50[6];
  union 
  {
    f32 matrix[9];
    struct 
    {
      f32 pad[4];
      f32 first[3];
      f32 gap;
      f32 second[3];
    } points;
  } geometry;
  union 
  {
    s16 angles[3];
    f32 data[6];
  } workspace;
  struct 
  {
    f32 lower[3];
    f32 pad;
    f32 upper[3];
  } bbox;
  f32 spD0Buf[3];
  void *temp_s3_3;
  u8 spF7;
  void *spFC;
  void *sp104;
  f32 sp10C;
  f32 *sp114;
  register s16 *sp11C;
  s32 *sp124;
  u16 sp12E;
  s32 temp_v1_16;
  s32 rowIndex;
  s32 __repair_phase_temp_v1_16;
  u16 sp136;
  f32 *sp13C;
  s8 sp147;
  u16 *var_s6;
  void *sp14C;
  f32 *sp154;
  f32 *sp15C;
  f32 temp_fa0;
  f32 temp_fa0_2;
  f32 temp_fa0_4;
  f32 temp_fs0;
  f32 temp_fs0_2;
  register f32 temp_fa0_3;
  f32 temp_fs2;
  long long temp_v1_8;
  f32 temp_ft0_2;
  f32 temp_ft1;
  f32 temp_ft1_2;
  f32 temp_ft1_3;
  f32 temp_ft1_4;
  f32 temp_fv0;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f32 temp_fv0_4;
  f32 temp_fv0_5;
  f32 temp_fv0_6;
  f32 temp_fv0_7;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  f32 temp_fv1_4;
  f32 temp_fv1_5;
  f32 temp_fv1_6;
  f32 var_ft0;
  f32 var_ft1;
  s32 temp_a0_2;
  s32 hit;
  s32 temp_a3;
  
  s32 temp_v0;
  s32 temp_v0_2;
  s32 temp_v0_3;
  u16 sp166;
  s32 temp_v1_4;
  s32 temp_v1_5;
  s32 temp_v1_7;
  f32 temp_ft0;
  s32 temp_v1_9;
  u16 var_s4;
  u16 var_s4_2;
  u16 var_s6_3;
  u16 var_s6_4;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v1_2;
  s32 var_v1_3;
  u16 sp16E;
  u8 *var_s6_2;
  s32 temp_a0;
  s32 var_v1;
  u16 temp_v1;
  s32 temp_v1_13;
  u16 temp_v1_15;
  int temp_v1_3;
  int temp_v1_6;
  register u32 temp_s1_2;
  u32 temp_v1_12;
  u32 temp_v1_14;
  u32 temp_v1_2;
  void *temp_a2;
  void *temp_a2_2;
  void *temp_s0;
  void *temp_s0_2;
  void *temp_s1;
  void *temp_s1_3;
  void *temp_s1_4;
  void *temp_s3_2;
  void *var_fp;
  void *temp_s4;
  void *var_s0;
  void *var_s0_2;
  void *var_s2;
  void *var_s3;
  var_s0 = arg1;
  spF7 = 0;
  sp104 = NULL;
  gSweepHitActor = NULL;
  gReferenceActor = NULL;
  spFC = var_s0;
  sp10C = (f32) (2.0 * (((f64) arg5) * kActorPushRadiusScale));
  if (var_s0 == NULL)
  {
    return 0;
  }
  sp114 = &sp28Buf[0];
  sp11C = &workspace.angles[0];
  var_fp = *((void **) (((char *) (*((void **) (((char *) var_s0) + 0x20)))) + 0x58));
  sp124 = sp38;
  __base_gSurfaceQueryStamp = &gSurfaceQueryStamp;
  *__base_gSurfaceQueryStamp += 1;
  do {
  var_s2 = var_s0;

  *((u16 *) (((char *) (*((void **) (((char *) var_s0) + 0x20)))) + 0x60)) = (u16) (*__base_gSurfaceQueryStamp);
  if (var_s0 != NULL)
  {
    var_s0_2 = *((void **) (((char *) var_s0) + 0));
    if (var_s0_2 != NULL)
    {
      sp13C = &workspace.data[2];
      do
      {
        if ((var_s0_2 != arg0) && (((__repair_record_var_s0_2 *) var_s0_2)->field_5C & 0x200))
        {
          var_s3 = ((__repair_record_var_s0_2 *) var_s0_2)->field_58 & 0x400;
          if (var_s3 != 0)
          {
            if (((((Field_s32 *) (((char *) arg0) + 0x58))->v & 0x400) && (((Field_s32 *) (((char *) arg0) + 0x5C))->v & 0x200)) && (absFloat(((Field_f32 *) (((char *) arg3) + 4))->v - ((__repair_record_var_s0_2 *) var_s0_2)->field_28) < 1.5f))
            {
              temp_fv0 = distanceXZ(var_s0_2 + 0x24, arg3);
              var_v0 = 1;
              if (!(temp_fv0 < sp10C))
              {
                var_v0 = 0;
              }
              var_v1 = 1;
              if (temp_fv0 == 0.0f)
              {
                var_v1 = 0;
              }
              if (var_v0 & var_v1)
              {
                sp18Buf[0] = ((Field_f32 *) (((char *) arg3) + 0))->v - ((__repair_record_var_s0_2 *) var_s0_2)->field_24;
                sp18Buf[1] = 0.0f;
                sp18Buf[2] = ((Field_f32 *) (((char *) arg3) + 8))->v - ((__repair_record_var_s0_2 *) var_s0_2)->field_2C;
                vec3NormalizeLength(&sp18Buf[0], &sp18Buf[0]);
                temp_v1 = ((__repair_record_var_s0_2 *) var_s0_2)->field_78;
                temp_fs0 = sp10C - temp_fv0;
                if (temp_v1 == 1)
                {
                  var_ft0 = temp_fs0;
                  if (((Field_u16 *) (((char *) arg0) + 0x78))->v == temp_v1)
                  {
                    var_ft0 = temp_fs0 * 0.75f;
                    ((__repair_record_var_s0_2 *) var_s0_2)->field_58 = (s32) (((__repair_record_var_s0_2 *) var_s0_2)->field_58 | 1);
                    ((__repair_record_var_s0_2 *) var_s0_2)->field_60 = (s32) (((__repair_record_var_s0_2 *) var_s0_2)->field_60 | 0x01000000);
                    var_ft1 = temp_fs0 * 0.25f;
                  }
                  else
                  {
                    goto block_21;
                  }
                }
                else
                {
                  var_ft0 = temp_fs0;
                  block_21:
                  var_ft1 = 0.0f;

                }
                ((Field_f32 *) (((char *) arg3) + 0))->v = (f32) (((Field_f32 *) (((char *) arg3) + 0))->v + (sp18Buf[0] * var_ft0));
                ((Field_f32 *) (((char *) arg3) + 8))->v = (f32) (((Field_f32 *) (((char *) arg3) + 8))->v + (sp18Buf[2] * var_ft0));
                ((__repair_record_var_s0_2 *) var_s0_2)->field_24 = (f32) (((__repair_record_var_s0_2 *) var_s0_2)->field_24 - (sp18Buf[0] * var_ft1));
                spF7 = 1;
                ((__repair_record_var_s0_2 *) var_s0_2)->field_2C = (f32) (((__repair_record_var_s0_2 *) var_s0_2)->field_2C - (sp18Buf[2] * var_ft1));
              }
            }
          }
          else
          {
            temp_s1 = ((__repair_record_var_s0_2 *) var_s0_2)->field_70;
            if ((isPointOutsideActorSphere(var_s0_2, arg3, arg5) << 0x18) != 0)
            {
              *((__repair_vec3 *) sp28Buf) = *((__repair_vec3 *) arg3);
              workspace.angles[0] = (s16) ((s32) (-((__repair_record_var_s0_2 *) var_s0_2)->field_3C));
              workspace.angles[1] = (s16) ((s32) (-((__repair_record_var_s0_2 *) var_s0_2)->field_40));
              workspace.angles[2] = (s16) ((s32) (-((__repair_record_var_s0_2 *) var_s0_2)->field_44));
              buildRotationMatrix(sp11C, sp124);
              sp28Buf[0] -= ((__repair_record_var_s0_2 *) var_s0_2)->field_24;
              sp28Buf[1] -= ((__repair_record_var_s0_2 *) var_s0_2)->field_28;
              sp28Buf[2] -= ((__repair_record_var_s0_2 *) var_s0_2)->field_2C;
              rotateVec3ByMat3(sp124, sp114);
              if ((((((((Field_f32 *) (((char *) temp_s1) + 0x18))->v < (sp28Buf[0] + arg5)) && ((sp28Buf[0] - arg5) < ((Field_f32 *) (((char *) temp_s1) + 0x1C))->v)) && (((Field_f32 *) (((char *) temp_s1) + 0x28))->v < (sp28Buf[2] + arg5))) && ((sp28Buf[2] - arg5) < ((Field_f32 *) (((char *) temp_s1) + 0x2C))->v)) && (((Field_f32 *) (((char *) temp_s1) + 0x20))->v < (sp28Buf[1] + arg5))) && ((sp28Buf[1] - arg5) < ((Field_f32 *) (((char *) temp_s1) + 0x24))->v))
              {
                *((__repair_vec3 *) spC0Buf) = *((__repair_vec3 *) sp28Buf);
                *((__repair_vec3 *) spB0Buf) = *((__repair_vec3 *) spC0Buf);
                spB0Buf[0] -= arg5;
                spB0Buf[2] -= arg5;
                spC0Buf[0] += arg5;
                spC0Buf[2] += arg5;
                temp_v0 = computeGridCellMask(temp_s1 + 0x18, &spB0Buf[0], &spC0Buf[0]);
                workspace.angles[0] = (s16) ((s32) ((__repair_record_var_s0_2 *) var_s0_2)->field_3C);
                sp12E = temp_v0 & 0xFF;
                sp136 = temp_v0 & 0xFF00;
                workspace.angles[1] = (s16) ((s32) ((__repair_record_var_s0_2 *) var_s0_2)->field_40);
                gReferenceActor = var_s0_2;
                workspace.angles[2] = (s16) ((s32) ((__repair_record_var_s0_2 *) var_s0_2)->field_44);
                buildRotationMatrixS16(sp11C, geometry.matrix);
                temp_v1_2 = ((Field_u8 *) (((char *) temp_s1) + 0x48))->v & 4;
                if (temp_v1_2 != 0)
                {
                  var_s6 = *((u16 **) (((char *) temp_s1) + 0x3C));
                  var_s4 = 0;
                  if (var_s3 < ((u16) ((Field_u16 *) (((char *) temp_s1) + 0x40))->v))
                  {
                    var_s3 = var_s6 + 2;
                    __repair_rows:
                    {
                      temp_v1_3 = *((u16 *) (((char *) (*((void **) (((char *) temp_s1) + 0x38)))) + ((var_s4 & 0xFFFF) * 2)));
                      if ((sp12E & temp_v1_3) && (sp136 & temp_v1_3))
                      {
                        temp_v1_4 = ((Field_s32 *) (((char *) temp_s1) + 0x34))->v;
                        buildPlaneFromPoints(sp13C, temp_v1_4 + ((*var_s6) * 0xC), temp_v1_4 + ((*((u16 *) (((char *) var_s3) + (-2)))) * 0xC), temp_v1_4 + (((Field_u16 *) (((char *) var_s3) + 0))->v * 0xC));
                        var_v0_2 = 1;
                        do { temp_fs0_2 = (((workspace.data[2] * sp28Buf[0]) + (workspace.data[3] * sp28Buf[1])) + (workspace.data[4] * sp28Buf[2])) + workspace.data[5]; } while (0);
                        if (!(temp_fs0_2 < arg5))
                        {
                          var_v0_2 = 0;
                        }
                        var_v1_2 = 1;
                        if (!(temp_fs0_2 > 0.0f))
                        {
                          var_v1_2 = 0;
                        }
                        if (var_v0_2 & var_v1_2)
                        {
                          ((Field_f32 *) (((char *) arg4) + 0))->v = (f32) (sp28Buf[0] - (temp_fs0_2 * workspace.data[2]));
                          ((Field_f32 *) (((char *) arg4) + 4))->v = (f32) (sp28Buf[1] - (temp_fs0_2 * workspace.data[3]));
                          ((Field_f32 *) (((char *) arg4) + 8))->v = (f32) (sp28Buf[2] - (temp_fs0_2 * workspace.data[4]));
do { hit = triangleContainsPoint(arg4, ((Field_s32 *) (((char *) temp_s1) + 0x34))->v + ((*var_s6) * 0xC), ((Field_s32 *) (((char *) temp_s1) + 0x34))->v + ((*((u16 *) (((char *) var_s3) + (-2)))) * 0xC), ((Field_s32 *) (((char *) temp_s1) + 0x34))->v + (((Field_u16 *) (((char *) var_s3) + 0))->v * 0xC), sp13C); } while (0); if ((hit << 0x18) != 0)
                          {
                            do { temp_fa0 = arg5 - temp_fs0_2;
                            temp_ft1 = temp_fa0 * workspace.data[2];
                            temp_ft0 = temp_fa0 * workspace.data[3];
                            temp_fv0_2 = temp_fa0 * workspace.data[4];
                            sp18Buf[0] = temp_ft1;
                            sp18Buf[1] = temp_ft0;
                            sp18Buf[2] = temp_fv0_2;
                            sp28Buf[0] += temp_ft1;
                            sp28Buf[1] += temp_ft0;
                            sp28Buf[2] += temp_fv0_2;
                            rotateVec3ByMat3((s32 *) geometry.matrix, &sp18Buf[0]);
                            ((Field_f32 *) (((char *) arg3) + 0))->v = (f32) (((Field_f32 *) (((char *) arg3) + 0))->v + sp18Buf[0]);
                            ((Field_f32 *) (((char *) arg3) + 4))->v = (f32) (((Field_f32 *) (((char *) arg3) + 4))->v + sp18Buf[1]);
                            gSweepHitActor = var_s0_2;
                            sp104 = var_s2;
                            spF7 = 1;
                            ((Field_f32 *) (((char *) arg3) + 8))->v = (f32) (((Field_f32 *) (((char *) arg3) + 8))->v + sp18Buf[2]); } while (0);
                          }
                        }
                      }
                      var_s3 += 6;
                    }

                    do { var_s6 += 3; var_s4 += 1; if (((u32) (var_s4 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s1) + 0x40))->v))
                    {
                      goto __repair_rows;
                    } } while (0);
                  }
                }
                else
                {
                  var_s6_2 = *((u8 **) (((char *) temp_s1) + 0x3C));
                  var_s4 = 0;
                  if (temp_v1_2 < ((u16) ((Field_u16 *) (((char *) temp_s1) + 0x40))->v))
                  {
                    var_s3 = var_s6_2 + 2;
                    do
                    {
                      temp_v1_6 = *((u16 *) (((char *) (*((void **) (((char *) temp_s1) + 0x38)))) + ((var_s4 & 0xFFFF) * 2)));
 { if ((sp12E & temp_v1_6) && (temp_v1_6 & sp136)) { temp_v1_7 = ((Field_s32 *) (((char *) temp_s1) + 0x34))->v; buildPlaneFromPoints(sp13C, temp_v1_7 + ((*var_s6_2) * 0xC), temp_v1_7 + ((*((u8 *) (((char *) var_s3) + (-1)))) * 0xC), temp_v1_7 + (((Field_u8 *) (((char *) var_s3) + 0))->v * 0xC)); temp_fs0 = (((workspace.data[2] * sp28Buf[0]) + (workspace.data[3] * sp28Buf[1])) + (workspace.data[4] * sp28Buf[2])) + workspace.data[5]; var_v0_3 = 1; if (!(temp_fs0 < arg5)) { var_v0_3 = 0; } var_v1_3 = 1; if (!(temp_fs0 > 0.0f)) { var_v1_3 = 0; } if (var_v0_3 & var_v1_3) { ((Field_f32 *) (((char *) arg4) + 0))->v = (f32) (sp28Buf[0] - (temp_fs0 * workspace.data[2])); ((Field_f32 *) (((char *) arg4) + 4))->v = (f32) (sp28Buf[1] - (temp_fs0 * workspace.data[3])); ((Field_f32 *) (((char *) arg4) + 8))->v = (f32) (sp28Buf[2] - (temp_fs0 * workspace.data[4])); if ((triangleContainsPoint(arg4, ((Field_s32 *) (((char *) temp_s1) + 0x34))->v + ((*var_s6_2) * 0xC), ((Field_s32 *) (((char *) temp_s1) + 0x34))->v + ((*((u8 *) (((char *) var_s3) + (-1)))) * 0xC), ((Field_s32 *) (((char *) temp_s1) + 0x34))->v + (((Field_u8 *) (((char *) var_s3) + 0))->v * 0xC), sp13C) << 0x18) != 0) { temp_fa0 = arg5 - temp_fs0; temp_ft1_2 = temp_fa0 * workspace.data[2]; temp_ft0_2 = temp_fa0 * workspace.data[3]; temp_fv0_3 = temp_fa0 * workspace.data[4]; sp18Buf[0] = temp_ft1_2; sp18Buf[1] = temp_ft0_2; sp18Buf[2] = temp_fv0_3; sp28Buf[0] += temp_ft1_2; sp28Buf[1] += temp_ft0_2; sp28Buf[2] += temp_fv0_3; rotateVec3ByMat3((s32 *) geometry.matrix, &sp18Buf[0]); ((Field_f32 *) (((char *) arg3) + 0))->v = (f32) (((Field_f32 *) (((char *) arg3) + 0))->v + sp18Buf[0]); ((Field_f32 *) (((char *) arg3) + 4))->v = (f32) (((Field_f32 *) (((char *) arg3) + 4))->v + sp18Buf[1]); gSweepHitActor = var_s0_2; sp104 = var_s2; spF7 = 1; ((Field_f32 *) (((char *) arg3) + 8))->v = (f32) (((Field_f32 *) (((char *) arg3) + 8))->v + sp18Buf[2]); } } var_s3 += 3; } else { var_s3 += 3; } }
                      var_s6_2 += 3;
                      var_s4 += 1;
                    }
                    while (((u32) (var_s4 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s1) + 0x40))->v));
                  }
                }
              }
            }
          }
        }
        var_s0_2 = ((__repair_record_var_s0_2 *) var_s0_2)->field_0;
      }
      while (var_s0_2 != NULL);
    }
  }
  sp147 = 1;
  sp14C = var_s2;
  sp154 = &geometry.points.first[0];
  sp15C = &geometry.points.second[0];
  for (;;)
  {
    temp_v0_2 = var_s2 != NULL;
    var_s2 = sp14C;
    if (sp147 & temp_v0_2)
    {
      var_s2 = *((void **) (((char *) var_s2) + 0x14));
    }
    if (var_s2 != NULL)
    {
      for (;;)
      {
        temp_v1_9 = ((Field_s32 *) (((char *) var_s2) + 0x50))->v;
        temp_s4 = *((void **) (((char *) var_s2) + 0x3C));
        if (!(temp_v1_9 & 0x20000000))
        {
          if (temp_v1_9 & 0x200)
          {
            temp_s1_2 = (((u32) ((Field_u32 *) (((char *) var_s2) + 0x5C))->v) >> 0x17) & 0x20;
            if ((temp_s1_2 == 0) && ((sphereContainsPoint(var_s2 + 0x40, arg3, arg5) << 0x18) != 0))
            {
              *((__repair_vec3 *) geometry.points.first) = *((__repair_vec3 *) arg3);
              *((__repair_vec3 *) geometry.points.second) = *((__repair_vec3 *) arg2);
              if ((((u32) ((Field_u32 *) (((char *) var_s2) + 0x5C))->v) >> 0x17) & 1)
              {
                {
                  geometry.points.first[0] -= ((Field_f32 *) (((char *) var_s2) + 0x24))->v;
                }
                geometry.points.first[1] -= ((Field_f32 *) (((char *) var_s2) + 0x28))->v;
                geometry.points.first[2] -= ((Field_f32 *) (((char *) var_s2) + 0x2C))->v;
                geometry.points.second[0] -= ((Field_f32 *) (((char *) var_s2) + 0x24))->v;
                geometry.points.second[1] -= ((Field_f32 *) (((char *) var_s2) + 0x28))->v;
                geometry.points.second[2] -= ((Field_f32 *) (((char *) var_s2) + 0x2C))->v;
              }
              if ((((u32) ((Field_u32 *) (((char *) var_s2) + 0x5C))->v) >> 0x17) & 2)
              {
                applyObjectRotation(var_s2, &sp28Buf[0], sp50);
                rotateVec3InPlaceByMat3(sp50, sp154);
                rotateVec3InPlaceByMat3(sp50, sp15C);
              }
              if ((((((((Field_f32 *) (((char *) temp_s4) + 0x18))->v < (geometry.points.first[0] + arg5)) && ((geometry.points.first[0] - arg5) < ((Field_f32 *) (((char *) temp_s4) + 0x1C))->v)) && (((Field_f32 *) (((char *) temp_s4) + 0x28))->v < (geometry.points.first[2] + arg5))) && ((geometry.points.first[2] - arg5) < ((Field_f32 *) (((char *) temp_s4) + 0x2C))->v)) && (((Field_f32 *) (((char *) temp_s4) + 0x20))->v < (geometry.points.first[1] + arg5))) && ((geometry.points.first[1] - arg5) < ((Field_f32 *) (((char *) temp_s4) + 0x24))->v))
              {
                f32 *lower;
                temp_fs2 = geometry.points.first[1];
                lower = &workspace.data[4];
                *((__repair_vec3 *) spD0Buf) = *((__repair_vec3 *) geometry.points.first);
                *((__repair_vec3 *) lower) = *((__repair_vec3 *) spD0Buf);
                lower[0] -= arg5;
                lower[2] -= arg5;
                spD0Buf[0] += arg5;
                spD0Buf[2] += arg5;
                temp_v0_3 = computeGridCellMask(temp_s4 + 0x18, lower, spD0Buf);
                sp166 = temp_v0_3 & 0xFF;
                sp16E = temp_v0_3 & 0xFF00;
                temp_v1_2 = ((Field_u8 *) (((char *) temp_s4) + 0x48))->v & 4;
                if (temp_v1_2 != 0)
                {
                  {
                    var_s6_3 = 0;
                    if (var_s6_3 < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v))
                    {
                      do
                      {
                        temp_a2 = (void *) ((Field_s32 *) (((char *) temp_s4) + 0x3C))->v; rowIndex = var_s6_3; temp_a2 = (char *) temp_a2 + (rowIndex * 6); temp_a0 = *((u16 *) (((char *) (*((void **) (((char *) temp_s4) + 0x38)))) + (rowIndex * 2)));
                        if ((sp166 & temp_a0) && (temp_a0 & sp16E))
                        {
                          temp_a3 = ((Field_s32 *) (((char *) temp_s4) + 0x34))->v; temp_s3_2 = temp_a3 + (((Field_u16 *) (((char *) temp_a2) + 0))->v * 0xC); temp_s1_3 = temp_a3 + (((Field_u16 *) (((char *) temp_a2) + 2))->v * 0xC); temp_s0 = temp_a3 + (((Field_u16 *) (((char *) temp_a2) + 4))->v * 0xC);
                          buildPlaneFromPoints(workspace.data, temp_s3_2, temp_s1_3, temp_s0);
                          if ((((Field_f32 *) (((char *) var_s2) + 0x30))->v == 0.0f) && (((Field_f32 *) (((char *) var_s2) + 0x38))->v == 0.0f))
                          {
                            temp_fv1 = ((((Field_f32 *) (((char *) temp_s3_2) + 4))->v + ((Field_f32 *) (((char *) temp_s1_3) + 4))->v) + ((Field_f32 *) (((char *) temp_s0) + 4))->v) * 0.33333334f; temp_fv0_4 = temp_fs2 - arg6; geometry.points.first[1] = temp_fv1;
                            if (temp_fv1 < temp_fv0_4)
                            {
                              geometry.points.first[1] = temp_fv0_4;
                            }
                            temp_fv1_2 = temp_fs2 + arg7;
                            if (temp_fv1_2 < geometry.points.first[1])
                            {
                              geometry.points.first[1] = temp_fv1_2;
                            }
                          }
                          if ((workspace.data[1] < 0.5f) || ((((u32) ((Field_u32 *) (((char *) var_s2) + 0x5C))->v) >> 0x17) & 2))
                          {
                            temp_fs0 = (((workspace.data[0] * geometry.points.first[0]) + (workspace.data[1] * geometry.points.first[1])) + (workspace.data[2] * geometry.points.first[2])) + workspace.data[3];
                            if (temp_fs0 < arg5)
                            {
                              ((Field_f32 *) (((char *) arg4) + 0))->v = (f32) (geometry.points.first[0] - (temp_fs0 * workspace.data[0]));
                              ((Field_f32 *) (((char *) arg4) + 4))->v = (f32) (geometry.points.first[1] - (temp_fs0 * workspace.data[1]));
                              ((Field_f32 *) (((char *) arg4) + 8))->v = (f32) (geometry.points.first[2] - (temp_fs0 * workspace.data[2]));
                              if ((triangleContainsPoint(arg4, temp_s3_2, temp_s1_3, temp_s0, (f32 *) sp11C) << 0x18) != 0)
                              {
                                if (1)
                                {
                                  if (temp_fs0 < 0.0f)
                                  {
                                  if (((((workspace.data[0] * geometry.points.second[0]) + (workspace.data[1] * geometry.points.second[1])) + (workspace.data[2] * geometry.points.second[2])) + workspace.data[3]) > 0.0f)
                                  {
                                    *((__repair_vec3 *) (((s8 *) arg3) + 0)) = *((__repair_vec3 *) (((s8 *) arg2) + 0));
                                    return 1;
                                  }
                                  }
                                  else
                                  {
                                    temp_fa0 = arg5 - temp_fs0; temp_ft1_3 = temp_fa0 * workspace.data[0]; temp_fv1_3 = temp_fa0 * workspace.data[1]; temp_fv0_5 = temp_fa0 * workspace.data[2]; sp18Buf[0] = temp_ft1_3; sp18Buf[1] = temp_fv1_3; sp18Buf[2] = temp_fv0_5; geometry.points.first[0] += temp_ft1_3; geometry.points.first[1] += temp_fv1_3; geometry.points.first[2] += temp_fv0_5;
                                    if ((((u32) ((Field_u32 *) (((char *) var_s2) + 0x5C))->v) >> 0x17) & 2)
                                    {
                                      rotateVec3InPlaceByMat3((s32 *) (&sp28Buf[0]), &sp18Buf[0]);
                                    }
                                    ((Field_f32 *) (((char *) arg3) + 0))->v = (f32) (((Field_f32 *) (((char *) arg3) + 0))->v + sp18Buf[0]);
                                    ((Field_f32 *) (((char *) arg3) + 4))->v = (f32) (((Field_f32 *) (((char *) arg3) + 4))->v + sp18Buf[1]);
                                    ((Field_f32 *) (((char *) arg3) + 8))->v = (f32) (((Field_f32 *) (((char *) arg3) + 8))->v + sp18Buf[2]); temp_v1_12 = ((Field_u32 *) (((char *) var_s2) + 0x5C))->v;
                                    if (temp_v1_12 & 0x7E0000)
                                    {
                                      if (arg9 != NULL)
                                      {
                                        *arg9 = (temp_v1_12 >> 0x11) & 0x3F;
                                      }
                                      if (arg10 != NULL)
                                      {
                                        *arg10 = var_s2;
                                      }
                                    }
                                    spF7 = 1;
                                  }
                                  goto block_103;
                                }
                              }
                            }
                          }
                          goto block_103;
                        }
                        block_103:
                        var_s6_3 += 1;

                      }
                      while (var_s6_3 < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v));
                      goto block_133;
                    }
                  }
                  goto block_133;
                }
                {
                  var_s6_4 = 0;
                }
                if (temp_v1_2 < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v))
                {
                  for (;;)
                  {
                    temp_a2_2 = (void *) ((Field_s32 *) (((char *) temp_s4) + 0x3C))->v;
                    temp_a0_2 = var_s6_4 & 0xFFFF;
                    temp_a2_2 = (char *) temp_a2_2 + (temp_a0_2 * 3);
                    temp_v1_13 = *((u16 *) (((char *) (*((void **) (((char *) temp_s4) + 0x38)))) + (temp_a0_2 * 2)));
                    if ((sp166 & temp_v1_13) && (sp16E & temp_v1_13))
                    {
                      temp_a3 = ((Field_s32 *) (((char *) temp_s4) + 0x34))->v;
                      temp_s3_3 = temp_a3 + (((Field_u8 *) (((char *) temp_a2_2) + 0))->v * 0xC);
                      temp_s1_4 = temp_a3 + (((Field_u8 *) (((char *) temp_a2_2) + 1))->v * 0xC);
                      temp_s0_2 = temp_a3 + (((Field_u8 *) (((char *) temp_a2_2) + 2))->v * 0xC);
                      buildPlaneFromPoints(workspace.data, temp_s3_3, temp_s1_4, temp_s0_2);
                      if ((((Field_f32 *) (((char *) var_s2) + 0x30))->v == 0.0f) && (((Field_f32 *) (((char *) var_s2) + 0x38))->v == 0.0f))
                      {
                        temp_fv1_4 = ((((Field_f32 *) (((char *) temp_s3_3) + 4))->v + ((Field_f32 *) (((char *) temp_s1_4) + 4))->v) + ((Field_f32 *) (((char *) temp_s0_2) + 4))->v) * 0.33333334f;
                        temp_fv0_6 = temp_fs2 - arg6;
                        geometry.points.first[1] = temp_fv1_4;
                        if (temp_fv1_4 < temp_fv0_6)
                        {
                          geometry.points.first[1] = temp_fv0_6;
                        }
                        temp_fv1_5 = temp_fs2 + arg7;
                        if (temp_fv1_5 < geometry.points.first[1])
                        {
                          geometry.points.first[1] = temp_fv1_5;
                        }
                      }
                      if ((workspace.data[1] < 0.5f) || ((((u32) ((Field_u32 *) (((char *) var_s2) + 0x5C))->v) >> 0x17) & 2))
                      {
                        temp_fs0 = (((workspace.data[0] * geometry.points.first[0]) + (workspace.data[1] * geometry.points.first[1])) + (workspace.data[2] * geometry.points.first[2])) + workspace.data[3];
                        if (temp_fs0 < arg5)
                        {
                          ((Field_f32 *) (((char *) arg4) + 0))->v = (f32) (geometry.points.first[0] - (temp_fs0 * workspace.data[0]));
                          ((Field_f32 *) (((char *) arg4) + 4))->v = (f32) (geometry.points.first[1] - (temp_fs0 * workspace.data[1]));
                          ((Field_f32 *) (((char *) arg4) + 8))->v = (f32) (geometry.points.first[2] - (temp_fs0 * workspace.data[2]));
                          if ((triangleContainsPoint(arg4, temp_s3_3, temp_s1_4, temp_s0_2, (f32 *) sp11C) << 0x18) != 0)
                          {
                            if (temp_fs0 < 0.0f)
                            {
                            if (((((workspace.data[0] * geometry.points.second[0]) + (workspace.data[1] * geometry.points.second[1])) + (workspace.data[2] * geometry.points.second[2])) + workspace.data[3]) > 0.0f)
                            {
                              *((__repair_vec3 *) (((s8 *) arg3) + 0)) = *((__repair_vec3 *) (((s8 *) arg2) + 0));
                              return 1;
                            }
                            }
                            else
                            {
                              temp_fa0 = arg5 - temp_fs0;
                              temp_ft1_4 = temp_fa0 * workspace.data[0];
                              temp_fv1_6 = temp_fa0 * workspace.data[1];
                              temp_fv0_7 = temp_fa0 * workspace.data[2];
                              sp18Buf[0] = temp_ft1_4;
                              sp18Buf[1] = temp_fv1_6;
                              sp18Buf[2] = temp_fv0_7;
                              geometry.points.first[0] += temp_ft1_4;
                              geometry.points.first[1] += temp_fv1_6;
                              geometry.points.first[2] += temp_fv0_7;
                              if ((((u32) ((Field_u32 *) (((char *) var_s2) + 0x5C))->v) >> 0x17) & 2)
                              {
                                rotateVec3InPlaceByMat3((s32 *) (&sp28Buf[0]), &sp18Buf[0]);
                              }
                              ((Field_f32 *) (((char *) arg3) + 0))->v = (f32) (((Field_f32 *) (((char *) arg3) + 0))->v + sp18Buf[0]);
                              ((Field_f32 *) (((char *) arg3) + 4))->v = (f32) (((Field_f32 *) (((char *) arg3) + 4))->v + sp18Buf[1]);
                              ((Field_f32 *) (((char *) arg3) + 8))->v = (f32) (((Field_f32 *) (((char *) arg3) + 8))->v + sp18Buf[2]);
                              temp_v1_14 = ((Field_u32 *) (((char *) var_s2) + 0x5C))->v;
                              if (temp_v1_14 & 0x7E0000)
                              {
                                if (arg9 != NULL)
                                {
                                  *arg9 = (temp_v1_14 >> 0x11) & 0x3F;
                                }
                                if (arg10 != NULL)
                                {
                                  *arg10 = var_s2;
                                }
                              }
                              spF7 = 1;
                            }
                            goto block_132;
                          }
                        }
                      }
                      goto block_132;
                    }
                    block_132:
                    var_s6_4 += 1;

                    if (((u32) (var_s6_4 & 0xFFFF)) >= ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v))
                    {
                      goto block_133;
                    }
                    continue;
                    break;
                  }

                }
                goto block_133;
              }
              goto block_133;
            }
          }
        }
        block_133:
        if (sp147 == 0)
        {
          break;
        }

        var_s2 = *((void **) (((char *) var_s2) + 0x14));
        if (var_s2 == NULL)
        {
          goto block_135;
        }
      }

      goto block_137;
    }
    block_135:
    if (sp147 == 0)
    {
      break;
    }

    sp147 = 0;
  }

  block_137:
  {
  void *hitActor;
    void *hitActor_gc;
  hitActor = gSweepHitActor;
  if (hitActor != NULL)
  {
      hitActor_gc = hitActor;
      hitActor = NULL;
    if (arg9 != NULL)
    {
      temp_v1_15 = ((Field_u16 *) (((char *) hitActor_gc) + 0x78))->v;
      switch (temp_v1_15)
      {
        case 0xB:
          if (((u32) ((*((u8 *) (((char *) (*((void **) (((char *) hitActor_gc) + 0x6C)))) + 0x4A))) - 4)) < 2U)
        {
          *arg9 = 0x10;
        }
          break;

        case 0x3D:

        case 0x53:

        case 0xD:
          *arg9 = 0x20;
          break;

      }

    }
    if (arg11 != NULL)
    {
      *arg11 = hitActor_gc;
    }
    __repair_phase_temp_v1_16 = ((Field_s32 *) (((char *) hitActor_gc) + 0x60))->v | arg8;
    ((Field_s32 *) (((char *) hitActor_gc) + 0x60))->v = __repair_phase_temp_v1_16;
    if (sp104 == spFC)
    {
      ((Field_s32 *) (((char *) hitActor_gc) + 0x60))->v = __repair_phase_temp_v1_16 | 8;
    }
    else
    {
      ((Field_s32 *) (((char *) hitActor_gc) + 0x60))->v = __repair_phase_temp_v1_16 & (~8);
    }
  }
  }

  if (var_fp == NULL)
  {
    return (s8) spF7;
  }
  goto walk;
  next_cell:
  var_fp = *((void **) (((char *) var_fp) + 0));
  if (var_fp == NULL) continue;
  walk:
  do {
    var_s0 = *((void **) (((char *) var_fp) + 8));
    if (!((*((u16 *) (((char *) (*((void **) (((char *) var_s0) + 0x20)))) + 0x60))) == (*__base_gSurfaceQueryStamp))) {
      if (var_fp != NULL) {
      if (!((sphereContainsPoint(((Field_s32 *) (((char *) var_fp) + 4))->v + 0x40, arg3, arg5) << 0x18) != 0)) goto next_cell;
      var_fp = *((void **) (((char *) var_fp) + 0));
      break;
      } else {
        return (s8) spF7;
      }
    }
    var_fp = *((void **) (((char *) var_fp) + 0));
  } while (var_fp != NULL);
  } while (var_s0 != NULL);
  return (s8) spF7;
}
