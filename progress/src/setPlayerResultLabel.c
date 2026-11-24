typedef struct 
{
  char pad[12];
  u16 start;
  u16 end;
  char pad2[2];
  u8 kind;
} Save;
typedef struct 
{
  char pad[0xB4];
  Save *save;
} Slot;
typedef struct 
{
  char pad[0x10];
  u32 color;
  char pad2[0x14];
  u32 flags;
} Label;
extern Slot *gSaveSlots[];
extern s16 gBonusPlayerScores[];
extern s16 gResultLabelTimers[];
extern char gResultLabelText[][12];
extern Label *gResultLabels[];
extern s32 gVisibleSaveSlotCount;
extern s32 gSaveTotalSlots;
extern void *lookupDataEntry(volatile int);
extern s32 sprintf(char *, const char *, ...);
inline static char *inline_fn(char *arg0, s32 arg1)
{
  return arg0 + (arg1 >> 14);
}

inline static Save *inline_fn2(Slot **arg0)
{
  return (*arg0)->save;
}

/* Sets a player's result label text (win/place message), color and display timer from scores or ranking. */ void setPlayerResultLabel(unsigned short slot)
{
  volatile s32 *count = &gVisibleSaveSlotCount;
  short index = (s16) slot;
  s32 i;
  u16 playerIndex;
  s32 textId;
  s32 kind;
  Save *save;
  Slot **cursor;
  s32 unused[2];
  Label **label;
  if (index < (*count))
  {
    save = gSaveSlots[index]->save;
    kind = save->kind;
    playerIndex = kind;
    cursor = gSaveSlots;
    if (playerIndex == 2)
    {
      s32 scoreDelta = save->start - save->end;
      s32 place = gSaveTotalSlots;
      i = 0;
      if (place > 0)
      {
        s32 slotCount;
        s32 idx;
        do
        {
          idx = index;
          slotCount = (&gVisibleSaveSlotCount)[-3];
          if (i != idx)
          {
            Save *other = (*cursor)->save;
            place -= (other->start - other->end) <= scoreDelta;
          }
          i++;
          cursor++;
        }
        while (i < slotCount);
      }
      switch (place)
      {
        case 1:
          textId = 0x2E5;
          goto format;
        case 2:
          textId = 0x2E6;
          goto format;
        case 3:
          textId = 0x2E7;
          goto format;
        case 4:
          textId = 0x2E8;
          format:
          sprintf(gResultLabelText[(s16) slot], lookupDataEntry(textId));
      }
      index = (s16) slot;
      {
        Label **la = (Label **) inline_fn((char *) gResultLabels, (s32) (((u32) index) << 16));
        (*la)->flags = ((*la)->flags & (~0xFC)) | 0xC;
        (*la)->color = -1;
        gResultLabelTimers[index] = 60;
      }
    }
    else
    {
      textId = 0x2E6;
      if (gBonusPlayerScores[playerIndex] >= gBonusPlayerScores[1 - playerIndex])
      {
        textId = 0x2E5;
      }
      sprintf(gResultLabelText[index], lookupDataEntry(textId));
      {
      Label **lb = (Label **) inline_fn((char *) gResultLabels, (s32) (((u32) slot) << 16));
      (*lb)->flags = ((*lb)->flags & (~0xFC)) | 0xC;
      if (kind == 0)
      {
        (*lb)->color = 0xFF2020FF;
      }
      else
      {
        (*lb)->color = 0x2020FFFF;
      }
      }
      *((s16 *) (((char *) gResultLabelTimers) + (((s32) (((u32) slot) << 16)) >> 15))) = 60;
    }
    if (1)
    {
    }
    if (1)
    {
    }
    if (1)
    {
    }
    if (1)
    {
    }
  }
}

