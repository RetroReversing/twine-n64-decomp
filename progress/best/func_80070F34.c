f32 __cosf(f32);
s32 effectSetAnimFrame(void *, s16, s16);
void *func_80015F0C(s32);
s32 func_800165E0(void *, s32);
s32 func_80016600(void *);
s32 func_80063C7C(s8);
s32 func_80064318(void *, s8);
s32 func_80070ECC(void *, void *, s32, s32, s32, s32);
s32 func_800AB9B0(void *);
s32 heapAllocTagged(s32, s32);
s32 initObjectFromBankEntry(void *, u8, s32);
char *lookupDataEntry(u16);
s32 memset(s32, s32, s32);
f32 sinApprox(f32);
void *spawnEffectObject(s32, s32, s32);
void *spawnTrackMarker(s8);
s32 sprintf(char *, const char *, ...);
s16 strlen(void *);
extern s32 D_800C46FC;
extern s16 D_800C7E10;
extern s16 D_800C7E12;
extern s32 D_800C7E14;
extern u16 D_800C7E18;
extern u8 D_800C7E40;
typedef struct { s8 first, second; } EnemyPair;
extern EnemyPair D_800D47A0;
extern char D_800D47A4[];
extern char D_800D47A8[];
extern f64 D_800D47F8;
extern f64 D_800D4800;
extern f64 D_800D4808;
extern f64 D_800D4810;
extern u8 D_8011508D;
extern u8 gBorderFlipFlag;
extern s32 gBorderSkipActive;
extern u8 gPauseFlag;
extern s32 gVisibleSaveSlotCount;
extern s32 sEnemyDefTable;
extern s32 sTrackMarkerTable;
void func_80070F34(void *arg0)
{
  s16 *__base_D_800C7E10;
  volatile u32 reserved[2];
  void *sp1C;
  char *temp_s0;
  f32 temp_fs0;
  f32 temp_ft0;
  f32 temp_fv1;
  f32 temp_fv1_10;
  f32 temp_fv1_11;
  f32 temp_fv1_12;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  f32 temp_fv1_4;
  f32 temp_fv1_5;
  f32 temp_fv1_6;
  f32 temp_fv1_7;
  register f32 temp_fv1_8;
  f32 temp_fv1_9;
  f32 width;
  f32 height;
  f32 var_fs1;
  f32 var_fs2;
  f32 var_fs2_2;
  f32 var_fs3;
  f32 var_fv1;
  register f32 var_fv1_2;
  f32 var_fv1_3;
  f64 phaseOffset;
  f64 temp_fs0_2;
  f64 temp_fs0_3;
  f64 temp_fs1;
  f64 temp_fs4;
  f64 temp_fs5;
  s16 temp_v0_15;
  s16 temp_v1_14;
  s32 temp_a0_10;
  s32 temp_a0_11;
  s32 temp_a0_12;
  s32 temp_a0_14;
  s32 temp_a0_8;
  s32 temp_a0_9;
  register s32 temp_a1_2;
  s32 temp_fv0;
  s32 temp_v0_12;
  unsigned long temp_v0_14;
  s32 var_a1;
  s32 var_a1_2;
  s32 var_a1_3;
  s32 var_a2;
  s32 var_a2_2;
  s32 var_a3;
  register s32 var_s0;
  s32 var_s5;
  register s32 var_v0;
  s32 var_v0_2;
  u32 var_v1;
  s32 var_v1_2;
  s32 var_v1_3;
  s32 var_v1_4;
  s8 temp_v0_4;
  u32 temp_t0;
  u32 temp_v0_13;
  register u32 temp_v1_22;
  u32 temp_v1_23;
  u32 var_a0_2;
  u32 var_s0_2;
  u32 var_s0_3;
  u32 var_s3;
  u32 var_s3_2;
  u32 var_s3_3;
  u8 *temp_v1_20;
  u8 *temp_v1_21;
  u8 *var_v1_6;
  s32 temp_a0_2;
  u32 temp_s6;
  register u8 temp_v1_19;
  s16 var_s1_2;
  u8 var_v0_5;
  void *temp_a0;
  void *temp_a0_13;
  void *temp_a0_3;
  void *temp_a0_4;
  register void *temp_a0_5;
  void *temp_a0_6;
  register void *temp_a0_7;
  void *temp_a1;
  void *temp_a1_3;
  void *temp_s0_2;
  void *temp_s0_3;
  void *temp_s0_4;
  void *temp_s0_5;
  void *temp_s2;
  void *temp_v0;
  void *temp_v0_10;
  void *temp_v0_11;
  void *temp_v0_16;
  void *temp_v0_2;
  void *temp_v0_3;
  void *temp_v0_5;
  void *temp_v0_6;
  void *temp_v0_7;
  void *temp_v0_8;
  void *temp_v0_9;
  void *temp_v1;
  register void *temp_v1_10;
  void *temp_v1_11;
  void *temp_v1_12;
  void *temp_v1_13;
  void *temp_v1_15;
  void *temp_v1_16;
  void *temp_v1_17;
  void *temp_v1_18;
  void *temp_v1_24;
  void *temp_v1_2;
  void *temp_v1_3;
  void *temp_v1_4;
  void *temp_v1_5;
  void *temp_v1_6;
  void *temp_v1_7;
  void *temp_v1_8;
  void *temp_v1_9;
  void *var_a0;
  void *var_s1;
  void *var_s1_3;
  void *var_s1_4;
  void *var_t1;
  void *var_v1_5;
  temp_s2 = *((void **) (((char *) arg0) + 0x6C));
  width = 160.0f;
  var_fs2 = width;
  temp_v0 = ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) * 0xE8) + ((u8 *) (&sEnemyDefTable));
  sp1C = temp_v0;
  temp_s6 = *((u8 *) (((char *) temp_v0) + 0x80));
  height = 120.0f;
  var_fs1 = height;
  if (gBorderSkipActive != 0)
  {
    if (gVisibleSaveSlotCount != 2)
    {
      if (gVisibleSaveSlotCount >= 3)
      {
        if (gVisibleSaveSlotCount < 5)
        {
          var_fs2 = 80.0f;
          var_fs1 = 60.0f;
          width = var_fs2;
          height = var_fs1;
        }
      }
    }
    else
      if (gBorderFlipFlag == 1)
    {
      width = (var_fs2 = 80.0f);
    }
    else
    {
      height = (var_fs1 = 60.0f);
    }
    if (gBorderSkipActive == 0)
    {
      goto block_10;
    }
  }
  else
  {
    block_10:
    var_s3 = 0;

    var_s0 = 0;
    var_s5 = 0x438;
    var_s1 = temp_s2;
    do
    {
      if ((*((void **) (((char *) var_s1) + 0x418))) == NULL)
      {
        temp_v0_2 = spawnTrackMarker(*((s8 *) (((char *) temp_s2) + 0x182)));
        *((void **) (((char *) var_s1) + 0x418)) = temp_v0_2;
        if (temp_v0_2 != NULL)
        {
          var_a2 = (u32) (temp_fv1 = (2.0f * var_fs2) + ((f32) (*((s16 *) (((char *) (__base_D_800C7E10 = &D_800C7E10)) + var_s0)))));
          temp_fv1_2 = (2.0f * var_fs1) + ((f32) (*((s16 *) (((char *) (&D_800C7E12)) + var_s0))));
          ;
          func_80070ECC(*((void **) (((char *) var_s1) + 0x418)), temp_s2 + var_s5, var_a2 & 0xFFFF, ((u32) temp_fv1_2) & 0xFFFF, (s32) (*((u16 *) (((char *) (&D_800C7E18)) + var_s0))), *((s32 *) (((char *) (&D_800C7E14)) + var_s0)));
        }
      }
      var_s0 += 0xC;
      var_s5 += 0x10;
      var_s3 += 1;
      var_s1 += 4;
    }
    while (var_s3 < 4U);
    if ((*((void **) (((char *) temp_s2) + 0x428))) == NULL)
    {
      temp_v0_3 = spawnTrackMarker(*((s8 *) (((char *) temp_s2) + 0x182)));
      *((void **) (((char *) temp_s2) + 0x428)) = temp_v0_3;
      if (temp_v0_3 != NULL)
      {
        temp_v1 = (void *) ((((int) var_s3) * 4) + ((s32) temp_s2));
        temp_a1 = *((void **) (((char *) temp_v1) + 0x418));
        temp_fv1_3 = ((2.0f * var_fs2) - 66.0f) - 8.0f;
        *((s32 *) (((char *) temp_a1) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_a1) + 0x28))) & (~0xFC)) | 0x10);
        temp_a0 = *((void **) (((char *) temp_v1) + 0x418));
        if (!(temp_fv1_3 >= 2147483648.0f))
          var_v1 = (s32)temp_fv1_3;
        else
          var_v1 = ((s32)(temp_fv1_3 - 2147483648.0f)) | 0x80000000U;
        var_fv1 = 2.0f * var_fs1;
        temp_fv1_4 = var_fv1 - 48.0f;
        *((s16 *) (((char *) temp_a0) + 0x20)) = (s16) var_v1;
        temp_a0 = *((void **) (((char *) temp_v1) + 0x418));
        *((s16 *) (((char *) temp_a0) + 0x22)) = (u16) ((u32) temp_fv1_4);
        temp_v1_2 = (void *) ((var_s3 * 4) + ((s32) temp_s2));
        *((s32 *) (((char *) (*((void **) (((char *) temp_v1_2) + 0x418)))) + 0x10)) = -0x60;
        *((s32 *) (((char *) (*((void **) (((char *) temp_v1_2) + 0x418)))) + 0x14)) = 0x20202000;
        *((s16 *) (((char *) (*((void **) (((char *) temp_v1_2) + 0x418)))) + 0x1E)) = 0;
        initObjectFromBankEntry(*((void **) (((char *) temp_v1_2) + 0x418)), 0x19U, 0x1B);
      }
    }
    temp_a0_2 = *((u8 *) (((char *) (*((void **) (((char *) temp_s2) + 0x418)))) + 0x13));
    temp_v0_4 = *((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE));
    var_s1_2 = temp_a0_2;
    if (((temp_v0_4 == 0) | (temp_v0_4 >= 0x27)) != 0)
    {
      if (((s32) temp_a0_2) >= 4)
      {
        var_s1_2 = temp_a0_2 - 4;
      }
    }
    else
    {
      switch (temp_s6)
      {
        case 0:
          temp_v1_3 = *((void **) (((char *) temp_s2) + 0x428));
          *((u16 *) (((char *) temp_v1_3) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v1_3) + 0x1E))) | 2);
          *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x428)))) + 0x10)) = -1;
          break;

        case 15:
          temp_v1_4 = *((void **) (((char *) temp_s2) + 0x428));
          *((u16 *) (((char *) temp_v1_4) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v1_4) + 0x1E))) | 2);
          *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x428)))) + 0x10)) = 0xFFFFFF;
          break;

        case 16:
          temp_v1_5 = *((void **) (((char *) temp_s2) + 0x428));
          *((u16 *) (((char *) temp_v1_5) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v1_5) + 0x1E))) | 2);
          *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x428)))) + 0x10)) = 0xFF00FF;
          break;

        case 17:
          temp_v1_6 = *((void **) (((char *) temp_s2) + 0x428));
          *((u16 *) (((char *) temp_v1_6) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v1_6) + 0x1E))) | 2);
          *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x428)))) + 0x10)) = 0xFF0000FF;
          break;

        default:
          temp_v1_7 = *((void **) (((char *) temp_s2) + 0x428));
          *((u16 *) (((char *) temp_v1_7) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v1_7) + 0x1E))) & 0xFFFD);
          *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x428)))) + 0x10)) = -0x60;
          break;

      }

      initObjectFromBankEntry(*((void **) (((char *) temp_s2) + 0x428)), *((u8 *) (((char *) (&D_800C7E40)) + temp_s6)), 0x1B);
      temp_a0_3 = *((void **) (((char *) temp_s2) + 0x428));
      temp_fv1_5 = ((2.0f * var_fs1) - 16.0f) - ((f32) (*((u8 *) (((char *) temp_a0_3) + 0x28))));
      var_v1_2 = (u32) temp_fv1_5;
      var_v0_2 = var_s1_2;
      *((s16 *) (((char *) temp_a0_3) + 0x22)) = (s16) var_v1_2;
      if (var_v0_2 < 0x80)
      {
        var_s1_2 += 4;
      }
      if ((*((s32 *) (((char *) (&D_800C46FC)) + ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) * 0xE8)))) & 0x10000)
      {
        temp_v0_5 = *((void **) (((char *) (*((void **) (((char *) temp_s2) + 0x418)))) + 0x18));
        *(EnemyPair *)temp_v0_5 = D_800D47A0;
        temp_v0_6 = *((void **) (((char *) (*((void **) (((char *) temp_s2) + 0x41C)))) + 0x18));
        *(EnemyPair *)temp_v0_6 = D_800D47A0;
      }
      else
      {
        temp_s0 = D_800D47A4;
        sprintf(*((void **) (((char *) (*((void **) (((char *) temp_s2) + 0x418)))) + 0x18)), temp_s0, *((s16 *) (((char *) (temp_s2 + (temp_s6 * 2))) + 0x1BC)));
        sprintf(*((void **) (((char *) (*((void **) (((char *) temp_s2) + 0x41C)))) + 0x18)), temp_s0, (s16) (*((s8 *) (((char *) (temp_s2 + (((s32) (func_80063C7C(*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) << 0x10)) >> 0xD))) + 0x1FF))));
      }
      sprintf(*((void **) (((char *) (*((void **) (((char *) temp_s2) + 0x420)))) + 0x18)), D_800D47A8, lookupDataEntry(*((u16 *) (((char *) (((*((u8 *) (((char *) (temp_s2 + ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) * 8))) + 0x1FD))) * 2) + sp1C)) + 0x2C))));
    }
    *((u8 *) (((char *) temp_s2) + 0x18C)) = 0x80;
    temp_fv1_6 = *((f32 *) (((char *) arg0) + 0x74));
    if ((temp_fv1_6 != (*((f32 *) (((char *) temp_s2) + 0x68)))) && ((*((u8 *) (((char *) temp_s2) + 0x18D))) != 1))
    {
      *((f32 *) (((char *) temp_s2) + 0x68)) = temp_fv1_6;
      *((u8 *) (((char *) temp_s2) + 0x18D)) = 0x80U;
    }
    temp_fv1_7 = *((f32 *) (((char *) temp_s2) + 0x60));
    if ((temp_fv1_7 != (*((f32 *) (((char *) temp_s2) + 0x64)))) && ((*((u8 *) (((char *) temp_s2) + 0x18D))) != 1))
    {
      *((f32 *) (((char *) temp_s2) + 0x64)) = temp_fv1_7;
      *((u8 *) (((char *) temp_s2) + 0x18D)) = 0x80U;
    }
    temp_fv1_8 = (*((f32 *) (((char *) arg0) + 0x74))) * 0.48f;
    temp_a0_4 = *((void **) (((char *) temp_s2) + 0x478));
    *((u16 *) (((char *) temp_a0_4) + 0x26)) = (u16) ((u32) temp_fv1_8);
    temp_fv1_9 = (*((f32 *) (((char *) temp_s2) + 0x60))) * 0.48f;
    temp_a0_5 = *((void **) (((char *) temp_s2) + 0x47C));
    *((s16 *) (((char *) temp_a0_5) + 0x26)) = (u16) temp_fv1_9;
    if ((*((f32 *) (((char *) temp_s2) + 0x60))) > 0.0f)
    {
      temp_v1_8 = *((void **) (((char *) temp_s2) + 0x488));
      *((s32 *) (((char *) temp_v1_8) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_8) + 0x28))) & (~0xFC)) | 0x10);
      *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x47C)))) + 0x28)) = ((*((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x47C)))) + 0x28))) & (~0xFC)) | 0x10;
    }
    else
    {
      temp_v1_9 = *((void **) (((char *) temp_s2) + 0x488));
      *((s32 *) (((char *) temp_v1_9) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v1_9) + 0x28))) & (~0xFC)) | 0x1C);
      *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x47C)))) + 0x28)) = ((*((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x47C)))) + 0x28))) & (~0xFC)) | 0x1C;
    }
    if ((*((f32 *) (((char *) arg0) + 0x74))) > 0.0f)
    {
      temp_v1_10 = *((void **) (((char *) temp_s2) + 0x478));
      if ((*((u16 *) (((char *) temp_v1_10) + 0x26))) == 0)
      {
        *((u16 *) (((char *) temp_v1_10) + 0x26)) = 1U;
      }
    }
    if ((*((f32 *) (((char *) arg0) + 0x74))) < 30.0f)
    {
      *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x478)))) + 0x10)) = 0xAA0000FF;
    }
    var_s3_2 = 0;
    do
    {
      if (var_s3_2 != 3)
      {
        if ((*((u8 *) (((char *) (&D_8011508D)) + ((*((s8 *) (((char *) temp_s2) + 0x182))) * 0xA0)))) == 0)
        {
          *((s32 *) (((char *) (*((void **) (((char *) (((char *) temp_s2) + (var_s3_2 * 4))) + 0x418)))) + 0x10)) = 0;
        }
        else
          if (var_s3_2 == 4)
        {
          temp_v1_11 = *((void **) (((char *) temp_s2) + 0x428));
          do
          {
            *((s32 *) (((char *) temp_v1_11) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_11) + 0x10))) & (~0xFF)); temp_v1_12 = *((void **) (((char *) temp_s2) + 0x428));
          }
          while (0);
          *((s32 *) (((char *) temp_v1_12) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_12) + 0x10))) | ((s16) var_s1_2));
        }
        else
        {
          *((s32 *) (((char *) (*((void **) (((char *) (((char *) temp_s2) + (var_s3_2 * 4))) + 0x418)))) + 0x10)) = (s32) (((s16) var_s1_2) | 0xFF0000);
        }
      }
      var_s3_2 += 1;
    }
    while (var_s3_2 < 5U);
    var_s3_3 = 0;
    var_s1_3 = temp_s2;
    do
    {
      ++var_s3_3;
      if ((*((void **) (((char *) var_s1_3) + 0x418))) != NULL)
      {
        *((s16 *) (((char *) (*((void **) (((char *) var_s1_3) + 0x418)))) + 0x1C)) = strlen(*((void **) (((char *) (*((void **) (((char *) var_s1_3) + 0x418)))) + 0x18)));
      }
      var_s1_3 += 4;
    }
    while (var_s3_3 < 4U);
    temp_a0_6 = *((void **) (((char *) temp_s2) + 0x48C));
    if (temp_a0_6 == NULL)
    {
      temp_v0_7 = spawnEffectObject(0, 0, 0);
      if (temp_v0_7 != NULL)
      {
        *((void **) (((char *) temp_s2) + 0x48C)) = temp_v0_7;
        *((void **) (((char *) temp_v0_7) + 0x18)) = arg0;
        *((s16 *) (((char *) temp_v0_7) + 0x78)) = 0x30;
        *((s32 *) (((char *) temp_v0_7) + 0x40)) = 0;
        *((f32 *) (((char *) temp_v0_7) + 0x24)) = 0.276f;
        *((f32 *) (((char *) temp_v0_7) + 0x28)) = 0.17f;
        *((f32 *) (((char *) temp_v0_7) + 0x2C)) = 0.5f;
        *((f32 *) (((char *) temp_v0_7) + 0x3C)) = -20.48f;
        *((f32 *) (((char *) temp_v0_7) + 0x44)) = -2048.0f;
        func_80064318(temp_v0_7, (int) (*((s8 *) (((char *) temp_s2) + 0x182))));
      }
    }
    else
    {
      temp_v0_8 = ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xE))) * 0xE8) + ((u8 *) (&sEnemyDefTable));
      effectSetAnimFrame(temp_a0_6, *((s16 *) (((char *) temp_v0_8) + 0x38)), *((s16 *) (((char *) temp_v0_8) + 0x3A)));
      temp_v0_9 = *((void **) (((char *) temp_s2) + 0x48C));
      *((f32 *) (((char *) temp_v0_9) + 0x54)) = (f32) ((0.0625f / (*((f32 *) (((char *) temp_v0_9) + 0x64)))) * 0.0134375f);
      temp_v1_13 = *((void **) (((char *) temp_s2) + 0x48C));
      *((s32 *) (((char *) temp_v1_13) + 0x58)) = (s32) ((*((s32 *) (((char *) temp_v1_13) + 0x58))) | 0x1000);
      temp_v0_10 = *((void **) (((char *) temp_s2) + 0x48C));
      *((f32 *) (((char *) temp_v0_10) + 0x40)) = (f32) ((*((f32 *) (((char *) temp_v0_10) + 0x40))) + 68.26667f);
    }
  }
  if ((*((void **) (((char *) temp_s2) + 0x490))) == NULL)
  {
    if ((gBorderSkipActive == 0) || gPauseFlag)
    {
      *((void **) (((char *) temp_s2) + 0x490)) = spawnTrackMarker(*((s8 *) (((char *) temp_s2) + 0x182)));
    }
  }
  else
  {
    temp_v1_14 = *((s16 *) (((char *) (*((void **) (((char *) temp_s2) + 0xA8)))) + 0x7A));
    switch (temp_v1_14)
    {
      case 1:

      case 2:

      case 3:

      case 4:

      case 6:

      case 8:

      case 10:

      case 11:
        if ((*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xF))) < 0x37)
      {
        temp_fv1_10 = (2.0f * height) - 44.0f;
        var_v1_3 = (u32) temp_fv1_10;
        *((s16 *) (((char *) (*((void **) (((char *) temp_s2) + 0x490)))) + 0x20)) = 0x20;
        *((s16 *) (((char *) (*((void **) (((char *) temp_s2) + 0x490)))) + 0x22)) = (s16) var_v1_3;
        temp_s0_3 = (void *) (0x494 + ((s32) temp_s2));
        sprintf(temp_s0_3, D_800D47A8, lookupDataEntry((((s8) ((u8) (*((s8 *) (((char *) (*((void **) (((char *) arg0) + 0x68)))) + 0xF))))) | 0x6000) & 0xFFFF));
        *((void **) (((char *) (*((void **) (((char *) temp_s2) + 0x490)))) + 0x18)) = temp_s0_3;
        temp_s0_4 = *((void **) (((char *) temp_s2) + 0x490));
        *((s16 *) (((char *) temp_s0_4) + 0x1C)) = strlen(*((void **) (((char *) temp_s0_4) + 0x18)));
        if (gBorderSkipActive != 0)
        {
          temp_fv1_11 = (2.0f * height) - 34.0f;
          *((s16 *) (((char *) (*((void **) (((char *) temp_s2) + 0x490)))) + 0x20)) = 0x16;
          temp_a0_7 = *((void **) (((char *) temp_s2) + 0x490));
          *((s16 *) (((char *) temp_a0_7) + 0x22)) = (u16) ((u32) temp_fv1_11);
          temp_v1_15 = *((void **) (((char *) temp_s2) + 0x490));
          *((u16 *) (((char *) temp_v1_15) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v1_15) + 0x1E))) | 0x840);
          func_800AB9B0(temp_s2 + 0x494);
        }
        else
        {
          temp_v1_16 = *((void **) (((char *) temp_s2) + 0x490));
          *((u16 *) (((char *) temp_v1_16) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v1_16) + 0x1E))) | 0x20);
        }
        temp_v1_17 = *((void **) (((char *) temp_s2) + 0x490));
        *((s32 *) (((char *) temp_v1_17) + 0x10)) = (s32) ((*((s32 *) (((char *) temp_v1_17) + 0x10))) | 0xFF);
      }
        break;

      case 0:

      case 5:

      case 7:

      case 9:
        temp_v1_18 = *((void **) (((char *) temp_s2) + 0x490));
        temp_a0_8 = *((s32 *) (((char *) temp_v1_18) + 0x10));
        if (!(((u32) (temp_a0_8 & 0xFF)) < 9U))
      {
        *((s32 *) (((char *) temp_v1_18) + 0x10)) = (s32) (temp_a0_8 - 8);
      }
      else
      {
        *((void **) (((char *) temp_v1_18) + 0x18)) = NULL;
        *((s16 *) (((char *) (*((void **) (((char *) temp_s2) + 0x490)))) + 0x1C)) = 0;
      }
        break;

    }

  }
  temp_v1_19 = *((u8 *) (((char *) temp_s2) + 0x5A8));
  switch (temp_v1_19)
  {
    case 0:
      if ((*((void **) (((char *) temp_s2) + 0x514))) == NULL)
    {
      temp_v0_11 = func_80015F0C(0);
      *((void **) (((char *) temp_s2) + 0x514)) = temp_v0_11;
      if (temp_v0_11 != NULL)
      {
        func_80016600(temp_v0_11);
        func_800165E0(*((void **) (((char *) temp_s2) + 0x514)), ((s32 *) (&sTrackMarkerTable))[*((s8 *) (((char *) temp_s2) + 0x182))]);
        *((s32 *) (((char *) temp_v0_11) + 0xC)) = 0;
        *((s32 *) (((char *) temp_v0_11) + 0x28)) = (s32) ((((*((s32 *) (((char *) temp_v0_11) + 0x28))) & (~0xFC)) | 0x1C) & (~3));
        temp_v0_12 = heapAllocTagged(0x1000, 0x1A);
        *((s32 *) (((char *) temp_s2) + 0x5A4)) = temp_v0_12;
        *((s32 *) (((char *) temp_v0_11) + 8)) = temp_v0_12;
        temp_fv1_12 = 2.0f * width;
        *((s16 *) (((char *) temp_v0_11) + 0x24)) = 0x40;
        *((s32 *) (((char *) temp_v0_11) + 0x28)) = 0x80;
        *((s16 *) (((char *) temp_v0_11) + 0x20)) = 0;
        *((s16 *) (((char *) temp_v0_11) + 0x22)) = 0;
        var_v1_4 = (u32) temp_fv1_12;
        var_fv1_2 = 2.0f * height;
        *((s16 *) (((char *) temp_v0_11) + 0x26)) = (s16) var_v1_4;
        var_a1 = (u32) var_fv1_2;
        *((u16 *) (((char *) temp_v0_11) + 0x1E)) = 0x400U;
        *((s8 *) (((char *) temp_v0_11) + 0x29)) = (s8) var_a1;
        *((s32 *) (((char *) temp_v0_11) + 0x10)) = 0x3F000080;
        *((s32 *) (((char *) temp_v0_11) + 0x14)) = 0x20000080;
        *((u16 *) (((char *) temp_v0_11) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v0_11) + 0x1E))) | 2);
      }
    }
      var_a0_2 = 0;
      do
    {
      *((s16 *) (((char *) (((char *) temp_s2) + (var_a0_2 * 2))) + 0x522)) = 2;
      ++var_a0_2;
    }
    while (var_a0_2 < 0x40U);
      memset(*((s32 *) (((char *) temp_s2) + 0x5A4)), 0, 0x1000);
      *((u8 *) (((char *) temp_s2) + 0x5A8)) = 1U;
      *((f32 *) (((char *) temp_s2) + 0x51C)) = 0.0f;
      *((f32 *) (((char *) temp_s2) + 0x518)) = 0.0f;
      if (gBorderSkipActive != 0)
    {
      *((u32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x514)))) + 0x10)) = 0x3F0000FFU;
      *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x514)))) + 0x14)) = 0x200000FF;
      return;
    }

    default:
      return;

    case 2:
      var_fs3 = *((f32 *) (((char *) temp_s2) + 0x518));
      var_fs2_2 = 0.0f;
      temp_a1_2 = (s32) (*((f32 *) (((char *) temp_s2) + 0x51C)));
      if (gBorderSkipActive != 0)
    {
      var_fv1_3 = 2.45f;
      *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x514)))) + 0x28)) = ((*((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x514)))) + 0x28))) & (~0xFC)) | 4;
    }
    else
    {
      var_fv1_3 = 0.8f;
      *((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x514)))) + 0x28)) = (*((s32 *) (((char *) (*((void **) (((char *) temp_s2) + 0x514)))) + 0x28))) & (~0xFC);
    }
      *((f32 *) (((char *) temp_s2) + 0x51C)) = (f32) ((*((f32 *) (((char *) temp_s2) + 0x51C))) + var_fv1_3);
      if ((*((f32 *) (((char *) temp_s2) + 0x51C))) > 175.0f)
    {
      *((u8 *) (((char *) temp_s2) + 0x5A8)) = 3U;
    }
      var_s0_2 = 0;
      temp_fs1 = (f64) ((s16) temp_a1_2);
      phaseOffset = D_800D47F8;
      temp_fs5 = D_800D4800;
      temp_fs4 = D_800D4808;
      var_s1_4 = temp_s2;
      do
    {
      temp_fs0 = sinApprox(var_fs2_2);
      temp_fs0_2 = (f64) (temp_fs0 + sinApprox((f32) ((((f64) var_fs2_2) + phaseOffset) * temp_fs5)));
      var_fs2_2 += 0.21f;
      temp_fs0_3 = temp_fs1 + ((temp_fs0_2 + ((((f64) __cosf(var_fs3)) * temp_fs4) * temp_fs1)) * D_800D4810);
      var_s0_2 = var_s0_2 + 1;
      var_fs3 += 0.133f;
      temp_fv0 = (s32) temp_fs0_3;
      *((s16 *) (((char *) var_s1_4) + 0x522)) = (s16) (temp_fv0 & (((s32) (~((s16) temp_fv0))) >> 0x1F));
      var_s1_4 += 2;
    }
    while (var_s0_2 < 0x40U);
      var_s0_3 = 0;
      var_t1 = temp_s2;
      *((f32 *) (((char *) temp_s2) + 0x518)) = (f32) ((*((f32 *) (((char *) temp_s2) + 0x518))) + (-0.05f));
      do
    {
      temp_t0 = var_s0_3 >> 1;
      var_a2_2 = 0;
      loop_154:
      var_a1_2 = var_a2_2;

      temp_a0_9 = (*((u16 *) (((char *) var_t1) + 0x522))) - var_a2_2;
      if (((u32) (var_a1_2 & 0xFF)) >= 0x10U)
      {
        var_a1_2 = 0xF;
      }
      if (temp_a0_9 >= 0)
      {
        do
        {
          if (temp_a0_9 < 0x7F)
          {
            temp_a0_10 = temp_a0_9 << 5;
            if (!(var_s0_3 & 1))
            {
              temp_a0_11 = temp_a0_10 + temp_t0; temp_v1_20 = (*((s32 *) (((char *) temp_s2) + 0x5A4))) + temp_a0_11;
              *temp_v1_20 &= 0xF; var_v1_6 = (*((s32 *) (((char *) temp_s2) + 0x5A4))) + temp_a0_11; var_v0_5 = (*var_v1_6) | (var_a1_2 * 0x10);
            }
            else
            {
              temp_a0_12 = temp_a0_10 + temp_t0; temp_v1_21 = (*((s32 *) (((char *) temp_s2) + 0x5A4))) + temp_a0_12;
              *temp_v1_21 &= 0xF0; var_v1_6 = (*((s32 *) (((char *) temp_s2) + 0x5A4))) + temp_a0_12; var_v0_5 = (*var_v1_6) | var_a1_2;
            }
            *var_v1_6 = var_v0_5;
          }
          ++var_a2_2;
          goto loop_154;
        }
        while (0);
      }
      var_s0_3 += 1;
      var_t1 += 2;
    }
    while (var_s0_3 < 0x40U);
      temp_ft0 = *((f32 *) (((char *) temp_s2) + 0x34));
      *((f32 *) (((char *) temp_s2) + 0x34)) = (f32) (temp_ft0 + ((0.66f - temp_ft0) * 0.015625f));
      if (gBorderSkipActive != 0)
    {
      temp_a0_13 = *((void **) (((char *) temp_s2) + 0x514));
      temp_v1_22 = *((u32 *) (((char *) temp_a0_13) + 0x10));
      if (((u32) (temp_v1_22 & 0xFF)) < 0xC8U)
      {
        *((u32 *) (((char *) temp_a0_13) + 0x10)) = (u32) (temp_v1_22 + 1);
        return;
      }
    }
      break;

    case 3:
      if (gBorderSkipActive != 0)
    {
      temp_s0_5 = *((void **) (((char *) temp_s2) + 0x514));
      temp_v0_13 = *((u32 *) (((char *) temp_s0_5) + 0x10));
      temp_a0_14 = (temp_v0_13 & 0xFF) + 4;
      var_a1_3 = temp_a0_14;
      ;
      if (temp_a0_14 >= 0x100)
      {
        var_a1_3 = 0xFF;
      }
      *((u32 *) (((char *) temp_s0_5) + 0x10)) = (u32) (var_a1_3 | ((((temp_v0_13 >> 0x18) - 4) & (((s32) (~((temp_v0_13 >> 0x18) - 4))) >> 0x1F)) << 0x18));
      return;
    }
      break;

    case 1:
      break;

    case 4:
      temp_a1_3 = *((void **) (((char *) temp_s2) + 0x514));
      temp_v1_23 = *((u32 *) (((char *) temp_a1_3) + 0x10));
      temp_v0_15 = (temp_v1_23 & 0xFF) - 0x10;
      if (temp_v0_15 <= 0)
    {
      temp_v0_16 = *((void **) (((char *) temp_s2) + 0x514));
      *((u8 *) (((char *) temp_s2) + 0x5A8)) = 0U;
      *((s32 *) (((char *) temp_v0_16) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v0_16) + 0x28))) & (~0xFC)) | 0x1C);
      return;
    }
      *((u32 *) (((char *) temp_a1_3) + 0x10)) = (u32) (temp_v1_23 & (~0xFF));
      temp_v1_24 = *((void **) (((char *) temp_s2) + 0x514));
      *((u32 *) (((char *) temp_v1_24) + 0x10)) = (u32) ((*((u32 *) (((char *) temp_v1_24) + 0x10))) | temp_v0_15);
      break;

  }

}

