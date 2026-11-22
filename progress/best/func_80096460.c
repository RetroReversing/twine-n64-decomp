extern char D_800EE420[];
extern char D_800F2720[];
inline static unsigned char inline_fn(s32 arg0)
{
  return arg0 & 0xFF;
}

inline static char *inline_fn2(s32 arg0, int arg1, char *arg2)
{
  return ((arg0 & arg1) * 0x86) + arg2;
}

inline static char *inline_fn23(s32 arg0, char *arg1)
{
  return (arg0 * 0x860) + arg1;
}

s32 func_80096460(s32 arg0, s32 arg1, s32 arg2)
{
  s32 temp_a3 = arg0;
  union 
  {
    char *pointer;
    u32 value;
  } __repair_phase_storage;
  char *__base_D_800F2720;
  char *__repair_phase___base_D_800F2720;
  s32 temp_a2;
  s32 __repair_phase_temp_a2;
  
  u32 temp_t0;
  u8 *var_v0;
  u8 *var_v0_2;
  s32 var_v1;
  void *temp_v1;
  void *var_v1_2;
  __repair_phase_temp_a2 = arg2 & 0xFF;
  __repair_phase_storage.value = temp_a3;
  if (__repair_phase_temp_a2 != 0xFF)
  {
    temp_t0 = __repair_phase_storage.value & 0xFF;
    if (temp_t0 < 0x40U)
    {
      __repair_phase_storage.pointer = D_800EE420;
      __repair_phase_storage.pointer = D_800EE420;
      temp_v1 = (((arg1 & 0xFF) * 0x86) + ((__repair_phase_temp_a2 * 0x860) + __repair_phase_storage.pointer)) + (temp_a3 & 0x1F);
      temp_a2 = (*((u8 *) (((char *) temp_v1) + 0))) << 7;
      var_v1 = *((u8 *) (((char *) temp_v1) + 0x20));
      goto block_19;
    }
    if (((u32) ((temp_a3 + 0x80) & 0xFF)) < 2U)
    {
      char *bank = inline_fn23(__repair_phase_temp_a2, D_800EE420);
      if (arg1 || __base_D_800F2720)
      {
        var_v1_2 = (void *) ((arg1 & 0xFF) * 0x86);
        var_v1_2 = (void *) (((char *) var_v1_2) + ((s32) bank));
        goto block_18;
      }
      else
      {
        var_v1_2 = (void *) ((arg1 & 0xFF) * 0x86);
        var_v1_2 = (void *) (((char *) var_v1_2) + ((s32) bank));
        goto block_18;
      }
    }
    if (((u32) ((temp_a3 + 0x7C) & 0xFF)) < 2U)
    {
      __repair_phase_storage.pointer = D_800EE420;
      var_v1_2 = (((arg1 & 0xFF) * 2) * 67) + ((__repair_phase_temp_a2 * 0x860) + __repair_phase_storage.pointer);
      goto block_18;
    }
    if (temp_t0 < 0x46U)
    {
      __repair_phase_storage.pointer = D_800EE420;
      var_v0_2 = (void *)((((arg1 & 0xFF) * 0x86) + ((__repair_phase_temp_a2 * 0x860) + __repair_phase_storage.pointer))); var_v0_2 = (void *)((char *)var_v0_2 + (s32)(temp_t0));
      return (-(((u8) (*var_v0_2)) >= 0x40U)) & 0x3FFF;
    }
    if (((u32) ((temp_a3 - 0x60) & 0xFF)) < 6U)
    {
      return 0;
    }
    __repair_phase_storage.pointer = D_800EE420;
    temp_a2 = (((arg1 & 0xFF) * 0x86) + ((__repair_phase_temp_a2 * 0x860) + __repair_phase_storage.pointer)); var_v0 = temp_a2 + temp_t0;
    return (*var_v0) << 7;
  }
  arg2 = __repair_phase_storage.value & 0xFF;
  if (arg2 < 0x40U)
  {
    __base_D_800F2720 = D_800F2720;
    __base_D_800F2720 = D_800F2720;
    var_v1 = *((u8 *) (((char *) (inline_fn2(arg1, 0xFF, __base_D_800F2720) + (temp_a3 & 0x1F))) + 0x20));
    {
      __base_D_800F2720 = D_800F2720;
    }
    __repair_phase_temp_a2 = *((u8 *) (((char *) (inline_fn2(arg1, 0xFF, __base_D_800F2720) + (temp_a3 & 0x1F))) + 0)); temp_a2 = __repair_phase_temp_a2 << 7;
    goto block_19;
  }
  temp_t0 = arg1 & 0xFF;
  if ((((u32) ((temp_a3 + 0x80) & 0xFF)) < 2U) || ((temp_t0 = inline_fn(arg1), (((u32) ((temp_a3 + 0x7C) & 0xFF)) < 2U) != 0)))
  {
    __base_D_800F2720 = D_800F2720;
    var_v1 = temp_t0 * 0x86; var_v1_2 = var_v1 + __base_D_800F2720;
    block_18:
    temp_v1 = var_v1_2 + (temp_a3 & 0xFE);

    var_v1 = *((u8 *) (((char *) temp_v1) + 1));
    temp_a2 = (*((u8 *) (((char *) temp_v1) + 0))) << 7;
    block_19:
    return var_v1 | temp_a2;

  }
  if (arg2 < 0x46U)
  {
    __base_D_800F2720 = D_800F2720;
    var_v0_2 = inline_fn2(arg1, 0xFF, __base_D_800F2720) + arg2;
    do
    {
      if (1)
      {
        return (-(((u8) (*var_v0_2)) >= 0x40U)) & 0x3FFF;
      }
    }
    while (0);
  }
  if (((u32) ((temp_a3 - 0x60) & 0xFF)) < 6U)
  {
    return 0;
  }
  __repair_phase___base_D_800F2720 = D_800F2720;
  var_v0 = (((arg1 & 0xFF) * 0x86) + __repair_phase___base_D_800F2720) + arg2;
  return ((*var_v0) << 5) << 2;
}

