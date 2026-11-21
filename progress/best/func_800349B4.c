s32 func_80034928();
extern u8 D_801002E5;
extern u8 D_80100774;
extern u8 D_80100775;
extern u8 D_80100776;
extern u8 D_80100778;
extern u8 D_80100779;
extern u8 D_80100775;
extern u8 D_80100774;
extern u8 D_8010077A;
extern u8 D_8010077B;
extern u8 D_8010077C;
extern u8 D_80100777;
extern u8 D_80100778;
extern u8 D_80100779;
extern u8 D_8010077A;
extern u8 D_8010077B;
extern u8 D_8010077C;
extern u8 D_801007CC;
extern u8 D_801007CD;
extern u8 D_801007CE;
extern u8 D_801007CF;
extern u8 D_801007CC;
extern u8 D_801007CD;
extern u8 D_801007CE;
extern u8 D_801007D0;
extern u8 D_801007D1;
extern u8 D_801007D2;
extern u8 D_801007D3;
extern u8 D_801007D4;
extern u8 D_80102F38;
extern u8 D_801032A4;
extern u8 D_80108F74;
extern u8 D_801093A0;
extern u8 D_8010A3C4;
extern u8 D_8010A4B8;
extern void *D_8010A4D8;
extern u8 D_80110CA8;
extern u8 D_80110DB1;
extern void *sDisplayListCursor;
inline static int inline_fn(s32 arg0, int arg1)
{
  return (arg0 + arg1) << 16;
}

inline static char *inline_fn2(void *arg0)
{
  return ((char *) arg0) + 0x145;
}

inline static int inline_fn23(s32 arg0, s32 arg1, int arg2, s32 arg3, int arg4, s32 arg5, s32 arg6, int arg7, s32 arg8)
{
  return inline_fn(arg0, ((arg1 << arg2) - arg3) * arg4) | ((((arg5 - (arg6 << 4)) * arg7) + arg8) & 0xFFFF);
}

void func_800349B4(void *arg0)
{
  register unsigned int temp_v1;
  s32 var_s1;
  s32 var_s2;
  s32 averageR;
  s32 averageG;
  s32 averageB;
  s32 fogScale;
  s32 fogStart;
s32 __repair_phase_fogStart;
  unsigned char fogEnd;
  u8 fogR;
  u8 fogG;
  u8 fogB;
  void *temp_a0;
  s32 var_s3;
  void *temp_a3;
  var_s2 = 0;
  var_s1 = 0;
  var_s3 = 0;
  if ((*((s32 *) (((char *) arg0) + 0x100))) & 1)
  {
    *((u8 *) inline_fn2(arg0)) = 0U;
    *((u8 *) (((char *) arg0) + 0x144)) = 0U;
    *((u8 *) (((char *) arg0) + 0x143)) = 0U;
    *((u8 *) (((char *) arg0) + 0x146)) = 0xFFU;
    func_80034928(arg0, D_8010A4D8);
  }
  if ((*((s32 *) (((char *) arg0) + 0x100))) & 4)
  {
    *((u8 *) (((char *) arg0) + 0x143)) = (u8) D_801093A0;
    if (1)
    {
    }
    *((u8 *) (((char *) arg0) + 0x144)) = (u8) D_801002E5;
    *((u8 *) inline_fn2(arg0)) = (u8) D_80110CA8;
    *((u8 *) (((char *) arg0) + 0x146)) = 0xFFU;
    func_80034928(arg0, D_8010A4D8);
  }
  if ((*((s32 *) (((char *) arg0) + 0x100))) & 2)
  {
    *((u8 *) (((char *) arg0) + 0x143)) = (u8) D_8010A3C4;
    *((u8 *) (((char *) arg0) + 0x144)) = (u8) D_8010A4B8;
    *((u8 *) inline_fn2(arg0)) = (u8) D_80110DB1;
    *((u8 *) (((char *) arg0) + 0x146)) = 0xFFU;
    func_80034928(arg0, (void *) 2);
  }
  temp_a3 = sDisplayListCursor;
  sDisplayListCursor = temp_a3 + 8;
  *((s32 *) (((char *) temp_a3) + 0)) = 0xFB000000;
  *((s32 *) (((char *) temp_a3) + 4)) = (s32) (((((*((u8 *) (((char *) arg0) + 0x143))) << 0x18) | ((*((u8 *) (((char *) arg0) + 0x144))) << 0x10)) | ((*((u8 *) (((char *) arg0) + 0x145))) << 8)) | (*((u8 *) (((char *) arg0) + 0x146))));
  temp_v1 = *((s32 *) (((char *) arg0) + 0x100));
  if (temp_v1 & 2)
  {
    var_s2 = 0;
    averageR = D_801007CF;
    averageG = D_801007D0;
    averageB = D_801007D1;
    *((s32 *) (((char *) temp_a3) + 8)) = 0xDB080000;
    var_s1 = ((averageR + averageG) + averageB) / 3;
    sDisplayListCursor = temp_a3 + 0x10;
    *((s32 *) (((char *) temp_a3) + 0xC)) = (s32) (((D_801007CD + 0x7530) << 0x10) | ((D_801007CE - 0x7530) & 0xFFFF));
  }
  else
    if (temp_v1 & 4)
  {
    s32 __repair_branch_fogScale_0;
    var_s2 = 0;
    *((s32 *) (((char *) temp_a3) + 8)) = 0xDB080000;
    var_s1 = 0;
    __repair_branch_fogScale_0 = D_801007CC;
    fogStart = D_801007CD;
    fogEnd = D_801007CE;
    *((s32 *) (((char *) temp_a3) + 0xC)) = (s32) (((fogStart + (((__repair_branch_fogScale_0 << 4) - __repair_branch_fogScale_0) * 8)) << 16) | ((((__repair_branch_fogScale_0 - (__repair_branch_fogScale_0 << 4)) * 8) + fogEnd) & 0xFFFF));
    fogR = D_801007D2;
    fogG = D_801007D3;
    fogB = D_801007D4;
    sDisplayListCursor = temp_a3 + 0x10;
    D_80102F38 = fogR;
    D_80108F74 = fogG;
    D_801032A4 = fogB;
    var_s3 = 0x40;
  }
  else
  {
    if (temp_v1 & 1)
    {
      s32 __repair_branch_fogScale_1;
      var_s2 = D_801007CF;
      var_s1 = D_801007D0;
      var_s3 = D_801007D1;
      *((s32 *) (((char *) temp_a3) + 8)) = 0xDB080000;
      __repair_branch_fogScale_1 = D_801007CC;
      __repair_phase_fogStart = D_801007CD;
      fogEnd = D_801007CE;
      *((s32 *) (((char *) temp_a3) + 0xC)) = (s32) inline_fn23(__repair_phase_fogStart, __repair_branch_fogScale_1, 4, __repair_branch_fogScale_1, 8, __repair_branch_fogScale_1, __repair_branch_fogScale_1, 8, fogEnd);
      fogR = D_801007D2;
      fogG = D_801007D3;
      fogB = D_801007D4;
      sDisplayListCursor = temp_a3 + 0x10;
      D_80102F38 = fogR;
      D_80108F74 = fogG;
      D_801032A4 = fogB;
    }
    if ((*((s32 *) (((char *) arg0) - (-0x100)))) & 8)
    {
      s32 __repair_branch_fogScale_2;
      var_s2 = D_80100777;
      var_s1 = D_80100778;
      var_s3 = D_80100779;
      *((s32 *) (((char *) sDisplayListCursor) + 0)) = 0xDB080000;
      __repair_branch_fogScale_2 = D_80100774;
      fogStart = D_80100775;
      fogEnd = D_80100776;
      *((s32 *) (((char *) sDisplayListCursor) + 4)) = (s32) inline_fn23(fogStart, __repair_branch_fogScale_2 << 1, 3, __repair_branch_fogScale_2, 8, __repair_branch_fogScale_2, __repair_branch_fogScale_2, 8, fogEnd);
      D_80102F38 = D_8010077A;
      sDisplayListCursor = sDisplayListCursor + 8;
      D_801032A4 = D_8010077C;
      D_80108F74 = D_8010077B;
    }
  }
  temp_a0 = sDisplayListCursor;
  sDisplayListCursor = temp_a0 + 8;
  *((s32 *) (((char *) temp_a0) + 0)) = 0xF8000000;
  *((s32 *) (((char *) temp_a0) + 4)) = (s32) ((((var_s2 << 0x18) | ((var_s1 & 0xFF) << 0x10)) | (var_s3 << 8)) | ((unsigned short) 0xFF));
}

