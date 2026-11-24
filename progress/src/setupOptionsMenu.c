void *findEntryById(s32 *, s32);
void *findEntryPayload(s32 *, s32);
s32 formatTextEntry(void *, s32 *, s32);
s32 optionValueToSliderIndex(s32);
s32 setupMenuItemPair(void *, void *, void *, void *, s32, s32);
long formatTimeToScratchBuffer(s32 *);
s32 loadMapEntries(u8, u8);
s32 initSaveSlotMenus(void *, void *);
s32 lookupDataEntry(volatile long);
s32 menuSetItemLabelIndices(void *, void *, void *, void *, s32, s32);
s32 timerGetTotalSeconds(s32 *);
extern s32 D_8011AC34;
extern s32 D_8011AC94;
extern s32 D_800BD9A0;
extern u8 D_801002A4;
extern s32 gBonusGoalTarget;
extern s32 gMenuTimerSetting;
extern u8 D_801002D5;
extern s32 gMenuTimerOption;
extern s32 * volatile gMenuOptionTable;
extern u32 gMenuOptionIndex;
extern u8 gBorderFlipFlag;
extern s8 gMenuAnyController;
extern u8 gPauseFlag;
extern u8 gSaveKeyRelaxed;
extern s32 gSaveSlotCount;
extern u8 gSceneType;
extern u8 sDifficultyLevel;
extern s32 sFmtEntryName;
extern s32 D_800D2858;
extern s32 updateActorPartnerLink;
/* Builds the options/save menu: selects the option table by scene, formats label texts and links the menu items. */ void setupOptionsMenu(void)
{
  s32 *__base_D_801002A8;
  s32 *var_a1;
  s32 *optionTable;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a0_3;
  s16 var_v0_2;
  s32 *temp_s0;
  s32 nameId;
  s32 var_v0_4;
  s32 var_v0_5;
  u32 maxIndex;
  u32 optionCount;
  void *temp_a0;
  void *temp_a0_2;
  void *entryA;
  void *pauseItem;
  void *timeItem;
  void *keyItem;
  void *borderItem;
  void *entryB;
  void *entryC;
  void *var_a2_2;
  void *saveSlotItem; s32 la; s32 *fmtp;
  gMenuAnyController = 1;
  entryA = findEntryById(&D_800BD9A0, 0x5B);
  entryB = findEntryById(&D_800BD9A0, 0x5C);
  pauseItem = findEntryPayload(&D_800BD9A0, 0xE7);
  borderItem = findEntryPayload(&D_800BD9A0, 0x66);
  saveSlotItem = findEntryPayload(&D_800BD9A0, 0xB1);
  if (saveSlotItem == NULL)
  {
    saveSlotItem = findEntryPayload(&D_800BD9A0, 0x1AD);
  }
  keyItem = findEntryPayload(&D_800BD9A0, 0x16C);
  timeItem = findEntryPayload(&D_800BD9A0, 0x61);
  entryC = findEntryById(&D_800BD9A0, 0xC);
  gMenuTimerOption = optionValueToSliderIndex(gMenuTimerSetting);
  if (((((entryA != NULL) & (entryB != NULL)) && ((keyItem != NULL) & (borderItem != NULL))) && ((saveSlotItem != NULL) & (timeItem != NULL))) && ((pauseItem != NULL) & (entryC != NULL)))
  {
    switch (gSceneType)
    {
      case 5:

      case 6:
        optionTable = (s32 *) (((u8 *) (&updateActorPartnerLink)) + 0x1C4);
        if (gMenuOptionTable != optionTable)
      {
        gMenuOptionIndex = 0;
      }
        optionCount = 0x19;
        goto selected;

      case 2:

      case 3:

      case 4:
        optionTable = &D_8011AC34;
        if (gMenuOptionTable != optionTable)
      {
        gMenuOptionIndex = 0;
      }
        optionCount = 0x14;
        goto selected;

      case 7:
        optionTable = &D_8011AC94;
        if (gMenuOptionTable != optionTable)
      {
        gMenuOptionIndex = 9;
      }
        optionCount = 0xF;
        goto selected;

      default:
        optionTable = (s32 *) (((u8 *) (&updateActorPartnerLink)) + 0x180);
        if (gMenuOptionTable != optionTable)
      {
        gMenuOptionIndex = 0;
      }
        optionCount = 0xB;

    }

    selected:
    gMenuOptionTable = optionTable;

    *((u32 *) (((char *) saveSlotItem) + (-0x14))) = optionCount;
    if (gSceneType == 7) {
      *((s16 *)((char *)saveSlotItem - 0x28)) = 0x1AD;
    } else {
      *((s16 *)((char *)saveSlotItem - 0x28)) = 0xB1;
    }
    optionCount = gMenuOptionIndex;
    maxIndex = *((volatile u32 *) (((char *) saveSlotItem) - 0x14));
    if (maxIndex < optionCount)
    {
      gMenuOptionIndex = maxIndex;
    }
    __base_D_801002A8 = &gBonusGoalTarget;
    *__base_D_801002A8 = (s32) (*(((u16 *) gMenuOptionTable) + gMenuOptionIndex));
    initSaveSlotMenus(entryA, entryB);
    temp_s0 = ((s8 *) __base_D_801002A8) + 0x1C;
    loadMapEntries(D_801002A4, sDifficultyLevel);
    if ((timerGetTotalSeconds(temp_s0) << 0x10) != 0)
    {
      formatTextEntry(timeItem, &sFmtEntryName, formatTimeToScratchBuffer(temp_s0));
    }
    else
    {
      formatTextEntry(timeItem, &sFmtEntryName, lookupDataEntry(0x5F));
    }
    nameId = gBonusGoalTarget;
    if (nameId)
    {
      var_a1 = &D_800D2858;
      formatTextEntry(saveSlotItem, var_a1, nameId);
    }
    else
    {
      var_a1 = &sFmtEntryName;
      nameId = lookupDataEntry(0x5F);
      formatTextEntry(saveSlotItem, var_a1, nameId);
    }
    var_a0 = 0x67;
    if (gBorderFlipFlag != 0)
    {
      var_a0 = 0x68;
    }
    formatTextEntry(borderItem, ((s32 *) ((u8 *) &D_800D2858 + 0xC)), lookupDataEntry(var_a0));
    var_a0_2 = 0xA;
    if (D_801002D5) { var_a0_2 = 9; }
    formatTextEntry(keyItem, ((s32 *) ((u8 *) &D_800D2858 + 0xC)), lookupDataEntry(var_a0_2));
    switch (gPauseFlag) {
      case 1: formatTextEntry(pauseItem, ((s32 *) ((u8 *) &D_800D2858 + 0xC)), lookupDataEntry(0x2E2)); break;
      case 2: formatTextEntry(pauseItem, ((s32 *) ((u8 *) &D_800D2858 + 0xC)), lookupDataEntry(0x2E3)); break;
      case 0: la = 0xA; goto L;
      default: la = 0x2E4;
      L: formatTextEntry(pauseItem, &sFmtEntryName, lookupDataEntry(la)); break;
    }
    if (gSaveKeyRelaxed) {
      menuSetItemLabelIndices(keyItem - 0x28, keyItem, pauseItem - 0x28, timeItem - 0x28, 0x16C, 1);
    } else {
      setupMenuItemPair(keyItem - 0x28, keyItem, pauseItem - 0x28, timeItem - 0x28, 1, 0xD);
    }
    if (gSaveSlotCount == 2)
    {
      menuSetItemLabelIndices(borderItem - 0x28, borderItem, entryB, pauseItem - 0x28, 0x66, 1);
    }
    else
    {
      setupMenuItemPair(borderItem - 0x28, borderItem, entryB, pauseItem - 0x28, 1, 0xD);
    }
    if (gSceneType == 8)
    {
      setupMenuItemPair(saveSlotItem - 0x28, saveSlotItem, timeItem - 0x28, entryC, 1, 0xD);
      return;
    }
    if (gSceneType == 7)
    {
      menuSetItemLabelIndices(saveSlotItem - 0x28, saveSlotItem, timeItem - 0x28, entryC, 0x1AD, 1);
    }
    else
    {
      menuSetItemLabelIndices(saveSlotItem - 0x28, saveSlotItem, timeItem - 0x28, entryC, 0xB1, 1);
    }
  }
}
