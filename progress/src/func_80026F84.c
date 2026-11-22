void copyStateTablesToRam();
u16 countValidSaveSlots(u16);
volatile char func_8002D240();
s32 func_80081828(s32);
extern s32 sSaveMenuFlagsB;
extern s32 sSaveMenuColorIdle;
extern s32 D_800BD664;
extern u8 sMenuListKind;
extern u8 gMenuSlot;
extern u8 gMenuNeedsRedraw;
extern s8 gMenuParamB;
extern s32 D_800BD8C4;
extern u8 D_800E109F;
extern u8 D_800E10A0;
extern u8 D_800E10A1;
extern u8 D_800E10A2;
extern u8 D_800E10A3;
extern u8 D_800E10A4;
extern s8 D_800BF598;
extern s8 D_800E109C;
extern s8 D_800E109D;
extern s8 D_800E109E;
extern s8 D_801002AE;
extern s8 D_801002E6;
extern s8 D_801002E7;
extern s8 D_801002E8;
extern s8 D_801002E9;
extern s8 gValidSaveSlotCount;
extern s8 D_80102ED4;
extern s8 D_80102F04;
extern s32 gMenuSoundParams;
extern s32 D_80102EC0;
extern s32 sMenuDefaultSoundParams;
extern volatile s32 gBorderSkipActive;
extern u8 gMenuUseTextList;
extern u8 * volatile gSaveMenuState;
extern s32 sBonusObjectTable[];
void func_80026F84(u8 arg0)
{
  
  long slot;
  u8 *p;
  u8 *q;
  if (D_800BF598 != 0)
  {
    D_800E109F = 0xFF; D_800E10A0 = 0xFF; D_800E10A1 = 0xFF; D_800E10A2 = 0xFF; D_800E10A3 = 0xFF; D_800E10A4 = 0xFF;
    D_80102F04 = 0; D_800BF598 = 0; gMenuSlot = 0;
    D_800E109E = 0; D_800E109D = 0; D_800E109C = 0;
    D_801002E6 = -1; D_801002E7 = -1; D_801002E8 = -1; D_801002E9 = -1;
    gSaveMenuState = NULL;
    func_8002D240();
    copyStateTablesToRam();
  }
  gValidSaveSlotCount = countValidSaveSlots(0xA3);
  D_80102ED4 = 1;
  if ((p = gSaveMenuState) != NULL)
  {
    p[7] = 0;
    { u8 *a = gSaveMenuState;
    a[0x2F] = 0;
    { u8 *b = gSaveMenuState;
    *((s32 *) (a + 0x20)) = 0;
    *((s32 *) (a + 0x24)) = 0;
    *((u16 *) (a + 0x14)) = 0;
    *((u16 *) (a + 0x16)) = 0;
    b[0x28] = 0;
    { u8 *c = gSaveMenuState;
    *((s32 *) b) = 0;
    c[0x29] = 0;
    { u8 *d = gSaveMenuState;
    d[0x2C] = 0;
    { u8 *e = gSaveMenuState;
    *((u16 *) (d + 0x2A)) = 0x1D;
    e[0x2D] = 0;
    { u8 *f = gSaveMenuState;
    *((s32 *) (f + 0x1C)) = 0;
    *((s32 *) (f + 0x10)) = 0;
    *((s32 **) (f + 0xC)) = &D_800BD8C4;
    }}}}}}
  }
  slot = arg0;
{ s32 *tp = &sBonusObjectTable[slot]; s32 t; do { D_801002AE = 0; t = *tp; gMenuNeedsRedraw = 1; if (t != 0) { gMenuSlot = arg0; } else { gMenuSlot = 0; } gMenuParamB = func_80081828(gMenuSlot); if (gMenuUseTextList != 0) { if (gBorderSkipActive) { sMenuListKind = 4; goto done; } sMenuListKind = 4; } else { sMenuListKind = gMenuSlot; } done: do { D_80102EC0 = D_800BD664; gMenuSoundParams = sSaveMenuColorIdle; sMenuDefaultSoundParams = sSaveMenuFlagsB; } while (0); } while (0); }
}


