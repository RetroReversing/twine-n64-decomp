s32 stopAllAudio();
s32 initMenuSlot(s32, s32);
s32 destroyMenuCursor();
s32 freeBonusObject();
s32 closeSaveMenu();
s32 initSlotRecord(s32 *, s32);
s32 getItemTableByte(s32);
s32 loadMapEntries(u8, u8);
s32 requestSceneChange(u8);
s32 getSaveSlotIndex(s32);
typedef struct 
{
  u16 *id;
  s32 pad[2];
} ItemEntry;
typedef struct 
{
  s32 id;
  s32 pad[5];
} SlotEntry;
extern ItemEntry gAssetSlotTable[];
extern s8 gBonusMarkerActive;
extern u8 D_801002A4;
extern s8 gBonusGoalReached;
extern s32 gMenuTimerSetting;
extern s32 D_801002C8;
extern s32 D_801002D0;
extern s8 gMenuStateIndex;
extern u8 gCurrentItemId;
extern s32 gSceneChangePending;
extern volatile s32 D_80102EF0;
extern s32 D_801176D8;
extern s32 D_801176DC;
extern s16 D_801176E0;
extern s16 D_801176E2;
extern s16 D_801176E4;
extern s32 gBorderSkipActive;
extern s8 gMenuUseTextList;
extern s8 gPendingMenuCommand;
extern volatile s8 gPickupSavedByte;
extern SlotEntry gSaveSlotInfo[];
extern volatile s32 gSaveTotalSlots;
extern s16 gSharedItemId[];
extern void *sActiveMenu;
extern u8 sDifficultyLevel;
extern s32 sProbeTimer;
extern s32 sRaceTimer;
/* Sets up the menu/bonus state: resets probe and race timers, fills the shared item ids from the save slots, then reloads map entries. */ void enterBonusMenuState(void)
{
  s16 menuState;
  s32 var_a0;
  s32 slotOffset;
  s32 idx;
  u8 itemId;
  u8 *__base_D_801002A4;
  __base_D_801002A4 = &D_801002A4;
  gMenuUseTextList = 1;
  if (gSceneChangePending == 0)
  {
    if ((sActiveMenu != NULL) && ((menuState = *((s16 *) (((char *) sActiveMenu) + 0x7A)), menuState != 0xF)))
    {
      if (menuState != 0xE)
      {
        *((s16 *) (((char *) sActiveMenu) + 0x7A)) = 0xE;
      }
    }
    else
    {
      idx = 0;
      D_801176D8 = 0;
      D_801176DC = 0;
      D_801176E0 = 0;
      D_801176E2 = 0;
      D_801176E4 = 0;
      gMenuStateIndex = 0xB;
      do
      {
        initMenuSlot((u16) idx, 0);
        idx += 1;
      }
      while (((u32) (idx & 0xFFFF)) < 4U);
      initSlotRecord(&sProbeTimer, 0x1E);
      if (gBorderSkipActive != 0)
      {
        do
        {
          gBonusGoalReached = 0;
        }
        while (0);
        gBonusMarkerActive = 0;
        gPickupSavedByte = 0;
 do { s32 timer = gMenuTimerSetting; s32 other = D_801002C8; sRaceTimer = timer; D_801002D0 = other; } while (0);
 { s32 slotCount = gSaveTotalSlots; D_80102EF0 = 0; do { idx = 0; } while (0);
        if (slotCount > 0)
        {
          s16 *sharedItems = gSharedItemId;
          do
          {
            s32 slot;
            s16 *out;
            s32 itemIdx;
            slotOffset = (u16) idx;
            slot = getSaveSlotIndex(slotOffset);
            slotOffset *= 2;
            itemIdx = getItemTableByte(gSaveSlotInfo[(u16) slot].id);
            out = (s16 *) (slotOffset + ((int) sharedItems));
            *out = *gAssetSlotTable[itemIdx].id;
            idx += 1;
          }
          while (((s32) ((u16) idx)) < gSaveTotalSlots);
        }
 }
        gSharedItemId[(u16) idx] = -1;
        itemId = *((volatile u8 *) __base_D_801002A4);
      }
      else
      {
        itemId = gCurrentItemId;
        D_80102EF0 = 1;
      }
      requestSceneChange(itemId);
      gPendingMenuCommand = 0;
      closeSaveMenu();
      stopAllAudio();
      destroyMenuCursor();
      freeBonusObject();
      loadMapEntries(gCurrentItemId, sDifficultyLevel);
    }
  }
}
