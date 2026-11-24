typedef struct { s32 w0; s32 w1; } Gfx;
typedef struct { s32 x; } W;
s32 emitScissorFromWindow();
void appendProjectionViewportCommands(void);
void applyFogColorMode(s32, s32);
s32 appendMatrixAndLightCommands(void *);
extern s32 gGeometryModeSetupDL;
extern void *D_801002FC;
extern s32 gCurCombineSetup;
extern void *D_8010A4B4;
extern W D_8010A4D8;
extern s32 gCurGeometryModeSetup;
extern s32 gRenderMode;
extern void * volatile sDisplayListCursor;
extern void *sRenderState;
/* Emits display list commands to draw a full-screen solid-color overlay (black or white by view flags), then restores the render state. */ void renderSolidColorOverlay(void *viewport)
{
  register s32 temp_a1;
  void *state;
  unsigned int redChannel;
  register s32 greenChannel;
  s32 blue;
  int overlayDl;
  void *tail;
  s32 viewFlags;
  void *temp_a0;
  void *temp_a2;
  register void *end;
  void *temp_v1;
  void *temp_v1_2;
  void *temp_v1_4;
  emitScissorFromWindow();
  if (gRenderMode != 1)
  {
    gRenderMode = 1;
    appendMatrixAndLightCommands(viewport);
  }
  if (gCurGeometryModeSetup != 8)
  {
    temp_v1 = sDisplayListCursor;
    gCurGeometryModeSetup = 8;
    sDisplayListCursor = temp_v1 + 8;
    *((s32 *) (((char *) temp_v1) + 0)) = 0xDE000000;
    *((s32 **) (((char *) temp_v1) + 4)) = &gGeometryModeSetupDL;
  }
  if (gCurCombineSetup != 2)
  {
    temp_v1_2 = sDisplayListCursor;
    gCurCombineSetup = 2;
    sDisplayListCursor = temp_v1_2 + 8;
    *((s32 *) (((char *) temp_v1_2) + 0)) = 0xFC419883;
    *((s32 *) (((char *) temp_v1_2) + 4)) = 0xFF32FF7F;
  }
  applyFogColorMode((s32) viewport, 2);
  end = D_801002FC;
  *((s32 *) (((char *) end) + 0)) = 0xDF000000;
  *((s32 *) (((char *) end) + 4)) = 0;
  viewFlags = *((s32 *) (((char *) viewport) + 0x100));
  D_801002FC = end + 8;
  if (viewFlags & 2)
  {
    greenChannel = 0;
    redChannel = 0;
    blue = 0xFF;
  }
  else
  {
    if (viewFlags & 4)
        return;
    temp_v1_4 = sDisplayListCursor;
    sDisplayListCursor = temp_v1_4 + 8;
    *((s32 *) (((char *) temp_v1_4) + 0)) = 0xFB000000;
    *((s32 *) (((char *) temp_v1_4) + 4)) = 0xFF;
    greenChannel = 0xFF;
    blue = 0xFF;
    redChannel = 0xFF;
  }
  {
    temp_a0 = sDisplayListCursor;

    *((s32 *) (((char *) temp_a0) + 0)) = 0xFA000000;
    {
      u32 packed = (redChannel << 24) | (blue << 16);
      u32 green = greenChannel << 8;
      state = sRenderState;
      *((s32 *) (((char *) temp_a0) + 4)) = packed | green | 0xFF;
    }
    *((s32 *) (((char *) temp_a0) + 8)) = 0xFB000000;
    *((s32 *) (((char *) temp_a0) + 0xC)) = 0xFF;
    *((s32 *) (((char *) temp_a0) + 0x10)) = 0xDE000000;
    overlayDl = *((s32 *) (((char *) state) + 0x1B68));
    temp_a1 = gRenderMode;
    sDisplayListCursor = temp_a0 + 8;
    sDisplayListCursor = temp_a0 + 0x10;
    sDisplayListCursor = temp_a0 + 0x18;
    *((s32 *) (((char *) temp_a0) + 0x14)) = overlayDl;
    if (temp_a1 != 0)
    {
      gRenderMode = 0;
      appendProjectionViewportCommands();
    }
    {
    void *tailState;
    tail = D_8010A4B4;
    temp_a2 = sDisplayListCursor;
    tailState = sRenderState;
    *((s32 *) (((char *) tail) + 0)) = 0xDF000000;
    *((s32 *) (((char *) tail) + 4)) = 0;
    *((s32 *) (((char *) temp_a2) + 0)) = 0xDE000000;
    ((Gfx *)temp_a2)->w1 = *((s32 *) (((char *) tailState) + 0x1C70));
    D_8010A4B4 = tail + 8;
    sDisplayListCursor = temp_a2 + 8;
    temp_a1 = D_8010A4D8.x;
    temp_a2 += 8;
    applyFogColorMode((s32) viewport, temp_a1);
    }
  }
}


