f32 func_80046140(f32, f32);
f32 func_80082A70(f32, f32);
extern u8 D_800CA338;
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

s16 func_8000628C(void *arg0, void *arg1, s32 arg2, s32 arg3)
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
  s32 var_a1;
  s32 var_s0;
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
  void *temp_s1;
  void *temp_v0;
  register void *temp_v1_5;
  void *temp_v1_6;
  __repair_phase_storage.pointer = *((void **) (((char *) arg0) + 0x68)); temp_s1 = (void *) (0x14 + ((s32) __repair_phase_storage.pointer));
  if (arg1 != NULL)
  {
    var_ft1 = 0.2f;
    ((__repair_record_temp_a2 *) __repair_phase_storage.pointer)->field_14 |= 0x180000;
    if (D_800CA338 != 0)
    {
      var_ft1 = 0.0f;
    }
    temp_fs1 = (*((f32 *) (((char *) arg1) + 0))) - (*((f32 *) (inline_fn(*((void **) (((char *) (*((void **) (inline_fn(arg0) + 0x68)))) + 0))) + 0))); temp_fs0 = (*((f32 *) (inline_fn(arg1) + 8))) - (*((f32 *) (inline_fn(*((void **) (((char *) (*((void **) (inline_fn(arg0) + 0x68)))) + 0))) + 8))); temp_fs2 = ((*((f32 *) (((char *) arg1) + 4))) - (*((f32 *) (inline_fn(*((void **) (inline_fn(*((void **) (inline_fn(arg0) + 0x68))) + 0))) + 0xAC)))) + var_ft1; scale = 651.8986f; var_s0 = (s32) (((f32) ((s32) (func_80082A70(-temp_fs1, temp_fs0) * scale))) + (*((f32 *) (((char *) arg0) + 0x40)))); var_s0 &= 0xFFF;
    if (var_s0 >= 0x800)
    {
      var_s0 -= 0x1000;
    }
    var_a1 = (s32) (func_80082A70(temp_fs2, func_80046140(temp_fs1, temp_fs0)) * scale); var_v1 = arg2 * 2;
  }
  else
  {
    var_s0 = 0; var_a1 = 0; var_v1 = arg2 * 2;
  }
  var_v1 = var_v1 + ((s32) temp_s1); var_a0 = (var_s0 - ((__repair_record_temp_a2 *) var_v1)->field_94) * arg3;
  pitchDelta = var_a1 - ((__repair_record_temp_a2 *) var_v1)->field_98;
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
    var_v1 = (arg2 * 2) + ((s32) temp_s1);
    temp_v0_2 = (*((u16 *) (((char *) var_v1) + 0x94))) + var_a0;
    *((u16 *) (((char *) var_v1) + 0x94)) = (s16) (((s32) (((u32) temp_v0_2) << 16)) >> 16);
  }
  else
  {
    var_v1 = (arg2 * 2) + ((s32) temp_s1);
    temp_v0_2 = (*((u16 *) (((char *) var_v1) + 0x94))) + var_a0;
    *((u16 *) (((char *) var_v1) + 0x94)) = (s16) (((s32) (((u32) temp_v0_2) << 16)) >> 16);
  }
  if (var_a0 >= 0)
  {
    var_v0_2 = var_s0 < ((s16) temp_v0_2);
  }
  else
  {
    var_v0_2 = ((s16) temp_v0_2) < var_s0;
  }
  if (var_v0_2)
  {
    *((u16 *) (((char *) var_v1) + 0x94)) = (u16) var_s0;
  }
  if (arg2 == 0)
  {
    temp_v1_3 = *((s16 *) (inline_fn(temp_s1) + 0x94));
    if (temp_v1_3 < (-0x384))
    {
      *((s16 *) (inline_fn(temp_s1) + 0x94)) = -0x384;
    }
    else
      if (temp_v1_3 >= 0x385)
    {
      *((s16 *) (inline_fn(temp_s1) + 0x94)) = 0x384;
    }
  }
  else
  {
    temp_v0 = (void *) ((arg2 * 2) + ((s32) temp_s1)); temp_a0 = *((s16 *) (inline_fn(temp_v0) + 0x94));
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
  var_a0 = pitchDelta * arg3; pitchScaled = var_a0 >> 7;
  if (pitchScaled < (-0x40))
  {
    pitchScaled = -0x40;
  }
  else
    if (pitchScaled >= 0x41)
  {
    pitchScaled = 0x40;
  }
  var_v1 = ((s32) temp_s1) + (arg2 * 2); temp_v0_3 = (*((u16 *) (((char *) var_v1) + 0x98))) + pitchScaled;
  *((u16 *) (inline_fn((void *) var_v1) + 0x98)) = temp_v0_3;
  if (pitchScaled >= 0)
  {
    var_v0_4 = var_a1 < ((s16) temp_v0_3);
  }
  else
  {
    var_v0_4 = ((s16) temp_v0_3) < var_a1;
  }
  if (var_v0_4 != 0)
  {
    *((u16 *) (((char *) var_v1) + 0x98)) = (u16) var_a1;
  }
  temp_v1_6 = (void *) (((s32) temp_s1) + (arg2 << 1));
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
  return ((__repair_record_temp_a2 *) ((arg2 << 1) + ((s32) temp_s1)))->field_94;
}


