f32 Vec3_DistanceSq(f32 *, void *);
f32 absFloat(f32);
s32 actorFinishIfMatch(void *, s32);
s32 angleDelta12(s32, s32);
f32 approximateAtan2(f32, f32);
s32 clearProbeState(void *, s32);
f32 cosAngle(f32);
s32 effectSetAnimFrame(void *, s32, s32);
s32 freeMenuItemRecord(void *, void *);
s32 func_80002BD0(void *, s32);
s32 func_8000C91C(s32);
void *func_80015F0C();
unsigned int func_800165E0(void *, s32);
s32 func_800452E0(void *, void *, s32 *);
f32 func_80045764(s32 *, s32 *);
s32 func_80047B14(s32 *, f32, s32 *);
s32 func_800635BC(void *, s32);
s32 func_80065684(void *);
s32 func_8006CD34(void *);
s32 func_8006D224(void *, s32);
s32 func_8006E648(s32, void *, s32, s32 *, void **, void **, s32 *, s32 *);
s32 func_80070730(void *, s32, s32);
s32 func_80073A30(void);
s32 func_80082834(char, s32, s32);
s32 func_800843CC(void *, s32, s32);
s32 func_800848EC(void *, s32, s32);
s32 func_80084CD8(void *, s32, s32);
s32 func_80085454();
s32 func_8008558C(void *);
void *func_8011B3D8(s32);
s32 getSaveSlotIndex(s32);
s32 initObjectFromBankEntry(void *, s32, s32);
s32 randomIntBelow(s32);
s32 randomU32Next();
s32 requestSound(s32);
s32 segmentClosestPoint(f32 *, void *, void *, void *);
f32 sinAngle(f32);
s32 updateSwingAnimation(void *, f32);
s32 vec3Add(s32 *, s32 *, s32 *);
extern s32 D_800BF688;
extern u8 D_800C7DAC[];
typedef struct 
{
  u16 f0;
  u8 pad[6];
} Slot_800C7DC8;
extern Slot_800C7DC8 D_800C7DC8[];
typedef struct 
{
  u16 f0;
  u8 pad[6];
} Slot_800C7DCC;
extern Slot_800C7DCC D_800C7DCC[];
extern f64 D_800D4650;
extern s8 D_800E19F4;
extern f32 D_800E19F8;
extern f32 D_800E19FC;
extern s32 D_800E1A04;
extern s32 D_800E1A08;
extern s32 D_800E1A24;
extern u8 D_801002D5;
extern u8 D_80100B18;
extern u8 D_80109A73;
extern s32 D_80112F68;
extern u8 gBorderFlipFlag;
extern s32 gBorderSkipActive;
extern s32 gGameMode;
extern u8 gSaveKeyRelaxed;
extern s32 gSaveSlotCount;
extern s32 gSaveSlotInfo;
extern s32 gSwingPhase;
extern s32 gVisibleSaveSlotCount;
extern u8 gWheelsGrounded;
extern u8 sDifficultyLevel;
extern void *sTrackMarkerTable[];
typedef struct 
{
  unsigned char pad_0[96];
  int field_60;
  unsigned char pad_64[12];
  void *field_70;
} __repair_record_sp38;
inline static s32 inline_fn()
{
  return (s32) sDifficultyLevel;
}

inline static f32 inline_fn2(f32 *arg0)
{
  return arg0[1];
}

void func_8006D2E4(void *arg0)
{
  char sp20[0x10];
  volatile unsigned int sp30;
  void *sp34;
  void *sp38;
  s32 sp3C;
  s32 sp40;
  f32 sp48[3];
  f32 sp58[3];
  s32 *temp_s0_2;
  s32 var_a1_2;
  s32 var_a2_3;
  s32 var_a2_4;
  f32 temp_fa0;
  f32 temp_fa0_2;
  f32 temp_fs0;
  f32 temp_fv0;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  f32 var_fs0;
  f32 var_fv0;
  f32 var_fv0_2;
  f32 var_fv1;
  f64 var_ft0;
  s16 temp_s0;
  s16 temp_v0_10;
  s16 temp_v0_14;
  s16 var_a1;
  s32 temp_s1;
  s32 temp_s5;
  unsigned int temp_v0_4;
  s32 temp_v0_5;
  s32 temp_v0_7;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 temp_v1_3;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a2;
  s32 var_a2_2;
  s32 var_condition_bit;
  s32 var_s0;
  s32 var_v0;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v1;
  s8 temp_a0;
  int temp_s4;
  s8 temp_v0_2;
  short var_a0_3;
  u32 temp_v0_8;
  u32 temp_v0_9;
  void *temp_a1;
  register void *temp_s0_3;
  void *temp_s3;
  void *temp_v0;
  void *temp_v0_11;
  void *temp_v0_12;
  void *temp_v0_13;
  void *temp_v0_15;
  void *temp_v0_3;
  void *temp_v0_6;
  void *temp_v1_4;
  void *temp_v1_5;
  temp_s3 = *((void **) (((char *) arg0) + 0x6C));
  temp_s4 = *((s8 *) (((char *) temp_s3) + 0x182));
  var_fs0 = 0.0f;
  sp34 = NULL;
  sp40 = 0;
  sp38 = NULL;
  sp3C = 0;
  sp30 = 0;
  temp_s5 = *((s32 *) (((char *) arg0) + 0x20));
  if (((gBorderSkipActive != 0) && (gSaveKeyRelaxed != 0)) && (D_801002D5 == 0))
  {
    temp_v0 = func_8011B3D8(*((s32 *) (((char *) temp_s3) + 0x1B8)));
    if ((temp_v0 != NULL) && (((*((u8 *) (((char *) (*((void **) (((char *) temp_s3) + 0xB4)))) + 0x12))) == (*((u8 *) (((char *) (*((void **) (((char *) temp_v0) + 0xB4)))) + 0x12)))) & (((s32) temp_s3) != ((s32) temp_v0))))
    {
      *((s32 *) (((char *) arg0) + 0x60)) = (s32) ((*((s32 *) (((char *) arg0) + 0x60))) & (~0x62));
    }
  }
  if ((D_80112F68 == 0) && ((temp_s0 = *((s16 *) (((char *) arg0) + 0x7A)), temp_s0 == 1)))
  {
    temp_v0_2 = *((s8 *) (((char *) temp_s3) + 0x198));
    if (temp_v0_2 > 0)
    {
      *((s8 *) (((char *) temp_s3) + 0x198)) = (s8) (temp_v0_2 - 1);
    }
    if ((*((s32 *) (((char *) arg0) + 0x60))) & 0x20)
    {
      *((s8 *) (((char *) temp_s3) + 0x198)) = 0;
    }
    if ((*((s32 *) (((char *) arg0) + 0x60))) & 4)
    {
      func_80085454();
      *((s32 *) (((char *) arg0) + 0x60)) = (s32) ((*((s32 *) (((char *) arg0) + 0x60))) & (~4));
    }
    temp_v1 = *((s32 *) (((char *) arg0) + 0x60));
    if (temp_v1 & 0x42000022)
    {
      if (temp_v1 & 0x40000020)
      {
        var_fs0 = *((f32 *) (((char *) temp_s3) + 0x1B0));
        *((f32 *) (((char *) temp_s3) + 0x1B0)) = 0.0f;
        *((u32 *) (((char *) temp_s3) + 0x18C)) = (u32) (((*((u32 *) (((char *) temp_s3) + 0x18C))) & 0xFFFF0FFF) | 0x7000);
      }
      if ((*((s32 *) (((char *) arg0) + 0x60))) & 2)
      {
        if (gBorderSkipActive != 0)
        {
          temp_v0_3 = func_8011B3D8(*((s32 *) (((char *) temp_s3) + 4)));
          if (temp_v0_3 != NULL)
          {
            temp_a0 = *((s8 *) (((char *) temp_v0_3) + 0x182));
            if (temp_a0 >= gSaveSlotCount)
            {
              temp_v0_4 = (((u16) (*((u16 *) (((u8 *) (&D_800BF688)) + ((*((s32 *) (((u8 *) (&gSaveSlotInfo)) + ((getSaveSlotIndex(temp_a0 & 0xFFFF) & 0xFFFF) * 0x18)))) * 0xC))))) >> 5) & 7;
              switch (temp_v0_4)
              {
                case 1:

                default:
                  var_s0 = 1;
                  break;

                case 2:
                  var_s0 = 5;
                  break;

                case 3:
                  var_s0 = 0xA;
                  break;

                case 4:
                  var_s0 = 0x19;
                  break;

                case 5:
                  var_s0 = 0x32;
                  break;

              }

              if ((((*((u32 *) (((char *) temp_s3) + 0x18C))) & 0xF000) == 0xE000) && (var_s0 < randomIntBelow(0x64)))
              {
                *((u32 *) (((char *) temp_s3) + 0x18C)) = (u32) (((*((u32 *) (((char *) temp_s3) + 0x18C))) & 0xFFFF0FFF) | 0x7000);
              }
            }
          }
          temp_fs0 = (*((f32 *) (((char *) temp_s3) + 0x1B0))) * ((f32) (*(D_800C7DAC + ((((u32) (*((u32 *) (((char *) temp_s3) + 0x18C)))) >> 0xC) & 0xF))));
          temp_fv1 = temp_fs0 * 0.1f;
          var_a0 = (u32) temp_fv1;
          temp_v0_5 = randomIntBelow(var_a0);
          var_ft0 = (f64) temp_v0_5;
          if (temp_v0_5 < 0)
          {
            var_ft0 += D_800D4650;
          }
          var_fs0 = temp_fs0 + ((f32) ((s16) ((s32) (((f32) var_ft0) - (temp_fs0 * 0.05f)))));
          *((f32 *) (((char *) temp_s3) + 0x1B0)) = 0.0f;
          if (var_fs0 <= 0.0f)
          {
            var_fs0 = 1.0f;
          }
        }
        else
        {
          if (sDifficultyLevel != temp_s0)
          {
            if ((inline_fn() < 2) || (sDifficultyLevel != 2))
            {
              var_fv1 = 0.90000004f;
            }
            else
            {
              var_fv1 = 1.8000001f;
            }
          }
          else
          {
            var_fv1 = 1.35f;
          }
          temp_fv0 = *((f32 *) (((char *) temp_s3) + 0x1B0));
          *((f32 *) (((char *) temp_s3) + 0x1B0)) = 0.0f;
          var_fs0 = temp_fv0 * var_fv1;
        }
      }
      if (!((*((s32 *) (((char *) arg0) + 0x60))) & 0x40000000))
      {
        temp_fv0_2 = *((f32 *) (((char *) temp_s3) + 0x60));
        if (((temp_fv0_2 > 0.0f) && ((*((s8 *) (((char *) temp_s3) + 0x198))) == 0)) && (((*((u32 *) (((char *) temp_s3) + 0x18C))) & 0xF000) != 0xE000))
        {
          temp_fv0_3 = temp_fv0_2 - var_fs0;
          *((f32 *) (((char *) temp_s3) + 0x60)) = temp_fv0_3;
          if (temp_fv0_3 < 0.0f)
          {
            *((f32 *) (((char *) temp_s3) + 0x60)) = 0.0f;
            var_fs0 = -temp_fv0_3;
            func_80070730(temp_s3, 0x1A, 1);
          }
          else
          {
            var_fs0 = 0.0f;
          }
        }
      }
      if (!((*((s32 *) (((char *) arg0) + 0x60))) & 0x02000000))
      {
        do
        {
          if ((*((u16 *) (((char *) arg0) + 0x78))) == 2)
          {
            var_a2 = (((*(D_800C7DAC + ((((u32) (*((u32 *) (((char *) temp_s3) + 0x18C)))) >> 0xC) & 0xF))) * 0x46) / 25) + 0x1E;
            if (var_a2 <= 0)
            {
              var_a2 = 1;
            }
            else
              if (var_a2 >= 0x65)
            {
              var_a2 = 0x64;
            }
            func_80082834(temp_s4, 8, var_a2);
          }
        }
        while (0);
        if ((*((s32 *) (((char *) arg0) + 0x60))) & 0x02000000)
        {
          goto block_62;
        }
        goto block_95;
      }
      block_62:
      if (gWheelsGrounded == 0)
      {
        if (randomIntBelow(0x1E) == 0)
        {
          *((s8 *) (((char *) temp_s3) + 0x198)) = 0;
          switch (sDifficultyLevel)
          {
            case 3:

            case 4:

            case 5:

            default:
              var_fs0 = 1.1f;
              break;

            case 1:
              var_fs0 = 1.15f;
              break;

            case 2:
              var_fs0 = 1.2f;
              break;

          }

          if (randomU32Next() & 1)
          {
            requestSound(0x1AB);
          }
          else
          {
            requestSound(0x1AC);
          }
        }
      }
      else
      {
        var_a0_2 = 8;
        if ((*((s16 *) (((char *) arg0) + 0x7C))) == 6)
        {
          var_a0_2 = 0x10;
        }
        if (randomIntBelow(var_a0_2) == 0)
        {
          *((s8 *) (((char *) temp_s3) + 0x198)) = 0;
          if ((sDifficultyLevel != 1) && ((inline_fn() < 2) || (sDifficultyLevel != 2)))
          {
            var_fs0 = 1.0f;
          }
          else
          {
            var_fs0 = 2.0f;
          }
          temp_fv1_2 = *((f32 *) (((char *) arg0) + 0x74));
          var_v0 = (u32) temp_fv1_2;
          if (!var_v0)
          {
            func_8008558C(arg0);
          }
        }
      }

      var_condition_bit = var_fs0 > 0.0f;
      *((f32 *) (((char *) temp_s3) + 0x1A0)) = (f32) (*((f32 *) (((char *) arg0) + 0x24)));
      *((f32 *) (((char *) temp_s3) + 0x1A4)) = (f32) (*((f32 *) (((char *) arg0) + 0x28)));
      *((f32 *) (((char *) temp_s3) + 0x1A8)) = (f32) (*((f32 *) (((char *) arg0) + 0x2C)));
      if ((var_fs0 > 0.0f) && ((*((u16 *) (((char *) arg0) + 0x78))) == 2))
      {
        var_a2_2 = (s32) (var_fs0 * 40.0f);
        if (var_a2_2 <= 0)
        {
          var_a2_2 = 1;
        }
        else
          if (var_a2_2 >= 0x65)
        {
          var_a2_2 = 0x64;
        }
        func_80082834(temp_s4, 8, var_a2_2);
        block_95:
        var_condition_bit = var_fs0 > 0.0f;

      }
      if (var_condition_bit)
      {
        if ((*((s8 *) (((char *) temp_s3) + 0x198))) == 0)
        {
          *((s8 *) (((char *) temp_s3) + 0x198)) = 5;
          *((f32 *) (((char *) arg0) + 0x74)) = (f32) ((*((f32 *) (((char *) arg0) + 0x74))) - var_fs0);
          if ((*((void **) (((char *) temp_s3) + 0x414))) == NULL)
          {
            temp_v0_6 = func_80015F0C();
            *((void **) (((char *) temp_s3) + 0x414)) = temp_v0_6;
            if (temp_v0_6 != NULL)
            {
              temp_s1 = (angleDelta12((s32) (approximateAtan2((*((f32 *) (((char *) arg0) + 0x24))) - (*((f32 *) (((char *) temp_s3) + 0x1A0))), (*((f32 *) (((char *) arg0) - (-0x2C)))) - (*((f32 *) (((char *) temp_s3) + 0x1A8)))) * 651.8986f), (s32) ((*((f32 *) (((char *) arg0) + 0x40))) + 256.0f)) >> 9) & 7;
              temp_v0_7 = temp_s1 * 8;
              *((s32 *) (((char *) temp_v0_6) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v0_6) + 0x28))) & (~0xFC)) | 0x10);
              initObjectFromBankEntry(temp_v0_6, D_800C7DC8[temp_s1].f0, 0x1B);
              func_800165E0(*((void **) (((char *) temp_s3) + 0x414)), sTrackMarkerTable[temp_s4]);
              var_a1 = 0x140;
              var_a0_3 = 0xF0;
              if (gBorderSkipActive != 0)
              {
                if (gVisibleSaveSlotCount != 2)
                {
                  var_v0_2 = temp_s1 * 8;
                  if (gVisibleSaveSlotCount >= 2)
                  {
                    var_v0_2 = temp_s1 * 8;
                    if (gVisibleSaveSlotCount < 5)
                    {
                      var_a1 = 0xA0;
                      goto block_107;
                    }
                  }
                }
                else
                {
                  if (gBorderFlipFlag == 1)
                  {
                    var_a1 = 0xA0;
                  }
                  else
                  {
                    block_107:
                    var_a0_3 = 0x78;

                  }
                  goto block_108;
                }
              }
              else
              {
                block_108:
                var_v0_2 = temp_s1 * 8;

              }
              *((s16 *) (((char *) temp_v0_6) + 0x20)) = 0;
              *((s16 *) (((char *) temp_v0_6) + 0x22)) = 0;
              *((s16 *) (((char *) temp_v0_6) + 0x26)) = var_a1;
              *((s8 *) (((char *) temp_v0_6) + 0x29)) = var_a0_3;
              *((s16 *) (((char *) temp_v0_6) + 0x1E)) = (s16) (D_800C7DCC[temp_s1].f0 | 0x4402);
            }
          }
          func_8006D224(arg0, 0xA0);
        }
        if ((!((*((s32 *) (((char *) arg0) + 0x60))) & 0x02000000)) || (gWheelsGrounded != 0))
        {
          var_a2_3 = 1;
          if (!((*((f32 *) (((char *) arg0) + 0x74))) > 0.0f))
          {
            var_a2_3 = 0;
          }
          func_800848EC(arg0, 1, var_a2_3);
        }
      }
      temp_v1_2 = *((s32 *) (((char *) arg0) + 0x60));
      var_a2_4 = 1;
      if (temp_v1_2 & 0x40)
      {
        if (!((*((f32 *) (((char *) arg0) + 0x74))) > 0.0f))
        {
          var_a2_4 = 0;
        }
        func_80084CD8(arg0 + 0x24, 1, var_a2_4);
      }
      else
        if (temp_v1_2 & 2)
      {
        if (!((*((f32 *) (((char *) arg0) + 0x74))) > 0.0f))
        {
          var_a2_4 = 0;
        }
        func_800843CC(arg0 + 0x24, 1, var_a2_4);
      }
      if ((actorFinishIfMatch(arg0, 2) << 0x18) == 0)
      {
        if ((*((s32 *) (((char *) arg0) + 0x60))) & 0x40000022)
        {
          func_800452E0(temp_s3 + 0x1A0, arg0 + 0x24, sp20);
          func_80045764(sp20, sp20);
          func_80047B14(sp20, 0.075f, sp20);
          temp_s0_2 = temp_s3 + 0x11C;
          vec3Add(sp20, temp_s0_2, temp_s0_2);
          var_fv0 = func_80045764(temp_s0_2, temp_s0_2);
          if (var_fv0 > 0.075f)
          {
            var_fv0 = 0.075f;
          }
          func_80047B14(temp_s0_2, var_fv0, temp_s0_2);
        }
        goto block_130;
      }
    }
    else
    {
      goto block_130;
    }
  }
  else
  {
    block_130:
    if (temp_s5)
    {
      func_8006E648(temp_s5, arg0, D_800E1A24, &sp30, &sp34, &sp38, &sp3C, &sp40);
    }

    temp_a1 = *((void **) (((char *) temp_s3) + 0x414));
    if (temp_a1 != NULL)
    {
      temp_v1_2 = *((s32 *) (((char *) temp_a1) + 0x10));
      temp_v0_8 = temp_v1_2 & 0xFF;
      temp_v0_9 = temp_v0_8 - (temp_v0_8 >> 2);
      *((s32 *) (((char *) temp_a1) + 0x10)) = (s32) ((temp_v1_2 & (~0xFF)) | temp_v0_9);
      if (temp_v0_9 < 4U)
      {
        freeMenuItemRecord(*((void **) (((char *) temp_s3) + 0x414)), temp_a1);
        *((void **) (((char *) temp_s3) + 0x414)) = NULL;
      }
    }
    if (((u32) (((u16) (*((s16 *) (((char *) arg0) + 0x7A)))) - 2)) >= 2U)
    {
      if (((((D_800E19F4 == 0) && (gGameMode == 0xB)) && (sp38 != NULL)) && (D_80109A73 != 0)) && (((*((s32 *) (((char *) ((__repair_record_sp38 *) sp38)->field_70) + 0x30))) & 0xFFFF0) == 0x610))
      {
        D_800E19F4 = 1;
        ((__repair_record_sp38 *) sp38)->field_60 = (s32) (((__repair_record_sp38 *) sp38)->field_60 | 1);
        func_80073A30();
        func_8000C91C(7);
      }
      if ((sp34 != NULL) && (sp30 & 1))
      {
        temp_v0_10 = *((s16 *) (((char *) arg0) + 0x7C));
        if ((((temp_v0_10 != 1) & (temp_v0_10 != 3)) && ((*((u8 *) (((char *) temp_s3) + 0x186))) == 0)) && (((f32) angleDelta12((s32) (*((f32 *) (((char *) arg0) + 0x40))), (s32) ((*((f32 *) (((char *) sp34) + 0x34))) * 651.8986f))) < 0.0f))
        {
          *((f32 *) (((char *) temp_s3) + 0x14)) = (f32) (((*((f32 *) (((char *) sp34) + 0x44))) + (*((f32 *) (((char *) sp34) + 0x4C)))) + (-1.1f));
          *((f32 *) (((char *) temp_s3) + 0x18)) = (f32) (((*((f32 *) (((char *) sp34) + 0x44))) - (*((f32 *) (((char *) sp34) + 0x4C)))) + 0.9f);
          temp_fa0 = ((*((f32 *) (((char *) sp34) + 0x34))) * 651.8986f) + 1024.0f;
          sp48[1] = temp_fa0;
          sp58[0] = *((f32 *) (((char *) sp34) + 0x24));
          sp58[1] = *((f32 *) (((char *) arg0) + 0x28));
          sp58[2] = *((f32 *) (((char *) sp34) + 0x2C));
          sp58[0] -= sinAngle(temp_fa0) * 0.43f;
          sp58[2] -= cosAngle(temp_fa0) * 0.43f;
          if ((!((*((f32 *) (((char *) temp_s3) + 0x14))) < inline_fn2(sp58))) && (!(inline_fn2(sp58) < (*((f32 *) (((char *) temp_s3) + 0x18))))))
          {
            *((f32 *) (((char *) arg0) + 0x24)) = sp58[0];
            *((f32 *) (((char *) arg0) + 0x28)) = inline_fn2(sp58);
            *((f32 *) (((char *) arg0) + 0x2C)) = sp58[2];
            *((f32 *) (((char *) arg0) + 0x3C)) = 0.0f;
            *((f32 *) (((char *) arg0) + 0x44)) = 0.0f;
            *((f32 *) (((char *) arg0) + 0x40)) = inline_fn2(sp48);
            *((f32 *) (((char *) temp_s3) + 0x90)) = (f32) (*((f32 *) (((char *) arg0) + 0x40)));
            if (absFloat((*((f32 *) (((char *) arg0) + 0x28))) - (*((f32 *) (((char *) temp_s3) + 0x18)))) < 0.15f)
            {
              var_a1_2 = 0x296;
              goto block_153;
            }
            var_a1_2 = 0x297;
            if (absFloat((*((f32 *) (((char *) arg0) + 0x28))) - (*((f32 *) (((char *) temp_s3) + 0x14)))) < 0.15f)
            {
              block_153:
              func_80002BD0(arg0, var_a1_2);

              temp_v1_4 = *((void **) (((char *) arg0) + 0x68));
              *((u16 *) (((char *) temp_v1_4) + 0xC)) = (u16) ((*((u16 *) (((char *) temp_v1_4) + 0xC))) | 0x40);
            }
            else
            {
              func_80002BD0(arg0, 0x295);
            }
            requestSound(0x1B);
            *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x30)) = 0;
            *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x34)) = 0;
            func_80065684(arg0);
            func_800635BC(arg0, 1);
            *((s8 *) (((char *) temp_s3) + 0x181)) = 1;
            *((s8 *) (((char *) temp_s3) + 0x17E)) = 2;
          }
        }
      }
      switch (D_80100B18)
      {
        case 0:
          if ((*((s8 *) (((char *) temp_s3) + 0x19C))) != 0)
        {
          temp_v0_11 = *((void **) (((char *) temp_s3) + 0xC4));
          *((f32 *) (((char *) temp_v0_11) + 0x24)) = (f32) (*((f32 *) (((char *) temp_s3) + 0xEC)));
          *((f32 *) (((char *) temp_v0_11) + 0x28)) = (f32) (*((f32 *) (((char *) temp_s3) + 0xF0)));
          *((f32 *) (((char *) temp_v0_11) + 0x2C)) = (f32) (*((f32 *) (((char *) temp_s3) + 0xF4)));
          *((f32 *) (((char *) (*((void **) (((char *) temp_s3) + 0xC4)))) + 0x3C)) = -1024.0f;
          *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0xC4)))) + 0x40)) = 0;
          *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0xC4)))) + 0x44)) = 0;
          *((f32 *) (((char *) (*((void **) (((char *) temp_s3) + 0xC4)))) + 0x54)) = 0.0f;
          effectSetAnimFrame(*((void **) (((char *) temp_s3) + 0xC4)), 0xC, 0x1B);
          var_fv0_2 = ((*((f32 *) (((char *) temp_s3) + 0xF0))) - (*((f32 *) (((char *) temp_s3) + 0xFC)))) - 0.4f;
          if (var_fv0_2 < 0.4f)
          {
            var_fv0_2 = 0.4f;
          }
          D_80100B18 = 1;
          D_800E19FC = var_fv0_2;
          gSwingPhase = 0;
          D_800E1A04 = 0;
          D_800E1A08 = 0;
          if ((*((s16 *) (((char *) arg0) + 0x7C))) == 3)
          {
            *((s32 *) (((char *) temp_s3) + 0xCC)) = 0;
            *((s8 *) (((char *) temp_s3) + 0x188)) = 0x14;
            func_800635BC(arg0, 0);
          }
        }
          break;

        case 1:
          updateSwingAnimation(arg0, randomFloatScaled(0.1f) + 0.1f);
          temp_v0_12 = *((void **) (((char *) temp_s3) + 0xC4));
          *((f32 *) (((char *) temp_v0_12) + 0x54)) = (f32) ((*((f32 *) (((char *) temp_v0_12) + 0x54))) + (D_800E19FC * 0.016666668f));
          temp_v0_13 = *((void **) (((char *) temp_s3) + 0xC4));
          if (D_800E19FC <= (*((f32 *) (((char *) temp_v0_13) + 0x54))))
        {
          *((f32 *) (((char *) temp_v0_13) + 0x54)) = (f32) D_800E19FC;
          D_80100B18 = 2;
        }
          break;

        case 2:
          updateSwingAnimation(arg0, 0.01f);
          temp_v0_14 = *((s16 *) (((char *) arg0) + 0x7C));
          if (((temp_v0_14 != 3) & (temp_v0_14 != 1)) && ((*((s8 *) (((char *) temp_s3) + 0x188))) == 0))
        {
          temp_s0_3 = arg0 + 0x24;
          segmentClosestPoint(sp48, temp_s3 + 0xEC, temp_s3 + 0xF8, temp_s0_3);
          if (Vec3_DistanceSq(sp48, temp_s0_3) < 0.8f)
          {
            temp_fa0_2 = approximateAtan2((*((f32 *) (((char *) arg0) + 0x24))) - sp48[0], (*((f32 *) (((char *) arg0) + 0x2C))) - sp48[2]) * 651.8986f;
            temp_fv1_3 = (f32) (((s32) ((((s32) (*((f32 *) (((char *) arg0) + 0x40)))) - ((s32) temp_fa0_2)) << 0x14)) >> 0x14);
            D_800E19F8 = temp_fa0_2;
            var_v0_3 = 1;
            if (!(temp_fv1_3 > 1800.0f))
            {
              var_v0_3 = 0;
            }
            var_v1 = 1;
            if (!(temp_fv1_3 < (-1800.0f)))
            {
              var_v1 = 0;
            }
            if ((var_v0_3 | var_v1) != 0)
            {
              *((f32 *) (((char *) arg0) + 0x40)) = (f32) (temp_fa0_2 + 2048.0f);
              sp48[0] = (*((f32 *) (((char *) temp_s3) + 0xEC))) + (sinAngle(temp_fa0_2) * 0.22500001f);
              sp48[2] = (*((f32 *) (((char *) temp_s3) + 0xF4))) + (cosAngle(D_800E19F8) * 0.22500001f);
              *((f32 *) (((char *) arg0) + 0x24)) = sp48[0];
              *((f32 *) (((char *) arg0) + 0x28)) = inline_fn2(sp48);
              *((f32 *) (((char *) arg0) + 0x2C)) = sp48[2];
              func_80065684(arg0);
              func_800635BC(arg0, 3);
              clearProbeState(arg0, 0x159);
              *((s8 *) (((char *) temp_s3) + 0x17E)) = 2;
              *((s8 *) (((char *) temp_s3) + 0x181)) = 1;
              *((s32 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0x34)) = 0;
            }
          }
        }
          break;

      }

      temp_v0_15 = *((void **) (((char *) arg0) + 0x68));
      *((u16 *) (((char *) temp_v0_15) + 0xC)) = (u16) ((*((u16 *) (((char *) temp_v0_15) + 0xC))) & 0xFFFB);
      if ((sp40 != 0) && (sp3C & 2))
      {
        temp_v1_5 = *((void **) (((char *) arg0) + 0x68));
        *((u16 *) (((char *) temp_v1_5) + 0xC)) = (u16) ((*((u16 *) (((char *) temp_v1_5) + 0xC))) | 4);
      }
    }
    *((s32 *) (((char *) arg0) + 0x60)) = (s32) ((*((s32 *) (((char *) arg0) + 0x60))) & 0xBDFFFF9D);
    *((s32 *) (((char *) sTrackMarkerTable[temp_s4]) + 0xFC)) = (s32) (*((u8 *) (((char *) temp_s3) + 0x184)));
    *((s32 *) (((char *) arg0) + 0x58)) = (s32) ((*((s32 *) (((char *) arg0) + 0x58))) | 1);
    func_8006CD34(arg0);
    *((s32 *) (((char *) temp_s3) + 4)) = 0;
  }
}

