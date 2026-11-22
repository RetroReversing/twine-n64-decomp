typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} CaptionPosition;
s32 effectSetAnimFrame(void *, s16, s16);
void *func_80015F0C();
s32 func_800165E0(void *, void *);
f32 func_80045590(void *, s32);
s32 func_800AB880(s32 *, s32 *);
s32 func_800AB9B0(s32 *, s32);
void *spawnEffectObject(s32, s32, s32);
u16 strlen(s32 *);
extern s32 D_800C7EDC;
extern f64 D_800D4860;
extern f64 D_800D4868;
extern void *D_8010969C;
extern s32 D_8010D2C0[][7];
extern s32 D_8010D2CC;
extern s32 D_8010D38C;
extern u8 gBorderFlipFlag;
extern s32 gBorderSkipActive;
extern s32 gTrackMarkerSerial;
extern s32 gVisibleSaveSlotCount;
extern s32 sBonusObjectTable;
extern void *sTrackMarkerTable[];
extern s32 D_800C7EE0[];
typedef struct 
{
  unsigned char pad[36];
  int value;
} __repair_field_24;
typedef struct 
{
  f32 v;
} Field_f32;
typedef struct 
{
  s16 v;
} Field_s16;
typedef struct 
{
  s32 v;
} Field_s32;
typedef struct 
{
  s8 v;
} Field_s8;
typedef struct 
{
  u16 v;
} Field_u16;
typedef struct 
{
  u8 v;
} Field_u8;
inline static u8 inline_fn(void *arg0)
{
  return ((Field_u8 *) (((char *) arg0) + 0x34))->v;
}

void *func_80073AF8(void *arg0, void *arg1, s32 *arg2, u16 arg3, u16 arg4, u8 arg5, s32 arg6, u8 arg7, u8 arg8, s32 arg9, s32 arg10)
{
  s32 sp10[64];
  void *sp114;
  u16 sp11E;
  u16 sp126;
  u8 sp12F;
  u8 sp137;
  void *sp13C;
  s32 *temp_s6;
  s32 *pstr;
  s32 var_a1;
  s32 sflag;
  f32 temp_fv0;
  f64 var_fv1;
  register s16 temp_v0;
  s16 var_s2;
  unsigned long var_s4;
  s16 var_s5;
  s32 *temp_v1_2;
  s32 temp_v0_3;
  s32 var_a0;
  s32 var_fp;
  u16 temp_v0_2;
  u32 temp_v1;
  u8 var_s7;
  void *temp_s1;
  void *temp_s3;
  void *temp_v0_4;
  f64 scale;
  var_s7 = arg8;
  sp126 = arg4;
  sp12F = arg5;
  pstr = arg2;
  var_s5 = 0;
  sp114 = arg1;
  sp11E = arg3;
  sp137 = arg7;
  if (pstr == NULL)
  {
    pstr = D_800C7EE0;
  }
  sp13C = sp114;
  if (gBorderSkipActive != 0)
  {
    temp_v0 = ((Field_s16 *) (((char *) sp114) + 0x140))->v;
    if (gVisibleSaveSlotCount > temp_v0)
    {
      goto block_10;
    }
    if (((u16) (temp_v0 - 4)) >= 2U)
    {
      return NULL;
    }
    goto block_10;
  }
  if (sTrackMarkerTable[0] == sp13C)
  {
    sp114 = D_8010969C;
  }
  block_10:
  temp_s3 = spawnEffectObject(0x138, 0, 0);

  var_fp = 0;
  func_800AB880(sp10, pstr);
  if (temp_s3 != NULL)
  {
    u16 sp14E;
    temp_s1 = *((void **) (((char *) temp_s3) + 0x6C));
    temp_v0_2 = strlen(sp10);
    ((Field_s32 *) (((char *) temp_s1) + 0x20))->v = (s32) gTrackMarkerSerial;
    ((Field_s8 *) (((char *) temp_s1) + 0x135))->v = 1;
    {
      u16 caption = *((u16 *) (((char *) sp114) + 0x140));
      ((Field_s8 *) (((char *) temp_s1) + 0x136))->v = 0;
      ((Field_u8 *) (((char *) temp_s1) + 0x33))->v = caption;
    }
    temp_v1 = var_s7 & 0xFF;
    ((Field_s16 *) (((char *) temp_s3) + 0x7C))->v = 0;
    ((Field_u8 *) (((char *) temp_s1) + 0x35))->v = var_s7;
    sp14E = temp_v0_2;
    switch (temp_v1)
    {
      case 5:
        temp_v0_3 = ((Field_u8 *) (((char *) temp_s1) + 0x33))->v * 0x1C;
        var_s7 = 3;
        if ((*((s32 *) (((char *) (&D_8010D38C)) + temp_v0_3))) != (*((s32 *) (((char *) (&D_8010D2CC)) + temp_v0_3))))
      {
        ((Field_s32 *) (((char *) temp_s3) + 0x60))->v = (s32) (((Field_s32 *) (((char *) temp_s3) + 0x60))->v | 1);
        return NULL;
      }

      case 3:
        ((Field_s8 *) (((char *) temp_s1) + 0x135))->v = 0;
        var_fp = 0x96;
        sflag = (s8) sp12F;
        if (sflag == 0)
      {
        ((Field_s8 *) (((char *) temp_s1) + 0x136))->v = 1;
      }
        var_s4 = 0xA0;
        var_s2 = 0x24;
        if (sflag != 0)
      {
        var_s2 = 0x30;
      }
        goto block_50;

      case 2:

      case 4:
        ((Field_s8 *) (((char *) temp_s1) + 0x135))->v = 0;
        if ((var_s7 & 0xFF) == 4)
      {
        var_s4 = 0x20;
        var_s2 = 0x8A;
        var_s5 = 0x20;
        if (D_800C7EDC == 0x3FA)
        {
          var_s4 = 0xA0;
          var_s2 = 0x30;
          var_s5 = 0x21;
        }
        var_s7 = 2;
      }
      else
      {
        var_s4 = 0xA0;
        var_s2 = 0x9C;
        var_s5 = 0x21;
      }
        if (sp12F != 0)
      {
        var_s2 += 0xC;
      }
        goto block_51;

      case 6:
        var_s7 = 0;
        var_s4 = 0xA0;
        if (gVisibleSaveSlotCount != 1)
      {
        var_s2 = 0x74;
        if (gVisibleSaveSlotCount == 2)
        {
          if (gBorderFlipFlag != 1)
          {
            goto block_34;
          }
          else
          {
            goto block_33;
          }
        }
        else
        {
          goto block_34;
        }
      }
      else
      {
        block_33:
        var_s2 = 0x3A;

        block_34:
        ((Field_s8 *) (((char *) temp_s1) + 0x135))->v = 0;

      }
        goto block_50;

      case 1:
        var_s4 = 0x24;
        var_s2 = 0x7C;
        if (sp12F != 0)
      {
        var_s2 = 0x88;
      }
        goto block_51;

      case 0:

      default:
        var_fp = 0x1E;
        ((Field_s8 *) (((char *) temp_s1) + 0x135))->v = 0;
        var_a1 = 0xA0;
        var_a0 = 0x78;
        if (gBorderSkipActive != 0)
      {
        if (gVisibleSaveSlotCount != 2)
        {
          if (gVisibleSaveSlotCount >= 2)
          {
            if (5 > gVisibleSaveSlotCount)
            {
              var_a1 = 0x50;
              var_a0 = 0x3C;
            }
          }
        }
        else
          if (gBorderFlipFlag == 1)
        {
          var_a1 = 0x50;
        }
        else
        {
          var_a0 = 0x3C;
        }
        var_s4 = 0x16;
        if (gBorderSkipActive != 0)
        {
          var_s2 = (var_a0 * 2) - 0x18;
          var_s5 = 0x840;
          func_800AB9B0(sp10, var_a1);
        }
        else
        {
          goto block_47;
        }
      }
      else
      {
        block_47:
        var_s5 = 0x20;

        if (((s16) sp11E) == (-1))
        {
          var_s2 = (var_a0 * 2) - 0x20;
          var_s4 = 0x20;
        }
        else
        {
          var_s2 = var_a0 - 0x20;
          var_s4 = var_a1 & 0xFFFF;
          goto block_50;
        }
      }
        goto block_51;

    }

    block_50:
    var_s5 = 0x21;

    block_51:
    if (arg10 > 0)
    {
      var_fp = arg10;
    }

    if (arg0 != NULL)
    {
      *((CaptionPosition *) (((char *) temp_s1) + 8)) = *((CaptionPosition *) arg0);
      temp_fv0 = func_80045590(temp_s1 + 8, sBonusObjectTable + 0x24);
      ((Field_f32 *) (((char *) temp_s1) + 0x28))->v = temp_fv0;
      if (temp_fv0 < 4.0f)
      {
        ((Field_f32 *) (((char *) temp_s1) + 0x28))->v = 4.0f;
      }
    }
    else
    {
      ((Field_f32 *) (((char *) temp_s1) + 0xC))->v = 65536.0f;
    }
    ((Field_s32 *) (((char *) temp_s1) + 0x1C))->v = 0;
    ((__repair_field_24 *) temp_s1)->value = arg6;
    temp_s6 = temp_s1 + 0x36;
    ((Field_u8 *) (((char *) temp_s1) + 0x32))->v = sp137;
    ((Field_u8 *) (((char *) temp_s1) + 0x34))->v = var_s7;
    ((Field_s32 *) (((char *) temp_s1) + 0x2C))->v = arg9;
    func_800AB880(temp_s1 + 0x36, sp10);
    temp_v0_4 = func_80015F0C();
    if (temp_v0_4 != NULL)
    {
      {
        long long phantom_wide = arg3;
      }
      *((s32 **) (((char *) temp_v0_4) + 0x18)) = temp_s6;
      ((Field_u16 *) (((char *) temp_v0_4) + 0x1C))->v = sp14E;
      ((Field_s16 *) (((char *) temp_v0_4) + 0x20))->v = var_s4;
      ((Field_s16 *) (((char *) temp_v0_4) + 0x22))->v = var_s2;
      ((Field_s32 *) (((char *) temp_v0_4) + 0x10))->v = 0;
      ((Field_s32 *) (((char *) temp_v0_4) + 0x14))->v = 0;
      ((Field_s16 *) (((char *) temp_v0_4) + 0x1E))->v = var_s5;
      func_800165E0(temp_v0_4, sp114);
      var_fv1 = (f64) var_fp;
      ((Field_s16 *) (((char *) temp_s3) + 0x78))->v = 0x19;
      *((void **) (((char *) temp_s1) + 4)) = temp_v0_4;
      ((Field_s16 *) (((char *) temp_s1) + 0x30))->v = (s16) var_fp;
      if (var_fp < 0)
      {
        var_fv1 += D_800D4860;
      }
      ((Field_f32 *) (((char *) temp_s1) + 0x14))->v = (f32) (4096.0f / ((f32) var_fv1));
    }
    else
    {
      ((Field_s32 *) (((char *) temp_s3) + 0x60))->v = (s32) (((Field_s32 *) (((char *) temp_s3) + 0x60))->v | 1);
    }
    if (((s16) sp11E) != (-1))
    {
      ((Field_s32 *) (((char *) temp_s1) + 0))->v = (s32) ((Field_s32 *) (((char *) sp13C) + 0x138))->v;
      {
        effectSetAnimFrame(temp_s3, (s16) sp11E, (s16) sp126);
      }
      scale = ((f64) (0.0625f / ((Field_f32 *) (((char *) temp_s3) + 0x64))->v)) * D_800D4868;
      ((__repair_field_24 *) temp_s3)->value = 0;
      ((Field_s32 *) (((char *) temp_s3) + 0x28))->v = 0;
      ((Field_s32 *) (((char *) temp_s3) + 0x3C))->v = 0;
      ((Field_s32 *) (((char *) temp_s3) + 0x40))->v = 0;
      ((Field_s16 *) (((char *) temp_s3) + 0x7A))->v = 0;
      ((Field_s32 *) (((char *) temp_s3) + 0x20))->v = 0;
      ((Field_f32 *) (((char *) temp_s3) + 0x2C))->v = 0.5f;
      ((Field_f32 *) (((char *) temp_s3) + 0x44))->v = -2048.0f;
      ((Field_s32 *) (((char *) temp_s3) + 0x58))->v = (s32) (((Field_s32 *) (((char *) temp_s3) + 0x58))->v | 0x1000);
      ((Field_f32 *) (((char *) temp_s3) + 0x54))->v = (f32) scale;
    }
    else
    {
      ((Field_s32 *) (((char *) temp_s1) + 0))->v = 0;
    }
    ((Field_s32 *) (((char *) temp_s1) + 0x18))->v = D_8010D2C0[((Field_u8 *) (((char *) temp_s1) + 0x33))->v][((Field_u8 *) (((char *) temp_s1) + 0x34))->v];
    if (sp12F != 0)
    {
      ((Field_s32 *) (((char *) temp_s1) + 0x1C))->v = (s32) (((Field_s32 *) (((char *) temp_s1) + 0x1C))->v | 1);
      D_8010D2C0[((Field_u8 *) (((char *) temp_s1) + 0x33))->v][((Field_u8 *) (((char *) temp_s1) + 0x34))->v] += 1;
    }
  }
  return temp_s3;
}

