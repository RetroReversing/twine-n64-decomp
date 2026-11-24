typedef struct 
{
  u32 w0;
  u32 w1;
} FrameCommand;
typedef struct 
{
  u8 pad000[0x100];
  unsigned int flags;
  u8 pad104[0x20];
  f32 overlay;
  u8 pad128[4];
  f32 opacity;
  u8 pad130[4];
  u32 alpha;
  u8 pad138[0xA];
  s8 transition;
} FrameView;
typedef struct 
{
  u8 pad00[0x30];
  FrameCommand *commands;
  long commandBytes;
  u8 pad38[8];
  u8 buffer[0x750];
  FrameCommand *start;
} FrameSlot;
extern u64 osGetTime(void);
extern s32 osRecvMesg(void *, void **, s32);
extern void osViSwapBuffer(void *);
extern void func_80034DD0(void);
extern void emitRdpFramebufferSetup(void);
extern void emitFullScreenScissor(FrameView *);
extern void drawFilledScreenRect(FrameView *);
extern void drawUiElementsForLayer(FrameView *, u32, s32);
extern void renderCameraView(FrameView *, u32);
extern void emitScissorFromWindow(FrameView *);
extern void drawWindowFillRect(u8, u32, u8, u8, u8);
extern void drawLetterboxBars(FrameView *);
extern void func_80044410(s32);
extern void osWritebackDCache(void *, s32);
extern void waitForGfxMessage(void);
extern void postSpTaskMessage(FrameSlot *);
extern s32 __osDisableInt(void);
extern void __osRestoreInt(s32);
extern void vi_apply_context(void);
extern u8 D_800AE4B0;
extern u8 gTrackMarkerActiveMask;
extern u8 gSceneFlagsB;
extern u8 D_80113022;
extern u32 D_800B1BE0[];
extern s16 gFramesQueuedCount;
extern s16 gFramesCompletedCount;
extern s16 D_8010A4B0;
extern u16 D_80109B9C;
extern u16 gFramebufferCount;
extern f32 gAnimTime;
extern u64 D_800DD750[];
extern u64 D_800DD768[];
extern volatile u64 gUpdateLoopStartTime;
extern u8 *sRenderState;
extern u8 *gDisplayListPtr;
extern u8 *D_80109CB8;
extern u8 *D_801002FC;
extern u8 *D_8010A4B4;
extern void *gFramebuffers[];
extern u32 gGfxSyncQueue[];
extern u32 gFrameDoneMsgQueue[];
extern s32 gCurCombineSetup;
extern s32 gCurGeometryModeSetup;
extern s32 gCurrentFogColorMode;
extern s32 D_8010A4E4;
extern s32 D_80100C04;
extern s32 gRetraceFrameCount;
extern s32 gRenderMode;
extern FrameView *gTrackMarkerParents[];
extern FrameSlot *sMatrixPoolSlots[];
extern FrameCommand *sDisplayListCursor;
inline static f32 clamp_opacity(f32 value)
{
  return (value < 0.0f) ? (0.0f) : (value);
}

inline static int inline_fn()
{
  return ((u32) gDisplayListPtr) - 0x798;
}

inline static int inline_fn2(FrameCommand *arg0, int arg1)
{
  return ((u32) arg0) - arg1;
}

inline static int inline_fn23(u8 *arg0)
{
  return ((u32) arg0) - 0x16A0;
}

inline static float inline_fn234(f32 arg0)
{
  return arg0 * 255.0f;
}

inline static FrameView *inline_fn2345(FrameView *arg0)
{
  return arg0;
}

inline static u32 inline_fn23456(f32 arg0)
{
  return (u32) (arg0 * 255.0f);
}

inline static int inline_fn234567(u32 arg0, int arg1)
{
  return arg0 - arg1;
}

/* Draws per-view overlays and fades, closes the display list, waits for the previous frame, swaps framebuffers and submits the RSP task. */ void finishFrameAndSubmitDisplayList(void)
{
  short __repair_constant = -1;
  FrameSlot *slot = sMatrixPoolSlots[D_8010A4B0];
  register FrameCommand *start = slot->start;
  s32 *renderMode;
  u8 *buffer;
  u8 *segment1;
  u8 *segment2;
  u8 *segment3;
  u8 *segment4;
  s32 commandBytes;
  FrameView **entry;
  FrameView *view;
  FrameView *first;
  FrameView *p;
  u32 alpha32;
  FrameView *__repair_phase_view;
  FrameSlot *slotToSubmit;
  FrameView **layerEntry;
  u64 stamp;
  FrameCommand *cmd;
  FrameCommand *__repair_phase_cmd;
  u32 i;
  u32 mask;
  u32 __repair_phase_alpha;
  u32 __repair_phase___repair_phase_alpha;
  register s8 transitioning;
  s32 displayListBytes;
  s32 __repair_phase_layer;
  s32 __repair_phase___repair_phase_layer;
  f32 opacity;
  f32 zero;
  u8 *modeFlags;
  sRenderState = slot->buffer;
  gDisplayListPtr = 0x798 + ((u8 *) slot);
  D_80109CB8 = ((u8 *) slot) + 0x16A0;
  D_801002FC = ((u8 *) slot) + 0x1AA8;
  D_8010A4B4 = ((u8 *) slot) + 0x1BB0;
  gAnimTime += 1.0f;
  sDisplayListCursor = start;
  if (!start)
  {
    return;
  }
  gUpdateLoopStartTime = osGetTime();
  func_80034DD0();
  renderMode = &D_8010A4E4;
  if ((*renderMode) == 0)
  {
    emitRdpFramebufferSetup();
  }
  else
  {
    transitioning = 0;
    i = 0;
    D_80113022 = 0;
    do
    {
      buffer = sRenderState;
      segment1 = gDisplayListPtr;
      segment2 = D_80109CB8;
      segment3 = D_801002FC;
      segment4 = D_8010A4B4;
      *((u8 **) (buffer + 0x1658)) = segment1;
      *((u8 **) (buffer + 0x1A60)) = segment2;
      *((u8 **) (buffer + 0x1B68)) = segment3;
      *((u8 **) (buffer + 0x1C70)) = segment4;
      first = gTrackMarkerParents[i];
      gCurCombineSetup = __repair_constant;
      gCurGeometryModeSetup = __repair_constant;
      gRenderMode = __repair_constant;
      gCurrentFogColorMode = __repair_constant;
      if (first == NULL)
      {
        goto next_view;
      }
      opacity = first->opacity;
      if (opacity < (zero = 0.0f)) { opacity = zero; }
      p = first;
      alpha32 = (u32) (opacity * 255.0f);
      view = p;
      view->alpha = alpha32;
      emitFullScreenScissor(view);
      if (gTrackMarkerParents[i]->flags & 0x40)
      {
        drawFilledScreenRect(gTrackMarkerParents[i]);
        gTrackMarkerParents[i]->transition--;
        if (gTrackMarkerParents[i]->transition < 0)
        {
          gTrackMarkerParents[i]->flags &= ~0x40;
        }
        do { transitioning = 1; } while (0);
      }
      else
        if (!transitioning)
      {
        mask = 1U << i;
        if (((u8 *) &D_8010A4E4)[-0x21] & mask)
        {
          drawFilledScreenRect(gTrackMarkerParents[i]);
        }
        if (((u8 *) &D_8010A4E4)[-0x22] & mask)
        {
          cmd = sDisplayListCursor;
          cmd->w0 = 0xDE000000;
          cmd->w1 = D_800B1BE0;
          view = gTrackMarkerParents[i];
          sDisplayListCursor = cmd + 1;
          drawUiElementsForLayer(view, i, 5);
        }
        do { if (((u8 *) &D_8010A4E4)[-0x23] & mask)
        {
          __repair_phase_cmd = sDisplayListCursor;
          __repair_phase_cmd->w0 = 0xDE000000;
          __repair_phase_cmd->w1 = (u32) D_800B1BE0;
          view = gTrackMarkerParents[i];
          sDisplayListCursor = __repair_phase_cmd + 1;
          renderCameraView(view, i);
        } } while (0);
        if (((u8 *) &D_8010A4E4)[-0x22] & mask)
        {
          __repair_phase_layer = 4;
          layerEntry = &gTrackMarkerParents[i];
          emitScissorFromWindow(gTrackMarkerParents[i]);
          do
          {
            drawUiElementsForLayer(*layerEntry, i, __repair_phase_layer);
          }
          while ((--__repair_phase_layer) >= 0);
        }
      }
      { u32 markerMask = 1U << i;
      if ((!(gTrackMarkerActiveMask & markerMask)) && (!(gSceneFlagsB & markerMask)))
      {
        goto next_view;
      }
      }
      if (0)
      {
        goto next_view;
      }
      __repair_phase_view = gTrackMarkerParents[i];
      if (__repair_phase_view->overlay > 0.01f)
      {
        do
        {
          __repair_phase_alpha = (u32) inline_fn234(__repair_phase_view->overlay);
          if (gTrackMarkerParents[i]->flags & 2)
          {
            drawWindowFillRect(__repair_phase_alpha, i, 0, 255, 0);
          }
          else
          {
            drawWindowFillRect(__repair_phase_alpha, i, 255, 255, 255);
          }
          gTrackMarkerParents[i]->overlay *= 0.9f;
        }
        while (0);
      }
      else
      {
        __repair_phase_view->overlay = 0.0f;
      }
      __repair_phase___repair_phase_alpha = gTrackMarkerParents[i]->alpha;
      if (__repair_phase___repair_phase_alpha != 255)
      {
        drawWindowFillRect(255 - __repair_phase___repair_phase_alpha, i, 0, 0, 0);
      }
      drawLetterboxBars(gTrackMarkerParents[i]);
      next_view:
      i += 1;

    }
    while (i < 6);
  }
  func_80044410(0);
  cmd = sDisplayListCursor++;
  displayListBytes = inline_fn2(cmd, (unsigned short) 0x30) - ((u32) slot);
  cmd->w0 = 0xE9000000;
  cmd->w1 = 0;
  cmd = sDisplayListCursor++;
  cmd->w0 = 0xDF000000;
  cmd->w1 = 0;
  osWritebackDCache(slot->buffer, displayListBytes);
  osWritebackDCache(slot->buffer, inline_fn234567(inline_fn(), (u32) slot));
  osWritebackDCache(slot->buffer, inline_fn234567(inline_fn23(D_80109CB8), (u32) slot));
  osWritebackDCache(slot->buffer, inline_fn234567((u32) D_801002FC, 0x1AA8) - ((u32) slot));
  osWritebackDCache(slot->buffer, inline_fn234567((u32) D_8010A4B4, 0x1BB0) - ((u32) slot));
  slotToSubmit = slot;
  slot->commands = *((FrameCommand **) (sRenderState + 0x750));
  slot->commandBytes = (((s32) (((u32) sDisplayListCursor) - (*((u32 *) (sRenderState + 0x750))))) >> 3) << 3;
  if (gFramesQueuedCount != gFramesCompletedCount)
  {
    waitForGfxMessage();
    osRecvMesg(gFrameDoneMsgQueue, NULL, 1);
    __repair_phase_layer = inline_fn234567((u32) D_8010A4B0, 1);
    if (__repair_phase_layer < 0)
    {
      __repair_phase_layer += gFramebufferCount;
    }
    osViSwapBuffer(gFramebuffers[__repair_phase_layer]);
    D_800DD768[__repair_phase_layer] = osGetTime() - D_800DD750[__repair_phase_layer];
    switch (D_80109B9C)
    {
      default:

      case 1:
        while (gRetraceFrameCount < (D_80100C04 + 2))
      {
        osRecvMesg(gGfxSyncQueue, NULL, 1);
      }

        __repair_phase_layer = __osDisableInt();
        vi_apply_context();
        __osRestoreInt(__repair_phase_layer);
        break;

      case 0:
        while (osRecvMesg((s32) gGfxSyncQueue, NULL, 0) == 0)
      {
      }

        while (gRetraceFrameCount < (D_80100C04 + 1))
      {
        osRecvMesg(gGfxSyncQueue, NULL, 1);
      }

        osRecvMesg(gGfxSyncQueue, NULL, 1);
        break;

      case 2:
        while (gRetraceFrameCount < (D_80100C04 + 2))
      {
        osRecvMesg(gGfxSyncQueue, NULL, 1);
      }

        break;

    }

    __repair_phase___repair_phase_layer = ((u16) gFramesCompletedCount) + 1;
    D_80100C04 = (s32) gRetraceFrameCount;
    gFramesCompletedCount = __repair_phase___repair_phase_layer;
  }
  if (!D_800AE4B0)
  {
    stamp = osGetTime();
    D_800DD750[D_8010A4B0] = stamp;
    postSpTaskMessage(slotToSubmit);
 do { gFramesQueuedCount++; D_8010A4B0++; if (gFramebufferCount <= D_8010A4B0) { D_8010A4B0 = 0; } } while (0);
  }
}


