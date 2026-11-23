s32 func_8008C1B0(s32);
s32 func_80095EC4(s32, s32);
s32 func_800982B4(u32 arg0);
void func_8009876C(void *);
s32 func_800988D8(void *);
void func_80098B14(void *, s32);
s32 func_80098D18(s32, s32, s32, u32);
extern u8 D_8010D724[];
inline static int inline_fn(unsigned char arg0)
{
  return arg0 & 0xFF;
}

inline static int inline_fn2(s32 arg0)
{
  return arg0 & 0xFF;
}

s32 func_8009C420(u32 arg0_in, s32 arg1_in, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8, u8 arg9, u8 arg10)
{
  s32 arg1;
  u32 arg0;
  u32 hi;
  unsigned char lo;
  s32 temp_v0;
  u8 var_s4;
  s32 var_v0;
  u32 temp_s5;
  unsigned char temp_s7;
  s32 temp_v0_2;
  u8 *temp_s0;
  s16 temp_v0_3;
  arg1 = arg1_in;
  arg0 = arg0_in;
  lo = arg0_in;
  var_s4 = arg2;
  temp_s7 = (arg0 >> 1) >> 7;
  temp_s5 = arg0 >> 0x10;
  temp_v0 = func_800982B4(temp_s5);
  if (temp_v0 != 0)
  {
    {
      {
        temp_v0_2 = func_80098D18(inline_fn(temp_s7), inline_fn(lo), arg1 & 0xFFFF, ((u32) inline_fn(var_s4)) >> 7);
        if (temp_v0_2 != (-1))
        {
          temp_s0 = D_8010D724 + (temp_v0_2 * 0x1A0);
          func_8009876C(temp_s0);
          *((s32 *) (temp_s0 + 0x24)) = ((*((s32 *) (temp_s0 + 0x24))) & 0x10) | 2;
          if (func_8008C1B0(temp_v0_2) & 0xFF)
          {
            *((s32 *) (temp_s0 + 0x24)) = (*((s32 *) (temp_s0 + 0x24))) | 1;
          }
          *((s32 *) (temp_s0 + 0x9C)) = 0;
          if (arg2 & 0x80)
          {
            var_s4 = arg2 & 0x7F;
            *((s8 *) (temp_s0 + 0x4C)) = 1;
            func_80095EC4(temp_v0_2 & 0xFF, 0xFF);
            *((u8 *) (temp_s0 + 0x54)) = temp_v0_2;
            *((u8 *) (temp_s0 + 0x55)) = 0xFF;
          }
          else
          {
            *((s8 *) (temp_s0 + 0x4C)) = 0;
            *((u8 *) (temp_s0 + 0x54)) = arg5;
            *((u8 *) (temp_s0 + 0x55)) = arg6;
          }
          *((s32 *) (temp_s0 + 0x28)) = 0x75300000;
          *((s16 *) (temp_s0 + 0x64)) = temp_s5;
          *((s16 *) (temp_s0 + 0xBA)) = arg1;
          *((s16 *) (temp_s0 + 0x2C)) = 0x400;
          { *((s32 *) (temp_s0 + 0)) = temp_v0; }
          *((s32 *) (temp_s0 + 4)) = temp_v0 + (arg7 * 8);
          ;
hi = temp_s5 << 0x10;
*((s16 *) (temp_s0 + 0x4E)) = var_s4;
*((s16 *) (temp_s0 + 0x50)) = var_s4;
*((s8 *) (temp_s0 + 0xC0)) = 0;
*((u8 *) (temp_s0 + 0x52)) = arg3;
*((u8 *) (temp_s0 + 0x53)) = arg4;
*((u8 *) (temp_s0 + 0x56)) = inline_fn(arg8);
*((s32 *) (temp_s0 + 0x10)) = -1;
*((s32 *) (temp_s0 + 0x14)) = -1;
*((s32 *) (temp_s0 + 8)) = 0;
*((u8 *) (temp_s0 + 0xBF)) = arg10;
          *((s32 *) (temp_s0 + 0x60)) = (hi | (inline_fn(var_s4) << 8)) | temp_v0_2;
          {
            func_80098B14(temp_s0, inline_fn(temp_s7));
          }
          if (arg9 != 0)
          {
            if (1)
            {
              return func_800988D8(temp_s0);
            }
          }
          return *((s32 *) (temp_s0 + 0x60));
        }
      }
    }
  }
  return -1;
}


