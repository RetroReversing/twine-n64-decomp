typedef struct 
{
  u8 b[8];
} Pk8;
extern u8 gPickupSavedByte;
extern s32 gSaveSlotCount;
extern s32 gSaveSlotInfo[];
extern u16 D_800BF688[];
extern Pk8 D_800D2914;
extern char D_800D290C[];
extern char D_800D291C[];
s32 getKeyEntryFlag(s32);
u16 *lookupDataEntry(u16);
void formatTextEntry(s32, char *, u16 *);
s32 sprintf(char *, char *, ...);
/* Formats the selected pickup item's name (plus variant, for non-save-slot items as "name, variant") into the text entry. */ void showPickupItemName(s32 textSlot)
{
  u8 *__base_D_801002AD;
  char label[32];
  Pk8 variantNames;
  u16 *itemName;
  s32 itemId;
  s32 variantIdx;
  u16 var_a0;
  __base_D_801002AD = &gPickupSavedByte;
  if ((*__base_D_801002AD) < gSaveSlotCount)
  {
    formatTextEntry(textSlot, D_800D290C, lookupDataEntry((!(getKeyEntryFlag(gSaveSlotInfo[(*__base_D_801002AD) * 6]) & 0xFF)) ? (0x15B) : (0x15C)));
  }
  else
  {
    if (textSlot)
    {
      variantNames = D_800D2914;
      itemId = gSaveSlotInfo[(*__base_D_801002AD) * 6];
      variantIdx = D_800BF688[itemId * 6] & 3;
      itemName = lookupDataEntry((!(getKeyEntryFlag(itemId) & 0xFF)) ? (0x15B) : (0x15C));
    }
    else
    {
      variantNames = D_800D2914;
      itemId = gSaveSlotInfo[(*__base_D_801002AD) * 6];
      variantIdx = D_800BF688[itemId * 6] & 3;
      itemName = lookupDataEntry((!(getKeyEntryFlag(itemId) & 0xFF)) ? (0x15B) : (0x15C));
    }
    do
    {
      sprintf(label, D_800D291C, itemName, lookupDataEntry(((u16 *) (&variantNames))[variantIdx]));
    }
    while (0);
    formatTextEntry(textSlot, D_800D290C, (u16 *) label);
  }
}

