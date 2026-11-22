s32 Sphere_OverlapsPoint(void **, void *, f32);
s32 applyObjectRotation(void **, s32, f32 *);
void buildRotationMatrix(const s16 *, f32 *);
void buildRotationMatrixS16(const s16 *, f32 *);
void *func_80047B44(void **, void *, f32 *, f32 *);
s32 func_800487F0(void *, void *, f32);
s32 func_8004D910(f32 *, f32 *, s32, s32, s32, f32 *);
unsigned char func_8004E418(s32, f32 *, f32 *);
void func_800839F0(f32 *, f32 *, f32 *);
s32 func_80083B64(f32 *, s16 *);
s32 rayHitsTriangleXZ(f32 *, f32 *, s32, s32, s32, f32 *);
s32 rotateVec3ByMat3(f32 *, f32 *);
s32 segmentOverlapsBox(s32, f32 *, f32 *);
extern s32 D_800D3E18;
extern void **D_80108F84;
extern void *gPlayerActor;
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} SweepVec;
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
s32 sweepSphereAgainstScene(void **arg0, void *arg1, void *arg2, f32 arg3, void *arg4, void *arg5, s32 arg6, s32 arg7)
{
  f32 sp18[3];
  SweepVec vec28;
  SweepVec vec38;
  SweepVec vec48;
  f32 matrix[9];
  s16 sp68[3];
  union 
  {
    s16 angles[3];
    SweepVec point;
    struct 
    {
      f32 padding[2];
      SweepVec direction;
    } first;
  } scratch;
  f32 spA0;
  SweepVec vecA8;
  SweepVec vecB8;
  union 
  {
    f32 rotated[3];
    struct 
    {
      f32 padding[2];
      SweepVec end;
    } second;
  } result;
  f32 spE0;
  SweepVec vec70;
  register f32 spE4;
  f32 spE8[9];
  volatile SweepVec vec118;
  void *sp134;
  void *sp13C;
  volatile s32 sp144;
  void *sp14C;
  f32 *sp154;
  f32 *sp15C;
  f32 *sp164;
  f32 *sp16C;
  void **sp12C;
  f32 *sp174;
  s16 *sp17C;
  f32 *sp184;
  f32 *sp18C;
  f32 *sp194;
  f32 *sp19C;
  s32 sp1A0;
  f32 temp_ft1;
  f32 temp_fv0;
  f32 temp_fv1;
  f32 var_fs0;
  int temp_fp;
  s32 temp_fp_2;
  s32 temp_s0;
  s32 temp_s0_2;
  s32 temp_s4_2;
  s32 temp_s4_3;
  s32 temp_s4_4;
  s32 temp_s5;
  s32 temp_s5_2;
  register unsigned temp_s7;
  register s32 temp_t2;
  s32 temp_v0;
  register s32 temp_v0_2;
  s32 temp_v1_10;
  s32 temp_v1_12;
  s32 temp_v1_15;
  s32 temp_v1_17;
  s32 temp_v1_5;
  s32 temp_v1_7;
  s32 var_s0;
  s32 var_s0_2;
  s32 var_s0_3;
  unsigned short var_s0_4;
  s32 var_s0_5;
  unsigned short var_s0_6;
  s32 var_s5;
  s32 var_s7;
  s32 var_t2;
  register s32 var_v0;
  s32 var_v1;
  register u16 *var_s3;
  u8 *var_s3_2;
  u16 *var_s3_3;
  u8 *var_s3_4;
  u16 *var_s3_5;
  u8 *var_s3_6;
  s32 temp_v1;
  u16 temp_v1_11;
  u16 temp_v1_14;
  u16 temp_v1_16;
  u16 temp_v1_4;
  u16 temp_v1_6;
  u16 temp_v1_9;
  u32 temp_v1_13;
  u32 temp_v1_3;
  u32 temp_v1_8;
  u32 var_s2;
  s32 temp_v1_2;
  void **var_a0;
  void **var_s6;
  void *temp_s1;
  register void *temp_s4;
  void *temp_v0_3;
  void *var_s1;
  register void *var_s2_2;
  void *var_s2_3;
  void *var_s2_4;
  void *var_s2_5;
  void *var_s2_6;
  void *var_s2_7;
  sp12C = arg0;
  sp134 = arg1;
  sp13C = arg2;
  D_80108F84 = NULL;
  gPlayerActor = NULL;
  var_fs0 = arg3;
  if (sp12C != NULL)
  {
    sp18[0] = 0.0f;
    sp18[1] = 0.0f;
    sp18[2] = 0.0f;
    vec28.x = ((Field_f32 *) (((char *) sp134) + 0))->v;
    vec28.y = ((Field_f32 *) (((char *) sp134) + 4))->v - var_fs0;
    sp154 = matrix;
    sp15C = &vec38.x;
    vec28.z = ((Field_f32 *) (((char *) sp134) + 8))->v;
    sp16C = &scratch.first.direction.x;
    sp164 = &vec48.x;
    sp144 = *((s32 *) (((char *) (*((void **) (((char *) sp12C) + 0x20)))) + 0x58));
    do
    {
      var_s6 = sp12C;
      var_a0 = sp12C;
      sp14C = *((void **) (((char *) (*((void **) (((char *) sp12C) + 0x20)))) + 0x58));
      if (sp12C != NULL)
      {
        sp174 = &spA0;
        do
        {
          var_s1 = *var_a0;
          if (var_s1 != NULL)
          {
            do
            {
              if ((((*((void **) (((char *) var_s1) + 0x70))) != NULL) && (!(((Field_s32 *) (((char *) var_s1) + 0x58))->v & 0x400))) && (((Field_s32 *) (((char *) var_s1) + 0x5C))->v & 0x200))
              {
                temp_v1 = ((Field_u16 *) (((char *) var_s1) + 0x78))->v;
                if (temp_v1 != 0x3B)
                {
                  if (((s32) temp_v1) >= 0x3C)
                  {
                    var_s2 = 1;
                    if (temp_v1 == 0x3F)
                    {
                      goto block_17;
                    }
                  }
                  else
                  {
                    var_s2 = 1;
                    if (temp_v1 != 0xB)
                    {
                    }
                    else
                    {
                      temp_v1_2 = *((u8 *) (((char *) (*((void **) (((char *) var_s1) + 0x6C)))) + 0x4A));
                      if ((((s32) temp_v1_2) >= 0xE) || ((var_s2 = 1, (temp_v1_2 < 0xA) != 0)))
                      {
                        goto block_16;
                      }
                    }
                  }
                }
                else
                {
                  block_16:
                  block_17:
                  var_s2 = 0;


                }
                if ((!var_s2) && ((func_800487F0(var_s1, sp134, arg3) << 0x18) != 0))
                {
                  temp_s4 = *((void **) (((char *) var_s1) + 0x70));
                  scratch.angles[0] = (s16) ((s32) (-((Field_f32 *) (((char *) var_s1) + 0x3C))->v));
                  scratch.angles[1] = (s16) ((s32) (-((Field_f32 *) (((char *) var_s1) + 0x40))->v));
                  scratch.angles[2] = (s32) (-((Field_f32 *) (((char *) var_s1) + 0x44))->v);
                  buildRotationMatrix(scratch.angles, sp154);
                  vec38.x = ((Field_f32 *) (((char *) sp134) + 0))->v - ((Field_f32 *) (((char *) var_s1) + 0x24))->v;
                  vec38.y = ((Field_f32 *) (((char *) sp134) + 4))->v - ((Field_f32 *) (((char *) var_s1) + 0x28))->v;
                  vec38.z = ((Field_f32 *) (((char *) sp134) + 8))->v - ((Field_f32 *) (((char *) var_s1) + 0x2C))->v;
                  vec48.x = vec28.x - ((Field_f32 *) (((char *) var_s1) + 0x24))->v;
                  vec48.y = vec28.y - ((Field_f32 *) (((char *) var_s1) + 0x28))->v;
                  vec48.z = vec28.z - ((Field_f32 *) (((char *) var_s1) + 0x2C))->v;
                  rotateVec3ByMat3(sp154, sp15C);
                  temp_s0 = temp_s4 + 0x18;
                  rotateVec3ByMat3(sp154, sp164);
                  if ((segmentOverlapsBox(temp_s0, sp15C, sp164) << 0x18) != 0)
                  {
                    scratch.first.direction = *((SweepVec *) (&D_800D3E18));
                    temp_v0 = func_8004E418(temp_s0, sp15C, sp164) & 0xFFFF;
                    temp_t2 = temp_v0 & 0xFF;
                    temp_fp = temp_v0 & 0xFF00;
                    sp1A0 = temp_t2;
                    rotateVec3ByMat3(sp154, sp16C);
                    sp18[0] = vec38.x;
                    sp18[2] = vec38.z;
                    var_t2 = temp_t2;
                    temp_v1_3 = ((Field_u8 *) (((char *) temp_s4) + 0x48))->v & 4;
                    var_s7 = -1;
                    if (temp_v1_3 != 0)
                    {
                      var_s3 = *((u16 **) (((char *) temp_s4) + 0x3C));
                      if (var_s2 < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v))
                      {
                        var_s0 = 0;
                        var_s2_2 = ((u8 *) var_s3) + 4;
                        do
                        {
                          temp_s5 = var_s0 & 0xFFFF;
                          temp_v1_4 = *((u16 *) (((char *) (*((void **) (((char *) temp_s4) + 0x38)))) + (temp_s5 * 2)));
                          if ((var_t2 & temp_v1_4) && (temp_fp & temp_v1_4))
                          {
                            temp_v1_5 = ((Field_s32 *) (((char *) temp_s4) + 0x34))->v;
                            sp1A0 = var_t2;
                            var_t2 = sp1A0;
                            if (((func_8004D910(&(&vec38)->x, &scratch.first.direction.x, temp_v1_5 + ((*var_s3) * 0xC), temp_v1_5 + ((*((u16 *) (((char *) var_s2_2) + (-2)))) * 0xC), temp_v1_5 + (((Field_u16 *) (((char *) var_s2_2) + 0))->v * 0xC), sp174) & 0xFF) && (spA0 >= 0.0f)) && (spA0 < var_fs0))
                            {
                              var_fs0 = spA0;
                              var_s7 = temp_s5;
                            }
                          }
                          var_s2_2 += 6;
                          var_s3 += 3;
                          var_s0 += 1;
                        }
                        while (((u32) (var_s0 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v));
                      }
                    }
                    else
                    {
                      var_s3_2 = (u8 *) (*((u16 **) (((char *) temp_s4) + 0x3C)));
                      if (temp_v1_3 < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v))
                      {
                        var_s0_2 = 0;
                        var_s2_3 = var_s3_2 + 2;
                        do
                        {
                          temp_s5_2 = var_s0_2 & 0xFFFF;
                          temp_v1_6 = *((u16 *) (((char *) (*((void **) (((char *) temp_s4) + 0x38)))) + (temp_s5_2 * 2)));
                          if ((var_t2 & temp_v1_6) && (temp_fp & temp_v1_6))
                          {
                            temp_v1_7 = ((Field_s32 *) (((char *) temp_s4) + 0x34))->v;
                            sp1A0 = var_t2;
                            var_t2 = sp1A0;
                            if (((func_8004D910(&vec38.x, &scratch.first.direction.x, temp_v1_7 + ((*var_s3_2) * 0xC), ((u32) temp_v1_7) + ((*((u8 *) (((char *) var_s2_3) + (-1)))) * 0xC), temp_v1_7 + (((Field_u8 *) (((char *) var_s2_3) + 0))->v * 0xC), sp174) & 0xFF) && ((spA0 + 1) >= (0.0f + 1))) && (spA0 < var_fs0))
                            {
                              var_fs0 = spA0;
                              var_s7 = temp_s5_2;
                            }
                          }
                          var_s2_3 += 3;
                          var_s3_2 += 3;
                          var_s0_2++;
                        }
                        while (((u32) (var_s0_2 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s4) + 0x40))->v));
                      }
                    }
                    if (var_s7 != (-1))
                    {
                      gPlayerActor = var_s1;
                      D_80108F84 = NULL;
                      sp18[1] = vec38.y - var_fs0;
                    }
                  }
                }
              }
              var_s1 = *((void **) (((char *) var_s1) + 0));
            }
            while (var_s1 != NULL);
          }
          var_a0 = NULL;
          if (sp14C != ((int) NULL))
          {
            var_a0 = *((void ***) (((char *) sp14C) + 8));
            sp14C = *((void **) (((char *) sp14C) + 0));
          }
        }
        while (var_a0 != NULL);
      }
      if (var_s6 != NULL)
      {
        sp17C = (s16 *) (&scratch.point);
        sp184 = &result.second.end.x;
        sp18C = &vecA8.x;
        sp194 = &spE0;
        sp19C = &spE4;
        do
        {
          if (((((Field_s32 *) (((char *) var_s6) + 0x50))->v & 0x200) && (((((u32) ((Field_u32 *) (((char *) var_s6) + 0x5C))->v) >> 0x11) & 0x3F) & arg7)) && ((Sphere_OverlapsPoint((void **) (((u8 *) var_s6) + 0x40), sp134, arg3) << 0x18) != 0))
          {
            vec48 = *((SweepVec *) (&D_800D3E18));
            temp_s1 = *((void **) (((char *) var_s6) + 0x3C));
            scratch.point = *((SweepVec *) sp134);
            result.second.end = vec28;
            if ((((u32) ((Field_u32 *) (((char *) var_s6) + 0x5C))->v) >> 0x17) & 1)
            {
              scratch.point.x -= ((Field_f32 *) (((char *) var_s6) + 0x24))->v;
              scratch.point.y -= ((Field_f32 *) (((char *) var_s6) + 0x28))->v;
              scratch.point.z -= ((Field_f32 *) (((char *) var_s6) + 0x2C))->v;
              result.second.end.x -= ((Field_f32 *) (((char *) var_s6) + 0x24))->v;
              result.second.end.y -= ((Field_f32 *) (((char *) var_s6) + 0x28))->v;
              result.second.end.z -= ((Field_f32 *) (((char *) var_s6) + 0x2C))->v;
            }
            if ((((u32) ((Field_u32 *) (((char *) var_s6) + 0x5C))->v) >> 0x17) & 2)
            {
              applyObjectRotation(var_s6, 0, sp18C);
              func_80083B64(sp18C, sp17C);
              func_80083B64(sp18C, (s16 *) sp184);
            }
            temp_s0_2 = temp_s1 + 0x18;
            if ((segmentOverlapsBox(temp_s0_2, (f32 *) sp17C, sp184) << 0x18) != 0)
            {
              temp_v0_2 = func_8004E418(temp_s0_2, (f32 *) sp17C, sp184) & 0xFFFF;
              temp_fp_2 = temp_v0_2 & 0xFF;
              temp_s7 = temp_v0_2 & 0xFF00;
              if ((!((((u32) ((Field_u32 *) (((char *) var_s6) + 0x5C))->v) >> 0x17) & 2)) || ((func_80083B64(&vecA8.x, (s16 *) sp164), ((((u32) ((Field_u32 *) (((char *) var_s6) + 0x5C))->v) >> 0x17) & 2) == 0)))
              {
                temp_v1_8 = ((Field_u8 *) (((char *) temp_s1) + 0x48))->v & 4;
                var_s5 = -1;
                if (temp_v1_8 != 0)
                {
                  var_s3_3 = *((u16 **) (((char *) temp_s1) + 0x3C));
                  var_s0_3 = 0;
                  if (((Field_u16 *) (((char *) temp_s1) + 0x40))->v != 0)
                  {
                    var_s2_4 = ((u8 *) var_s3_3) + 4;
                    do
                    {
                      temp_v1_9 = *((u16 *) (((char *) (*((void **) (((char *) temp_s1) + 0x38)))) + ((var_s0_3 & 0xFFFF) * 2)));
                      if ((temp_fp_2 & temp_v1_9) && (temp_s7 & temp_v1_9))
                      {
                        temp_v1_10 = ((Field_s32 *) (((char *) temp_s1) + 0x34))->v;
                        if (((rayHitsTriangleXZ(&scratch.point.x, &vec48.x, temp_v1_10 + ((*var_s3_3) * 0xC), temp_v1_10 + ((*((u16 *) (((char *) var_s2_4) + (-2)))) * 0xC), temp_v1_10 + (((Field_u16 *) (((char *) var_s2_4) + 0))->v * 0xC), sp194) & 0xFF) && (spE0 >= 0.0f)) && (spE0 < var_fs0))
                        {
                          var_fs0 = spE0;
                        }
                      }
                      var_s2_4 += 6;
                      var_s3_3 += 3;
                      var_s0_3 += 1;
                    }
                    while (((u32) (var_s0_3 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s1) + 0x40))->v));
                  }
                }
                else
                {
                  var_s3_4 = (u8 *) (*((u16 **) (((char *) temp_s1) + 0x3C)));
                  var_s0_4 = 0;
                  if (temp_v1_8 < ((u16) ((Field_u16 *) (((char *) temp_s1) + 0x40))->v))
                  {
                    var_s2_5 = var_s3_4 + 2;
                    do
                    {
                      temp_s4_2 = var_s0_4 & 0xFFFF;
                      temp_v1_11 = *((u16 *) (((char *) (*((void **) (((char *) temp_s1) + 0x38)))) + (temp_s4_2 * 2)));
                      if ((temp_fp_2 & temp_v1_11) && (temp_s7 & temp_v1_11))
                      {
                        temp_v1_12 = ((Field_s32 *) (((char *) temp_s1) + 0x34))->v;
                        if (((rayHitsTriangleXZ(&scratch.point.x, &vec48.x, temp_v1_12 + ((*var_s3_4) * 0xC), temp_v1_12 + ((*((u8 *) (((char *) var_s2_5) + (-1)))) * 0xC), temp_v1_12 + (((Field_u8 *) (((char *) var_s2_5) + 0))->v * 0xC), sp194) & 0xFF) && ((spE0 - 1) >= (0.0f - 1))) && (var_fs0 > spE0))
                        {
                          var_fs0 = spE0;
                          var_s5 = temp_s4_2;
                        }
                      }
                      var_s2_5 += 3;
                      var_s3_4 += 3;
                      var_s0_4 += 1;
                    }
                    while (((u32) (var_s0_4 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s1) + 0x40))->v));
                  }
                  if (var_s5 != (-1))
                  {
                    gPlayerActor = NULL;
                    D_80108F84 = var_s6;
                  }
                }
              }
              else
              {
                temp_v1_13 = ((Field_u8 *) (((char *) temp_s1) + 0x48))->v & 4;
                var_s5 = -1;
                if (temp_v1_13 != 0)
                {
                  if (var_s6)
                  {
                    var_s3_5 = *((u16 **) (((char *) temp_s1) + 0x3C));
                    var_s0_5 = 0;
                  }
                  else
                  {
                    var_s3_5 = *((u16 **) (((char *) temp_s1) + 0x3C));
                    var_s0_5 = 0;
                  }
                  if (((Field_u16 *) (((char *) temp_s1) + 0x40))->v != 0)
                  {
                    var_s2_6 = ((u8 *) var_s3_5) + 4;
                    do
                    {
                      temp_s4_3 = var_s0_5 & 0xFFFF;
                      temp_v1_14 = *((u16 *) (((char *) (*((void **) (((char *) temp_s1) + 0x38)))) + (temp_s4_3 * 2)));
                      if ((temp_fp_2 & temp_v1_14) && (temp_s7 & temp_v1_14))
                      {
                        temp_v1_15 = ((Field_s32 *) (((char *) temp_s1) + 0x34))->v;
                        if (((func_8004D910(&scratch.point.x, &vec48.x, temp_v1_15 + ((*var_s3_5) * 0xC), temp_v1_15 + ((*((u16 *) (((char *) var_s2_6) + (-2)))) * 0xC), temp_v1_15 + (((Field_u16 *) (((char *) var_s2_6) + 0))->v * 0xC), sp19C) & 0xFF) && (spE4 >= 0.0f)) && (spE4 < var_fs0))
                        {
                          var_fs0 = spE4;
                          var_s5 = temp_s4_3;
                        }
                      }
                      var_s2_6 += 6;
                      var_s3_5 += 3;
                      var_s0_5 += 1;
                    }
                    while (((u32) (var_s0_5 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s1) + 0x40))->v));
                  }
                }
                else
                {
                  var_s3_6 = (u8 *) (*((u16 **) (((char *) temp_s1) + 0x3C)));
                  var_s0_6 = 0;
                  if (temp_v1_13 < ((u16) ((Field_u16 *) (((char *) temp_s1) + 0x40))->v))
                  {
                    var_s2_7 = var_s3_6 + 2;
                    do
                    {
                      temp_s4_4 = ((int) var_s0_6) & 0xFFFF;
                      temp_v1_16 = *((u16 *) (((char *) (*((void **) (((char *) temp_s1) + 0x38)))) + (temp_s4_4 * 2)));
                      if ((temp_fp_2 & temp_v1_16) && (temp_s7 & temp_v1_16))
                      {
                        temp_v1_17 = ((Field_s32 *) (((char *) temp_s1) + 0x34))->v;
                        if (((func_8004D910(&scratch.point.x, &vec48.x, temp_v1_17 + ((*var_s3_6) * 0xC), temp_v1_17 + ((*((u8 *) (((char *) var_s2_7) + (-1)))) * 0xC), temp_v1_17 + (((Field_u8 *) (((char *) var_s2_7) + 0))->v * 0xC), sp19C) & 0xFF) && (spE4 >= 0.0f)) && (spE4 < var_fs0))
                        {
                          var_s5 = temp_s4_4;
                          var_fs0 = spE4;
                        }
                      }
                      var_s2_7 += 3;
                      var_s3_6 += 3;
                      var_s0_6 += 1;
                    }
                    while (((u32) (var_s0_6 & 0xFFFF)) < ((u16) ((Field_u16 *) (((char *) temp_s1) + 0x40))->v));
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
          var_s6 = *((void ***) (((char *) var_s6) + 0x14));
        }
        while (var_s6 != NULL);
      }
      if ((sp144 != 0) && ((sp144 = 0, temp_v0_3 = func_80047B44(sp12C, sp134, &vec28.x, &result.second.end.x), temp_v0_3 != NULL)))
      {
        if (((Field_u16 *) (((char *) temp_v0_3) + 0x26))->v & 0x1000)
        {
          temp_fv1 = ((Field_f32 *) (((char *) sp134) + 4))->v - result.second.end.y;
          var_v0 = 1;
          if (!(temp_fv1 >= 0.0f))
          {
            var_v0 = 0;
          }
          var_v1 = 1;
          if (!(var_fs0 > temp_fv1))
          {
            var_v1 = 0;
          }
          if (var_v0 & var_v1)
          {
            var_fs0 = temp_fv1;
            gPlayerActor = NULL;
            D_80108F84 = NULL;
          }
        }
        sp12C = *((void ***) (((char *) temp_v0_3) + 8));
      }
      else
      {
        sp12C = NULL;
      }
    }
    while (sp12C != NULL);
    if (var_fs0 == arg3)
    {
      if (1)
      {
        goto block_131;
      }
    }
    if (gPlayerActor == NULL)
    {
      if (arg4 != NULL)
      {
        ((Field_f32 *) (((char *) arg4) + 0))->v = 0.0f;
        ((Field_f32 *) (((char *) arg4) + 4))->v = 0.0f;
        ((Field_f32 *) (((char *) arg4) + 8))->v = 0.0f;
      }
      if (arg5 != NULL)
      {
        ((Field_f32 *) (((char *) arg5) + 0))->v = 0.0f;
        ((Field_f32 *) (((char *) arg5) + 4))->v = 0.0f;
        ((Field_f32 *) (((char *) arg5) + 8))->v = 0.0f;
      }
      ((Field_f32 *) (((char *) sp13C) + 0))->v = (f32) ((Field_f32 *) (((char *) sp134) + 0))->v;
      ((Field_f32 *) (((char *) sp13C) + 4))->v = (f32) (((Field_f32 *) (((char *) sp134) + 4))->v - var_fs0);
      ((Field_f32 *) (((char *) sp13C) + 8))->v = (f32) ((Field_f32 *) (((char *) sp134) + 8))->v;
      return 1;
    }
    vecA8.x = ((Field_f32 *) (((char *) gPlayerActor) + 0x3C))->v - ((Field_f32 *) (((char *) gPlayerActor) + 0x48))->v;
    vecA8.y = ((Field_f32 *) (((char *) gPlayerActor) + 0x40))->v - ((Field_f32 *) (((char *) gPlayerActor) + 0x4C))->v;
    vecA8.z = ((Field_f32 *) (((char *) gPlayerActor) + 0x44))->v - ((Field_f32 *) (((char *) gPlayerActor) + 0x50))->v;
    ((Field_s32 *) (((char *) gPlayerActor) + 0x60))->v = (s32) (((Field_s32 *) (((char *) gPlayerActor) + 0x60))->v | arg6);
    ((Field_f32 *) (((char *) sp13C) + 0))->v = (f32) ((Field_f32 *) (((char *) sp134) + 0))->v;
    ((Field_f32 *) (((char *) sp13C) + 4))->v = (f32) (((Field_f32 *) (((char *) sp134) + 4))->v - var_fs0);
    ((Field_f32 *) (((char *) sp13C) + 8))->v = (f32) ((Field_f32 *) (((char *) sp134) + 8))->v;
    if (arg4 != NULL)
    {
      vecB8.x = sp18[0];
      vecB8.y = sp18[1];
      vecB8.z = sp18[2];
      sp68[0] = (s16) ((s32) ((Field_f32 *) (((char *) gPlayerActor) + 0x3C))->v);
      sp68[1] = (s16) ((s32) ((Field_f32 *) (((char *) gPlayerActor) + 0x40))->v);
      sp68[2] = (s16) ((s32) ((Field_f32 *) (((char *) gPlayerActor) + 0x44))->v);
      buildRotationMatrixS16(sp68, spE8);
      func_800839F0(spE8, &vecB8.x, result.rotated);
      sp68[0] = (s16) ((s32) (((Field_f32 *) (((char *) gPlayerActor) + 0x3C))->v + vecA8.x));
      sp68[1] = (s16) ((s32) (((Field_f32 *) (((char *) gPlayerActor) + 0x40))->v + vecA8.y));
      sp68[2] = (s16) ((s32) (((Field_f32 *) (((char *) gPlayerActor) + 0x44))->v + vecA8.z));
      buildRotationMatrixS16(sp68, spE8);
      func_800839F0(spE8, &vecB8.x, matrix);
      temp_ft1 = ((Field_f32 *) (((char *) gPlayerActor) + 0x24))->v - ((Field_f32 *) (((char *) gPlayerActor) + 0x30))->v;
      vec70.x = temp_ft1;
      temp_fv0 = ((Field_f32 *) (((char *) gPlayerActor) + 0x28))->v - ((Field_f32 *) (((char *) gPlayerActor) + 0x34))->v;
      vec70.y = temp_fv0;
      vec70.z = ((Field_f32 *) (((char *) gPlayerActor) + 0x2C))->v - ((Field_f32 *) (((char *) gPlayerActor) + 0x38))->v;
      ((Field_f32 *) (((char *) arg4) + 0))->v = (f32) (temp_ft1 + (matrix[0] - result.rotated[0]));
      ((Field_f32 *) (((char *) arg4) + 4))->v = (f32) (temp_fv0 + (matrix[1] - result.rotated[1]));
      ((Field_f32 *) (((char *) arg4) + 8))->v = (f32) (vec70.z + (matrix[2] - result.rotated[2]));
      vec118 = *(SweepVec *) sp134;
      vec118.x += ((Field_f32 *) (((char *) arg4) + 0))->v;
      vec118.y += ((Field_f32 *) (((char *) arg4) + 4))->v;
      vec118.z += ((Field_f32 *) (((char *) arg4) + 8))->v;
    }
    if (arg5 != NULL)
    {
      ((Field_f32 *) (((char *) arg5) + 0))->v = vecA8.x;
      ((Field_f32 *) (((char *) arg5) + 4))->v = vecA8.y;
      ((Field_f32 *) (((char *) arg5) + 8))->v = vecA8.z;
    }
    return 1;
  }
  block_131:
  return 0;

}

