s32 replaceMenuMarker(void *, s32, s32);
s32 hideSaveMenu();
s32 setSaveMenuPage(s32, s32, s32);
s32 isMenuButtonPressed(s32);
s32 setStateMachineState(s32, s32);
s32 setObjectAlpha(s32, s32);
extern s32 D_800BD8C4;
extern s32 gMenuSoundParams;
extern void *gSaveMenuState;
extern void *sActiveMenu;
extern s32 sSaveMenuColorIdle;
extern s32 sSaveMenuFlagsB;
inline static s32 inline_fn(void *arg0)
{
  return *((s32 *) (((char *) (*((s32 **) (((char *) arg0) + 0x10)))) + 0));
}

/* Fades in the save menu entries, then counts down and plays the sound for the current menu state. */
void updateSaveMenuFade(void)
{
  s32 soundId;
  s16 temp_v0_2;
  unsigned short temp_v0_4;
  s32 temp_v0_5;
  void *state;
  void *loopState;
  volatile s32 *idle;
  s16 temp_v1_2;
  s16 var_v0;
  s32 temp_v1_4;
  s32 var_a0;
  s32 alpha;
  u16 slot;
  u16 fadeTimer;
  u16 menuState;
  void *temp_v0;
  void *temp_v0_7;
  void *temp_v1;
  void *temp_v1_3;
  if (isMenuButtonPressed(0x24) & 0xFF)
  {
    setObjectAlpha(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 0xFF);
    *((s32 **) (((char *) gSaveMenuState) + 0xC)) = &D_800BD8C4;
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
    *((s16 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x1E)) = 0x102;
  }
  temp_v1_2 = *((s16 *) (((char *) sActiveMenu) + 0x7C));
  if (temp_v1_2 == 0)
  {
    slot = 0;
    state = gSaveMenuState;
    if (((u32) temp_v1_2) < ((u8) (*((u8 *) (((char *) (*((s32 **) (((char *) state) + 0x10)))) + 5)))))
    {
      loopState = state;
      idle = &sSaveMenuColorIdle;
      do
      {
        temp_v1_3 = ((char *) ((slot & 0xFFFF) * 0x28)) + inline_fn(state);
        if ((*((s32 *) (((char *) temp_v1_3) + 8))) != 0)
        {
          temp_v0_2 = (*((u16 *) (((char *) state) + 0x32))) - (*((u16 *) (((char *) temp_v1_3) + 0x1A)));
          alpha = 0;
          if (temp_v0_2 <= 0)
          {
            temp_v1_4 = (temp_v0_2 - (temp_v0_2 << 3)) << 1;
            if (temp_v1_4 >= 0)
            {
              var_a0 = 0xFF;
              if (temp_v1_4 < 0x100)
              {
                var_a0 = temp_v1_4;
              }
            }
            else
            {
              var_a0 = 0;
            }
            alpha = var_a0;
          }
          *((s32 *) (((char *) (*((void **) (((char *) (((slot & 0xFFFF) * 0x28) + (*(*((s32 **) (((char *) loopState) + 0x10)))))) + 8)))) + 0x10)) = (s32) (((*idle) & (~0xFF)) | (alpha & 0xFFFF));
        }
        state = gSaveMenuState;
        slot += 1;
      }
      while (((u32) (slot & 0xFFFF)) < ((u8) (*((u8 *) (((char *) (*((s32 **) (((char *) state) + 0x10)))) + 5)))));
    }
    fadeTimer = (*((u16 *) (((char *) gSaveMenuState) + 0x32))) + 6;
    *((u16 *) (((char *) gSaveMenuState) + 0x32)) = fadeTimer;
    if (((u32) (fadeTimer & 0xFFFF)) >= 0xF6U)
    {
      void *active;
      if ((*((u16 *) (((char *) gSaveMenuState) + 0x14))) == 0x10)
      {
        active = sActiveMenu;
        *((s16 *) (((char *) active) + 0x7C)) = 0x4B;
      }
      else
      {
        active = sActiveMenu;
        *((s16 *) (((char *) active) + 0x7C)) = 1;
      }
      goto block_24;
    }
  }
  else
  {
    block_24:
    state = gSaveMenuState;

    if ((*((u16 *) (((char *) state) + 0x32))) >= 0xF6U)
    {
      void *active = sActiveMenu;
      if ((*((s16 *) (((char *) active) + 0x7C))) > 0)
      {
        (*((s16 *) (((char *) active) + 0x7C)))--;
        if ((*((s16 *) (((char *) active) + 0x7C))) == 0)
        {
          menuState = *((u16 *) (((char *) state) + 0x14));
          switch (menuState)
          {
            case 1:
              soundId = 2;
              goto play_sound;

            case 2:
              soundId = 3;
              goto play_sound;

            case 3:
              soundId = 4;
              goto play_sound;

            case 4:
              soundId = 5;
              goto play_sound;

            case 5:
              soundId = 6;
              goto play_sound;

            case 6:
              soundId = 7;
              goto play_sound;

            case 7:
              soundId = 8;
              goto play_sound;

            case 8:
              soundId = 9;
              goto play_sound;

            case 9:
              soundId = 10;
              goto play_sound;

            case 10:
              soundId = 11;
              goto play_sound;

            case 11:
              soundId = 12;
              goto play_sound;

            case 12:
              soundId = 13;
              goto play_sound;

            case 13:
              soundId = 14;
              goto play_sound;

            case 14:
              soundId = 15;
              goto play_sound;

            case 15:
              soundId = 16;
              play_sound:
            setSaveMenuPage(soundId, gMenuSoundParams & (~0xFF), 0x16);

              break;

            case 16:
              setObjectAlpha(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 0xFF);
              *((s32 **) (((char *) gSaveMenuState) + 0xC)) = &D_800BD8C4;
              setSaveMenuPage(1, gMenuSoundParams, 0xA);
              setStateMachineState(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 4);
              replaceMenuMarker(gSaveMenuState + 0x1C, 3, 0x2A);
              temp_v0_7 = *((void **) (((char *) gSaveMenuState) + 0x1C));
              if (temp_v0_7 != NULL)
            {
              *((s16 *) (((char *) temp_v0_7) + 0x26)) = 0;
            }
              break;

          }

          hideSaveMenu();
          *((u16 *) (((char *) gSaveMenuState) + 0x32)) = 0U;
        }
      }
    }
  }
}
