s32 func_8000828C();
s32 allocZeroedTag15Block(s32 *, u32, u32, s32 *);
s32 clearTrackMarkerCounters();
s32 resetLightingDefaults();
s32 setupViewportsForPlayerCount();
s32 resetHeap();
s32 setHeapMode(s32);
extern s32 D_800CA31C;
extern s32 D_8010302C;
extern void *gObjectListHead;
extern s32 D_80109688;
extern s32 gChasedObject;
extern s32 D_8010A500;
extern s32 gBonusTotalCount;
extern s32 gBonusCollectedCount;
extern u8 D_801002E4;
extern u8 D_801002E5;
extern u8 D_80100300;
extern u8 D_80100784;
extern u8 gBaseColorR;
extern u8 D_80103020;
extern u8 D_8010302A;
extern u8 D_80103041;
extern u8 gBaseColorB;
extern u8 D_801032AC;
extern u8 D_80103EB1;
extern u8 D_80107B60;
extern u8 D_80107ECC;
extern u8 D_80107ECD;
extern u8 D_80107ECE;
extern u8 D_80107ECF;
extern u8 gBaseColorG;
extern u8 D_80108F94;
extern u8 D_801093A0;
extern u8 D_8010957C;
extern u8 D_80109684;
extern u8 D_80109A34;
extern u8 D_80109A35;
extern u8 gTrackSpecialMarkerFlag;
extern u8 gTrackMarkerSpawned;
extern u8 D_8010A2CC;
extern u8 D_8010A3C4;
extern u8 D_8010A4B8;
extern u8 D_8010A91C;
extern u8 D_8010D2B0;
extern u8 D_8010D2B8;
extern u8 D_8010D36C;
extern u8 D_8010D374;
extern u8 D_80110CA8;
extern u8 D_80110DB1;
extern u8 D_80112F88;
extern u8 D_80115318;
extern u8 D_80117734;
/* Resets per-level state: clears bonus counters and tables, then restores default colors and flags. */ void resetLevelState(void)
{
  s32 *totalPtr;
  s32 *collectedRow;
  s32 *totalRow;
  s32 *p;
  s32 *p2;
  s32 *collectedPtr;
  u32 col;
  u32 row;
  u32 var_a2_2;
  u32 var_a2_3;
  setHeapMode(0);
  resetHeap();
  func_8000828C();
  clearTrackMarkerCounters();
  resetLightingDefaults();
  row = 0; p = &D_80109688;
  do
  {
    *p = 0; row += 1; p += 1;
  }
  while (row < 6U);
  row = 0; p2 = &D_8010A500;
  do
  {
    *p2 = 0; row += 1; p2 += 1;
  }
  while (row < 4U);
  row = 0; totalRow = &gBonusTotalCount; collectedRow = &gBonusCollectedCount;
  do
  {
    col = 0; totalPtr = totalRow; collectedPtr = collectedRow;
    loop_6:
    *collectedPtr = 0;

    *totalPtr = 0; totalPtr += 1; col += 1; collectedPtr += 1;
    if (col < 6U)
    {
      goto loop_6;
    }
    totalRow += 7; row += 1; collectedRow += 7;
  }
  while (row < 6U);
  D_8010302C = 0; D_800CA31C = allocZeroedTag15Block(totalPtr, col, row, collectedRow);
  setupViewportsForPlayerCount();
 do { u8 reset = 0xFF; D_801032AC = 0xA0; D_8010D374 = 0x60; gObjectListHead = 0; gBaseColorB = reset; gBaseColorG = reset; gBaseColorR = reset; D_80112F88 = reset; D_80107B60 = reset; D_80100784 = reset; D_80103041 = 0; D_8010302A = 0; D_8010957C = 0; D_80103EB1 = 0; D_80115318 = 8; D_8010A3C4 = 0; D_80109A34 = 0xEF; D_80109684 = 0x40; D_8010A4B8 = 0x10; D_80110DB1 = 8; D_80107ECE = 0; D_80108F94 = reset; D_80103020 = 0; D_80107ECF = 0; D_8010D2B8 = reset; D_8010A2CC = 0; D_8010D36C = 0; D_801002E4 = 0; D_80107ECD = 0x80; D_801093A0 = 0; } while (0);
  D_801002E5 = 0; D_80110CA8 = 0x80; D_80100300 = 0; D_8010A91C = 0; gTrackSpecialMarkerFlag = 0; D_80117734 = 0; gTrackMarkerSpawned = 0; D_8010D2B0 = 0; D_80107ECC = 0; D_80109A35 = 0; gChasedObject = 0;
}

