s32 actorFinishIfMatch(void *, s32);
s32 actorUpdateGatedState(void *, s32);
f32 approxDistance(void *, void *);
f32 approximateAtan2(f32, f32);
s32 func_80002BD0(void *, s32);
s32 func_80002EF0(void *);
s32 func_800158A4(s32, void *, s32, s32 *, s32, s32, s32, s32, s32);
f32 func_800461D4(void *, void *);
s32 func_80065D90(void *);
s32 func_80067E94(void *);
s32 func_8006899C(void *, s8);
s32 func_8006CD34(void *);
s32 func_8006E648(s32, void *, s32, s32 *, s32 *, void **, s32 *, s32 *);
s32 func_80070730(void *, s32, s32);
s32 func_80070F34(void *);
s32 func_8007A9CC(void *, s32, s32 *, f32);
s32 func_8007AB18(void *, void *, f32);
s32 func_800843CC(void *, s32, s32);
s32 func_800848EC(void *, s32, s32);
s32 func_80084CD8(void *, s32, s32);
s32 func_80117EC8(void *, s32);
s32 func_80117ED0(void *, void *, void *);
void *func_801183F4(void *, s32);
s32 func_80118AE8(void *);
void *func_8011B3D8(s32);
s32 getSaveSlotIndex(s32);
u32 randomIntBelow(s32);
s32 refreshSaveSlotSelection(void *);
s32 updateSwayMotion(void *);
extern u8 D_800BF688;
extern u8 D_800BF68B;
extern u8 D_800C7DAC[];
extern u8 D_801002D5;
extern void *D_80108F84;
extern s32 D_8011EF30;
extern f64 D_8011EF78;
extern u16 D_8011F060[];
extern void *gPlayerActor;
extern s32 gSaveSlotInfo;
extern u8 gSceneType;
extern u8 sProbeActive;
extern s32 sTrackMarkerTable;
inline static char *inline_fn(char *arg0)
{
  return arg0 + 0x84;
}

inline static s32 inline_fn2(int arg0)
{
  return (s32) arg0;
}

inline static long inline_fn23(long arg0)
{
  return arg0 << 0x18;
}

inline static int inline_fn234(int arg0)
{
  return arg0;
}

void func_80118BCC(void *arg0)
{
  s32 sp38;
  u8 sp28[0x10];
  s32 sp3C;
  int sp40;
  register void *sp44;
  s32 sp48;
  s32 sp4C;
  struct Coefficients
  {
    f32 values[6];
  } coefficients;
  s32 var_a1;
  s32 var_a1_2;
  unsigned var_a1_3;
  unsigned int var_a2;
  s32 var_a2_2;
  s32 var_s0;
  f32 temp_a2;
  f32 temp_fa1;
  f32 temp_ft1;
  f32 temp_fv0;
  f32 temp_fv0_2;
  register f32 temp_fv0_3;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  f32 temp_fv1_4;
  f32 temp_fv1_5;
  f32 var_fa0;
  f32 var_fs0;
  f32 var_fv0;
  f32 var_fv1;
  f64 var_ft0;
  s32 temp_v1_13;
  s32 temp_v1_3;
  s32 temp_v1_6;
  u32 temp_v1_7;
  s32 temp_v1_8;
  unsigned temp_a3;
  u32 temp_s5;
  s32 temp_v0;
  s32 temp_v1;
  s32 temp_v1_10;
  s32 temp_v1_2;
  s32 var_s0_2;
  
  long var_s3;
  
  int temp_v0_5;
  char var_s3_2;
  u16 *temp_v0_6;
  s32 temp_v1_4;
  long temp_v1_5;
  u32 var_a0;
  s32 temp_s4;
  s32 temp_v1_9;
  void *temp_a1;
  void *temp_a1_2;
  void *temp_a1_3;
  void *temp_a1_4;
  void *temp_s0;
  void *temp_s0_2;
  void *temp_s2;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v1_11;
  temp_s2 = *((void **) (((char *) arg0) + 0x6C));
  temp_s5 = *((s32 *) (((char *) arg0) + 0x20));
  temp_v1 = *((s32 *) (((u8 *) (&gSaveSlotInfo)) + ((getSaveSlotIndex((u16) (((s32) ((*((volatile u8 *) (((char *) temp_s2) + 0x182))) << 24)) >> 24)) & 0xFFFF) * 0x18)));
  temp_fv1 = *((f32 *) (((char *) arg0) + 0x74));
  temp_v1_2 = ((s32)((u32)temp_v1 << 16) >> 16) * 0xC;
  temp_s4 = *((&D_800BF68B) + temp_v1_2);
  temp_v0 = temp_s4 & 0x10;
  if (temp_fv1 > 0.0f)
  {
    if (temp_v0)
    {
      temp_fv0 = temp_fv1 + 0.5f;
      *((f32 *) (((char *) arg0) + 0x74)) = temp_fv0;
      temp_fv1_2 = (f32) ((*((&D_800BF688) + temp_v1_2)) * 5);
      if (temp_fv0 > temp_fv1_2)
      {
        *((f32 *) (((char *) arg0) + 0x74)) = temp_fv1_2;
      }
    }
  }
  *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x34)) = 0;
  temp_v1_3 = *((s16 *) (((char *) arg0) + 0x7A));
  switch (temp_v1_3)
  {
    case 0:

    case 1:

    case 7:
      *((void **) (((char *) temp_s2) + 0xC0)) = func_801183F4(arg0, 1);
      break;

    case 2:
      temp_a1 = *((void **) (((char *) temp_s2) + 0xC0));
      if (temp_a1 == NULL)
    {
      *((void **) (((char *) temp_s2) + 0xC0)) = func_801183F4(arg0, 1);
    }
    else
    {
      temp_v1_4 = *((u16 *) (((char *) temp_a1) + 0x78));
      var_s0 = 1;
      if ((((temp_v1_4 == 0x55) | (temp_v1_4 == 0x28)) != 0) && (func_800461D4(arg0 + 0x24, temp_a1 + 0x24) > 2.0f))
      {
        var_s0 = 0;
      }
      *((void **) (((char *) temp_s2) + 0xC0)) = func_801183F4(arg0, var_s0);
    }
      break;

    default:
      break;

  }

  temp_a1_2 = *((void **) (((char *) temp_s2) + 0xC0));
  var_s3 = 0;
  if ((temp_a1_2 != NULL) && ((*((s16 *) (((char *) arg0) + 0x7A))) != 6))
  {
    temp_v1_5 = *((u16 *) (((char *) temp_a1_2) + 0x78));
    switch (temp_v1_5)
    {
      case 0x4D:

      case 0x61:
        *((s16 *) (((char *) arg0) + 0x7A)) = 2;
        *((void **) (((char *) temp_s2) + 0xC0)) = func_801183F4(arg0, 1);
        break;

      case 0x29:
        var_fv0 = func_800461D4(arg0 + 0x24, temp_a1_2 + 0x24);
        var_fv1 = 1.0f;
        block_33:
      if (var_fv0 < var_fv1)
      {
        *((s16 *) (((char *) arg0) + 0x7A)) = 7;
      }

        break;

      case 0x45:
        if (gSceneType == 3)
      {
        temp_v1_6 = *((s16 *) (((char *) temp_a1_2) + 0x7A));
        if ((temp_v1_6 == (*((u8 *) (((char *) (*((void **) (((char *) temp_s2) + 0xB4)))) + 0x12)))) && ((*((&sProbeActive) + temp_v1_6)) == 0))
        {
          if (func_800461D4(arg0 + 0x24, temp_a1_2 + 0x24) < 2.0f)
          {
            *((s16 *) (((char *) arg0) + 0x7A)) = 7;
          }
        }
      }
        break;

    }

  }
  func_8006CD34(arg0);
  temp_a1_3 = *((void **) (((char *) temp_s2) + 0xC0));
  if (temp_a1_3 != NULL)
  {
    temp_s0 = arg0 + 0x24;
    if (((u32) ((*((u16 *) (((char *) temp_a1_3) + 0x78))) - 2)) < 2U)
    {
      temp_fv0_2 = approxDistance(temp_s0, temp_a1_3 + 0x24);
      if (((temp_fv0_2 < 25.0f) && (((temp_fv0_2 < 6.0f) || (temp_s4 & 1)) || ((func_8007A9CC(arg0, temp_s0, &sp38, 1137.77783203125f) << 0x18) != 0))) && (inline_fn23(func_800158A4((*((s32 *) (((u8 *) (&sTrackMarkerTable)) + (((s8) (*((u8 *) (((char *) temp_s2) + 0x182)))) * 4)))) + 0x10, (*((void **) (((char *) temp_s2) + 0xC0))) + 0x24, *((s32 *) (((char *) arg0) + 0x20)), sp28, 0, 0, 0x20000, 1, 0)) != 0))
      {
        var_s3 = 1;
      }
    }
    func_80065D90(arg0);
    temp_v1_7 = *((s16 *) (((char *) arg0) + 0x7A));
    {
      switch (temp_v1_7)
      {
        case 0:
          var_a1_2 = 1;
          D_8011F060[(s8) (*((u8 *) (((char *) temp_s2) + 0x182)))] = 0;
          func_80117EC8(arg0, var_a1_2);
          *((s32 *) (((char *) temp_s2) + 0xA4)) = 0;
          break;

        case 2:
          if ((inline_fn23(var_s3) != 0) && (func_800461D4(arg0 + 0x24, (*((void **) (((char *) temp_s2) + 0xC0))) + 0x24) < 6.0f))
        {
          var_a1_2 = 8;
          func_80117EC8(arg0, var_a1_2);
          break;
        }
          func_80118AE8(arg0);
          break;

        case 8:
          D_8011F060[(s8) (*((u8 *) (((char *) temp_s2) + 0x182)))] = 0;
          if (((randomIntBelow(0x64) + 1) <= 0x21U) || (((((u16) (*((u16 *) (((char *) (((*((s32 *) (((u8 *) (&gSaveSlotInfo)) + ((getSaveSlotIndex((u16) (inline_fn2((*((volatile u8 *) (((char *) temp_s2) + 0x182))) << 24) >> 24)) & 0xFFFF) * 0x18)))) * 0xC) + 0x800C0000)) + (-0x978))))) >> 2) & 7) < 2))
        {
          var_a1_2 = 3;
        }
        else
        {
          long long phantom_wide = sp38;
          var_a1_2 = 9;
          if (randomIntBelow(0x64) < 0x32U)
          {
            {
            }
          }
          else
          {
            var_a1_2 = 10;
          }
        }
          func_80117EC8(arg0, var_a1_2);
          break;

        case 3:
          if (((u16) D_8011F060[(s8) (*((u8 *) (((char *) temp_s2) + 0x182)))]) >= 0x79U)
        {
          var_a1_2 = 8;
          func_80117EC8(arg0, var_a1_2);
          break;
        }
          if ((var_s3 << 0x18) != 0)
        {
          var_a1_2 = 2;
          if ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) != 0)
          {
            func_80002BD0(arg0, 0x14D);
            func_8007AB18(arg0, (*((void **) (((char *) temp_s2) + 0xC0))) + 0x24, 0.2f);
          }
          else
          {
            func_80117EC8(arg0, var_a1_2);
            break;
          }
        }
        else
        {
          block_84:
          var_a1_2 = 2;

          func_80117EC8(arg0, var_a1_2);
          break;
        }
          break;

        case 9:

        case 10:
          if (((u16) D_8011F060[(s8) (*((u8 *) (((char *) temp_s2) + 0x182)))]) >= 0x79U)
        {
          do
          {
            do
            {
              var_a1_2 = 8;
              func_80117EC8(arg0, var_a1_2);
              break;
            }
            while (0);
          }
          while (0);
        }
          if ((var_s3 << 0x18) != 0)
        {
          var_a1_2 = 2;
          if ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) != 0)
          {
            *((f32 *) inline_fn((char *) temp_s2)) = (f32) (func_800461D4(arg0 + 0x24, (*((void **) (((char *) temp_s2) + 0xC0))) + 0x24) - 1.5f);
            func_80117ED0(arg0, (*((void **) (((char *) temp_s2) + 0xC0))) + 0x24, inline_fn(temp_s2));
          }
          else
          {
            func_80117EC8(arg0, var_a1_2);
            break;
          }
        }
        else
        {
          {
            var_a1_2 = 2;
            func_80117EC8(arg0, var_a1_2);
            break;
          }
        }
          break;

        case 4:
          temp_s0_2 = arg0 + 0x24;
          if ((var_s3 << 0x18) != 0)
        {
          struct Position
          {
            f32 x;
            f32 y;
            f32 z;
          };
          temp_v0_2 = *((void **) (((char *) temp_s2) + 0xC0));
          do
          {
            *((struct Position *) (((char *) temp_s2) + 0x104)) = *((struct Position *) (((char *) temp_v0_2) + 0x24));
            *((f32 *) inline_fn((char *) temp_s2)) = (f32) (func_800461D4(temp_s0_2, temp_s2 + 0x104) - 1.5f);
            if (func_800461D4(temp_s0_2, (*((void **) (((char *) temp_s2) + 0xC0))) + 0x24) < 6.0f)
            {
              var_a1_2 = 8;
              func_80117EC8(arg0, var_a1_2);
              break;
            }
          }
          while (0);
        }
          if ((*((f32 *) inline_fn((char *) temp_s2))) > 0.0f)
        {
          func_80117ED0(arg0, temp_s2 + 0x104, inline_fn(temp_s2));
        }
        else
        {
          var_a1_2 = 5;
          func_80117EC8(arg0, var_a1_2);
          break;
        }
          break;

        case 5:
          if ((var_s3 << 0x18) != 0)
        {
          var_a1_2 = 8;
          if (func_800461D4(arg0 + 0x24, (*((void **) (((char *) temp_s2) + 0xC0))) + 0x24) < 6.0f)
          {
          }
          else
          {
            goto block_83;
          }
          do
          {
            func_80117EC8(arg0, var_a1_2);
            break;
          }
          while (0);
        }
          if ((*((f32 *) (((char *) temp_s2) + 0x88))) > 0.0f)
        {
          func_80117ED0(arg0, temp_s2 + 0x110, temp_s2 + 0x88);
        }
        else
        {
          case 1:
            block_83:
          {
            var_a1_2 = 2;
            func_80117EC8(arg0, var_a1_2);
            break;
          }


        }
          break;

        case 6:
          if ((*((u8 *) (((char *) temp_s2) + 0x5A8))) == 3)
        {
          actorUpdateGatedState(arg0, 3);
        }
          break;

        case 7:
          func_80117ED0(arg0, (*((void **) (((char *) temp_s2) + 0xC0))) + 0x24, inline_fn(temp_s2));
          if ((gSceneType == 3) && ((*((&sProbeActive) + (*((u8 *) (((char *) (*((void **) (((char *) temp_s2) + 0xB4)))) + 0x12))))) == 1))
        {
          func_80117EC8(arg0, 2);
        }
          if ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) == 0)
        {
          goto block_83;
        }
          break;

      }

    }
    func_80002EF0(arg0);
    sp40 = 0;
    sp44 = NULL;
    sp4C = 0;
    sp3C = 0;
    sp48 = 0;
    *((s16 *) (((char *) arg0) + 0x7C)) = 0;
    func_8006E648(temp_s5, arg0, 0x10, &sp3C, &sp40, &sp44, &sp48, &sp4C);
    if ((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 0x10)
    {
      temp_v1_8 = *((s16 *) (((char *) arg0) + 0x7A));
      if (temp_v1_8 == 9)
      {
        D_8011F060[(s8) (*((u8 *) (((char *) temp_s2) + 0x182)))] = 0;
        if (randomIntBelow(0x64) < 0x42U)
        {
          var_a1_3 = 0xA;
        
        func_80117EC8(arg0, var_a1_3);}
        else
        {
          var_a1_3 = 3;
        
        func_80117EC8(arg0, var_a1_3);}
      }
      else
        if (temp_v1_8 == 0xA)
      {
        D_8011F060[(s8) (*((u8 *) (((char *) temp_s2) + 0x182)))] = 0;
        if (randomIntBelow(0x64) < 0x42U)
        {
          var_a1_3 = 9;
        }
        else
          if (1)
        {
          var_a1_3 = 3;
        }
        func_80117EC8(arg0, var_a1_3);
      }
    }
    if ((sp44 != NULL) && ((*((u16 *) (((char *) sp44) + 0x78))) == 0xB))
    {
      temp_v1_9 = *((u8 *) (((char *) (*((void **) (((char *) sp44) + 0x6C)))) + 0x4A));
      if (((((s32) temp_v1_9) >= 4) && ((((s32) temp_v1_9) < 6) || ((inline_fn2((s32) temp_v1_9) < 0xE) && (((s32) temp_v1_9) >= 0xA)))) && ((*((s16 *) (((char *) sp44) + 0x7A))) == 0))
      {
        if ((*((s32 *) (((char *) sp44) + 0x20))) == (*((s32 *) (((char *) arg0) + 0x20))))
        {
          *((s32 *) (((char *) sp44) + 0x60)) = (*((s32 *) (((char *) sp44) + 0x60))) | 8;
        }
        else
        {
          *((s32 *) (((char *) sp44) + 0x60)) = (*((s32 *) (((char *) sp44) + 0x60))) & (~8);
        }
        *((s32 *) (((char *) sp44) + 0x60)) = inline_fn2((*((s32 *) (((char *) sp44) + 0x60))) | 0x100800);
      }
    }
    *((s32 *) (((char *) arg0) + 0x58)) = inline_fn2((*((s32 *) (((char *) arg0) + 0x58))) | 1);
    if (((*((u8 *) 0x801002A1)) != 0) && (D_801002D5 == 0))
    {
      temp_v0_3 = func_8011B3D8(*((s32 *) (((char *) temp_s2) + 0x1B8)));
      if ((temp_v0_3 != NULL) && (((*((u8 *) (((char *) (*((void **) (((char *) temp_s2) + 0xB4)))) + 0x12))) == (*((u8 *) (((char *) (*((void **) (((char *) temp_v0_3) + 0xB4)))) + 0x12)))) & (((s32) temp_s2) != ((s32) temp_v0_3))))
      {
        *((s32 *) (((char *) arg0) + 0x60)) = inline_fn2((*((s32 *) (((char *) arg0) + 0x60))) & (~0x62));
      }
    }
    temp_v1_9 = *((s8 *) (((char *) temp_s2) + 0x198));
    if (temp_v1_9 > 0)
    {
      *((s8 *) (((char *) temp_s2) + 0x198)) = (s8) (temp_v1_9 - 1);
    }
    if ((*((s32 *) (((char *) arg0) + 0x60))) & 0x20)
    {
      *((s8 *) (((char *) temp_s2) + 0x198)) = 0;
    }
    if ((*((s32 *) (((char *) arg0) + 0x60))) & 0x22)
    {
      if ((*((s16 *) (((char *) arg0) + 0x7A))) != 6)
      {
        temp_ft1 = *((f32 *) (((char *) temp_s2) + 0x60));
        var_fs0 = (*((f32 *) (((char *) temp_s2) + 0x1B0))) * ((f32) (*(D_800C7DAC + ((((u32) (*((u32 *) (((char *) temp_s2) + 0x18C)))) >> 0xC) & 0xF))));
        if (temp_ft1 > 0.0f)
        {
          temp_fv1_3 = temp_ft1 - var_fs0;
          *((f32 *) (((char *) temp_s2) + 0x60)) = temp_fv1_3;
          if (temp_fv1_3 < 0.0f)
          {
            *((f32 *) (((char *) temp_s2) + 0x60)) = 0.0f;
            var_fs0 = -temp_fv1_3;
            func_80070730(temp_s2, 0x1A, 1);
          }
          else
          {
            var_fs0 = 0.0f;
          }
        }
        if ((var_fs0 > 0.0f) && ((*((s8 *) (((char *) temp_s2) + 0x198))) == 0))
        {
          *((s8 *) (((char *) temp_s2) + 0x198)) = 5;
          temp_fv0_3 = (*((f32 *) (((char *) arg0) + 0x74))) - var_fs0;
          var_a2 = 1;
          *((f32 *) (((char *) arg0) + 0x74)) = temp_fv0_3;
          if (!(temp_fv0_3 > 0.0f))
          {
            var_a2 = 0;
          }
          func_800848EC(arg0, 1, var_a2);
        }
        *((f32 *) (((char *) temp_s2) + 0x1B0)) = 0.0f;
        temp_v1_10 = *((s32 *) (((char *) arg0) + 0x60));
        var_a2_2 = 1;
        if (temp_v1_10 & 0x40)
        {
          {
            long long phantom_wide2 = sp38;
          }
          if (!((*((f32 *) (((char *) temp_s2) + 0x1B0))) < (*((f32 *) (((char *) arg0) + 0x74)))))
          {
            var_a2_2 = 0;
          }
          func_80084CD8(arg0 + 0x24, 1, var_a2_2);
        }
        else
          if (temp_v1_10 & 2)
        {
          if (!((*((f32 *) (((char *) temp_s2) + 0x1B0))) < (*((f32 *) (((char *) arg0) + 0x74)))))
          {
            var_a2_2 = 0;
          }
          func_800843CC(arg0 + 0x24, 1, var_a2_2);
        }
      }
      *((s32 *) (((char *) arg0) + 0x60)) = inline_fn2((*((s32 *) (((char *) arg0) + 0x60))) & (~0x42));
    }
    if ((*((u16 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xC))) & 8)
    {
      var_a0 = 0;
      if (D_80108F84 != NULL)
      {
        var_a0 = ((u8) (*((u8 *) (((char *) D_80108F84) + 0x51)))) >> 7;
      }
      if ((gPlayerActor != NULL) && ((*((s32 *) (((char *) gPlayerActor) + 0x5C))) & 0x800000))
      {
        var_a0 = 1;
      }
      if (inline_fn23(var_a0) != 0)
      {
        *((f32 *) (((char *) arg0) + 0x74)) = 0.0f;
        *((s32 *) (((char *) arg0) + 0x60)) = inline_fn2((*((s32 *) (((char *) arg0) + 0x60))) | 0x40000000);
        *((u32 *) (((char *) temp_s2) + 0x18C)) = (u32) (((*((u32 *) (((char *) temp_s2) + 0x18C))) & 0xFFFF0FFF) | 0x7000);
        {
          struct Position
          {
            f32 x;
            f32 y;
            f32 z;
          };
          *((struct Position *) (((char *) temp_s2) + 0x1A0)) = *((struct Position *) (((char *) arg0) + 0x24));
        }
        *((f32 *) (((char *) temp_s2) + 0x1B0)) = 100.0f;
        *((s32 *) (((char *) temp_s2) + 0x1B4)) = 0;
      }
    }
    if ((((*((f32 *) (((char *) arg0) + 0x74))) <= 0.0f) && ((*((u16 *) (((char *) arg0) + 0x78))) == 3)) && (inline_fn23(actorFinishIfMatch(arg0, 3)) != 0))
    {
      func_80117EC8(arg0, 6);
    }
    if ((((*((s16 *) (((char *) arg0) + 0x7A))) != 6) & (inline_fn23(var_s3) != 0)) && ((temp_a1_4 = *((void **) (((char *) temp_s2) + 0xC0)), (((u32) ((*((u16 *) (((char *) temp_a1_4) + 0x78))) - 2)) < 2U) != 0)))
    {
      temp_fa1 = func_800461D4(arg0 + 0x24, temp_a1_4 + 0x24);
      temp_v1_11 = *((void **) (((char *) temp_s2) + 0xC0));
      var_fa0 = (*((f32 *) (((char *) temp_v1_11) + 0x28))) - (*((f32 *) (((char *) arg0) + 0x28)));
      if ((*((f32 *) (((char *) (*((void **) (((char *) (((*((s8 *) (((char *) (*((void **) (((char *) temp_v1_11) + 0x6C)))) + 0x182))) * 4) + 0x80110000)) + (-0x6978))))) + 0x130))) > 0.0f)
      {
        var_fa0 -= 0.35f;
      }
      temp_fv1_4 = *((f32 *) (((char *) temp_s2) + 0x34));
      *((f32 *) (((char *) temp_s2) + 0x34)) = (f32) (temp_fv1_4 + (((approximateAtan2(var_fa0, temp_fa1) * 0.63661975f) - temp_fv1_4) * 0.5f));
    }
    else
    {
      *((f32 *) (((char *) temp_s2) + 0x34)) = (f32) ((*((f32 *) (((char *) temp_s2) + 0x34))) * 0.5f);
    }
    func_80067E94(arg0);
    *((s32 *) (((char *) temp_s2) + 0x48)) = 0;
    *((s32 *) (((char *) temp_s2) + 0x4C)) = 0;
    updateSwayMotion(arg0);
    func_80070F34(arg0);
    if ((*((s16 *) (((char *) arg0) + 0x7A))) != 6)
    {
      temp_v0_5 = var_s3 & (inline_fn2((*((u16 *) (((char *) temp_s2) + 0x176))) << 0x10) >> 0x1F);
      var_s3_2 = temp_v0_5;
      if ((temp_v0_5 << 0x18) != 0)
      {
        coefficients = *((struct Coefficients *) (&D_8011EF30));
        temp_v1_10 = *((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE));
        var_s0_2 = 0x28;
        if (9 <= temp_v1_10)
        {
          var_s0_2 = 0x4B;
          if (1)
          {
            if (temp_v1_10 >= 0xC)
            {
              if (temp_v1_10 < 0x13)
              {
                var_s0_2 = 0x28;
                if (temp_v1_10 >= 0xD)
                {
                  var_s0_2 = 0x4B;
                }
              }
              else
              {
                var_s0_2 = 0x28;
              }
            }
          }
        }
        var_ft0 = (f64) var_s0_2;
        if (var_s0_2 < 0)
        {
          var_ft0 += D_8011EF78;
        }
        temp_fv1_5 = ((f32) var_ft0) * (*((f32 *) (((char *) (((u8 *) (&coefficients)) + (((*((u16 *) ((&D_800BF688) + (((s16) temp_v1) * 0xC)))) >> 3) & 0x1C))) + 0)));
        var_s0_2 = (u32) temp_fv1_5;
        var_s3_2 = 0;
        if (randomIntBelow(0x64) < var_s0_2)
        {
          var_s3_2 = inline_fn23(func_8007A9CC(arg0, ((s32) (*((void **) (((char *) temp_s2) + 0xC0)))) + 0x24, &sp38, 170.6666717529296875f)) != 0;
        }
      }
      func_8006899C(arg0, var_s3_2);
      temp_v1_13 = *((s16 *) (((char *) (*((void **) (((char *) temp_s2) + 0xA8)))) + 0x7A));
      if (((int) temp_v1_13) != 2)
      {
        if (temp_v1_13 >= 3)
        {
          if (inline_fn234(temp_v1_13 == 4) || (temp_v1_13 == 8))
          {
            goto block_179;
          }
        }
        else
          if (temp_v1_13 != 0)
        {
        }
        else
        {
          goto block_179;
        }
      }
      else
      {
        block_179:
        refreshSaveSlotSelection(arg0);

      }
    }
    temp_v0_6 = &D_8011F060[(s8) (*((u8 *) (((char *) temp_s2) + 0x182)))];
    *temp_v0_6 += 1;
  }
}

