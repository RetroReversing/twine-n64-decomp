inline static int __repair_inline(s32 a, s32 b)
{
  return a > b;
}

s32 initTextWidget();
s32 func_800162BC();
s32 setCursorMarker();
s32 updateTrackMarker();
s32 showTextPopup();
s32 func_80025D84();
s32 setupMenuItemPair();
s32 formatTextEntry();
s32 findEntryPayload();
s32 moveMenuSelection();
s32 initMenuWindow();
s32 appendWeightedListEntry();
s32 func_8002A9A8();
s32 setMenuActiveState();
u8 countValidSaveSlots();
s32 lookupDataEntry();
s32 sprintf();
extern char D_800D285C[];
extern char D_800D2864[];
extern u8 gCurrentSaveSlot;
extern u8 sMenuListKind;
extern s8 D_800BD690;
extern char D_800BD914[];
typedef struct 
{
  u8 f0;
  u8 pad[23];
} Slot_80100198;
extern Slot_80100198 D_80100198[];
extern u8 gPickupSavedByte;
extern char D_80100408[];
extern u8 D_801007C1;
extern u8 D_80102EB0;
extern u8 gValidSaveSlotCount;
extern char D_80102F48[];
extern u8 D_80104310;
extern u8 D_80108960;
extern void *gSaveMenuState;
extern u8 D_80109E20;
extern u8 D_8010A394;
extern char gPickupSearchBox[];
extern u8 D_8010D2B1;
extern u8 D_8010D454;
extern char gSlotTable[];
extern char gSlotMarkerActive[];
extern char D_8011508A[];
extern char D_8011508C[];
extern char D_8011508D[];
extern char D_8011508E[];
extern char gZoneModeEntries[];
extern char D_80115090[];
extern char D_80115091[];
extern s32 releaseMenuItemAndMarkers;
extern s32 bindMenuItemRecord;
/* Builds the pickup search menu: looks up its eight text widgets, fills them from the current save slot's flags, then registers the menu window and its per-slot list entries. */ void initPickupSearchMenuWidgets(void)
{
  s32 temp_a0;
  s32 widget6;
  s32 widget1;
  s32 temp_s2_2;
  s32 widget3;
  s32 widget5;
  s32 widget7;
  s32 __repair_result_temp_s5;
  s32 widget0;
  s32 widget4;
  s32 temp_v0_8;
  s32 temp_v1;
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a0_3;
  s32 var_a0_4;
  s32 var_a0_5;
  s32 var_a0_6;
  s32 var_a0_7;
  s32 var_a0_8;
  s32 var_a0_9;
  s32 var_a2;
  s32 var_a3;
  s32 widget2;
  s32 slotIdx;
  u32 slotIdxMasked;
  u8 temp_v0;
  u8 temp_v0_2;
  u8 temp_v0_3;
  u8 temp_v0_4;
  u8 temp_v0_5;
  u8 temp_v0_6;
  u8 temp_v0_7;
  s32 temp_v1_2;
  s32 temp_v1_3;
  char *menuEntryTable = D_800BD914;
  D_800BD690 = 1;
  widget0 = findEntryPayload(menuEntryTable, 0x78);
  widget1 = findEntryPayload(menuEntryTable, 0x79);
  widget2 = findEntryPayload(menuEntryTable, 0x7A);
  if (widget2 == 0)
  {
    widget2 = findEntryPayload(menuEntryTable, 0x13);
  }
  widget3 = findEntryPayload(menuEntryTable, 0x7B);
  widget4 = findEntryPayload(menuEntryTable, 0x7D);
  widget5 = findEntryPayload(menuEntryTable, 0x7C);
  widget6 = findEntryPayload(menuEntryTable, 0x162);
  widget7 = findEntryPayload(menuEntryTable, 0x7F);
  if (((((widget0 != 0) & (widget1 != 0)) && ((widget2 != 0) & (widget3 != 0))) && ((widget4 != 0) & (widget5 != 0))) && ((widget7 != 0) & (widget6 != 0)))
  {
    gCurrentSaveSlot = gPickupSavedByte;
    temp_v1 = gPickupSavedByte & 0xFF;
    D_80100198[temp_v1].f0 = *(D_80115091 + (temp_v1 * 0xA0));
    temp_v0 = *(gSlotTable + (gCurrentSaveSlot * 0xA0));
    D_80109E20 = temp_v0;
    var_a0 = 0x10;
    if (temp_v0 != 0)
    {
      var_a0 = 0xF;
    }
    __repair_rows:
    {
      {
        formatTextEntry(widget0, D_800D2864, lookupDataEntry(var_a0));
      }
    }

    if (0)
    {
      goto __repair_rows;
    }
    temp_v0_2 = *(gSlotMarkerActive + (gCurrentSaveSlot * 0xA0));
    D_8010D454 = temp_v0_2;
    var_a0_2 = 0xA;
    if (temp_v0_2 != 0)
    {
      var_a0_2 = 9;
    }
    formatTextEntry(widget1, D_800D2864, lookupDataEntry(var_a0_2));
    D_8010D2B1 = *(D_8011508A + (gCurrentSaveSlot * 0xA0));
    temp_v1_2 = D_80100198[gCurrentSaveSlot].f0;
    temp_a0 = widget2 - 0x28;
    if (((s32) __repair_inline(2, temp_v1_2)) && (((s32) temp_v1_2) >= 0))
    {
      setupMenuItemPair(temp_a0, widget2, widget1 - 0x28, widget3 - 0x28, 1, 0xD);
    }
    else
    {
      func_80025D84(temp_a0, widget2, widget1 - 0x28, widget3 - 0x28, 0x7A, 1);
      var_a0_3 = 0x11;
      if (D_8010D2B1 != 0)
      {
        var_a0_3 = 0x12;
      }
      formatTextEntry(widget2, D_800D2864, lookupDataEntry(var_a0_3));
    }
    temp_v0_3 = *(D_80115090 + (gCurrentSaveSlot * 0xA0));
    D_80102EB0 = temp_v0_3;
    var_a0_4 = 0xA;
    if (temp_v0_3 != 0)
    {
      var_a0_4 = 9;
    }
    formatTextEntry(widget3, D_800D2864, lookupDataEntry(var_a0_4));
    temp_v0_4 = *(D_8011508D + (gCurrentSaveSlot * 0xA0));
    D_801007C1 = temp_v0_4;
    var_a0_5 = 0xA;
    if (temp_v0_4 != 0)
    {
      var_a0_5 = 9;
    }
    {
      formatTextEntry(widget4, D_800D2864, lookupDataEntry(var_a0_5));
    }
    temp_v0_5 = *(D_8011508C + (gCurrentSaveSlot * 0xA0));
    D_8010A394 = temp_v0_5;
    var_a0_6 = 0xA;
    if (temp_v0_5 != 0)
    {
      var_a0_6 = 9;
    }
    formatTextEntry(widget5, D_800D2864, lookupDataEntry(var_a0_6));
    D_80108960 = *(gZoneModeEntries + (gCurrentSaveSlot * 0xA0));
    temp_v1_3 = D_80100198[gCurrentSaveSlot].f0;
    if (((s32) temp_v1_3) >= 0)
    {
      if (temp_v1_3)
      {
        var_a0_7 = widget6 - 0x28;
      }
      else
      {
        var_a0_7 = widget6 - 0x28;
      }
      if (((s32) temp_v1_3) >= 2)
      {
        if ((s32) __repair_inline(6, temp_v1_3))
        {
          if (((s32) temp_v1_3) >= 4)
          {
            var_a0_7 = widget6 - 0x28;
            goto block_27;
          }
          goto block_31;
        }
        goto block_30;
      }
      block_27:
      setupMenuItemPair(var_a0_7, widget6, widget5 - 0x28, widget7 - 0x28, 1, 0xD);

      if ((*((u8 *) (((char *) gSaveMenuState) + 8))) == 0xD)
      {
        moveMenuSelection(0x100, 2);
      }
    }
    else
    {
      var_a0_7 = widget6 - 0x28;
      block_30:
      block_31:
      func_80025D84(var_a0_7, widget6, widget5 - 0x28, widget7 - 0x28, 0x162, 1);


      var_a0_8 = 0xA;
      if (D_80108960 != 0)
      {
        var_a0_8 = 9;
      }
      formatTextEntry(widget6, D_800D2864, lookupDataEntry(var_a0_8));
    }
    temp_v0_6 = *(D_8011508E + (gCurrentSaveSlot * 0xA0));
    D_80104310 = temp_v0_6;
    var_a0_9 = 0xA;
    if (temp_v0_6 != 0)
    {
      var_a0_9 = 9;
    }
    formatTextEntry(widget7, D_800D2864, lookupDataEntry(var_a0_9));
    initMenuWindow(gPickupSearchBox, D_80100408, 0x1A4, 0xB, 0x25, 0xB4, 0x34, 0xE, 1, &bindMenuItemRecord, &releaseMenuItemAndMarkers);
    setCursorMarker(sMenuListKind, 0x23, 0x2C, 0x33, 0x9A);
    temp_v0_7 = countValidSaveSlots(0xA3);
    gValidSaveSlotCount = temp_v0_7;
    slotIdx = 0;
    if (temp_v0_7 & 0xFF)
    {
      do
      {
        slotIdxMasked = slotIdx & 0xFFFF;
        temp_v0_8 = func_800162BC(sMenuListKind);
        *((s32 *) ((slotIdxMasked * 4) + D_80102F48)) = temp_v0_8;
        if (temp_v0_8 != 0)
        {
          __repair_result_temp_s5 = lookupDataEntry((slotIdx + 0x400D) & 0xFFFF);
          if (slotIdxMasked < 4U)
          {
            var_a2 = lookupDataEntry(0xAD);
            var_a3 = slotIdxMasked + 1;
            sprintf(__repair_result_temp_s5, D_800D285C, var_a2, var_a3);
          }
          else
          {
            var_a2 = lookupDataEntry(0x158);
            var_a3 = slotIdxMasked - 3;
            sprintf(__repair_result_temp_s5, D_800D285C, var_a2, var_a3);
          }
          initTextWidget(*((s32 *) (((slotIdx & 0xFFFF) * 4) + D_80102F48)), __repair_result_temp_s5, 0x40);
        }
        appendWeightedListEntry(gPickupSearchBox, *((s32 *) (((slotIdx & 0xFFFF) * 4) + D_80102F48)), slotIdx & 0xFF, 1);
        slotIdx += 1;
      }
      while (((u32) (slotIdx & 0xFFFF)) < ((u8) gValidSaveSlotCount));
    }
    showTextPopup(sMenuListKind);
    updateTrackMarker(sMenuListKind);
    func_8002A9A8(gPickupSearchBox, gPickupSavedByte);
    setMenuActiveState(gPickupSearchBox, 1);
  }
}


