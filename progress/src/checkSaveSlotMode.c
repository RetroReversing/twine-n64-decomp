typedef struct 
{
  char pad[0x18];
  s8 *name;
} SaveHeader;
extern char gSaveMenuObjectPool[];
extern u8 D_80107EC0;
extern SaveHeader ***getSelectedMenuEntry(void *);
extern SaveHeader ***getMenuEntry(void *, s8);
extern s8 *findSubstring(s8 *, s8 *);
extern s8 *lookupDataEntry(s32);
extern s32 isSaveSlotValid(u8);
/* Checks the current save slot's name against the requested mode (1-3); returns mode, or mode | 0x1000 if invalid. */
s32 checkSaveSlotMode(s32 mode, s32 arg1, s32 arg2, s32 arg3)
{
  SaveHeader ***slotEntry;
  SaveHeader **slotHeader;
  s8 *slotName;
  s8 *expectedName;
  s16 slotIndex;
  s32 result;
  mode &= 0xEFFF;
  slotEntry = getSelectedMenuEntry(gSaveMenuObjectPool);
  result = mode;
  if (slotEntry == NULL)
  {
    goto invalid;
  }
  if (mode)
  {
    slotHeader = *slotEntry;
  }
  else
  {
    slotHeader = *slotEntry;
  }
  if (slotHeader == NULL)
  {
    goto invalid;
  }
  slotName = (*slotHeader)->name;
  if (slotName == NULL)
  {
    goto invalid;
  }
  switch ((u16) result)
  {
    case 1:
      if (findSubstring(slotName, "TWINE") == NULL)
    {
      return mode | 0x1000;
    }
      if (isSaveSlotValid(D_80107EC0) != 0)
    {
      return result;
    }
      return mode | 0x1000;

    case 2:
      if ((findSubstring(slotName, "TWINE") == NULL) || (isSaveSlotValid(D_80107EC0) == 0))
    {
      expectedName = lookupDataEntry(0x3004);
      if (findSubstring((*slotHeader)->name, expectedName) == NULL)
      {
        return mode | 0x1000;
      }
    }
      if (findSubstring((*slotHeader)->name, "TWINE") != NULL)
    {
      return result;
    }
      for (slotIndex = D_80107EC0 - 1; slotIndex >= 0; slotIndex--)
    {
      slotEntry = getMenuEntry(gSaveMenuObjectPool, (s8) slotIndex);
      if (slotEntry == NULL)
      {
        return result | 0x1000;
      }
      slotHeader = *slotEntry;
      if (slotHeader == NULL)
      {
        return result | 0x1000;
      }
      if ((*slotHeader)->name == NULL)
      {
        return result | 0x1000;
      }
      expectedName = lookupDataEntry(0x3004);
      if (findSubstring((*slotHeader)->name, expectedName) != NULL)
      {
        return result | 0x1000;
      }
    }

      return result;

    case 3:
      expectedName = lookupDataEntry(0x3004);
      if (findSubstring((*slotHeader)->name, expectedName) == NULL)
    {
      return result;
    }
      invalid:
    return mode | 0x1000;


  }

  return result;
}
