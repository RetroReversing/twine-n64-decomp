extern s32 D_801003D8;
extern u8 D_80100774;
extern s8 D_80100775;
extern s8 D_80100776;
extern s8 D_80100777;
extern s8 D_80100778;
extern s8 D_80100779;
extern s8 D_8010077A;
extern s8 D_8010077B;
extern s8 D_8010077C;
extern s32 D_801007CF;
extern f32 D_80109CC0;
extern f32 D_8010D370;
extern s32 D_8010D450;
void func_80073400(void)
{
  f32 __repair_fzero;
  unsigned char __repair_constant;
  volatile u8 *state = (volatile u8 *) ((((u32) (&D_801007CF)) + D_801003D8) - D_801003D8);
  if (D_801003D8)
  {
    *(state + (-1)) = 0;
    __repair_fzero = 0.0f;
    *(state + (-3)) = 0;
    *(state + (-2)) = 0;
    *(state + 2) = 0;
    *(state + 1) = 0;
    *(state + 0) = 0;
    *(state + 3) = 0xFF;
    *(state + 4) = (__repair_constant = 0xFF);
    *(state + 5) = __repair_constant;
    D_80100774 = 0xEB;
    *((u8 *) (&D_80100776)) = 0x78;
    *((u8 *) (&D_80100778)) = 0x30;
    *((u8 *) (&D_80100779)) = 0x9B;
    *((u8 *) (&D_8010077A)) = 0x28;
    *((u8 *) (&D_80100775)) = 0;
    *((u8 *) (&D_80100777)) = 0;
    *((u8 *) (&D_8010077B)) = 0xCD;
    *((u8 *) (&D_8010077C)) = __repair_constant;
    D_8010D450 = 0;
    D_801003D8 = 0;
    D_80109CC0 = __repair_fzero;
    D_8010D370 = __repair_fzero;
  }
  else
  {
    *(state + (-1)) = 0;
    __repair_fzero = 0.0f;
    *(state + (-3)) = 0;
    *(state + (-2)) = 0;
    *(state + 2) = 0;
    *(state + 1) = 0;
    *(state + 0) = 0;
    *(state + 3) = 0xFF;
    *(state + 4) = (__repair_constant = 0xFF);
    *(state + 5) = __repair_constant;
    D_80100774 = 0xEB;
    *((u8 *) (&D_80100776)) = 0x78;
    *((u8 *) (&D_80100778)) = 0x30;
    *((u8 *) (&D_80100779)) = 0x9B;
    *((u8 *) (&D_8010077A)) = 0x28;
    *((u8 *) (&D_80100775)) = 0;
    *((u8 *) (&D_80100777)) = 0;
    *((u8 *) (&D_8010077B)) = 0xCD;
    *((u8 *) (&D_8010077C)) = __repair_constant;
    D_8010D450 = 0;
    D_801003D8 = 0;
    D_80109CC0 = __repair_fzero;
    D_8010D370 = __repair_fzero;
  }
}

