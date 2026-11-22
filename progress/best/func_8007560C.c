s32 func_80048794(unsigned int, s32);
unsigned int func_800820B0(volatile unsigned char);
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
inline static float inline_fn(float arg0, float arg1)
{
  return arg0 * arg1;
}

inline static unsigned int inline_fn2()
{
  return (unsigned short) 1.0f;
}

inline static u8 inline_fn23(u8 *arg0)
{
  return *arg0;
}

inline static char *inline_fn234(char *arg0)
{
  return arg0 + 0;
}

void func_8007560C(void)
{
  s32 var_a0;
  f32 temp_fs0_2;
  f32 __repair_phase_temp_fs0_2;
  u32 temp_v1;
  f32 temp_fs0_5;
  f32 temp_fs1;
  f32 temp_fs2;
  f32 temp_fs2_2;
  f32 temp_fs2_3;
  f32 temp_fs3;
  f32 temp_fs3_2;
  f32 temp_fs0_3;
  register f32 temp_fs4;
  f32 var_a1;
  f32 var_a2;
  f32 __repair_var_a2_1;
  register f32 var_a3;
  f64 temp_fs0;
  f64 var_fv0;
  register f64 var_fv1;
  s32 var_s0;
  f64 var_fv1_2;
  f64 var_fv1_3;
  f64 var_fv1_4;
  s32 var_v1;
  void **var_s1;
  void *temp_s4;
  void *temp_v1_2;
  void *var_a0_2;
  unsigned long offsetSeed = 0;
  unsigned int xOffset;
  unsigned int yOffset = 0;
  f32 height;
  f32 centerX = 160.0f;
  f32 centerY = 120.0f;
  xOffset = offsetSeed;
  {
    
  }
  if (osTvType)
  {
    {
      
    }
    xOffset = yOffset;
  }
  if (gMenuRootObject == NULL)
  {
    if (sTrackMarkerTable)
    {
      func_80048794(4, gProbeObjectList);
    }
    else
    {
      func_80048794(4, gProbeObjectList);
    }
  }
  func_8004844C(gMenuRootObject, centerX, centerY, 320.0f, 240.0f, (f32) (var_fv1 = (f64) xOffset), (f32) (s32)yOffset);
  *((u8 *) (((char *) (&D_8010A4C3)) + 0)) = (u8) ((*((u8 *) inline_fn234((char *) (&D_8010A4C3)))) & 0xEF);
  *((u8 *) (((char *) (&D_8010A4C3)) + (-2))) = (u8) ((*((u8 *) (((char *) (&D_8010A4C3)) + (-2)))) & 0xEF);
  *((s32 *) (((char *) gMenuRootObject) + 0x100)) = (s32) ((*((s32 *) (((char *) gMenuRootObject) + 0x100))) | 0x100);
  if (D_8010969C == NULL)
  {
    func_80048794(5, gProbeObjectList);
  }
  func_8004844C(D_8010969C, centerX, centerY, 320.0f, 240.0f, (f32) (var_fv1_2 = (f64) xOffset), (f32) (s32)yOffset);
  *((u8 *) (((char *) (&D_8010A4C3)) + 0)) = (u8) (inline_fn23((u8 *) inline_fn234((char *) (&D_8010A4C3))) & 0xDF);
  *((u8 *) (((char *) (&D_8010A4C3)) + (-2))) = (u8) ((*((u8 *) (((char *) (&D_8010A4C3)) + (-2)))) & 0xDF);
  gSceneFlagsB |= 0x20;
  *((s32 *) (((char *) D_8010969C) + 0x100)) = (s32) ((*((s32 *) (((char *) D_8010969C) + 0x100))) | 0x100);
  if (gBorderSkipActive == 0)
  {
    if (sTrackMarkerTable[0] == NULL)
    {
      func_80048794(0, gProbeObjectList);
    }
    if (gMenuRootObject)
    {
      var_fv1_3 = (f64) 0;
      func_8004844C(sTrackMarkerTable[0], centerX, centerY, 320.0f, 240.0f, (f32) xOffset, (f32) yOffset);
      var_a0 = 1;
      goto block_75;
    }
    else
    {
      var_fv1_3 = (f64) 0;
      func_8004844C(sTrackMarkerTable[0], centerX, centerY, 320.0f, 240.0f, (f32) xOffset, (f32) yOffset);
      var_a0 = 1;
      goto block_75;
    }
  }
  if ((s32)yOffset < gSaveTotalSlots)
  {
    var_s0 = 0;
    temp_fs0 = D_800D48D0;
    {
      temp_s4 = ((char *) (&D_8010A4C3)) - 1;
    }
    var_s1 = (void **) (((char *) (&gMenuRootObject)) - 0x10);
    do
    {
      if ((*var_s1) == NULL)
      {
        func_80048794(var_s0, gProbeObjectList);
        var_fv0 = (f64) 0;
        do
        {
          func_8004844C(*var_s1, centerX, centerY, centerX + centerX, centerY + centerY, (f32) xOffset, (f32) yOffset);
        }
        while (0);
        if (var_s0 >= gVisibleSaveSlotCount)
        {
          var_v1 = 1 << var_s0;
          if ((gVisibleSaveSlotCount == 3) & (var_s0 == 3))
          {
            *((u8 *)&D_8010A4C3) |= var_v1;
          }
          else
          {
            *((u8 *) inline_fn234((char *) (&D_8010A4C3))) = (u8) ((*((u8 *) inline_fn234((char *) (&D_8010A4C3)))) & (~(1 << var_s0)));
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
          *((u8 *) inline_fn234((char *) (&D_8010A4C3))) = (u8) ((*((u8 *) inline_fn234((char *) (&D_8010A4C3)))) | (1 << var_s0));
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
      func_8004844C(sTrackMarkerTable[0], centerX, centerY, centerX + centerX, centerY + centerY, (f32) xOffset, (f32) yOffset);
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
      __repair_phase_temp_fs0_2 = inline_fn(centerX, 0.5f);
      func_8004844C(sTrackMarkerTable[0], __repair_phase_temp_fs0_2, centerY, centerX, centerY + centerY, 1.0f, 1.0f);
      var_a0_2 = sTrackMarkerTable[1];
      __repair_var_a2_1 = centerY;
      var_a1 = centerX + __repair_phase_temp_fs0_2;
      var_a3 = centerX;
      height = centerY + centerY;
    }
    else
    {
      temp_fs0_3 = inline_fn(centerY, 0.5f);
      temp_fs2 = centerX + centerX;
      func_8004844C(sTrackMarkerTable[0], centerX, temp_fs0_3, temp_fs2, centerY, 1.0f, 1.0f);
      var_a0_2 = sTrackMarkerTable[1];
      var_a1 = centerX;
      var_a3 = temp_fs2;
      height = centerY;
      __repair_var_a2_1 = centerY + temp_fs0_3;
    }
      block_74:
    func_8004844C(var_a0_2, var_a1, __repair_var_a2_1, var_a3, height, 1.0f, 1.0f);

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
      temp_fs0_2 = inline_fn(centerY, 0.5f);
      func_8004844C(sTrackMarkerTable[0], inline_fn(centerX, 0.5f), temp_fs0_2, centerX, centerY, 1.0f, 1.0f);
      temp_fs3 = inline_fn(centerX, 0.5f) + centerX;
      func_8004844C(sTrackMarkerTable[1], temp_fs3, temp_fs0_2, centerX, centerY, 1.0f, 1.0f);
      func_8004844C(sTrackMarkerTable[2], inline_fn(centerX, 0.5f), temp_fs0_2, centerX, centerY, 1.0f, 1.0f);
    {
      temp_fs0_2 = centerY + temp_fs0_2; var_a0_2 = sTrackMarkerTable[3]; var_a1 = temp_fs3; var_a3 = centerX; __repair_var_a2_1 = temp_fs0_2; height = centerY;
    }
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
      temp_fs4 = inline_fn(centerY, 0.5f);
      temp_fs1 = inline_fn(centerY + centerY, 0.5f);
      func_8004844C(sTrackMarkerTable[0], inline_fn(centerX, 0.5f), temp_fs4, centerX, centerY, 1.0f, 1.0f);
      ;
      func_8004844C(sTrackMarkerTable[1], (temp_fs3_2 = inline_fn(centerX, 0.5f) + centerX), temp_fs1, centerX, centerY, 1.0f, 1.0f);
      func_8004844C(sTrackMarkerTable[2], inline_fn(centerX, 0.5f), (centerY + temp_fs4), centerX, centerY, 1.0f, 1.0f);
      var_a0_2 = sTrackMarkerTable[3];
      var_a1 = temp_fs3_2;
      __repair_var_a2_1 = centerY + temp_fs1;
      var_a3 = centerX;
      height = centerY;
      goto block_74;

  }

  *((s32 *) (((char *) sTrackMarkerTable[0]) + 0x100)) = (s32) ((*((s32 *) (((char *) sTrackMarkerTable[0]) + 0x100))) | 0x40);
  *((s8 *) (((char *) sTrackMarkerTable[0]) + 0x142)) = 4;
}


