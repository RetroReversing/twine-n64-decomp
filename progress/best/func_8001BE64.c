void *findEntryById(s32 *, s32);
void *findEntryPayload(s32 *, s32);
s32 formatTextEntry(void *, s32 *, s32);
s32 func_80018BE0(s32);
s32 func_80025E9C(void *, void *, void *, void *, s32, s32);
long func_8002B248(s32 *);
s32 func_8003099C(u8, u8);
s32 initSaveSlotMenus(void *, void *);
s32 lookupDataEntry(volatile long);
s32 menuSetItemLabelIndices(void *, void *, void *, void *, s32, s32);
s32 timerGetTotalSeconds(s32 *);
extern s32 D_8011AC34;
extern s32 D_8011AC94;
extern s32 D_800BD9A0;
extern u8 D_801002A4;
extern s32 D_801002A8;
extern s32 D_801002C4;
extern u8 D_801002D5;
extern s32 D_801002F4;
extern s32 * volatile D_80102FD4;
extern u32 D_80117730;
extern u8 gBorderFlipFlag;
extern s8 gMenuNeedsRedraw;
extern u8 gPauseFlag;
extern u8 gSaveKeyRelaxed;
extern s32 gSaveSlotCount;
extern u8 gSceneType;
extern u8 sDifficultyLevel;
extern s32 sFmtEntryName;
extern s32 updateActorPartnerLink;
void func_8001BE64(void)
{
  s32 *__base_D_801002A8;
  s32 *var_a1;
  s32 *var_v1;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a0_3;
  s16 var_v0_2;
  s32 *temp_s0;
  s32 var_a2;
  s32 var_v0_4;
  s32 var_v0_5;
  u32 temp_v1;
  u32 var_v0;
  void *temp_a0;
  void *temp_a0_2;
  void *temp_fp;
  void *temp_s2;
  void *temp_s3;
  void *temp_s4;
  void *temp_s5;
  void *temp_s6;
  void *temp_s7;
  void *var_a2_2;
  void *var_s1;
  gMenuNeedsRedraw = 1;
  temp_fp = findEntryById(&D_800BD9A0, 0x5B);
  temp_s6 = findEntryById(&D_800BD9A0, 0x5C);
  temp_s2 = findEntryPayload(&D_800BD9A0, 0xE7);
  temp_s5 = findEntryPayload(&D_800BD9A0, 0x66);
  var_s1 = findEntryPayload(&D_800BD9A0, 0xB1);
  if (var_s1 == NULL)
  {
    var_s1 = findEntryPayload(&D_800BD9A0, 0x1AD);
  }
  temp_s4 = findEntryPayload(&D_800BD9A0, 0x16C);
  temp_s3 = findEntryPayload(&D_800BD9A0, 0x61);
  temp_s7 = findEntryById(&D_800BD9A0, 0xC);
  D_801002F4 = func_80018BE0(D_801002C4);
  if (((((temp_s6 != NULL) & (temp_fp != NULL)) && ((temp_s4 != NULL) & (temp_s5 != NULL))) && ((var_s1 != NULL) & (temp_s3 != NULL))) && ((temp_s2 != NULL) & (temp_s7 != NULL)))
  {
    switch (gSceneType)
    {
      case 5:

      case 6:
        do
      {
        var_v1 = (s32 *) (((u8 *) (&updateActorPartnerLink)) + 0x1C4); var_v0 = 0x19;
        if (D_80102FD4 != var_v1)
        {
          {
            long long phantom_wide = var_a0;
          }
          D_80117730 = 0;
        }
        break;
      }
      while (0);

      case 2:

      case 3:

      case 4:
 do { var_v1 = &D_8011AC34; var_v0 = 0x14; if (D_80102FD4 != (&D_8011AC34)) { { long long phantom_wide2 = var_a0; } D_80117730 = 0; } break; } while (0);

      case 7:
        var_v1 = &D_8011AC94;
        if (D_80102FD4 != (&D_8011AC94))
      {
        D_80117730 = 9;
      }
        var_v0 = 0xF;
        break;

      default:
        var_v1 = (s32 *) (((u8 *) (&updateActorPartnerLink)) + 0x180);
        var_v0 = 0xB;
        if (D_80102FD4 != var_v1)
      {
        D_80117730 = 0;
      }
        break;

    }

    D_80102FD4 = var_v1;
    *((u32 *) (((char *) var_s1) + (-0x14))) = var_v0;
    var_v0_2 = 0xB1;
    if (gSceneType == 7)
    {
      var_v0_2 = 0x1AD;
    }
    *((s16 *) (((char *) var_s1) + (-0x28))) = var_v0_2;
    temp_v1 = *((u32 *) (((char *) var_s1) + (-0x14)));
    if (temp_v1 < ((u32) D_80117730))
    {
      D_80117730 = temp_v1;
    }
    __base_D_801002A8 = &D_801002A8;
    *__base_D_801002A8 = (s32) (*(((u16 *) D_80102FD4) + D_80117730));
    initSaveSlotMenus(temp_fp, temp_s6);
    temp_s0 = ((s8 *) __base_D_801002A8) + 0x1C;
    func_8003099C(D_801002A4, sDifficultyLevel);
    if ((timerGetTotalSeconds(temp_s0) << 0x10) != 0)
    {
      formatTextEntry(temp_s3, &sFmtEntryName, func_8002B248(temp_s0));
    }
    else
    {
      formatTextEntry(temp_s3, &sFmtEntryName, lookupDataEntry(0x5F));
    }
    var_a2 = *__base_D_801002A8;
    if (var_a2)
    {
      var_a1 = "%d";
      formatTextEntry(var_s1, var_a1, var_a2);
    }
    else
      if (temp_s5)
    {
      var_a1 = &sFmtEntryName;
      var_a2 = lookupDataEntry(0x5F);
      formatTextEntry(var_s1, var_a1, var_a2);
    }
    else
    {
      var_a1 = &sFmtEntryName;
      var_a2 = lookupDataEntry(0x5F);
      formatTextEntry(var_s1, var_a1, var_a2);
    }
    var_a0 = 0x67;
    if (gBorderFlipFlag != 0)
    {
      var_a0 = 0x68;
    }
    formatTextEntry(temp_s5, &sFmtEntryName, lookupDataEntry(var_a0));
    var_a0_2 = 0xA;
    if (D_801002D5)
    {
      var_a0_2 = 9;
    }
    formatTextEntry(temp_s4, &sFmtEntryName, lookupDataEntry(var_a0_2));
    if (gPauseFlag != 1)
    {
      if ((((s32) gPauseFlag) + 1) <= 2)
      {
        var_a0_3 = 0xA;
        if (gPauseFlag)
        {
          var_a0_3 = 0x2E4;
        }
        block_41:
        var_v0_4 = lookupDataEntry(var_a0_3);

      }
      else
      {
        if (gPauseFlag != 2)
        {
          var_a0_3 = 0x2E4;
          goto block_41;
        }
        var_v0_4 = lookupDataEntry(0x2E3);
      }
    }
    else
    {
      var_v0_4 = lookupDataEntry(0x2E2);
    }
    formatTextEntry(temp_s2, &sFmtEntryName, var_v0_4);
    temp_a0 = temp_s4 - 0x28;
    if (gSaveKeyRelaxed)
    {
      menuSetItemLabelIndices(temp_a0, temp_s4, temp_s2 - 0x28, temp_s3 - 0x28, 0x16C, 1);
    }
    else
    {
      func_80025E9C(temp_a0, temp_s4, temp_s2 - 0x28, temp_s3 - 0x28, 1, 0xD);
    }
    temp_a0_2 = temp_s5 - 0x28;
    if (gSaveSlotCount == 2)
    {
      menuSetItemLabelIndices(temp_a0_2, temp_s5, temp_s6, temp_s2 - 0x28, 0x66, 1);
    }
    else
    {
      func_80025E9C(temp_a0_2, temp_s5, temp_s6, temp_s2 - 0x28, 1, 0xD);
    }
    if (gSceneType == 8)
    {
      func_80025E9C(var_s1 - 0x28, var_s1, temp_s3 - 0x28, temp_s7, 1, 0xD);
      return;
    }
    if (gSceneType == 7)
    {
      var_a2_2 = temp_s3 - 0x28;
      var_v0_5 = 0x1AD;
      menuSetItemLabelIndices(var_s1 - 0x28, var_s1, var_a2_2, temp_s7, var_v0_5, 1);
    }
    else
    {
      do
      {
        ;
        var_a2_2 = temp_s3 - 0x28;
        menuSetItemLabelIndices(var_s1 - 0x28, var_s1, var_a2_2, temp_s7, 0xB1, 1);
      }
      while (0);
    }
  }
}
