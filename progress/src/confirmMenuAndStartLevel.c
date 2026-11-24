s32 stopDistanceSoundWrapper();
s32 requestSound();
s32 startSceneIfReset();
s32 initMenuSlot();
s32 func_80022DBC();
s32 setSaveMenuState();
s32 isMenuButtonPressed();
s32 updateActiveMenuState();
s32 clearEntryHeader();
s32 getItemTableByte();
s32 loadMapEntries();
s32 requestSceneChange();
s32 clearBonusSlotValue();
extern char gSharedItemId[];
extern s8 D_800BD690;
extern s16 gSaveStatus;
extern char gAssetSlotTable[];
extern s8 gSkipActorSpawns;
extern char gSaveSlotInfo[];
extern s8 gBonusMarkerActive;
extern u8 D_801002A4;
extern s8 gBonusGoalReached;
extern s8 D_801002AD;
extern int gSaveTotalSlots;
extern s32 gMenuTimerSetting;
extern s32 D_801002C8;
extern s32 D_801002CC;
extern s32 D_801002D0;
extern s16 D_80102CBC;
extern s16 D_80102CBE;
extern s16 D_80102CC0;
extern s32 gBorderSkipFlag;
extern s8 D_80102EDD;
extern u8 gCurrentItemId;
extern u8 D_80102EE8;
extern s32 D_80102EF0;
extern char D_80102EFC[];
extern void *sActiveMenu;
extern void *gSaveMenuState;
extern s32 gSceneLoaded;
inline static u8 *inline_fn(int arg0)
{
  return (u8 *) (((char *) gSaveMenuState) + arg0);
}

inline static char *inline_fn2(void *arg0)
{
  return (char *) arg0;
}

/* Confirms the highlighted menu entry, resets per-run state and starts the mode/level for the current item. */ void confirmMenuAndStartLevel(void)
{
  char *__base_D_800C3CF8;
  void *entry;
  s32 slotIdx;
  unsigned playerIdx;
  register s32 nextMode;
  entry = *((void **) (inline_fn2(gSaveMenuState) + 0x18));
  *((u8 *) (inline_fn2(entry) + 0x1C)) |= 0x10;
  if (isMenuButtonPressed(0x23) & 0xFF)
  {
    *((u8 *) (((char *) gSaveMenuState) + 0x2C)) = 1;
    *((s8 *) (((char *) gSaveMenuState) + 0x2F)) = 1;
  }
  if ((*inline_fn(0x2C)) == 0)
  {
    updateActiveMenuState();
    return;
  }
  if (((*((s32 *) (inline_fn2(*((void **) (((char *) gSaveMenuState) + 0x18))) + 0x14))) != 0) && (gSaveTotalSlots < 2))
  {
    *inline_fn(0x2C) = 0;
    requestSound(0xEA);
    return;
  }
  if ((sActiveMenu != NULL) && ((*((s16 *) (inline_fn2(sActiveMenu) + 0x7A))) != 0xF))
  {
    if ((*((s16 *) (inline_fn2(sActiveMenu) + 0x7A))) != 0xE)
    {
      *((s16 *) (((char *) sActiveMenu) + 0x7A)) = 0xE;
      gSaveStatus = 0x60;
      setSaveMenuState(sActiveMenu, 0x18);
      D_800BD690 = 0;
    }
  }
  else
  {
    loadMapEntries(gCurrentItemId, D_80102EE8);
    D_80102EDD = 1;
    entry = *((void **) (inline_fn2(gSaveMenuState) + 0x18));
    if ((*((s32 *) (inline_fn2(entry) + 0x10))) != 0)
    {
      gBorderSkipFlag = *((s32 *) (inline_fn2(entry) + 0x14));
    }
    if (gBorderSkipFlag != 0)
    {
      if (sActiveMenu)
      {
        gBonusGoalReached = 0;
        gBonusMarkerActive = 0;
        D_801002AD = 0;
      }
      else
      {
        gBonusGoalReached = 0;
        gBonusMarkerActive = 0;
        D_801002AD = 0;
      }
      if (sActiveMenu)
      {
        D_801002CC = gMenuTimerSetting;
        D_801002D0 = D_801002C8;
      }
      else
      {
        D_801002CC = gMenuTimerSetting;
        D_801002D0 = D_801002C8;
      }
      slotIdx = 0;
D_80102EF0 = 0;

      if (gSaveTotalSlots > 0)
      {
        do
        {
          s32 row = func_80022DBC((u16) slotIdx);
          s32 key = *((s32 *) (((((u16) row) * 3) << 3) + ((u32) gSaveSlotInfo)));
          s32 index = getItemTableByte(key);
          *((s16 *) (gSharedItemId + (((u16) slotIdx) * 2))) = *(*((u16 **) (gAssetSlotTable + ((index * 3) << 2))));
          slotIdx++;
        }
        while ((slotIdx & 0xFFFF) < gSaveTotalSlots);
      }
      *((s16 *) (gSharedItemId + ((slotIdx & 0xFFFF) * 2))) = -1;
      playerIdx = 0;
    }
    else
    {
      D_80102EF0 = 1;
      playerIdx = 0;
    }
    do
    {
      clearBonusSlotValue(playerIdx & 0xFFFF);
      initMenuSlot(playerIdx & 0xFFFF, 0);
      playerIdx++;
    }
    while ((playerIdx & 0xFFFF) < 4);
    clearEntryHeader(D_80102EFC);
    stopDistanceSoundWrapper();
    D_80102CBC = 0;
    D_80102CBE = 0;
    D_80102CC0 = 0;
    gSceneLoaded = 0;
    if (gBorderSkipFlag != 0)
    {
      gSkipActorSpawns = 0;
      requestSceneChange(D_801002A4);
      return;
    }
    switch (gCurrentItemId)
    {
      default:
        gSkipActorSpawns = 0;
        nextMode = -1;
        requestSceneChange(gCurrentItemId);
        break;

      case 2:
        nextMode = 4;
        break;

      case 20:
        nextMode = 0x10;
        break;

      case 16:
        nextMode = 0xE;
        break;

      case 34:
        nextMode = 0x22;
        break;

      case 25:
        nextMode = 0x11;
        break;

      case 38:
        nextMode = 0x2C;
        break;

      case 1:
        nextMode = 1;
        break;

      case 11:
        nextMode = 8;
        break;

      case 41:
        nextMode = 0x2F;
        break;

      case 40:
        nextMode = 0x31;
        break;

      case 28:
        nextMode = 0xC;
        break;

      case 18:
        nextMode = 0x25;
        break;

      case 29:
        nextMode = 0x18;
        break;

      case 33:
        nextMode = 0x1A;
        break;

    }

    if (nextMode >= 0)
    {
      startSceneIfReset(nextMode);
    }
  }
}


