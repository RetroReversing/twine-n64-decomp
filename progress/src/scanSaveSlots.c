s32 saveWaitCommand(void);
s32 saveFindTaggedSlot(void);
u16 getSaveErrorStatus(u32);
u16 saveVerifySlot(void);
s32 saveSubmitCommand(u16, s32, s32, s32, s32, s32, s32, s32);
u16 loadSaveSlotHeaders(void);
extern u16 gSaveStatus;
extern u16 D_800E0768[4];
extern u8 D_800E076A[16];
extern u8 D_800E076B[16];
extern u8 gRumblePaks[];
extern s16 gSaveSlotIndex;
extern s16 gSaveSlot;
extern s16 D_800E093C;
extern s16 D_800E093E;
extern s16 gSaveSlotFlags[4];
extern s32 gSaveCmdResult;
extern s16 gSaveSlotAltFlags[4];
extern u8 gSavePresentMask;
extern s16 gSaveSlotLoaded[4];
extern s16 gSaveSlotValid[4];
extern s8 gSaveSlotCodeBuf;
extern s8 D_8010A3C6;
extern s8 D_8010A3C7;
extern s8 D_8010A3C8;
inline static int inline_fn(int arg0)
{
  return -arg0;
}

/* Scans all four save slots, verifies each present one, loads headers for slot 0 on first scan, and returns the save status. */ s32 scanSaveSlots(void)
{
  s16 *slotFlagsBase;
  s16 *slotLoadedBase;
  s32 firstScan;
  firstScan = inline_fn(1);
  gSaveSlotCodeBuf = 0; D_8010A3C6 = 0; D_8010A3C7 = 0; D_8010A3C8 = 0;
  D_800E093E = 0;
  gSaveSlot = 0;
  D_800E093C = -1;
  D_800E093E = 0;
  gSaveSlotIndex = -1;
  saveSubmitCommand(0xD, 0, 0, 0, 0, 0, 0, 0);
  saveWaitCommand();
  slotFlagsBase = gSaveSlotFlags;
  slotLoadedBase = gSaveSlotLoaded;
  gSaveSlot = 0;
  for (;;)
  {
    s32 slot;
    s32 entryOffset;
    s16 *slotFlags;
    s16 *slotLoaded;
    slot = gSaveSlot;
    slotFlags = (s16 *)(slot * 2 + (s32)slotFlagsBase);
    slotLoaded = (s16 *)(slot * 2 + (s32)slotLoadedBase);
    entryOffset = slot * 4;
    *slotFlags = 0;
    do { *slotLoaded = 0; } while (0);
    gSaveSlotValid[slot] = 0;
    do { do { gSaveSlotAltFlags[slot] = 0; } while (0); } while (0);
    do { if (((D_800E076B[entryOffset] == 0) && ((gSavePresentMask >> slot) != 0)) && (((*(u16 *)((u8 *)D_800E0768 + entryOffset) & 0x1F07) != 5) || ((*slotFlags = 1, (D_800E076A[entryOffset] & 1) != 0))))
    {
      u32 verifyResult;
      verifyResult = saveVerifySlot();
      switch (verifyResult)
      {
        case 0xA4:
          if ((firstScan != 0) && (gSaveSlot == 0))
        {
          firstScan = 0;
          *slotLoadedBase = 1;
          if ((loadSaveSlotHeaders() == 0) && (((u16) saveFindTaggedSlot()) != 0))
          {
            gSaveStatus = 0x30;
          }
        }
          break;

        case 0xA5:
          saveSubmitCommand(0xC, (s32) (gRumblePaks + (gSaveSlot * 0x68)), gSaveSlot, 0, 0, 0, 0, 0);
          saveWaitCommand();
          break;

        case 0x12:

        case 0x62:

        case 0x63:
          if (gSaveSlot == 0)
        {
          return verifyResult;
        }
          break;

        case 0x20:
          if (gSaveSlot == 0)
        {
          goto ret20;
        }
          break;

      }

    } } while (0);
    if ((++gSaveSlot) >= 4)
    {
      if (firstScan == 0)
      {
        gSaveSlot = 0;
      }
      else
      {
        firstScan = inline_fn(1);
      }
      if (0)
      {
        ret20:
        return getSaveErrorStatus(gSaveCmdResult);

      }
      if (firstScan < 0)
      {
        gSaveStatus = 0x10;
      }
      return gSaveStatus;
    }
  }

}


