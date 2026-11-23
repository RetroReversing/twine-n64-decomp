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
extern s32 D_800D2858;
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
  void *var_s1; s32 la; s32 *fmtp;
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
  if (((((temp_fp != NULL) & (temp_s6 != NULL)) && ((temp_s4 != NULL) & (temp_s5 != NULL))) && ((var_s1 != NULL) & (temp_s3 != NULL))) && ((temp_s2 != NULL) & (temp_s7 != NULL)))
  {
    switch (gSceneType)
    {
      case 5:

      case 6:
        var_v1 = (s32 *) (((u8 *) (&updateActorPartnerLink)) + 0x1C4);
        if (D_80102FD4 != var_v1)
      {
        D_80117730 = 0;
      }
        var_v0 = 0x19;
        goto selected;

      case 2:

      case 3:

      case 4:
        var_v1 = &D_8011AC34;
        if (D_80102FD4 != var_v1)
      {
        D_80117730 = 0;
      }
        var_v0 = 0x14;
        goto selected;

      case 7:
        var_v1 = &D_8011AC94;
        if (D_80102FD4 != var_v1)
      {
        D_80117730 = 9;
      }
        var_v0 = 0xF;
        goto selected;

      default:
        var_v1 = (s32 *) (((u8 *) (&updateActorPartnerLink)) + 0x180);
        if (D_80102FD4 != var_v1)
      {
        D_80117730 = 0;
      }
        var_v0 = 0xB;

    }

    selected:
    D_80102FD4 = var_v1;

    *((u32 *) (((char *) var_s1) + (-0x14))) = var_v0;
    if (gSceneType == 7) {
      *((s16 *)((char *)var_s1 - 0x28)) = 0x1AD;
    } else {
      *((s16 *)((char *)var_s1 - 0x28)) = 0xB1;
    }
    var_v0 = D_80117730;
    temp_v1 = *((volatile u32 *) (((char *) var_s1) - 0x14));
    if (temp_v1 < var_v0)
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
    var_a2 = D_801002A8;
    if (var_a2)
    {
      var_a1 = &D_800D2858;
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
    formatTextEntry(temp_s5, ((s32 *) ((u8 *) &D_800D2858 + 0xC)), lookupDataEntry(var_a0));
    var_a0_2 = 0xA;
    if (D_801002D5) { var_a0_2 = 9; }
    formatTextEntry(temp_s4, ((s32 *) ((u8 *) &D_800D2858 + 0xC)), lookupDataEntry(var_a0_2));
    switch (gPauseFlag) {
      case 1: formatTextEntry(temp_s2, ((s32 *) ((u8 *) &D_800D2858 + 0xC)), lookupDataEntry(0x2E2)); break;
      case 2: formatTextEntry(temp_s2, ((s32 *) ((u8 *) &D_800D2858 + 0xC)), lookupDataEntry(0x2E3)); break;
      case 0: la = 0xA; goto L;
      default: la = 0x2E4;
      L: formatTextEntry(temp_s2, &sFmtEntryName, lookupDataEntry(la)); break;
    }
    if (gSaveKeyRelaxed) {
      menuSetItemLabelIndices(temp_s4 - 0x28, temp_s4, temp_s2 - 0x28, temp_s3 - 0x28, 0x16C, 1);
    } else {
      func_80025E9C(temp_s4 - 0x28, temp_s4, temp_s2 - 0x28, temp_s3 - 0x28, 1, 0xD);
    }
    if (gSaveSlotCount == 2)
    {
      menuSetItemLabelIndices(temp_s5 - 0x28, temp_s5, temp_s6, temp_s2 - 0x28, 0x66, 1);
    }
    else
    {
      func_80025E9C(temp_s5 - 0x28, temp_s5, temp_s6, temp_s2 - 0x28, 1, 0xD);
    }
    if (gSceneType == 8)
    {
      func_80025E9C(var_s1 - 0x28, var_s1, temp_s3 - 0x28, temp_s7, 1, 0xD);
      return;
    }
    if (gSceneType == 7)
    {
      menuSetItemLabelIndices(var_s1 - 0x28, var_s1, temp_s3 - 0x28, temp_s7, 0x1AD, 1);
    }
    else
    {
      menuSetItemLabelIndices(var_s1 - 0x28, var_s1, temp_s3 - 0x28, temp_s7, 0xB1, 1);
    }
  }
}
