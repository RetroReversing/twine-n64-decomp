s32 func_8003278C();
s32 guMtxCatL(s32 *, s32 *, s32 *);
s32 guMtxIdent(s32 *);
s32 guRotate(s32 *, f32, f32, f32, f32);
extern s8 gVisibleObjectTotal;
extern s32 sMatrixPoolUsed, D_801096A8;
extern s32 *D_8010D538;
extern void *sRenderState;
void func_80034DD0(void) {
 s32 *temp_a0, *temp_a0_2;
 s32 temp_v0;
 s32 *__base_D_801096A8 = &D_801096A8;
 func_8003278C();
 temp_a0 = *(s32 **)((char *)sRenderState + 0x74C);
 gVisibleObjectTotal = 0;
 sMatrixPoolUsed = 0;
 D_8010D538 = temp_a0;
 guMtxIdent(temp_a0);
 temp_v0 = sMatrixPoolUsed + 1;
 temp_a0_2 = (s32 *)((char *)*(s32 **)((char *)sRenderState + 0x74C) + (temp_v0 << 6));
 sMatrixPoolUsed = temp_v0;
 D_8010D538 = temp_a0_2;
 guRotate(temp_a0_2, -180.0f, 0, 1.0f, 0.0f);
 guRotate(__base_D_801096A8, 180.0f, 0, 0.0f, 1.0f);
 guMtxCatL(__base_D_801096A8, D_8010D538, D_8010D538);
}
