inline static char *inline_fn234(char *arg0)
{
  return arg0 + 0;
}

s32 func_80048794(unsigned int, s32);
unsigned int func_800820B0(volatile unsigned char);
extern void *D_8010969C;
extern u8 D_8010A4C3;
extern u8 gBorderFlipFlag;
extern s32 gBorderSkipActive;
extern void *gMenuRootObject;
extern s32 gProbeObjectList;
extern s32 gSaveTotalSlots;
extern u8 gSceneFlagsB;
extern s32 gVisibleSaveSlotCount;
extern s32 osTvType;
extern void *sTrackMarkerTable[];
extern void *D_80109688;

void func_8007560C(void)
{
  f32 cxF = 160.0f;
  f32 cyI = 120.0f;
  f32 cxI = 160.0f;
  f32 cyF = 120.0f;
  unsigned long offsetSeed = 0;
  u32 x;
  u32 y;
  char *t4;
  void **p;
  register f64 var_fv1;
  s32 i;

  x = 0;
  if (osTvType) {
    y = 0;
    x = y;
  } else {
    y = 0;
  }
  if (gMenuRootObject == NULL) {
    if (sTrackMarkerTable) {
      func_80048794(4, gProbeObjectList);
    } else {
      func_80048794(4, gProbeObjectList);
    }
  }
  func_8004844C(gMenuRootObject, cxI, cyF, 320.0f, 240.0f, (f32)(var_fv1 = (f64) x), (f32)(f64)(s32)y);
  *((u8 *) inline_fn234((char *) (&D_8010A4C3))) &= ~0x10;
  *((u8 *) (((char *) (&D_8010A4C3)) + (-2))) &= ~0x10;
  *(s32 *)((u8 *)gMenuRootObject + 0x100) |= 0x100;
  if (D_8010969C == NULL) {
    func_80048794(5, gProbeObjectList);
  }
  func_8004844C(D_8010969C, cxI, cyF, 320.0f, 240.0f, (f32)(f64)x, (f32)(f64)(s32)y);
  *((u8 *) inline_fn234((char *) (&D_8010A4C3))) &= ~0x20;
  *((u8 *) (((char *) (&D_8010A4C3)) + (-2))) &= ~0x20;
  gSceneFlagsB |= 0x20;
  *(s32 *)((u8 *)D_8010969C + 0x100) |= 0x100;
  if (gBorderSkipActive == 0) {
    if (D_80109688 == NULL) {
      func_80048794(0, gProbeObjectList);
    }
    func_8004844C(D_80109688, cxF, cyI, 320.0f, 240.0f, (f32)(f64)x, (f32)(f64)y);
    func_800820B0(1);
  } else {
    if ((s32) y < gSaveTotalSlots) {
      i = 0;
      {
        t4 = ((char *) (&D_8010A4C3)) - 1;
      }
      p = (void **) (((char *) (&gMenuRootObject)) - 0x10);
      do {
        if (*p == NULL) {
          func_80048794(i, gProbeObjectList);
          func_8004844C(*p, cxF, cyI, cxI + cxI, cyF + cyF, (f32)(f64)x, (f32)(f64)y);
          if (i >= gVisibleSaveSlotCount) {
            if ((gVisibleSaveSlotCount == 3) & (i == 3)) {
              *((u8 *) inline_fn234((char *) (&D_8010A4C3))) |= 1 << i;
            } else {
              *((u8 *) inline_fn234((char *) (&D_8010A4C3))) &= ~(1 << i);
            }
            t4[0] &= ~(1 << i);
            t4[-1] &= ~(1 << i);
            *(s32 *)((u8 *)*p + 0x100) |= 0x100;
          } else {
            *((u8 *) inline_fn234((char *) (&D_8010A4C3))) |= 1 << i;
          }
        }
        i += 1;
        p += 1;
      } while (gSaveTotalSlots > i);
    }
    switch (gVisibleSaveSlotCount) {
    case 1:
      if (sTrackMarkerTable[0] == NULL) {
        func_80048794(0, gProbeObjectList);
      }
      func_8004844C(sTrackMarkerTable[0], cxF, cyI, cxI + cxI, cyF + cyF, (f32)(f64)x, (f32)(f64)y);
      break;
    case 2:
      if (sTrackMarkerTable[0] == NULL) {
        func_80048794(0, gProbeObjectList);
      }
      if (sTrackMarkerTable[1] == NULL) {
        func_80048794(1, gProbeObjectList);
      }
      if (gBorderFlipFlag == 1) {
        f32 hx = cxF * 0.5f;
        func_8004844C(sTrackMarkerTable[0], hx, cyI, cxI, cyF + cyF, 1.0f, 1.0f);
        func_8004844C(sTrackMarkerTable[1], cxF + hx, cyI, cxI, cyF + cyF, 1.0f, 1.0f);
      } else {
        f32 hy = cyI * 0.5f;
        func_8004844C(sTrackMarkerTable[0], cxF, hy, cxI + cxI, cyF, 1.0f, 1.0f);
        func_8004844C(sTrackMarkerTable[1], cxF, cyI + hy, cxI + cxI, cyF, 1.0f, 1.0f);
      }
      func_800820B0(0);
      break;
    case 3:
      if (sTrackMarkerTable[0] == NULL) {
        func_80048794(0, gProbeObjectList);
      }
      if (sTrackMarkerTable[1] == NULL) {
        func_80048794(1, gProbeObjectList);
      }
      if (sTrackMarkerTable[2] == NULL) {
        func_80048794(2, gProbeObjectList);
      }
      if (sTrackMarkerTable[3] == NULL) {
        func_80048794(3, gProbeObjectList);
      }
      {
        f32 hx = cxF * 0.5f;
        f32 hy = cyI * 0.5f;
        func_8004844C(sTrackMarkerTable[0], hx, hy, cxI, cyF, 1.0f, 1.0f);
        func_8004844C(sTrackMarkerTable[1], hx + cxF, hy, cxI, cyF, 1.0f, 1.0f);
        func_8004844C(sTrackMarkerTable[2], hx, cyI + hy, cxI, cyF, 1.0f, 1.0f);
        func_8004844C(sTrackMarkerTable[3], hx + cxF, cyI + hy, cxI, cyF, 1.0f, 1.0f);
      }
      func_800820B0(0);
      break;
    case 4:
      if (sTrackMarkerTable[0] == NULL) {
        func_80048794(0, gProbeObjectList);
      }
      if (sTrackMarkerTable[1] == NULL) {
        func_80048794(1, gProbeObjectList);
      }
      if (sTrackMarkerTable[2] == NULL) {
        func_80048794(2, gProbeObjectList);
      }
      if (sTrackMarkerTable[3] == NULL) {
        func_80048794(3, gProbeObjectList);
      }
      {
        f32 hx = cxF * 0.5f;
        f32 hyA = cyI * 0.5f;
        f32 hyB = cyF * 0.5f;
        func_8004844C(sTrackMarkerTable[0], hx, hyA, cxI, cyF, 1.0f, 1.0f);
        func_8004844C(sTrackMarkerTable[1], hx + cxF, hyB, cxI, cyF, 1.0f, 1.0f);
        func_8004844C(sTrackMarkerTable[2], hx, cyI + hyA, cxI, cyF, 1.0f, 1.0f);
        func_8004844C(sTrackMarkerTable[3], hx + cxF, cyF + hyB, cxI, cyF, 1.0f, 1.0f);
      }
      func_800820B0(0);
      break;
    }
  }
  *(s32 *)((u8 *)sTrackMarkerTable[0] + 0x100) |= 0x40;
  *(s8 *)((u8 *)sTrackMarkerTable[0] + 0x142) = 4;
}
