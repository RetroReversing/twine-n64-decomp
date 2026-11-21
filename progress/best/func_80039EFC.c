extern f64 D_800D2EF8;
extern f64 D_800D2F00;
extern f64 D_800D2F08;
extern f64 D_800D2F10;
extern f64 D_800D2F18;
extern f64 D_800D2F20;
extern f64 D_800D2F28;
extern s32 gHiResScreen;
inline static int inline_fn(int arg0, int arg1)
{
  return arg0 | arg1;
}

inline static int inline_fn2(u32 arg0, int arg1)
{
  return arg0 | arg1;
}

void func_80039EFC(u32 **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, volatile int arg8, s32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13, f32 arg14, f32 arg15)
{
  u32 sp14;
  u32 **sp4;
  s32 spC;
  volatile s32 sp1C;
  volatile s32 sp24;
  s32 sp2C;
  f32 ratioX;
  f32 ratioY;
  f32 temp_ft1;
  register f32 temp_fv0;
  f32 var_fv0;
  f32 var_fv1_3;
  f64 var_ft0;
  f64 var_ft0_2;
  f64 var_ft0_3;
  f64 var_ft0_4;
  f64 var_fv1;
  f64 var_fv1_2;
  register s32 temp_a0;
  register s32 temp_a0_2;
  s32 temp_a0_3;
  s32 temp_a1;
  s32 temp_a1_2;
  s32 temp_a1_3;
  register s32 temp_a1_4;
  s32 temp_a2;
  s32 temp_a2_2;
  s32 temp_a2_3;
  s32 temp_a2_4;
  s32 temp_a3;
  s32 temp_fv1;
  s32 temp_t3;
  s32 temp_t7;
  s32 temp_v1;
  register s32 temp_v1_2;
  s32 var_a0;
  volatile unsigned long var_a0_2;
  u8 *var_t1;
  unsigned var_t6;
  s32 var_t8;
  s32 var_v1;
  u32 temp_s0;
  u32 temp_s1;
  u32 var_a3;
  u32 var_t2;
  register u32 var_t4;
  u32 var_t5;
  u8 *var_t0;
  ;
  spC = arg3;
  var_t1 = (u8 *) (*arg0);
  var_ft0 = (f64) arg6;
  if (0 > arg6)
  {
    var_ft0 += D_800D2EF8;
  }
  var_fv1 = (f64) arg4;
  if (arg4 < 0)
  {
    var_fv1 += D_800D2F00;
  }
  ratioX = ((f32) var_ft0) / ((f32) var_fv1);
  var_ft0_2 = (f64) arg7;
  if (0 > arg7)
  {
    var_ft0_2 += D_800D2F08;
  }
  var_fv1_2 = (f64) arg5;
  if (0 > arg5)
  {
    if (D_800D2F28)
    {
      var_fv1_2 += D_800D2F10;
    }
    else
    {
      var_fv1_2 += D_800D2F10;
    }
  }
  ratioY = ((f32) var_ft0_2) / ((f32) var_fv1_2);
  var_ft0_3 = (f64) arg8;
  if (arg8 < 0)
  {
    var_ft0_3 += D_800D2F18;
  }
  var_ft0_4 = (f64) arg9;
  temp_fv1 = (s32) (((f32) var_ft0_3) * ratioX);
  if (arg9 < 0)
  {
    var_ft0_4 += D_800D2F20;
  }
  var_t5 = arg11;
  var_t8 = arg15;
  sp2C = (s32) (((f32) var_ft0_4) * ratioY);
  if (arg13 > var_t5)
  {
    temp_s1 = arg12 - 1;
    temp_s0 = arg13 - 1;
    temp_t7 = (arg2 & 7) << 0x15;
    sp14 = ((u32) arg4) >> 1;
    do
    {
      var_t4 = arg10;
      var_t6 = (s32) arg14;
      if (var_t4 < arg12)
      {
        var_t0 = var_t1 - 4;
        sp1C = temp_t7 | inline_fn2((sp14 - 1) & 0xFFF, 0xFD080000);
        sp24 = temp_t7 | (((arg4 - 1) & 0xFFF) | 0xFD080000);
        temp_ft1 = (f32) (((f64) ((f32) ((s32) var_t5))) + D_800D2F28);
        do
        {
          temp_a1 = var_t4 - 1;
          temp_t3 = (temp_a1 < 0) ? (0) : (temp_a1);
          var_t2 = var_t4 + arg8;
          temp_fv0 = (f32) (((f64) ((f32) ((s32) var_t4))) + D_800D2F28);
          if (temp_s1 < var_t2)
          {
            var_t2 = temp_s1;
          }
          temp_a2 = var_t5 - 1;
          temp_a2_2 = (temp_a2 < 0) ? (0) : (temp_a2);
          var_a3 = var_t5 + arg9;
          if (temp_s0 < var_a3)
          {
            var_a3 = temp_s0;
          }
          var_t0 += 8;
          switch (spC)
          {
            case 0:
            {
              temp_a0 = ((((s32) ((((s32) ((var_t2 - temp_t3) + 1)) >> 1) + 7)) >> 3) & 0x1FF) << 9;
              temp_a1_2 = (temp_a2_2 * 4) & 0xFFF;
              temp_a2_3 = (var_a3 * 4) & 0xFFF;
              var_t1 += 0x38;
              *((s32 *) (((char *) var_t0) + (-4))) = sp1C;
              *((s32 *) (((char *) var_t0) + 0)) = arg1;
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + (-4))) = (s32) (temp_t7 | inline_fn2(((((s32) ((((s32) ((var_t2 - temp_t3) + 1)) >> 1) + 7)) >> 3) & 0x1FF) << 9, 0xF5080000));
              *((s32 *) (((char *) var_t0) + 0)) = 0x07080200;
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + (-4))) = 0xE6000000;
              *((s32 *) (((char *) var_t0) + 0)) = 0;
              var_t0 += 8;
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + 0)) = (s32) ((((var_t2 * 2) & 0xFFF) << 0xC) | inline_fn2(temp_a2_3, 0x07000000));
              *((s32 *) (((char *) var_t0) + (-4))) = (s32) ((((temp_t3 * 2) & 0xFFF) << 0xC) | inline_fn2(temp_a1_2, 0xF4000000));
              *((s32 *) (((char *) var_t0) + (-4))) = 0xE7000000;
              *((s32 *) (((char *) var_t0) + 0)) = 0;
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + (-4))) = (s32) inline_fn2(temp_t7, inline_fn2(temp_a0, 0xF5000000));
              *((s32 *) (((char *) var_t0) + 0)) = 0x80200;
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + (-4))) = (s32) ((((temp_t3 * 4) & 0xFFF) << 0xC) | inline_fn2(temp_a1_2, 0xF2000000));
              *((s32 *) (((char *) var_t0) + 0)) = (s32) ((((var_t2 * 4) & 0xFFF) << 0xC) | temp_a2_3);
            }
              break;

            default:
            {
              temp_v1 = inline_fn2(temp_t7, inline_fn2(((((s32) ((var_t2 - temp_t3) + 8)) >> 3) & 0x1FF) << 9, 0xF5080000));
              temp_a1_3 = ((temp_t3 * 4) & 0xFFF) << 0xC;
              temp_a2_2 = (temp_a2_2 * 4) & 0xFFF;
              temp_a0_2 = ((var_t2 * 4) & 0xFFF) << 0xC;
              temp_a3 = (var_a3 * 4) & 0xFFF;
              var_t1 += 0x38;
              *((s32 *) (((char *) var_t0) + 0)) = arg1;
              *((s32 *) (((char *) var_t0) + (-4))) = sp24;
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + (-4))) = temp_v1;
              *((s32 *) (((char *) var_t0) + 0)) = 0x07080200;
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + (-4))) = 0xE6000000;
              *((s32 *) (((char *) var_t0) + 0)) = 0;
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + 0)) = (s32) inline_fn2(temp_a0_2, inline_fn2(temp_a3, 0x07000000));
              *((s32 *) (((char *) var_t0) + (-4))) = (s32) inline_fn2(temp_a1_3, temp_a2_2 | 0xF4000000);
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + (-4))) = 0xE7000000;
              *((s32 *) (((char *) var_t0) + 0)) = 0;
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + (-4))) = temp_v1;
              *((s32 *) (((char *) var_t0) + 0)) = 0x80200;
              var_t0 += 8;
              *((s32 *) (((char *) var_t0) + (-4))) = (s32) (temp_a1_3 | (temp_a2_2 | 0xF2000000));
              *((s32 *) (((char *) var_t0) + 0)) = (s32) inline_fn2(temp_a0_2, temp_a3);
            }
              break;

          }

          var_a0 = var_t6 + temp_fv1;
          var_v1 = var_t8 + sp2C;
          if (var_a0 >= 0x141)
          {
            var_a0 = 0x140;
          }
          if (var_v1 >= 0xF1)
          {
            var_v1 = 0xF0;
          }
          temp_a0_3 = var_a0 * 4;
          var_v1 = var_v1 * 4;
          temp_a1_4 = var_t6 * 4;
          if (gHiResScreen != 0)
          {
            var_t0 += 8;
            var_fv1_3 = temp_fv0 * 32.0f;
            *((s32 *) (((char *) var_t0) + (-4))) = (s32) inline_fn((temp_a0_3 & 0xFFF) << 0xC, inline_fn2((var_v1 * 2) & 0xFFF, 0xE4000000));
            *((s32 *) (((char *) var_t0) + 0)) = (s32) inline_fn2((temp_a1_4 & 0xFFF) << 0xC, (var_t8 * 8) & 0xFFF);
            var_t0 += 8;
            var_t1 += 0x18;
            var_fv0 = temp_ft1 * 32.0f;
            var_a0_2 = 0x04000200;
          }
          else
          {
            var_t0 += 8;
            *((s32 *) (((char *) var_t0) + (-4))) = (s32) (((temp_a0_3 & 0xFFF) << 0xC) | ((var_v1 & 0xFFF) | 0xE4000000));
            var_fv1_3 = temp_fv0 * 32.0f;
            *((s32 *) (((char *) var_t0) + 0)) = (s32) (((temp_a1_4 & 0xFFF) << 0xC) | ((var_t8 * 4) & 0xFFF));
            var_t0 += 8;
            var_t1 += 0x18;
            var_fv0 = temp_ft1 * 32.0f;
            var_a0_2 = 0x04000400;
          }
          *((s32 *) (((char *) var_t0) + (-4))) = 0xE1000000;
          *((s32 *) (((char *) var_t0) + 0)) = (s32) inline_fn2(((u32) ((s32) var_fv1_3)) << 0x10, ((s32) var_fv0) & 0xFFFF);
          var_t0 += 8;
          *((s32 *) (((char *) var_t0) + (-4))) = 0xF1000000;
          *((s32 *) (((char *) var_t0) + 0)) = var_a0_2;
          var_t4 += arg8;
          var_t6 += temp_fv1;
        }
        while (arg12 > var_t4);
      }
      var_t5 += arg9;
      var_t8 += sp2C;
    }
    while (var_t5 < arg13);
  }
  *arg0 = (u32 *) var_t1;
}

