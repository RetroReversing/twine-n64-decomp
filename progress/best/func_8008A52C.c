s32 func_80089890();
s32 advanceLoopPosition();
s32 slotFindOrAlloc();
s32 func_80089F7C();
f64 func_8008CD54();
s32 func_800CEEE0();
extern f64 D_800D6760;
extern f64 D_800D6768;
extern f64 D_800D6770;
extern u8 *D_800E4218;
extern u16 *D_800E421C;
extern s32 D_8010D378;
extern s32 D_8010D42C;
inline static u32 inline_fn(u32 *arg0)
{
  return arg0[0];
}

inline static int inline_fn2(u32 *arg0)
{
  return ((((u32) arg0[0]) >> 6) * 0x28) + 0x100;
}

inline static int inline_fn23(u32 arg0)
{
  return ((arg0 >> 6) * 0x28) + 0x100;
}

inline static int inline_fn234(int arg0)
{
  return arg0;
}

inline static int inline_fn2345(void *arg0)
{
  return (*((u16 *) (((char *) arg0) + 4))) * 0x10;
}

typedef struct { f32 v; } Field_f32;
typedef struct { f64 v; } Field_f64;
typedef struct { s16 v; } Field_s16;
typedef struct { s32 v; } Field_s32;
typedef struct { s8 v; } Field_s8;
typedef struct { u16 v; } Field_u16;
typedef struct { u32 v; } Field_u32;
typedef struct { u8 v; } Field_u8;
void func_8008A52C(void *arg0, s32 arg1, s32 arg2)
{
  u32 sp10[6];
  u8 sp28;
  s32 var_s5;
  f64 temp_fv0;
  register f64 temp_fv1_9;
  s32 var_a0_2;
  s16 var_s6;
  int var_v0_2;
  s32 temp_a1;
  s32 temp_a3_3;
  s32 temp_a3_4;
  s32 temp_a3_5;
  register s32 temp_fv1_2;
  register s32 temp_a3_6;
  s32 temp_fv1;
  s32 temp_fv1_3;
  s32 temp_fv1_4;
  s32 temp_fv1_5;
  s32 var_v0;
  s32 temp_fv1_7;
  s32 temp_fv1_8;
  s32 temp_s0_2;
  s32 temp_s0_2_b1;
  s32 var_a1;
  s32 var_a0;
  s32 temp_fv1_6;
  u16 *temp_v0;
  u16 temp_a3;
  register u32 temp_a0;
  u32 temp_a0_2;
  u32 temp_a2;
  u32 temp_a3_2;
  u32 temp_s0;
  u32 temp_v1_2;
  u8 temp_a0_3;
  u8 temp_s0_3;
  u8 temp_s4;
  u8 temp_s4_2;
  u8 temp_v1_3;
  u8 temp_v1_4;
  unsigned var_s3;
  u8 var_s3_2;
  u32 var_s4;
  void *temp_s1;
  s32 old = D_8010D378;
  temp_v0 = (u16 *) (D_800E4218 + ((*D_800E421C) * 0xA10));
  temp_a3_2 = *temp_v0;
  temp_a1 = D_8010D42C + 0x50;
  D_8010D42C = temp_a1;
  temp_s0 = (temp_a3_2 * 0x50) + 0x10; temp_s1 = ((char *) temp_v0) + temp_s0;
  D_8010D378 = func_800CEEE0(old, temp_a1);
  temp_s0 = ((u32) ((((((Field_u16 *) (((char *) arg0) + 4))->v)) * 0xC0) + 0xFFF)) >> 0xC;
  temp_fv0 = func_8008CD54((((Field_f64 *) (((char *) arg0) + 8))->v));
  temp_s0_2 = temp_s0 + 6;
  if (!(D_800D6760 <= temp_fv0))
  {
    var_a1 = (s32) temp_fv0;
  }
  else
  {
    var_a1 = ((s32) (temp_fv0 - D_800D6760)) | 0x80000000;
  }
  temp_a0 = (*((volatile u32 *) (((char *) arg0) + 0x34))) + (*((volatile u32 *) (((char *) arg0) + 0x38)));
  temp_a3_2 = *((volatile u32 *) (((char *) arg0) + 0x38));
  sp28 = 2;
  if (temp_a3_2 != 0 && ((((Field_u8 *) (((char *) arg0) + 1))->v) != 0 || (((Field_s32 *) (((char *) arg0) + 0x3C))->v) == 0) && temp_a0 >= (u32) var_a1)
  {
    var_s6 = 0;
    if (temp_a0 < ((u32) (var_a1 + temp_s0_2)))
    {
      temp_v1_2 = (((Field_u32 *) (((char *) arg0) + 0x34))->v);
      temp_a0_2 = temp_a0 - var_a1;
      if (temp_v1_2 >= var_a1)
      {
        sp10[0] = (u32) var_a1;
        sp10[3] = 0;
        sp10[2] = (((((Field_u32 *) (((char *) arg0) + 0x34))->v)) - var_a1) + ((((Field_u32 *) (((char *) arg0) + 0x38))->v));
        var_s6 = 0;
        var_s5 = ((((Field_u32 *) (((char *) arg0) + 0x34))->v)) - var_a1;
      }
      else
      {
        temp_a2 = temp_s0_2 - temp_a0_2;
        if ((temp_a3_2 < temp_a2) || ((var_s6 = 0, (temp_a2 < ((u32) (var_a1 - temp_v1_2))) == 0)))
        {
          sp10[0] = temp_v1_2;
          var_s6 = var_a1 - temp_v1_2;
          var_s5 = 0;
          sp10[3] = 0;
          sp10[2] = (((Field_u32 *) (((char *) arg0) + 0x38))->v);
        }
        else
        {
          sp10[2] = temp_a0_2;
          sp10[0] = var_a1;
          var_s5 = 0;
          sp10[3] = temp_a2 - 6;
          sp10[1] = (((Field_u32 *) (((char *) arg0) + 0x34))->v);
        }
      }
    }
    else
    {
      var_s5 = -1;
      sp10[0] = var_a1;
      sp10[3] = 0;
      sp10[2] = temp_s0_2 - 6;
    }
  }
  else
  {
    var_s6 = 0;
    if (((u32) (var_a1 + temp_s0_2)) >= ((u32) ((((Field_u32 *) (((char *) arg0) + 0x30))->v))))
    {
      sp10[0] = var_a1;
      var_s5 = -2;
      sp10[3] = 0;
      sp10[2] = (((((Field_u32 *) (((char *) arg0) + 0x30))->v)) - var_a1) + 0x20;
      sp28 = 0;
    }
    else
    {
      var_s5 = -1;
      sp10[0] = var_a1;
      sp10[2] = temp_s0_2 - 6;
      sp10[3] = 0;
    }
  }
  sp10[4] = sp10[2] + 6;
  if (sp10[3] != 0)
  {
    sp10[5] = sp10[3] + 6;
  }
  if (((((Field_u16 *) (((char *) arg0) + 2))->v)) & 1)
  {
    temp_v1_3 = (((Field_u8 *) (((char *) arg0) + 0x5D))->v);
    if (temp_v1_3 != 0)
    {
      if (temp_v1_3 == 3)
      {
        if (sp10[3] != 0)
        {
          temp_a3_3 = (((Field_s32 *) (((char *) arg0) + 0x2C))->v);
          var_s4 = (sp10[1] & 0x3F) & 0xFF;
          temp_s0_2_b1 = (u8) (var_s4 & 0x1F);
          func_80089F7C(temp_s1 + 0x30, temp_a3_3 + inline_fn23(sp10[1]), (((u32) (((var_s4 >> 5) + (((u32) ((sp10[5] + temp_s0_2_b1) + 0x1F)) >> 5)) + 1)) >> 1) * 0x28, temp_a3_3 + 0x100);
          (((Field_u8 *) (((char *) temp_s1) + 0x3F))->v) = var_s4;
          var_s4 = temp_s0_2_b1;
          (((Field_s8 *) (((char *) temp_s1) + 0x3D))->v) = (s8) (((u32) ((var_s4 + sp10[5]) + 0x1F)) >> 5);
        }
        else
        {
          (((Field_s32 *) (((char *) temp_s1) + 0x30))->v) = 0;
          (((Field_s8 *) (((char *) temp_s1) + 0x3D))->v) = 0;
        }
        temp_a3_4 = (((Field_s32 *) (((char *) arg0) + 0x2C))->v);
        var_s3_2 = (sp10[0] & 0x3F) & 0xFF;
        func_80089F7C(temp_s1 + 0x24, temp_a3_4 + inline_fn2(sp10), (((u32) (((((u32) ((sp10[4] + (var_s3_2 & 0x1F)) + 0x1F)) >> 5) + (var_s3_2 >> 5)) + 1)) >> 1) * 0x28, temp_a3_4 + 0x100);
        (((Field_s32 *) (((char *) temp_s1) + 0x40))->v) = slotFindOrAlloc((((Field_s32 *) (((char *) arg0) + 0x2C))->v));
        goto block_38;
      }
    }
    else
    {
      if (sp10[3] != 0)
      {
        temp_a3_5 = (((Field_s32 *) (((char *) arg0) + 0x2C))->v);
        var_s4 = (sp10[1] & 3) & 0xFF;
        func_80089F7C(temp_s1 + 0x30, temp_a3_5 + ((sp10[1] & 0xFFFC) * 2), (((var_s4 + sp10[5]) + 3) & 0xFFFC) * 2, temp_a3_5);
        (((Field_u8 *) (((char *) temp_s1) + 0x3F))->v) = var_s4;
        (((Field_s16 *) (((char *) temp_s1) + 0x42))->v) = (s16) sp10[5];
      }
      else
      {
        (((Field_s32 *) (((char *) temp_s1) + 0x30))->v) = 0;
        (((Field_s16 *) (((char *) temp_s1) + 0x42))->v) = 0;
      }
      temp_a3_6 = (((Field_s32 *) (((char *) arg0) + 0x2C))->v);
      var_s3 = (sp10[0] & 3) & 0xFF;
      func_80089F7C(temp_s1 + 0x24, temp_a3_6 + ((sp10[0] & 0xFFFC) * 2), (((var_s3 + sp10[4]) + 3) & 0xFFFC) * 2, temp_a3_6);
      (((Field_s8 *) (((char *) temp_s1) + 0x3C))->v) = 0;
      (((Field_u8 *) (((char *) temp_s1) + 0x3E))->v) = var_s3;
      (((Field_s16 *) (((char *) temp_s1) + 0x40))->v) = (s16) sp10[4];
    }
  }
  else
  {
    temp_v1_4 = (((Field_u8 *) (((char *) arg0) + 0x5D))->v);
    if (temp_v1_4 != 0)
    {
      if (temp_v1_4 == 3)
      {
        if (!(sp10[3] == 0))
        {
          temp_s4_2 = (sp10[1] & 0x3F) & 0xFF;
          (((Field_s32 *) (((char *) temp_s1) + 0x30))->v) = (s32) (((((Field_s32 *) (((char *) arg0) + 0x2C))->v)) + inline_fn23(sp10[1]));
          temp_s0_2 = (u8) (temp_s4_2 & 0x1F);
          (((Field_s16 *) (((char *) temp_s1) + 0x3A))->v) = 0;
          (((Field_u8 *) (((char *) temp_s1) + 0x3F))->v) = temp_s4_2;
          (((Field_s16 *) (((char *) temp_s1) + 0x38))->v) = (s16) ((((u32) (((((u32) ((sp10[5] + temp_s0_2) + 0x1F)) >> 5) + (temp_s4_2 >> 5)) + 1)) >> 1) * 0x28);
          var_s4 = temp_s0_2;
          (((Field_s8 *) (((char *) temp_s1) + 0x3D))->v) = (s8) (((u32) ((var_s4 + sp10[5]) + 0x1F)) >> 5);
        }
        else
        {
          (((Field_s32 *) (((char *) temp_s1) + 0x30))->v) = 0;
          (((Field_s8 *) (((char *) temp_s1) + 0x3D))->v) = 0;
        }
        (((Field_s32 *) (((char *) temp_s1) + 0x24))->v) = (s32) (((((Field_s32 *) (((char *) arg0) + 0x2C))->v)) + inline_fn2(sp10));
        var_s3_2 = (inline_fn(sp10) & 0x3F) & 0xFF;
        (((Field_s16 *) (((char *) temp_s1) + 0x2C))->v) = (s16) ((((u32) (((((u32) inline_fn234((sp10[4] + (var_s3_2 & 0x1F)) + 0x1F)) >> 5) + (var_s3_2 >> 5)) + 1)) >> 1) * 0x28);
        (((Field_s16 *) (((char *) temp_s1) + 0x2E))->v) = 0;
        (((Field_s32 *) (((char *) temp_s1) + 0x40))->v) = (s32) ((((Field_s32 *) (((char *) arg0) + 0x2C))->v));
        block_38:
        (((Field_u8 *) (((char *) temp_s1) + 0x3E))->v) = var_s3_2;

        var_s3 = var_s3_2 & 0x1F;
        (((Field_s8 *) (((char *) temp_s1) + 0x3C))->v) = (s8) (((u32) ((var_s3 + sp10[4]) + 0x1F)) >> 5);
      }
    }
    else
    {
      if (sp10[3] == 0)
      {
        (((Field_s32 *) (((char *) temp_s1) + 0x30))->v) = 0;
        (((Field_s16 *) (((char *) temp_s1) + 0x42))->v) = 0;
      }
      else
      {
        (((Field_s32 *) (((char *) temp_s1) + 0x30))->v) = (s32) (((((Field_s32 *) (((char *) arg0) + 0x2C))->v)) + ((sp10[1] & 0xFFFC) * 2));
        var_s4 = (sp10[1] & 3) & 0xFF;
        (((Field_s16 *) (((char *) temp_s1) + 0x3A))->v) = 0;
        (((Field_s16 *) (((char *) temp_s1) + 0x38))->v) = (s16) ((((var_s4 + sp10[5]) + 3) & 0xFFFC) * 2);
        do
        {
          (((Field_s16 *) (((char *) temp_s1) + 0x42))->v) = (s16) sp10[5];
        }
        while (0);
        (((Field_u8 *) (((char *) temp_s1) + 0x3F))->v) = var_s4;
      }
      (((Field_s32 *) (((char *) temp_s1) + 0x24))->v) = (s32) (((((Field_s32 *) (((char *) arg0) + 0x2C))->v)) + ((inline_fn(sp10) & 0xFFFC) * 2));
      var_s3 = (inline_fn(sp10) & 3) & 0xFF;
      (((Field_s16 *) (((char *) temp_s1) + 0x2E))->v) = 0;
      (((Field_s16 *) (((char *) temp_s1) + 0x2C))->v) = (s16) ((((var_s3 + sp10[4]) + 3) & 0xFFFC) * 2);
      (((Field_s8 *) (((char *) temp_s1) + 0x3C))->v) = 0;
      (((Field_u8 *) (((char *) temp_s1) + 0x3E))->v) = var_s3;
      (((Field_s16 *) (((char *) temp_s1) + 0x40))->v) = (s16) sp10[4];
    }
  }
  (((Field_s16 *) (((char *) temp_s1) + 0x4E))->v) = var_s6;
  if (var_s5 == (-1))
  {
    (((Field_s16 *) (((char *) temp_s1) + 0x48))->v) = 0x4000;
  }
  else
  {
    if (var_s5 == (-2))
    {
      (((Field_s16 *) (((char *) temp_s1) + 0x48))->v) = (s16) (var_s3 + sp10[2]);
      var_v0_2 = (var_s3 + sp10[2]) - 0x20;
    }
    else
    {
      (((Field_s16 *) (((char *) temp_s1) + 0x48))->v) = (s16) (var_s3 + sp10[2]);
      if (((((Field_s32 *) (((char *) temp_s1) + 0x30))->v)) != 0)
      {
        var_v0_2 = (var_s4 + var_s5) | 0x8000;
      }
      else
      {
        var_v0_2 = var_s3 + var_s5;
      }
    }
    (((Field_s16 *) (((char *) temp_s1) + 0x4A))->v) = var_v0_2;
  }
  (((Field_s8 *) (((char *) arg0) + 0x60))->v) = arg2;
  func_80089890(arg0, 0xC0, &sp28);
  var_a0 = 0x2AAA0000;
  if (((((Field_u8 *) (((char *) arg0) + 0))->v)) == 1)
  {
    temp_fv1 = (s32) (((f32) ((((Field_s16 *) (((char *) arg0) + 0x40))->v))) * ((((Field_f32 *) (((char *) arg0) + 0x4C))->v)));
    (((Field_s16 *) (((char *) arg0) + 0x18))->v) = (s16) temp_fv1;
    (((Field_s32 *) (((char *) temp_s1) + 0))->v) = (s32) (temp_fv1 << 0x10);
    temp_fv1_2 = (s32) (((f32) ((((Field_s16 *) (((char *) arg0) + 0x42))->v))) * ((((Field_f32 *) (((char *) arg0) + 0x4C))->v)));
    (((Field_s16 *) (((char *) arg0) + 0x1A))->v) = (s16) temp_fv1_2;
    (((Field_s32 *) (((char *) temp_s1) + 4))->v) = (s32) (temp_fv1_2 << 0x10);
    temp_fv1_3 = (s32) (((f32) ((((Field_s16 *) (((char *) arg0) + 0x44))->v))) * ((((Field_f32 *) (((char *) arg0) + 0x4C))->v)));
    (((Field_s16 *) (((char *) arg0) + 0x1C))->v) = (s16) temp_fv1_3;
    (((Field_s32 *) (((char *) temp_s1) + 8))->v) = (s32) (temp_fv1_3 << 0x10);
    temp_fv1_4 = (s32) (((f32) ((((Field_s16 *) (((char *) arg0) + 0x46))->v))) * ((((Field_f32 *) (((char *) arg0) + 0x4C))->v)));
    (((Field_s16 *) (((char *) arg0) + 0x1E))->v) = (s16) temp_fv1_4;
    (((Field_s32 *) (((char *) temp_s1) + 0xC))->v) = (s32) (temp_fv1_4 << 0x10);
    (((Field_s32 *) (((char *) temp_s1) + 0x1C))->v) = 0;
    (((Field_s32 *) (((char *) temp_s1) + 0x18))->v) = 0;
    (((Field_s32 *) (((char *) temp_s1) + 0x14))->v) = 0;
    (((Field_s32 *) (((char *) temp_s1) + 0x10))->v) = 0;
  }
  else
  {
    (((Field_s32 *) (((char *) temp_s1) + 0))->v) = (s32) (((((Field_s16 *) (((char *) arg0) + 0x18))->v)) << 0x10);
    (((Field_s32 *) (((char *) temp_s1) + 4))->v) = (s32) (((((Field_s16 *) (((char *) arg0) + 0x1A))->v)) << 0x10);
    (((Field_s32 *) (((char *) temp_s1) + 8))->v) = (s32) (((((Field_s16 *) (((char *) arg0) + 0x1C))->v)) << 0x10);
    (((Field_s32 *) (((char *) temp_s1) + 0xC))->v) = (s32) (((((Field_s16 *) (((char *) arg0) + 0x1E))->v)) << 0x10);
    temp_fv1_5 = (s32) (((f32) ((((Field_s16 *) (((char *) arg0) + 0x40))->v))) * ((((Field_f32 *) (((char *) arg0) + 0x4C))->v)));
    (((Field_s16 *) (((char *) arg0) + 0x18))->v) = (s16) temp_fv1_5;
    var_a0 = 0x2AAAAAAB;
    (((Field_s32 *) (((char *) temp_s1) + 0x10))->v) = (s32) (((temp_fv1_5 << 0x10) - ((((Field_s32 *) (((char *) temp_s1) + 0))->v))) / 192);
    temp_fv1_6 = (s32) (((f32) ((((Field_s16 *) (((char *) arg0) + 0x42))->v))) * ((((Field_f32 *) (((char *) arg0) + 0x4C))->v)));
    (((Field_s16 *) (((char *) arg0) + 0x1A))->v) = (s16) temp_fv1_6;
    (((Field_s32 *) (((char *) temp_s1) + 0x14))->v) = (s32) (((temp_fv1_6 << 0x10) - ((((Field_s32 *) (((char *) temp_s1) + 4))->v))) / 192);
    temp_fv1_7 = (s32) (((f32) ((((Field_s16 *) (((char *) arg0) + 0x44))->v))) * ((((Field_f32 *) (((char *) arg0) + 0x4C))->v)));
    (((Field_s16 *) (((char *) arg0) + 0x1C))->v) = (s16) temp_fv1_7;
    (((Field_s32 *) (((char *) temp_s1) + 0x18))->v) = (s32) (((temp_fv1_7 << 0x10) - ((((Field_s32 *) (((char *) temp_s1) + 8))->v))) / 192);
    temp_fv1_8 = (s32) (((f32) ((((Field_s16 *) (((char *) arg0) + 0x46))->v))) * ((((Field_f32 *) (((char *) arg0) + 0x4C))->v)));
    (((Field_s16 *) (((char *) arg0) + 0x1E))->v) = (s16) temp_fv1_8;
    (((Field_s32 *) (((char *) temp_s1) + 0x1C))->v) = (s32) (((temp_fv1_8 << 0x10) - ((((Field_s32 *) (((char *) temp_s1) + 0xC))->v))) / 192);
  }
  (((Field_u16 *) (((char *) temp_s1) + 0x22))->v) = (u16) ((((Field_u16 *) (((char *) arg0) + 4))->v));
  temp_fv1_9 = (((((Field_f64 *) (((char *) arg0) + 8))->v)) - func_8008CD54((((Field_f64 *) (((char *) arg0) + 8))->v))) * D_800D6768;
  if (!(D_800D6770 <= temp_fv1_9))
  {
    var_a0_2 = (s32) temp_fv1_9;
    (((Field_s16 *) (((char *) temp_s1) + 0x20))->v) = var_a0_2;
  }
  else
  {
    var_a0_2 = ((s32) (temp_fv1_9 - D_800D6770)) | 0x80000000;
    (((Field_s16 *) (((char *) temp_s1) + 0x20))->v) = var_a0_2;
  }
  (((Field_s32 *) (((char *) temp_s1) + 0x44))->v) = 0;
  (((Field_s16 *) (((char *) temp_s1) + 0x4C))->v) = (s16) (var_a0_2 + (inline_fn2345(arg0) * sp10[4]));
  temp_v0 = ((*D_800E421C) * 0xA10) + D_800E4218;
  *temp_v0 += 1;
  advanceLoopPosition(arg0, 0xC0);
  (((Field_u8 *) (((char *) arg0) + 0))->v) = sp28;
}


