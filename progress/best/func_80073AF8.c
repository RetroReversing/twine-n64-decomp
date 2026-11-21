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
void *func_80073AF8(void *arg0, void *arg1, s32 *arg2, u16 arg3, u16 arg4, u8 arg5, s32 arg6, u8 arg7, u8 arg8, s32 arg9, s32 arg10)
{
  s32 sp10[64];
  void *sp114;
  u16 sp11E;
  u16 sp126;
  u8 sp12F;
  u8 sp137;
  void *sp13C;
  u16 sp14E;
  s32 *temp_s6;
  union 
  {
    s32 *pointer;
    s32 value;
  } __repair_phase_storage;
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
  __repair_phase_storage.pointer = arg2;
  var_s5 = 0;
  sp114 = arg1;
  sp11E = arg3;
  sp137 = arg7;
  if (__repair_phase_storage.pointer == NULL)
  {
    __repair_phase_storage.pointer = D_800C7EE0;
  }
  sp13C = sp114;
  if (gBorderSkipActive != 0)
  {
    temp_v0 = *((s16 *) (((char *) sp114) + 0x140));
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
  func_800AB880(sp10, __repair_phase_storage.pointer);
  if (temp_s3 != NULL)
  {
    temp_s1 = *((void **) (((char *) temp_s3) + 0x6C));
    temp_v0_2 = strlen(sp10);
    *((s32 *) (((char *) temp_s1) + 0x20)) = (s32) gTrackMarkerSerial;
    *((s8 *) (((char *) temp_s1) + 0x135)) = 1;
    *((s8 *) (((char *) temp_s1) + 0x136)) = 0;
    *((u8 *) (((char *) temp_s1) + 0x33)) = (u8) ((u16) (*((s16 *) (((char *) sp114) + 0x140))));
    temp_v1 = var_s7 & 0xFF;
    *((s16 *) (((char *) temp_s3) + 0x7C)) = 0;
    *((u8 *) (((char *) temp_s1) + 0x35)) = var_s7;
    sp14E = temp_v0_2;
    switch (temp_v1)
    {
      case 5:
        temp_v0_3 = (*((u8 *) (((char *) temp_s1) + 0x33))) * 0x1C;
        var_s7 = 3;
        if ((*((s32 *) (((char *) (&D_8010D38C)) + temp_v0_3))) != (*((s32 *) (((char *) (&D_8010D2CC)) + temp_v0_3))))
      {
        *((s32 *) (((char *) temp_s3) + 0x60)) = (s32) ((*((s32 *) (((char *) temp_s3) + 0x60))) | 1);
        return NULL;
      }

      case 3:
        *((s8 *) (((char *) temp_s1) + 0x135)) = 0;
        var_fp = 0x96;
        if (((s8) sp12F) == 0)
      {
        *((s8 *) (((char *) temp_s1) + 0x136)) = 1;
      }
        var_s4 = 0xA0;
        var_s2 = 0x24;
        if (((s8) sp12F) != 0)
      {
        var_s2 = 0x30;
      }
        goto block_50;

      case 2:

      case 4:
        *((s8 *) (((char *) temp_s1) + 0x135)) = 0;
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
            *((s8 *) (((char *) temp_s1) + 0x135)) = 0;
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
        *((s8 *) (((char *) temp_s1) + 0x135)) = 0;

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
        *((s8 *) (((char *) temp_s1) + 0x135)) = 0;
        __repair_phase_storage.value = 0xA0;
        var_a0 = 0x78;
        if (gBorderSkipActive != 0)
      {
        if (gVisibleSaveSlotCount != 2)
        {
          if (gVisibleSaveSlotCount >= 2)
          {
            if (5 > gVisibleSaveSlotCount)
            {
              __repair_phase_storage.value = 0x50;
              var_a0 = 0x3C;
            }
          }
        }
        else
          if (gBorderFlipFlag == 1)
        {
          __repair_phase_storage.value = 0x50;
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
          func_800AB9B0(sp10, __repair_phase_storage.value);
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
          var_s4 = __repair_phase_storage.value & 0xFFFF;
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
      *((f32 *) (((char *) temp_s1) + 0x28)) = temp_fv0;
      if (temp_fv0 < 4.0f)
      {
        *((f32 *) (((char *) temp_s1) + 0x28)) = 4.0f;
      }
    }
    else
    {
      *((f32 *) (((char *) temp_s1) + 0xC)) = 65536.0f;
    }
    *((s32 *) (((char *) temp_s1) + 0x1C)) = 0;
    ((__repair_field_24 *) temp_s1)->value = arg6;
    temp_s6 = temp_s1 + 0x36;
    *((u8 *) (((char *) temp_s1) + 0x32)) = sp137;
    *((u8 *) (((char *) temp_s1) + 0x34)) = var_s7;
    *((s32 *) (((char *) temp_s1) + 0x2C)) = arg9;
    func_800AB880(temp_s6, sp10);
    temp_v0_4 = func_80015F0C();
    if (temp_v0_4 != NULL)
    {
      {
        long long phantom_wide = arg3;
      }
      *((s32 **) (((char *) temp_v0_4) + 0x18)) = temp_s6;
      *((u16 *) (((char *) temp_v0_4) + 0x1C)) = sp14E;
      *((s16 *) (((char *) temp_v0_4) + 0x20)) = var_s4;
      *((s16 *) (((char *) temp_v0_4) + 0x22)) = var_s2;
      *((s32 *) (((char *) temp_v0_4) + 0x10)) = 0;
      *((s32 *) (((char *) temp_v0_4) + 0x14)) = 0;
      *((s16 *) (((char *) temp_v0_4) + 0x1E)) = var_s5;
      func_800165E0(temp_v0_4, sp114);
      var_fv1 = (f64) var_fp;
      *((s16 *) (((char *) temp_s3) + 0x78)) = 0x19;
      *((void **) (((char *) temp_s1) + 4)) = temp_v0_4;
      *((s16 *) (((char *) temp_s1) + 0x30)) = (s16) var_fp;
      if (var_fp < 0)
      {
        var_fv1 += D_800D4860;
      }
      *((f32 *) (((char *) temp_s1) + 0x14)) = (f32) (4096.0f / ((f32) var_fv1));
    }
    else
    {
      *((s32 *) (((char *) temp_s3) + 0x60)) = (s32) ((*((s32 *) (((char *) temp_s3) + 0x60))) | 1);
    }
    if (((s16) sp11E) != (-1))
    {
      *((s32 *) (((char *) temp_s1) + 0)) = (s32) (*((s32 *) (((char *) sp13C) + 0x138)));
      do
      {
        effectSetAnimFrame(temp_s3, (s16) sp11E, (s16) sp126);
      }
      while (0);
      scale = ((f64) (0.0625f / (*((f32 *) (((char *) temp_s3) + 0x64))))) * D_800D4868;
      ((__repair_field_24 *) temp_s3)->value = 0;
      *((s32 *) (((char *) temp_s3) + 0x3C)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x28)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x40)) = 0;
      *((s16 *) (((char *) temp_s3) + 0x7A)) = 0;
      *((s32 *) (((char *) temp_s3) + 0x20)) = 0;
      *((f32 *) (((char *) temp_s3) + 0x2C)) = 0.5f;
      *((f32 *) (((char *) temp_s3) + 0x44)) = -2048.0f;
      *((s32 *) (((char *) temp_s3) + 0x58)) = (s32) ((*((s32 *) (((char *) temp_s3) + 0x58))) | 0x1000);
      *((f32 *) (((char *) temp_s3) + 0x54)) = (f32) scale;
    }
    else
    {
      *((s32 *) (((char *) temp_s1) + 0)) = 0;
    }
    *((s32 *) (((char *) temp_s1) + 0x18)) = D_8010D2C0[*((u8 *) (((char *) temp_s1) + 0x33))][*((u8 *) (((char *) temp_s1) + 0x34))];
    if (sp12F == 0)
    {
      return temp_s3;
    }
    {
      *((s32 *) (((char *) temp_s1) + 0x1C)) = (s32) ((*((s32 *) (((char *) temp_s1) + 0x1C))) | 1);
      temp_v1_2 = &D_8010D2C0[*((u8 *) (((char *) temp_s1) + 0x33))][*((u8 *) (((char *) temp_s1) + 0x34))];
      *temp_v1_2 += 1;
    }
    return temp_s3;
  }
  else
  {
    return temp_s3;
  }
}

