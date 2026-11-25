f32 func_80046140(f32, f32);
f32 func_80082A70(f32, f32);
extern u8 gSkipActorSpawns;
typedef struct 
{
  unsigned char pad_0[20];
  int field_14;
  unsigned char pad_18[124];
  short field_94;
  unsigned char pad_96[2];
  short field_98;
} __repair_record_temp_a2;
inline static short __repair_store_halfword(int x)
{
  x = ((unsigned int) x) << 16;
  x = ((int) x) >> 16;
  return x;
}

inline static char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

/* Smoothly turns a joint's yaw (field_94) and pitch (field_98) toward a target position, with per-step rate limits and angle clamps. Returns the new yaw. */
s32 updateActorHeadLook(void * actor, void * target, s32 jointIdx, s32 turnRate)
{
  f32 temp_fs0;
  f32 temp_fs1;
  register f32 temp_fs2;
  f32 var_ft1;
  f32 scale;
  s16 temp_a0;
  s16 temp_a0_2;
  s16 temp_v1_3;
  register s16 var_v0_3;
  s16 var_v0_5;
  s32 var_a0;
  s32 targetPitch;
  s32 targetYaw;
  s32 pitchDelta;
  s32 pitchScaled;
  long var_v0;
  s32 var_v0_2;
  s32 var_v0_4;
  s32 var_v1;
  u16 temp_v0_2;
  register u16 temp_v0_3;
  register union 
  {
    void *pointer;
    s32 value;
  } __repair_phase_storage;
  void *lookState;
  void *temp_v0;
  register void *temp_v1_5;
  void *temp_v1_6;
  __repair_phase_storage.pointer = *((void **) (((char *) actor) + 0x68)); lookState = (void *) (0x14 + ((s32) __repair_phase_storage.pointer));
  if (target != NULL)
  {
    var_ft1 = 0.2f;
    ((__repair_record_temp_a2 *) __repair_phase_storage.pointer)->field_14 |= 0x180000;
    if (gSkipActorSpawns != 0)
    {
      var_ft1 = 0.0f;
    }
    temp_fs1 = (*((f32 *) (((char *) target) + 0))) - (*((f32 *) (inline_fn(*((void **) (((char *) (*((void **) (inline_fn(actor) + 0x68)))) + 0))) + 0))); temp_fs0 = (*((f32 *) (inline_fn(target) + 8))) - (*((f32 *) (inline_fn(*((void **) (((char *) (*((void **) (inline_fn(actor) + 0x68)))) + 0))) + 8))); temp_fs2 = ((*((f32 *) (((char *) target) + 4))) - (*((f32 *) (inline_fn(*((void **) (inline_fn(*((void **) (inline_fn(actor) + 0x68))) + 0))) + 0xAC)))) + var_ft1; scale = 651.8986f; targetYaw = (s32) (((f32) ((s32) (func_80082A70(-temp_fs1, temp_fs0) * scale))) + (*((f32 *) (((char *) actor) + 0x40)))); targetYaw &= 0xFFF;
    if (targetYaw >= 0x800)
    {
      targetYaw -= 0x1000;
    }
    targetPitch = (s32) (func_80082A70(temp_fs2, func_80046140(temp_fs1, temp_fs0)) * scale); var_v1 = jointIdx * 2;
  }
  else
  {
    targetYaw = 0; targetPitch = 0; var_v1 = jointIdx * 2;
  }
  var_v1 = var_v1 + ((s32) lookState); var_a0 = (targetYaw - ((__repair_record_temp_a2 *) var_v1)->field_94) * turnRate;
  pitchDelta = targetPitch - ((__repair_record_temp_a2 *) var_v1)->field_98;
  var_a0 >>= 7;
  if (var_a0 < (-0x40))
  {
    var_a0 = -0x40;
  }
  else
    if (var_a0 >= 0x41)
  {
    var_a0 = 0x40;
  }
  if (scale)
  {
    var_v1 = (jointIdx * 2) + ((s32) lookState);
    temp_v0_2 = (*((u16 *) (((char *) var_v1) + 0x94))) + var_a0;
    *((u16 *) (((char *) var_v1) + 0x94)) = (s16) (((s32) (((u32) temp_v0_2) << 16)) >> 16);
  }
  else
  {
    var_v1 = (jointIdx * 2) + ((s32) lookState);
    temp_v0_2 = (*((u16 *) (((char *) var_v1) + 0x94))) + var_a0;
    *((u16 *) (((char *) var_v1) + 0x94)) = (s16) (((s32) (((u32) temp_v0_2) << 16)) >> 16);
  }
  if (var_a0 >= 0)
  {
    var_v0_2 = targetYaw < ((s16) temp_v0_2);
  }
  else
  {
    var_v0_2 = ((s16) temp_v0_2) < targetYaw;
  }
  if (var_v0_2)
  {
    *((u16 *) (((char *) var_v1) + 0x94)) = (u16) targetYaw;
  }
  if (jointIdx == 0)
  {
    temp_v1_3 = *((s16 *) (inline_fn(lookState) + 0x94));
    if (temp_v1_3 < (-0x384))
    {
      *((s16 *) (inline_fn(lookState) + 0x94)) = -0x384;
    }
    else
      if (temp_v1_3 >= 0x385)
    {
      *((s16 *) (inline_fn(lookState) + 0x94)) = 0x384;
    }
  }
  else
  {
    temp_v0 = (void *) ((jointIdx * 2) + ((s32) lookState)); temp_a0 = *((s16 *) (inline_fn(temp_v0) + 0x94));
    if (temp_a0 < (-0x1C2))
    {
      *((s16 *) (((char *) temp_v0) + 0x94)) = -0x1C2;
    }
    else
      if (temp_a0 >= 0x1C3)
    {
      *((s16 *) (inline_fn(temp_v0) + 0x94)) = 0x1C2;
    }
  }
  var_a0 = pitchDelta * turnRate; pitchScaled = var_a0 >> 7;
  if (pitchScaled < (-0x40))
  {
    pitchScaled = -0x40;
  }
  else
    if (pitchScaled >= 0x41)
  {
    pitchScaled = 0x40;
  }
  var_v1 = ((s32) lookState) + (jointIdx * 2); temp_v0_3 = (*((u16 *) (((char *) var_v1) + 0x98))) + pitchScaled;
  *((u16 *) (inline_fn((void *) var_v1) + 0x98)) = temp_v0_3;
  if (pitchScaled >= 0)
  {
    var_v0_4 = targetPitch < ((s16) temp_v0_3);
  }
  else
  {
    var_v0_4 = ((s16) temp_v0_3) < targetPitch;
  }
  if (var_v0_4 != 0)
  {
    *((u16 *) (((char *) var_v1) + 0x98)) = (u16) targetPitch;
  }
  temp_v1_6 = (void *) (((s32) lookState) + (jointIdx << 1));
  temp_a0_2 = *((s16 *) (inline_fn(temp_v1_6) + 0x98));
  if (temp_a0_2 < (-0x258))
  {
    *((s16 *) (inline_fn(temp_v1_6) + 0x98)) = -0x258;
  }
  else
    if (temp_a0_2 >= 0x259)
  {
    *((s16 *) (inline_fn(temp_v1_6) + 0x98)) = 0x258;
  }
  return ((__repair_record_temp_a2 *) ((jointIdx << 1) + ((s32) lookState)))->field_94;
}
