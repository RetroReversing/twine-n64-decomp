s32 buildEulerRotationMatrix(s32 *, f32, f32, s32);
s32 resetSurfaceQueryState(void *);
s32 propagatePortalVisibility(s32, f32 *);
s32 buildDepthSortedObjectList();
s32 func_80015BA8(void *, s32, f32 *);
s32 setPerspectiveMtx(void *, void *, f32, s32, f32, f32, f32);
s32 applyFogColorMode(void *, s32);
s32 setupFogAndEnvColor(void *);
s32 getBlockSizeClass(s32);
s32 renderFlaggedObjectParts(void *);
f32 randomFloatUpTo(f32);
s32 addRandomOffsetToVec3(void *, f32, f32);
s32 drawLightFlares(void *);
s32 func_80036108(void *);
s32 renderObjectListWithReflections(void *);
s32 func_80036820(void *);
s32 func_800369B8(void *);
s32 drawVisibleObjectsLit(void *);
s32 drawObjectParts(void *);
s32 renderDeferredParts(void *);
s32 func_800374BC(void *);
s32 renderObjectListPass(void *);
s32 endWindowDisplayList(void *);
s32 beginRenderModeTwoPass(void *);
s32 renderSolidColorOverlay(void *);
s32 func_80045180(void *, void *, void *, f32);
s32 updateRayRange(void *);
s32 loadSurfaceQueryMatrix(void *);
s32 setSurfaceQueryPosition(void *);
s32 multiplyMat3ByVec3(void *, void *, void *);
s32 guMtxCatF(s32 *, s32 *, f32 *);
s32 guMtxF2L(f32 *, void *);
s32 guTranslateF(s32 *, f32, f32, f32);
s32 renderObjectList(void *);
s32 updateObjectColor(void *);
extern u16 D_800B35B0;
extern f32 kRayNoHitDistance;
extern s8 gSineTable[];
extern s32 gFrameBufferIndex;
extern s32 D_800E1714;
extern s32 gTickCount;
extern void *D_80107E9C;
extern s32 D_80109E28;
extern s32 D_8010A4D8;
extern u8 D_8010D2B0;
extern f32 gCullFarDistance;
extern s32 gObjectList;
extern s32 sCurrentMatrixSlot;
typedef struct { u32 w0; void *w1; } Gfx;
typedef struct { s16 h[8]; } Vp;
typedef struct RS { u8 p0[0x300]; Vp a[31]; Vp b[31]; Vp c[6]; u8 p7[0xC]; s32 s74c; } RS;
extern Gfx *sDisplayListCursor;
extern u32 sMatrixPoolLimit;
extern u32 sMatrixPoolUsed;
extern s32 sObjectMatrixF;
extern f32 sParentMatrixF;
extern RS *sRenderState;
typedef struct 
{
  unsigned char pad[244];
  int value;
} __repair_field_F4;
typedef struct 
{
  int value;
} __repair_field_0;
inline static s32 inline_fn(f32 arg0, float arg1)
{
  return (s32) (2.0f * (arg0 * arg1));
}

inline static char *inline_fn2(void *arg0)
{
  return (char *) arg0;
}

typedef struct { u32 a, b, c; } W3;
typedef union { W3 w; f32 f[3]; s32 i[3]; } U3;
typedef union { f32 values[4]; u32 words[4]; } ClipB;
typedef struct Cam {
  u8 p0[0x10];
  U3 u10;
  U3 u1C;
  u8 p28[0xC];
  U3 u34;
  U3 u40;
  f32 f4C;
  ClipB clip;
  f32 f60;
  f32 f64;
  u8 p68[0x18];
  s32 s80;
  f32 f84;
  u8 b88[0x24];
  f32 fAC;
  f32 fB0;
  f32 fB4;
  u8 bB8[0x30];
  f32 fE8;
  f32 fEC;
  f32 fF0;
  s32 sF4;
  u8 pF8[8];
  s32 flags;
  u8 p104[0x1C];
  f32 f120;
  u8 p124[0x24];
  f32 f148;
} Cam;
/* Sets up one camera view (projection, viewports, view matrix, visibility) and renders all object passes for it. */ void renderCameraView(Cam *arg0, s32 p1)
{
  s32 arg1;
  s16 tv1;
  s16 tv2;
  s16 tv3;
  s16 tv4;
  s16 tv5;
  s16 tv6;
  s16 tv7;
  s16 tv8;
  s16 tv9;
  s16 tv10;
  s16 tv11;
  s16 tv12;
  s16 tv13;
  s16 tv14;
  s16 tv15;
  s16 tv16;

  typedef struct 
  {
    u32 words[3];
  } ThreeWords;
  typedef union 
  {
    f32 values[4];
    u32 words[4];
  } ClipBounds;
  f32 *var_s0;
  register f32 *var_v1;
  f32 temp_fs3;
  f32 temp_fv0;
  void *var_s0_2;
  f32 temp_fv1_2;
  ClipB clipBounds;
  s32 var_a0;
  u32 var_a1;
  do
  {
    void *temp_s0;
    void *temp_s0_3;
    int temp_s7;
    f32 temp_fv1;
    temp_fs3 = arg0->f4C;
    arg1 = p1;
    if ((arg0->flags) & 4)
    {
      gCullFarDistance = 15.0f;
      if (D_8010D2B0 != 0)
      {
        gCullFarDistance = 7.5f;
      }
    }
    else
    {
      gCullFarDistance = kRayNoHitDistance;
      arg0->f148 = 2.0f;
    }
    arg0->u1C.w = arg0->u10.w;
    arg0->u40.w = arg0->u34.w; temp_fv1 = arg0->f120;
    if (temp_fv1 > 0.0f)
    {
      f32 horizontal = temp_fv1 * 0.4f;
      f32 vertical = temp_fv1 * 0.2f;
      temp_fv0 = 2.0f * temp_fv1;
      addRandomOffsetToVec3(&arg0->u1C, temp_fv0, temp_fv0);
      addRandomOffsetToVec3(&arg0->u40, horizontal, vertical);
      temp_fv1_2 = (arg0->f120) - randomFloatUpTo((arg0->f120) * 0.25f);
      arg0->f120 = temp_fv1_2;
      if (temp_fv1_2 < 0.0f)
      {
        arg0->f120 = 0.0f;
      }
    }
    updateRayRange(arg0);
    D_800E1714 = getBlockSizeClass((s32) arg1); gFrameBufferIndex = (int) arg1; D_80107E9C = NULL; gObjectList = 0; D_800B35B0 += 1;
    if (arg0->sF4 != 0)
    {
      clipBounds = arg0->clip; temp_s7 = arg0->sF4;
      cameraUpdateProjection(arg0, arg0->f84);
      temp_s0 = arg0->b88;
      func_80045180(&arg0->u40, arg0->bB8, temp_s0, temp_fs3);
      multiplyMat3ByVec3(temp_s0, &arg0->u1C, &arg0->fE8);
      arg0->fAC = (f32) (-(arg0->fE8));
      arg0->fB0 = (f32) (-(arg0->fEC));
      arg0->fB4 = (f32) (-(arg0->fF0));
      tv1 = (s16) ((s32) (2.0f * (temp_fs3 * (arg0->clip.values[1] - arg0->clip.values[0]))));
      sRenderState->a[arg1].h[0] = tv1;
      tv2 = (s16) ((s32) (2.0f * (temp_fs3 * (arg0->clip.values[3] - arg0->clip.values[2]))));
      sRenderState->a[arg1].h[1] = tv2;
      sRenderState->a[arg1].h[2] = 0x2FF;
      sRenderState->a[arg1].h[3] = 0;
      if (arg0->flags & 8)
      {
        tv3 = (s16) ((s32) (((f32) sRenderState->a[arg1].h[0]) + (((f32) (gSineTable[gTickCount & 0x7F] + 0x80)) * 0.078125f)));
      sRenderState->a[arg1].h[0] = tv3;
        tv4 = (s16) ((s32) (((f32) sRenderState->a[arg1].h[1]) + (((f32) (gSineTable[(gTickCount + 0x2AB) & 0x7F] + 0x80)) * 0.0390625f)));
      sRenderState->a[arg1].h[1] = tv4;
      }
      tv5 = (s16) ((s32) (arg0->f60 * 4.0f));
      sRenderState->a[arg1].h[4] = tv5;
      tv6 = (s16) ((s32) (arg0->f64 * 4.0f));
      sRenderState->a[arg1].h[5] = tv6;
      sRenderState->a[arg1].h[6] = 255;
      sRenderState->a[arg1].h[7] = 0;
      sDisplayListCursor->w0 = 0xDC080008;
      sDisplayListCursor->w1 = &sRenderState->a[arg1];
      sDisplayListCursor++;
      setPerspectiveMtx((char *) sRenderState + (arg1 << 6), (char *) sRenderState + ((arg1 * 2) + 0x360), arg0->f84, arg0->s80, 12.8f, gCullFarDistance * 64.0f, 1.0f);
      tv7 = (s16) ((s32) (2.0f * (temp_fs3 * (arg0->clip.values[1] - arg0->clip.values[0]))));
      sRenderState->b[arg1].h[0] = tv7;
      tv8 = (s16) ((s32) (2.0f * (temp_fs3 * (arg0->clip.values[3] - arg0->clip.values[2]))));
      sRenderState->b[arg1].h[1] = tv8;
      sRenderState->b[arg1].h[2] = 0x2EF;
      sRenderState->b[arg1].h[3] = 0;
      if (arg0->flags & 8)
      {
        tv9 = (s16) ((s32) (((f32) sRenderState->b[arg1].h[0]) + (((f32) (gSineTable[gTickCount & 0x7F] + 0x80)) * 0.078125f)));
      sRenderState->b[arg1].h[0] = tv9;
        tv10 = (s16) ((s32) (((f32) sRenderState->b[arg1].h[1]) + (((f32) (gSineTable[(gTickCount + 0x2AB) & 0x7F] + 0x80)) * 0.0390625f)));
      sRenderState->b[arg1].h[1] = tv10;
      }
      tv11 = (s16) ((s32) (arg0->f60 * 4.0f));
      sRenderState->b[arg1].h[4] = tv11;
      tv12 = (s16) ((s32) (arg0->f64 * 4.0f));
      sRenderState->b[arg1].h[5] = tv12;
      sRenderState->b[arg1].h[6] = 255;
      sRenderState->b[arg1].h[7] = 0;
      sDisplayListCursor->w0 = 0xDC080008;
      sDisplayListCursor->w1 = &sRenderState->b[arg1];
      sDisplayListCursor++;
      setPerspectiveMtx((char *) sRenderState + ((arg1 << 6) + 0x370), (char *) sRenderState + ((arg1 * 2) + 0x550), arg0->f84, arg0->s80, 12.8f, gCullFarDistance * 64.0f, 1.0f);
      tv13 = (s16) ((s32) (2.0f * (temp_fs3 * (arg0->clip.values[1] - arg0->clip.values[0]))));
      sRenderState->c[arg1].h[0] = tv13;
      tv14 = (s16) ((s32) (2.0f * (temp_fs3 * (arg0->clip.values[3] - arg0->clip.values[2]))));
      sRenderState->c[arg1].h[1] = tv14;
      sRenderState->c[arg1].h[2] = 0xFF;
      sRenderState->c[arg1].h[3] = 0;
      tv15 = (s16) ((s32) (arg0->f60 * 4.0f));
      sRenderState->c[arg1].h[4] = tv15;
      tv16 = (s16) ((s32) (arg0->f64 * 4.0f));
      sRenderState->c[arg1].h[5] = tv16;
      sRenderState->c[arg1].h[6] = 0;
      sRenderState->c[arg1].h[7] = 0;
      sDisplayListCursor->w0 = 0xDC080008;
      sDisplayListCursor->w1 = &sRenderState->c[arg1];
      sDisplayListCursor++;
      setPerspectiveMtx((char *) sRenderState + ((arg1 << 6) + 0x560), (char *) sRenderState + ((arg1 * 2) + 0x740), arg0->f84, arg0->s80, 0.64f, 64.0f, 1.0f);
      if (sMatrixPoolUsed < sMatrixPoolLimit)
      {
        sMatrixPoolUsed = sMatrixPoolUsed + 1;
        sCurrentMatrixSlot = sRenderState->s74c + (sMatrixPoolUsed << 6);
        buildEulerRotationMatrix(&sObjectMatrixF, (arg0->u40.f[2]) + 3.1415927f, -((arg0->u40.f[1]) + 3.1415927f), arg0->u40.i[0]);
        guTranslateF(&D_80109E28, (-(arg0->u1C.f[0])) * 64.0f, (-(arg0->u1C.f[1])) * 64.0f, (-(arg0->u1C.f[2])) * 64.0f);
        guMtxCatF(&D_80109E28, &sObjectMatrixF, &sParentMatrixF);
        var_s0 = &sParentMatrixF; var_a1 = 0;
        do
        {
          var_a0 = 0; var_v1 = var_s0;
          loop_15:
          var_a0 += 1;

          *var_v1 *= 0.8f; var_v1 += 1;
          if (var_a0 < 4U)
          {
            goto loop_15;
          }
          ++var_a1;
          var_s0 += 4;
        }
        while (var_a1 < 4U);
        guMtxF2L(&sParentMatrixF, (char *) sRenderState + ((arg1 << 6) + 0x180));
        resetSurfaceQueryState(arg0);
        if ((arg0->flags) & 3)
        {
          propagatePortalVisibility(temp_s7, clipBounds.values);
          buildDepthSortedObjectList();
        }
        if ((arg0->flags) & 4)
        {
          func_80015BA8(&arg0->u10, temp_s7, clipBounds.values);
        }
        temp_s0_3 = arg0->b88; D_800B35B0 += 1;
        loadSurfaceQueryMatrix(temp_s0_3);
        setSurfaceQueryPosition(temp_s0_3);
        setupFogAndEnvColor(arg0);
        var_s0_2 = D_80107E9C;
        if (var_s0_2 != NULL)
        {
          do
          {
            updateObjectColor(var_s0_2);
            do
            {
              var_s0_2 = *((void **) (((char *) var_s0_2) + 0x1C));
            }
            while (0);
          }
          while (var_s0_2 != NULL);
        }
        {
          volatile s32 *renderSelector = &D_8010A4D8;
          applyFogColorMode(arg0, *renderSelector);
          func_80036108(arg0);
          applyFogColorMode(arg0, *renderSelector);
          renderObjectListWithReflections(arg0);
          applyFogColorMode(arg0, *renderSelector);
          func_800374BC(arg0);
          applyFogColorMode(arg0, *renderSelector);
          drawObjectParts(arg0);
          applyFogColorMode(arg0, *renderSelector);
          func_80036820(arg0);
          applyFogColorMode(arg0, *renderSelector);
          renderObjectList(arg0);
          applyFogColorMode(arg0, *renderSelector);
          renderDeferredParts(arg0);
          applyFogColorMode(arg0, *renderSelector);
          renderObjectListPass(arg0);
          applyFogColorMode(arg0, *renderSelector);
          func_800369B8(arg0);
          applyFogColorMode(arg0, *renderSelector);
          endWindowDisplayList(arg0);
          applyFogColorMode(arg0, *renderSelector);
          drawLightFlares(arg0);
          applyFogColorMode(arg0, *renderSelector);
          renderFlaggedObjectParts(arg0);
        }
        drawVisibleObjectsLit(arg0);
        beginRenderModeTwoPass(arg0);
        renderSolidColorOverlay(arg0);
      }
    }
  }
  while (0);
}
