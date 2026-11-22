s8 Sphere_OverlapsPoint(void *, void *, f32);
s32 buildPlaneFromPoints(f32 *, s32, s32, s32);
s32 buildRotationMatrix(s16 *, f32 *);
s32 buildRotationMatrixCopy(s16 *, f32 *);
s32 buildRotationMatrixS16(s16 *, f32 *);
s32 buildRotationMatrixS16Copy(s16 *, f32 *);
f32 func_80047AB0(f32 *, f32 *);
s32 func_800487F0(void *, void *, f32);
s32 func_8004E418(void *, f32 *, f32 *);
f32 func_80082908(f32);
s32 func_80083B64(f32 *, f32 *);
s32 rotateVec3ByMat3(f32 *, f32 *);
s32 segmentClosestPoint(f32 *, s32, s32, f32 *);
s8 triangleContainsPoint(void *, s32, s32, s32, f32 *);
extern f64 D_800D3E70;
extern f64 D_800D3E78;
extern f64 D_800D3E80;
extern f64 D_800D3E88;
extern u16 gSurfaceQueryStamp;
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} SurfaceVec3;
inline static u16 inline_fn(u16 arg0)
{
  return arg0;
}

inline static void **inline_fn2(void *arg0)
{
  return (void **) (((char *) arg0) + 0);
}

inline static int inline_fn23(f32 arg0, f32 arg1)
{
  return !(arg0 < arg1);
}

s8 func_8004FF30(void *arg0, void *arg1, void *arg2, f32 arg3, s32 arg4, s32 *arg5, void **arg6, s32 arg7)
{
  union 
  {
    f32 vsp18[3];
    struct 
    {
      u8 pad[0x10];
      f32 values[9];
    } vsp28;
    struct 
    {
      u8 pad[0x20];
      f32 values[3];
    } vsp38;
    struct 
    {
      u8 pad[0x40];
      f32 values[9];
    } vsp58;
    struct 
    {
      u8 pad[0x70];
      s16 values[3];
    } vsp88;
    struct 
    {
      u8 pad[0x78];
      f32 values[4];
    } vsp90;
    struct 
    {
      u8 pad[0x88];
      f32 values[9];
    } vspA0;
    struct 
    {
      u8 pad[0x98];
      f32 values[3];
    } vspB0;
    struct 
    {
      u8 pad[0xa8];
      f32 values[3];
    } vspC0;
    struct 
    {
      u8 pad[0xb0];
      f32 values[4];
    } vspC8;
    struct 
    {
      u8 pad[0xb8];
      f32 values[3];
    } vspD0;
    struct 
    {
      u8 pad[0xc0];
      f32 values[3];
    } boundsMin;
    struct 
    {
      u8 pad[0xc8];
      f32 values[3];
    } correction;
    struct 
    {
      u8 pad[0xd8];
      f32 values[3];
    } vspF0;
    struct 
    {
      u8 pad[0xe8];
      f32 values[9];
    } vsp100;
    struct 
    {
      u8 pad[0x110];
      f32 values[3];
    } vsp128;
    struct 
    {
      u8 pad[0x120];
      f32 values[3];
    } vsp138;
    struct 
    {
      u8 pad[0x130];
      f32 values[3];
    } vsp148;
    struct 
    {
      u8 pad[0x140];
      f32 values[3];
    } vsp158;
    struct 
    {
      u8 pad[0x150];
      f32 values[3];
    } vsp168;
    struct 
    {
      u8 pad[0x30];
      f32 values[3];
    } chosenPoint;
  } scratch;
  u8 sp187;
  void *sp18C;
  void *sp17C;
  volatile u16 sp196;
  f32 *sp19C;
  f32 *sp1AC;
  void *temp_v1;
  f32 *sp1B4;
  f32 *sp1BC;
  f32 *sp1CC;
  f32 *sp1C4;
  f32 *sp1D4;
  u16 sp1E6;
  u16 sp1DE;
  f32 *sp1EC;
  f32 *sp1FC;
  f32 *sp1F4;
  f32 temp_fs0;
  f32 temp_fs0_2;
  f32 temp_fs0_3;
  f32 temp_fs0_4;
  f32 temp_fs0_5;
  f32 temp_fs0_6;
  f32 temp_fs0_7;
  f32 temp_fs0_8;
  f32 temp_fs1;
  f32 temp_fs1_2;
  f32 temp_fs1_3;
  f32 temp_fs1_4;
  f32 temp_fs4;
  f32 temp_ft0;
  f32 temp_ft0_2;
  register f32 temp_ft0_3;
  f32 temp_ft0_4;
  f32 temp_ft0_5;
  f32 temp_ft0_6;
  f32 temp_ft0_7;
  f32 temp_ft0_8;
  f32 temp_ft1;
  f32 temp_ft1_2;
  f32 temp_ft1_3;
  f32 temp_ft1_4;
  f32 temp_fv0;
  f32 temp_fv0_10;
  f32 temp_fv0_11;
  f32 temp_fv0_12;
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
  f32 temp_fv1_3;
  register f32 temp_fv1_4;
  f32 var_a0;
  f32 var_a0_2;
  f32 var_a0_3;
  f32 var_a0_4;
  f32 var_fa0;
  f32 var_fa0_2;
  f32 var_fa0_3;
  f32 var_fa0_4;
  f32 var_fa0_5;
  f32 var_fa0_6;
  f32 var_fa0_7;
  f32 var_fa0_8;
  s32 temp_a0_2;
  s32 temp_a3;
  s32 temp_a3_2;
  s32 temp_a3_3;
  s32 temp_a3_4;
  s32 temp_s0_2;
  s32 temp_s0_3;
  s32 temp_s0_4;
  s32 temp_s0_5;
  s32 temp_s1;
  long temp_s1_2;
  s32 temp_s1_5;
  s32 temp_s1_7;
  s32 temp_s2;
  s32 temp_s2_2;
  s32 temp_s2_3;
  s32 temp_s2_4;
  unsigned int temp_v0_2;
  s32 temp_v1_10;
  s32 temp_v1_3;
  s32 temp_v1_4;
  s32 temp_v1_6;
  s32 temp_v1_7;
  s32 var_s5_3;
  s32 var_s5_4;
  unsigned long var_v0;
  s32 var_v0_10;
  s32 var_v0_11;
  s32 var_v0_12;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v0_5;
  register s32 var_v0_6;
  s32 var_v0_7;
  s32 var_v0_8;
  s32 var_v0_9;
  s32 var_v1;
  long var_v1_10;
  s32 var_v1_11;
  unsigned int var_v1_12;
  s32 var_v1_2;
  int var_v1_3;
  s32 var_v1_4;
  s32 var_v1_5;
  s32 var_v1_6;
  s32 var_v1_7;
  unsigned long var_v1_8;
  s32 var_v1_9;
  register u16 *var_fp;
  u8 *var_fp_2;
  s32 temp_a0;
  s32 temp_v1_9;
  u32 temp_s0;
  u32 temp_s1_3;
  u32 temp_v1_11;
  u32 temp_v1_2;
  u32 temp_v1_5;
  u32 temp_v1_8;
  void *temp_s1_4;
  void *temp_s1_6;
  void *temp_s4;
  void *temp_t1;
  s16 *sp1A4;
  void *temp_t1_2;
  void *temp_v0;
  void *var_s0;
  void *var_s4;
  void *var_s5;
  void *var_s5_2;
  void *var_s6;
  var_s0 = arg0;
  sp17C = arg2;
  sp187 = 0;
  temp_fs4 = arg3 * arg3;
  if (var_s0 == NULL)
  {
    return 0;
  }
  sp19C = &scratch.vsp18[0];
  sp1A4 = &scratch.vsp88.values[0];
  sp1AC = &scratch.vsp28.values[0];
  sp1B4 = &scratch.vsp90.values[0];
  gSurfaceQueryStamp += 1;
  sp18C = *((void **) (((char *) (*((void **) (((char *) var_s0) + 0x20)))) + 0x58));
  for (;;)
  {
    var_s6 = var_s0;
    *((u16 *) (((char *) (*((void **) (((char *) var_s0) + 0x20)))) + 0x60)) = (u16) ((s32) gSurfaceQueryStamp);
    if (var_s0 != NULL)
    {
      var_s4 = *((void **) (((char *) var_s0) + 0));
      if (var_s4 != NULL)
      {
        sp1BC = &scratch.vspB0.values[0];
        sp1C4 = &scratch.vspC0.values[0];
        sp1CC = &scratch.vspD0.values[0];
        do
        {
          if (var_s4 != arg7)
          {
            temp_s1_4 = *((void **) (((char *) var_s4) + 0x70)); temp_v1 = (void *) temp_s1_4;
            if (temp_v1 != NULL)
            {
              temp_s1_6 = (void *) (*((s32 *) (((char *) var_s4) + 0x58))); temp_s0 = ((u32) temp_s1_6) & 0x400;
              if (((temp_s0 == 0) && ((*((s32 *) (((char *) var_s4) + 0x5C))) & 0x200)) && (((s8) func_800487F0(var_s4, arg1, arg3)) != 0))
              {
                *((SurfaceVec3 *) scratch.vsp18) = *((SurfaceVec3 *) arg1);
                scratch.vsp88.values[0] = (s16) ((s32) (-(*((f32 *) (((char *) var_s4) + 0x3C)))));
                scratch.vsp88.values[1] = (s16) ((s32) (-(*((f32 *) (((char *) var_s4) + 0x40)))));
                scratch.vsp88.values[2] = (s16) ((s32) (-(*((f32 *) (((char *) var_s4) + 0x44)))));
                buildRotationMatrix(sp1A4, sp1AC);
                scratch.vsp18[0] -= *((f32 *) (((char *) var_s4) + 0x24));
                scratch.vsp18[1] -= *((f32 *) (((char *) var_s4) + 0x28));
                scratch.vsp18[2] -= *((f32 *) (((char *) var_s4) + 0x2C));
                rotateVec3ByMat3(sp1AC, sp19C);
                scratch.vsp88.values[0] = (s16) ((s32) (*((f32 *) (((char *) var_s4) + 0x3C))));
                scratch.vsp88.values[1] = (s16) ((s32) (*((f32 *) (((char *) var_s4) + 0x40))));
                scratch.vsp88.values[2] = (s16) ((s32) (*((f32 *) (((char *) var_s4) + 0x44))));
                buildRotationMatrixS16(sp1A4, scratch.vsp58.values);
                temp_s1_4 = (void *) (*((u8 *) (((char *) temp_v1) + 0x48))); temp_v1_2 = ((u32) temp_s1_4) & 4;
                if (temp_v1_2)
                {
                  var_fp = *((u16 **) (((char *) temp_v1) + 0x3C));
                  if (temp_s0 < ((u16) (*((u16 *) (((char *) temp_v1) + 0x40)))))
                  {
                    sp196 = 0;
                    var_s5 = (void *) (2 + var_fp);
                    do
                    {
                      temp_v1_3 = *((s32 *) (((char *) temp_v1) + 0x34));
                      buildPlaneFromPoints(sp1B4, temp_v1_3 + ((*var_fp) * 0xC), temp_v1_3 + ((*((u16 *) (((char *) var_s5) + (-2)))) * 0xC), temp_v1_3 + ((*((u16 *) (((char *) var_s5) + 0))) * 0xC));
                      temp_fs0 = (((scratch.vsp90.values[0] * scratch.vsp18[0]) + (scratch.vsp90.values[1] * scratch.vsp18[1])) + (scratch.vsp90.values[2] * scratch.vsp18[2])) + scratch.vsp90.values[3];
                      var_v0 = 1;
                      if (!(temp_fs0 > 0.0f))
                      {
                        var_v0 = 0;
                      }
                      var_v1 = 1;
                      if (inline_fn23(temp_fs0, arg3))
                      {
                        var_v1 = 0;
                      }
                      if (var_v0 & var_v1)
                      {
                        *((f32 *) (((char *) sp17C) + 0)) = (f32) (scratch.vsp18[0] - (temp_fs0 * scratch.vsp90.values[0]));
                        *((f32 *) (((char *) sp17C) + 4)) = (f32) (scratch.vsp18[1] - (temp_fs0 * scratch.vsp90.values[1]));
                        *((f32 *) (((char *) sp17C) + 8)) = (f32) (scratch.vsp18[2] - (temp_fs0 * scratch.vsp90.values[2]));
                        temp_a3 = *((s32 *) (((char *) temp_v1) + 0x34));
                        temp_s2 = temp_a3 + ((*var_fp) * 0xC);
                        temp_s0_2 = temp_a3 + (((*((u16 *) (((char *) var_s5) + (-2)))) * 4) * 3);
                        temp_s1 = temp_a3 + ((*((u16 *) (((char *) var_s5) + 0))) * 0xC);
                        if (triangleContainsPoint(sp17C, temp_s2, temp_s0_2, temp_s1, sp1B4) != 0)
                        {
                          goto block_37_plane;
                        }
                        segmentClosestPoint(sp1BC, temp_s2, temp_s0_2, &scratch.vsp18[0]);
                        temp_fs0_2 = func_80047AB0(sp1BC, &scratch.vsp18[0]);
                        segmentClosestPoint(sp1C4, temp_s0_2, temp_s1, &scratch.vsp18[0]);
                        temp_fs1 = func_80047AB0(sp1C4, &scratch.vsp18[0]);
                        segmentClosestPoint(sp1CC, temp_s1, temp_s2, &scratch.vsp18[0]);
                        temp_fv0_2 = func_80047AB0(sp1CC, &scratch.vsp18[0]);
                        var_fa0_2 = temp_fs0_2;
                        var_a0 = scratch.vspB0.values[2];
                        *((SurfaceVec3 *) scratch.vspA0.values) = *((SurfaceVec3 *) scratch.vspB0.values);
                        var_v0_2 = 1;
                        if (inline_fn23(temp_fs1, var_fa0_2))
                        {
                          var_v0_2 = 0;
                        }
                        var_v1_2 = 1;
                        if ((float) inline_fn23(temp_fs1, temp_fv0_2))
                        {
                          var_v1_2 = 0;
                        }
                        if (var_v0_2 & var_v1_2)
                        {
                          var_a0 = scratch.vspC0.values[2];
                          *((SurfaceVec3 *) scratch.vspA0.values) = *((SurfaceVec3 *) scratch.vspC0.values);
                          var_fa0_2 = temp_fs1;
                        }
                        else
                        {
                          var_v0_3 = 1;
                          if (!(temp_fv0_2 < var_fa0_2))
                          {
                            var_v0_3 = 0;
                          }
                          var_v1_3 = 1;
                          if (inline_fn23(temp_fv0_2, temp_fs1))
                          {
                            var_v1_3 = 0;
                          }
                          if (var_v0_3 & var_v1_3)
                          {
                            var_a0 = scratch.vspD0.values[2];
                            *((SurfaceVec3 *) scratch.vspA0.values) = *((SurfaceVec3 *) scratch.vspD0.values);
                            var_fa0_2 = temp_fv0_2;
                          }
                        }
                        if (var_fa0_2 < temp_fs4)
                        {
                          var_fa0 = (f32) (D_800D3E70 - ((f64) (func_80082908(var_fa0_2) / arg3)));
                          temp_ft0_2 = var_fa0 * (scratch.vsp18[0] - scratch.vspA0.values[0]);
                          temp_fv0_3 = var_fa0 * (scratch.vsp18[2] - scratch.vspA0.values[2]);
                          temp_fv1 = var_fa0 * (scratch.vsp18[1] - scratch.vspA0.values[1]);
                          scratch.correction.values[0] = temp_ft0_2;
                          scratch.correction.values[2] = temp_fv0_3;
                          scratch.vsp18[0] += temp_ft0_2;
                          scratch.correction.values[1] = temp_fv1;
                          scratch.vsp18[2] += temp_fv0_3;
                          scratch.vsp18[1] += temp_fv1;
                          rotateVec3ByMat3(scratch.vsp58.values, &scratch.correction.values[0]);
                          goto block_37_after_call;
                        }
                        goto block_37_done;
                        block_37_plane:
                        var_fa0 = arg3 - temp_fs0;

                        temp_ft1 = var_fa0 * scratch.vsp90.values[0];
                        temp_ft0 = var_fa0 * scratch.vsp90.values[1];
                        temp_fv0 = var_fa0 * scratch.vsp90.values[2];
                        scratch.correction.values[0] = temp_ft1;
                        scratch.correction.values[1] = temp_ft0;
                        scratch.correction.values[2] = temp_fv0;
                        scratch.vsp18[0] += temp_ft1;
                        scratch.vsp18[1] += temp_ft0;
                        scratch.vsp18[2] += temp_fv0;
                        {
                          block_37:
                          rotateVec3ByMat3(scratch.vsp58.values, &scratch.correction.values[0]);

                          block_37_after_call:
                          if (arg6)
                          {
                            *((f32 *) (((char *) arg1) + 0)) = (f32) ((*((f32 *) (((char *) arg1) + 0))) + scratch.correction.values[0]);
                            *((f32 *) (((char *) arg1) + 4)) = (f32) ((*((f32 *) (((char *) arg1) + 4))) + scratch.correction.values[1]);
                            *((f32 *) (((char *) arg1) + 8)) = (f32) ((*((f32 *) (((char *) arg1) + 8))) + scratch.correction.values[2]);
                            sp187 = 1;
                            *((s32 *) (((char *) var_s4) + 0x60)) = (s32) ((*((s32 *) (((char *) var_s4) + 0x60))) | arg4);
                          }
                          else
                          {
                            *((f32 *) (((char *) arg1) + 0)) = (f32) ((*((f32 *) (((char *) arg1) + 0))) + scratch.correction.values[0]);
                            *((f32 *) (((char *) arg1) + 4)) = (f32) ((*((f32 *) (((char *) arg1) + 4))) + scratch.correction.values[1]);
                            *((f32 *) (((char *) arg1) + 8)) = (f32) ((*((f32 *) (((char *) arg1) + 8))) + scratch.correction.values[2]);
                            sp187 = 1;
                            *((s32 *) (((char *) var_s4) + 0x60)) = (s32) ((*((s32 *) (((char *) var_s4) + 0x60))) | arg4);
                          }

                          block_37_done:
                          ;

                          ;
                        }
                      }
                      sp196 += 1;
                      var_s5 += 6;
                      var_fp += 3;
                    }
                    while (sp196 < inline_fn((u16) (*((u16 *) (((char *) temp_v1) + 0x40)))));
                  }
                }
                else
                {
                  temp_s4 = *((u8 **) (((char *) temp_v1) + 0x3C)); var_fp_2 = (u8 *) temp_s4;
                  if (temp_v1_2 < ((u16) (*((u16 *) (((char *) temp_v1) + 0x40)))))
                  {
                    u16 __block_sp196;
                    __block_sp196 = 0;
                    var_s5_2 = (void *) (2 + var_fp_2);
                    do
                    {
                      temp_v1_4 = *((s32 *) (((char *) temp_v1) + 0x34));
                      buildPlaneFromPoints(sp1B4, temp_v1_4 + ((*var_fp_2) * 0xC), temp_v1_4 + ((*((u8 *) (((char *) var_s5_2) + (-1)))) * 0xC), temp_v1_4 + ((*((u8 *) (((char *) var_s5_2) + 0))) * 0xC));
                      temp_fs0_3 = (((scratch.vsp90.values[0] * scratch.vsp18[0]) + (scratch.vsp90.values[1] * scratch.vsp18[1])) + (scratch.vsp90.values[2] * scratch.vsp18[2])) + scratch.vsp90.values[3];
                      var_v0_4 = 1;
                      if (!(temp_fs0_3 > 0.0f))
                      {
                        var_v0_4 = 0;
                      }
                      var_v1_4 = 1;
                      if (!(temp_fs0_3 < arg3))
                      {
                        var_v1_4 = 0;
                      }
                      if (var_v0_4 & var_v1_4)
                      {
                        *((f32 *) (((char *) sp17C) + 0)) = (f32) (scratch.vsp18[0] - (temp_fs0_3 * scratch.vsp90.values[0]));
                        *((f32 *) (((char *) sp17C) + 4)) = (f32) (scratch.vsp18[1] - (temp_fs0_3 * scratch.vsp90.values[1]));
                        *((f32 *) (((char *) sp17C) + 8)) = (f32) (scratch.vsp18[2] - (temp_fs0_3 * scratch.vsp90.values[2]));
                        temp_a3_2 = *((s32 *) (((char *) temp_v1) + 0x34));
                        temp_s1_2 = temp_a3_2 + ((*((u8 *) (((char *) var_s5_2) + 0))) * 0xC);
                        temp_s2_2 = temp_a3_2 + ((*var_fp_2) * 0xC);
                        temp_s0_3 = temp_a3_2 + ((*((u8 *) (((char *) var_s5_2) + (-1)))) * 0xC);
                        if (triangleContainsPoint(sp17C, (s32) temp_s2_2, temp_s0_3, temp_s1_2, sp1B4) != 0)
                        {
                          goto block_65_plane;
                        }
                        segmentClosestPoint(sp1BC, temp_s2_2, temp_s0_3, &scratch.vsp18[0]);
                        temp_fs0_4 = func_80047AB0(sp1BC, &scratch.vsp18[0]);
                        segmentClosestPoint(sp1C4, temp_s0_3, temp_s1_2, &scratch.vsp18[0]);
                        temp_fs1_2 = func_80047AB0(sp1C4, &scratch.vsp18[0]);
                        segmentClosestPoint(sp1CC, temp_s1_2, temp_s2_2, &scratch.vsp18[0]);
                        var_fa0_4 = temp_fs0_4;
                        temp_fv0_5 = func_80047AB0(sp1CC, &scratch.vsp18[0]);
                        var_a0_2 = scratch.vspB0.values[2];
                        *((SurfaceVec3 *) scratch.vspA0.values) = *((SurfaceVec3 *) scratch.vspB0.values);
                        var_v0_5 = 1;
                        if (!(temp_fs1_2 < var_fa0_4))
                        {
                          var_v0_5 = 0;
                        }
                        var_v1_5 = 1;
                        if (inline_fn23(temp_fs1_2, temp_fv0_5))
                        {
                          var_v1_5 = 0;
                        }
                        if (var_v0_5 & var_v1_5)
                        {
                          var_a0_2 = scratch.vspC0.values[2];
                          *((SurfaceVec3 *) scratch.vspA0.values) = *((SurfaceVec3 *) scratch.vspC0.values);
                          var_fa0_4 = temp_fs1_2;
                        }
                        else
                        {
                          var_v0_6 = 1;
                          if (inline_fn23(temp_fv0_5, var_fa0_4))
                          {
                            var_v0_6 = 0;
                          }
                          var_v1_6 = 1;
                          if (inline_fn23(temp_fv0_5, temp_fs1_2))
                          {
                            var_v1_6 = 0;
                          }
                          if (var_v0_6 & var_v1_6)
                          {
                            var_a0_2 = scratch.vspD0.values[2];
                            *((SurfaceVec3 *) scratch.vspA0.values) = *((SurfaceVec3 *) scratch.vspD0.values);
                            var_fa0_4 = temp_fv0_5;
                          }
                        }
                        if (temp_fs4 > var_fa0_4)
                        {
                          var_fa0_3 = (f32) (D_800D3E78 - ((f64) (func_80082908(var_fa0_4) / arg3)));
                          temp_ft0_4 = var_fa0_3 * (scratch.vsp18[0] - scratch.vspA0.values[0]);
                          temp_fv0_6 = var_fa0_3 * (scratch.vsp18[2] - scratch.vspA0.values[2]);
                          temp_fv1_2 = var_fa0_3 * (scratch.vsp18[1] - scratch.vspA0.values[1]);
                          scratch.vspF0.values[0] = temp_ft0_4;
                          scratch.vsp18[0] += temp_ft0_4;
                          scratch.vspF0.values[2] = temp_fv0_6;
                          scratch.vspF0.values[1] = temp_fv1_2;
                          scratch.vsp18[1] += temp_fv1_2;
                          scratch.vsp18[2] += temp_fv0_6;
                          rotateVec3ByMat3(scratch.vsp58.values, &scratch.vspF0.values[0]);
                          goto block_65_after_call;
                        }
                        goto block_65_done;
                        block_65_plane:
                        var_fa0_3 = arg3 - temp_fs0_3;

                        temp_ft1_2 = var_fa0_3 * scratch.vsp90.values[0];
                        temp_ft0_3 = var_fa0_3 * scratch.vsp90.values[1];
                        temp_fv0_4 = var_fa0_3 * scratch.vsp90.values[2];
                        scratch.vspF0.values[0] = temp_ft1_2;
                        scratch.vspF0.values[1] = temp_ft0_3;
                        scratch.vspF0.values[2] = temp_fv0_4;
                        scratch.vsp18[0] += temp_ft1_2;
                        scratch.vsp18[1] += temp_ft0_3;
                        scratch.vsp18[2] += temp_fv0_4;
                        {
                          block_65:
                          rotateVec3ByMat3(scratch.vsp58.values, &scratch.vspF0.values[0]);

                          block_65_after_call:
                          *((f32 *) (((char *) arg1) + 0)) = (f32) ((*((f32 *) (((char *) arg1) + 0))) + scratch.vspF0.values[0]);

                          *((f32 *) (((char *) arg1) + 4)) = (f32) ((*((f32 *) (((char *) arg1) + 4))) + scratch.vspF0.values[1]);
                          *((f32 *) (((char *) arg1) + 8)) = (f32) ((*((f32 *) (((char *) arg1) + 8))) + scratch.vspF0.values[2]);
                          sp187 = 1;
                          *((s32 *) (((char *) var_s4) + 0x60)) = (s32) ((*((s32 *) (((char *) var_s4) + 0x60))) | arg4);
                        }
                        block_65_done:
                        ;

                        ;
                      }
                      var_s5_2 += 3;
                      var_fp_2 += 3;
                      __block_sp196 += 1;
                    }
                    while (__block_sp196 < ((u16) (*((u16 *) (((char *) temp_v1) + 0x40)))));
                  }
                }
              }
            }
          }
          var_s4 = *((void **) (((char *) var_s4) + 0));
        }
        while (var_s4 != NULL);
      }
      if (var_s6 != NULL)
      {
        sp1D4 = &scratch.vspA0.values[0];
        sp1EC = scratch.vspC8.values;
        sp1F4 = &scratch.vsp128.values[0];
        sp1FC = &scratch.vsp138.values[0];
        do
        {
          temp_s4 = *((void **) (((char *) var_s6) + 0x3C));
          if ((*((s32 *) (((char *) var_s6) + 0x50))) & 0x200)
          {
            temp_s1_3 = (((u32) (*((u32 *) (((char *) var_s6) + 0x5C)))) >> 0x17) & 0x20;
            if ((!temp_s1_3) && (Sphere_OverlapsPoint(var_s6 + 0x40, arg1, arg3) != 0))
            {
              *((SurfaceVec3 *) scratch.vsp28.values) = *((SurfaceVec3 *) arg1);
              scratch.vsp28.values[0] -= *((f32 *) (((char *) var_s6) + 0x24));
              scratch.vsp28.values[1] -= *((f32 *) (((char *) var_s6) + 0x28));
              scratch.vsp28.values[2] -= *((f32 *) (((char *) var_s6) + 0x2C));
              scratch.vsp88.values[0] = (s16) ((s32) (-((*((f32 *) (((char *) var_s6) + 0x30))) * 651.8986f)));
              scratch.vsp88.values[1] = (s16) ((s32) (-((*((f32 *) (((char *) var_s6) + 0x34))) * 651.8986f)));
              scratch.vsp88.values[2] = (s16) ((s32) (-((*((f32 *) (((char *) var_s6) + 0x38))) * 651.8986f)));
              buildRotationMatrixCopy(sp1A4, sp1D4);
              scratch.vsp88.values[0] = (s16) ((s32) ((*((f32 *) (((char *) var_s6) + 0x30))) * 651.8986f));
              scratch.vsp88.values[1] = (s16) ((s32) ((*((f32 *) (((char *) var_s6) + 0x34))) * 651.8986f));
              scratch.vsp88.values[2] = (s16) ((s32) ((*((f32 *) (((char *) var_s6) + 0x38))) * 651.8986f));
              buildRotationMatrixS16Copy(sp1A4, scratch.vsp100.values);
              func_80083B64(sp1D4, sp1AC);
              temp_v0 = *((void **) (((char *) var_s6) + 0x3C));
              if (((((((*((f32 *) (((char *) temp_v0) + 0x18))) < (scratch.vsp28.values[0] + arg3)) && ((scratch.vsp28.values[0] - arg3) < (*((f32 *) (((char *) temp_v0) + 0x1C))))) && ((*((f32 *) (((char *) temp_v0) + 0x28))) < (scratch.vsp28.values[2] + arg3))) && ((scratch.vsp28.values[2] - arg3) < (*((f32 *) (((char *) temp_v0) + 0x2C))))) && ((*((f32 *) (((char *) temp_v0) + 0x20))) < (scratch.vsp28.values[1] + arg3))) && ((scratch.vsp28.values[1] - arg3) < (*((f32 *) (((char *) temp_v0) + 0x24)))))
              {
                *((SurfaceVec3 *) scratch.vsp38.values) = *((SurfaceVec3 *) scratch.vsp28.values);
                *((SurfaceVec3 *) scratch.boundsMin.values) = *((SurfaceVec3 *) scratch.vsp38.values);
                scratch.boundsMin.values[0] -= arg3;
                scratch.boundsMin.values[2] -= arg3;
                scratch.vsp38.values[0] += arg3;
                scratch.vsp38.values[2] += arg3;
                temp_v0_2 = func_8004E418((*((void **) (((char *) var_s6) + 0x3C))) + 0x18, &scratch.boundsMin.values[0], &scratch.vsp38.values[0]);
                sp1DE = temp_v0_2 & 0xFF;
                temp_v1_5 = (*((u8 *) (((char *) temp_s4) + 0x48))) & 4;
                sp1E6 = temp_v0_2 & 0xFF00;
                if (temp_v1_5 != 0)
                {
                  if (temp_s1_3 < ((u16) (*((u16 *) (((char *) temp_s4) + 0x40)))))
                  {
                    var_s5_4 = 0;
                    do
                    {
                      temp_v1_6 = var_s5_4 & 0xFFFF;
                      temp_s1_4 = (*((s32 *) (((char *) temp_s4) + 0x3C))) + (temp_v1_6 * 6);
                      temp_a0 = *((u16 *) (((char *) (*((void **) (((char *) temp_s4) + 0x38)))) + (temp_v1_6 * 2)));
                      if ((sp1DE & temp_a0) && (sp1E6 & temp_a0))
                      {
                        temp_v1_7 = *((s32 *) (((char *) temp_s4) + 0x34));
                        buildPlaneFromPoints(sp1EC, temp_v1_7 + (((*((u16 *) (((char *) temp_s1_4) + 0))) * 4) * 3), temp_v1_7 + ((*((u16 *) (((char *) temp_s1_4) + 2))) * 0xC), temp_v1_7 + ((*((u16 *) (((char *) temp_s1_4) + 4))) * 0xC));
                        temp_fs0_5 = (((scratch.vspC8.values[0] * scratch.vsp28.values[0]) + (scratch.vspC8.values[1] * scratch.vsp28.values[1])) + (scratch.vspC8.values[2] * scratch.vsp28.values[2])) + scratch.vspC8.values[3];
                        var_v0_7 = 1;
                        if (!(temp_fs0_5 > 0.0f))
                        {
                          var_v0_7 = 0;
                        }
                        var_v1_7 = 1;
                        if (inline_fn23(temp_fs0_5, arg3))
                        {
                          var_v1_7 = 0;
                        }
                        if (var_v0_7 & var_v1_7)
                        {
                          *((f32 *) (((char *) sp17C) + 0)) = (f32) (scratch.vsp28.values[0] - (temp_fs0_5 * scratch.vspC8.values[0]));
                          *((f32 *) (((char *) sp17C) + 4)) = (f32) (scratch.vsp28.values[1] - (temp_fs0_5 * scratch.vspC8.values[1]));
                          *((f32 *) (((char *) sp17C) + 8)) = (f32) (scratch.vsp28.values[2] - (temp_fs0_5 * scratch.vspC8.values[2]));
                          temp_a3_3 = *((s32 *) (((char *) temp_s4) + 0x34));
                          temp_s2_3 = temp_a3_3 + ((*((u16 *) (((char *) temp_s1_4) + 0))) * 0xC);
                          temp_s0_4 = temp_a3_3 + ((*((u16 *) (((char *) temp_s1_4) + 2))) * 0xC);
                          temp_s1_5 = temp_a3_3 + ((*((u16 *) (((char *) temp_s1_4) + 4))) * 0xC);
                          if (triangleContainsPoint(sp17C, temp_s2_3, temp_s0_4, temp_s1_5, sp1EC) != 0)
                          {
                            goto block_106_plane;
                          }
                          segmentClosestPoint(sp1F4, temp_s2_3, temp_s0_4, sp1AC);
                          temp_fs0_6 = func_80047AB0(sp1F4, sp1AC);
                          segmentClosestPoint(sp1FC, temp_s0_4, temp_s1_5, sp1AC);
                          temp_fs1_3 = func_80047AB0(sp1FC, sp1AC);
                          segmentClosestPoint(&scratch.vsp148.values[0], temp_s1_5, temp_s2_3, sp1AC);
                          temp_fv0_8 = func_80047AB0(&scratch.vsp148.values[0], sp1AC);
                          var_fa0_6 = temp_fs0_6;
                          *((SurfaceVec3 *) scratch.chosenPoint.values) = *((SurfaceVec3 *) scratch.vsp128.values);
                          var_v0_8 = 1;
                          if (inline_fn23(temp_fs1_3, var_fa0_6))
                          {
                            var_v0_8 = 0;
                          }
                          var_v1_8 = 1;
                          if (inline_fn23(temp_fs1_3, temp_fv0_8))
                          {
                            var_v1_8 = 0;
                          }
                          if (var_v0_8 & var_v1_8)
                          {
                            *((SurfaceVec3 *) scratch.chosenPoint.values) = *((SurfaceVec3 *) scratch.vsp138.values);
                            var_fa0_6 = temp_fs1_3;
                          }
                          else
                          {
                            var_v0_9 = 1;
                            if (inline_fn23(temp_fv0_8, var_fa0_6))
                            {
                              var_v0_9 = 0;
                            }
                            var_v1_9 = 1;
                            if (inline_fn23(temp_fv0_8, temp_fs1_3))
                            {
                              var_v1_9 = 0;
                            }
                            if (var_v0_9 & var_v1_9)
                            {
                              ((u32 *) scratch.chosenPoint.values)[0] = ((u32 *) scratch.vsp148.values)[0];
                              ((u32 *) scratch.chosenPoint.values)[1] = ((u32 *) scratch.vsp148.values)[1];
                              ((u32 *) scratch.chosenPoint.values)[2] = ((u32 *) scratch.vsp148.values)[2];
                              var_fa0_6 = temp_fv0_8;
                            }
                          }
                          if (var_fa0_6 < temp_fs4)
                          {
                            var_fa0_5 = (f32) (D_800D3E80 - ((f64) (func_80082908(var_fa0_6) / arg3)));
                            temp_ft0_6 = var_fa0_5 * (scratch.vsp28.values[0] - scratch.chosenPoint.values[0]);
                            temp_fv0_9 = var_fa0_5 * (scratch.vsp28.values[2] - scratch.chosenPoint.values[2]);
                            temp_fv1_3 = var_fa0_5 * (scratch.vsp28.values[1] - scratch.chosenPoint.values[1]);
                            scratch.vsp158.values[0] = temp_ft0_6;
                            scratch.vsp158.values[2] = temp_fv0_9;
                            scratch.vsp28.values[0] += temp_ft0_6;
                            scratch.vsp158.values[1] = temp_fv1_3;
                            scratch.vsp28.values[1] += temp_fv1_3;
                            scratch.vsp28.values[2] += temp_fv0_9;
                            func_80083B64(scratch.vsp100.values, &scratch.vsp158.values[0]);
                            goto block_106_after_call;
                          }
                          goto block_106_done;
                          block_106_plane:
                          var_fa0_5 = arg3 - temp_fs0_5;

                          temp_ft1_3 = var_fa0_5 * scratch.vspC8.values[0];
                          temp_ft0_5 = var_fa0_5 * scratch.vspC8.values[1];
                          temp_fv0_7 = var_fa0_5 * scratch.vspC8.values[2];
                          scratch.vsp158.values[0] = temp_ft1_3;
                          scratch.vsp158.values[1] = temp_ft0_5;
                          scratch.vsp158.values[2] = temp_fv0_7;
                          scratch.vsp28.values[0] += temp_ft1_3;
                          scratch.vsp28.values[1] += temp_ft0_5;
                          scratch.vsp28.values[2] += temp_fv0_7;
                          {
                            block_106:
                            func_80083B64(scratch.vsp100.values, &scratch.vsp158.values[0]);

                            block_106_after_call:
                            *((f32 *) (((char *) arg1) + 0)) = (f32) ((*((f32 *) (((char *) arg1) + 0))) + scratch.vsp158.values[0]);

                            *((f32 *) (((char *) arg1) + 4)) = (f32) ((*((f32 *) (((char *) arg1) + 4))) + scratch.vsp158.values[1]);
                            *((f32 *) (((char *) arg1) + 8)) = (f32) ((*((f32 *) (((char *) arg1) + 8))) + scratch.vsp158.values[2]);
                            temp_v1_8 = *((u32 *) (((char *) var_s6) + 0x5C));
                            if (temp_v1_8 & 0x7E0000)
                            {
                              if (arg5 != NULL)
                              {
                                *arg5 = (temp_v1_8 >> 0x11) & 0x3F;
                              }
                              if (arg6 != NULL)
                              {
                                *arg6 = var_s6;
                              }
                            }
                            sp187 = 1;
                          }
                          block_106_done:
                          ;

                          ;
                        }
                      }
                      var_s5_4 += 1;
                    }
                    while (((u32) (var_s5_4 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) temp_s4) + 0x40)))));
                  }
                }
                else
                  if (temp_v1_5 < ((u16) (*((u16 *) (((char *) temp_s4) + 0x40)))))
                {
                  var_s5_4 = 0;
                  do
                  {
                    temp_a0_2 = var_s5_4 & 0xFFFF;
                    temp_v1_9 = *((u16 *) (((char *) (*((void **) (((char *) temp_s4) + 0x38)))) + (temp_a0_2 * 2)));
                    temp_s1_6 = (*((s32 *) (((char *) temp_s4) + 0x3C))) + (temp_a0_2 * 3);
                    if ((sp1DE & temp_v1_9) && (sp1E6 & temp_v1_9))
                    {
                      temp_v1_10 = *((s32 *) (((char *) temp_s4) + 0x34));
                      buildPlaneFromPoints(sp1EC, temp_v1_10 + ((*((u8 *) (((char *) temp_s1_6) + 0))) * 0xC), temp_v1_10 + ((*((u8 *) (((char *) temp_s1_6) + 1))) * 0xC), temp_v1_10 + ((*((u8 *) (((char *) temp_s1_6) + 2))) * 0xC));
                      temp_fs0_7 = (((scratch.vspC8.values[0] * scratch.vsp28.values[0]) + (scratch.vspC8.values[1] * scratch.vsp28.values[1])) + (scratch.vspC8.values[2] * scratch.vsp28.values[2])) + scratch.vspC8.values[3];
                      var_v0_10 = 1;
                      if (!(temp_fs0_7 > 0.0f))
                      {
                        var_v0_10 = 0;
                      }
                      var_v1_10 = 1;
                      if (inline_fn23(temp_fs0_7, arg3))
                      {
                        var_v1_10 = 0;
                      }
                      if (var_v0_10 & var_v1_10)
                      {
                        *((f32 *) (((char *) sp17C) + 0)) = (f32) (scratch.vsp28.values[0] - (temp_fs0_7 * scratch.vspC8.values[0]));
                        *((f32 *) (((char *) sp17C) + 4)) = (f32) (scratch.vsp28.values[1] - (temp_fs0_7 * scratch.vspC8.values[1]));
                        *((f32 *) (((char *) sp17C) + 8)) = (f32) (scratch.vsp28.values[2] - (temp_fs0_7 * scratch.vspC8.values[2]));
                        temp_a3_4 = *((s32 *) (((char *) temp_s4) + 0x34));
                        temp_s2_4 = temp_a3_4 + ((*((u8 *) (((char *) temp_s1_6) + 0))) * 0xC);
                        temp_s0_5 = temp_a3_4 + ((*((u8 *) (((char *) temp_s1_6) + 1))) * 0xC);
                        temp_s1_7 = temp_a3_4 + ((*((u8 *) (((char *) temp_s1_6) + 2))) * 0xC);
                        if (triangleContainsPoint(sp17C, temp_s2_4, temp_s0_5, temp_s1_7, sp1EC) != 0)
                        {
                          goto block_141_plane;
                        }
                        segmentClosestPoint(sp1F4, temp_s2_4, temp_s0_5, sp1AC);
                        temp_fs0_8 = func_80047AB0(sp1F4, sp1AC);
                        segmentClosestPoint(sp1FC, temp_s0_5, temp_s1_7, sp1AC);
                        temp_fs1_4 = func_80047AB0(sp1FC, sp1AC);
                        segmentClosestPoint(&scratch.vsp148.values[0], temp_s1_7, temp_s2_4, sp1AC);
                        temp_fv0_11 = func_80047AB0(&scratch.vsp148.values[0], sp1AC);
                        *((SurfaceVec3 *) scratch.chosenPoint.values) = *((SurfaceVec3 *) scratch.vsp128.values);
                        var_fa0_8 = temp_fs0_8;
                        var_v0_11 = 1;
                        if (inline_fn23(temp_fs1_4, var_fa0_8))
                        {
                          var_v0_11 = 0;
                        }
                        var_v1_11 = 1;
                        if (!(temp_fv0_11 > temp_fs1_4))
                        {
                          var_v1_11 = 0;
                        }
                        if (var_v0_11 & var_v1_11)
                        {
                          ((u32 *) scratch.chosenPoint.values)[0] = ((u32 *) scratch.vsp138.values)[0];
                          ((u32 *) scratch.chosenPoint.values)[1] = ((u32 *) scratch.vsp138.values)[1];
                          ((u32 *) scratch.chosenPoint.values)[2] = ((u32 *) scratch.vsp138.values)[2];
                          var_fa0_8 = temp_fs1_4;
                        }
                        else
                        {
                          var_v0_12 = 1;
                          if (inline_fn23(temp_fv0_11, var_fa0_8))
                          {
                            var_v0_12 = 0;
                          }
                          var_v1_12 = 1;
                          if (inline_fn23(temp_fv0_11, temp_fs1_4))
                          {
                            var_v1_12 = 0;
                          }
                          if (var_v0_12 & var_v1_12)
                          {
                            *((SurfaceVec3 *) scratch.chosenPoint.values) = *((SurfaceVec3 *) scratch.vsp148.values);
                            var_fa0_8 = temp_fv0_11;
                          }
                        }
                        if (var_fa0_8 < temp_fs4)
                        {
                          var_fa0_7 = (f32) (D_800D3E88 - ((f64) (func_80082908(var_fa0_8) / arg3)));
                          temp_ft0_8 = var_fa0_7 * (scratch.vsp28.values[0] - scratch.chosenPoint.values[0]);
                          temp_fv0_12 = var_fa0_7 * (scratch.vsp28.values[2] - scratch.chosenPoint.values[2]);
                          temp_fv1_4 = var_fa0_7 * (scratch.vsp28.values[1] - scratch.chosenPoint.values[1]);
                          scratch.vsp168.values[0] = temp_ft0_8;
                          scratch.vsp168.values[2] = temp_fv0_12;
                          scratch.vsp28.values[0] += temp_ft0_8;
                          scratch.vsp168.values[1] = temp_fv1_4;
                          scratch.vsp28.values[1] += temp_fv1_4;
                          scratch.vsp28.values[2] += temp_fv0_12;
                          func_80083B64(scratch.vsp100.values, &scratch.vsp168.values[0]);
                          goto block_141_after_call;
                        }
                        goto block_141_done;
                        block_141_plane:
                        var_fa0_7 = arg3 - temp_fs0_7;

                        temp_ft1_4 = var_fa0_7 * scratch.vspC8.values[0];
                        temp_ft0_7 = var_fa0_7 * scratch.vspC8.values[1];
                        temp_fv0_10 = var_fa0_7 * scratch.vspC8.values[2];
                        scratch.vsp168.values[0] = temp_ft1_4;
                        scratch.vsp168.values[1] = temp_ft0_7;
                        scratch.vsp168.values[2] = temp_fv0_10;
                        scratch.vsp28.values[0] += temp_ft1_4;
                        scratch.vsp28.values[1] += temp_ft0_7;
                        scratch.vsp28.values[2] += temp_fv0_10;
                        {
                          block_141:
                          func_80083B64(scratch.vsp100.values, &scratch.vsp168.values[0]);

                          block_141_after_call:
                          *((f32 *) (((char *) arg1) + 0)) = (f32) ((*((f32 *) (((char *) arg1) + 0))) + scratch.vsp168.values[0]);

                          *((f32 *) (((char *) arg1) + 4)) = (f32) ((*((f32 *) (((char *) arg1) + 4))) + scratch.vsp168.values[1]);
                          *((f32 *) (((char *) arg1) + 8)) = (f32) ((*((f32 *) (((char *) arg1) + 8))) + scratch.vsp168.values[2]);
                          temp_v1_11 = *((u32 *) (((char *) var_s6) + 0x5C));
                          if (temp_v1_11 & 0x7E0000)
                          {
                            if (arg5 != NULL)
                            {
                              if (!temp_v0)
                              {
                                *arg5 = (temp_v1_11 >> 0x11) & 0x3F;
                              }
                              else
                              {
                                *arg5 = (temp_v1_11 >> 0x11) & 0x3F;
                              }
                            }
                            if (arg6 != NULL)
                            {
                              if (scratch.vsp90.values)
                              {
                                *arg6 = var_s6;
                              }
                              else
                              {
                                *arg6 = var_s6;
                              }
                            }
                          }
                          sp187 = 1;
                        }
                        block_141_done:
                        ;

                        ;
                      }
                    }
                    var_s5_4 += 1;
                  }
                  while (((u32) (var_s5_4 & 0xFFFF)) < ((u16) (*((u16 *) (((char *) temp_s4) + 0x40)))));
                }
              }
            }
          }
          var_s6 = *((void **) (((char *) var_s6) + 0x14));
        }
        while (var_s6 != NULL);
      }
    }
    if (sp18C != NULL)
    {
      loop_153:
      for (;;)
      {
        var_s0 = *((void **) (((char *) sp18C) + 8));
        if ((*((u16 *) (((char *) (*((void **) (((char *) var_s0) + 0x20)))) + 0x60))) != gSurfaceQueryStamp)
        {
          if (sp18C != ((u32) NULL))
          {
            if (Sphere_OverlapsPoint((*((s32 *) (((char *) sp18C) + 4))) + 0x40, arg1, arg3) != 0)
            {
              sp18C = *inline_fn2(sp18C);
              goto block_160;
            }
            temp_t1 = *inline_fn2(sp18C);
            sp18C = temp_t1;
            if (temp_t1 != NULL)
            {
              goto loop_153;
            }
            goto block_160;
          }
          return (s8) sp187;
        }
        temp_t1_2 = *((void **) (((char *) sp18C) + 0));
        sp18C = temp_t1_2;
        if (temp_t1_2 == NULL)
        {
          block_160:
          if (var_s0 == NULL)
          {
            goto block_161;
          }

          do
          {
            continue;
          }
          while (0);
        }
        continue;
        break;
      }


    }
    break;
  }

  block_161:
  return (s8) sp187;

}

