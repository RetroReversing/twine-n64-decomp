extern float D_800D461C;
extern float D_800D4620;
extern float D_800D4624;
s32 func_80045290();
s32 func_800480A0();
s32 func_80048124();
s32 func_80048164(void *, void *, f32);
s32 func_800481E8(void *, void *, f32, s32);
s32 func_80048224(s32, s32, s32, f32, f32);
s32 func_80064370();
s32 func_800643C8();
s32 buildRotationMatrixS16();
s32 rotateVec3ByMat3();
extern f32 D_800C9D4C;
extern f64 D_800D4628;
extern f64 D_800D4630;
extern u8 gWheelsGrounded;
extern char D_80109688[];
typedef struct 
{
  f32 __repair_v[3];
} __repair_vec3;
void func_8006CD34(void *arg0)
{
  float *__base_D_800D461C;
  f32 sp18[3];
  char sp28[0x30];
  s16 sp58[3];
  f32 temp_ft0;
  f32 temp_ft0_2;
  f32 var_fv0;
  f32 var_fv0_2;
  f32 var_fv1;
  f32 __repair_var_fv1_1;
  s32 temp_s4;
  s32 var_condition_bit;
  s32 temp_s3;
  void **temp_s0;
  void **temp_s0_2;
  void **temp_s0_3;
  void **temp_s0_4;
  void **temp_v1_2;
  void **temp_v1_3;
  void *temp_s2;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v1;
  void *var_v0;
  temp_s2 = *((void **) (((char *) arg0) + 0x6C));
  temp_s4 = *((s32 *) (((char *) arg0) + 0x20));
  temp_s3 = *((s8 *) (((char *) temp_s2) + 0x182));
  if ((*((u8 *) (((char *) temp_s2) + 0x184))) == 0)
  {
    func_80064370(arg0, temp_s3);
    if ((*((s16 *) (((char *) arg0) + 0x7C))) == 5)
    {
      temp_s0 = (temp_s3 * 4) + D_80109688;
      *((f32 *) (((char *) (*temp_s0)) + 0x4C)) = (f32) (*((f32 *) (((char *) temp_s2) + 0x3C)));
      func_800480A0(arg0, *temp_s0);
      temp_v1 = *temp_s0;
      temp_v0 = *((void **) (((char *) temp_s2) + 0xBC));
      *((__repair_vec3 *) (((s8 *) temp_v1) + 0x10)) = *((__repair_vec3 *) (((s8 *) temp_v0) + 0x24));
      var_v0 = *((void * volatile *) temp_s0);
      var_fv0 = (f32) (((f64) (*((f32 *) (((char *) var_v0) + 0x14)))) + D_800D4628);
    }
    else
    {
      var_fv0_2 = 0.55f;
      if (gWheelsGrounded == 0)
      {
        var_fv0_2 = 0.0f;
      }
      temp_ft0 = *((f32 *) (((char *) temp_s2) + 0x98));
      temp_s0_2 = (temp_s3 * 4) + D_80109688;
      *((f32 *) (((char *) temp_s2) + 0x98)) = (f32) (((var_fv0_2 - temp_ft0) * 0.1f) + temp_ft0);
      *((f32 *) (((char *) (*temp_s0_2)) + 0x4C)) = (f32) (*((f32 *) (((char *) temp_s2) + 0x3C)));
      func_800480A0(arg0, *temp_s0_2);
      if ((*((s16 *) (((char *) arg0) + 0x7C))) == 6)
      {
        temp_v0_2 = *temp_s0_2;
        *((f32 *) (((char *) temp_v0_2) + 0x130)) += 0.040000003f;
        if ((*((f32 *) ((*temp_s0_2) + 0x130))) > 0.4f)
        {
          *((f32 *) ((*temp_s0_2) + 0x130)) = 0.4f;
        }
      }
      else
      {
        temp_v0_3 = *temp_s0_2;
        *((f32 *) (temp_v0_3 + 0x130)) -= 0.040000003f;
        if ((*((f32 *) ((*temp_s0_2) + 0x130))) < 0.0f)
        {
          *((f32 *) ((*temp_s0_2) + 0x130)) = 0.0f;
        }
      }
      if (((u32) ((*((u16 *) (((char *) arg0) + 0x7A))) - 2)) < 2U)
      {
        *((s32 *) (((char *) (*((s32 *) (D_80109688 + (temp_s3 * 4))))) + 0x130)) = 0;
      }
      temp_v1_2 = (temp_s3 * 4) + D_80109688;
      temp_v0_4 = *temp_v1_2;
      *((f32 *) (((char *) temp_v0_4) + 0x14)) -= *((f32 *) (((char *) temp_v0_4) + 0x130));
      var_v0 = *temp_v1_2;
      temp_ft0_2 = *((f32 *) (((char *) var_v0) + 0x2C));
      var_fv0 = (((*((f32 *) (((char *) var_v0) + 0x14))) - temp_ft0_2) * 0.5f) + temp_ft0_2;
    }
    *((f32 *) (((char *) var_v0) + 0x14)) = var_fv0;
  }
  if ((*((u8 *) (((char *) temp_s2) + 0x184))) == 1)
  {
    func_800643C8(arg0);
    temp_s0_3 = (temp_s3 * 4) + D_80109688;
    func_80048224(arg0 + 0x24, arg0 + 0x3C, *temp_s0_3, 1.0f, 10.0f);
    func_800481E8(arg0, *temp_s0_3, 1.0f, 0);
    func_80048124(arg0, *temp_s0_3);
    func_80048164(arg0, *temp_s0_3, 1.0f);
    *((f32 *) (((char *) (*temp_s0_3)) + 0x4C)) = 1.0f;
    *((s32 *) (((char *) (*temp_s0_3)) + 0xF4)) = temp_s4;
  }
  if ((*((u8 *) (((char *) temp_s2) + 0x184))) == 2)
  {
    func_800643C8(arg0);
    temp_v1_3 = (temp_s3 * 4) + D_80109688;
    *((f32 *) (((char *) (*temp_v1_3)) + 0x10)) = (f32) (*((f32 *) (((char *) arg0) + 0x24)));
    *((f32 *) (((char *) (*temp_v1_3)) + 0x18)) = (f32) (*((f32 *) (((char *) arg0) + 0x2C)));
    *((f32 *) (((char *) (*temp_v1_3)) + 0x14)) = (f32) ((((f64) (*((f32 *) (((char *) arg0) + 0x28)))) + D_800D4630) + ((f64) D_800C9D4C));
    *((s32 *) (((char *) (*temp_v1_3)) + 0x38)) = 0;
    *((f32 *) (((char *) (*temp_v1_3)) + 0x34)) = -1.5707964f;
    *((s32 *) (((char *) (*temp_v1_3)) + 0x3C)) = 0;
    *((f32 *) (((char *) (*temp_v1_3)) + 0x4C)) = 1.0f;
    *((s32 *) (((char *) (*temp_v1_3)) + 0xF4)) = temp_s4;
  }
  if ((*((u8 *) (((char *) temp_s2) + 0x184))) == 3)
  {
    temp_s2 = *((void **) (((char *) temp_s2) + 0xBC));
    if (temp_s2 != NULL)
    {
      __base_D_800D461C = &D_800D461C;
      *((__repair_vec3 *) sp18) = *((__repair_vec3 *) __base_D_800D461C);
      do
      {
        func_800643C8(arg0, __base_D_800D461C);
      }
      while (0);
      sp58[0] = (s16) ((s32) (*((f32 *) (((char *) temp_s2) + 0x3C))));
      sp58[1] = (s16) ((s32) (*((f32 *) (((char *) temp_s2) + 0x40))));
      sp58[2] = (s16) ((s32) (*((f32 *) (((char *) temp_s2) + 0x44))));
      buildRotationMatrixS16(sp58, sp28);
      arg0 = sp18;
      rotateVec3ByMat3(sp28);
      sp18[0] += *((f32 *) (((char *) temp_s2) + 0x24));
 do { sp18[1] += *((f32 *) (((char *) temp_s2) + 0x28)); temp_s0_4 = (temp_s3 * 4) + D_80109688; sp18[2] += *((f32 *) (((char *) temp_s2) + 0x2C)); func_80045290(arg0, (*temp_s0_4) + 0x10); *((f32 *) (((char *) (*temp_s0_4)) + 0x34)) = (f32) ((*((f32 *) (((char *) temp_s2) + 0x3C))) * 0.0015339808f); *((f32 *) (((char *) (*temp_s0_4)) + 0x38)) = (f32) (((*((f32 *) (((char *) temp_s2) + 0x40))) * 0.0015339808f) + 3.1415927f); *((f32 *) (((char *) (*temp_s0_4)) + 0x3C)) = (f32) (((*((f32 *) (((char *) temp_s2) + 0x44))) * 0.0015339808f) + 3.1415927f); *((f32 *) (((char *) (*temp_s0_4)) + 0x4C)) = 1.0f; } while (0);
      *((s32 *) (((char *) (*temp_s0_4)) + 0xF4)) = (s32) (*((s32 *) (((char *) temp_s2) + 0x20)));
    }
  }
}
