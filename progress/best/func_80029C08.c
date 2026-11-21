void *findEntryById(s32, s32);
void *func_80026314(s32, s32, s32);
s32 func_8002AAD4(void *, void *);
s32 func_8002AAF4(void *, void *);
s32 func_8002AB14(void *, void *);
s32 func_8002AB34(void *, void *);
s32 func_8002AB54(void *);
s32 func_8002AB6C(void *);
s32 menuItemIsActive(s32);
s32 requestSound(s32);
extern s32 D_80000001;
extern s32 D_800BD660;
extern f64 D_800D2CD0;
extern f64 D_800D2CD8;
extern void *gSaveMenuState;
extern s32 sSaveMenuColorActive;
extern s32 sSaveMenuColorIdle;
s32 func_80029C08(void *arg0, s32 arg1, s32 arg2)
{
  s32 var_a0;
  s32 var_a0_2;
  s32 var_a0_3;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f64 var_ft0;
  f64 var_ft0_2;
  s32 *var_a0_4;
  void *inactiveState;
  void *inactiveEntry;
  s32 colorMask;
  s32 temp_s0;
  s32 temp_v0;
  s32 temp_v0_2;
  s32 temp_v1_3;
  s32 var_a1;
  unsigned short var_s0;
  s32 var_s1;
  s32 var_v0_2;
  s32 var_v1;
  u8 temp_s6;
  u8 temp_v1;
  u8 var_s1_2;
  u8 var_v0_4;
  void *temp_a0;
  void *temp_a1;
  void *temp_a1_2;
  void *temp_s3;
  void *temp_s3_2;
  void *temp_v1_2;
  void *var_s3;
  void *var_s4;
  void *var_v0;
  if (arg0 == NULL)
  {
    goto block_12;
  }
  {
    temp_s6 = *((u8 *) (((char *) arg0) + 0x18));
    if (!(arg2 & 0xFF))
    {
      var_s4 = findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0xAC);
      var_s3 = findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0xAB);
      var_v0 = findEntryById(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 4);
      var_a1 = arg1 & 0xFF;
    }
    else
    {
      var_s4 = func_80026314(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0xAC, 2);
      var_s3 = func_80026314(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 0xAB, 2);
      var_v0 = func_80026314(*((s32 *) (((char *) gSaveMenuState) + 0x10)), 4, 2);
      var_a1 = arg1 & 0xFF;
    }
    switch (var_a1)
    {
      case 0:
        var_s1 = menuItemIsActive(0x25) & 0xFF;
        var_a0 = 0x26;
        goto block_9;

      case 1:
        var_s1 = menuItemIsActive(0x1E) & 0xFF;
        var_a0 = 0x1F;
        block_9:
      var_s0 = menuItemIsActive(var_a0) & 0xFF;

        break;

      default:
        var_s0 = menuItemIsActive(0x25);
        var_s0 |= menuItemIsActive(0x1E);
        var_s1 = var_s0 & 0xFF;
        var_s0 = menuItemIsActive(0x26);
        var_s0 |= menuItemIsActive(0x1F);
        var_s0 &= 0xFF;
        break;

    }

    if ((var_s3 != NULL) & (var_s4 != NULL))
    {
      goto active_check;
    }
    block_12:
    return 0;

    active_check:
    if ((var_s1 != 0) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
    {
      if (func_8002AB54(arg0) & 0xFF)
      {
        var_a0_2 = 0xEC;
      }
      else
      {
        var_a0_2 = 0xEB;
      }
      requestSound(var_a0_2);
      temp_a1 = *((void **) (((char *) var_s3) + 8));
      *((s32 *) (((char *) temp_a1) + 0x10)) = (s32) ((sSaveMenuColorActive & (~0xFF)) | (*((u8 *) (((char *) gSaveMenuState) + 0x30))));
      if ((*((u8 *) (((char *) arg0) + 0x1E))) == 0)
      {
        func_8002AAF4(arg0, temp_a1);
      }
      else
      {
        func_8002AB34(arg0, temp_a1);
      }
    }
    else
      if ((var_s0 != 0) && ((*((u8 *) (((char *) gSaveMenuState) + 0x29))) != 0))
    {
      if (func_8002AB6C(arg0) & 0xFF)
      {
        var_a0_3 = 0xEC;
      }
      else
      {
        var_a0_3 = 0xEB;
      }
      if (gSaveMenuState)
      {
        requestSound(var_a0_3);
        temp_a1_2 = *((void **) (((char *) var_s4) + 8));
        *((s32 *) (((char *) temp_a1_2) + 0x10)) = (s32) ((sSaveMenuColorActive & (~0xFF)) | (*((u8 *) (((char *) gSaveMenuState) + 0x30))));
      }
      else
      {
        requestSound(var_a0_3);
        temp_a1_2 = *((void **) (((char *) var_s4) + 8));
        *((s32 *) (((char *) temp_a1_2) + 0x10)) = (s32) ((sSaveMenuColorActive & (~0xFF)) | (*((u8 *) (((char *) gSaveMenuState) + 0x30))));
      }
      if ((*((u8 *) (((char *) arg0) + 0x1E))) == 0)
      {
        func_8002AAD4(arg0, temp_a1_2);
      }
      else
      {
        func_8002AB14(arg0, temp_a1_2);
      }
    }
    else
    {
      if ((*((s32 *) (((char *) var_s4) + 0x20))) != 0x390024)
      {
        inactiveEntry = *((void **) (((char *) var_s3) + 8));
        inactiveState = gSaveMenuState;
        var_a0_4 = (s32 *) (((char *) (&D_800BD660)) - 0x14);
      }
      else
      {
        inactiveEntry = *((void **) (((char *) var_s3) + 8));
        inactiveState = gSaveMenuState;
        var_a0_4 = &sSaveMenuColorIdle;
      }
      colorMask = -0x100;
      *((s32 *) (((char *) inactiveEntry) + 0x10)) = ((*var_a0_4) & colorMask) | (*((u8 *) (((char *) inactiveState) + 0x30)));
      *((s32 *) (((char *) (*((void **) (((char *) var_s4) + 8)))) + 0x10)) = (s32) (((*var_a0_4) & colorMask) | (*((u8 *) (((char *) inactiveState) + 0x30))));
      temp_v1 = *((u8 *) (((char *) gSaveMenuState) + 0x30));
      var_s1_2 = 0xFF;
      if ((temp_v1 + 1) <= 0xFFU)
      {
        var_s1_2 = temp_v1;
      }
      temp_s3 = *((void **) (((char *) var_s3) + 8));
      colorMask = *((s32 *) (((char *) temp_s3) + 0x10)); temp_s0 = colorMask & (~0xFF);
      if (func_8002AB54(arg0) & 0xFF)
      {
        var_v0_2 = var_s1_2 | temp_s0;
      }
      else
      {
        var_v0_2 = temp_s0 | (*((u8 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x13)));
      }
      *((s32 *) (((char *) temp_s3) + 0x10)) = var_v0_2;
      temp_s3_2 = *((void **) (((char *) var_s4) + 8));
      temp_s0 = (*((s32 *) (((char *) temp_s3_2) + 0x10))) & (~0xFF);
      *((s32 *) (((char *) temp_s3_2) + 0x10)) = (func_8002AB6C(arg0) & 0xFF) ? ((unsigned long long) (var_s1_2 | temp_s0)) : ((unsigned long long) (temp_s0 | (*((u8 *) (((char *) (*((void **) (((char *) gSaveMenuState) + 0x1C)))) + 0x13)))));
    }

    if (var_v0 != NULL)
    {
      temp_v1_2 = *((void **) (((char *) var_v0) + 8));
      if (temp_v1_2 != NULL)
      {
        temp_v0 = *((s32 *) (((char *) var_v0) + 0x14));
        var_ft0 = (f64) temp_v0;
        if (temp_v0 < 0)
        {
          var_ft0 += D_800D2CD0;
        }
        temp_fv1 = (*((f32 *) (((char *) arg0) + 0xC))) * ((f32) var_ft0);
        if (!(temp_fv1 >= 2147483648.0f))
        {
          var_v0_4 = ((s32) temp_fv1) + 1;
        }
        else
        {
          var_v0_4 = ((s32) (temp_fv1 - 2147483648.0f)) | ((s32) (&D_80000001));
        }
        *((u8 *) (((char *) temp_v1_2) + 0x29)) = var_v0_4;
        temp_a0 = *((void **) (((char *) var_v0) + 8));
        temp_v1_3 = *((s32 *) (((char *) var_v0) + 0x14));
        if (((u32) temp_v1_3) < ((u8) (*((u8 *) (((char *) temp_a0) + 0x29)))))
        {
          *((u8 *) (((char *) temp_a0) + 0x29)) = (u8) temp_v1_3;
        }
        temp_v0_2 = *((s32 *) (((char *) var_v0) + 0x14));
        temp_a0 = *((void * volatile *) (((char *) var_v0) + 8));
        var_ft0_2 = (f64) temp_v0_2;
        if (temp_v0_2 < 0)
        {
          var_ft0_2 += D_800D2CD8;
        }
        temp_fv1_2 = (*((f32 *) (((char *) arg0) + 0x10))) * ((f32) var_ft0_2);
        if (!(temp_fv1_2 >= 2147483648.0f))
        {
          var_v1 = (s32) temp_fv1_2;
        }
        else
        {
          var_v1 = ((s32) (temp_fv1_2 - 2147483648.0f)) | 0x80000000;
        }
        *((s16 *) (((char *) temp_a0) + 0x22)) = (s16) (var_v1 + (*((u16 *) (((char *) var_v0) + 0x1A))));
      }
    }
    return temp_s6 != (*((u8 *) (((char *) arg0) + 0x18)));
  }
}

