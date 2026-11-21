s32 func_800269B4(void *, s32, s32);
s32 func_8002778C();
s32 func_800278AC(s32, s32, s32);
s32 func_80027C60(s32);
s32 func_8002FBD4(s32, s32);
s32 func_80030644(s32, s32);
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

void func_80028A7C(void)
{
  s32 var_a0_2;
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
  s32 var_a1;
  s32 var_a2;
  u16 temp_v0_3;
  u16 temp_v0_6;
  void *temp_v0;
  void *temp_v0_7;
  void *temp_v1;
  void *temp_v1_3;
  if (func_80027C60(0x24) & 0xFF)
  {
    func_80030644(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 0xFF);
    *((s32 **) (((char *) gSaveMenuState) + 0xC)) = &D_800BD8C4;
    func_800278AC(1, gMenuSoundParams, 0xA);
    func_8002FBD4(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 4);
    func_800269B4(gSaveMenuState + 0x1C, 3, 0x2A);
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
    var_a2 = 0;
    state = gSaveMenuState;
    if ((((u32) temp_v1_2) + 1) <= ((u8) (*((u8 *) (((char *) (*((s32 **) (((char *) state) + 0x10)))) + 5)))))
    {
      loopState = state;
      idle = &sSaveMenuColorIdle;
      do
      {
        temp_v1_3 = ((char *) ((var_a2 & 0xFFFF) * 0x28)) + inline_fn(state);
        if ((*((s32 *) (((char *) temp_v1_3) + 8))) != 0)
        {
          temp_v0_2 = (*((u16 *) (((char *) state) + 0x32))) - (*((u16 *) (((char *) temp_v1_3) + 0x1A)));
          var_a1 = 0;
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
            var_a1 = var_a0;
          }
          *((s32 *) (((char *) (*((void **) (((char *) (((var_a2 & 0xFFFF) * 0x28) + (*(*((s32 **) (((char *) loopState) + 0x10)))))) + 8)))) + 0x10)) = (s32) (((*idle) & (~0xFF)) | (var_a1 & 0xFFFF));
        }
        state = gSaveMenuState;
        var_a2 += 1;
      }
      while (((u32) (var_a2 & 0xFFFF)) < ((u8) (*((u8 *) (((char *) (*((s32 **) (((char *) state) + 0x10)))) + 5)))));
    }
    temp_v0_3 = (*((u16 *) (((char *) gSaveMenuState) + 0x32))) + 6;
    *((u16 *) (((char *) gSaveMenuState) + 0x32)) = temp_v0_3;
    if (((u32) (temp_v0_3 & 0xFFFF)) >= 0xF6U)
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
      void *saved = state;
      temp_v0_4 = *((s16 *) (((char *) active) + 0x7C));
      if (((s16) temp_v0_4) > 0)
      {
        temp_v0_5 = temp_v0_4 - 1;
        *((s16 *) (((char *) active) + 0x7C)) = temp_v0_5;
        if ((temp_v0_5 << 0x10) == 0)
        {
          temp_v0_6 = *((u16 *) (((char *) saved) + 0x14));
          switch (temp_v0_6)
          {
            case 1:
              var_a0_2 = 2;
              goto play_sound;

            case 2:
              var_a0_2 = 3;
              goto play_sound;

            case 3:
              var_a0_2 = 4;
              goto play_sound;

            case 4:
              var_a0_2 = 5;
              goto play_sound;

            case 5:
              var_a0_2 = 6;
              goto play_sound;

            case 6:
              var_a0_2 = 7;
              goto play_sound;

            case 7:
              var_a0_2 = 8;
              goto play_sound;

            case 8:
              var_a0_2 = 9;
              goto play_sound;

            case 9:
              var_a0_2 = 10;
              goto play_sound;

            case 10:
              var_a0_2 = 11;
              goto play_sound;

            case 11:
              var_a0_2 = 12;
              goto play_sound;

            case 12:
              var_a0_2 = 13;
              goto play_sound;

            case 13:
              var_a0_2 = 14;
              goto play_sound;

            case 14:
              var_a0_2 = 15;
              goto play_sound;

            case 15:
              var_a0_2 = 16;
              play_sound:
            func_800278AC(var_a0_2, gMenuSoundParams & (~0xFF), 0x16);

              break;

            case 16:
              func_80030644(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 0xFF);
              *((s32 **) (((char *) gSaveMenuState) + 0xC)) = &D_800BD8C4;
              func_800278AC(1, gMenuSoundParams, 0xA);
              func_8002FBD4(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 4);
              func_800269B4(gSaveMenuState + 0x1C, 3, 0x2A);
              temp_v0_7 = *((void **) (((char *) gSaveMenuState) + 0x1C));
              if (temp_v0_7 != NULL)
            {
              *((s16 *) (((char *) temp_v0_7) + 0x26)) = 0;
            }
              break;

          }

          func_8002778C();
          *((u16 *) (((char *) gSaveMenuState) + 0x32)) = 0U;
        }
      }
    }
  }
}

