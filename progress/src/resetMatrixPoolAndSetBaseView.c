s32 func_8003278C();
s32 guMtxCatL(s32 *, s32 *, s32 *);
s32 guMtxIdent(s32 *);
s32 guRotate(s32 *, f32, f32, f32, f32);
extern s8 gVisibleObjectTotal;
extern s32 sMatrixPoolUsed, sFlipRotationMatrix;
extern s32 *D_8010D538;
extern void *sRenderState;
/* Resets the matrix pool, then builds the base view matrix from an identity matrix and 180-degree flip rotations. */
void resetMatrixPoolAndSetBaseView(void) {
 s32 *baseMtx, *viewMtx;
 s32 nextSlot;
 s32 *flipMtx = &sFlipRotationMatrix;
 func_8003278C();
 baseMtx = *(s32 **)((char *)sRenderState + 0x74C);
 gVisibleObjectTotal = 0;
 sMatrixPoolUsed = 0;
 D_8010D538 = baseMtx;
 guMtxIdent(baseMtx);
 nextSlot = sMatrixPoolUsed + 1;
 viewMtx = (s32 *)((char *)*(s32 **)((char *)sRenderState + 0x74C) + (nextSlot << 6));
 sMatrixPoolUsed = nextSlot;
 D_8010D538 = viewMtx;
 guRotate(viewMtx, -180.0f, 0, 1.0f, 0.0f);
 guRotate(flipMtx, 180.0f, 0, 0.0f, 1.0f);
 guMtxCatL(flipMtx, D_8010D538, D_8010D538);
}
