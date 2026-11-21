s32 func_800083DC(s32 *, f32, f32, f32, f32);
s32 IsSphereVisible(f32 *, s32, void *, void *);
s32 func_800158A4(void *, f32 *, s32, s32 *, s32, s32, s32, s32, s32);
s32 func_80032630(s32, void *);
s32 func_80034928(void *, s32);
f32 func_800357C8(f32);
s32 func_80039068();
s32 func_80043FA0(s32 *, void *);
s32 func_8004478C(s32, s32);
s32 vec3Add(f32 *, f32 *, f32 *);
s32 func_800452E0(f32 *, f32 *, f32 *);
f32 approxDistance(void *, void *);
f32 func_80046140(f32, f32);
s32 func_80047B14(f32 *, s32, f32 *);
s32 rotateVec3ByMat3(void *, f32 *);
s32 guMtxF2L(s32 *, s32);
s32 func_800A3840(s32 *, s32 *, s32 *);
s32 func_800A3940(s32 *, f32, f32, f32);
s32 guTranslateF(s32 *, f32, f32, f32);
extern s32 D_800B1CA8;
extern u32 sMatrixPoolLimit;
extern s32 D_800C0670;
extern s32 D_800C0698;
extern u8 D_800C06C4;
extern s32 D_800C06D0;
extern s32 D_800C06DC;
extern s32 D_800C06E8;
extern u8 D_800C2B40;
extern s32 D_801032A0;
extern void *gObjectListHead;
extern u32 sMatrixPoolUsed;
extern s32 gTrackMarkerDone;
extern s32 sParentMatrixF;
extern void *D_80109CB8;
extern s32 D_8010A4D8;
extern s32 D_8010A924;
extern s32 D_8010D538;
extern s32 gRenderMode;
extern s32 D_80112F90;
extern void *D_80115328;
extern void * volatile sRenderState;
inline static int inline_fn(int arg0)
{
  return D_8010D538 - arg0;
}

void func_800358D4(void *arg0)
{
  union 
  {
    unsigned char bytes[152];
    struct 
    {
      f32 value;
    } view_sp28;
    struct 
    {
      unsigned char pad[4];
      f32 value;
    } view_sp2C;
    struct 
    {
      unsigned char pad[8];
      f32 value;
    } view_sp30;
    struct 
    {
      unsigned char pad[16];
      s32 value;
    } view_sp38;
    struct 
    {
      unsigned char pad[20];
      s32 value;
    } view_sp3C;
    struct 
    {
      unsigned char pad[24];
      s32 value;
    } view_sp40;
    struct 
    {
      unsigned char pad[28];
      s32 value;
    } view_sp44;
    struct 
    {
      unsigned char pad[32];
      s32 value;
    } view_sp48;
    struct 
    {
      unsigned char pad[40];
      s32 value;
    } view_sp50;
    struct 
    {
      unsigned char pad[56];
      f32 value;
    } view_sp60;
    struct 
    {
      unsigned char pad[60];
      f32 value;
    } view_sp64;
    struct 
    {
      unsigned char pad[64];
      f32 value;
    } view_sp68;
    struct 
    {
      unsigned char pad[72];
      f32 value;
    } view_sp70;
    struct 
    {
      unsigned char pad[88];
      f32 value;
    } view_sp80;
    struct 
    {
      unsigned char pad[92];
      f32 value;
    } view_sp84;
    struct 
    {
      unsigned char pad[96];
      f32 value;
    } view_sp88;
    struct 
    {
      unsigned char pad[108];
      f32 value;
    } view_sp94;
    struct 
    {
      unsigned char pad[119];
      u8 value;
    } view_sp9F;
    struct 
    {
      unsigned char pad[127];
      u8 value;
    } view_spA7;
    struct 
    {
      unsigned char pad[135];
      u8 value;
    } view_spAF;
    struct 
    {
      unsigned char pad[140];
      s32 value;
    } view_spB4;
  } m2c_initial_frame;
  s32 var_a0;
  void *temp_v0_5;
  f32 *temp_s1;
  f32 temp_fs0;
  f32 temp_fv0;
  f32 temp_fv0_2;
  f32 temp_fv0_3;
  f32 temp_fv0_4;
  void *temp_v1_2;
  f32 var_fs1;
  f32 var_fv0;
  s32 *temp_a0;
  u8 *var_s2;
  s32 var_s1;
  s32 var_s4;
  register s32 var_v0;
  u32 temp_v0_2;
  unsigned var_a1;
  s32 temp_v1_3;
  u8 temp_v0;
  void *temp_a1;
  void *temp_v1_6;
  void *temp_v0_4;
  void *temp_a1_2;
  void *temp_v1;
  f32 var_fs0;
  void *temp_v1_4;
  void *temp_v1_5;
  u32 temp_v0_3;
  void *var_fp;
  void *var_s3;
  var_fp = gObjectListHead;
  if (gRenderMode != 2)
  {
    gRenderMode = 2;
    func_80039068();
  }
  var_a0 = 7;
  if (D_8010A924 != 7)
  {
    temp_v1 = D_80115328;
    D_8010A924 = 7;
    D_80115328 = temp_v1 + 8;
    *((s32 *) (((char *) temp_v1) + 0)) = 0xDE000000;
    *((s32 **) (((char *) temp_v1) + 4)) = &D_800B1CA8;
  }
  var_a1 = 0xFC410000;
  if (D_801032A0 != 2)
  {
    if (D_800C2B40 || m2c_initial_frame.view_spB4.value)
    {
      var_a1 = 0xFC419883;
      temp_v1_2 = D_80115328;
      var_a0 = 0xFF32FF7F;
      D_801032A0 = 2;
      D_80115328 = temp_v1_2 + 8;
      *((s32 *) (((char *) temp_v1_2) + 0)) = 0xFC419883;
      *((s32 *) (((char *) temp_v1_2) + 4)) = 0xFF32FF7F;
    }
    else
    {
      var_a1 = 0xFC419883;
      temp_v1_2 = D_80115328;
      var_a0 = 0xFF32FF7F;
      D_801032A0 = 2;
      D_80115328 = temp_v1_2 + 8;
      *((s32 *) (((char *) temp_v1_2) + 0)) = 0xFC419883;
      *((s32 *) (((char *) temp_v1_2) + 4)) = 0xFF32FF7F;
    }
  }
  temp_v1_3 = *((s32 *) (((char *) arg0) + 0x100));
  if (temp_v1_3 & 1)
  {
    m2c_initial_frame.view_spAF.value = 0xFF;
    var_fv0 = func_800357C8(0.05f) + 1.0f;
    m2c_initial_frame.view_spA7.value = 0xFF;
    m2c_initial_frame.view_sp9F.value = 0xFF;
    goto block_10;
  }
  if (!(temp_v1_3 & 4))
  {
    m2c_initial_frame.view_spAF.value = 0;
    temp_fv0 = func_800357C8(0.1f);
    m2c_initial_frame.view_sp9F.value = 0;
    m2c_initial_frame.view_spA7.value = 0xFF;
    var_fv0 = temp_fv0 + 3.0f;
    block_10:
    m2c_initial_frame.view_sp94.value = var_fv0;

    if (var_fp != NULL)
    {
      for (;;)
      {
        var_s3 = *((void **) (((char *) var_fp) + 0x14));
        if (var_s3 != NULL)
        {
          m2c_initial_frame.view_spB4.value = m2c_initial_frame.view_sp9F.value << 0x18;
          for (;;)
          {
            if (((((((u32) (*((s32 *) (((char *) var_s3) + 0x58)))) >> 2) & 1) && (((temp_v0 = *((u8 *) (((char *) var_s3) + 0x54)), temp_s1 = var_s3 + 0x24, temp_v0 == 0)) || ((*((u8 *) (((s8 *) (&gTrackMarkerDone)) + temp_v0))) != (*((u8 *) (((char *) var_s3) + 0x55)))))) && ((IsSphereVisible(temp_s1, *((s32 *) (((char *) var_s3) + 0x4C)), var_fp, arg0) << 0x18) != 0)) && ((func_80034928(arg0, 2), func_800452E0(temp_s1, arg0 + 0x1C, &m2c_initial_frame.view_sp28.value), rotateVec3ByMat3(arg0 + 0xB8, &m2c_initial_frame.view_sp28.value), m2c_initial_frame.view_sp30.value > 0.0f)))
            {
              if (((u32) (*((s32 *) (&sMatrixPoolUsed)))) < ((u32) (*((s32 *) (&sMatrixPoolLimit)))))
              {
                temp_v0_2 = (*((s32 *) (&sMatrixPoolUsed))) + 1;
                *((s32 *) (&sMatrixPoolUsed)) = temp_v0_2;
                D_8010D538 = (*((s32 *) (((char *) sRenderState) + 0x74C))) + (temp_v0_2 << 6);
                func_800083DC(&D_80112F90, m2c_initial_frame.view_sp28.value * 64.0f, m2c_initial_frame.view_sp2C.value * 64.0f, m2c_initial_frame.view_sp30.value * 64.0f, m2c_initial_frame.view_sp94.value);
                guMtxF2L(&D_80112F90, D_8010D538);
                *((s32 *) (((char *) D_80115328) + 0)) = 0xDA380003;
                *((s32 *) (((char *) D_80115328) + 4)) = (s32) inline_fn(0x80000000);
                *((s32 *) (((char *) D_80115328) + 8)) = 0xFA000000;
                *((s32 *) (((char *) D_80115328) + 0xC)) = (s32) ((((m2c_initial_frame.view_spA7.value << 0x10) | m2c_initial_frame.view_spB4.value) | (m2c_initial_frame.view_spAF.value << 8)) | 0xFF);
                temp_a1 = D_80115328 + 0x10;
                D_80115328 += 8;
                D_80115328 = temp_a1;
                func_80032630(*((s32 *) (((char *) var_s3) + 0x3C)), temp_a1);
                if ((((((u32) (*((s32 *) (((char *) var_s3) + 0x58)))) >> 2) & 2) && ((m2c_initial_frame.view_sp38.value = func_8004478C(1, 0x18A), m2c_initial_frame.view_sp3C.value = func_8004478C(2, 0x18A), m2c_initial_frame.view_sp40.value = func_8004478C(3, 0x18A), m2c_initial_frame.view_sp44.value = func_8004478C(4, 0x18A), m2c_initial_frame.view_sp48.value = func_8004478C(5, 0x18A), (func_800158A4(arg0 + 0x10, temp_s1, *((s32 *) (((char *) arg0) + 0xF4)), &m2c_initial_frame.view_sp50.value, 0, 0, 0, 1, 0) << 0x18) != 0))) && ((temp_fv0_2 = func_80046140(m2c_initial_frame.view_sp28.value, m2c_initial_frame.view_sp2C.value), var_fs1 = temp_fv0_2, temp_fv0_2 < 127.0f)))
                {
                  temp_fv0_3 = 25.0f / m2c_initial_frame.view_sp30.value;
                  var_s1 = 0;
                  var_s2 = &D_800C06C4;
                  var_s4 = 0;
                  m2c_initial_frame.view_sp60.value = 0.0f;
                  m2c_initial_frame.view_sp64.value = 0.0f;
                  m2c_initial_frame.view_sp68.value = 25.0f;
                  m2c_initial_frame.view_sp28.value *= temp_fv0_3;
                  m2c_initial_frame.view_sp30.value *= temp_fv0_3;
                  m2c_initial_frame.view_sp2C.value *= temp_fv0_3;
                  func_800452E0(&m2c_initial_frame.view_sp60.value, &m2c_initial_frame.view_sp28.value, &m2c_initial_frame.view_sp70.value);
                  for (;;)
                  {
                    func_80047B14(&m2c_initial_frame.view_sp70.value, *((s32 *) (((s8 *) (&D_800C0670)) + var_s4)), &m2c_initial_frame.view_sp80.value);
                    vec3Add(&m2c_initial_frame.view_sp28.value, &m2c_initial_frame.view_sp80.value, &m2c_initial_frame.view_sp80.value);
                    if (var_s1 == 0)
                    {
                      var_fs1 = func_80046140(m2c_initial_frame.view_sp80.value, m2c_initial_frame.view_sp84.value);
                      var_fs0 = (16.0f - var_fs1) * 0.03125f;
                      if ((*((s32 *) (((char *) arg0) + 0x100))) & 2)
                      {
                        temp_fv0_4 = approxDistance(arg0 + 0x10, var_s3 + 0x24) * 0.125f;
                        if (temp_fv0_4 > 1.0f)
                        {
                          var_fs0 /= temp_fv0_4;
                        }
                      }
                      if ((*((f32 *) (((char *) arg0) + 0x124))) < var_fs0)
                      {
                        if (temp_fv0_4)
                        {
                          *((f32 *) (((char *) arg0) + 0x124)) = var_fs0;
                        }
                        else
                        {
                          *((f32 *) (((char *) arg0) + 0x124)) = var_fs0;
                        }
                      }
                      if ((*((f32 *) (((char *) arg0) + 0x124))) > 1.0f)
                      {
                        *((f32 *) (((char *) arg0) + 0x124)) = 1.0f;
                      }
                      if ((*((f32 *) (((char *) arg0) + 0x124))) < 0.0f)
                      {
                        *((f32 *) (((char *) arg0) + 0x124)) = 0.0f;
                      }
                      if (!((*((s32 *) (((char *) arg0) + 0x100))) & 2))
                      {
                        goto block_35;
                      }
                      goto block_47;
                    }
                    block_35:
                    if (var_fs1 < 127.0f)
                    {
                      temp_fs0 = *((f32 *) (((s8 *) (&D_800C0698)) + var_s4));
                      if (((u32) (*((s32 *) (&sMatrixPoolUsed)))) < ((u32) (*((s32 *) (&sMatrixPoolLimit)))))
                      {
                        temp_v0_3 = (*((s32 *) (&sMatrixPoolUsed))) + 1;
                        D_8010D538 = (*((s32 *) (((char *) sRenderState) + 0x74C))) + (temp_v0_3 << 6);
                        *((s32 *) (&sMatrixPoolUsed)) = temp_v0_3;
                        guTranslateF(&D_80112F90, m2c_initial_frame.view_sp80.value * 64.0f, m2c_initial_frame.view_sp84.value * 64.0f, m2c_initial_frame.view_sp88.value * 64.0f);
                        func_800A3940(&sParentMatrixF, temp_fs0, temp_fs0, temp_fs0);
                        func_800A3840(&sParentMatrixF, &D_80112F90, &D_80112F90);
                        guMtxF2L(&D_80112F90, D_8010D538);
                        temp_v1_4 = D_80109CB8;
                        temp_a1_2 = temp_v1_4 + 8;
                        *((s32 *) (((char *) temp_v1_4) + 4)) = (s32) inline_fn(0x80000000);
                        temp_v0_4 = temp_v1_4 + 0x10;
                        D_80109CB8 = temp_a1_2;
                        *((s32 *) (((char *) temp_v1_4) + 0)) = 0xDA380003;
                        D_80109CB8 = temp_v0_4;
                        *((s32 *) (((char *) temp_v1_4) + 8)) = 0xFA000000;
                        if (!(2.1474836e9f <= 0.0f))
                        {
                          var_v0 = ((s32) 0.0f) & 0xFF;
                        }
                        else
                        {
                          var_v0 = (((s32) (0.0f - 2.1474836e9f)) | 0x80000000) & 0xFF;
                        }
                        *((s32 *) (((char *) temp_a1_2) + 4)) = (s32) (((((*((u8 *) (((s8 *) (&D_800C06D0)) + var_s1))) << 0x18) | ((*((u8 *) (((s8 *) (&D_800C06DC)) + var_s1))) << 0x10)) | ((*((u8 *) (((s8 *) (&D_800C06E8)) + var_s1))) << 8)) | var_v0);
                        temp_a0 = *((s32 **) (((char *) (&(&m2c_initial_frame.view_sp28.value)[*var_s2])) + 0x10));
                        if (((*temp_a0) != 0) || ((func_80043FA0(temp_a0, temp_a1_2), (*(*((s32 **) (((char *) (&(&m2c_initial_frame.view_sp28.value)[*var_s2])) + 0x10)))) != 0)))
                        {
                          temp_v1_5 = *((void **) (((char *) (&(&m2c_initial_frame.view_sp28.value)[*var_s2])) + 0x10));
                          if (!((*((u8 *) (((char *) temp_v1_5) + 0x46))) & 0x80))
                          {
                            *((u8 *) (((char *) temp_v1_5) + 0x46)) = (u8) D_800C2B40;
                          }
                          temp_v1_6 = D_80109CB8;
                          D_80109CB8 = temp_v1_6 + 8;
                          *((s32 *) (((char *) temp_v1_6) + 0)) = 0xDE000000;
                          *((s32 *) (((char *) temp_v1_6) + 4)) = (s32) (*(*((s32 **) (((char *) (&(&m2c_initial_frame.view_sp28.value)[*var_s2])) + 0x10))));
                        }
                        goto block_45;
                      }
                    }
                    else
                    {
                      block_45:
                      ++var_s2;

                      var_s1 += 1;
                      var_s4 += 4;
                      if (var_s1 >= 0xA)
                      {
                        temp_v0_5 = D_80109CB8;
                        D_80109CB8 = temp_v0_5 + 8;
                        *((s32 *) (((char *) temp_v0_5) + 0)) = 0xFA000000;
                        *((s32 *) (((char *) temp_v0_5) + 4)) = -1;
                        goto block_47;
                      }
                      continue;
                    }

                    break;
                  }

                }
                else
                {
                  goto block_47;
                }
              }
            }
            else
            {
              block_47:
              var_s3 = *((void **) (((char *) var_s3) + 0x14));

              if (var_s3 == NULL)
              {
                goto block_48;
              }
              continue;
            }
            break;
          }

        }
        else
        {
          block_48:
          var_fp = *((void **) (((char *) var_fp) + 0x1C));

          if (var_fp == NULL)
          {
            goto block_49;
          }
          continue;
        }
        break;
      }

    }
    else
    {
      block_49:
      func_80034928(arg0, D_8010A4D8);

    }
  }
}

