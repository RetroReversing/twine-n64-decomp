s32 emitScissorFromWindow();
s32 applyFogColorMode();
s32 disableTextureFilterAndSetUiDisplayList(void);
s32 drawSprite();
s32 drawSprite8bpp();
s32 drawTextBox();
s32 setScissorRect();
extern s8 D_800C0738;
extern s8 gTextureFilterEnabled;
extern s32 D_8010A4D8;
extern s32 gHiResScreen;
extern void *sDisplayListCursor;
typedef struct 
{
  unsigned char pad[40];
  int value;
} __repair_field_28;
typedef struct 
{
  int value;
} __repair_field_0;
typedef struct 
{
  unsigned char pad[8];
  int value;
} __repair_field_8;
typedef struct 
{
  unsigned char pad[20];
  int value;
} __repair_field_14;
typedef struct 
{
  unsigned char pad[16];
  int value;
} __repair_field_10;
typedef struct { s32 w0; s32 w1; } Gfx_;
#define GFX(a, b) { Gfx_ *_g = (Gfx_ *) sDisplayListCursor; sDisplayListCursor = _g + 1; _g->w0 = (a); _g->w1 = (b); }
inline static int inline_fn(__repair_field_28 *arg0)
{
  return arg0->value;
}

inline static unsigned inline_fn2(unsigned arg0)
{
  return (arg0 >> 0x18) << 0x18;
}

/* Draws every UI element on the given layer: sets its scissor, then emits fill/outline colors and draws it, with an optional offset shadow pass. */
void drawUiElementsForLayer(void *uiContext, s32 arg1, s32 layer)
{
  s8 *__base_D_800C0738;
  s32 sp14;
  u8 sp1F;
  register f32 originX;
  f32 originY;
  void *temp_v1_4;
  void *temp_v1_3;
  u16 var_a1;
  unsigned int fillColor;
  unsigned outlineColor;
  u32 var_a3;
  void *element;
  unsigned char var_v0;
  u16 temp_v1;
  void *temp_v1_2;
  void *temp_a3_2;
  void *temp_a3;
  sp14 = layer;
  element = *((void **) (((char *) uiContext) + 4));
  originX = (*((f32 *) (((char *) uiContext) + 0x50))) + (*((f32 *) (((char *) uiContext) + 0x60)));
  sp1F = 1;
  originY = (*((f32 *) (((char *) uiContext) + 0x58))) + (*((f32 *) (((char *) uiContext) + 0x64)));
  if (element != NULL)
  {
    do
    {
      if (((((u32) inline_fn((__repair_field_28 *) element)) >> 2) & 0x3F) == sp14)
      {
        fillColor = ((volatile __repair_field_10 *) element)->value;
        var_v0 = (u8)fillColor;
        temp_v1 = *((u16 *) (((char *) element) + 0x1E));
        do
        {
          outlineColor = ((__repair_field_14 *) element)->value;
        }
        while (0);
        if (temp_v1 & 0x1000)
        {
          u16 top = *(volatile u16 *) ((char *) element + 0x22);
          u32 bottom = *(u8 *) ((char *) element + 0x28);
          int hiRes = *(int *) &gHiResScreen;
          u32 left = *(u16 *) ((char *) element + 0x20);
          u32 right = *(u16 *) ((char *) element + 0x24);
          if (hiRes)
          {
            bottom <<= 1;
            top <<= 1;
          }
          setScissorRect(left, top & 0xFFFF, right, bottom);
        }
        else
          if (temp_v1 & 0x2000)
        {
          emitScissorFromWindow(uiContext);
        }
        else
          if (var_v0 >= 5U)
        {
          if (sp1F == 1)
          {
            disableTextureFilterAndSetUiDisplayList();
            sp1F = 0;
            applyFogColorMode(uiContext, D_8010A4D8);
          }
          if (fillColor & 0xFF)
          {
            if ((*((u16 *) (((char *) element) + 0x1E))) & 0x400)
            {
              if (!gTextureFilterEnabled)
              {
                temp_v1_2 = sDisplayListCursor;
                gTextureFilterEnabled = 1;
                sDisplayListCursor = temp_v1_2 + 8;
                ((__repair_field_0 *) temp_v1_2)->value = 0xE3001201;
                *((s32 *) (((char *) temp_v1_2) + 4)) = 0x2000;
              }
            }
            else
              if (gTextureFilterEnabled)
            {
              void *temp_a0;
              temp_a0 = sDisplayListCursor;
gTextureFilterEnabled = 0;
sDisplayListCursor = temp_a0 + 8;
((__repair_field_0 *) temp_a0)->value = 0xE3001201;
*((s32 *) (((char *) temp_a0) + 4)) = 0;
}
if ((*((s32 *) (((char *) element) + 0x18))) != 0)
{
if ((*((u16 *) (((char *) element) + 0x1E))) & 0x20)
{
                __base_D_800C0738 = &D_800C0738;
                *__base_D_800C0738 = 1;
                GFX(0xFA000000, var_v0);
                GFX(0xFB000000, 0);
                drawTextBox((s32) (originX + 1.0f), (s32) (originY + 1.0f), element);
              }
              D_800C0738 = 0;
              GFX(0xFA000000, (((((fillColor >> 0x18) << 0x18) | ((((fillColor) >> 0x10) & 0xFF) << 0x10)) | (fillColor & 0xFF00)) | var_v0));
              GFX(0xFB000000, (((outlineColor >> 0x18) << 0x18) | ((((outlineColor) >> 0x10) & 0xFF) << 0x10) | (outlineColor & 0xFF00)));
drawTextBox(((s32) originX), ((s32) originY), element);
            }
            else
            {
              void *temp_a0;
              if ((*((u16 *) (((char *) element) + 0x1E))) & 0x20)
              {
                temp_a3_2 = sDisplayListCursor;
                sDisplayListCursor = temp_a3_2 + 8;
                ((Gfx_ *) temp_a3_2)->w0 = 0xFA000000;
                ((Gfx_ *) temp_a3_2)->w1 = var_v0;
                GFX(0xFB000000, 0);
                if ((inline_fn((__repair_field_28 *) element) & 3) == 1)
                {
                  GFX(0xFC119623, 0xFF2FFFFF);
                  GFX(0xE3001001, 0x8000);
                  drawSprite8bpp((s32) (originX + 1.0f), (s32) (originY + 1.0f), element, temp_a3_2);
                }
                else
                {
                  drawSprite((s32) (originX + 1.0f), (s32) (originY + 1.0f), element, temp_a3_2);
                }
              }
              GFX(0xFA000000, (((((fillColor >> 0x18) << 0x18) | ((((fillColor) >> 0x10) & 0xFF) << 0x10)) | (fillColor & 0xFF00)) | var_v0));
              GFX(0xFB000000, (((outlineColor >> 0x18) << 0x18) | ((((outlineColor) >> 0x10) & 0xFF) << 0x10) | (outlineColor & 0xFF00)));
              if ((inline_fn((__repair_field_28 *) element) & 3) == 1)
              {
                drawSprite8bpp(((s32) originX), ((s32) originY), element);
              }
              else
              {
                drawSprite(((s32) originX), ((s32) originY), element);
              }
            }
          }
        }
      }
      if (1)
      {
      }
      element = *((void **) (((char *) element) + 4));
    }
    while (element != NULL);
  }
  if (!gTextureFilterEnabled)
  {
    temp_v1_4 = sDisplayListCursor;
    sDisplayListCursor = temp_v1_4 + 8;
    ((__repair_field_0 *) temp_v1_4)->value = 0xE3001201;
    *((s32 *) (((char *) temp_v1_4) + 4)) = 0x2000;
  }
}
