s16 randomIntBelow(u32);
f32 approxDistance(void *, s32);
s32 func_80063DB4(void *);
extern u8 gSceneType;
extern s32 gSaveTotalSlots;
extern u32 gTrackMarkerCount;
extern u8 D_80100BE0[];
extern s32 gTrackMarkerIndex;
extern s32 gBonusObjects;
extern s32 gTrackMarkerPosTable;
inline static int inline_fn(u16 arg0)
{
  return arg0 & 0xFFFF;
}

void func_80063FE8(void *arg0)
{
  f32 temp_fv0;
  f32 var_fs0;
  f32 var_fs1;
  u16 temp_s1;
  s16 temp_v0;
  s16 temp_v0_2;
  s16 var_s0;
  s16 var_s0_2;
  
  s16 var_s4;
  u8 temp_v1;
  void *temp_s3;
  var_fs1 = -1.0f;
  temp_s3 = *((void **) (((char *) arg0) + 0x6C));
  temp_v1 = ((u32) (gSceneType - 2)) < 2U;
  var_s4 = 0;
  if (temp_v1 == 0)
  {
    loop_1:
    var_s0 = 0;

    temp_s1 = randomIntBelow(gTrackMarkerCount);
    if (gSaveTotalSlots > 0)
    {
      for (;;)
      {
        if ((var_s0 == (*((s8 *) (((char *) temp_s3) + 0x182))))) { temp_v0 = var_s0 + 1; goto next_slot; }
        temp_v0 = var_s0 + 1;
        if (!(!(approxDistance((inline_fn(temp_s1) * 0xC) + ((char *) (&gTrackMarkerPosTable)), (&gBonusObjects)[var_s0] + 0x24) < 3.0f))) goto loop_1;
        next_slot:
        var_s0 = temp_v0;
        if (temp_v0 >= gSaveTotalSlots) break;
      }

    }
    var_s4 = temp_s1;
  }
  else
  {
    temp_s1 = 0;
    if (gTrackMarkerCount != 0)
    {
      do
      {
        if ((temp_v1 == 0) || ((*(D_80100BE0 + inline_fn(temp_s1))) == (*((u8 *) (((char *) (*((void **) (((char *) temp_s3) + 0xB4)))) + 0x12)))))
        {
          var_fs0 = 4194304.0f;
          var_s0_2 = 0;
          if (gSaveTotalSlots > 0)
          {
            do
            {
              if (var_s0_2 != (*((s8 *) (((char *) temp_s3) + 0x182))))
              {
                temp_fv0 = approxDistance((inline_fn(temp_s1) * 0xC) + ((char *) (&gTrackMarkerPosTable)), (&gBonusObjects)[var_s0_2] + 0x24);
                if (temp_fv0 < var_fs0)
                {
                  do
                  {
                    var_fs0 = temp_fv0;
                  }
                  while (0);
                }
              }
              temp_v0_2 = var_s0_2 + 1;
              var_s0_2 = temp_v0_2;
            }
            while (temp_v0_2 < gSaveTotalSlots);
          }
          if (var_fs1 < var_fs0)
          {
            var_fs1 = var_fs0;
            var_s4 = temp_s1;
          }
        }
        temp_s1 += 1;
      }
      while (((u32) inline_fn(temp_s1)) < ((u32) gTrackMarkerCount));
    }
  }
  gTrackMarkerIndex = (s32) var_s4;
  func_80063DB4(arg0);
}

