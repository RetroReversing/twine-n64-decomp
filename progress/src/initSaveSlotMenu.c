s32 findSaveSlotByMode();
s32 setCursorMarker();
s32 updateTrackMarker();
s32 initMenuWindow();
s32 appendWeightedListEntry();
s32 setMenuActiveState();
s32 setSaveMenuFlag();
s32 isSaveSlotUsed16();
s32 refreshSlotMenuLabels();
s32 selectItemAndUpdateAmount();
s32 spawnTextNode();
s32 updateSaveMenuSprites();
extern u16 D_800B81A8;
extern u8 D_800B81AB;
extern char D_800BD5D0[];
extern char gSaveMenuObjectPool[];
extern char D_80109C18[];
extern char D_80109C1C[];
extern char D_8010D478[];
extern s32 freeMenuPair;
extern s8 gMenuAnyController;
extern void *gSaveMenuState;
extern u8 sMenuListKind;
extern volatile u16 sSaveMenuAction;
extern s8 sSaveMenuRefresh;
extern s32 sSaveMenuSpriteFirst;
extern s32 sSaveMenuSpriteSecond;
extern s32 updateSaveMenuEntries;
typedef struct 
{
  short field_0;
  unsigned char pad_2[34];
  short field_24;
} __repair_record_temp_s2;
inline static u16 *inline_fn(void *arg0)
{
  return (u16 *) (((char *) arg0) + 0x14);
}

inline static s32 inline_fn2(char *arg0, int arg1)
{
  return spawnTextNode(arg0 - arg1);
}

/* Builds the save slot menu: window, 16 slot entries, sprites and initial selection. */ void initSaveSlotMenu(void)
{
  int usedSprite;
  int emptySprite;
  char *__base_D_800BD5D0;
  s16 *slotNode;
  s32 temp_a0;
  int entryOffset;
  s32 temp_v0;
  s32 slot;
  s32 temp_v1;
  u16 action;
  void *headerNode;
  setSaveMenuFlag();
  gMenuAnyController = 0;
  initMenuWindow(gSaveMenuObjectPool, D_8010D478, 0xC0, 6, 0x58, 0xB2, 0x3C, 0x14, 1, &updateSaveMenuEntries, &freeMenuPair);
  setCursorMarker(sMenuListKind, 0x20, 0x3C, 0xF8, 0x78);
  slot = 0;
  __base_D_800BD5D0 = D_800BD5D0;
  headerNode = __base_D_800BD5D0 - 0x4C;
  usedSprite = 0xF;
  emptySprite = 0x10;
  slotNode = __base_D_800BD5D0 - 0x34;
  sSaveMenuSpriteSecond = spawnTextNode(__base_D_800BD5D0);
  sSaveMenuSpriteFirst = inline_fn2(__base_D_800BD5D0, 0x24);
  do
  {
    temp_a0 = slot & 0xFFFF;
    ((__repair_record_temp_s2 *) headerNode)->field_0 = (s16) sMenuListKind;
    do
    {
      (*((__repair_record_temp_s2 *) headerNode)).field_24 = (s16) sMenuListKind; temp_v0 = temp_a0 * 8;
      *((s32 *) (D_80109C18 + temp_v0)) = 0;
      *((s32 *) (D_80109C1C + temp_v0)) = 0;
      if (isSaveSlotUsed16(temp_a0) & 0xFFFF)
      {
        *((s32 *) (((char *) headerNode) + (-8))) = usedSprite;
      }
      else
      {
        *((s32 *) (((char *) headerNode) + (-8))) = emptySprite;
      }
      *slotNode = slot + 0x4000;
      *((s32 *) (D_80109C18 + (entryOffset = (slot & 0xFFFF) * 8))) = inline_fn2(slotNode, 0x14);
      *((s32 *) (D_80109C1C + entryOffset)) = inline_fn2(slotNode, 0x38);
      appendWeightedListEntry(gSaveMenuObjectPool, entryOffset + D_80109C18, slot & 0xFF, 1);
      slot += 1;
    }
    while (0);
  }
  while (((u32) (slot & 0xFFFF)) < 0x10U);
  refreshSlotMenuLabels();
  sSaveMenuRefresh = 0;
  sSaveMenuAction = 1;
  updateTrackMarker(sMenuListKind);
  temp_v1 = *inline_fn(gSaveMenuState);
  switch (temp_v1)
  {
    case 0x19:
    case 0x1B:
      action = 3;
      break;
    case 0x1A:
      action = 2;
      break;
    default:
      action = 1;
      break;
  }
  sSaveMenuAction = action;
  do
  {
    updateSaveMenuSprites(sSaveMenuAction, D_800B81A8, D_800B81AB, 1);
  }
  while (0);
  selectItemAndUpdateAmount(gSaveMenuObjectPool, 0);
  setMenuActiveState(gSaveMenuObjectPool, 1);
  if (((u32) ((*inline_fn(gSaveMenuState)) - 0x19)) < 2U)
  {
    selectItemAndUpdateAmount(gSaveMenuObjectPool, findSaveSlotByMode(sSaveMenuAction) & 0xFF);
  }
  *((s8 *) (((char *) gSaveMenuState) + 0x2C)) = 0;
}


