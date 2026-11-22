s32 lookupMenuItemIndex(u32);
s32 lookupItemSlotIndex(s32);
s32 func_8002B000(void *, s32);
s16 timerGetTotalSeconds(void *);
s32 func_8002B2B0(void *, void *);
unsigned short func_8002B2FC(void *, void *);
s32 func_8002B3C0(void *, s32 *);
s32 func_8002BC68(s32, s32);
s32 func_80030C58();
s32 func_80030D40();
u16 func_800316B8();
extern s16 D_80102CBC;
extern s16 D_80102CBE;
extern s16 D_80102CC0;
extern u8 D_80102EE0;
extern s32 D_80102EE4;
extern s32 D_80102EFC;
extern s8 sMenuRowEnabled;
extern s8 gMenuFlagItem20;
extern s8 gMenuFlagItem22;
extern s8 gMenuFlagItem27;
extern s8 D_80112F7F;
extern s8 D_80112F80;
extern s8 D_80112F81;
extern s8 sOptionReady7;
extern s8 sOptionReady8;
extern s8 D_80112F84;
extern u8 D_80117410;
extern u8 D_80117428;
extern u8 D_80117578;
extern u8 D_801176C8;
inline static unsigned char inline_fn(u16 arg0)
{
  return arg0 & 0xFFFF;
}

inline static u8 *inline_fn2(u8 *arg0)
{
  return arg0;
}

inline static u8 *inline_fn23(s32 arg0, u8 *arg1)
{
  return arg0 + arg1;
}

inline static int inline_fn234(s32 arg0)
{
  return inline_fn(arg0) * 0x18;
}

inline static u8 *inline_fn2345(int arg0, unsigned char arg1, u8 *arg2)
{
  return arg0 + inline_fn23(arg1 * 8, arg2 + 0x18);
}

void func_8001C6CC(void)
{
  s16 temp_s0_4;
  s16 var_v0;
  s32 temp_s0;
  s32 __repair_phase_temp_s0;
  s32 temp_s2;
  s32 temp_s5;
  s32 var_a0;
  s32 __repair_phase_var_s1;
  s32 var_s2;
  u32 temp_s0_3;
  s32 temp_v0;
  void *temp_s0_2;
  D_80102CBC = 0;
  D_80102CBE = 0;
  D_80102CC0 = 0;
  if (func_80030D40() == 5)
  {
    u8 *p_ee0 = &D_80102EE0;
    var_s2 = lookupItemSlotIndex(*p_ee0) + 1;
    if (((u32) inline_fn(var_s2)) >= 0xEU)
    {
      var_s2 = 0xD;
    }
    *p_ee0 = lookupMenuItemIndex(var_s2 & 0xFFFF);
    temp_s5 = lookupItemSlotIndex(func_80030C58());
    temp_v0 = func_800316B8();
    var_s2 = temp_s5;
    __repair_phase_var_s1 = temp_s5 & 0xFFFF;
    temp_s0 = __repair_phase_var_s1 * 0x18;
    if (((timerGetTotalSeconds(inline_fn23(temp_s0, (temp_v0 * 8) + (&D_80117428))) << 0x10) == 0) || (func_8002B2B0(temp_s0 + inline_fn23(inline_fn(func_800316B8()) * 8, &D_80117428), (&D_80102EE0) + 0x1C) & 0xFF))
    {
      func_8002B3C0(inline_fn23(temp_s0, inline_fn23(inline_fn(func_800316B8()) * 8, inline_fn2(&D_80117428))), &D_80102EFC);
    }
    __repair_phase_temp_s0 = 0;
    func_8002B000(inline_fn23(inline_fn(func_800316B8()) * 8, &D_80117410), 0x1E);
    do
    {
      temp_s0_2 = inline_fn23((func_800316B8() & 0xFFFF) * 8, &D_80117410);
      func_8002B2FC(temp_s0_2, inline_fn2345((__repair_phase_temp_s0 & 0xFFFF) * 0x18, inline_fn(func_800316B8()), &D_80117410));
      __repair_phase_temp_s0 += 1;
    }
    while (((u32) ((temp_s0 = (temp_v0 = __repair_phase_temp_s0)) & 0xFFFF)) < 0xEU);
    temp_s0_3 = inline_fn(var_s2);
    if (((u8) (*((&D_801176C8) + temp_s0_3))) < ((u32) inline_fn(func_800316B8())))
    {
      *((&D_801176C8) + temp_s0_3) = func_800316B8();
    }
    {
      s32 *selected = &D_80102EE4;
      temp_s0 = var_s2 + 1;
      do
      {
      }
      while (0);
      if (temp_s0_3 >= ((u32) inline_fn(lookupItemSlotIndex(*selected))))
      {
        if (((u32) inline_fn(temp_s0)) >= 0xEU)
        {
          temp_s0 = 0xD;
        }
        var_a0 = temp_s0 & 0xFFFF;
      }
      else
      {
        var_a0 = inline_fn(lookupItemSlotIndex(*selected));
      }
      *selected = inline_fn(lookupMenuItemIndex(var_a0));
    }
    if (func_80030C58() == 0x21)
    {
      if (!inline_fn(func_800316B8()))
      {
        func_8002BC68(0xA, 1);
        D_80102CBC = 0x2C4;
      }
      if (inline_fn(func_800316B8()) == 1)
      {
        if (temp_s0)
        {
          func_8002BC68(4, 1);
          D_80102CBE = 0x2B3;
        }
        else
        {
          func_8002BC68(4, 1);
          D_80102CBE = 0x2B3;
        }
      }
      if ((func_800316B8() & 0xFFFF) == 2)
      {
        D_80112F81 = 1;
        D_80102CC0 = 0x2BC;
      }
    }
    temp_s0_4 = timerGetTotalSeconds(&D_80102EFC);
    if (temp_s0_4 <= timerGetTotalSeconds(inline_fn234(temp_s5) + ((inline_fn(func_800316B8()) * 8) + (&D_80117578))))
    {
      var_a0 = func_80030C58();
      switch (var_a0)
      {
        case 2:
          if ((func_800316B8() & 0xFFFF) == 1)
        {
          if (p_ee0)
          {
            func_8002BC68(5, 1);
            var_v0 = 0x2AF;
            goto block_59;
          }
          else
          {
            func_8002BC68(5, 1);
            var_v0 = 0x2AF;
            goto block_59;
          }
        }
          break;

        case 20:
          if (!(func_800316B8() & 0xFFFF))
        {
          D_80112F7F = 1;
          D_80102CBC = 0x2BA;
        }
          if ((func_800316B8() & 0xFFFF) == 1)
        {
          func_8002BC68(8, 1);
          D_80102CBE = 0x2B0;
          return;
        }
          break;

        case 16:
          if (inline_fn(func_800316B8()) == 2)
        {
          sOptionReady7 = 1;
          var_v0 = 0x2B7;
          goto block_59;
        }
          break;

        case 34:
          if (!inline_fn(func_800316B8()))
        {
          gMenuFlagItem27 = 1;
          var_v0 = 0x2C0;
          goto block_59;
        }
          break;

        case 25:
          if ((func_800316B8() & 0xFFFF) == 2)
        {
          func_8002BC68(1, 1);
          D_80102CBC = 0x2B4;
        }
          if ((func_800316B8() & 0xFFFF) == 1)
        {
          gMenuFlagItem20 = 1;
          var_v0 = 0x2BE;
          goto block_59;
        }
          break;

        case 38:
          if ((func_800316B8() & 0xFFFF) == 2)
        {
          sMenuRowEnabled = 1;
          var_v0 = 0x2BD;
          goto block_59;
        }
          break;

        case 1:
          if (!inline_fn(func_800316B8()))
        {
          func_8002BC68(9, 1);
          var_v0 = 0x2AE;
          goto block_59;
        }
          break;

        case 11:
          if (!(func_800316B8() & 0xFFFF))
        {
          gMenuFlagItem22 = 1;
          D_80102CBC = 0x2BF;
        }
          if ((func_800316B8() & 0xFFFF) == 2)
        {
          func_8002BC68(2, 1);
          D_80102CC0 = 0x2B2;
          return;
        }
          break;

        case 41:
          if (!inline_fn(func_800316B8()))
        {
          func_8002BC68(6, 1);
          D_80102CBC = 0x2B6;
        }
          if ((func_800316B8() & 0xFFFF) == 1)
        {
          func_8002BC68(3, 1);
          D_80102CBE = 0x2B1;
          return;
        }
          break;

        case 40:
          if (!inline_fn(func_800316B8()))
        {
          sOptionReady8 = 1;
          var_v0 = 0x2B8;
          goto block_59;
        }
          break;

        case 28:
          if (inline_fn(func_800316B8()) == 1)
        {
          D_80112F80 = 1;
          var_v0 = 0x2BB;
          goto block_59;
        }
          break;

        case 18:
          if (inline_fn(func_800316B8()) == 1)
        {
          D_80112F84 = 1;
          D_80102CBE = 0x2B9;
          return;
        }
          break;

        case 29:
          if (inline_fn(func_800316B8()) == 2)
        {
          func_8002BC68(7, 1);
          var_v0 = 0x2B5;
          goto block_59;
        }
          break;

      }

    }
  }
  return;
  block_59:
  D_80102CBC = var_v0;

}

