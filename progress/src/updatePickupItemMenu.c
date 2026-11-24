s32 loadTrackIdList(u16 *);
s32 clearProbeState(void *, s32);
void *findEntryById(s32, s32);
s32 formatTextEntry(void *, const void *, s32);
s32 countGlyphStrokes(s16);
s32 allocActorAnimData(void *, s32, s32, u8);
s32 setActorCommandState(void *, s32);
s32 showPickupItemName(void *);
s32 isMenuButtonPressed(s32);
s32 releaseSpawnTableAssets();
s32 findNextPickupItemSlot(s32, s32);
s32 getItemTableByte(s32);
s32 loadSpawnEntryData(s32);
s32 getKeyEntryFlag(s32);
s32 menuItemIsActive(s32);
s32 updateActiveMenuState();
extern u8 D_800BF688;
extern char D_800D2858[];
extern s16 *gAssetSlotTable;
extern u8 D_801001A3;
extern void *gPickupActor;
extern u8 gPickupSavedByte;
extern void *gSaveMenuState;
extern s32 gSaveSlotCount;
extern s32 gSaveSlotInfo;
extern s16 gSharedItemArg;
extern s8 gSharedItemBusy;
extern u16 gSharedItemId;
extern s32 sFmtEntryName;
inline static s8 inline_fn(u8 arg0)
{
  return (s8) (arg0 - 1);
}

inline static u8 *inline_fn2(u8 *arg0, int arg1)
{
  return arg0 - arg1;
}

/* Updates the pickup item menu: left/right changes the selected item, up/down adjusts its count, then respawns the preview actor and refreshes the text entries. */ void updatePickupItemMenu(void)
{
  char *__repair_addr;
  u8 *savedSlot;
  u8 *__repair_offset;
  u16 *idList;
  void **actor;
  s32 id;
  s32 temp_v0;
  s32 itemIndex;
  u8 tmpA; s32 *tmpP;
  u16 temp_v1;
  u16 temp_v1_3;
  u8 temp_s0_2;
  u8 temp_v1_2;
  void *menuItem;
  void *labelEntry;
  void *headerEntry;
  headerEntry = findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0x400C);
  menuItem = *((void **) (((char *) gSaveMenuState) + 0x18));
  do
  {
    updateActiveMenuState();
  }
  while (0);
  tmpP = *((s32 **) (((char *) menuItem) + 0x10));
  tmpA = (*((u8 *) (((char *) gSaveMenuState) + 0x2D)));
  do { itemIndex = *tmpP; } while (0);
  labelEntry = menuItem + 0x28;
  if ((tmpA != 0) && ((*((u8 *) (((char *) gSaveMenuState) + 0x2E))) == 0))
  {
    savedSlot = &gPickupSavedByte;
    {
      extern char D_8010019C[];
      *((u8 *) ((((char *) D_8010019C) + ((*savedSlot) * 0x18)) + 7)) = 0;
    }
    if (menuItemIsActive(0x20) & 0xFF)
    {
      itemIndex = findNextPickupItemSlot(itemIndex, -1);
    }
    if (menuItemIsActive(0x21) & 0xFF)
    {
      itemIndex = findNextPickupItemSlot(itemIndex, 1);
    }
    *(*((s32 **) (((char *) menuItem) + 0x10))) = itemIndex;
    actor = &gPickupActor;
    if ((*actor) != NULL)
    {
      releaseSpawnTableAssets();
      temp_v1 = *(*((s16 **) (((u8 *) (&gAssetSlotTable)) + (getItemTableByte(itemIndex) * 0xC))));
      gSharedItemArg = -1;
      gSharedItemBusy = 1;
      idList = &gSharedItemId;
      *idList = temp_v1;
      loadTrackIdList(idList);
      gSharedItemBusy = 0;
      id = getItemTableByte(itemIndex);
      allocActorAnimData(*actor, id, 0, *((&D_801001A3) + ((*savedSlot) * 0x18)));
      setActorCommandState(*actor, 0x14D);
      *((f32 *) (((char *) (*((void **) (((char *) gPickupActor) + 0x68)))) + 0x34)) = 0.05f;
      if (!(getKeyEntryFlag(*((s32 *) (((char *) (&gSaveSlotInfo)) + ((*savedSlot) * 0x18)))) & 0xFF))
      {
        clearProbeState(*actor, 0x2A9);
      }
      else
      {
        clearProbeState(*actor, 0x327);
      }
      goto block_11;
    }
  }
  else
  {
    block_11:
    *((u8 *) (((char *) gSaveMenuState) + 0x2D)) = 0U;

    if (isMenuButtonPressed(0x28) & 0xFF)
    {
      u8 *decrementSlot = &gPickupSavedByte;
      if (labelEntry || gSaveMenuState)
      {
        id = (*decrementSlot) * 0x18;
        temp_v1_2 = *((&D_801001A3) + id);
      }
      else
      {
        id = (*decrementSlot) * 0x18;
        do
        {
          temp_v1_2 = *((&D_801001A3) + id);
        }
        while (0);
      }
      if (temp_v1_2 != 0)
      {
        if (1)
        {
          __repair_addr = (char *) ((unsigned) id + (unsigned) inline_fn2(decrementSlot, 0x115));
        }
        *((s8 *) (((char *) __repair_addr) + 0xB)) = inline_fn(temp_v1_2);
        *((u8 *) (((char *) gSaveMenuState) + 0x2D)) = 1U;
      }
    }
    if (isMenuButtonPressed(0x29) & 0xFF)
    {
      savedSlot = &gPickupSavedByte;
      temp_s0_2 = *((&D_801001A3) + ((*savedSlot) * 0x18));
      if (((s32) temp_s0_2) < countGlyphStrokes(*(*((s16 **) (((u8 *) (&gAssetSlotTable)) + (getItemTableByte(itemIndex) * 0xC))))))
      {
        temp_v0 = (*savedSlot) * 0x18;
        __repair_offset = savedSlot - 0x115;
        *((s8 *) (((char *) (temp_v0 + __repair_offset)) + 0xB)) = (s8) ((*((&D_801001A3) + temp_v0)) + 1);
        *((u8 *) (((char *) gSaveMenuState) + 0x2D)) = 1U;
      }
    }
    if (((*((u8 *) (((char *) gSaveMenuState) + 0x2D))) != 0) && ((*((u8 *) (((char *) gSaveMenuState) + 0x2E))) == 0))
    {
      actor = &gPickupActor;
      if ((*actor) != NULL)
      {
        releaseSpawnTableAssets();
        temp_v1_3 = *(*((s16 **) (((u8 *) (&gAssetSlotTable)) + (0xC * getItemTableByte(itemIndex)))));
        gSharedItemArg = -1;
        gSharedItemBusy = 1;
        idList = &gSharedItemId;
        *idList = temp_v1_3;
        loadTrackIdList(idList);
        gSharedItemBusy = 0;
        id = getItemTableByte(itemIndex);
        allocActorAnimData(*actor, id, 0, *((&D_801001A3) + (gPickupSavedByte * 0x18)));
        setActorCommandState(*actor, 0x14D);
        *((f32 *) (((char *) (*((void **) (((char *) gPickupActor) + 0x68)))) + 0x34)) = 0.05f;
        goto block_21;
      }
    }
    else
    {
      block_21:
      if (labelEntry != NULL)
      {
        if (savedSlot)
        {
          formatTextEntry(labelEntry, &sFmtEntryName, loadSpawnEntryData(itemIndex));
        }
        else
        {
          formatTextEntry(labelEntry, &sFmtEntryName, loadSpawnEntryData(itemIndex));
        }
      }

      if (headerEntry != NULL)
      {
        showPickupItemName(headerEntry);
      }
      {
      u8 *tailSlot = &gPickupSavedByte;
      if (gSaveSlotCount < ((s32) (*tailSlot)))
      {
        if (1)
        {
          formatTextEntry(findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0x4004), D_800D2858, (*((u8 *) (((char *) (&D_800BF688)) + ((*((s32 *) (((char *) (&gSaveSlotInfo)) + ((*tailSlot) * 0x18)))) * 0xC)))) * 5);
        }
      }
      }
    }
  }
}


