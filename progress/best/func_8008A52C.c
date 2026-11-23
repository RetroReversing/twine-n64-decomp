/* Partial candidate from function #296352744174 in project #69; rechecked locally. */
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
typedef struct Voice {
  u8 m0; u8 m1; u16 m2; u16 m4; u16 pad6; f64 m8; u8 pad10[8];
  s16 m18; s16 m1A; s16 m1C; s16 m1E; u8 pad20[12];
  s32 m2C; u32 m30; u32 m34; u32 m38; s32 m3C;
  s16 m40; s16 m42; s16 m44; s16 m46; u8 pad48[4]; f32 m4C;
  u8 pad50[13]; u8 m5D; u8 pad5E[2]; s8 m60;
} Voice;

inline static u32 inline_fn(u32 *arg0)
{
  return arg0[0];
}

inline static int inline_fn2(u32 *arg0)
{
  return ((((u32) arg0[0]) >> 6) * 0x28) + 0x100;
}

void func_8008A52C(Voice *arg0, s32 arg1, s8 arg2)
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
  s32 lo5;
  s32 lo5b;
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
  u8 temp_v1_3;
  u8 temp_v1_4;
  unsigned var_s3;
  u8 var_s4;
  void *temp_s1;
  u16 cnt;
  u16 *tab;
  s32 old = D_8010D378;
  tab = (u16 *) (D_800E4218 + ((*D_800E421C) * 0xA10));
  cnt = *tab;
  temp_a1 = D_8010D42C + 0x50;
  D_8010D42C = temp_a1;
  temp_s1 = ((char *) tab) + (cnt * 0x50 + 0x10);
  D_8010D378 = func_800CEEE0(old, temp_a1);
  temp_s0_2 = ((u32) (((arg0->m4) * 0xC0) + 0xFFF)) >> 0xC;
  temp_fv0 = func_8008CD54(arg0->m8);
  temp_s0_2 = temp_s0_2 + 6;
  if (!(D_800D6760 <= temp_fv0))
  {
    var_a1 = (s32) temp_fv0;
  }
  else
  {
    var_a1 = ((s32) (temp_fv0 - D_800D6760)) | 0x80000000;
  }
  temp_a0 = ((*(volatile u32 *) &arg0->m34)) + ((*(volatile u32 *) &arg0->m38));
  temp_a3_2 = (*(volatile u32 *) &arg0->m38);
  sp28 = 2;
  if ((temp_a3_2 != 0) && (((arg0->m1) != 0) || ((arg0->m3C) == 0)) && !(temp_a0 < ((u32) var_a1)))
  {
    var_s6 = 0;
    if (temp_a0 < ((u32) (var_a1 + temp_s0_2)))
    {
      temp_v1_2 = arg0->m34;
      temp_a0_2 = temp_a0 - var_a1;
      if (temp_v1_2 >= var_a1)
      {
        sp10[0] = (u32) var_a1;
        sp10[3] = 0;
        sp10[2] = ((arg0->m34) - var_a1) + (arg0->m38);
        var_s6 = 0;
        var_s5 = (arg0->m34) - var_a1;
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
          sp10[2] = arg0->m38;
        }
        else
        {
          sp10[2] = temp_a0_2;
          sp10[0] = var_a1;
          var_s5 = 0;
          sp10[3] = temp_a2 - 6;
          sp10[1] = arg0->m34;
        }
      }
    }
    else
    {
      var_s5 = -1;
      sp10[0] = var_a1;
      sp10[2] = temp_s0_2 - 6;
      sp10[3] = 0;
    }
  }
  else
  {
    var_s6 = 0;
    if (((u32) (var_a1 + temp_s0_2)) >= ((u32) (arg0->m30)))
    {
      sp10[0] = var_a1;
      var_s5 = -2;
      sp10[3] = 0;
      sp10[2] = ((arg0->m30) - var_a1) + 0x20;
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
  if ((arg0->m2) & 1)
  {
    temp_v1_3 = arg0->m5D;
    if (temp_v1_3 != 0)
    {
      if (temp_v1_3 == 3)
      {
        if (sp10[3] != 0)
        {
          temp_a3_3 = arg0->m2C;
          var_s4 = (sp10[1] & 0x3F) & 0xFF;
          lo5 = (u8) (var_s4 & 0x1F);
          func_80089F7C(temp_s1 + 0x30, temp_a3_3 + (((sp10[1] >> 6) * 0x28) + 0x100), (((u32) (((var_s4 >> 5) + (((u32) ((sp10[5] + lo5) + 0x1F)) >> 5)) + 1)) >> 1) * 0x28, temp_a3_3 + 0x100);
          *((u8 *) (((char *) temp_s1) + 0x3F)) = var_s4;
          var_s4 = lo5;
          *((s8 *) (((char *) temp_s1) + 0x3D)) = (s8) (((u32) ((var_s4 + sp10[5]) + 0x1F)) >> 5);
        }
        else
        {
          *((s32 *) (((char *) temp_s1) + 0x30)) = 0;
          *((s8 *) (((char *) temp_s1) + 0x3D)) = 0;
        }
        temp_a3_4 = arg0->m2C;
        var_s3 = (sp10[0] & 0x3F) & 0xFF;
        func_80089F7C(temp_s1 + 0x24, temp_a3_4 + inline_fn2(sp10), (((u32) (((((u32) ((sp10[4] + (var_s3 & 0x1F)) + 0x1F)) >> 5) + (var_s3 >> 5)) + 1)) >> 1) * 0x28, temp_a3_4 + 0x100);
        *((s32 *) (((char *) temp_s1) + 0x40)) = slotFindOrAlloc(arg0->m2C);
        goto block_38;
      }
    }
    else
    {
      if (sp10[3] != 0)
      {
        temp_a3_5 = arg0->m2C;
        var_s4 = (sp10[1] & 3) & 0xFF;
        func_80089F7C(temp_s1 + 0x30, temp_a3_5 + ((sp10[1] & 0xFFFC) * 2), (((var_s4 + sp10[5]) + 3) & 0xFFFC) * 2, temp_a3_5);
        *((u8 *) (((char *) temp_s1) + 0x3F)) = var_s4;
        *((s16 *) (((char *) temp_s1) + 0x42)) = (s16) sp10[5];
      }
      else
      {
        *((s32 *) (((char *) temp_s1) + 0x30)) = 0;
        *((s16 *) (((char *) temp_s1) + 0x42)) = 0;
      }
      temp_a3_6 = arg0->m2C;
      var_s3 = (sp10[0] & 3) & 0xFF;
      func_80089F7C(temp_s1 + 0x24, temp_a3_6 + ((sp10[0] & 0xFFFC) * 2), (((var_s3 + sp10[4]) + 3) & 0xFFFC) * 2, temp_a3_6);
      *((s8 *) (((char *) temp_s1) + 0x3C)) = 0;
      *((u8 *) (((char *) temp_s1) + 0x3E)) = var_s3;
      *((s16 *) (((char *) temp_s1) + 0x40)) = (s16) sp10[4];
    }
  }
  else
  {
    temp_v1_4 = arg0->m5D;
    if (temp_v1_4 != 0)
    {
      if (temp_v1_4 == 3)
      {
        if (!(sp10[3] == 0))
        {
          var_s4 = (sp10[1] & 0x3F) & 0xFF;
          *((s32 *) (((char *) temp_s1) + 0x30)) = (s32) ((arg0->m2C) + (((sp10[1] >> 6) * 0x28) + 0x100));
          lo5b = (u8) (var_s4 & 0x1F);
          *((s16 *) (((char *) temp_s1) + 0x3A)) = 0;
          *((u8 *) (((char *) temp_s1) + 0x3F)) = var_s4;
          *((s16 *) (((char *) temp_s1) + 0x38)) = (s16) ((((u32) (((((u32) ((sp10[5] + lo5b) + 0x1F)) >> 5) + (var_s4 >> 5)) + 1)) >> 1) * 0x28);
          var_s4 = lo5b;
          *((s8 *) (((char *) temp_s1) + 0x3D)) = (s8) (((u32) ((var_s4 + sp10[5]) + 0x1F)) >> 5);
        }
        else
        {
          *((s32 *) (((char *) temp_s1) + 0x30)) = 0;
          *((s8 *) (((char *) temp_s1) + 0x3D)) = 0;
        }
        *((s32 *) (((char *) temp_s1) + 0x24)) = (s32) ((arg0->m2C) + inline_fn2(sp10));
        var_s3 = (inline_fn(sp10) & 0x3F) & 0xFF;
        *((s16 *) (((char *) temp_s1) + 0x2C)) = (s16) ((((u32) (((((u32) ((sp10[4] + (var_s3 & 0x1F)) + 0x1F)) >> 5) + (var_s3 >> 5)) + 1)) >> 1) * 0x28);
        *((s16 *) (((char *) temp_s1) + 0x2E)) = 0;
        *((s32 *) (((char *) temp_s1) + 0x40)) = (s32) (arg0->m2C);
        block_38:
        *((u8 *) (((char *) temp_s1) + 0x3E)) = var_s3;

        var_s3 = var_s3 & 0x1F;
        *((s8 *) (((char *) temp_s1) + 0x3C)) = (s8) (((u32) ((var_s3 + sp10[4]) + 0x1F)) >> 5);
      }
    }
    else
    {
      if (sp10[3] != 0)
      {
        *((s32 *) (((char *) temp_s1) + 0x30)) = (s32) ((arg0->m2C) + ((sp10[1] & 0xFFFC) * 2));
        var_s4 = (sp10[1] & 3) & 0xFF;
        *((s16 *) (((char *) temp_s1) + 0x3A)) = 0;
        *((s16 *) (((char *) temp_s1) + 0x38)) = (s16) ((((var_s4 + sp10[5]) + 3) & 0xFFFC) * 2);
        *((s16 *) (((char *) temp_s1) + 0x42)) = (s16) sp10[5];
        *((u8 *) (((char *) temp_s1) + 0x3F)) = var_s4;
      }
      else
      {
        *((s32 *) (((char *) temp_s1) + 0x30)) = 0;
        *((s16 *) (((char *) temp_s1) + 0x42)) = 0;
      }
      *((s32 *) (((char *) temp_s1) + 0x24)) = (s32) ((arg0->m2C) + ((inline_fn(sp10) & 0xFFFC) * 2));
      var_s3 = (inline_fn(sp10) & 3) & 0xFF;
      *((s16 *) (((char *) temp_s1) + 0x2E)) = 0;
      *((s16 *) (((char *) temp_s1) + 0x2C)) = (s16) ((((var_s3 + sp10[4]) + 3) & 0xFFFC) * 2);
      *((s8 *) (((char *) temp_s1) + 0x3C)) = 0;
      *((u8 *) (((char *) temp_s1) + 0x3E)) = var_s3;
      *((s16 *) (((char *) temp_s1) + 0x40)) = (s16) sp10[4];
    }
  }
  *((s16 *) (((char *) temp_s1) + 0x4E)) = var_s6;
  if (var_s5 == (-1))
  {
    *((s16 *) (((char *) temp_s1) + 0x48)) = 0x4000;
  }
  else
  {
    if (var_s5 == (-2))
    {
      *((s16 *) (((char *) temp_s1) + 0x48)) = (s16) (var_s3 + sp10[2]);
      var_v0_2 = (var_s3 + sp10[2]) - 0x20;
    }
    else
    {
      *((s16 *) (((char *) temp_s1) + 0x48)) = (s16) (var_s3 + sp10[2]);
      if ((*((s32 *) (((char *) temp_s1) + 0x30))) != 0)
      {
        var_v0_2 = (var_s4 + var_s5) | 0x8000;
      }
      else
      {
        var_v0_2 = var_s3 + var_s5;
      }
    }
    *((s16 *) (((char *) temp_s1) + 0x4A)) = var_v0_2;
  }
  arg0->m60 = arg2;
  func_80089890(arg0, 0xC0, &sp28);
  var_a0 = 0x2AAA0000;
  if ((arg0->m0) == 1)
  {
    temp_fv1 = (s32) (((f32) (arg0->m40)) * (arg0->m4C));
    arg0->m18 = (s16) temp_fv1;
    *((s32 *) (((char *) temp_s1) + 0)) = (s32) (temp_fv1 << 0x10);
    temp_fv1_2 = (s32) (((f32) (arg0->m42)) * (arg0->m4C));
    arg0->m1A = (s16) temp_fv1_2;
    *((s32 *) (((char *) temp_s1) + 4)) = (s32) (temp_fv1_2 << 0x10);
    temp_fv1_3 = (s32) (((f32) (arg0->m44)) * (arg0->m4C));
    arg0->m1C = (s16) temp_fv1_3;
    *((s32 *) (((char *) temp_s1) + 8)) = (s32) (temp_fv1_3 << 0x10);
    temp_fv1_4 = (s32) (((f32) (arg0->m46)) * (arg0->m4C));
    arg0->m1E = (s16) temp_fv1_4;
    *((s32 *) (((char *) temp_s1) + 0xC)) = (s32) (temp_fv1_4 << 0x10);
    *((s32 *) (((char *) temp_s1) + 0x1C)) = 0;
    *((s32 *) (((char *) temp_s1) + 0x18)) = 0;
    *((s32 *) (((char *) temp_s1) + 0x14)) = 0;
    *((s32 *) (((char *) temp_s1) + 0x10)) = 0;
  }
  else
  {
    *((s32 *) (((char *) temp_s1) + 0)) = (s32) ((arg0->m18) << 0x10);
    *((s32 *) (((char *) temp_s1) + 4)) = (s32) ((arg0->m1A) << 0x10);
    *((s32 *) (((char *) temp_s1) + 8)) = (s32) ((arg0->m1C) << 0x10);
    *((s32 *) (((char *) temp_s1) + 0xC)) = (s32) ((arg0->m1E) << 0x10);
    temp_fv1_5 = (s32) (((f32) (arg0->m40)) * (arg0->m4C));
    arg0->m18 = (s16) temp_fv1_5;
    var_a0 = 0x2AAAAAAB;
    *((s32 *) (((char *) temp_s1) + 0x10)) = (s32) (((temp_fv1_5 << 0x10) - (*((s32 *) (((char *) temp_s1) + 0)))) / 192);
    temp_fv1_6 = (s32) (((f32) (arg0->m42)) * (arg0->m4C));
    arg0->m1A = (s16) temp_fv1_6;
    *((s32 *) (((char *) temp_s1) + 0x14)) = (s32) (((temp_fv1_6 << 0x10) - (*((s32 *) (((char *) temp_s1) + 4)))) / 192);
    temp_fv1_7 = (s32) (((f32) (arg0->m44)) * (arg0->m4C));
    arg0->m1C = (s16) temp_fv1_7;
    *((s32 *) (((char *) temp_s1) + 0x18)) = (s32) (((temp_fv1_7 << 0x10) - (*((s32 *) (((char *) temp_s1) + 8)))) / 192);
    temp_fv1_8 = (s32) (((f32) (arg0->m46)) * (arg0->m4C));
    arg0->m1E = (s16) temp_fv1_8;
    *((s32 *) (((char *) temp_s1) + 0x1C)) = (s32) (((temp_fv1_8 << 0x10) - (*((s32 *) (((char *) temp_s1) + 0xC)))) / 192);
  }
  *((u16 *) (((char *) temp_s1) + 0x22)) = (u16) (arg0->m4);
  temp_fv1_9 = ((arg0->m8) - func_8008CD54(arg0->m8)) * D_800D6768;
  if (!(D_800D6770 <= temp_fv1_9))
  {
    var_a0_2 = (s32) temp_fv1_9;
    *((s16 *) (((char *) temp_s1) + 0x20)) = var_a0_2;
  }
  else
  {
    var_a0_2 = ((s32) (temp_fv1_9 - D_800D6770)) | 0x80000000;
    *((s16 *) (((char *) temp_s1) + 0x20)) = var_a0_2;
  }
  *((s32 *) (((char *) temp_s1) + 0x44)) = 0;
  *((s16 *) (((char *) temp_s1) + 0x4C)) = (s16) (var_a0_2 + (((arg0->m4) * 0x10) * sp10[4]));
  temp_v0 = ((*D_800E421C) * 0xA10) + D_800E4218;
  *temp_v0 += 1;
  advanceLoopPosition(arg0, 0xC0);
  arg0->m0 = sp28;
}

