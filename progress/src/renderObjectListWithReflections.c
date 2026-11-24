#define EMIT(a, b) { RenderCommand *cmd = D_80115328++; cmd->w0 = (a); cmd->w1 = (b); }
typedef struct 
{
  u32 w0;
  u32 w1;
} RenderCommand;
typedef struct 
{
  u8 pad[0x20];
  f32 height;
} RenderDetail;
typedef struct RenderNode
{
  u8 pad0[0x1C];
  struct RenderNode *next;
  u8 pad20[0x1C];
  RenderDetail *detail;
  u8 pad40[0x18];
  u32 flags;
} RenderNode;
typedef struct 
{
  u8 pad[0x100];
  u32 flags;
} RenderView;
typedef struct 
{
  u8 pad[0x74C];
  u32 matrices;
} RenderFrame;
extern void buildQuadUvFrames(RenderNode *, RenderView *);
extern void drawObjectPart(void *);
extern void emitPrimColor(RenderNode *, RenderView *);
extern void emitClippedScissor(RenderNode *, RenderView *);
extern void appendProjectionViewportCommands(void);
extern void guMtxF2L(f32 *, u32);
extern void func_800A3940(f32 *, f32, f32, f32);
extern void guMtxIdentF(f32 *);
extern RenderCommand D_800B1A00[];
extern RenderCommand D_800B1A78[];
extern RenderCommand D_800B1B18[];
extern u32 sMatrixPoolLimit[3];
extern s32 gCurCombineSetup;
extern s32 gCurGeometryModeSetup;
extern s32 gRenderMode;
extern RenderNode *gObjectListHead;
extern u32 sMatrixPoolUsed;
extern u32 D_8010D538;
extern f32 D_80112F90[16];
extern f32 D_80112FC4;
extern RenderCommand *D_80115328;
extern RenderFrame *sRenderState;
/* Emits display-list commands for every object in the list, then a second pass drawing mirrored copies for flagged objects. */ void renderObjectListWithReflections(RenderView *view)
{
  RenderNode *node = gObjectListHead;
  RenderCommand *cmd;
  if (gCurCombineSetup != 1)
  {
    gCurCombineSetup = 1;
    if (view->flags & 3)
    {
      EMIT(0xFC40FE03, 0xFFFFF378);
    }
    else
    {
      EMIT(0xFC40FE03, 0xFF0FF37F);
    }
  }
  if (gRenderMode)
  {
    gRenderMode = 0;
    appendProjectionViewportCommands();
  }
  if (0 != gCurGeometryModeSetup)
  {
    gCurGeometryModeSetup = 0;
    if (view->flags & 3)
    {
      EMIT(0xDE000000, (u32) D_800B1A00);
    }
    else
    {
      EMIT(0xDE000000, (u32) D_800B1B18);
    }
  }
  cmd = D_80115328;
  cmd->w0 = 0xDA380003;
  D_80115328++;
  cmd->w1 = sRenderState->matrices - 0x80000000;
  for (; node != NULL; node = node->next)
  {
    buildQuadUvFrames(node, view);
    emitPrimColor(node, view);
    emitClippedScissor(node, view);
    if (node->detail != NULL)
    {
      drawObjectPart(node->detail);
    }
  }

  if (gCurGeometryModeSetup != 3)
  {
    gCurGeometryModeSetup = 3;
    EMIT(0xDE000000, (u32) D_800B1A78);
  }
  node = gObjectListHead;
  if (node != NULL)
  {
    f32 *reflectMtx = D_80112F90;
    f32 unitScale = 1.0f;
    f32 fixedScale = 64.0f;
  loop:
    {
      if ((node->flags >> 2) & 0x200)
      {
        f32 offsetY = 2.0f * node->detail->height;
        if (sMatrixPoolUsed >= sMatrixPoolLimit[0])
        {
          goto done;
        }
        emitPrimColor(node, view);
        emitClippedScissor(node, view);
        D_8010D538 = sRenderState->matrices + ((++sMatrixPoolUsed) << 6);
        guMtxIdentF(reflectMtx);
        func_800A3940(reflectMtx, unitScale, -1.0f, unitScale);
        D_80112FC4 = offsetY * fixedScale;
        guMtxF2L(reflectMtx, D_8010D538);
        D_80115328->w0 = 0xDA380003;
        D_80115328->w1 = D_8010D538 - 0x80000000;
        D_80115328++;
        drawObjectPart(node->detail);
      }
    }
    if ((node = node->next) != NULL) goto loop;
  done:;

  }
}

