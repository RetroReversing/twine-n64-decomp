s32 getTextLength(void *);
void setMenuMarkersPalette(s32);
extern s32 sMenuMarkerColor;
extern u8 gMenuUseTextList;
extern void *gSaveMenuState;
extern s32 sSaveMenuColorIdle;
inline static int inline_fn(void *arg0)
{
  return -((((s32) arg0) & 0xFF) == 0);
}

inline static char *inline_fn2(void *arg0)
{
  return (char *) arg0;
}

/* Positions and colors a save-menu entry's pair of sprites from the entry's layout and slot state, then refreshes the menu. */
void layoutSaveMenuEntrySprites(void *entry, void *slotState)
{
  void **__base_gSaveMenuState;
  s32 var_a0;
  s32 var_v0_2;
  s32 var_v0_4;
  s32 var_v0_5;
  s32 var_v1;
  s32 var_v1_2;
  u16 posX;
  u16 var_v0_3;
  u8 mode;
  u8 temp_a0_4;
  void *temp_a0_2;
  void *sprites;
  void *slotArg;
  void *temp_v1;
  void *var_a1;
  s32 f1, f2; void *f3, *f4;
  sprites = *((void **) (((char *) entry) + 0));
  slotArg = slotState;
  if (sprites != NULL)
  {
    if (1)
    {
      void *spriteB = *((void **) (inline_fn2(sprites) + 4));
      if (spriteB != NULL)
      {
        mode = *((u8 *) (inline_fn2(entry) + 8));
        if (mode == 0xFE)
        {
          *((u16 *) (((char *) spriteB) + 0x22)) = *((u16 *) (((char *) entry) + 6));
          posX = *((u16 *) (((char *) entry) + 4));
          spriteB = *((void **) (((char *) sprites) + 4));
          posX += 0xD0;
        }
        else
        {
          if (mode == 0xFF)
          {
            *((u16 *) (((char *) spriteB) + 0x22)) = *((u16 *) (((char *) entry) + 6));
          }
          else
          {
            s32 count = getTextLength(*((void **) sprites));
            var_a1 = *((void **) (((char *) sprites) + 4));
            *((u16 *) (((char *) var_a1) + 0x22)) = (*((u16 *) (((char *) entry) + 6))) + (count * 11);
          }
          spriteB = *((void **) (((char *) sprites) + 4));
          posX = *((u16 *) (((char *) entry) + 4));
        }
        temp_v1 = spriteB;
        *((u16 *) (((char *) temp_v1) + 0x20)) = posX;
        {
          void *child;
          short mask = ~0xFC;
          if (gMenuUseTextList != 0)
          {
            child = *((void * volatile *) (((char *) sprites) + 4));
            var_v1 = *((s32 *) (((char *) child) + 0x28));
            do
            {
              var_v1 &= mask; var_v0_2 = inline_fn(slotArg) & 0x1C;
            }
            while (0);
          }
          else
          {
            child = *((void * volatile *) (((char *) sprites) + 4));
            do
            {
              var_v1 = *((s32 *) (((char *) child) + 0x28)); var_v1 = var_v1 & mask;
            }
            while (0);
            var_v0_2 = inline_fn(slotArg);
            var_v0_2 &= 7;
            var_v0_2 |= 2;
            var_v0_2 <<= 2;
          }
          var_v1 |= var_v0_2;
          *((s32 *) (((char *) child) + 0x28)) = var_v1;
        }
        {
          void *state = gSaveMenuState;
          if (state != NULL)
          {
            temp_a0_2 = *((void **) (((char *) state) + 0x1C));
            var_a1 = (void *) (-0x100);
            if (temp_a0_2 != NULL)
            {
              temp_v1 = *((void **) (((char *) sprites) + 4));
              var_v0_5 = sSaveMenuColorIdle;
              var_v0_5 &= ~0xFF;
              var_v1 = *(((u8 *) state) + 0x30); var_v0_5 |= var_v1;
              var_v0_5 &= ~0xFF;
              var_a0 = *(((u8 *) temp_a0_2) + 0x13); var_v0_5 |= var_a0;
              *((s32 *) (((char *) temp_v1) + 0x10)) = var_v0_5;
            }
          }
        }
      }
      temp_a0_2 = *((void **) (inline_fn2(sprites) + 0));
      if (temp_a0_2 != NULL)
      {
        if ((*((u8 *) (((char *) entry) + 8))) == 0xFF) { var_v0_3 = 0xA0; } else { var_v0_3 = *((u16 *) (((char *) entry) + 4)); }
        *((u16 *) (((char *) temp_a0_2) + 0x20)) = var_v0_3;
        *((u16 *) (inline_fn2(*((void **) (inline_fn2(sprites) + 0))) + 0x22)) = (u16) (*((u16 *) (((char *) entry) + 6)));
        {
          void *child;
          short mask = ~0xFC;
 do { if (gMenuUseTextList != 0) { child = *((void * volatile *) (((char *) sprites) + 0)); var_v1_2 = *((s32 *) (((char *) child) + 0x28)); var_v1_2 &= mask; do { var_v0_4 = inline_fn(slotArg) & 0x1C; } while (0); } else { child = *((void * volatile *) (((char *) sprites) + 0)); var_v1_2 = *((s32 *) (((char *) child) + 0x28)); do { var_v1_2 &= mask; var_v0_4 = inline_fn(slotArg); var_v0_4 &= 7; var_v0_4 |= 2; var_v0_4 <<= 2; } while (0); } } while (0);
          var_v1_2 |= var_v0_4;
          *((s32 *) (((char *) child) + 0x28)) = var_v1_2;
        }
        temp_a0_4 = *((u8 *) (inline_fn2(entry) + 8));
        if (temp_a0_4 == 0x80)
        {
          void *st = gSaveMenuState;
          s32 i = sSaveMenuColorIdle;
          temp_v1 = *((void **) sprites);
          *((s32 *) (((char *) temp_v1) + 0x10)) = (((i & (~0xFF)) | (*((u8 *) (((char *) st) + 0x30)))) & (~0xFF)) | (*((u8 *) (((char *) (*((void **) (((char *) st) + 0x1C)))) + 0x13)));
        }
        else if (temp_a0_4 == 0x81)
        {
          void *st = gSaveMenuState;
          s32 i = sMenuMarkerColor;
          temp_v1 = *((void **) sprites);
          *((s32 *) (((char *) temp_v1) + 0x10)) = (((i & (~0xFF)) | (*((u8 *) (((char *) st) + 0x30)))) & (~0xFF)) | (*((u8 *) (((char *) (*((void **) (((char *) st) + 0x1C)))) + 0x13)));
        }
        else
        {
          void *c = *((void **) sprites);
          void *st = gSaveMenuState;
          s32 i = sSaveMenuColorIdle;
          *((s32 *) (((char *) c) + 0x10)) = (i & (~0xFF)) | (*((u8 *) (((char *) st) + 0x30)));
        }
      }
      var_a0 = 2;
      if (gMenuUseTextList != 0)
      {
        if (sprites || sSaveMenuColorIdle)
        {
          var_a0 = 0;
        }
        else
        {
          var_a0 = 0;
        }
      }
      setMenuMarkersPalette(var_a0);
    }
  }
}
