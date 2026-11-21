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
void func_80019E28(s32 arg0)
{
  u8 *__base_D_801002AD;
  char sp10[32];
  Pk8 sp30;
  u16 *temp_s1;
  s32 temp_a0;
  s32 temp_s0;
  u16 var_a0;
  __base_D_801002AD = &gPickupSavedByte;
  if ((*__base_D_801002AD) < gSaveSlotCount)
  {
    formatTextEntry(arg0, D_800D290C, lookupDataEntry((!(getKeyEntryFlag(gSaveSlotInfo[(*__base_D_801002AD) * 6]) & 0xFF)) ? (0x15B) : (0x15C)));
  }
  else
  {
    if (arg0)
    {
      sp30 = D_800D2914;
      temp_a0 = gSaveSlotInfo[(*__base_D_801002AD) * 6];
      temp_s0 = D_800BF688[temp_a0 * 6] & 3;
      temp_s1 = lookupDataEntry((!(getKeyEntryFlag(temp_a0) & 0xFF)) ? (0x15B) : (0x15C));
    }
    else
    {
      sp30 = D_800D2914;
      temp_a0 = gSaveSlotInfo[(*__base_D_801002AD) * 6];
      temp_s0 = D_800BF688[temp_a0 * 6] & 3;
      temp_s1 = lookupDataEntry((!(getKeyEntryFlag(temp_a0) & 0xFF)) ? (0x15B) : (0x15C));
    }
    do
    {
      sprintf(sp10, D_800D291C, temp_s1, lookupDataEntry(((u16 *) (&sp30))[temp_s0]));
    }
    while (0);
    formatTextEntry(arg0, D_800D290C, (u16 *) sp10);
  }
}

