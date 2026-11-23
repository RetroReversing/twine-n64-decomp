s32 func_80026424();
s32 func_800269B4();
s32 func_800278AC();
s32 func_80027C60();
s32 func_8002FBD4();
s32 func_80030644();
extern s32 sSaveMenuFlagsB;
extern s32 sSaveMenuColorIdle;
extern char D_800BD8C4[];
extern s32 gMenuSoundParams;
extern void *sActiveMenu;
extern void *gSaveMenuState;
void func_800287DC(void)
{
  void *menu;
  s32 __repair_operand;
  s16 temp_v0_2;
  s16 temp_v0_3;
  s16 var_v0_2;
  u16 var_a1;
  s32 var_a2;
  s32 var_v0;
  u32 temp_a3;
  void *temp_v0;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_3;
  func_80030644(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 0x80);
  temp_a3 = func_80027C60(0x24) & 0xFF;
  if (((s8) temp_a3) != 0)
  {
    func_80030644(*((s32 *) (((char *) gSaveMenuState) + 0x20)), 0xFF);
    *((s32 **) (((char *) gSaveMenuState) + 0xC)) = D_800BD8C4;
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
    temp_v1_2 = *((void **) (((char *) gSaveMenuState) + 0x1C));
    *((u16 *) (((char *) temp_v1_2) + 0x1E)) &= 0xFEFF;
    *((u16 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x1E)) = 2U;
  }
  {
    void *items = gSaveMenuState;
    if (((u16) (*((u16 *) (((char *) items) + 0x32)))) < 0xFAU)
    {
      var_a2 = 0;
      if (temp_a3 < ((u8) (*((u8 *) (((char *) (*((s32 **) (((char *) items) + 0x10)))) + 5)))))
      {
        s32 k255 = 0xFF;
        void *loopItems = items;
        do
        {
          __repair_operand = *((s32 *) (((char *) (*((s32 **) (((char *) items) + 0x10)))) + 0));
          temp_v1_3 = ((var_a2 & 0xFFFF) * 0x28) + __repair_operand;
          if ((*((s32 *) (((char *) temp_v1_3) + 8))) != 0)
          {
            temp_v0_2 = (*((u16 *) (((char *) items) + 0x32))) - (*((u16 *) (((char *) temp_v1_3) + 0x1A)));
            var_a1 = 0xFF;
            if (temp_v0_2 < 0)
            {
              if (((-temp_v0_2) * 0x16) >= 0)
              {
                if (((-temp_v0_2) * 0x16) >= 0x100)
                {
                  var_v0 = 0;
                }
                else
                {
                  var_v0 = k255 - ((-temp_v0_2) * 0x16);
                }
              }
              else
              {
                var_v0 = 0xFF;
              }
              var_a1 = var_v0;
            }
            *((s32 *) (((char *) (*((void **) (((char *) (((var_a2 & 0xFFFF) * 0x28) + (*(*((s32 **) (((char *) loopItems) + 0x10)))))) + 8)))) + 0x10)) = (s32) (((*(s32 *)((char *)&sSaveMenuColorIdle)) & (~0xFF)) | (var_a1 & 0xFFFF));
          }
          items = gSaveMenuState;
          var_a2 += 1;
        }
        while (((u32) (var_a2 & 0xFFFF)) < ((u8) (*((u8 *) (((char *) (*((s32 **) (((char *) items) + 0x10)))) + 5)))));
      }
      { u16 t = *((u16 *) (((char *) gSaveMenuState) + 0x32));
      menu = sActiveMenu;
      *((u16 *) (((char *) gSaveMenuState) + 0x32)) = t + 6; 
      do { var_v0_2 = 0x96; } while (0);}
      goto block_23;
    }
  }
  menu = sActiveMenu;
  temp_v0_3 = *((s16 *) (((char *) menu) + 0x7C));
  if (temp_v0_3 == 0)
  {
    func_80026424(menu, 0x17);
    *((u16 *) (((char *) gSaveMenuState) + 0x32)) = 0U;
    return;
  }
  var_v0_2 = temp_v0_3 - 1;
  block_23:
  *((s16 *) (((char *) menu) + 0x7C)) = var_v0_2;

}


