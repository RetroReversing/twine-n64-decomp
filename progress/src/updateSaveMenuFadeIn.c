s32 setSaveMenuState();
s32 replaceMenuMarker();
s32 setSaveMenuPage();
s32 isMenuButtonPressed();
s32 setStateMachineState();
s32 setObjectAlpha();
extern s32 sSaveMenuFlagsB;
extern s32 sSaveMenuColorIdle;
extern char D_800BD8C4[];
extern s32 gMenuSoundParams;
extern void *sActiveMenu;
extern void *gSaveMenuState;
/* Per-frame update of the save menu: fades items in as a counter advances, and on confirm switches the menu state; otherwise counts down and returns to the previous menu. */ void updateSaveMenuFadeIn(void)
{
  void *activeMenu;
  s32 __repair_operand;
  s16 fadeDelta;
  s16 menuTimer;
  s16 newTimer;
  u16 alpha;
  s32 itemIndex;
  s32 var_v0;
  u32 confirmPressed;
  void *temp_v0;
  void *temp_v1;
  void *temp_v1_2;
  void *item;
  setObjectAlpha(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 0x80);
  confirmPressed = isMenuButtonPressed(0x24) & 0xFF;
  if (((s8) confirmPressed) != 0)
  {
    setObjectAlpha(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 0xFF);
    *((s32 **) (((char *) gSaveMenuState) + 0xC)) = D_800BD8C4;
    setSaveMenuPage(1, gMenuSoundParams, 0xA);
    setStateMachineState(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 4);
    replaceMenuMarker(gSaveMenuState + 0x1C, 3, 0x2A);
    temp_v0 = *((void **) (((char *) gSaveMenuState) + 0x1C));
    if (temp_v0 != NULL)
    {
      *((s16 *) (((char *) temp_v0) + 0x26)) = 0;
      return;
    }
    return;
  }
  temp_v1 = *((void **) (((char *) gSaveMenuState) + 0x1C));
  if (temp_v1 != NULL)
  {
    *((s32 *) (((char *) temp_v1) + 0x10)) = (s32) (sSaveMenuFlagsB | 0xFF);
    *((u16 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x22)) = (u16) (*((u16 *) (((char *) gSaveMenuState) + 0x32)));
    *((s16 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x20)) = 0;
    *((s16 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x26)) = 0x140;
    *((s8 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x29)) = 0x16;
    temp_v1_2 = *((void **) (((char *) gSaveMenuState) + 0x1C));
    *((u16 *) (((char *) temp_v1_2) + 0x1E)) &= 0xFEFF;
    *((u16 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x1E)) = 2U;
  }
  {
    void *state = gSaveMenuState;
    if (((u16) (*((u16 *) (((char *) state) + 0x32)))) < 0xFAU)
    {
      itemIndex = 0;
      if (confirmPressed < ((u8) (*((u8 *) (((char *) (*((s32 **) (((char *) state) + 0x10)))) + 5)))))
      {
        s32 k255 = 0xFF;
        void *loopItems = state;
        do
        {
          __repair_operand = *((s32 *) (((char *) (*((s32 **) (((char *) state) + 0x10)))) + 0));
          item = ((itemIndex & 0xFFFF) * 0x28) + __repair_operand;
          if ((*((s32 *) (((char *) item) + 8))) != 0)
          {
            fadeDelta = (*((u16 *) (((char *) state) + 0x32))) - (*((u16 *) (((char *) item) + 0x1A)));
            alpha = 0xFF;
            if (fadeDelta < 0)
            {
              if (((-fadeDelta) * 0x16) >= 0)
              {
                if (((-fadeDelta) * 0x16) >= 0x100)
                {
                  var_v0 = 0;
                }
                else
                {
                  var_v0 = k255 - ((-fadeDelta) * 0x16);
                }
              }
              else
              {
                var_v0 = 0xFF;
              }
              alpha = var_v0;
            }
            *((s32 *) (((char *) (*((void **) (((char *) (((itemIndex & 0xFFFF) * 0x28) + (*(*((s32 **) (((char *) loopItems) + 0x10)))))) + 8)))) + 0x10)) = (s32) (((*(s32 *)((char *)&sSaveMenuColorIdle)) & (~0xFF)) | (alpha & 0xFFFF));
          }
          state = gSaveMenuState;
          itemIndex += 1;
        }
        while (((u32) (itemIndex & 0xFFFF)) < ((u8) (*((u8 *) (((char *) (*((s32 **) (((char *) state) + 0x10)))) + 5)))));
      }
      { u16 t = *((u16 *) (((char *) gSaveMenuState) + 0x32));
      activeMenu = sActiveMenu;
      *((u16 *) (((char *) gSaveMenuState) + 0x32)) = t + 6; 
      do { newTimer = 0x96; } while (0);}
      goto block_23;
    }
  }
  activeMenu = sActiveMenu;
  menuTimer = *((s16 *) (((char *) activeMenu) + 0x7C));
  if (menuTimer == 0)
  {
    setSaveMenuState(activeMenu, 0x17);
    *((u16 *) (((char *) gSaveMenuState) + 0x32)) = 0U;
    return;
  }
  newTimer = menuTimer - 1;
  block_23:
  *((s16 *) (((char *) activeMenu) + 0x7C)) = newTimer;

}


