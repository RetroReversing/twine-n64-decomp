s32 func_8000828C();
s32 func_8003C7C4(s32 *, u32, u32, s32 *);
s32 func_80064250();
s32 func_80073400();
s32 func_8007560C();
s32 func_80083C98();
s32 func_80083D04(s32);
extern s32 D_800CA31C;
extern s32 D_8010302C;
extern void *gObjectListHead;
extern s32 D_80109688;
extern s32 D_80109CB4;
extern s32 D_8010A500;
extern s32 D_8010D2C0;
extern s32 D_8010D380;
extern u8 D_801002E4;
extern u8 D_801002E5;
extern u8 D_80100300;
extern u8 D_80100784;
extern u8 D_80102F38;
extern u8 D_80103020;
extern u8 D_8010302A;
extern u8 D_80103041;
extern u8 D_801032A4;
extern u8 D_801032AC;
extern u8 D_80103EB1;
extern u8 D_80107B60;
extern u8 D_80107ECC;
extern u8 D_80107ECD;
extern u8 D_80107ECE;
extern u8 D_80107ECF;
extern u8 D_80108F74;
extern u8 D_80108F94;
extern u8 D_801093A0;
extern u8 D_8010957C;
extern u8 D_80109684;
extern u8 D_80109A34;
extern u8 D_80109A35;
extern u8 D_80109B1E;
extern u8 D_8010A2B8;
extern u8 D_8010A2CC;
extern u8 D_8010A3C4;
extern u8 D_8010A4B8;
extern u8 D_8010A91C;
extern u8 D_8010D2B0;
extern u8 D_8010D2B8;
extern u8 D_8010D36C;
extern u8 D_8010D374;
extern u8 D_80110CA8;
extern u8 D_80110DB1;
extern u8 D_80112F88;
extern u8 D_80115318;
extern u8 D_80117734;
void func_800449A0(void)
{
  s32 *var_a0;
  s32 *var_a3;
  s32 *var_t0;
  s32 *var_v1;
  s32 *var_v1_2;
  s32 *var_v1_3;
  u32 var_a1;
  u32 var_a2;
  u32 var_a2_2;
  u32 var_a2_3;
  func_80083D04(0);
  func_80083C98();
  func_8000828C();
  func_80064250();
  func_80073400();
  var_a2 = 0; var_v1 = &D_80109688;
  do
  {
    *var_v1 = 0; var_a2 += 1; var_v1 += 1;
  }
  while (var_a2 < 6U);
  var_a2 = 0; var_v1_2 = &D_8010A500;
  do
  {
    *var_v1_2 = 0; var_a2 += 1; var_v1_2 += 1;
  }
  while (var_a2 < 4U);
  var_a2 = 0; var_t0 = &D_8010D2C0; var_a3 = &D_8010D380;
  do
  {
    var_a1 = 0; var_a0 = var_t0; var_v1_3 = var_a3;
    loop_6:
    *var_v1_3 = 0;

    *var_a0 = 0; var_a0 += 1; var_a1 += 1; var_v1_3 += 1;
    if (var_a1 < 6U)
    {
      goto loop_6;
    }
    var_t0 += 7; var_a2 += 1; var_a3 += 7;
  }
  while (var_a2 < 6U);
  D_8010302C = 0; D_800CA31C = func_8003C7C4(var_a0, var_a1, var_a2, var_a3);
  func_8007560C();
 do { u8 reset = 0xFF; D_801032AC = 0xA0; D_8010D374 = 0x60; gObjectListHead = 0; D_801032A4 = reset; D_80108F74 = reset; D_80102F38 = reset; D_80112F88 = reset; D_80107B60 = reset; D_80100784 = reset; D_80103041 = 0; D_8010302A = 0; D_8010957C = 0; D_80103EB1 = 0; D_80115318 = 8; D_8010A3C4 = 0; D_80109A34 = 0xEF; D_80109684 = 0x40; D_8010A4B8 = 0x10; D_80110DB1 = 8; D_80107ECE = 0; D_80108F94 = reset; D_80103020 = 0; D_80107ECF = 0; D_8010D2B8 = reset; D_8010A2CC = 0; D_8010D36C = 0; D_801002E4 = 0; D_80107ECD = 0x80; D_801093A0 = 0; } while (0);
  D_801002E5 = 0; D_80110CA8 = 0x80; D_80100300 = 0; D_8010A91C = 0; D_80109B1E = 0; D_80117734 = 0; D_8010A2B8 = 0; D_8010D2B0 = 0; D_80107ECC = 0; D_80109A35 = 0; D_80109CB4 = 0;
}

