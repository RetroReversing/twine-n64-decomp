typedef struct { s16 a; s16 b; s16 c; s16 d; } Src8;
typedef struct { s32 x; s32 y; s32 dx; s32 dy; s32 e; s32 f; s32 g; s32 h; u8 pad[0x80]; } Dst160;
extern Dst160 D_80115108[];
s32 func_80011950();
s32 func_80081D50(s32 *, u8, int, void *);
s32 func_800828D8(s32);
s32 func_800828EC(s32);
s32 updateDemoPlayback();
s32 memset(s32 *, s32, s32);
extern s32 D_800C9D70;
extern s32 D_800C9DF8;
extern s32 D_800C9E80;
extern s32 D_800C9F08;
extern s32 D_800C9F90;
extern s32 D_800C9FC8;
extern s32 D_800CA068;
extern s32 D_800CA108;
extern s32 D_800CA1A8;
extern s32 D_800CA248;
extern s32 D_800CA278;
extern u8 D_800CEEB0;
extern s32 D_800E1A80;
extern u8 D_801002AE;
extern u16 D_801002BA;
extern s32 gBorderSkipFlag;
extern s32 D_8010A500;
extern s32 D_8010D430;
extern Src8 D_8010D434[];
extern s32 D_80112E98[];
extern s32 D_80112E9C;
extern s32 D_80112EA0;
extern s32 D_80112EAC;
extern s32 D_80112EB0;
extern s32 D_80115091;
extern char D_80115094;
void func_800821B4(void)
{
  s32 i;
  s32 v;
  s32 m;
  s32 r;
  s32 u;
  s16 n;
  s32 sp24, sp2C;
  s32 var_t8;
  s32 temp_a2;
  s32 temp_a3;
  s32 temp_t0;
  s32 temp_t1;
  s32 temp_t2;
  s32 var_a0;
  s32 var_a1;
  s32 var_v0_3;
  s32 var_s2_2;
  s32 var_s3_2;
  s32 var_s0_5;
  s32 temp_fp;
  void *temp_s5;
  void *temp_s1;
  s32 temp_s0_5;
  s32 var_a1_2;
  s32 temp_s0_6;
  unsigned temp_s0_8;
  unsigned short temp_s0_7;
  void *var_a0_2;
  func_80011950();
  if (D_800CEEB0 == 1) {
    func_80087A80();
  }
  if (D_800CEEB0 == 2) {
    updateDemoPlayback();
  }
  for (i = 0; i < 4; i++) {
    v = D_8010D434[i].a;
    if (v >= 0) { v -= 4; m = ~v >> 31; } else { v += 4; m = -(v < 1); }
    v &= m; v = (v << 16) / 76;
    if (v < -0x10000) v = -0x10000; else if (v > 0x10000) v = 0x10000;
    D_80115108[i].dx = v - D_80115108[i].x;
    D_80115108[i].x = v;
    v = D_8010D434[i].a;
    { s32 w = func_800828EC(v & -(func_800828D8(v) >= 0x21));
    if (w != D_80115108[i].g) { D_80115108[i].g = w; D_80115108[i].e = w; } else { D_80115108[i].e = 0; } }
    v = D_8010D434[i].b;
    if (v >= 0) { v -= 4; m = ~v >> 31; } else { v += 4; m = -(v < 1); }
    v &= m; v = (v << 16) / 76;
    if (v < -0x10000) v = -0x10000; else if (v > 0x10000) v = 0x10000;
    D_80115108[i].dy = v - D_80115108[i].y;
    D_80115108[i].y = v;
    v = D_8010D434[i].b;
    { s32 w = func_800828EC(v & -(func_800828D8(v) >= 0x21));
    if (w != D_80115108[i].h) { D_80115108[i].h = w; D_80115108[i].f = w; } else { D_80115108[i].f = 0; } }
  }
  if (gBorderSkipFlag == 0) { n = 4; } else { n = D_801002BA; }
  {
    s32 __block_var_s6;
    for (__block_var_s6 = 0; __block_var_s6 < (s16)n; __block_var_s6++)
    {
      s32 p8 = __block_var_s6 * 8;
      memset(D_80112E98, 0, 0x24);
      temp_s5 = ((void **) &D_8010A500)[__block_var_s6];
      temp_fp = *(((u8 *) (&D_80115091)) + (__block_var_s6 * 0xA0));
      var_a1 = 1;
      if (temp_s5 != NULL)
      {
        var_s3_2 = *((s8 *) (((char *) (*((void **) (((char *) temp_s5) + 0x6C)))) + 0x183));
        var_s2_2 = *((u16 *) (((u8 *) (&D_8010D430)) + (var_s3_2 * 8)));
        var_a0 = ((s16 *) (&D_800E1A80))[var_s3_2];
        temp_a2 = var_s2_2 & 0x2000;
        temp_a3 = var_s2_2 & 0x4000;
        temp_t2 = -(temp_a3 != 0);
        temp_t0 = var_s2_2 & 0x8000;
        temp_t1 = -(temp_t0 != 0);
        var_v0_3 = var_a0 & 7;
        do
        {
          switch (var_v0_3)
          {
            default:
              if (temp_a2 != 0) { var_a0 = 1; }
              else if (temp_a3 != 0) { var_a0 = 2; }
              else if (temp_t0 != 0) { var_a0 = 3; }
              else { var_a1 = 0; }
              break;
            case 1:
              if (temp_a2 != 0) {
                D_80112E98[1] = 1;
                var_a1 = 0;
                if (temp_a3 != 0) { D_80112E98[2] = 1; }
              } else { var_a0 = 0; }
              break;
            case 2:
              if (temp_a3 != 0) {
                if (temp_a2 != 0) { D_80112E98[5] = 1; var_a0 = 4; }
                else if (temp_t0 != 0) { D_80112E98[6] = 1; var_a0 = 5; }
                else { var_a1 = 0; }
              } else {
                if (!(var_a0 & 8)) { D_80112E98[2] = 1; }
                var_a0 = 0;
              }
              break;
            case 3:
              if (temp_t0 != 0) {
                if (temp_a2 != 0) { D_80112E98[3] = 1; var_a0 = 6; }
                else if (temp_a3 != 0) { D_80112E98[7] = 1; var_a0 = 7; }
                else { var_a1 = 0; }
              } else {
                if (!(var_a0 & 8)) { D_80112E98[4] = 1; }
                var_a0 = 0;
              }
              break;
            case 4:
              if (temp_a2 != 0) { var_a1 = 0; } else { var_a0 = temp_t2 & 0xA; }
              break;
            case 5:
              if (temp_t0 != 0) { var_a1 = 0; } else { var_a0 = temp_t2 & 0xA; }
              break;
            case 6:
              if (temp_a2 != 0) { var_a1 = 0; } else { var_a0 = temp_t1 & 0xB; }
              break;
            case 7:
              if (temp_a3 != 0) { var_a1 = 0; } else { var_a0 = temp_t1 & 0xB; }
              break;
          }
          var_v0_3 = var_a0 & 7;
        }
        while (var_a1 != 0);
        ((s16 *) (&D_800E1A80))[var_s3_2] = var_a0;
      }
      else
      {
        var_s3_2 = __block_var_s6;
        var_s2_2 = *((u16 *) (((u8 *) (&D_8010D430)) + p8));
      }
      temp_s1 = (__block_var_s6 * 0xA0) + (&D_80115094);
      func_80081D50(&D_800CA278, (u8)var_s3_2, var_s2_2, temp_s1);
      if ((temp_s5 != NULL) && (D_801002AE == 0))
      {
        switch (temp_fp)
        {
          case 0:
            func_80081D50(&D_800C9D70, (u8)var_s3_2, var_s2_2, temp_s1);
            func_80081D50(&D_800C9F90, (u8)var_s3_2, var_s2_2, temp_s1);
            break;
          case 1:
            func_80081D50(&D_800C9DF8, (u8)var_s3_2, var_s2_2, temp_s1);
            func_80081D50(&D_800C9F90, (u8)var_s3_2, var_s2_2, temp_s1);
            break;
          case 2:
            func_80081D50(&D_800C9FC8, (u8)var_s3_2, var_s2_2, temp_s1);
            func_80081D50(&D_800CA248, (u8)var_s3_2, var_s2_2, temp_s1);
            break;
          case 3:
            func_80081D50(&D_800CA068, (u8)var_s3_2, var_s2_2, temp_s1);
            func_80081D50(&D_800CA248, (u8)var_s3_2, var_s2_2, temp_s1);
            break;
          case 4:
            func_80081D50(&D_800C9E80, (u8)var_s3_2, var_s2_2, temp_s1);
            func_80081D50(&D_800C9F90, (u8)var_s3_2, var_s2_2, temp_s1);
            break;
          case 5:
            func_80081D50(&D_800C9F08, (u8)var_s3_2, var_s2_2, temp_s1);
            func_80081D50(&D_800C9F90, (u8)var_s3_2, var_s2_2, temp_s1);
            break;
          case 6:
            func_80081D50(&D_800CA108, (u8)var_s3_2, var_s2_2, temp_s1);
            func_80081D50(&D_800CA248, (u8)var_s3_2, var_s2_2, temp_s1);
            break;
          default:
            func_80081D50(&D_800CA1A8, (u8)var_s3_2, var_s2_2, temp_s1);
            func_80081D50(&D_800CA248, (u8)var_s3_2, var_s2_2, temp_s1);
            break;
        }
      }
    }
  }
}


