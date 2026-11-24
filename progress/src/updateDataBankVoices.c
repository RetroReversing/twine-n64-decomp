s32 stopVoiceIfPlaying(s32);
s32 updateAudioStream(void *);
s32 advanceStreamStateToThree(void *);
s32 setDataBankState4(void *);
s32 osRecvMesg(s32 *, s32, s32);
s32 osSendMesg(s32 *, s32, s32);
s32 startAudioVoice(u8, s32, s32, s32, s32, s32, s32, s32, s32 *, s32);
extern f64 D_800D66D0;
extern u16 sDataBankBaseRates;
extern u8 D_800E2CC1;
extern u8 D_800E2CC2;
extern u8 D_800E2CC3;
extern u8 D_800E2CC4;
extern s32 D_800E2CD4;
extern u8 D_800E2CD8;
extern u8 D_800E2CD9;
extern s32 sDataBankElapsedTicks;
extern f32 D_800E2CE0;
extern s32 advanceDataBankByTicks;
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

inline static u8 *inline_fn2(s32 arg0)
{
  return (u8 *) (((u8 *) (&D_800E2CC1)) + arg0);
}

/* Per-frame update of both data banks: runs each active bank's streaming state machine (start voice, finish, free). */ void updateDataBankVoices(void)
{
  f64 var_ft0;
  f32 playbackRate;
  s32 voiceId;
  s32 temp_v1;
  s32 temp_v1_2;
  s32 bankOffset;
  s32 bankIndex;
  s32 stateLoading;
  u8 *stateCursor;
  s32 *var_s3;
  s32 *var_s4;
  u8 *statusCursor;
  s32 *var_s6;
  u8 temp_v0_2;
  void *bank;
  if (sDataBankInitialised != 0)
  {
    osRecvMesg(&sDataBankMesgQueue, 0, 1);
    bankIndex = 0;
    stateLoading = 2;
    stateCursor = &D_800E2CD8;
    var_s6 = (s32 *) ((&D_800E2CD8) - 0xC);
    var_s3 = (s32 *) ((&D_800E2CD8) - 8);
    statusCursor = (&D_800E2CD8) + (-0x3B);
    var_s4 = (s32 *) ((&D_800E2CD8) - 0x10);
    bankOffset = 0;
    do
    {
      if ((*((volatile u8 *) (((u8 *) (&sDataBankFlags)) + bankOffset))) != 0)
      {
        bank = (&sDataBanks) + bankOffset;
        do
        {
          updateAudioStream(bank);
          temp_v1 = (*((volatile u8 *) (((u8 *) (&sDataBankFlags)) + bankOffset))) & 0xFF;
          if (temp_v1 == stateLoading)
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
          do
          {
            state1:
            if (((s8) (*statusCursor)) == stateLoading)
            {
              temp_v1_2 = *var_s4; playbackRate = (((f32) (*((u16 *) (((u8 *) (&sDataBankBaseRates)) + bankOffset)))) * 160.0f) / ((f32) ((f64) ((u32) temp_v1_2)));
              *((s32 *) (((u8 *) (&sDataBankElapsedTicks)) + bankOffset)) = 0;
              do
              {
                *((volatile u8 *) (((u8 *) (&sDataBankFlags)) + bankOffset)) = stateLoading;
                *((f32 *) (((u8 *) (&D_800E2CE0)) + bankOffset)) = playbackRate;
                advanceStreamStateToThree(bank);
                {
                  s32 arg0 = inline_fn(bankOffset);
                  s32 arg1 = *var_s3;
                  s32 arg2 = *((s32 *) (((u8 *) (&D_800E2CD4)) + bankOffset));
                  s32 arg3 = *var_s4;
                  voiceId = startAudioVoice(arg0, arg1, arg2, arg3, (s32) (*inline_fn2(bankOffset)), (s32) (*((u8 *) (((u8 *) (&D_800E2CC2)) + bankOffset))), (s32) (*((u8 *) (((u8 *) (&D_800E2CC3)) + bankOffset))), (s32) (*((u8 *) (((u8 *) (&D_800E2CD9)) + bankOffset))), &advanceDataBankByTicks, bankIndex);
                }
              }
              while (0);
              *((s32 *) (((char *) bank) + 0x120C)) = voiceId;
              if (voiceId == (-1))
              {
                setDataBankState4(bank);
                goto block_17;
              }
              goto block_23;
            }

          }
          while (0);
          goto block_23;
          state2:
          if (((s8) (*statusCursor)) == 4)
          {
            *((volatile u8 *) (((u8 *) (&sDataBankFlags)) + bankOffset)) = 3;
            *stateCursor = 4;
          }

          goto block_23;
          state3:
          temp_v0_2 = *stateCursor;

          if (temp_v0_2 == 0)
          {
            block_17:
            if (!(sDataBankMode & 1))
            {
              if (bankOffset)
              {
                gDataBankFree(*var_s3);
              }
              else
              {
                gDataBankFree(*var_s3);
              }
            }

            *((volatile u8 *) (((u8 *) (&sDataBankFlags)) + bankOffset)) = 0; stateCursor += 0x1228;
          }
          else
          {
            if (temp_v0_2 == stateLoading)
            {
              stopVoiceIfPlaying(*var_s6);
              do
              {
                *var_s6 = -1;
              }
              while (0);
            }
            *((s8 *) (((char *) bank) + 0x1218)) = (s8) ((*stateCursor) - 1);
            goto block_23;
          }
        }
        while (0);
        goto advanced;
        advance:
        stateCursor += 0x1228;

        advanced:
        ;

        ;
        ;
        ;
        ;
        ;
        ;
      }
      else
      {
        block_23:
        stateCursor += 0x1228;

      }
      var_s6 = (s32 *) (((u8 *) var_s6) + 0x1228);
      var_s3 = (s32 *) (((u8 *) var_s3) + 0x1228);
      statusCursor += 0x1228;
      var_s4 = (s32 *) (((u8 *) var_s4) + 0x1228);
      bankIndex += 1;
      bankOffset += 0x1228;
    }
    while (bankIndex < 2);
    osSendMesg(&sDataBankMesgQueue, 0, 0);
  }
}

