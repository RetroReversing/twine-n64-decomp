s32 func_80048794(s32, s32);
s32 func_800820B0(s32);
extern f64 D_800D48B0;
extern f64 D_800D48B8;
extern f64 D_800D48C0;
extern f64 D_800D48C8;
extern f64 D_800D48D0;
extern f64 D_800D48D8;
extern f64 D_800D48E0;
extern void *D_8010969C;
extern s32 D_8010A4C3;
extern u8 gBorderFlipFlag;
extern s32 gBorderSkipActive;
extern void *gMenuRootObject;
extern s32 gProbeObjectList;
extern s32 gSaveTotalSlots;
extern u8 gSceneFlagsB;
extern s32 gVisibleSaveSlotCount;
extern s32 osTvType;
extern void *sTrackMarkerTable[];
void func_8007560C(void)
{
  s32 var_a0;
  f32 temp_fs0_2;
  f32 temp_fs0_3;
  u32 temp_v1;
  f32 temp_fs0_5;
  f32 temp_fs1;
  f32 temp_fs2;
  f32 temp_fs2_2;
  f32 temp_fs2_3;
  f32 temp_fs3;
  f32 temp_fs3_2;
  register f32 temp_fs4;
  f32 var_a1;
  f32 var_a2;
  register f32 var_a3;
  f64 temp_fs0;
  f64 var_fv0;
  register f64 var_fv1;
  f64 var_fv1_2;
  f64 var_fv1_3;
  f64 var_fv1_4;
  f32 temp_fs0_4;
  s32 var_s0;
  s32 var_v1;
  void **var_s1;
  void *temp_s4;
  void *temp_v1_2;
  void *var_a0_2;
  volatile s32 offsetSeed = 0;
  unsigned int xOffset;
  unsigned int yOffset = offsetSeed;
  f32 height;
  xOffset = offsetSeed;
  {
    long long phantom_wide = var_a0;
  }
  if (osTvType)
  {
    {
      long long phantom_wide2 = var_a0;
    }
    xOffset = yOffset;
  }
  if (gMenuRootObject == NULL)
  {
    func_80048794(4, gProbeObjectList);
  }
  func_8004844C(gMenuRootObject, 160.0f, 120.0f, 320.0f, 240.0f, (f32) (var_fv1 = (f64) xOffset), (f32) yOffset);
  *((u8 *) (((char *) (&D_8010A4C3)) + 0)) = (u8) ((*((u8 *) (((char *) (&D_8010A4C3)) + 0))) & 0xEF);
  *((u8 *) (((char *) (&D_8010A4C3)) + (-2))) = (u8) ((*((u8 *) (((char *) (&D_8010A4C3)) + (-2)))) & 0xEF);
  *((s32 *) (((char *) gMenuRootObject) + 0x100)) = (s32) ((*((s32 *) (((char *) gMenuRootObject) + 0x100))) | 0x100);
  if (D_8010969C == NULL)
  {
    func_80048794(5, gProbeObjectList);
  }
  func_8004844C(D_8010969C, 160.0f, 120.0f, 320.0f, 240.0f, (f32) (var_fv1_2 = (f64) xOffset), (f32) yOffset);
  *((u8 *) (((char *) (&D_8010A4C3)) + 0)) = (u8) ((*((u8 *) (((char *) (&D_8010A4C3)) + 0))) & 0xDF);
  *((u8 *) (((char *) (&D_8010A4C3)) + (-2))) = (u8) ((*((u8 *) (((char *) (&D_8010A4C3)) + (-2)))) & 0xDF);
  gSceneFlagsB |= 0x20;
  *((s32 *) (((char *) D_8010969C) + 0x100)) = (s32) ((*((s32 *) (((char *) D_8010969C) + 0x100))) | 0x100);
  if (gBorderSkipActive == 0)
  {
    if (sTrackMarkerTable[0] == NULL)
    {
      func_80048794(0, gProbeObjectList);
    }
    var_fv1_3 = (f64) 0;
    func_8004844C(sTrackMarkerTable[0], 160.0f, 120.0f, 320.0f, 240.0f, (f32) xOffset, (f32) yOffset);
    var_a0 = 1;
    goto block_75;
  }
  if ((0 - 1) < (gSaveTotalSlots - 1))
  {
    var_s0 = 0;
    temp_fs0 = D_800D48D0;
    do
    {
      temp_s4 = ((char *) (&D_8010A4C3)) - 1;
    }
    while (0);
    var_s1 = (void **) (((char *) (&gMenuRootObject)) - 0x10);
    do
    {
      if ((*var_s1) == NULL)
      {
        func_80048794(var_s0, gProbeObjectList);
        var_fv0 = (f64) 0;
        func_8004844C(*var_s1, 160.0f, 120.0f, 320.0f, 240.0f, (f32) xOffset, (f32) yOffset);
        if (var_s0 >= gVisibleSaveSlotCount)
        {
          var_v1 = 1 << var_s0;
          if ((gVisibleSaveSlotCount == 3) & (var_s0 == 3))
          {
            *((u8 *) (((char *) (&D_8010A4C3)) + 0)) = (u8) ((*((u8 *) (((char *) (&D_8010A4C3)) + 0))) | var_v1);
          }
          else
          {
            *((u8 *) (((char *) (&D_8010A4C3)) + 0)) = (u8) ((*((u8 *) (((char *) (&D_8010A4C3)) + 0))) & (~(1 << var_s0)));
            var_v1 = 1 << var_s0;
          }
          temp_v1 = ~var_v1;
          *((u8 *) (((char *) temp_s4) + 0)) = (u8) ((*((u8 *) (((char *) temp_s4) + 0))) & temp_v1);
          *((u8 *) (((char *) temp_s4) + (-1))) = (u8) ((*((u8 *) (((char *) temp_s4) + (-1)))) & temp_v1);
          temp_v1_2 = *var_s1;
          *((s32 *) (((char *) temp_v1_2) + 0x100)) = (s32) ((*((s32 *) (((char *) temp_v1_2) + 0x100))) | 0x100);
        }
        else
        {
          *((u8 *) (((char *) (&D_8010A4C3)) + 0)) = (u8) ((*((u8 *) (((char *) (&D_8010A4C3)) + 0))) | (1 << var_s0));
        }
      }
      var_s0 += 1;
      var_s1 += 1;
    }
    while (gSaveTotalSlots > var_s0);
  }
  switch (gVisibleSaveSlotCount)
  {
    case 1:
      if (sTrackMarkerTable[0] == NULL)
    {
      if (gSaveTotalSlots)
      {
        func_80048794(0, gProbeObjectList);
      }
      else
      {
        func_80048794(0, gProbeObjectList);
      }
    }
      var_fv1_4 = (f64) 0;
      func_8004844C(sTrackMarkerTable[0], 160.0f, 120.0f, 320.0f, 240.0f, (f32) xOffset, (f32) yOffset);
      break;

    case 2:
      if (sTrackMarkerTable[0] == NULL)
    {
      func_80048794(0, gProbeObjectList);
    }
      if (sTrackMarkerTable[1] == NULL)
    {
      func_80048794(1, gProbeObjectList);
    }
      if (gBorderFlipFlag == 1)
    {
      temp_fs0_2 = 160.0f * 0.5f;
      func_8004844C(sTrackMarkerTable[0], temp_fs0_2, 120.0f, 160.0f, 2.0f * 120.0f, (unsigned short) 1.0f, 1.0f);
      var_a0_2 = sTrackMarkerTable[1];
      var_a2 = 120.0f;
      var_a1 = 160.0f + temp_fs0_2;
      var_a3 = 160.0f;
      height = 240.0f;
    }
    else
    {
      func_8004844C(sTrackMarkerTable[0], 160.0f, temp_fs0_3, temp_fs2 = 160.0f + 160.0f, 120.0f, 1.0f, 1.0f);
      temp_fs0_3 = 120.0f * 0.5f;
      var_a0_2 = sTrackMarkerTable[1];
      var_a1 = 160.0f;
      var_a3 = temp_fs2;
      height = 120.0f;
      var_a2 = 120.0f + temp_fs0_3;
    }
      block_74:
    func_8004844C(var_a0_2, var_a1, var_a2, var_a3, height, 1.0f, 1.0f);

      var_a0 = 0;
      block_75:
    func_800820B0(var_a0);

      break;

    case 3:
      if (sTrackMarkerTable[0] == NULL)
    {
      func_80048794(0, gProbeObjectList);
    }
      if (sTrackMarkerTable[1] == NULL)
    {
      func_80048794(1, gProbeObjectList);
    }
      if (sTrackMarkerTable[2] == NULL)
    {
      func_80048794(2, gProbeObjectList);
    }
      if (sTrackMarkerTable[3] == NULL)
    {
      func_80048794(3, gProbeObjectList);
    }
      ;
      temp_fs0_4 = 120.0f * 0.5f;
      func_8004844C(sTrackMarkerTable[0], 160.0f * 0.5f, temp_fs0_4, 160.0f, 120.0f, 1.0f, 1.0f);
      temp_fs3 = temp_fs2_2 + 160.0f;
      func_8004844C(sTrackMarkerTable[1], temp_fs3, temp_fs0_4, 160.0f, 120.0f, 1.0f, 1.0f);
      func_8004844C(sTrackMarkerTable[2], 160.0f * 0.5f, temp_fs0_4, 160.0f, 120.0f, 1.0f, 1.0f);
      temp_fs0_4 = 120.0f + temp_fs0_4;
      var_a0_2 = sTrackMarkerTable[3];
      var_a1 = temp_fs3;
      var_a3 = 160.0f;
      var_a2 = temp_fs0_4;
      height = 120.0f;
      goto block_74;

    case 4:
      if (sTrackMarkerTable[0] == NULL)
    {
      func_80048794(0, gProbeObjectList);
    }
      if (sTrackMarkerTable[1] == NULL)
    {
      func_80048794(1, gProbeObjectList);
    }
      if (sTrackMarkerTable[2] == NULL)
    {
      func_80048794(2, gProbeObjectList);
    }
      if (sTrackMarkerTable[3] == NULL)
    {
      func_80048794(3, gProbeObjectList);
    }
      ;
      temp_fs4 = 120.0f * 0.5f;
      temp_fs1 = 120.0f * 0.5f;
      func_8004844C(sTrackMarkerTable[0], 160.0f * 0.5f, temp_fs4, 160.0f, 120.0f, 1.0f, 1.0f);
      temp_fs3_2 = temp_fs2_3 + 160.0f;
      func_8004844C(sTrackMarkerTable[1], temp_fs3_2, temp_fs1, 160.0f, 120.0f, 1.0f, 1.0f);
      func_8004844C(sTrackMarkerTable[2], 160.0f * 0.5f, 120.0f + temp_fs4, 160.0f, 120.0f, 1.0f, 1.0f);
      var_a0_2 = sTrackMarkerTable[3];
      var_a1 = temp_fs3_2;
      var_a2 = 120.0f + temp_fs1;
      var_a3 = 160.0f;
      height = 120.0f;
      goto block_74;

  }

  *((s32 *) (((char *) sTrackMarkerTable[0]) + 0x100)) = (s32) ((*((s32 *) (((char *) sTrackMarkerTable[0]) + 0x100))) | 0x40);
  *((s8 *) (((char *) sTrackMarkerTable[0]) + 0x142)) = 4;
}

