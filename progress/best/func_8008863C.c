s32 func_80093758(s32);
s32 func_8009D5D4(void *);
s32 func_8009D9B8(void *);
s32 func_8009D9D8(void *);
s32 osRecvMesg(s32 *, s32, s32);
s32 osSendMesg(s32 *, s32, s32);
s32 startAudioVoice(u8, s32, s32, s32, s32, s32, s32, s32, s32 *, s32);
extern f64 D_800D66D0;
extern u16 D_800E2C60;
extern u8 D_800E2CC1;
extern u8 D_800E2CC2;
extern u8 D_800E2CC3;
extern u8 D_800E2CC4;
extern s32 D_800E2CD4;
extern u8 D_800E2CD8;
extern u8 D_800E2CD9;
extern s32 D_800E2CDC;
extern f32 D_800E2CE0;
extern s32 func_80088EE4;
extern s32 (*gDataBankFree)(s32);
extern volatile u8 sDataBankFlags;
extern u8 sDataBankInitialised;
extern s32 sDataBankMesgQueue;
extern s32 sDataBankMode;
extern u8 sDataBanks;
inline static u8 inline_fn(s32 arg0)
{
  return *((u8 *) (((u8 *) (&D_800E2CC4)) + arg0));
}

void func_8008863C(void)
{
  f64 var_ft0;
  f32 rate;
  s32 temp_v0;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 var_s0;
  s32 var_s7;
  s32 limit;
  u8 *var_s2;
  s32 *var_s3;
  s32 *var_s4;
  u8 *var_s5;
  s32 *var_s6;
  u8 temp_v0_2;
  void *temp_s1;
  if (sDataBankInitialised != 0)
  {
    osRecvMesg(&sDataBankMesgQueue, 0, 1);
    var_s7 = 0;
    limit = 2;
    var_s2 = &D_800E2CD8;
    var_s6 = (s32 *) ((&D_800E2CD8) - 0xC);
    var_s3 = (s32 *) ((&D_800E2CD8) - 8);
    var_s5 = (&D_800E2CD8) - 0x3B;
    var_s4 = (s32 *) ((&D_800E2CD8) - 0x10);
    var_s0 = 0;
    do
    {
      if ((*((volatile u8 *) (((u8 *) (&sDataBankFlags)) + var_s0))) != 0)
      {
        temp_s1 = (&sDataBanks) + var_s0;
        func_8009D5D4(temp_s1);
        temp_v1 = (*((volatile u8 *) (((u8 *) (&sDataBankFlags)) + var_s0))) & 0xFF;
        if (temp_v1 == limit)
        {
          goto state2;
        }
        if (temp_v1 < 3)
        {
          if (temp_v1 == 1)
          {
            goto state1;
          }
          goto advance;
        }
        if (temp_v1 == 3)
        {
          goto state3;
        }
        goto advance;
        state1:
        if (((s8) (*var_s5)) == limit)
        {
          temp_v1_2 = *var_s4;
          rate = (((f32) (*((u16 *) (((u8 *) (&D_800E2C60)) + var_s0)))) * 160.0f) / ((f32) ((f64) ((u32) temp_v1_2)));
          *((s32 *) (((u8 *) (&D_800E2CDC)) + var_s0)) = 0;
          *((volatile u8 *) (((u8 *) (&sDataBankFlags)) + var_s0)) = limit;
          *((f32 *) (((u8 *) (&D_800E2CE0)) + var_s0)) = rate;
          func_8009D9B8(temp_s1);
          {
            s32 arg0 = inline_fn(var_s0);
            s32 arg1 = *var_s3;
            s32 arg2 = *((s32 *) (((u8 *) (&D_800E2CD4)) + var_s0));
            s32 arg3 = *var_s4;
            temp_v0 = startAudioVoice(arg0, arg1, arg2, arg3, (s32) (*((u8 *) (((u8 *) (&D_800E2CC1)) + var_s0))), (s32) (*((u8 *) (((u8 *) (&D_800E2CC2)) + var_s0))), (s32) (*((u8 *) (((u8 *) (&D_800E2CC3)) + var_s0))), (s32) (*((u8 *) (((u8 *) (&D_800E2CD9)) + var_s0))), &func_80088EE4, var_s7);
          }
          *((s32 *) (((char *) temp_s1) + 0x120C)) = temp_v0;
          if (temp_v0 == (-1))
          {
            func_8009D9D8(temp_s1);
            goto block_17;
          }
          goto block_23;
        }

        goto block_23;
        state2:
        if (((s8) (*var_s5)) == 4)
        {
          *((volatile u8 *) (((u8 *) (&sDataBankFlags)) + var_s0)) = 3;
          *var_s2 = 4;
        }

        goto block_23;
        state3:
        temp_v0_2 = *var_s2;

        if (temp_v0_2 == 0)
        {
          block_17:
          if (!(sDataBankMode & 1))
          {
            gDataBankFree(*var_s3);
          }

          *((volatile u8 *) (((u8 *) (&sDataBankFlags)) + var_s0)) = 0;
          var_s2 += 0x1228;
        }
        else
        {
          if (temp_v0_2 == limit)
          {
            func_80093758(*var_s6);
            do
            {
              *var_s6 = -1;
            }
            while (0);
          }
          *((s8 *) (((char *) temp_s1) + 0x1218)) = (s8) ((*var_s2) - 1);
          goto block_23;
        }
        goto advanced;
        advance:
        var_s2 += 0x1228;

        advanced:
        ;

        ;
      }
      else
      {
        block_23:
        var_s2 += 0x1228;

      }
      var_s6 = (s32 *) (((u8 *) var_s6) + 0x1228);
      var_s3 = (s32 *) (((u8 *) var_s3) + 0x1228);
      var_s5 += 0x1228;
      var_s4 = (s32 *) (((u8 *) var_s4) + 0x1228);
      var_s7 += 1;
      var_s0 += 0x1228;
    }
    while (var_s7 < 2);
    osSendMesg(&sDataBankMesgQueue, 0, 0);
  }
}

