#define FIELD(base, type, offset) (*(type *)((char *)(base) + (offset)))
#define SLOT_INDEX() FIELD(gSaveSlotInfo, s32, (getSaveSlotIndex((u16)FIELD(temp_s3, s8, 0x182)) & 0xFFFF) * 24)
extern s32 getSaveSlotIndex(s32);
extern f32 approxDistance(void *, void *);
extern s32 func_800158A4(void *, void *, s32, void *, s32, s32, s32, s32, s32);
extern s32 func_8007A9CC(void *, void *, void *, u32);
extern s32 func_801182B0(void *, void *);
extern u8 D_800BF688[];
extern u8 D_800BF68B[];
extern u8 gSaveSlotInfo[];
extern u8 sSaveSlotTable[];
extern u8 gSceneType[];
extern u8 sProbeActive[];
extern u8 D_8011F169[];
extern s16 sActorPartnerSlots[];
extern u32 gSaveTotalSlots;
extern void *D_8011ECB0[];
extern void *D_80102CD0[];
extern void *sBonusObjectTable[];
extern void *sProbeOriginTable[];
extern void *D_8010A410;
extern void *sTrackMarkerTable[];
inline static int inline_fn(int arg0)
{
  return arg0;
}

void *func_801183F4(void *arg0, u8 arg1)
{
  u32 sp28[4];
  u32 sp38[2];
  u8 sp47;
  void *sp4C;
  void *sp54;
  f32 temp_fs0;
  f32 var_fs0;
  f32 var_fs0_2;
  f32 var_fs1;
  f32 var_fs2;
  s16 temp_v0_2;
  s16 temp_v1_6;
  s16 var_a0_2;
  s16 var_a2;
  long temp_v1;
  s32 var_a3;
  s32 var_fp;
  s32 var_s5;
  s32 var_v0_2;
  s32 var_v0_3;
  s32 var_v0_4;
  s32 var_v0_6;
  s32 var_v0_7;
  s32 var_v0_8;
  u16 temp_v0;
  u16 temp_v1_2;
  int var_v0_5;
  u32 temp_v1_4;
  u32 var_s1;
  u32 var_s1_2;
  u8 temp_a1_2;
  u32 temp_s4;
  u8 temp_v1_3;
  u8 temp_v1_5;
  void **var_a0;
  void **var_s0;
  void *temp_a1;
  void *temp_s3;
  void *temp_s6;
  void *var_s0_2;
  void *var_s7;
  void *var_v0;
  temp_s3 = *((void **) (0x6C + ((char *) arg0)));
  sp47 = arg1;
  var_fs1 = 65536.0f;
  temp_s6 = D_8011ECB0[(*((u16 *) (((char *) D_800BF688) + (SLOT_INDEX() * 12)))) & 3];
  temp_v1 = SLOT_INDEX();
  var_s7 = NULL;
  sp4C = NULL;
  sp54 = NULL;
  temp_s4 = D_800BF68B[temp_v1 * 12];
  var_s5 = 0x270F;
  var_fs2 = 65536.0f;
  if (D_800BF68B[temp_v1 * 12] & 2)
  {
    var_s1 = 0;
    if (((u32) gSaveTotalSlots) > 0U)
    {
      var_a0 = D_80102CD0;
      do
      {
        temp_v1_2 = *((u16 *) (((char *) (*((void **) (((char *) (*var_a0)) + 0xB4)))) + 0xC));
        if (((s32) temp_v1_2) < var_s5)
        {
          var_s5 = (s32) temp_v1_2;
        }
        var_s1 += 1;
        var_a0++;
      }
      while (var_s1 < ((u32) gSaveTotalSlots));
    }
    if (var_s5 <= 0)
    {
      var_s5 = 1;
    }
  }
  var_s1_2 = 0;
  var_s0 = sBonusObjectTable;
  var_fp = 0;
  do
  {
    if ((((*var_s0) != NULL) && ((*var_s0) != arg0)) && (!((*((f32 *) (((char *) (*var_s0)) + 0x74))) <= 0.0f)))
    {
      temp_v0 = *((u16 *) (((char *) (*var_s0)) + 0x78));
      if ((((temp_v0 == 0x4D) | (temp_v0 == 0x61)) == 0) && (((temp_v1_3 = *((u8 *) (((char *) (*((void **) (((char *) temp_s3) + 0xB4)))) + 0x12)), temp_v1_3 == 2)) || (temp_v1_3 != (*((u8 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) (*var_s0)) + 0x6C)))) + 0xB4)))) + 0x12))))))
      {
        var_fs0 = approxDistance(arg0 + 0x24, (*var_s0) + 0x24) * (*((f32 *) (((char *) temp_s6) + 0x0)));
        if (((u32) (gSceneType[0] - 2)) < 2U)
        {
          if (1)
          {
            var_v0_2 = temp_s4 & 4;
          }
          if (sProbeOriginTable[*((u8 *) (((char *) (*((void **) (((char *) temp_s3) + 0xB4)))) + 0x12))] == (*var_s0))
          {
            var_fs0 *= 0.33333334f;
            goto block_18;
          }
        }
        else
        {
          block_18:
          var_v0_2 = temp_s4 & 4;

        }
        if (var_v0_2 != 0)
        {
          var_fs0 = (var_fs0 * 0.01f) * (*((f32 *) (((char *) (*var_s0)) + 0x74)));
        }
        var_v0_3 = temp_s4 & 2;
        var_v0_4 = temp_s4 & 8;
        if (var_v0_3 != 0)
        {
          var_v0_5 = *((u16 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) D_80102CD0) + var_fp)))) + 0xB4)))) + 0xC));
          if (((s32) var_v0_5) <= 0)
          {
            var_v0_5 = 1;
          }
          var_fs0 /= ((f32) var_v0_5) / ((f32) var_s5);
          var_v0_4 = temp_s4 & 8;
        }
        if ((var_v0_4 != 0) && (var_s1_2 == sActorPartnerSlots[*((s8 *) (((char *) temp_s3) + 0x182))]))
        {
          var_fs0 *= 0.25f;
        }
        if (var_fs0 < var_fs1)
        {
          var_fs1 = var_fs0;
          sp4C = *var_s0;
        }
        if ((((var_fs0 < 50.0f) && (((var_fs0 < 6.0f) || (temp_s4 & 1)) || (((func_8007A9CC(arg0, (*var_s0) + 0x24, &sp38, 0x448E38E4) << 22) << 2) != 0))) && ((func_800158A4(((char *) sTrackMarkerTable[*((s8 *) (((char *) temp_s3) + 0x182))]) + 0x10, (*var_s0) + 0x24, *((s32 *) (((char *) arg0) + 0x20)), &sp28, 0, 0, 0x20000, 1, 0) << 24) != 0)) && (var_fs0 < var_fs2))
        {
          var_fs2 = var_fs0;
          var_s7 = *var_s0;
        }
      }
    }
    var_s0++;
    var_s1_2 += 1;
    var_fp += 4;
  }
  while (var_s1_2 < 4U);
  if ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) == 0)
  {
    var_fs1 = 65536.0f;
    var_s7 = NULL;
    sp4C = NULL;
    sp47 = 1;
  }
  var_v0 = var_s7;
  if (var_s7 == NULL)
  {
    if (sp47 == 0)
    {
      do
      {
        return *((void **) (((char *) temp_s3) + 0xC0));
      }
      while (0);
    }
    var_s0_2 = D_8010A410;
    if (var_s0_2 != NULL)
    {
      do
      {
        var_fs0_2 = 1.0f;
        temp_v1_4 = (*((u16 *) (((char *) var_s0_2) + 0x78))) - 0x28;
        var_a3 = 0;
        switch (temp_v1_4)
        {
          case 0:

          case 45:
            if ((*((s16 *) (((char *) var_s0_2) + 0x7A))) == 3)
          {
            var_a3 = func_801182B0(temp_s3, var_s0_2);
          }
            var_fs0_2 = *((f32 *) (((char *) temp_s6) + 0x4));
            var_v0_6 = var_a3 & 0xFF;
            if ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) == 0)
          {
            var_fs0_2 = 0.01f;
          }
            break;

          case 1:
            var_fs0_2 = *((f32 *) (((char *) temp_s6) + 0x8));
            if ((*((s16 *) (((char *) arg0) + 0x7A))) != 7)
          {
            var_a3 = 1;
          }
            var_v0_7 = (*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) != 0;
            block_70:
          var_a3 &= -var_v0_7;

            goto block_75;

          case 25:
            if ((*((s16 *) (((char *) var_s0_2) + 0x7C))) != (*((u8 *) (((char *) (*((void **) (((char *) temp_s3) + 0xB4)))) + 0x12))))
          {
            var_a3 = 1;
          }
            var_fs0_2 = *((f32 *) (((char *) temp_s6) + 0xC));
            var_v0_6 = var_a3 & 0xFF;
            break;

          case 29:
            temp_a1_2 = *((u8 *) (((char *) (*((void **) (((char *) temp_s3) + 0xB4)))) + 0x12));
            if ((*((s16 *) (((char *) var_s0_2) + 0x7A))) == temp_a1_2)
          {
            if (sProbeOriginTable[1 - temp_a1_2] == arg0)
            {
              var_fs0_2 = 0.0f;
              var_a3 = 1;
              if (gSceneType[0] == 3)
              {
                temp_v1_5 = sProbeActive[temp_a1_2];
                var_a2 = 0;
                if (temp_v1_5 == 0)
                {
                  var_a0_2 = 0;
                  if (((s32) temp_v1_5) < ((s32) gSaveTotalSlots))
                  {
                    var_v0_8 = 0 << 0x10;
                    do
                    {
                      if (sSaveSlotTable[(var_v0_8 >> 16) * 24] == temp_a1_2)
                      {
                        var_a2 += 1;
                      }
                      do
                      {
                        temp_v0_2 = var_a0_2 + 1;
                      }
                      while (0);
                      var_a0_2 = temp_v0_2;
                      var_s5 = (u16) var_a0_2;
                      var_v0_8 = (((u32) var_s5) << 8) << 8;
                    }
                    while (temp_v0_2 < ((s32) gSaveTotalSlots));
                  }
                  var_a3 = 1 & (-(var_a2 != 1));
                }
              }
            }
          }
          else
            if (D_8011F169[inline_fn(-((s32) temp_a1_2))] != 0)
          {
            var_fs0_2 = *((f32 *) (((char *) temp_s6) + 0x10));
            var_a3 = 1;
          }
            var_v0_7 = (*((s16 *) (((char *) arg0) + 0x7A))) != 7;
            goto block_70;

          case 26:
            temp_v1_6 = *((s16 *) (((char *) var_s0_2) + 0x7A));
            if ((sProbeOriginTable[temp_v1_6] == 0) && (sProbeActive[temp_v1_6] == 0))
          {
            var_a3 = 1;
          }
            var_fs0_2 = *((f32 *) (((char *) temp_s6) + 0x14));
            goto block_75;

          default:
            block_75:
          var_v0_6 = var_a3 & 0xFF;


        }

        if (var_v0_6 != 0)
        {
          temp_fs0 = approxDistance(arg0 + 0x24, var_s0_2 + 0x24) * var_fs0_2;
          if (temp_fs0 < var_fs1)
          {
            var_fs1 = temp_fs0;
            var_s7 = var_s0_2;
          }
        }
        sp54 = var_s0_2;
        var_s0_2 = *((void **) (((char *) var_s0_2) + 0x10));
      }
      while (var_s0_2 != NULL);
    }
    var_v0 = var_s7;
    if (var_s7 == NULL)
    {
      var_v0 = sp4C;
      if (sp4C == NULL)
      {
        var_v0 = sp54;
      }
    }
    if (sSaveSlotTable)
    {
      return var_v0;
    }
    else
    {
      return var_v0;
    }
  }
  return var_v0;
}

