extern s32 D_800CFD60;
inline static s16 inline_fn(int arg0)
{
  return (s16) arg0;
}

s32 func_8009A4E4(void *arg0, u32 *arg1)
{
  s32 *__base_D_800CFD60;
  u16 *var_v1_4;
  s32 temp_v1_2;
  s32 var_a2;
  u16 *var_v1_2;
  s32 temp_v1;
  s32 __repair_phase_temp_v1;
  u16 temp_a1_2;
  u16 temp_a1_3;
  u32 temp_a0;
  u32 temp_a1;
  u32 temp_a2;
  u32 temp_lo;
  u32 temp_lo_2;
  u32 temp_lo_3;
  u32 temp_lo_4;
  u32 var_a1;
  u32 var_a1_2;
  u32 var_v1;
  u32 __repair_phase_var_v1_3;
  __repair_phase_var_v1_3 = *((u32 *) (((char *) arg0) + 0x5C));
  temp_a1 = (((u32) (*arg1)) >> 8) & 0xFFFF;
  temp_lo_4 = __repair_phase_var_v1_3 & 0xFFFFFF;
  if (temp_lo_4 == temp_a1)
  {
    *((s16 *) (((char *) arg0) + 0x50)) = inline_fn(__repair_phase_var_v1_3 >> 0x18);
    *((s8 *) (((char *) arg0) + 0xC0)) = 0;
  }
  else
    if (temp_lo_4 < temp_a1)
  {
    s32 temp_v1_arm;
    temp_lo = ((u32) (temp_a1 << 0xC)) / temp_lo_4;
    var_a1 = 0;
    do
    {
      u32 next = var_a1 + 1;
      if (((temp_lo >> 12) >> next) == 0)
      {
        break;
      }
      var_a1 = next;
    }
    while ((temp_a1 = var_a1) < 11);
    var_a2 = 0xB;
    __base_D_800CFD60 = &D_800CFD60;
    temp_lo_2 = temp_lo / ((u32) (1 << var_a1));
    var_v1_2 = (u16 *) (((s8 *) __base_D_800CFD60) + 0x16); var_v1_4 = (u16 *) (((s8 *) __base_D_800CFD60) + 0x16);
    loop_9:
    if (((u16) (*(var_v1_2--))) >= temp_lo_2)
    {
      var_a2 -= 1;
      goto loop_9;
    }

    *((s16 *) (((char *) arg0) + 0x50)) = inline_fn(((*((u8 *) (((char *) arg0) + 0x5C))) + (var_a1 * 0xC)) + var_a2);
    temp_v1_arm = var_a2; temp_a1_2 = ((u16 *) __base_D_800CFD60)[temp_v1_arm];
    *((s8 *) (((char *) arg0) + 0xC0)) = (s8) (((u32) ((temp_lo_2 - temp_a1_2) * 0x64)) / ((u32) ((*((u16 *) ((((char *) __base_D_800CFD60) + temp_v1_arm) + 2))) - temp_a1_2)));
  }
  else
  {
    temp_lo_3 = ((u32) (temp_lo_4 << 0xC)) / temp_a1; var_a1_2 = 0; var_v1 = 1;
    do
    {
      u32 next = var_a1_2 + 1;
      if (((temp_lo_3 >> 12) >> next) == 0)
      {
        break;
      }
      var_a1_2 = next;
    }
    while ((temp_lo_4 = var_a1_2) < 11);
    temp_v1 = 0xB; __base_D_800CFD60 = &D_800CFD60; var_v1_4 = (u16 *) (((s8 *) __base_D_800CFD60) + 0x16); temp_lo_4 = temp_lo_3 / ((u32) (1 << var_a1_2));
    loop_16:
    if (((u16) (*(var_v1_4--))) >= temp_lo_4)
    {
      temp_v1 -= 1;
      goto loop_16;
    }

    *((s16 *) (((char *) arg0) + 0x50)) = (s16) (((*((u8 *) (((char *) arg0) + 0x5C))) - (var_a1_2 * 0xC)) - temp_v1);
    temp_v1_2 = temp_v1 * 2; temp_a1_3 = *((u16 *) (temp_v1_2 + (int)__base_D_800CFD60));
    *((s8 *) (((char *) arg0) + 0xC0)) = (s8) (-((s8) (((u32) ((temp_lo_4 - temp_a1_3) * 0x64)) / ((u32) ((*((u16 *) ((((char *) __base_D_800CFD60) - (-temp_v1_2)) + 2))) - temp_a1_3)))));
  }
  *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) | 0x100);
  return 0;
}

