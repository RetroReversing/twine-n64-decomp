inline static char *inline_fn234(char *arg0)
{
  return arg0 + 0;
}

s32 registerTrackMarkerParent(unsigned int, s32);
unsigned int setSceneParamWord(volatile unsigned char);
extern void *D_8010969C;
extern u8 D_8010A4C3;
extern u8 gBorderFlipFlag;
extern s32 gBorderSkipActive;
extern void *gMenuRootObject;
extern s32 gDefaultOrderObj;
extern s32 gSaveTotalSlots;
extern u8 gSceneFlagsB;
extern s32 gVisibleSaveSlotCount;
extern s32 osTvType;
extern void *gTrackMarkerParents[];
extern void *D_80109688;

/* Creates and positions the per-player camera viewports for the current split-screen layout (1, 2, 3 or 4 players) plus the extra overlay viewports. */ void setupViewportsForPlayerCount(void)
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

  x = 0; y = 0; switch (osTvType) { case 0: break; case 1: case 2: x = y; break; }
  if (gMenuRootObject == NULL) {
    registerTrackMarkerParent(4, gDefaultOrderObj);
  }
  setViewportRect(gTrackMarkerParents[4], cxI, cyF, 320.0f, 240.0f, (f32)x, (f32)y);
  *((u8 *) inline_fn234((char *) (&D_8010A4C3))) &= ~0x10;
  *((u8 *) (((char *) (&D_8010A4C3)) + (-2))) &= ~0x10;
  *(s32 *)((u8 *)gMenuRootObject + 0x100) |= 0x100;
  if (D_8010969C == NULL) {
    registerTrackMarkerParent(5, gDefaultOrderObj);
  }
  setViewportRect(gTrackMarkerParents[5], cxI, cyF, 320.0f, 240.0f, (f32)x, (f32)y);
  *((u8 *) inline_fn234((char *) (&D_8010A4C3))) &= ~0x20;
  *((u8 *) (((char *) (&D_8010A4C3)) + (-2))) &= ~0x20;
  gSceneFlagsB |= 0x20;
  *(s32 *)((u8 *)D_8010969C + 0x100) |= 0x100;
  if (gBorderSkipActive == 0) {
    if (D_80109688 == NULL) {
      registerTrackMarkerParent(0, gDefaultOrderObj);
    }
    setViewportRect(gTrackMarkerParents[0], cxF, cyI, 320.0f, 240.0f, (f32)x, (f32)y);
    setSceneParamWord(1);
  } else {
    for (i = 0; i < gSaveTotalSlots; i++) {
        if (gTrackMarkerParents[i] == NULL) {
          registerTrackMarkerParent(i, gDefaultOrderObj);
          setViewportRect(gTrackMarkerParents[i], cxF, cyI, cxI + cxI, cyF + cyF, (f32)x, (f32)y);
          if (i >= gVisibleSaveSlotCount) {
            if ((gVisibleSaveSlotCount == 3) & (i == 3)) {
              *((u8 *) inline_fn234((char *) (&D_8010A4C3))) |= 1 << i;
            } else {
              *((u8 *) inline_fn234((char *) (&D_8010A4C3))) &= ~(1 << i);
            }
            (((char *) (&D_8010A4C3)) - 1)[0] &= ~(1 << i);
            (((char *) (&D_8010A4C3)) - 1)[-1] &= ~(1 << i);
            *(s32 *)((u8 *)gTrackMarkerParents[i] + 0x100) |= 0x100;
          } else {
            *((u8 *) inline_fn234((char *) (&D_8010A4C3))) |= 1 << i;
          }
        }
    }
    switch (gVisibleSaveSlotCount) {
    case 1:
      if (gTrackMarkerParents[0] == NULL) {
        registerTrackMarkerParent(0, gDefaultOrderObj);
      }
      setViewportRect(gTrackMarkerParents[0], cxF, cyI, cxI + cxI, cyF + cyF, (f32)x, (f32)y);
      break;
    case 2:
      if (gTrackMarkerParents[0] == NULL) {
        registerTrackMarkerParent(0, gDefaultOrderObj);
      }
      if (gTrackMarkerParents[1] == NULL) {
        registerTrackMarkerParent(1, gDefaultOrderObj);
      }
      if (gBorderFlipFlag == 1) {
        f32 hx = cxF * 0.5f;
        setViewportRect(gTrackMarkerParents[0], hx, cyI, cxI, cyF + cyF, 1.0f, 1.0f);
        setViewportRect(gTrackMarkerParents[1], cxF + hx, cyI, cxI, cyF + cyF, 1.0f, 1.0f);
      } else {
        f32 hy = cyI * 0.5f;
        setViewportRect(gTrackMarkerParents[0], cxF, hy, cxI + cxI, cyF, 1.0f, 1.0f);
        setViewportRect(gTrackMarkerParents[1], cxF, cyI + hy, cxI + cxI, cyF, 1.0f, 1.0f);
      }
      setSceneParamWord(0);
      break;
    case 3:
      if (gTrackMarkerParents[0] == NULL) {
        registerTrackMarkerParent(0, gDefaultOrderObj);
      }
      if (gTrackMarkerParents[1] == NULL) {
        registerTrackMarkerParent(1, gDefaultOrderObj);
      }
      if (gTrackMarkerParents[2] == NULL) {
        registerTrackMarkerParent(2, gDefaultOrderObj);
      }
      if (gTrackMarkerParents[3] == NULL) {
        registerTrackMarkerParent(3, gDefaultOrderObj);
      }
      {
        f32 hx = cxF * 0.5f;
        f32 hy = cyI * 0.5f;
        setViewportRect(gTrackMarkerParents[0], hx, hy, cxI, cyF, 1.0f, 1.0f);
        setViewportRect(gTrackMarkerParents[1], hx + cxF, hy, cxI, cyF, 1.0f, 1.0f);
        setViewportRect(gTrackMarkerParents[2], hx, cyI + hy, cxI, cyF, 1.0f, 1.0f);
        setViewportRect(gTrackMarkerParents[3], hx + cxF, cyI + hy, cxI, cyF, 1.0f, 1.0f);
      }
      setSceneParamWord(0);
      break;
    case 4:
      if (gTrackMarkerParents[0] == NULL) {
        registerTrackMarkerParent(0, gDefaultOrderObj);
      }
      if (gTrackMarkerParents[1] == NULL) {
        registerTrackMarkerParent(1, gDefaultOrderObj);
      }
      if (gTrackMarkerParents[2] == NULL) {
        registerTrackMarkerParent(2, gDefaultOrderObj);
      }
      if (gTrackMarkerParents[3] == NULL) {
        registerTrackMarkerParent(3, gDefaultOrderObj);
      }
      {
        f32 hx = cxF * 0.5f;
        f32 hyA = cyI * 0.5f;
        f32 hyB = cyF * 0.5f;
        setViewportRect(gTrackMarkerParents[0], hx, hyA, cxI, cyF, 1.0f, 1.0f);
        setViewportRect(gTrackMarkerParents[1], hx + cxF, hyB, cxI, cyF, 1.0f, 1.0f);
        setViewportRect(gTrackMarkerParents[2], hx, cyI + hyA, cxI, cyF, 1.0f, 1.0f);
        setViewportRect(gTrackMarkerParents[3], hx + cxF, cyF + hyB, cxI, cyF, 1.0f, 1.0f);
      }
      setSceneParamWord(0);
      break;
    }
  }
  *(s32 *)((u8 *)gTrackMarkerParents[0] + 0x100) |= 0x40;
  *(s8 *)((u8 *)gTrackMarkerParents[0] + 0x142) = 4;
}
