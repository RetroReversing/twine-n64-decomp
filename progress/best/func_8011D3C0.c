s32 func_800162BC(s32);
s32 func_800448A4(void *, s32, s32);
s32 func_80070ECC(s32, s32, s32, s32);
s32 *func_80087100(s32);
s32 func_8011CFB0();
void *func_8011E304(s32, s32, void *, s8);
s32 sprintf(void *, s32 *);
extern s32 D_800BD644;
extern s32 D_800BD654;
extern s32 D_800BD66C;
extern s32 D_800BD678;
typedef struct 
{
  u16 f0;
  u8 pad[22];
} Slot_801001A2;
extern Slot_801001A2 D_801001A2[];
extern u8 D_801002A1;
extern s32 D_801002B4;
extern s32 D_801002C0;
extern u8 D_801002D4;
extern s32 D_80109688;
extern u8 D_8010A4FD;
extern s32 D_8010A500;
extern s32 D_8011F018;
extern u16 D_8011F0EC;
extern s32 D_8011F0F0;
extern s32 D_8011F0F8;
extern u8 D_8011F2B8[];
extern u8 D_8011F2E8[];
extern u8 D_8011F378[];
extern s32 D_8011F3D0[];
extern s32 D_8011F3E0;
extern s32 D_8011F3E8;
void func_8011D3C0(void)
{
  u8 *__base_D_8011F2E8;
  char *__repair_addr;
  s32 var_a2;
  union 
  {
    s32 *pointer;
    s32 value;
  } __repair_phase_storage;
  int sp34;
  s32 *sp3C;
  unsigned int sp44;
  f32 temp_fv1;
  f32 temp_fv1_2;
  f32 temp_fv1_3;
  f32 temp_fv1_4;
  f32 temp_fv1_5;
  f32 var_fs0;
  f32 var_fs2;
  f32 var_fv1;
  f32 var_fv1_2;
  s32 var_s3;
  s16 var_v0_3;
  s32 temp_s0;
  s32 temp_s0_4;
  u16 sp26;
  register s32 temp_v1;
  s32 var_a0_2;
  u32 var_a0_3;
  int var_a1;
  unsigned int var_a1_2;
  u16 sp1E;
  s32 var_a2_3;
  unsigned var_a2_2;
  s32 var_a3;
  s32 var_fp;
  s32 var_s1;
  void *temp_v0;
  int var_v0_2;
  s32 var_v0_4;
  s8 temp_s1_2;
  s8 temp_s3;
  register u32 var_a0;
  u8 temp_s6;
  register void *temp_s0_2;
  void *temp_s0_3;
  void *temp_s0_5;
  void *temp_s1;
  void *temp_s5;
  s32 var_v0;
  register void *temp_v0_4;
  var_fs2 = 160.0f;
  var_fs0 = 120.0f;
  if (D_801002C0 != 2)
  {
    if (2 <= D_801002C0)
    {
      if (D_801002C0 < 5)
      {
        var_fs0 = 60.0f;
        var_fs2 = 80.0f;
      }
    }
  }
  else
    if (D_8010A4FD == 1)
  {
    var_fs2 = 80.0f;
  }
  else
  {
    var_fs0 = 60.0f;
  }
  var_fp = 0;
  func_8011CFB0();
  var_a0 = 0 & 0xFFFF;
  if (D_801002C0 > 0)
  {
    do
    {
      temp_v1 = var_a0 * 4;
      if ((*((s32 *) (((char *) (&D_80109688)) + temp_v1))) != 0)
      {
        __repair_addr = (char *) (((char *) (&D_8010A500)) + temp_v1);
        temp_s5 = *((void **) (((char *) (*((s32 *) __repair_addr))) + 0x6C));
        if (D_801002C0 != 2)
        {
          if ((D_801002C0 < 3) || (D_801002C0 >= 5))
          {
            sp26 = 4;
            sp1E = -4U;
          }
          else
          {
            temp_v1 = (-(((var_a0 == 0) | (var_a0 == 2)) == 0)) & (~3); sp1E = temp_v1 | 8;
            var_v0 = -(var_a0 >= 2U);
            goto block_21;
          }
        }
        else
          if (D_8010A4FD != 0)
        {
          sp1E = ((-(var_a0 != 0)) & (~3)) | 8;
          sp26 = 4;
        }
        else
        {
          var_v0 = -(var_a0 != 0);
          sp1E = -4U;
          block_21:
          sp26 = (var_v0 & (~3)) | 4;

        }
        var_s3 = 0;
        __repair_phase_storage.pointer = temp_s5 + 0x418;
        var_s1 = temp_s5 + 0x438;
        sp3C = temp_s5 + 0x41C;
        var_v0_2 = 0 << 0x10;
        var_a0 = temp_s5 + 0x448;
        do
        {
          temp_s0 = var_v0_2 >> 0x10;
          temp_s1 = (temp_s0 * 4) + temp_s5;
          *((void **) (((char *) temp_s1) + 0x418)) = NULL;
          if ((D_801002D4 == 0) || ((var_v0_3 = var_s3 + 1, temp_s0 != 1)))
          {
            temp_v0 = func_800162BC(*((s8 *) (((char *) temp_s5) + 0x182)));
            *((void **) (((char *) temp_s1) + 0x418)) = temp_v0;
            if (temp_v0 != NULL)
            {
              if (((unsigned) temp_s0) != 1)
              {
                if (temp_s0 >= 2)
                {
                  if (temp_s0 == 2)
                  {
                    temp_fv1 = ((2.0f * var_fs2) - 16.0f) + ((f32) ((s16) sp1E));
                    var_a2 = (u32) temp_fv1;
                    var_fv1 = 2.0f * var_fs0;
                    temp_fv1_2 = var_fv1 - 24.0f;
                    var_a2_2 = var_a2 & 0xFFFF;
                    var_a3 = (u32) temp_fv1_2;
                    var_a0_2 = *((s32 *) (((char *) temp_s5) + 0x420));
                    var_a1 = temp_s5 + 0x458;
                    goto block_62;
                  }
                  var_v0_3 = var_s3 + 1;
                }
                else
                {
                  if (!temp_s0)
                  {
                    temp_fv1_3 = ((2.0f * var_fs2) - 16.0f) + ((f32) ((s16) sp1E));
                    var_a2_3 = (u32) temp_fv1_3;
                    var_fv1_2 = 2.0f * var_fs0;
                    var_fv1_2 = var_fv1_2 - 34.0f;
                    var_a2_2 = var_a2_3 & 0xFFFF;
                    var_a3 = (u32) var_fv1_2;
                    var_a1 = var_s1;
                    var_a0_2 = *__repair_phase_storage.pointer;
                    goto block_62;
                  }
                  if (1)
                  {
                    var_v0_3 = var_s3 + 1;
                  }
                }
              }
              else
              {
                temp_fv1_5 = (2.0f * var_fs0) - 34.0f;
                var_a3 = (u32) temp_fv1_5;
                var_a1 = var_a0;
                var_a0_2 = *sp3C;
                var_a2_2 = 0x16;
                block_62:
                func_80070ECC(var_a0_2, var_a1, var_a2_2, var_a3 & 0xFFFF);

                goto block_63;
              }
            }
            else
            {
              block_63:
              var_v0_3 = var_s3 + 1;

            }
          }
          var_s3 = var_v0_3;
          var_v0_2 = var_s3 << 0x10;
        }
        while (var_v0_3 < 3);
        temp_s0 = (s8) (var_fp & 0xFFFF);
        temp_s0_2 = (temp_s0 * 0xC) + D_8011F378;
        temp_v0 = func_8011E304(0x18, 0x1E, temp_s0_2, temp_s0);
        *((s16 *) (((char *) temp_v0) + 0x1E)) = 0x20;
        sprintf(temp_s0_2, &D_8011F018);
        *((s16 *) (((char *) temp_v0) + 0x1C)) = 1;
        D_8011F3D0[(unsigned short) temp_s0] = temp_v0;
        var_a0_3 = (u16)(u32) var_fs2;
        if (!(var_fs0 >= 2.1474836e9f))
        {
          var_a1_2 = (s32) var_fs0;
          var_a1_2 = var_a1_2 & 0xFFFF;
        }
        else
        {
          var_a1_2 = (((s32) (var_fs0 - 2.1474836e9f)) | 0x80000000) & 0xFFFF;
        }
        temp_s3 = var_fp & 0xFFFF;
        __repair_phase_storage.value = temp_s3 * 2;
        temp_s0_3 = (temp_s3 * 0xC) + D_8011F2B8;
        temp_v0 = func_8011E304(var_a0_3 & 0xFFFF, var_a1_2, temp_s0_3, temp_s3);
        *((u16 *) (((char *) temp_v0) + 0x1E)) = (u16) ((*((u16 *) (((char *) temp_v0) + 0x1E))) | 0x20);
        sprintf(temp_s0_3, func_80087100(0x2E5));
        var_v0_2 = temp_s3 * 4;
        *((s16 *) (((char *) temp_v0) + 0x1C)) = 3;
        *((s32 *) (((char *) temp_v0) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v0) + 0x28))) & (~0xFC)) | 0x1C);
        *((s32 *) (((char *) (&D_8011F3E8)) + var_v0_2)) = temp_v0;
        *((s16 *) (((char *) (&D_8011F3E0)) + __repair_phase_storage.value)) = 0;
        temp_s6 = D_801001A2[temp_s3].f0;
        if (temp_s6 != 0)
        {
          temp_v0_4 = func_800162BC(temp_s3);
          if (temp_v0_4 != NULL)
          {
            func_800448A4(temp_v0_4, 0x13, 0x2A);
            *((s16 *) (((char *) temp_v0_4) + 0x1E)) = 2;
            *((s16 *) (((char *) temp_v0_4) + 0x22)) = (s16) (sp26 + 0xC);
            *((s32 *) (((char *) temp_v0_4) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v0_4) + 0x28))) & (~0xFC)) | 0x10);
            *((s16 *) (((char *) temp_v0_4) + 0x20)) = (s16) (D_8011F0EC + (sp1E + 0xFFC7));
            *((s32 *) (((char *) temp_v0_4) + 0x10)) = (s32) ((D_800BD66C & (~0xFF)) | 0x88);
            *((s16 *) (((char *) (&D_8011F0F0)) + __repair_phase_storage.value)) = sp1E + (D_8011F0EC + 0xFFDB);
            *((s16 *) (((char *) (&D_8011F0F8)) + __repair_phase_storage.value)) = sp26 + 0x20;
            __base_D_8011F2E8 = D_8011F2E8;
            *((s32 *) (((char *) __base_D_8011F2E8) + var_v0_2)) = temp_v0_4;
            if (D_801002B4 > 0)
            {
              var_s1 = 0;
              var_v0_4 = 0 & 0xFFFF;
              do
              {
                temp_s0_5 = *((void **) (((char *) (&D_8010A500)[var_v0_4]) + 0x6C));
                if (((temp_s3 != var_v0_4) && (temp_s6 != 5)) && ((D_801002A1 != 1) || (((temp_s6 != 2) || ((*((u8 *) (((char *) (*((void **) (((char *) temp_s5) + 0xB4)))) + 0x12))) == (*((u8 *) (((char *) (*((void **) (((char *) temp_s0_5) + 0xB4)))) + 0x12))))) && ((temp_s6 != 3) || ((*((u8 *) (((char *) (*((void **) (((char *) temp_s5) + 0xB4)))) + 0x12))) != (*((u8 *) (((char *) (*((void **) (((char *) temp_s0_5) + 0xB4)))) + 0x12))))))))
                {
                  temp_v0 = func_800162BC(var_fp & 0xFFFF);
                  do
                  {
                    if (temp_v0 != NULL)
                    {
                      if (D_801002A1)
                      {
                        if ((*((u8 *) (((char *) (*((void **) (((char *) temp_s0_5) + 0xB4)))) + 0x12))) == 0)
                        {
                          *((s32 *) (((char *) temp_v0) + 0x10)) = (s32) D_800BD678;
                        }
                        else
                        {
                          *((s32 *) (((char *) temp_v0) + 0x10)) = (s32) D_800BD654;
                        }
                      }
                      else
                      {
                        *((s32 *) (((char *) temp_v0) + 0x10)) = D_800BD644;
                      }
                      *((s32 *) (((char *) temp_v0) + 0x28)) = (s32) (((*((s32 *) (((char *) temp_v0) + 0x28))) & (~0xFC)) | 0xC);
                      func_800448A4(temp_v0, 0x17, 0x1B);
                      *(void **)(var_v0_2 + (((var_s1 & 0xFFFF) * 0x10) + (__base_D_8011F2E8 + 0x10))) = temp_v0;
                    }
                  }
                  while (0);
                }
                var_s1 += 1;
                var_v0_4 = var_s1 & 0xFFFF;
              }
              while ((var_s1 & 0xFFFF) < D_801002B4);
            }
          }
        }
      }
      var_fp += 1;
      var_a0 = var_fp & 0xFFFF;
    }
    while ((var_fp & 0xFFFF) < D_801002C0);
  }
}



