s32 actorSteerTowardTarget(void *, void *, s32, s32);
s32 func_80063C7C(s32);
s32 initObjectFromBankEntry(void *, s32, s32);
char *lookupDataEntry(u16);
s32 sprintf(char *, const char *, ...);
s16 strlen(s8 *);
extern s32 D_800BD660;
extern u8 D_801001A0[];
extern u8 D_8011508D[];
extern s32 D_8011F01C;
extern s32 D_8011F020;
extern s32 D_8011F02C;
extern s32 D_8011F034;
extern f64 D_8011F038;
extern s32 D_8011F15C;
extern s32 D_8011F2F8;
extern s32 D_8011F378;
extern s32 D_8011F3D0;
extern s32 D_8011F3E0;
extern s32 D_8011F3E8;
extern s32 gSaveTotalSlots;
extern u8 gSceneType;
extern s32 gVisibleSaveSlotCount;
extern s32 sBonusObjectTable;
extern s32 sEnemyDefTable;
extern s32 sSaveMenuColorActive;
extern s32 sSaveSlotInfo;
void func_8011DC18(void)
{
  int __repair_literal;
  register s32 var_a1;
  u8 slotLabel[2];
  register f32 temp_ft0;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  s16 *temp_a1_2;
  s32 temp_v0_2;
  s32 var_a3;
  s32 temp_a0_4;
  register s32 temp_a3;
  s32 temp_s2;
  s32 temp_s6;
  register s32 temp_v1_6;
  unsigned long var_s0;
  s32 var_s2;
  s32 var_s5;
  s32 var_v0;
  register s32 var_v0_3;
  u32 var_v1;
  short var_s1;
  u8 temp_s0;
  void **temp_a2;
  register void **temp_s0_5;
  void **temp_s4;
  void *temp_a0;
  register void *temp_a0_2;
  register void *temp_a0_3;
  void *temp_a0_5;
  void *temp_a1;
  register void *temp_s0_2;
  void *temp_s0_3;
  void *temp_s0_4;
  void *temp_s1;
  void *temp_s1_2;
  void *temp_s2_2;
  void *temp_s3;
  void *temp_v0;
  void *temp_v0_3;
  register void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_4;
  register void *temp_v1_5;
  void *temp_v1_7;
  var_s5 = 0;
  __repair_literal = 0;
  if (gVisibleSaveSlotCount > __repair_literal)
  {
    var_a3 = var_s5 & 0xFFFF;
    do
    {
      temp_v0 = *((void **) (((char *) (&sBonusObjectTable)) + (var_a3 * 4)));
      if (temp_v0 != NULL)
      {
        temp_s3 = *((void **) (((char *) temp_v0) + 0x6C));
        if (temp_s3 != NULL)
        {
          temp_a1 = *((void **) (((char *) temp_s3) + 0xB4));
          if ((*((u8 *) (((char *) temp_a1) + 0x12))) == 2)
          {
            do
            {
              sprintf((var_a3 * 0xC) + ((char *) (&D_8011F378)), &D_8011F01C, (*((u16 *) (((char *) temp_a1) + 0xC))) - (*((u16 *) (((char *) temp_a1) + 0xE))));
            }
            while (0);
            var_s0 = var_s5 & 0xFFFF;
          }
          else
          {
            slotLabel[0] = 12;
            slotLabel[1] = 5;
            temp_v1 = *((void **) (((char *) temp_s3) + 0xB4));
            do
            {
              sprintf((var_a3 * 0xC) + ((char *) (&D_8011F378)), &D_8011F020, (*((u16 *) (((char *) temp_v1) + 0xC))) - (*((u16 *) (((char *) temp_v1) + 0xE))), 5, slotLabel[*((u8 *) (((char *) temp_v1) + 0x12))], *((s16 *) (((char *) (&D_8011F15C)) + ((*((u8 *) (((char *) (*((void **) (((char *) temp_s3) + 0xB4)))) + 0x12))) * 2))));
            }
            while (0);
            var_s0 = var_s5 & 0xFFFF;
          }
          temp_s2 = var_s0 * 4;
          temp_s1 = *((void **) (((char *) (&D_8011F3D0)) + temp_s2));
          if (temp_s1 != NULL)
          {
            *((s16 *) (((char *) temp_s1) + 0x1C)) = strlen((var_s0 * 0xC) + ((char *) (&D_8011F378)));
          }
          temp_a2 = (void **) (((char *) (&D_8011F3E8)) + temp_s2);
          if (((*temp_a2) != NULL) && ((temp_a1_2 = (s16 *) (((char *) (&D_8011F3E0)) + (((u32) var_s0) * 2)), temp_v0_2 = *temp_a1_2, temp_v0_2 > 0)))
          {
            *temp_a1_2 = temp_v0_2 - 1;
            if ((*((f32 *) (((char *) ((void **) (&sBonusObjectTable))[var_s0]) + 0x74))) <= 0.0f)
            {
              *temp_a1_2 = 0;
            }
            if ((*temp_a1_2) < 0x20)
            {
              temp_v1_2 = *temp_a2;
              *((s32 *) (((char *) temp_v1_2) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_2) + 0x10))) & (~0xFF));
              temp_a0 = *temp_a2;
              *((s32 *) (((char *) temp_a0) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_a0) + 0x10))) | ((*temp_a1_2) * 8));
            }
            var_v0 = var_s5 & 0xFFFF;
            if ((*temp_a1_2) == 0)
            {
              temp_v1_3 = *temp_a2;
              *((s32 *) (((char *) temp_v1_3) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_3) + 0x28))) & (~0xFC)) | 0x1C);
              var_v0 = var_s5 & 0xFFFF;
            }
          }
          else
          {
            var_v0 = var_s5 & 0xFFFF;
          }
          temp_v0_3 = *((void **) (((char *) (*((void **) (((char *) (&sBonusObjectTable)) + (((s32) var_v0) * 4))))) + 0x68));
          var_s1 = 0;
          if (temp_v0_3 != NULL)
          {
            var_s1 = (s8) (*((u8 *) (((char *) temp_v0_3) + 0xE)));
          }
          temp_s2_2 = (((s16) var_s1) * 0xE8) + ((char *) (&sEnemyDefTable));
          temp_s0 = *((u8 *) (((char *) temp_s2_2) + 0x80));
          if ((*(D_8011508D + ((*((s8 *) (((char *) temp_s3) + 0x182))) * 0xA0))) != 0)
          {
            temp_v1_4 = *((void **) (((char *) temp_s3) + 0x418));
            *((s32 *) (((char *) temp_v1_4) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_4) + 0x10))) | 0xFF);
            *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x420)))) + 0x10)) = (*((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x420)))) + 0x10))) | 0xFF;
          }
          else
          {
            temp_v1_5 = *((void **) (((char *) temp_s3) + 0x418));
            *((s32 *) (((char *) temp_v1_5) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_5) + 0x10))) & (~0xFF));
            *((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x420)))) + 0x10)) = (*((s32 *) (((char *) (*((void **) (((char *) temp_s3) + 0x420)))) + 0x10))) & (~0xFF);
          }
          temp_v1_6 = var_s5 & 0xFFFF;
          temp_fv1 = ((f32) (D_8011F038 / (2.0 * ((f64) (*(D_801001A0 + (temp_v1_6 * 0x18))))))) * (*((f32 *) (((char *) (&sBonusObjectTable)[temp_v1_6]) + 0x74)));
          temp_a0_2 = *((void **) (((char *) temp_s3) + 0x478));
          *((u16 *) (((char *) temp_a0_2) + 0x26)) = (u32) temp_fv1;
          temp_fv1_2 = (*((f32 *) (((char *) temp_s3) + 0x60))) * 0.24f;
          temp_a0_3 = *((void **) (((char *) temp_s3) + 0x47C));
          *((s16 *) (((char *) temp_a0_3) + 0x26)) = (u32) temp_fv1_2;
          temp_v1_7 = *((void **) (((char *) temp_s3) + 0x478));
          if ((*((u16 *) (((char *) temp_v1_7) + 0x26))) == 0)
          {
            if ((*((f32 *) (((char *) (*((void **) (((var_s5 & 0xFFFF) * 4) + ((char *) (&sBonusObjectTable)))))) + 0x74))) > 0.0f)
            {
              *((u16 *) (((char *) temp_v1_7) + 0x26)) = 1U;
            }
          }
          var_v0_3 = var_s1 << 0x10;
          temp_a0_4 = var_v0_3 >> 0x10;
          if (temp_a0_4 != 0)
          {
            sprintf(*((s8 **) (((char *) (*((void **) (((char *) temp_s3) + 0x418)))) + 0x18)), &D_8011F02C, *((s8 *) (((char *) (temp_s3 + (((s32) (func_80063C7C(temp_a0_4) << 0x10)) >> 0xD))) + 0x1FF)), *((s16 *) (((char *) (temp_s3 - (-(temp_s0 * 2)))) + 0x1BC)));
          }
          else
          {
            *(*((s8 **) (((char *) (*((void **) (((char *) temp_s3) + 0x418)))) + 0x18))) = 0;
          }
          temp_s0_2 = *((void **) (((char *) temp_s3) + 0x418));
          *((s16 *) (((char *) temp_s0_2) + 0x1C)) = strlen(*((s8 **) (((char *) temp_s0_2) + 0x18)));
          if ((*((void **) (((char *) temp_s3) + 0x41C))) != NULL)
          {
            sprintf(*((s8 **) (((char *) (*((void **) (((char *) temp_s3) + 0x41C)))) + 0x18)), &D_8011F034, lookupDataEntry((var_s1 & 0xFFFF) | 0xA000));
            temp_s0_3 = *((void **) (((char *) temp_s3) + 0x41C));
            *((s16 *) (((char *) temp_s0_3) + 0x1C)) = strlen(*((s8 **) (((char *) temp_s0_3) + 0x18)));
          }
          sprintf(*((s8 **) (((char *) (*((void **) (((char *) temp_s3) + 0x420)))) + 0x18)), &D_8011F034, lookupDataEntry(*((u16 *) (((char *) (((*((u8 *) (((char *) (temp_s3 + ((((s32) (var_s1 << 0x10)) >> 5) >> 8))) + 0x1FD))) * 2) + temp_s2_2)) + 0x2C))));
          temp_s0_4 = *((void **) (((char *) temp_s3) + 0x420));
          temp_a3 = var_s5 & 0xFFFF;
          *((s16 *) (((char *) temp_s0_4) + 0x1C)) = strlen(*((s8 **) (((char *) temp_s0_4) + 0x18)));
          if ((*(((u8 *) (&sSaveSlotInfo)) + (temp_a3 * 0x18))) != 0)
          {
            var_s2 = 0;
            if (0 < gSaveTotalSlots)
            {
              var_v1 = 0 & 0xFFFF;
              temp_s6 = temp_a3 * 4;
              temp_s4 = (void **) (((char *) (&sBonusObjectTable)) + temp_s6);
              do
              {
                temp_a0_5 = (&sBonusObjectTable)[var_v1];
                if (temp_a0_5 != NULL)
                {
                  if (temp_a3 != var_v1)
                  {
                    temp_s1_2 = *((void **) (temp_s6 + ((var_v1 * 0x10) + ((char *) (&D_8011F2F8)))));
                    if (temp_s1_2 != NULL)
                    {
                      if (((u32) ((*((u16 *) (((char *) temp_a0_5) + 0x78))) - 2)) < 2U)
                      {
                        *((s32 *) (((char *) temp_s1_2) + 0x28)) = ((*((s32 *) (((char *) temp_s1_2) + 0x28))) & (~0xFC)) | 0xC;
                      }
                      else
                      {
                        *((s32 *) (((char *) temp_s1_2) + 0x28)) = ((*((s32 *) (((char *) temp_s1_2) + 0x28))) & (~0xFC)) | 0x1C;
                      }
                      temp_s0_5 = ((void **) (&sBonusObjectTable)) + (var_s2 & 0xFFFF);
                      actorSteerTowardTarget(temp_s1_2, *temp_s4, (*temp_s0_5) + 0x24, temp_a3);
                      temp_ft0 = *((f32 *) (((char *) (*temp_s0_5)) + 0x28));
                      temp_fv1_3 = *((f32 *) (((char *) (*temp_s4)) + 0x28));
                      if (temp_fv1_3 < (temp_ft0 - 1.0f))
                      {
                        var_a1 = 0x17;
                      }
                      else
                      {
                        var_a1 = 0x1A;
                        if (!((temp_ft0 + 1.0f) < temp_fv1_3))
                        {
                          var_a1 = 0x1B;
                        }
                      }
                      initObjectFromBankEntry(temp_s1_2, var_a1, 0x1B);
                      if (gSceneType == 8)
                      {
                        if ((*((u8 *) (((char *) (*((void **) (((char *) (*((void **) (((char *) (*((void **) (((var_s2 & 0xFFFF) * 4) + ((char *) (&sBonusObjectTable)))))) + 0x6C)))) + 0xB4)))) + 0x10))) != 0)
                        {
                          *((s32 *) (((char *) temp_s1_2) + 0x10)) = (s32) D_800BD660;
                        }
                        else
                        {
                          *((s32 *) (((char *) temp_s1_2) + 0x10)) = sSaveMenuColorActive;
                        }
                      }
                    }
                  }
                }
                var_s2 += 1;
                var_v1 = var_s2 & 0xFFFF;
              }
              while (((temp_s2 = var_s2) & 0xFFFF) < gSaveTotalSlots);
            }
          }
        }
      }
      var_s5++;
      var_a3 = var_s5 & 0xFFFF;
    }
    while ((var_s5 & 0xFFFF) < gVisibleSaveSlotCount);
  }
}

