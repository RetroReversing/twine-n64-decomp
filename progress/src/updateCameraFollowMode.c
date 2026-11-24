extern float D_800D461C;
extern float D_800D4620;
extern float D_800D4624;
s32 copyVec3f();
s32 syncChaseCameraToActor();
s32 setYawTowardTarget();
s32 smoothCameraPitchToTarget(void *, void *, f32);
s32 easeCameraHeightToTarget(void *, void *, f32, s32);
s32 blendCameraTowardOrbitPosition(s32, s32, s32, f32, f32);
s32 setObjectChannelMask();
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
inline static char *inline_fn(s32 arg0, int arg1, char *arg2)
{
  return (arg0 * arg1) + arg2;
}

inline static __repair_vec3 *inline_fn2(void *arg0)
{
  return (__repair_vec3 *) (((s8 *) arg0) + 0x10);
}

inline static void **slot_b(char *b, s32 i) { return (void **) (b + i * 4); }
/* Positions the player's camera according to the camera mode byte (follow, fixed, top-down, or attached to another actor). */
void updateCameraFollowMode(void *actor)
{
  float *__base_D_800D461C;
  f32 sp18[3];
  char sp28[0x30];
  s16 sp58[3];
  f32 temp_ft0;
  f32 temp_ft0_2;
  f32 var_fv0;
  f32 groundedBlend;
  f32 var_fv1;
  f32 __repair_var_fv1_1;
  s32 savedField20;
  s32 var_condition_bit;
  s32 playerIdx;
  void **temp_s0;
  void **temp_s0_2;
  void **temp_s0_3;
  void **temp_s0_4;
  void **temp_v1_2;
  void **temp_v1_3;
  void *playerData;
  void *temp_v0;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_4;
  void *temp_v1;
  void *var_v0;
  f32 c1; void *pv;
  void *var_v0_2;
  playerData = *((void **) (((char *) actor) + 0x6C));
  savedField20 = *((s32 *) (((char *) actor) + 0x20));
  playerIdx = *((s8 *) (((char *) playerData) + 0x182));
  if ((*((u8 *) (((char *) playerData) + 0x184))) == 0)
  {
    setObjectChannelMask(actor, playerIdx);
    if ((*((s16 *) (((char *) actor) + 0x7C))) == 5)
    {
      temp_s0 = (playerIdx * 4) + D_80109688;
      *((f32 *) (((char *) (*temp_s0)) + 0x4C)) = (f32) (*((f32 *) (((char *) playerData) + 0x3C)));
      syncChaseCameraToActor(actor, *temp_s0);
      temp_v1 = *temp_s0;
      temp_v0 = *((void **) (((char *) playerData) + 0xBC));
      *inline_fn2(temp_v1) = *((__repair_vec3 *) (((s8 *) temp_v0) + 0x24));
      var_v0 = *temp_s0;
      *((f32 *) (((char *) var_v0) + 0x14)) = (f32) (((f64) (*((f32 *) (((char *) var_v0) + 0x14)))) + D_800D4628);
    }
    else
    {
      groundedBlend = 0.55f;
      if (gWheelsGrounded == 0)
      {
        groundedBlend = 0.0f;
      }
      temp_ft0 = *((f32 *) (((char *) playerData) + 0x98));
      temp_s0_2 = inline_fn(playerIdx, 4, D_80109688);
      *((f32 *) (((char *) playerData) + 0x98)) = (f32) (((groundedBlend - temp_ft0) * 0.1f) + temp_ft0);
      *((f32 *) (((char *) (*temp_s0_2)) + 0x4C)) = (f32) (*((f32 *) (((char *) playerData) + 0x3C)));
      syncChaseCameraToActor(actor, *temp_s0_2);
      if ((*((s16 *) (((char *) actor) + 0x7C))) == 6)
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
      if (((u32) ((*((u16 *) (((char *) actor) + 0x7A))) - 2)) < 2U)
      {
        *((s32 *) (((char *) (*((s32 *) (D_80109688 + (playerIdx * 4))))) + 0x130)) = 0;
      }
      temp_v1_2 = inline_fn(playerIdx, 4, D_80109688);
      temp_v0_4 = *temp_v1_2;
      *((f32 *) (((char *) temp_v0_4) + 0x14)) -= *((f32 *) (((char *) temp_v0_4) + 0x130));
      var_v0_2 = *temp_v1_2;
      var_fv1 = *((f32 *) (((char *) var_v0_2) + 0x14));
      temp_ft0_2 = *((f32 *) (((char *) var_v0_2) + 0x2C));
      *((f32 *) (((char *) var_v0_2) + 0x14)) = ((var_fv1 - temp_ft0_2) * 0.5f) + temp_ft0_2;
    }
  }
  if ((*((u8 *) (((char *) playerData) + 0x184))) == 1)
  {
    func_800643C8(actor);
    c1 = 1.0f;
    temp_s0_3 = slot_b(D_80109688, playerIdx);
    blendCameraTowardOrbitPosition(actor + 0x24, actor + 0x3C, *temp_s0_3, c1, 10.0f);
    easeCameraHeightToTarget(actor, *temp_s0_3, 1.0f, 0);
    setYawTowardTarget(actor, *temp_s0_3);
    smoothCameraPitchToTarget(actor, *temp_s0_3, 1.0f);
    *((f32 *) (((char *) (*temp_s0_3)) + 0x4C)) = 1.0f;
    *((s32 *) (((char *) (*temp_s0_3)) + 0xF4)) = savedField20;
  }
  if ((*((u8 *) (((char *) playerData) + 0x184))) == 2)
  {
    func_800643C8(actor);
    temp_v1_3 = inline_fn(playerIdx, 4, D_80109688);
    *((f32 *) (((char *) (*temp_v1_3)) + 0x10)) = (f32) (*((f32 *) (((char *) actor) + 0x24)));
    *((f32 *) (((char *) (*temp_v1_3)) + 0x18)) = (f32) (*((f32 *) (((char *) actor) + 0x2C)));
    *((f32 *) (((char *) (*temp_v1_3)) + 0x14)) = (f32) ((((f64) (*((f32 *) (((char *) actor) + 0x28)))) + D_800D4630) + ((f64) D_800C9D4C));
    *((s32 *) (((char *) (*temp_v1_3)) + 0x38)) = 0;
    *((f32 *) (((char *) (*temp_v1_3)) + 0x34)) = -1.5707964f;
    *((s32 *) (((char *) (*temp_v1_3)) + 0x3C)) = 0;
    *((f32 *) (((char *) (*temp_v1_3)) + 0x4C)) = 1.0f;
    *((s32 *) (((char *) (*temp_v1_3)) + 0xF4)) = savedField20;
  }
  if ((*((u8 *) (((char *) playerData) + 0x184))) == 3)
  {
    playerData = *((void **) (((char *) playerData) + 0xBC));
    if (playerData != NULL)
    {
      __base_D_800D461C = &D_800D461C;
      *((__repair_vec3 *) sp18) = *((__repair_vec3 *) __base_D_800D461C);
      do
      {
        func_800643C8(actor, __base_D_800D461C);
      }
      while (0);
      sp58[0] = (s16) ((s32) (*((f32 *) (((char *) playerData) + 0x3C))));
      sp58[1] = (s16) ((s32) (*((f32 *) (((char *) playerData) + 0x40))));
      sp58[2] = (s16) ((s32) (*((f32 *) (((char *) playerData) + 0x44))));
      buildRotationMatrixS16(sp58, sp28);
      pv = sp18;
      rotateVec3ByMat3(sp28, pv);
      sp18[0] += *((f32 *) (((char *) playerData) + 0x24));
      do
      {
        sp18[1] += *((f32 *) (((char *) playerData) + 0x28)); temp_s0_4 = (playerIdx * 4) + D_80109688; sp18[2] += *((f32 *) (((char *) playerData) + 0x2C));
        copyVec3f(pv, (*temp_s0_4) + 0x10);
        *((f32 *) (((char *) (*temp_s0_4)) + 0x34)) = (f32) ((*((f32 *) (((char *) playerData) + 0x3C))) * 0.0015339808f);
        *((f32 *) (((char *) (*temp_s0_4)) + 0x38)) = (f32) (((*((f32 *) (((char *) playerData) + 0x40))) * 0.0015339808f) + 3.1415927f);
        *((f32 *) (((char *) (*temp_s0_4)) + 0x3C)) = (f32) (((*((f32 *) (((char *) playerData) + 0x44))) * 0.0015339808f) + 3.1415927f);
        *((f32 *) (((char *) (*temp_s0_4)) + 0x4C)) = 1.0f;
      }
      while (0);
      *((s32 *) (((char *) (*temp_s0_4)) + 0xF4)) = (s32) (*((s32 *) (((char *) playerData) + 0x20)));
    }
  }
}
