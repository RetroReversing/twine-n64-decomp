s32 func_8000A310();
s32 func_80011938(s32, s32);
s32 func_800218EC();
s32 func_80021938();
s32 func_800283B0();
s32 func_8002B000(s32 *, s32);
s32 func_8002B9CC(s32);
s32 func_8003099C(u8, u8);
s32 func_80045130(u8);
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
extern ItemEntry D_800C3CF8[];
extern s8 D_801002A3;
extern u8 D_801002A4;
extern s8 D_801002AC;
extern s32 D_801002C4;
extern s32 D_801002C8;
extern s32 D_801002D0;
extern s8 D_80102EB9;
extern u8 D_80102EE0;
extern s32 D_80102EEC;
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
void func_8001ED10(void)
{
  s16 temp_a0;
  s32 var_a0;
  s32 var_s0;
  s32 var_s1;
  u8 var_a0_2;
  u8 *__base_D_801002A4;
  __base_D_801002A4 = &D_801002A4;
  gMenuUseTextList = 1;
  if (D_80102EEC == 0)
  {
    if ((sActiveMenu != NULL) && ((temp_a0 = *((s16 *) (((char *) sActiveMenu) + 0x7A)), temp_a0 != 0xF)))
    {
      if (temp_a0 != 0xE)
      {
        *((s16 *) (((char *) sActiveMenu) + 0x7A)) = 0xE;
      }
    }
    else
    {
      var_s1 = 0;
      D_801176D8 = 0;
      D_801176DC = 0;
      D_801176E0 = 0;
      D_801176E2 = 0;
      D_801176E4 = 0;
      D_80102EB9 = 0xB;
      do
      {
        func_80011938((u16) var_s1, 0);
        var_s1 += 1;
      }
      while (((u32) (var_s1 & 0xFFFF)) < 4U);
      func_8002B000(&sProbeTimer, 0x1E);
      if (gBorderSkipActive != 0)
      {
        do
        {
          D_801002AC = 0;
        }
        while (0);
        D_801002A3 = 0;
        gPickupSavedByte = 0;
 do { { s32 timer = D_801002C4; s32 other = D_801002C8; sRaceTimer = timer; D_801002D0 = other; } D_80102EF0 = 0; var_s1 = 0; } while (0);
        if (gSaveTotalSlots > 0)
        {
          s16 *items = gSharedItemId;
          do
          {
            s32 slot;
            s16 *out;
            s32 item;
            var_s0 = (u16) var_s1;
            slot = getSaveSlotIndex(var_s0);
            var_s0 *= 2;
            item = func_8002B9CC(gSaveSlotInfo[(u16) slot].id);
            out = (s16 *) (var_s0 + ((int) items));
            *out = *D_800C3CF8[item].id;
            var_s1 += 1;
          }
          while (((s32) ((u16) var_s1)) < gSaveTotalSlots);
        }
        gSharedItemId[(u16) var_s1] = -1;
        var_a0_2 = *((volatile u8 *) __base_D_801002A4);
      }
      else
      {
        var_a0_2 = D_80102EE0;
        D_80102EF0 = 1;
      }
      func_80045130(var_a0_2);
      gPendingMenuCommand = 0;
      func_800283B0();
      func_8000A310();
      func_800218EC();
      func_80021938();
      func_8003099C(D_80102EE0, sDifficultyLevel);
    }
  }
}
