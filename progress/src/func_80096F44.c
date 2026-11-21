s32 func_80095B08(s32, u8, u8, s32);
inline static int inline_fn(s32 arg0, int arg1)
{
  return arg0 & arg1;
}

void func_80096F44(void *arg0, s32 arg1, s32 arg2)
{
  s16 var_a2;
  s32 temp_v0;
  s32 temp_v1;
  s32 var_v1;
  u8 temp_a1;
  {
    s32 original = arg2;
    s32 narrowed;
    if (var_v1)
    {
      arg2 = (s32) (((u32) arg2) << 16);
      narrowed = arg2 >> 16;
    }
    else
    {
      arg2 = (s32) (((u32) arg2) << 16);
      narrowed = arg2 >> 16;
    }
    if (narrowed >= 0)
    {
      arg2 = original;
      if (narrowed >= 0x4000)
      {
        arg2 = 0x3FFF;
      }
    }
    else
    {
      arg2 = 0;
    }
    var_a2 = arg2;
  }
  temp_v0 = inline_fn(arg1, 0xFF);
  var_v1 = arg1;
  switch (temp_v0)
  {
    case 0x80:
      var_v1 = 0x80;
      break;

    case 0x81:
      var_v1 = 0x82;
      break;

    case 0x82:
      var_v1 = 0xA0;
      break;

    case 0x83:
      var_v1 = 0xA1;
      break;

    case 0x84:
      var_v1 = 0x83;
      break;

    case 0x85:
      var_v1 = 0x84;
      break;

  }

  if ((inline_fn((int) var_v1, 0xFF) >= 0xA2) || ((temp_v1 = var_v1 & 0xFF) < 0xA0))
  {
    temp_a1 = *((u8 *) (((char *) arg0) + 0x4A));
    if (temp_a1 != 0xFF)
    {
      func_80095B08(arg1 & 0xFF, temp_a1, *((u8 *) (((char *) arg0) + 0x4B)), inline_fn(var_a2, 0xFFFF));
    }
  }
}

