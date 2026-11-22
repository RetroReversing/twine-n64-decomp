#define FLD(p, t, o) (*(t *)((u8 *)(p) + (o)))
extern u8 D_54D910[];
extern u8 D_800C0784[];
extern s8 D_80109A94;
void func_8000B9B8(u8 *, s32, u32);
void func_800134C0(void);
void func_800134C8(void);
s32 func_8001499C(s32 *);
s32 func_800149D4(void *);
s32 func_80014A0C(s32 *, s32 *);
s32 func_800328B8(void *, s32 *);
s32 func_800336FC(s32 *, s32 *, s32 *, s32 *, s32, f32, s32, s32, s32, s32 *, s32 *);
s32 *func_80083E90(s32, s32);
s32 func_80084048(s32 *, s32);
inline static s32 inline_fn(u8 *arg0)
{
  return func_800149D4(arg0);
}

void func_80043FA0(void *arg0)
{
  u8 sp30[0x20];
  u8 sp50[0x20];
  s32 sp70;
  s32 sp74;
  s32 *recordEnd;
  s32 *sp7C;
  s32 *sp84;
  s32 *sp8C;
  f32 var_fs0;
  union 
  {
    s32 *pointer;
    s32 value;
  } __repair_phase_storage;
  s32 *temp_s1;
  s32 *temp_s2;
  s32 *temp_s6;
  s32 *temp_t0;
  s32 *temp_v0_3;
  s32 *temp_v0_7;
  s32 *temp_v0_9;
  s32 *var_fp;
  s32 *var_s2;
  s32 *var_s3;
  s32 *var_s5;
  s32 *var_s7;
  s32 temp_s6_2;
  s32 temp_v0_2;
  s32 temp_v0;
  s32 temp_v0_4;
  s32 temp_v0_6;
  u8 *temp_v0_8;
  do
  {
    var_s5 = NULL;
    if (arg0 != NULL)
    {
      var_s7 = NULL; sp7C = NULL; var_fs0 = 1.0f;
      if ((*((u8 *) (((u8 *) arg0) + 0x48))) & 0x10)
      {
        var_fs0 = 64.0f;
      }
      func_800134C0();
      func_8000B9B8(sp30, D_54D910 + (*((s32 *) (((u8 *) arg0) + 4))), 0x20);
      sp8C = *((s32 **) (((u8 *) arg0) + 0x34));
      if (sp8C != ((u32) NULL))
      {
        goto block_10;
      }
      var_s5 = func_80083E90((*((u16 *) (((u8 *) sp30) + 4))) * 0x18, 0x2D);
      if (var_s5 != NULL)
      {
        recordEnd = (s32 *) (((u8 *) var_s5) + ((*((u16 *) (((u8 *) sp30) + 4))) * 0xC));
        func_8000B9B8(sp50, D_54D910 + (*((s32 *) (((u8 *) sp30) + 0))), 0x20);
        temp_v0 = func_800149D4(sp50);
        if (temp_v0 == 0)
        {
          sp8C = var_s5;
          func_8000B9B8(var_s5, D_54D910 + (*((s32 *) (((u8 *) sp30) + 0))), (*((u16 *) (((u8 *) sp30) + 4))) * 0xC);
        }
        else
        {
          func_8000B9B8(var_s5, D_54D910 + (*((s32 *) (((u8 *) sp30) + 0))), temp_v0);
          sp8C = recordEnd;
          do
          {
            func_8001499C(var_s5);
          }
          while (0);
          func_80014A0C(recordEnd, var_s5);
        }
        block_10:
        temp_v0_3 = func_80083E90(((u32) (((*((u16 *) (((u8 *) sp30) + 0x14))) * 8) + (temp_v0_2 = (*((u16 *) (((u8 *) sp30) + 0x0C))) * 4))) + ((*((u16 *) (((u8 *) sp30) + 0x1C))) + temp_v0_2), 0x2D);

        if (temp_v0_3 != NULL)
        {
          var_s7 = temp_v0_3; temp_t0 = &var_s7[*((u16 *) (((u8 *) sp30) + 0x14))]; temp_s1 = &temp_t0[*((u16 *) (((u8 *) sp30) + 0x14))]; temp_s2 = &temp_s1[*((u16 *) (((u8 *) sp30) + 0x0C))]; temp_s6 = &temp_s2[*((u16 *) (((u8 *) sp30) + 0x0C))]; sp84 = temp_t0;
          func_8000B9B8(sp50, D_54D910 + (*((s32 *) (((u8 *) sp30) + 8))), 0x20);
          temp_v0_4 = func_800149D4(sp50);
          if (temp_v0_4 == 0)
          {
            func_8000B9B8(temp_s1, D_54D910 + (*((s32 *) (((u8 *) sp30) + 8))), (*((u16 *) (((u8 *) sp30) + 0x0C))) * 4);
            var_fp = temp_s1;
          }
          else
          {

            func_8000B9B8(temp_s1, D_54D910 + (*((s32 *) (((u8 *) sp30) + 8))), temp_v0_4);
            func_8001499C(temp_s1);
            func_80014A0C(temp_s2, temp_s1);
            var_fp = temp_s2;
          }
          func_8000B9B8(sp50, D_54D910 + (*((s32 *) (((u8 *) sp30) + 0x10))), 0x20);
          temp_v0 = inline_fn(sp50);
          if (temp_v0 == 0)
          {
            func_8000B9B8(var_s7, D_54D910 + (*((s32 *) (((u8 *) sp30) + 0x10))), (*((u16 *) (((u8 *) sp30) + 0x14))) * 4);
            var_s3 = var_s7;
          }
          else
          {
            func_8000B9B8(var_s7, D_54D910 + (*((s32 *) (((u8 *) sp30) + 0x10))), temp_v0);
            func_8001499C(var_s7);
            var_s3 = sp84;
            func_80014A0C(var_s3, var_s7);
          }
          func_8000B9B8(sp50, D_54D910 + (*((s32 *) (((u8 *) sp30) + 0x18))), 0x20);
          temp_v0 = inline_fn(sp50);
          if (temp_v0 == 0)
          {
            func_8000B9B8(temp_s6, D_54D910 + FLD(sp30, s32, 0x18), FLD(sp30, u16, 0x1C));
            var_s2 = temp_s6;
            goto block_21;
          }
          func_8000B9B8(temp_s6, D_54D910 + (*((s32 *) (((u8 *) sp30) + 0x18))), temp_v0);
          temp_v0_7 = func_80083E90(func_8001499C(temp_s6), 0x2D); sp7C = temp_v0_7;
          if (temp_v0_7 != NULL)
          {
            func_80014A0C(sp7C, temp_s6);
            var_s2 = sp7C;
            block_21:
            temp_v0_8 = *((u8 **) (D_800C0784 + ((*((u16 *) (((u8 *) arg0) + 0x30))) & 0xFFF0)));

            sp70 = 0; sp74 = 0; temp_s6_2 = *((s32 *) (((u8 *) temp_v0_8) + 0x10)); __repair_phase_storage.value = *((s32 *) (((u8 *) temp_v0_8) + 0x18));
            func_800336FC(var_s2, sp8C, var_fp, var_s3, *((u8 *) (((u8 *) arg0) + 0x45)), var_fs0, __repair_phase_storage.value, temp_s6_2, 0, &sp70, &sp74);
            temp_v0_9 = func_80083E90((sp70 * 0x10) + (sp74 * 8), 0x2E);
            if (temp_v0_9 != NULL)
            {
              func_800328B8(((u8 *) temp_v0_9) + (sp74 * 8), temp_v0_9);
              *((s32 **) (((u8 *) arg0) + 0)) = temp_v0_9;
              func_800336FC(var_s2, sp8C, var_fp, var_s3, *((u8 *) (((u8 *) arg0) + 0x45)), var_fs0, __repair_phase_storage.value, temp_s6_2, 1, NULL, NULL);
              if (D_80109A94 != 0)
              {
                *((u8 *) (((u8 *) arg0) + 0x46)) |= 0x80;
              }
            }
            goto block_24;
          }
        }
        else
        {
          goto block_24;
        }
      }
      else
      {
        block_24:
        if (sp7C != NULL)
        {
          func_80084048(sp7C, 0x2D);
        }

      }
      if ((*((s32 **) (((u8 *) arg0) + 0x34))) == NULL)
      {
        do
        {
          func_80084048(var_s5, 0x2D);
        }
        while (0);
      }
      if (var_s7 != NULL)
      {
        func_80084048(var_s7, 0x2D);
      }
      func_800134C8();
    }
  }
  while (0);
}


