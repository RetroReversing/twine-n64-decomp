extern signed char D_801002AE;
extern char D_80112F68[];
extern signed char D_80112F70;
extern signed char gPauseFlag;
extern signed char D_801002D5;
extern int D_801002B4;
extern int gSaveExtraSlotCount;
extern int gSaveSlotCount;
extern int D_801002C0;
s32 func_80007160();
s32 func_8000A18C();
s32 func_8000A22C();
s32 func_8002B000();
s32 func_8002B150();
s32 func_8002B9FC();
s32 func_8002CA90();
s32 func_8002D13C();
s32 func_8002D7C0();
s32 func_8008173C();
s32 func_80081BC4();
s32 memset();
extern char D_800BFC38[];
extern char D_80100198[];
extern s32 gSaveSlotInfo;
extern char D_801001A0[];
extern char D_801001A1[];
extern char D_801001A2[];
extern char D_801001A3[];
extern s32 D_801001B4;
extern s32 D_801001CC;
extern s32 D_801001E4;
extern s32 D_801001FC;
extern s32 D_80100214;
extern s32 D_8010022C;
extern s32 D_80100244;
extern s32 D_8010025C;
extern s32 D_80100274;
extern s32 D_8010028C;
extern s8 D_801002AF;
extern s8 D_801002B0;
extern s8 D_801002B1;
extern s32 D_801002EC;
extern s8 D_801002F0;
extern u8 D_801002F1;
extern s8 D_801002F2;
extern s8 D_801002F3;
extern s8 D_80102EB9;
extern s32 gBorderSkipFlag;
extern s8 D_80102EDC;
extern s8 D_80102EDD;
extern s8 D_80102EDE;
extern s8 D_80102EE0;
extern s32 D_80102EE4;
extern s8 D_80102EE8;
extern s32 D_80102EEC;
extern s32 D_80102EF0;
extern s32 D_80102EF4;
extern s32 D_80102EF8;
extern char D_80102EFC[];
extern u16 D_80109B9C;
extern s8 D_8010A4C0;
extern s8 D_8010A4C1;
extern s8 gSceneFlagsB;
extern s8 D_8010A4C3;
extern s8 D_8010A4C4;
extern s32 D_8010A4C8;
extern s32 D_8010A4CC;
extern s32 D_8010A4D0;
extern s32 D_8010A4D4;
extern s32 D_8010A4D8;
extern s32 D_8010A4DC;
extern s32 D_8010A4E0;
extern s32 D_8010A4E4;
extern s32 gHiResScreen;
extern s32 D_8010A4EC;
extern s32 D_8010A4F0;
extern s32 D_8010A4F4;
extern s32 D_8010A4F8;
extern s8 D_8010A4FC;
extern s8 gBorderFlipFlag;
extern s8 gOptionFlagA;
extern s8 D_8010A4FF;
extern s8 D_80112F6C;
extern s8 D_80112F6D;
extern s8 D_80112F6E;
extern s8 D_80112F6F;
extern char D_80117410[];
extern char D_80117428[];
extern char D_801176C8[];
extern s32 D_801176D8;
extern s32 D_801176DC;
extern s16 D_801176E0;
extern s16 D_801176E2;
extern s16 D_801176E4;
inline static char *inline_fn()
{
  return D_80117428;
}

void func_8002D240(void)
{
  s8 *base_801002AE;
  unsigned int temp_v0;
  char c2;
  char c64;
  register unsigned short c1;
  s32 *temp_s0_2;
  s32 temp_v1_2;
  unsigned int temp_s1;
  unsigned temp_s1_2;
  unsigned temp_s3;
  unsigned int temp_v1;
  register int temp_s0;
  long var_s2;
  int var_s2_2;
  int __repair_phase_var_s2_2;
  int __repair_phase___repair_phase_var_s2_2;
  register unsigned long var_s5_2;
  register u16 temp_a2;
  u32 var_s0;
  func_8008173C();
  func_8002CA90("TWINE.");
  func_8002B000(D_80102EFC, 0x1E);
  gBorderSkipFlag = 0;
  D_80102EB9 = 0;
  D_80102EDD = 0;
  D_80102EDC = 0;
  D_80102EDE = 0;
  D_80102EF0 = 1;
  D_80102EF4 = 0;
  D_80102EF8 = 1;
  D_80102EE4 = 2;
  D_80102EE0 = 2;
  D_80102EE8 = 0;
  base_801002AE = &D_801002AE;
  base_801002AE[0] = 0;
  base_801002AE[1] = 0;
  base_801002AE[2] = 0;
  base_801002AE[3] = 0;
  D_80102EEC = 0;
  *((s32 *) D_80112F68) = 0;
  D_80112F68[4] = 0;
  D_80112F68[5] = 0;
  D_80112F68[6] = 0;
  D_80112F68[7] = 0;
  memset(((char *) (&D_80112F68)) + 0x13, 0, 4);
  memset(D_80112F68 + 0x17, 0, 3);
  memset(D_80112F68 + 0x1A, 0, 3);
  memset(D_80112F68 + 8, 0, 0xB);
  D_80112F68[8] = 1;
  D_801002F1 = 6;
  D_801002EC = 1;
  D_801002F3 = 1;
  D_801002F2 = 0;
  D_801002F0 = 0xA;
  c2 = 2; c64 = 0x64; c1 = 1;
  func_8000A22C(0xA);
  __repair_phase_var_s2_2 = 0;
  func_8000A18C(D_801002F1);
  D_8010A4C0 = 0;
  D_8010A4C4 = 1;
  gSceneFlagsB = 0x1F;
  D_8010A4C1 = 1;
  D_8010A4C3 = 0xF;
  D_8010A4C8 = 1;
  D_8010A4CC = 1;
  D_8010A4D0 = 1;
  D_8010A4D4 = 1;
  D_8010A4D8 = 2;
  D_8010A4DC = 1;
  D_8010A4E0 = 1;
  D_8010A4E4 = 1;
  gHiResScreen = 0;
  D_8010A4EC = 0;
  D_8010A4F0 = 1;
  D_8010A4F4 = 0;
  D_8010A4F8 = 0;
  D_8010A4FC = 0;
  gOptionFlagA = 0;
  gBorderFlipFlag = 0;
  D_8010A4FF = D_80109B9C == 0;
  func_80007160();
  do
  {
    func_8002B000((&D_801002AE) + 0x16, 0x1E);
  }
  while (0);
  func_8002B000((&D_801002AE) + 0x1E, 0x1E);
  *((s8 *) (((char *) (&D_801002AE)) + (-0xE))) = 0;
  *((s8 *) (((char *) (&D_801002AE)) + (-0xD))) = 0;
  *((s8 *) (((char *) (&D_801002AE)) + 0x26)) = 1;
  *((s8 *) (((char *) (&D_801002AE)) + 0x27)) = 0;
  *((s8 *) (((char *) (&D_801002AE)) + (-0xC))) = 0;
  *((s8 *) (((char *) (&D_801002AE)) + (-0xA))) = 0x18;
  *((s32 *) (((char *) (&D_801002AE)) + (-6))) = 0;
  *((s8 *) (((char *) (&D_801002AE)) + (-2))) = 0;
  *((s32 *) (((char *) (&D_801002AE)) + 6)) = (s32) (func_8002D13C(0xA3) & 0xFFFF);
  *((s32 *) (((char *) (&D_801002AE)) + 0xE)) = 0;
  *((s32 *) (((char *) (&D_801002AE)) + 0xA)) = (s32) (func_8002D13C(0xA3) & 0xFFFF);
  *((s32 *) (((char *) (&D_801002AE)) + 0x12)) = (s32) (func_8002D13C(0xA3) & 0xFFFF);
  *((s8 *) (((char *) (&D_801002AE)) + (-1))) = 0;
  var_s0 = __repair_phase_var_s2_2 & 0xFFFF;
  do
  {
    var_s0 = __repair_phase_var_s2_2 & 0xFFFF;
    temp_s1 = var_s0 < 4U;
    if (((int) temp_s1) != 0)
    {
      func_80081BC4(var_s0, 2);
    }
    temp_v1 = ((s32) var_s0) * 0x18;
    *(D_80100198 + temp_v1) = c2;
    *(D_801001A0 + temp_v1) = c64;
    *(D_801001A2 + temp_v1) = c1;
    *(D_801001A3 + temp_v1) = 0;
    if (temp_s1)
    {
      if ((__repair_phase_var_s2_2 & 1) != 0)
      {
        goto block_8;
      }
      goto block_7;
    }
    if (__repair_phase_var_s2_2 & 1)
    {
      block_7:
      *(D_801001A1 + temp_v1) = c1;

      __repair_phase_var_s2_2 += 1;
    }
    else
    {
      block_8:
      *(D_801001A1 + temp_v1) = 0;

      ++__repair_phase_var_s2_2;
    }
    var_s0 = __repair_phase_var_s2_2 & 0xFFFF;
  }
  while (((u32) ((temp_s1 = (short) __repair_phase_var_s2_2) & 0xFFFF)) < 0xBU);
  func_8002D7C0();
  var_s2 = 0;
  gSaveSlotInfo = func_8002B9FC(0x11);
  D_801001B4 = func_8002B9FC(0x52);
  D_801001CC = func_8002B9FC(0x31);
  D_801001E4 = func_8002B9FC(0x1A);
  D_801001FC = func_8002B9FC(0x33);
  D_80100214 = func_8002B9FC(0x2A);
  D_8010022C = func_8002B9FC(0x39);
  D_80100244 = func_8002B9FC(0x2E);
  D_8010025C = func_8002B9FC(0x2F);
  D_80100274 = func_8002B9FC(0x37);
  D_8010028C = func_8002B9FC(0x53);
  do
  {
    func_8002B000((temp_s1_2 * 8) + D_80117410, 0x1E);
    var_s2 += 1;
    __repair_phase_var_s2_2 = var_s2 & 0xFFFF;
    var_s2_2 = __repair_phase_var_s2_2;
    temp_s1_2 = var_s2_2;
  }
  while (((u32) (((unsigned char) (var_s2_2 = var_s2)) & ((short) 0xFFFF))) < ((unsigned) 2U));
  var_s5_2 = 0;
  do
  {
    do
    {
      __repair_phase_var_s2_2 = 0; var_s2 = ((s32) var_s5_2) & 0xFFFF;
 do { temp_s3 = var_s2 * 0x18; loop_14: temp_s1_2 = __repair_phase_var_s2_2 & 0xFFFF; temp_s0 = temp_s1_2 * 8; func_8002B000(temp_s3 + (temp_s0 + inline_fn()), 0x1E); temp_s0_2 = temp_s3 + (temp_s0 + (D_80117428 + 0x150)); } while (0);
  temp_s1_2 = 0 & 0xFFFF;
      func_8002B000(temp_s0_2, 0x1E);
      temp_a2 = *((u16 *) ((temp_s1_2 * 2) + ((((unsigned) var_s2) * 6) + D_800BFC38)));
    }
    while (0);
    func_8002B150(temp_s0_2, temp_a2 >> 8, temp_a2 & 0xFF);
    do
    {
      __repair_phase_var_s2_2 += 1;
    }
    while (0);
    if (((u32) (__repair_phase_var_s2_2 & 0xFFFF)) < 3U)
    {
      goto loop_14;
    }
    ++var_s5_2;
  }
  while (((u32) (var_s5_2 & 0xFFFF)) < 0xEU);
  memset(D_801176C8, 0, 0xE);
  D_801176D8 = 0;
  D_801176DC = 0;
  D_801176E0 = 0;
  D_801176E2 = 0;
  D_801176E4 = 0;
}
