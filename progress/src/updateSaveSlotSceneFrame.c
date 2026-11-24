extern s32 requestSaveMenu(s32);
extern s32 updateBonusGoalState(void);
extern void func_8011C580(void);
extern void updateRaceTimerHud(s32);
extern void func_8011C890(void);
extern void updateSaveSlotMarkerColors(void);
extern void steerSaveSlotActors(void);
extern void updateSaveSlotLabels(void);
extern void freeAllMenuItemRecords(void);
extern u8 gSceneType;
extern u8 gBonusGoalReached;
extern u8 D_801002AE;
extern s32 gSaveTotalSlots;
extern s32 gVisibleSaveSlotCount;
extern s32 gBorderSkipActive;
extern u8 gBorderFlipFlag;
extern s16 gViewportWidth;
extern s16 gViewportHeight;
extern s32 gBonusEndDelayFrames;
/* Per-frame update of the save-slot/bonus scene: sets viewport size, steps scene-specific actors, and when the bonus end delay expires marks every slot and finishes. */ void updateSaveSlotSceneFrame(void)
{
  u8 *slotFlag;
  u8 *menuActive;
  s32 *totalSlotsPtr;
  u16 slot;
  s32 delayLeft;
  s32 sceneType;
  gViewportHeight = 0x78;
  if (gVisibleSaveSlotCount >= 3)
  {
    gViewportWidth = 0xA0;
  }
  else
    if (gBorderFlipFlag == 1)
  {
    gViewportWidth = 0xA0;
    gViewportHeight = 0xF0;
  }
  else
  {
    gViewportWidth = 0x140;
  }
  menuActive = &D_801002AE;
  if ((*menuActive) == 0)
  {
    updateRaceTimerHud(-1);
    if ((*menuActive) == 0)
    {
      func_8011C580();
    }
  }
  sceneType = gSceneType;
  if (sceneType < 6)
  {
    if (sceneType >= 4)
    {
      func_8011C890();
      sceneType = gSceneType;
    }
  }
  if (sceneType >= 2)
  {
    if (sceneType >= 4)
    {
      if (sceneType == 6)
      {
        updateSaveSlotMarkerColors();
      }
    }
    else
    {
      steerSaveSlotActors();
    }
  }
  updateSaveSlotLabels();
  if ((((gBorderSkipActive != 0) && (gBonusGoalReached != 0)) || (updateBonusGoalState() & 0xFFFF)) && ((delayLeft = gBonusEndDelayFrames - 1, gBonusEndDelayFrames = delayLeft, delayLeft <= 0)))
  {
    if (delayLeft == 0)
    {
      freeAllMenuItemRecords();
      slot = 0;
      totalSlotsPtr = &gSaveTotalSlots;
      if (delayLeft < *totalSlotsPtr)
      {
        slotFlag = ((u8 *) totalSlotsPtr) + -6;
        do
        {
          *slotFlag = 1;
          requestSaveMenu(slot & 0xFF);
          slot++;
        }
        while ((slot & 0xFFFF) < (*((s32 *) (slotFlag + 6))));
      }
    }
    else
    {
      gBonusEndDelayFrames = -1;
    }
  }
}


