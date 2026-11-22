s32 func_80096F44(void *, s32, s16);
extern s16 D_80112E9E;
s32 func_8009ABD4(void *arg0, void *arg1, s32 arg2)
{
  short temp_v0;
  s32 temp_v0_2;
  s32 temp_v0_4;
  s32 var_a2;
  s16 __repair_saved_narrow;
  s32 var_s1;
  u32 temp_v0_3;
  unsigned char temp_v1;
  u32 temp_v1_2;
  u32 temp_v1_3;
  u32 temp_v1_4;
  u32 temp_v1_5;
  u32 temp_v1_6;
  u32 temp_v1_7;
  u32 var_a0;
  unsigned char var_v1;
  temp_v1 = *((u32 *) (((char *) arg1) + 4));
  if ((*((u8 *) (((char *) arg1) + 0))) != 0)
  {
    var_s1 = func_80096E7C(arg0, temp_v1 & 0xFF);
  }
  else
  {
    temp_v1_2 = temp_v1 & 0x1F;
    temp_v0 = temp_v1_2 * 2;
    if (temp_v1_2 < 0x10U)
    {
      var_s1 = (s32) (*((s16 *) (((char *) ((temp_v1_2 * 2) + arg0)) + 0x180)));
    }
    else
    {
      var_s1 = (s32) (*((s16 *)((char *)&D_80112E9E + temp_v0)));
    }
  }
  var_v1 = arg2 & 0xFF;
  if (var_v1 == 4)
  {
    var_a0 = ((u32) (*((u32 *) (((char *) arg1) + 4)))) >> 8;
  }
  else
  {
    temp_v1_3 = *((u32 *) (((char *) arg1) + 4));
    temp_v1_4 = temp_v1_3 >> 0x10;
    if ((temp_v1_3 >> 8) & 0xFF)
    {
      var_a0 = func_80096E7C(arg0, temp_v1_4 & 0xFF);
    }
    else
    {
      temp_v0_3 = temp_v1_4 & 0x1F;
      temp_v0_2 = temp_v0_3 * 2;
      if (((temp_v0_3 + 1) - 1) <= (0x10U - 1))
      {
        var_a0 = (u32) (*((s16 *) (((char *) (temp_v0_2 + arg0)) + 0x180)));
      }
      else
      {
        var_a0 = (u32) (*((s16 *)((char *)&D_80112E9E + temp_v0_2)));
      }
    }
    var_v1 = arg2 & 0xFF;
  }
  switch ((u32)((short) var_v1))
  {
    case 0:

    case 4:
      temp_v0_4 = ((s16) var_s1) + ((s16) var_a0);
      break;

    case 1:
      temp_v0_4 = ((s16) var_s1) - ((s16) var_a0);
      break;

    case 2:
      temp_v0_4 = ((s16) var_s1) * ((s16) var_a0);
      break;

    case 3:
      if (((s16) var_a0) != 0)
    {
      temp_v0_4 = ((s16) var_s1) / ((s16) var_a0);
    }
    else
    {
      temp_v0_4 = 0;
    }
      break;

  }

  temp_v0_3 = *((u32 *) (((char *) arg1) + 0));
  temp_v1_6 = temp_v0_3 >> 0x10;
  if (temp_v0_4 < (-0x8000))
  {
    {
      var_a2 = -0x8000; __repair_saved_narrow = (s16) var_a2;
    }
  }
  else
  {
    {
      var_a2 = 0x7FFF; __repair_saved_narrow = (s16) var_a2;
    }
    if (temp_v0_4 <= 0x7FFF)
    {
      __repair_saved_narrow = temp_v0_4;
    }
  }
  if ((temp_v0_3 >> 8) & 0xFF)
  {
    func_80096F44(arg0, temp_v1_6 & 0xFF, (s16) __repair_saved_narrow);
    return 0;
  }
  temp_v1_6 &= 0x1F;
  temp_v0_4 = temp_v1_6 * 2;
  if (temp_v1_6 < 0x10U)
  {
    *((s16 *) (((char *) (temp_v0_4 + arg0)) + 0x180)) = (s16) __repair_saved_narrow;
  }
  else
  {
    *((s16 *) (((u8 *) (&D_80112E9E)) + temp_v0_4)) = (s16) __repair_saved_narrow;
  }
  return 0;
}

