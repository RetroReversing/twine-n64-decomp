s32 func_80011950();
s32 func_80081D50(s32 *, s32, int, void *);
s32 func_800828D8(s16);
volatile long long func_800828EC(s32);
s32 updateDemoPlayback();
s32 memset(s32 *, s32, s32);
extern s32 D_800C9D70;
extern s32 D_800C9DF8;
extern s32 D_800C9E80;
extern s32 D_800C9F08;
extern s32 D_800C9F90;
extern s32 D_800C9FC8;
extern s32 D_800CA068;
extern s32 D_800CA108;
extern s32 D_800CA1A8;
extern s32 D_800CA248;
extern s32 D_800CA278;
extern u8 D_800CEEB0;
extern s32 D_800E1A80;
extern u8 D_801002AE;
extern u16 D_801002BA;
extern s32 gBorderSkipFlag;
extern s32 D_8010A500;
extern s32 D_8010D430;
extern s32 D_8010D434;
extern s16 D_8010D436;
extern s32 D_8010D456;
extern s32 D_80112E98;
extern s32 D_80112E9C;
extern s32 D_80112EA0;
extern s32 D_80112EAC;
extern s32 D_80112EB0;
extern s32 D_80115091;
extern char D_80115094;
extern s32 D_80115108;
extern s32 D_8011510C;
extern s32 D_80115110;
extern s32 D_80115114;
extern s32 D_80115118;
extern s32 D_8011511C;
extern s32 D_80115120;
extern s32 D_80115124;
void func_800821B4(void)
{
  volatile u64 frame_pad;
  s32 sp2C;
  unsigned sp24;
  short sp16;
  s32 *var_a0_2;
  s16 *var_s2;
  s32 temp_s0;
  s32 temp_s0_2;
  int temp_s0_3;
  s32 temp_s0_4;
  int var_a0;
  s32 temp_a2;
  s32 temp_a3;
  s32 temp_s0_5;
  s32 temp_s0_6;
  register volatile unsigned char temp_s0_7;
  unsigned int temp_s0_8;
  long temp_t0;
  s32 temp_t1;
  u32 temp_t2;
  unsigned int temp_v0;
  s32 temp_v0_2;
  long var_a1;
  s32 var_a1_2;
  s32 var_s0;
  s32 var_s0_2;
  register s32 var_s0_3;
  int var_s0_4;
  short var_s0_5;
  s32 var_s1;
  s32 var_s4;
  s32 var_s7;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  register s32 var_s3_2;
  s32 var_s6;
  s32 var_s2_2;
  s32 var_t8;
  s32 temp_fp;
  register s32 temp_v1;
  void *temp_s1;
  register void *temp_s5;
  func_80011950();
  do
  {
    temp_v1 = D_800CEEB0;
    if (((s32) temp_v1) == 1)
    {
      func_80087A80();
    }
    if (D_800CEEB0 == 2)
    {
      updateDemoPlayback();
    }
    var_s2 = &D_8010D436; var_s4 = 0; var_a0_2 = &D_8011510C; var_s1 = 0;
    do
    {
      {
        temp_s0 = *((&(*((s32 *) 0x8010d436))) + var_s4);
        if (temp_s0 >= 0)
        {
          if (D_801002BA)
          {
            var_s0 = temp_s0 - 4; var_v0 = ((s32) (~var_s0)) >> 0x1F;
          }
          else
          {
            var_s0 = temp_s0 - 4; var_v0 = (((s32) (~var_s0)) >> 9) >> 22;
          }
        }
        else
        {
          var_s0 = temp_s0 + 4; var_v0 = -(var_s0 < 1);
        }
        temp_a3 = (var_s0 & var_v0) << 0x10; var_s0_2 = temp_a3 / 76;
        if ((-0x10000) > var_s0_2)
        {
          var_s0_2 = -0x10000;
        }
        else
          if (var_s0_2 > 0x10000)
        {
          var_s0_2 = 0x10000;
        }
        *((&(*((s32 *) 0x8011510c))) + var_s1) = var_s0_2;
        *((&D_80115110) + ((int) var_s1)) = var_s0_2 - (*((&D_80115108) + var_s1)); var_s0_2 = (s16) (*((&D_8010D434) + var_s4)); temp_v0 = func_800828EC(var_s0_2 & (-((func_800828D8((s32) var_s0_2) + 1) > 0x21)));
        if (temp_v0 != (*((&D_80115120) + ((s32) var_s1))))
        {
          *((&D_80115120) + var_s1) = temp_v0;
          *((&D_80115118) + var_s1) = temp_v0;
        }
        else
        {
          *((&D_80115118) + var_s1) = 0;
        }
        temp_s0_3 = *var_s2;
        if ((temp_s0_3 + 1) >= (0 + 1))
        {
          var_s0_3 = temp_s0_3 - 4; var_v0_2 = ((s32) (~var_s0_3)) >> 0x1F;
        }
        else
        {
          var_s0_3 = temp_s0_3 + 4; var_v0_2 = -(1 > var_s0_3);
        }
        var_s0_4 = (((var_s0_3 & var_v0_2) << 9) << 7) / 76;
        if (var_s0_4 < (-0x10000))
        {
          var_s0_4 = -0x10000;
        }
        else
          if (var_s0_4 > 0x10000)
        {
          var_s0_4 = 0x10000;
        }
        *((&D_80115114) + var_s1) = var_s0_4 - (*var_a0_2);
        *var_a0_2 = var_s0_4; var_s0_4 = (s16) (*var_s2);
        temp_v0_2 = func_800828EC(var_s0_4 & (-(func_800828D8(var_s0_4) >= ((int) 0x21))));
        var_s2 += 4;
        if (temp_v0_2 != (*((&D_80115124) + var_s1)))
        {
          *((&D_80115124) + var_s1) = temp_v0_2;
          *((&D_8011511C) + var_s1) = temp_v0_2;
        }
        else
        {
          *((&D_8011511C) + var_s1) = 0;
        }
        var_s4 += 8; var_a0_2 += 40; var_s1 += 0xA0;
      }
    }
    while ((((s32) var_s2) + 1) < (((s32) (&D_8010D456)) + 1));
    var_t8 = 4;
    if (gBorderSkipFlag != 0)
    {
      var_t8 = D_801002BA;
    }
  }
  while (0);
  sp16 = var_t8;
  if ((var_t8 << 0x10) > 0)
  {
    s32 __block_sp2C;
    s32 __block_var_s7;
    s32 __block_var_s6;
    __block_var_s6 = 0;
    sp24 = 0;
    __block_sp2C = 0;
    do
    {
      memset(&D_80112E98, 0, 0x24);
      temp_s5 = *((void **) (((u8 *) (&D_8010A500)) + sp24));
      temp_fp = *(((u8 *) (&D_80115091)) + (__block_var_s6 * 0xA0));
      var_a1 = 1;
      if (temp_s5 != NULL)
      {
        var_s3_2 = *((s8 *) (((char *) (*((void **) (((char *) temp_s5) + 0x6C)))) + 0x183));
        var_s2_2 = *((u16 *) (((u8 *) (&D_8010D430)) + (var_s3_2 * 8)));
        var_a0 = ((s16 *) (&D_800E1A80))[var_s3_2];
        temp_a2 = var_s2_2 & 0x2000;
        temp_a3 = var_s2_2 & 0x4000;
        temp_t2 = -(temp_a3 != 0);
        temp_t0 = var_s2_2 & 0x8000;
        temp_t1 = -(temp_t0 != 0);
        var_v0_3 = var_a0 & 7;
        do
        {
          {
            long long phantom_wide = sp2C;
          }
          switch (var_v0_3)
          {
            default:
              if (temp_a2 != 0)
            {
              var_a0 = 1;
            }
            else
              if (temp_a3 != 0)
            {
              var_a0 = 2;
            }
            else
              if (temp_t0 != 0)
            {
              var_a0 = 3;
            }
            else
            {
              block_75:
              var_a1 = 0;

            }
              break;

            case 1:
              if (temp_a2)
            {
              D_80112E9C = 1;
              var_a1 = 0;
              if (((u32) temp_a3) != 0)
              {
                D_80112EA0 = 1;
              }
            }
            else
            {
              var_a0 = 0;
            }
              break;

            case 2:
              if (temp_a3)
            {
              if (temp_a2 != 0)
              {
                D_80112EAC = 1;
                var_a0 = 4;
              }
              else
                if (temp_t0 != 0)
              {
                *((s32 *) (((char *) (&D_80112EB0)) + 0)) = 1;
                var_a0 = 5;
              }
              else
              {
                goto block_75;
              }
            }
            else
              if (!(var_a0 & 8))
            {
              *((&D_80112EB0) - 0x10) = 1;
              block_65:
              var_a0 = 0;

            }
            else
            {
              var_a0 = 0;
            }
              if (var_s2_2 || temp_a3)
            {
              break;
            }
            else
            {
              break;
            }

            case 3:
              if (temp_t0)
            {
              if (((u32) temp_a2) != 0)
              {
                *((&D_80112EB0) - 0xC) = 1;
                var_a0 = 6;
              }
              else
                if (temp_a3 != 0)
              {
                *((s32 *) (((char *) (&D_80112EB0)) + 4)) = 1;
                var_a0 = 7;
              }
              else
              {
                goto block_75;
              }
            }
            else
            {
              if (!(var_a0 & 8))
              {
                *((&D_80112EB0) - 8) = 1;
              }
              goto block_65;
            }
              break;

            case 4:
              if (temp_a2 == 0)
            {
              var_a0 = temp_t2 & 0xA;
            }
            else
            {
              goto block_75;
            }
              break;

            case 5:
              if (temp_t0 == 0)
            {
              var_a0 = temp_t2 & 0xA;
            }
            else
            {
              goto block_75;
            }
              break;

            case 6:
              if (temp_a2 == 0)
            {
              var_a0 = temp_t1 & 0xB;
            }
            else
            {
              goto block_75;
            }
              break;

            case 7:
              if (temp_a3 == 0)
            {
              var_a0 = temp_t1 & 0xB;
            }
            else
            {
              goto block_75;
            }
              break;

          }

          var_v0_3 = var_a0 & 7;
        }
        while (var_a1 != 0);
        ((s16 *) (&D_800E1A80))[var_s3_2] = var_a0;
      }
      else
      {
        var_s3_2 = __block_var_s6;
        var_s2_2 = *((u16 *) (((u8 *) (&D_8010D430)) + __block_sp2C));
      }
      temp_s1 = (__block_var_s6 * 0xA0) + (&D_80115094);
      var_s0_5 = var_s3_2 & 0xFF;
      func_80081D50(&D_800CA278, var_s0_5, var_s2_2, temp_s1);
      if ((temp_s5 != NULL) && (D_801002AE == 0))
      {
        switch (temp_fp)
        {
          case 0:
            temp_s0_5 = var_s3_2 & 0xFF;
            var_a0_2 = &D_800C9F90;
            var_a1_2 = (s32) temp_s0_5;
            func_80081D50(&D_800C9D70, temp_s0_5, var_s2_2, temp_s1);
            break;

          case 1:
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            ;
            func_80081D50(&D_800C9DF8, var_s3_2 & 0xFF, var_s2_2, temp_s1);
            var_a0_2 = &D_800C9F90;
            var_a1_2 = temp_s0_6;
            break;

          case 2:
            var_a0_2 = &D_800C9FC8;
            var_s0_5 = var_s3_2 & 0xFF;
            func_80081D50(var_a0_2, var_s0_5, var_s2_2, temp_s1);
            var_a0_2 = &D_800CA248;
            var_a1_2 = var_s0_5;
            break;

          case 3:
            var_a0_2 = &D_800CA068;
            var_s0_5 = var_s3_2 & 0xFF;
            func_80081D50(var_a0_2, var_s3_2 & 0xFF, var_s2_2, temp_s1);
            var_a0_2 = &D_800CA248;
            var_a1_2 = var_s0_5;
            break;

          case 4:
            temp_s0_7 = var_s3_2 & 0xFF;
            var_a1_2 = temp_s0_7;
            func_80081D50(&D_800C9E80, temp_s0_7, var_s2_2, temp_s1);
            var_a0_2 = &D_800C9F90;
            break;

          case 5:
            temp_s0_8 = var_s3_2 & 0xFF;
            func_80081D50(&D_800C9F08, temp_s0_8, var_s2_2, temp_s1);
            var_a0_2 = &D_800C9F90;
            var_a1_2 = temp_s0_8;
            break;

          case 6:
            var_a0_2 = &D_800CA108;
            var_s0_5 = var_s3_2 & 0xFF;
            func_80081D50(var_a0_2, var_s0_5, var_s2_2, temp_s1);
            var_a0_2 = &D_800CA248;
            var_a1_2 = var_s0_5;
            break;

          default:
            var_a0_2 = &D_800CA1A8;
            func_80081D50(var_a0_2, var_s0_5, var_s2_2, temp_s1);
            var_a0_2 = &D_800CA248;
            var_a1_2 = var_s0_5;
            break;

        }

        func_80081D50(var_a0_2, var_a1_2, var_s2_2, temp_s1);
      }
      sp24 += 4;
      __block_sp2C += 8;
      __block_var_s6 += 1;
    }
    while (__block_var_s6 < ((s16) sp16));
  }
}

