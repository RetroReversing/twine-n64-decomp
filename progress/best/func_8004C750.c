s32 Sphere_OverlapsPoint(void **, void *, f32);
f32 absFloat(void);
s32 applyObjectRotation(void **, s32, f32 *);
s32 buildPlaneFromPoints(f32 *, s32, s32, s32);
void buildRotationMatrix(const s16 *, f32 *);
void buildRotationMatrixS16(const s16 *, f32 *);
void *func_80047B44(void **, f32 *, f32 *, f32 *);
s32 func_800487F0(void *, void *, f32);
s32 func_8004D910(f32 *, f32 *, s32, s32, s32, f32 *);
s32 func_8004E418(s32, f32 *, f32 *);
void func_800839F0(f32 *, f32 *, f32 *);
s32 func_80083B64(f32 *, f32 *);
s32 prepareLinkedObjectPair(void *, void *, void **);
s32 rayHitsTriangleXZ(f32 *, f32 *, s32, s32, s32, f32 *);
s32 rotateVec3ByMat3(f32 *, f32 *);
s32 segmentOverlapsBox(s32, f32 *, f32 *);
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} PointCopy;
extern PointCopy D_800D3E30;
extern void **D_80103F00;
extern void **D_80108F84;
extern void *gPlayerActor;
inline static f32 inline_fn(void *arg0, f32 arg1)
{
  return (f32) ((*((f32 *) (((char *) arg0) + 4))) - arg1);
}

s32 func_8004C750(void **arg0, void *arg1, void *arg2, void *arg3, f32 arg4, void *arg5, void *arg6, void *arg7)
{
  struct {
    volatile f32 sp18, sp1C, sp20;
    u32 pad24;
    f32 startPoint[3];
    u32 pad34;
    f32 endPoint[3];
    u32 pad44;
    f32 localStart[3];
    u32 pad54;
    f32 localEnd[3];
    u32 pad64;
    f32 matrix[12];
    union {
      s16 angles[3];
      f32 point[3];
      struct { f32 prefix[2]; f32 point[3]; } overlap;
    } rotationInput;
    u32 padAC;
    f32 spB0, spB4;
    f32 translation[3];
    u32 padC4;
    f32 rotatedA[3];
    u32 padD4;
    union {
      f32 rotated[3];
      struct { f32 prefix[2]; f32 point[3]; } overlap;
    } secondPoint;
    u32 padEC;
    f32 spF0;
    u32 padF4;
    f32 plane[4];
    f32 sp108;
    u32 pad10C;
    volatile f32 sp110[3];
  } scratch;
  void **sp124;
  void *sp12C;
  void *sp134;
  void *sp13C;
  void *sp144;
  f32 *sp14C;
  f32 *sp154;
  f32 *sp15C;
  f32 *sp164;
  f32 *sp16C;
  f32 *sp174;
  s32 var_s0_5;
  s16 *sp17C;
  f32 *sp184;
  u16 sp18E;
  f32 *sp194;
  u16 *var_s3;
  int sp19C;
  f32 temp_ft1;
  f32 temp_fv0;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 var_fs0;
  s32 temp_s0;
  s32 temp_s0_2;
  int temp_s2_3;
  s32 temp_s2_4;
  s32 temp_s4_2;
  s32 temp_s4_3;
  register int temp_s5;
  s32 temp_s5_2;
  register s32 temp_s7;
  s32 temp_t2;
  s32 temp_t3;
  s32 temp_v0;
  s32 temp_v0_2;
  s32 temp_v1_13;
  register s32 temp_v1_15;
  s32 temp_v1_3;
  long temp_v1_5;
  s32 temp_v1_6;
  s32 temp_v1_8;
  s32 var_a1;
  s32 var_a2;
  s32 var_s0;
  u32 var_s0_2;
  unsigned int var_s0_3;
  s32 var_s0_4;
  int var_s0_6;
  s32 var_v0_2;
  s32 var_s5;
  s32 var_s7;
  s32 var_t2;
  s32 var_t3;
  s32 var_s3_3;
  u32 var_v0_3;
  s32 var_v1;
  s32 var_v1_2;
  s32 sp198;
  u16 *var_s3_2;
  u16 *var_s3_4;
  u16 *var_s3_5;
  u16 temp_a0;
  u16 temp_v1_12;
  u16 temp_v1_14;
  register u16 temp_v1_2;
  u16 temp_v1_4;
  s32 temp_v1_7;
  u16 var_v0;
  u32 temp_s2;
  u32 temp_s2_2;
  u32 temp_v1;
  u32 temp_v1_11;
  void **var_a0;
  void **var_s6;
  void *temp_a1;
  void *temp_a1_2;
  void *temp_s1;
  void *temp_s4;
  void *temp_v0_3;
  void *temp_v1_10;
  void *temp_v1_9;
  void *var_s1;
  void *var_s2;
  void *var_s2_2;
  void *var_s2_3;
  void *var_s2_4;
  sp124 = arg0;
  sp12C = arg2;
  sp134 = arg3;
  D_80103F00 = NULL;
  gPlayerActor = NULL;
  D_80108F84 = NULL;
  var_fs0 = arg4;
  if (sp124 != NULL)
  {
    scratch.sp18 = 0.0f;
    scratch.sp1C = 0.0f;
    scratch.sp20 = 0.0f;
    *((PointCopy *) scratch.endPoint) = *((PointCopy *) arg1);
    scratch.startPoint[0] = *((f32 *) (((char *) arg1) + 0));
    sp14C = scratch.matrix;
    sp154 = &scratch.localStart[0];
    scratch.startPoint[1] = (*((f32 *) (((char *) arg1) + 4))) - var_fs0;
    sp15C = &scratch.localEnd[0];
    sp164 = scratch.rotationInput.overlap.point;
    scratch.startPoint[2] = *((f32 *) (((char *) arg1) + 8));
    do
    {
      var_s6 = sp124;
      var_a0 = sp124;
      sp13C = *((void **) (((char *) (*((void **) (((char *) sp124) + 0x20)))) + 0x58));
      sp144 = sp13C;
      if (var_a0 != NULL)
      {
        sp16C = &scratch.spB0;
        do
        {
          var_s1 = *var_a0;
          if (var_s1 != NULL)
          {
            sp174 = &scratch.spB4;
            do
            {
              if ((*((void **) (((char *) var_s1) + 0x70))) != NULL)
              {
 do { temp_s2 = (*((s32 *) (((char *) var_s1) + 0x58))) & 0x400; } while (0);
                if (((((s32) temp_s2) == 0) && ((*((s32 *) (((char *) var_s1) + 0x5C))) & 0x200)) && ((func_800487F0(var_s1, arg1, arg4) << 0x18) != 0))
                {
                  temp_s4 = *((void **) (((char *) var_s1) + 0x70));
                  scratch.rotationInput.angles[0] = (s16) ((s32) (-(*((f32 *) (((char *) var_s1) + 0x3C)))));
                  scratch.rotationInput.angles[1] = (s16) ((s32) (-(*((f32 *) (((char *) var_s1) + 0x40)))));
                  scratch.rotationInput.angles[2] = (s16) ((s32) (-(*((f32 *) (((char *) var_s1) + 0x44)))));
                  buildRotationMatrix(&scratch.rotationInput.angles[0], sp14C);
                  scratch.localStart[0] = (*((f32 *) (((char *) arg1) + 0))) - (*((f32 *) (((char *) var_s1) + 0x24)));
                  scratch.localStart[1] = (*((f32 *) (((char *) arg1) + 4))) - (*((f32 *) (((char *) var_s1) + 0x28)));
                  scratch.localStart[2] = (*((f32 *) (((char *) arg1) + 8))) - (*((f32 *) (((char *) var_s1) + 0x2C)));
                  scratch.localEnd[0] = scratch.startPoint[0] - (*((f32 *) (((char *) var_s1) + 0x24)));
                  scratch.localEnd[1] = scratch.startPoint[1] - (*((f32 *) (((char *) var_s1) + 0x28)));
                  scratch.localEnd[2] = scratch.startPoint[2] - (*((f32 *) (((char *) var_s1) + 0x2C)));
                  temp_s0 = temp_s4 + 0x18;
                  rotateVec3ByMat3(sp14C, sp154);
                  rotateVec3ByMat3(sp14C, sp15C);
                  if ((segmentOverlapsBox(temp_s0, sp154, sp15C) << 0x18) != 0)
                  {
                    *((PointCopy *) scratch.rotationInput.overlap.point) = D_800D3E30;
                    temp_v0 = func_8004E418(temp_s0, sp154, sp15C) & 0xFFFF;
                    temp_t3 = temp_v0 & 0xFF;
                    temp_t2 = temp_v0 & 0xFF00;
                    sp198 = temp_t2;
                    rotateVec3ByMat3(sp14C, sp164);
                    sp19C = temp_t3;
                    scratch.sp18 = scratch.localStart[0];
                    scratch.sp20 = scratch.localStart[2];
                    var_t3 = temp_t3;
                    var_t2 = (int) temp_t2;
                    temp_v1 = (*((u8 *) (((char *) temp_s4) + 0x48))) & 4;
                    var_s7 = -1;
                    if (temp_v1 != 0)
                    {
                      var_s3 = *((u16 **) (((char *) temp_s4) + 0x3C));
                      if (temp_s2 < ((u16) (*((u16 *) (((char *) temp_s4) + 0x40)))))
                      {
                        var_s0 = 0;
                        var_s2 = ((u8 *) var_s3) + 4;
                        do
                        {
                          temp_s5 = var_s0 & 0xFFFF;
                          temp_v1_2 = (*((u16 **) (((char *) temp_s4) + 0x38)))[temp_s5];
                          if ((var_t3 & temp_v1_2) && (var_t2 & temp_v1_2))
                          {
                            temp_v1_3 = *((s32 *) (((char *) temp_s4) + 0x34));
                            sp198 = var_t2;
                            sp19C = var_t3;
                            var_t2 = (s32) sp198;
                            var_t3 = sp19C;
                            if (((func_8004D910(&scratch.localStart[0], scratch.rotationInput.overlap.point, temp_v1_3 + ((*var_s3) * 0xC), temp_v1_3 + ((*((u16 *) (((char *) var_s2) + (-2)))) * 0xC), temp_v1_3 + ((*((u16 *) (((char *) var_s2) + 0))) * 0xC), sp16C) & 0xFF) && (scratch.spB0 >= 0.0f)) && (scratch.spB0 < var_fs0))
                            {
                              var_fs0 = scratch.spB0;
                              var_s7 = temp_s5;
                            }
                          }
                          var_s2 = (void *) (((u8 *) var_s2) + 6);
                          var_s3 = (void *) (((u8 *) var_s3) + 6);
                          var_s0 += 1;
                        }
                        while (((u32) (var_s0 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) temp_s4) + 0x40)))));
                      }
                    }
                    else
                    {
                      var_s3_2 = *((u16 **) (((char *) temp_s4) + 0x3C));
                      var_s0_2 = 0;
                      if (temp_v1 < ((u16) (*((u16 *) (((char *) temp_s4) + 0x40)))))
                      {
                        var_s2_2 = ((u8 *) ((u8 *) var_s3_2)) + 2;
                        do
                        {
                          temp_s5_2 = var_s0_2 & 0xFFFF;
                          temp_v1_4 = (*((u16 **) (((char *) temp_s4) + 0x38)))[temp_s5_2];
                          if ((var_t3 & temp_v1_4) && (var_t2 & temp_v1_4))
                          {
                            temp_v1_5 = *((s32 *) (((char *) temp_s4) + 0x34));
                            sp198 = var_t2;
                            sp19C = (unsigned) var_t3;
                            var_t2 = sp198;
                            var_t3 = sp19C;
                            if (((func_8004D910(&scratch.localStart[0], scratch.rotationInput.overlap.point, temp_v1_5 + ((*((u8 *) var_s3_2)) * 0xC), temp_v1_5 + ((*((u8 *) (((char *) var_s2_2) + (-1)))) * 0xC), temp_v1_5 + ((*((u8 *) (((char *) var_s2_2) + 0))) * 0xC), sp174) & 0xFF) && (scratch.spB4 >= 0.0f)) && (scratch.spB4 < var_fs0))
                            {
                              var_fs0 = scratch.spB4;
                              var_s7 = temp_s5_2;
                            }
                          }
                          var_s2_2 = (void *) (((u8 *) var_s2_2) + 3);
                          var_s0_2 += 1;
                          var_s3_2 = (void *) (((u8 *) var_s3_2) + 3);
                        }
                        while (((u32) (var_s0_2 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) temp_s4) + 0x40)))));
                      }
                    }
                    if (var_s7 != (-1))
                    {
                      gPlayerActor = var_s1;
                      D_80108F84 = NULL;
                      scratch.sp1C = scratch.localStart[1] - var_fs0;
                    }
                  }
                }
              }
              var_s1 = *((void **) (((char *) var_s1) + 0));
            }
            while (var_s1 != NULL);
          }
          var_a0 = (s32) NULL;
          if (sp144 != NULL)
          {
            var_a0 = *((void ***) (((char *) sp144) + 8));
            sp144 = *((void **) (((char *) sp144) + 0));
          }
        }
        while (var_a0 != NULL);
      }
      if (var_s6 != NULL)
      {
        sp184 = scratch.secondPoint.overlap.point;
        sp17C = (s16 *) scratch.rotationInput.point;
        sp194 = &scratch.sp108;
        do
        {
          if ((*((s32 *) (((char *) var_s6) + 0x50))) & 0x200)
          {
            temp_s2_2 = (((u32) (*((u32 *) (((char *) var_s6) + 0x5C)))) >> 0x17) & 4;
            if (temp_s2_2)
            {
              temp_fv1 = (*((f32 *) (((char *) arg1) + 4))) - (*((f32 *) (((char *) (*((void **) (((char *) var_s6) + 0x3C)))) + 0x20)));
              var_v0_2 = 1;
              if (!(temp_fv1 >= 0.0f))
              {
                var_v0_2 = 0;
              }
              var_v1 = 1;
              if (!(temp_fv1 < var_fs0))
              {
                var_v1 = 0;
              }
              if (var_v0_2 & var_v1)
              {
                var_fs0 = temp_fv1;
                gPlayerActor = NULL;
                D_80108F84 = var_s6;
              }
            }
            else
              if ((Sphere_OverlapsPoint(((s8 *) var_s6) + 0x40, arg1, arg4) << 0x18) != 0)
            {
              temp_s1 = *((void **) (((char *) var_s6) + 0x3C));
              *((PointCopy *) scratch.localEnd) = *((PointCopy *) arg1);
              *((PointCopy *) scratch.rotationInput.point) = *((PointCopy *) scratch.startPoint);
              if ((((u32) (*((u32 *) (((char *) var_s6) + 0x5C)))) >> 0x17) & 1)
              {
                scratch.localEnd[0] -= *((f32 *) (((char *) var_s6) + 0x24));
                scratch.localEnd[1] -= *((f32 *) (((char *) var_s6) + 0x28));
                scratch.localEnd[2] -= *((f32 *) (((char *) var_s6) + 0x2C));
                scratch.rotationInput.point[0] -= *((f32 *) (((char *) var_s6) + 0x24));
                scratch.rotationInput.point[1] -= *((f32 *) (((char *) var_s6) + 0x28));
                scratch.rotationInput.point[2] -= *((f32 *) (((char *) var_s6) + 0x2C));
              }
              if ((((u32) (*((u32 *) (((char *) var_s6) + 0x5C)))) >> 0x17) & 2)
              {
                applyObjectRotation(var_s6, 0, &scratch.translation[0]);
                func_80083B64(&scratch.translation[0], sp15C);
                func_80083B64(&scratch.translation[0], (f32 *) sp17C);
              }
              temp_s0_2 = temp_s1 + 0x18;
              if ((segmentOverlapsBox(temp_s0_2, sp15C, (f32 *) sp17C) << 0x18) != 0)
              {
                *((PointCopy *) scratch.secondPoint.overlap.point) = D_800D3E30;
                temp_v0_2 = func_8004E418(temp_s0_2, sp15C, (f32 *) sp17C);
                temp_s7 = temp_v0_2 & 0xFF00;
                sp18E = temp_v0_2 & 0xFF;
                if ((!((((u32) (*((u32 *) (((char *) var_s6) + 0x5C)))) >> 0x17) & 2)) || ((func_80083B64(&scratch.translation[0], sp184), ((((u32) (*((u32 *) (((char *) var_s6) + 0x5C)))) >> 0x17) & 2) == 0)))
                {
                  var_s3_3 = -1;
                  if ((*((u8 *) (((char *) temp_s1) + 0x48))) & 4)
                  {
                    var_s0_3 = 0;
                    if (temp_s2_2 < ((u16) (*((u16 *) (((char *) temp_s1) + 0x40)))))
                    {
                      do
                      {
                        temp_s2_3 = var_s0_3 & 0xFFFF;
                        temp_a0 = (*((u16 **) (((char *) temp_s1) + 0x38)))[temp_s2_3];
                        temp_a1 = ((u8 *) (*((u16 **) (((char *) temp_s1) + 0x3C)))) + (((u32) temp_s2_3) * 6);
                        if ((sp18E & temp_a0) && (temp_s7 & temp_a0))
                        {
                          temp_v1_6 = *((s32 *) (((char *) temp_s1) + 0x34));
                          if (((rayHitsTriangleXZ(&scratch.localEnd[0], scratch.secondPoint.overlap.point, ((s32) temp_v1_6) + ((*((u16 *) (((char *) temp_a1) + 0))) * 0xC), temp_v1_6 + ((*((u16 *) (((char *) temp_a1) + 2))) * 0xC), temp_v1_6 + ((*((u16 *) (((char *) temp_a1) + 4))) * 0xC), &scratch.spF0) & 0xFF) && (scratch.spF0 >= 0.0f)) && (scratch.spF0 < var_fs0))
                          {
                            if (!((((u32) (*((u32 *) (((char *) var_s6) + 0x5C)))) >> 0x17) & 0x20))
                            {
                              var_fs0 = scratch.spF0;
                              var_s3_3 = temp_s2_3;
                            }
                            else
                              if (sp134 != NULL)
                            {
                              *((f32 *) (((char *) sp134) + 0)) = (f32) (*((f32 *) (((char *) arg1) + 0)));
                              *((f32 *) (((char *) sp134) + 4)) = inline_fn(arg1, scratch.spF0);
                              gPlayerActor = NULL;
                              D_80103F00 = var_s6;
                              *((f32 *) (((char *) sp134) + 8)) = (f32) (*((f32 *) (((char *) arg1) + 8)));
                            }
                          }
                        }
                        var_s0_3 += 1;
                      }
                      while (((u32) (var_s0_3 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) temp_s1) + 0x40)))));
                    }
                  }
                  else
                    if (temp_s2_2 < ((u16) (*((u16 *) (((char *) temp_s1) + 0x40)))))
                  {
                    var_s0_4 = 0;
                    do
                    {
                      temp_s2_4 = var_s0_4 & 0xFFFF;
                      temp_v1_7 = (*((u16 **) (((char *) temp_s1) + 0x38)))[temp_s2_4];
                      temp_a1_2 = ((u8 *) (*((u16 **) (((char *) temp_s1) + 0x3C)))) + (temp_s2_4 * 3);
                      if ((sp18E & temp_v1_7) && (temp_s7 & temp_v1_7))
                      {
                        temp_v1_8 = *((s32 *) (((char *) temp_s1) + 0x34));
                        if (((rayHitsTriangleXZ(&scratch.localEnd[0], scratch.secondPoint.overlap.point, temp_v1_8 + ((*((u8 *) (((char *) temp_a1_2) + 0))) * 0xC), temp_v1_8 + ((*((u8 *) (((char *) temp_a1_2) + 1))) * 0xC), temp_v1_8 + ((*((u8 *) (((char *) temp_a1_2) + 2))) * 0xC), &scratch.spF0) & 0xFF) && (scratch.spF0 >= 0.0f)) && (var_fs0 > scratch.spF0))
                        {
                          if (!((((u32) (*((u32 *) (((char *) var_s6) + 0x5C)))) >> 0x17) & 0x20))
                          {
                            var_fs0 = scratch.spF0;
                            var_s3_3 = temp_s2_4;
                          }
                          else
                            if (sp134 != NULL)
                          {
                            *((f32 *) (((char *) sp134) + 0)) = (f32) (*((f32 *) (((char *) arg1) + 0)));
                            *((f32 *) (((char *) sp134) + 4)) = (f32) ((*((f32 *) (((char *) arg1) + 4))) - scratch.spF0);
                            gPlayerActor = NULL;
                            D_80103F00 = var_s6;
                            *((f32 *) (((char *) sp134) + 8)) = (f32) (*((f32 *) (((char *) arg1) + 8)));
                          }
                        }
                      }
                      ++var_s0_4;
                    }
                    while (((u32) (var_s0_4 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) temp_s1) + 0x40)))));
                  }
                  if (var_s3_3 != (-1))
                  {
                    gPlayerActor = NULL;
                    D_80108F84 = var_s6;
                    if (arg7 != NULL)
                    {
                      if ((*((u8 *) (((char *) temp_s1) + 0x48))) & 4)
                      {
                        temp_v1_9 = ((u8 *) (*((u16 **) (((char *) temp_s1) + 0x3C)))) + (var_s3_3 * 6);
                        var_a2 = (*((u16 *) (((char *) temp_v1_9) + 2))) * 3;
                        var_v0 = *((u16 *) (((char *) temp_v1_9) + 4));
                        var_a1 = (*((s32 *) (((char *) temp_s1) + 0x34))) + ((*((u16 *) (((char *) temp_v1_9) + 0))) * 0xC);
                        buildPlaneFromPoints(&scratch.plane[0], var_a1, (*((s32 *) (((char *) temp_s1) + 0x34))) + (var_a2 * 4), (*((s32 *) (((char *) temp_s1) + 0x34))) + (var_v0 * 0xC));
                      }
                      else
                      {
                        temp_v1_10 = ((u8 *) (*((u16 **) (((char *) temp_s1) + 0x3C)))) + (var_s3_3 * 3);
                        var_a1 = (*((s32 *) (((char *) temp_s1) + 0x34))) + ((*((u8 *) (((char *) temp_v1_10) + 0))) * 0xC);
                        var_a2 = (*((u8 *) (((char *) temp_v1_10) + 1))) * 3;
                        var_v0 = (u16) (*((u8 *) (((char *) temp_v1_10) + 2)));
                        buildPlaneFromPoints(&scratch.plane[0], var_a1, (*((s32 *) (((char *) temp_s1) + 0x34))) + (var_a2 * 4), (*((s32 *) (((char *) temp_s1) + 0x34))) + (var_v0 * 0xC));
                      }
                      *((f32 *) (((char *) arg7) + 0)) = scratch.plane[0];
                      *((f32 *) (((char *) arg7) + 4)) = scratch.plane[1];
                      *((f32 *) (((char *) arg7) + 8)) = scratch.plane[2];
                      *((f32 *) (((char *) arg7) + 0xC)) = scratch.plane[3];
                    }
                  }
                }
                else
                {
                  temp_v1_11 = (*((u8 *) (((char *) temp_s1) + 0x48))) & 4;
                  var_s5 = -1;
                  if (temp_v1_11 != 0)
                  {
                    var_s3_4 = *((u16 **) (((char *) temp_s1) + 0x3C));
                    var_s0_5 = 0;
                    if (temp_s2_2 < ((u16) (*((u16 *) (((char *) temp_s1) + 0x40)))))
                    {
                      var_s2_3 = ((u8 *) var_s3_4) + 4;
                      do
                      {
                        temp_s4_2 = var_s0_5 & 0xFFFF;
                        temp_v1_12 = (*((u16 **) (((char *) temp_s1) + 0x38)))[temp_s4_2];
                        if ((sp18E & temp_v1_12) && (temp_s7 & temp_v1_12))
                        {
                          temp_v1_13 = *((s32 *) (((char *) temp_s1) + 0x34));
                          if (((func_8004D910(&scratch.localEnd[0], scratch.secondPoint.overlap.point, temp_v1_13 + ((*var_s3_4) * 0xC), temp_v1_13 + ((*((u16 *) (((char *) var_s2_3) + (-2)))) * 0xC), temp_v1_13 + ((*((u16 *) (((char *) var_s2_3) + 0))) * 0xC), sp194) & 0xFF) && (scratch.sp108 >= 0.0f)) && (scratch.sp108 < var_fs0))
                          {
                            var_fs0 = scratch.sp108;
                            var_s5 = temp_s4_2;
                          }
                        }
                        var_s2_3 = (void *) (((u8 *) var_s2_3) + 6);
                        ++var_s0_5;
                        var_s3_4 = (void *) (((u8 *) var_s3_4) + 6);
                      }
                      while (((u32) (var_s0_5 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) temp_s1) + 0x40)))));
                    }
                  }
                  else
                  {
                    var_s3_5 = *((u16 **) (((char *) temp_s1) + 0x3C));
                    var_s0_6 = 0;
                    if (temp_v1_11 < ((u16) (*((u16 *) (((char *) temp_s1) + 0x40)))))
                    {
                      var_s2_4 = ((u8 *) var_s3_5) + 2;
                      do
                      {
                        temp_s4_3 = var_s0_6 & 0xFFFF;
                        temp_v1_14 = (*((u16 **) (((char *) temp_s1) + 0x38)))[temp_s4_3];
                        if ((sp18E & temp_v1_14) && (temp_s7 & temp_v1_14))
                        {
                          temp_v1_15 = *((s32 *) (((char *) temp_s1) + 0x34));
                          if (((func_8004D910(&scratch.localEnd[0], scratch.secondPoint.overlap.point, temp_v1_15 + ((*((u8 *) var_s3_5)) * 0xC), temp_v1_15 + ((*((u8 *) (((char *) var_s2_4) + (-1)))) * 0xC), temp_v1_15 + ((*((u8 *) (((char *) var_s2_4) + 0))) * 0xC), sp194) & 0xFF) && (scratch.sp108 >= 0.0f)) && (var_fs0 > scratch.sp108))
                          {
                            var_fs0 = scratch.sp108;
                            var_s5 = temp_s4_3;
                          }
                        }
                        var_s2_4 = (void *) (((u8 *) var_s2_4) + 3);
                        var_s3_5 = (void *) (((u8 *) var_s3_5) + 3);
                        var_s0_6 += 1;
                      }
                      while (((u32) (var_s0_6 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) temp_s1) + 0x40)))));
                    }
                  }
                  if (var_s5 != (-1))
                  {
                    gPlayerActor = NULL;
                    D_80108F84 = var_s6;
                  }
                }
              }
            }
          }
          var_s6 = *((void ***) (((char *) var_s6) + 0x14));
        }
        while (var_s6 != NULL);
      }
      if (sp13C == NULL)
      {
        sp124 = NULL;
      }
      else
        if (!(gPlayerActor != NULL))
      {
        if (D_80108F84 != ((s32) NULL))
        {
          sp124 = NULL;
        }
        else
        {
          temp_v0_3 = func_80047B44(sp124, &scratch.endPoint[0], &scratch.startPoint[0], &scratch.plane[0]);
          if (temp_v0_3 == NULL)
          {
            sp124 = NULL;
          }
          else
          {
            if ((*((u16 *) (((char *) temp_v0_3) + 0x26))) & 0x1000)
            {
              if (arg5)
              {
                temp_fv1_2 = (*((f32 *) (((char *) arg1) + 4))) - scratch.plane[1];
                var_v0_3 = 1;
              }
              else
              {
                temp_fv1_2 = (*((f32 *) (((char *) arg1) + 4))) - scratch.plane[1];
                var_v0_3 = 1;
              }
              if (!(temp_fv1_2 >= 0.0f))
              {
                var_v0_3 = 0;
              }
              var_v1_2 = 1;
              if (!(temp_fv1_2 < var_fs0))
              {
                var_v1_2 = 0;
              }
              if (var_v0_3 & var_v1_2)
              {
                gPlayerActor = NULL;
                D_80108F84 = NULL;
                var_fs0 = temp_fv1_2;
                if (absFloat() < 0.5f)
                {
                  prepareLinkedObjectPair(temp_v0_3, arg1, sp124);
                }
              }
            }
            scratch.endPoint[1] = scratch.plane[1] - 0.01f;
            sp124 = *((void ***) (((char *) temp_v0_3) + 8));
          }
        }
      }
      else
      {
        sp124 = NULL;
      }
    }
    while (sp124 != NULL);
    if (var_fs0 == arg4)
    {
      if (sp124 == NULL)
      {
        goto block_160;
      }
      *(PointCopy *)sp12C = *(PointCopy *)scratch.startPoint;
      goto block_162;
    }
    if (gPlayerActor == NULL)
    {
      if (arg5 != NULL)
      {
        *((f32 *) (((char *) arg5) + 0)) = 0.0f;
        *((f32 *) (((char *) arg5) + 4)) = 0.0f;
        *((f32 *) (((char *) arg5) + 8)) = 0.0f;
        if ((*((s32 *) (((char *) D_80108F84) + 0x50))) & 0x02000000)
        {
          *((f32 *) (((char *) arg5) + 0)) = (f32) ((*((f32 *) (((char *) arg5) + 0))) - 0.1f);
        }
        if ((*((s32 *) (((char *) D_80108F84) + 0x50))) & 0x04000000)
        {
          *((f32 *) (((char *) arg5) + 0)) = (f32) ((*((f32 *) (((char *) arg5) + 0))) + 0.1f);
        }
        if ((*((s32 *) (((char *) D_80108F84) + 0x50))) & 0x08000000)
        {
          *((f32 *) (((char *) arg5) + 8)) = (f32) ((*((f32 *) (((char *) arg5) + 8))) - 0.1f);
        }
        if ((*((s32 *) (((char *) D_80108F84) + 0x50))) & 0x10000000)
        {
          *((f32 *) (((char *) arg5) + 8)) = (f32) ((*((f32 *) (((char *) arg5) + 8))) + 0.1f);
        }
      }
      if (arg6 != NULL)
      {
        *((f32 *) (((char *) arg6) + 0)) = 0.0f;
        *((f32 *) (((char *) arg6) + 4)) = 0.0f;
        *((f32 *) (((char *) arg6) + 8)) = 0.0f;
      }
      *((f32 *) (((char *) sp12C) + 0)) = (f32) (*((f32 *) (((char *) arg1) + 0)));
      *((f32 *) (((char *) sp12C) + 4)) = (f32) ((*((f32 *) (((char *) arg1) + 4))) - var_fs0);
      *((f32 *) (((char *) sp12C) + 8)) = (f32) (*((f32 *) (((char *) arg1) + 8)));
      block_162:
      return 1;

    }
    scratch.plane[0] = (*((f32 *) (((char *) gPlayerActor) + 0x3C))) - (*((f32 *) (((char *) gPlayerActor) + 0x48)));
    scratch.plane[1] = (*((f32 *) (((char *) gPlayerActor) + 0x40))) - (*((f32 *) (((char *) gPlayerActor) + 0x4C)));
    scratch.plane[2] = (*((f32 *) (((char *) gPlayerActor) + 0x44))) - (*((f32 *) (((char *) gPlayerActor) + 0x50)));
    *((f32 *) (((char *) sp12C) + 0)) = (f32) (*((f32 *) (((char *) arg1) + 0)));
    *((f32 *) (((char *) sp12C) + 4)) = inline_fn(arg1, var_fs0);
    *((f32 *) (((char *) sp12C) + 8)) = (f32) (*((f32 *) (((char *) arg1) + 8)));
    if (arg5 != NULL)
    {
      scratch.translation[0] = scratch.sp18;
      scratch.translation[1] = scratch.sp1C;
      scratch.translation[2] = scratch.sp20;
      scratch.rotationInput.angles[0] = (s16) ((s32) (*((f32 *) (((char *) gPlayerActor) + 0x3C))));
      scratch.rotationInput.angles[1] = (s16) ((s32) (*((f32 *) (((char *) gPlayerActor) + 0x40))));
      scratch.rotationInput.angles[2] = (s16) ((s32) (*((f32 *) (((char *) gPlayerActor) + 0x44))));
      buildRotationMatrixS16(&scratch.rotationInput.angles[0], scratch.matrix);
      func_800839F0(scratch.matrix, &scratch.translation[0], &scratch.rotatedA[0]);
      scratch.rotationInput.angles[0] = (s16) ((s32) ((*((f32 *) (((char *) gPlayerActor) + 0x3C))) + scratch.plane[0]));
      scratch.rotationInput.angles[1] = (s16) ((s32) ((*((f32 *) (((char *) gPlayerActor) + 0x40))) + scratch.plane[1]));
      scratch.rotationInput.angles[2] = (s16) ((s32) ((*((f32 *) (((char *) gPlayerActor) + 0x44))) + scratch.plane[2]));
      buildRotationMatrixS16(&scratch.rotationInput.angles[0], scratch.matrix);
      func_800839F0(scratch.matrix, &scratch.translation[0], &scratch.secondPoint.rotated[0]);
      temp_ft1 = (*((f32 *) (((char *) gPlayerActor) + 0x24))) - (*((f32 *) (((char *) gPlayerActor) + 0x30)));
      scratch.sp110[0] = temp_ft1;
      temp_fv0 = (*((f32 *) (((char *) gPlayerActor) + 0x28))) - (*((f32 *) (((char *) gPlayerActor) + 0x34)));
      scratch.sp110[1] = temp_fv0;
      scratch.sp110[2] = (*((f32 *) (((char *) gPlayerActor) + 0x2C))) - (*((f32 *) (((char *) gPlayerActor) + 0x38)));
      *((f32 *) (((char *) arg5) + 0)) = (f32) (temp_ft1 + (scratch.secondPoint.rotated[0] - scratch.rotatedA[0]));
      *((f32 *) (((char *) arg5) + 4)) = (f32) (scratch.sp110[1] + (scratch.secondPoint.rotated[1] - scratch.rotatedA[1]));
      *((f32 *) (((char *) arg5) + 8)) = (f32) (scratch.sp110[2] + (scratch.secondPoint.rotated[2] - scratch.rotatedA[2]));
    }
    if (arg6 != NULL)
    {
      *((f32 *) (((char *) arg6) + 0)) = scratch.plane[0];
      *((f32 *) (((char *) arg6) + 4)) = scratch.plane[1];
      *((f32 *) (((char *) arg6) + 8)) = scratch.plane[2];
      return 1;
    }
    return 1;
  }
  block_160:
  return 0;

}

