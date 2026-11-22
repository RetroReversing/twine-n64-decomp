s32 audioApplyVoiceConfig(void *, u32 *);
s32 audioCmdNoteOn(void *, u32 *);
s32 audioUpdateClipSelection(void *, void *);
s32 audioVoiceApplyEnvelope(void *, u32 *);
s32 audioVoiceIsActive(u8);
s32 audioVoiceStepTimer(u8 *, u8 *);
s32 func_8008C380(u8, s32);
s32 func_8008C590(u8);
s32 func_8008C7E0(s32);
s32 func_8008CE38(void *);
s32 func_800957A8(u32 *);
s32 func_800957B8(u32 *, void *);
s32 func_800968A4(u8, u8, u8);
u8 func_800968E8(u8, u8);
s32 func_8009692C(u8, u8, s32);
s32 func_800969B4(void *);
u32 func_80096D9C(void *);
s32 func_80096E1C(s32);
s32 func_80096F44(void *, s32, s32);
s32 func_800982B4(u32);
void *func_8009846C(s32);
s32 func_80098B14(void *, u8);
s32 func_8009A0E4(void *, u32 *);
s32 func_8009A4E4(void *, u32 *);
s32 func_8009A70C(void *, u32 *);
s32 func_8009A804(void *, u32 *, s32);
s32 func_8009A990(void *, u32 *);
s32 func_8009ABD4(void *, u32 *, s32);
s32 func_8009AE24(void *, u32 *, s32);
s32 randomU16Next();
s32 releaseAudioVoice(void *);
s32 voiceListRemove(void *);
extern u32 D_800FDB9C;
extern u8 D_800FDB9D;
extern u8 D_800FDB9E;
extern s32 D_800FDBA0;
extern s32 D_801007D9;
extern u8 D_80100868;
extern s32 D_80100C7C;
extern s32 D_80109680;
extern s32 D_8010D748;
extern s32 D_8010D784;
extern s32 D_80112E9E;
extern s32 D_80112EBE;
extern u8 sVoiceCount;
inline static char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

inline static void *inline_fn2(void *arg0, unsigned int arg1)
{
  return arg0 + (arg1 * 4);
}

void audioVoiceTick(void *arg0, s32 arg1, s32 arg2)
{
  union 
  {
    u16 params[4];
    u32 value;
  } scratch;
  volatile u32 frameSpace[14];
  s32 var_a2_4;
  s32 var_a2_5;
  register s16 temp_v0_20;
  s32 var_v0;
  unsigned long temp_a0;
  s32 temp_a0_11;
  s32 temp_a0_13;
  s32 temp_a0_15;
  s32 temp_a0_17;
  s32 temp_a0_19;
  s32 temp_a0_21;
  s32 temp_a0_23;
  s32 temp_a0_2;
  u32 temp_a0_5;
  s32 temp_a0_7;
  u8 temp_s2_6;
  s32 temp_v0_14;
  s32 temp_v0_15;
  long temp_v0_19;
  s32 temp_v0_21;
  s32 temp_v0_3;
  s32 temp_v0_4;
  int temp_v0_5;
  s32 temp_v0_6;
  s32 temp_v0_7;
  s32 temp_v0_8;
  s32 temp_v1;
  s32 temp_v1_11;
  s32 temp_v1_2;
  unsigned long temp_v1_3;
  s32 temp_v1_4;
  s32 temp_v1_6;
  s32 temp_v1_7;
  s32 temp_v1_9;
  s32 var_a2;
  s32 var_a2_2;
  s32 var_a2_3;
  s32 var_a1_4;
  s32 var_v0_2;
  void *temp_a0_16;
  s32 var_v0_5;
  unsigned int var_v1;
  u16 temp_s0;
  u16 temp_v0_10;
  u16 temp_v0_11;
  u16 temp_v0_12;
  register u16 temp_v0_13;
  u16 temp_v1_10;
  u16 var_v1_3;
  unsigned int temp_s0_10;
  u32 temp_s0_11;
  long temp_s0_2;
  unsigned temp_s0_3;
  u32 temp_s0_4;
  int temp_s0_5;
  u32 temp_s0_6;
  s32 temp_s0_7;
  u32 temp_s0_8;
  u32 temp_s0_9;
  u32 temp_v0_17;
  u32 temp_v0_18;
  register u32 temp_v1_12;
  u32 temp_v1_23;
  u32 temp_v1_24;
  unsigned long temp_v1_25;
  u32 temp_v1_5;
  register u32 temp_v1_8;
  long var_a1_2;
  u32 var_v0_6;
  u8 temp_a0_3;
  u8 temp_a0_4;
  u8 temp_a1;
  u8 temp_a1_2;
  volatile unsigned short pad;
  u8 temp_a2;
  u8 temp_s2;
  u8 temp_s2_2;
  u8 temp_s2_3;
  u8 temp_s2_4;
  u8 temp_s2_5;
  s32 temp_a0_9;
  u8 temp_s2_7;
  u8 temp_s2_8;
  u8 temp_s2_9;
  u8 temp_v0;
  u8 temp_v0_16;
  u8 temp_v0_22;
  u8 temp_v0_2;
  u8 temp_v1_13;
  u8 temp_v1_14;
  u8 temp_v1_15;
  register u8 temp_v1_16;
  u8 temp_v1_17;
  u8 temp_v1_18;
  register u8 temp_v1_19;
  u8 temp_v1_20;
  u8 temp_v1_21;
  u8 var_a1;
  u8 var_a1_3;
  u8 var_v0_3;
  u8 var_v1_2;
  void *temp_a0_10;
  void *temp_a0_12;
  void *var_a0;
  s32 var_v0_4;
  register void *temp_a0_18;
  register void *temp_a0_20;
  void *temp_a0_22;
  register void *temp_a0_6;
  void *temp_a0_8;
  void *temp_v0_9;
  void *temp_v1_22;
  void *temp_a0_14;
  var_a1 = arg1 & 0xFF;
  var_a2 = arg2;
  temp_v1 = *((s32 *) (((char *) arg0) + 0x24));
  if (temp_v1 & 3)
  {
    if (temp_v1 & 1)
    {
      *((s32 *) (((char *) arg0) + 0x24)) = (s32) (temp_v1 & (~1));
      func_8008C590(*((u8 *) (((char *) arg0) + 0x63)));
    }
    if (!((*((s32 *) (((char *) arg0) + 0x24))) & 0x40))
    {
    func_800969B4(arg0);
    temp_v0_2 = *(((u8 *) arg0) + 0x54);
    temp_v1_2 = *(((u8 *) arg0) + 0x52);
    temp_a2 = *(((u8 *) arg0) + 0x56);
    *(((u8 *) arg0) + 0x4A) = temp_v0_2;
    *(((u8 *) arg0) + 0x4B) = *(((u8 *) arg0) + 0x55);
    temp_v1_2 <<= 16;
    *((s32 *) (((u8 *) arg0) + 0x30)) = temp_v1_2;
    *((s32 *) (((u8 *) arg0) + 0x34)) = temp_v1_2;
    *((u8 *) (((char *) arg0) + 0x2F)) = temp_a2;
    *((s32 *) (((char *) arg0) + 0x38)) = (s32) ((*((u8 *) (((char *) arg0) + 0x53))) << 0x10);
    temp_v0 = func_800968E8(*((u8 *) (((char *) arg0) + 0x4A)), *((u8 *) (((char *) arg0) + 0x4B)));
    if ((temp_v0 & 0xFF) != 0xFF)
    {
      *((u8 *) (((char *) arg0) + 0xC1)) = temp_v0;
    }
    else
    {
      *((u8 *) (((char *) arg0) + 0xC1)) = (u8) (*((volatile u16 *) (((char *) arg0) + 0x4E)));
    }
    func_800968A4(*((u8 *) (((char *) arg0) + 0x4A)), *((u8 *) (((char *) arg0) + 0x4B)), *((u8 *) (((char *) arg0) + 0x4F)));
    temp_v1_3 = *((s32 *) (((char *) arg0) + 0x60));
    if ((temp_v1_3 != (-1)) && ((temp_a1 = *((u8 *) (((char *) arg0) + 0x4A)), temp_a1 != 0xFF)))
    {
      s8 value = temp_v1_3;
      temp_v0_2 = *((u8 *) (((char *) arg0) + 0x4B));
      if (temp_v0_2 == 0xFF)
      {
        ((s8 *) &D_80100C7C)[(u8) value] = value;
      }
      else
      {
        s8 (*rows)[16] = (s8 (*)[16]) &D_801007D9;
        rows[temp_v0_2][temp_a1] = value;
      }
    }
    var_a1 = *((u8 *) (((char *) arg0) + 0xBF));
    var_a2 = 0;
    *((s32 *) (((char *) arg0) + 0x90)) = 0x64U;
    *((u8 *) (((char *) arg0) + 0x6A)) = 2;
    *((u8 *) (((char *) arg0) + 0x6B)) = 2;
    *((u8 *) (((char *) arg0) + 0x99)) = 0x80;
    *((s32 *) (((char *) arg0) + 0x8C)) = 0;
    *((u8 *) (((char *) arg0) + 0x98)) = 0;
    *((u8 *) (((char *) arg0) + 0x9A)) = 0;
    *((u16 *) (((char *) arg0) + 0x68)) = 0;
    *((u8 *) (((char *) arg0) + 0x48)) = 0;
    *((u8 *) (((char *) arg0) + 0x49)) = 0;
    *((s32 *) (((char *) arg0) + 0x40)) = 0;
    *((s32 *) (((char *) arg0) + 0x44)) = 0;
    *((s32 *) (((char *) arg0) + 0x16C)) = 0;
    *((u16 *) (((char *) arg0) + 0x170)) = 0;
    *((s32 *) (((char *) arg0) + 0x178)) = 0;
    *((u16 *) (((char *) arg0) + 0x17C)) = 0;
    *((s32 *) (((char *) arg0) + 0x1C)) = 0;
    *((void **) (((char *) arg0) + 0x20)) = NULL;
    *((s32 *) (((char *) arg0) + 0x5C)) = 0x4000AC44;
    *((u16 *) (((char *) arg0) + 0xB8)) = 0x2000;
    *((u16 *) (((char *) arg0) + 0xC2)) = 0;
    *((u8 *) (((char *) arg0) + 0xBE)) = var_a1;
    *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) & 8);
    {
      register u8 __repair_i;
      for (__repair_i = 0; __repair_i < 0x10; __repair_i++)
      {
        *((u16 *) (((char *) ((__repair_i * 2) + arg0)) + 0x180)) = 0;
      }

    }
    *((s32 *) (((char *) arg0) + 0xA0)) = 0U;
    *((s32 *) (((char *) arg0) + 0xA4)) = 0U;
    goto block_19;
    }
    *((s32 *) (((char *) arg0) + 0x24)) = 0;
    releaseAudioVoice(arg0);

    return;
  }
  block_19:
  var_a0 = *((void **) (((char *) arg0) + 0x20));

  if (var_a0 != NULL)
  {
    temp_v1_4 = *((s32 *) (((char *) arg0) + 0x24));
    if (!(temp_v1_4 & 0x40000000))
    {
      if (temp_v1_4 & 8)
      {
        temp_v0_3 = *((s32 *) (((char *) arg0) + 0x1C));
        *((void **) (((char *) arg0) + 4)) = var_a0;
        *((s32 *) (((char *) arg0) + 0x9C)) = 0U;
        *((void **) (((char *) arg0) + 0x20)) = NULL;
        *((s32 *) (((char *) arg0) + 0x1C)) = 0;
        *((s32 *) (((char *) arg0) + 0)) = temp_v0_3;
      }
    }
  }
  if ((*((s32 *) (((char *) arg0) + 0x9C))) == 0)
  {
    s32 commandResult;
    s32 invalidVoice;
    s32 divisorReciprocal;
    D_80100868 = 1;
    invalidVoice = -1;
    divisorReciprocal = 0x51EB851F;
    loop_25:
    {
    volatile u32 *commandWord = &D_800FDB9C;
    *commandWord = *((u32 *) (((char *) (*((void **) (((char *) arg0) + 4)))) + 0));

    *((u32 *) (((char *) (&D_800FDBA0)) + 0)) = (u32) (*((u32 *) (((char *) (*((void **) (((char *) arg0) + 4)))) + 4)));
    *((void **) (((char *) arg0) + 4)) = (void *) ((*((void **) (((char *) arg0) + 4))) + 8);
    temp_v1_5 = *commandWord & 0x7F;
    }
    switch (temp_v1_5)
    {
      case 0x1:
        if (D_800FDB9E && ((temp_v1_6 = *((s32 *) (((char *) arg0) + 8)), commandResult = 0, temp_v1_6 != 0)))
      {
        *((s32 *) (((char *) arg0) + 0)) = temp_v1_6;
        *((void **) (((char *) arg0) + 4)) = (void *) (*((void **) (((char *) arg0) + 0xC)));
      }
      else
      {
        case 0x0:
          block_40:
        goto release_command;
      }
        break;

      case 0x2:
      {
        unsigned long command = *(volatile u32 *) &D_800FDB9C;
        if (((u16) (*((u16 *) (((char *) arg0) + 0x50)))) >= ((u8) D_800FDB9E))
      {
        temp_v0_4 = func_800982B4(command >> 0x10);
        commandResult = 0;
        if (temp_v0_4 != 0)
        {
          *((s32 *) (((char *) arg0) + 0)) = temp_v0_4;
          *((void **) (((char *) arg0) + 4)) = (void *) (temp_v0_4 + ((*((u16 *) (((char *) (&D_800FDBA0)) + 2))) * 8));
        }
      }
      else
      {
        default:
          block_205:
        commandResult = 0;


      }
        break;

      }
      case 0x3:
      {
        unsigned long command = *(volatile u32 *) &D_800FDB9C;
        if ((*((u16 *) (((char *) arg0) + 0x30))) >= ((u8) D_800FDB9E))
      {
        temp_v0_5 = func_800982B4(command >> 0x10);
        commandResult = 0;
        if (temp_v0_5 != 0)
        {
          *((s32 *) (((char *) arg0) + 0)) = temp_v0_5;
          *((void **) (((char *) arg0) + 4)) = (void *) (temp_v0_5 + ((*((u16 *) (((char *) (&D_800FDBA0)) + 2))) * 8));
        }
      }
      else
      {
        goto block_205;
      }
        break;

      }
      case 0x4:
        commandResult = audioUpdateClipSelection(arg0, &D_800FDB9C);
        break;

      case 0x5:
        commandResult = audioVoiceStepTimer(arg0, (u8 *)&D_800FDB9C);
        break;

      case 0x6:
        temp_v0_6 = func_800982B4((u32) (*((u16 *) (((char *) (&D_800FDB9C)) + 0))));
        commandResult = 0;
        if (temp_v0_6)
      {
        temp_v0_7 = *((s32 *) (((char *) arg0) + 0));
        *((s32 *) (((char *) arg0) + 0)) = temp_v0_6;
        *((s32 *) (((char *) arg0) + 8)) = temp_v0_7;
        *((void **) (((char *) arg0) + 0xC)) = (void *) (*((void **) (((char *) arg0) + 4)));
        *((void **) (((char *) arg0) + 4)) = (void *) (temp_v0_6 + ((*((u16 *) (((char *) (&D_800FDBA0)) + 2))) * 8));
      }
      else
      {
        goto block_40;
      }
        break;

      case 0x7:
        *((u8 *) (((char *) (&D_800FDBA0)) + 2)) = 1;
        commandResult = audioUpdateClipSelection(arg0, &D_800FDB9C);
        break;

      case 0x8:
        commandResult = audioCmdNoteOn(arg0, &D_800FDB9C);
        break;

      case 0x9:
        var_a1_2 = 0;
      {
        u32 key = (((*((u16 *) (((char *) arg0) + 0x4E))) + D_800FDB9E) << 8) | ((*((u16 *) (((char *) (&D_800FDB9C)) + 0))) << 16);
        u32 voiceCount = sVoiceCount;
        if (voiceCount != 0)
        {
          var_a2_2 = 0;
          do
          {
            temp_a0 = *((s32 *) (((char *) (&D_8010D784)) + var_a2_2));
            if (temp_a0 == (key | var_a1_2))
            {
              if ((s32) temp_a0 != invalidVoice)
              {
                temp_s2_6 = (temp_a0 & 0xFF); temp_v1_7 = temp_s2_6 * 0x1A0;
                if ((*((s32 *) (((char *) (&D_8010D784)) + temp_v1_7))) == temp_a0)
                {
                  *((s32 *) (((char *) (&D_8010D748)) + temp_v1_7)) |= 8;
                }
              }
            }
            var_a1_2 += 1;
            var_a2_2 += 0x1A0;
          }
          while (var_a1_2 < voiceCount);
          commandResult = 0;
        }
        else
        {
          block_60:
          commandResult = 0;

        }
      }
        break;

      case 0xA:
        commandResult = 0;
        if ((*((u8 *) (((char *) arg0) + 0x4A))) != 0xFF)
      {
        if (((u32) ((func_80096D9C(arg0) >> 7) & 0xFF)) >= ((u8) D_800FDB9E))
        {
          temp_v0_8 = func_800982B4(D_800FDB9C >> 0x10);
          commandResult = 0;
          if (temp_v0_8)
          {
            *((s32 *) (((char *) arg0) + 0)) = temp_v0_8;
            *((void **) (((char *) arg0) + 4)) = (void *) (temp_v0_8 + ((*((u16 *) (((char *) (&D_800FDBA0)) + 2))) * 8));
          }
        }
        else
        {
          goto block_205;
        }
      }
        break;


      case 0xB:
        temp_a0_2 = (((s32) ((((*((u16 *) (((char *) arg0) + 0x50))) - D_800FDB9D) << 0x10) * (((s32) (D_800FDB9C << 0x10)) >> 0x18))) >> 7) + ((((u32) D_800FDB9C) >> 0x18) << 0x10);
        if (temp_a0_2 >= 0)
      {
        var_v1 = 0x7F0000;
        if (0x7F0000 > (temp_a0_2 - 1))
        {
          {
            long long phantom_wide = arg1;
          }
          var_v1 = temp_a0_2;
        }
      }
      else
      {
        var_v1 = 0;
      }
        *((s32 *) (((char *) arg0) + 0x38)) = var_v1;
        goto block_60;

      case 0xC:
        temp_v0_9 = func_8009846C((((u32) D_800FDB9C) >> 8) & 0xFFFF);
        if (temp_v0_9 != 0)
      {
        temp_v0_10 = *((u16 *) (((char *) temp_v0_9) + 0));
        temp_s0_7 = (temp_v0_10 >> 8); scratch.params[0] = temp_s0_7 | (temp_v0_10 << 8);
        temp_v0_11 = *((u16 *) (((char *) temp_v0_9) + 2));
        scratch.params[1] = (temp_v0_11 >> 8) | (temp_v0_11 << 8);
        temp_v0_12 = *((u16 *) (((char *) temp_v0_9) + 4));
        scratch.params[2] = (temp_v0_12 >> 8) | (temp_v0_12 << 8);
        temp_v0_13 = *((u16 *) (((char *) temp_v0_9) + 6));
        scratch.params[3] = (temp_v0_13 >> 8) | (temp_v0_13 << 8);
        func_8008C3D8((s32) (*((u8 *) (((char *) arg0) + 0x63))), scratch.params);
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) | 0x200);
        goto block_60;
      }
        goto block_205;

      case 0xD:
        commandResult = func_8009A70C(arg0, &D_800FDB9C);
        break;

      case 0xE:
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) | 0x10000);
        temp_s0 = *((u16 *) (((char *) (&D_800FDB9C)) + 0));
        *((s32 *) (((char *) arg0) + 0xA8)) = (s32) temp_s0;
        func_800957A8(arg0 + 0xA8);
        temp_v0_14 = D_800FDB9E << 0x10;
        temp_v1_8 = (*((s8 *) (((char *) (&D_800FDBA0)) + 3))) << 0x10;
        *((s32 *) (((char *) arg0) + 0x38)) = temp_v0_14;
        *((s32 *) (((char *) arg0) + 0xAC)) = (s32) (temp_v1_8 + temp_v0_14);
        if ((*((s32 *) (((char *) arg0) + 0xA8))) != 0)
      {
        *((s32 *) (((char *) arg0) + 0x3C)) = (u32) (temp_v1_8 / temp_s0);
      }
      else
      {
        *((s32 *) (((char *) arg0) + 0x3C)) = temp_v1_8;
      }
        goto block_60;

      case 0xF:
        var_a2_3 = *((s32 *) (((char *) arg0) + 0x30));
        commandResult = func_8009A804(arg0, &D_800FDB9C, var_a2_3);
        break;

      case 0x10:
        commandResult = audioVoiceApplyEnvelope(arg0, &D_800FDB9C);
        break;

      case 0x11:
        commandResult = 0;
        func_8008C380(*((u8 *) (((char *) arg0) + 0x63)), 1);
        break;

      case 0x12:
        commandResult = 0;
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) | 0x80);
        break;

      case 0x13:
        if (((u32) (randomU16Next() & 0xFF)) >= ((u8) D_800FDB9E))
      {
        temp_v0_15 = func_800982B4(D_800FDB9C >> 0x10);
        commandResult = 0;
        if (temp_v0_15 != 0)
        {
          *((void **) (((char *) arg0) + 4)) = (void *) (temp_v0_15 + ((*((u16 *) (((char *) (&D_800FDBA0)) + 2))) * 8));
          *((s32 *) (((char *) arg0) + 0)) = temp_v0_15;
        }
      }
      else
      {
        goto block_205;
      }
        break;

      case 0x14:
        var_a2_3 = 0;
        commandResult = func_8009A804(arg0, &D_800FDB9C, var_a2_3);
        break;

      case 0x17:
        commandResult = func_8009A990(arg0, &D_800FDB9C);
        break;

      case 0x18:
        commandResult = func_8009A0E4(arg0, &D_800FDB9C);
        break;

      case 0x19:
        temp_v1_9 = *((s32 *) (((char *) arg0) + 0x60));
        *((u16 *) (((char *) arg0) + 0x50)) = (u16) (((unsigned) D_800FDB9E) & 0x7F);
        *((u8 *) (((char *) arg0) + 0xC0)) = (s8) ((u16) D_800FDB9C);
        if (temp_v1_9 != invalidVoice)
      {
        temp_a1_2 = *((u8 *) (((char *) arg0) + 0x4A));
        var_v0_2 = 0;
        if (temp_a1_2 != 0xFF)
        {
          temp_v0_16 = *((u8 *) (((char *) arg0) + 0x4B));
          if (temp_v0_16 == 0xFF)
          {
            var_v1_2 = temp_v1_9 & 0xFF;
            var_v0_3 = *(((s8 *) (&D_80100C7C)) + var_v1_2);
          }
          else
          {
            s8 (*rows)[16] = (s8 (*)[16]) &D_801007D9;
            var_v1_2 = rows[temp_v0_16][temp_a1_2];
            var_v0_3 = temp_v1_9 & 0xFF;
          }
          var_v0_2 = 0;
          if (var_v1_2 == var_v0_3)
          {
            var_v0_2 = 1;
          }
        }
      }
      else
      {
        var_v0_2 = 0;
      }
        if (var_v0_2 & 0xFF)
      {
        func_800968A4(*((u8 *) (((char *) arg0) + 0x4A)), *((u8 *) (((char *) arg0) + 0x4B)), *((u8 *) (((char *) arg0) + 0x51)));
      }
        D_800FDB9C = 4;
        commandResult = audioUpdateClipSelection(arg0, &D_800FDB9C);
        break;

      case 0x1A:
        temp_v1_10 = (*((u8 *) (((char *) arg0) + 0xC1))) + (((s32) (D_800FDB9C << 0x10)) >> 0x18);
        *((u16 *) (((char *) arg0) + 0x50)) = temp_v1_10;
        if (!(temp_v1_10 & 0x8000))
      {
        if (((u32) (temp_v1_10 & 0xFFFF)) >= 0x80U)
        {
          var_v1_3 = 0x7F;
          goto block_95;
        }
        *((u16 *) (((char *) arg0) + 0x50)) = temp_v1_10;
      }
      else
      {
        var_v1_3 = 0;
        block_95:
        *((u16 *) (((char *) arg0) + 0x50)) = var_v1_3;

      }
        temp_a0_3 = *((u8 *) (((char *) arg0) + 0x4A));
        *((u8 *) (((char *) arg0) + 0xC0)) = (s8) ((u16) D_800FDB9C);
        if (temp_a0_3 != 0xFF)
      {
        func_800968A4(temp_a0_3, *((u8 *) (((char *) arg0) + 0x4B)), *((u8 *) (((char *) arg0) + 0x51)));
      }
        D_800FDB9C = 4;
        commandResult = audioUpdateClipSelection(arg0, &D_800FDB9C);
        break;

      case 0x1B:
        *((u8 *) (((char *) arg0) + 0x98)) = (s8) ((u16) D_800FDB9C);
        scratch.value = ((u32) (*((u32 *) (((char *) (&D_800FDBA0)) + 0)))) >> 0x10;
        if ((((u32) (*((u32 *) (((char *) (&D_800FDBA0)) + 0)))) >> 8) & 1)
      {
        func_800957A8(&scratch.value);
      }
      else
      {
        func_800957B8(&scratch.value, arg0);
      }
        *((s32 *) (((char *) arg0) + 0x90)) = scratch.value;
        if (D_800FDB9E != 0)
      {
        commandResult = 0;
        if (D_800FDB9E != 1)
        {
        }
        else
        {
          if (!((*((s32 *) (((char *) arg0) + 0x24))) & 0x800))
          {
            func_8008CE38(arg0);
          }
          *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) | 0x1800);
          goto block_60;
        }
      }
      else
      {
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) (((*((s32 *) (((char *) arg0) + 0x24))) & (~0x800)) | 0x1000);
        temp_a0_4 = *((u8 *) (((char *) arg0) + 0x4A));
        if (temp_a0_4 != 0xFF)
        {
          func_8009692C(temp_a0_4, *((u8 *) (((char *) arg0) + 0x4B)), 0);
          commandResult = 0;
        }
        else
        {
          goto block_205;
        }
      }
        break;

      case 0x1C:
        commandResult = audioApplyVoiceConfig(arg0, &D_800FDB9C);
        break;

      case 0x1D:
        *((s32 *) (((char *) arg0) + 0x40)) = 0;
        temp_v0_17 = ((u32) D_800FDB9C) >> 8;
        *((u8 *) (((char *) arg0) + 0x48)) = (s8) temp_v0_17;
        *((u8 *) (((char *) arg0) + 0xB0)) = (s8) temp_v0_17;
      {
        s16 pitch = *((s16 *) (&D_800FDB9C));
        if (pitch >= 0)
        {
          var_v0_4 = func_8008C7E0(pitch);
        }
        else
        {
          var_v0_4 = -func_8008C7E0(-pitch);
        }
      }
        *((s32 *) (((char *) arg0) + 0x7C)) = (s32) (var_v0_4 << 0x10);
        block_119:
      D_800FDB9C = 0;

        commandResult = audioUpdateClipSelection(arg0, &D_800FDB9C);
        break;

      case 0x1E:
        *((s32 *) (((char *) arg0) + 0x44)) = 0;
        temp_v0_18 = ((u32) ((s32) D_800FDB9C)) >> 8;
        *((u8 *) (((char *) arg0) + 0x49)) = (s8) temp_v0_18;
        *((u8 *) (((char *) arg0) + 0xB1)) = (s8) temp_v0_18;
      {
        s16 pitch = *((s16 *) (&D_800FDB9C));
        if (pitch >= 0)
        {
          var_v0_5 = func_8008C7E0(pitch);
        }
        else
        {
          var_v0_5 = -func_8008C7E0(-pitch);
        }
      }
        *((s32 *) (((char *) arg0) + 0x80)) = (s32) (var_v0_5 << 0x10);
      {
        D_800FDB9C = 0;
        commandResult = audioUpdateClipSelection(arg0, &D_800FDB9C);
        break;
      }

      case 0x1F:
        commandResult = func_8009A4E4(arg0, &D_800FDB9C);
        break;

      case 0x28:
        temp_v0_19 = func_800982B4((u32) (*((u16 *) (((char *) (&D_800FDB9C)) + 0))));
        commandResult = 0;
        if (temp_v0_19 != 0)
      {
        *((s32 *) (((char *) arg0) + 0x1C)) = temp_v0_19;
        *((void **) (((char *) arg0) + 0x20)) = (void *) (temp_v0_19 + ((*((u16 *) (((char *) (&D_800FDBA0)) + 2))) * 8));
      }
        break;

      case 0x29:
        commandResult = 0;
        *((void **) (((char *) arg0) + 0x20)) = 0;
        *((s32 *) (((char *) arg0) + 0x1C)) = 0;
        break;

      case 0x30:
        temp_v1_11 = (((u32) (*((s32 *) (((char *) arg0) + 0x28)))) >> 0xF) + (*((s16 *) (((char *) (&D_800FDB9C)) + 0)));
        if (temp_v1_11 < 0)
      {
        *((s32 *) (((char *) arg0) + 0x28)) = 0U;
      }
      else
      {
        if (temp_v1_11 > 0xFFFF)
        {
          var_v0_6 = 0x7FFF8000;
        }
        else
        {
          var_v0_6 = temp_v1_11 << 0xF;
        }
        *((s32 *) (((char *) arg0) + 0x28)) = var_v0_6;
      }
        goto block_60;

      case 0x31:
        commandResult = 0;
        *((s32 *) (((char *) arg0) + 0x28)) = (u32) ((*((u16 *) (((char *) (&D_800FDB9C)) + 0))) << 0xF);
        break;

      case 0x32:
        *((s16 *) (((char *) (&D_80112EBE)) + (D_800FDB9E * 2))) = (s16) D_800FDB9D;
        commandResult = 0;
        break;

      case 0x33:
        *((u8 *) (((char *) arg0) + 0x6A)) = (s8) ((u16) D_800FDB9C);
        commandResult = 0;
        *((u8 *) (((char *) arg0) + 0x6B)) = (s8) (((u32) D_800FDB9C) >> 8);
        break;

      case 0x34:
        *((u8 *) (((char *) arg0) + 0x99)) = (s8) (((u32) D_800FDB9C) >> 8);
        commandResult = 0;
        *((u8 *) (((char *) arg0) + 0x9A)) = (s8) ((u16) D_800FDB9C);
        break;

      case 0x35:
        commandResult = 0;
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) | 0x40000);
        break;

      case 0x36:
        var_a1_3 = D_800FDB9E;
        block_144:
      func_80098B14(arg0, var_a1_3);

        commandResult = 0;
        break;

      case 0x37:
        temp_v0_20 = (*((u8 *) (((char *) arg0) + 0x2E))) + ((u16) D_800FDB9C);
        var_a1_4 = temp_v0_20;
        if (temp_v0_20 >= 0)
      {
        if (temp_v0_20 >= 0x100)
        {
          var_a1_4 = 0xFF;
        }
      }
      else
      {
        var_a1_4 = 0;
      }
        var_a1_3 = var_a1_4 & 0xFF;
        goto block_144;

      case 0x38:
        if ((*((u32 *) (((char *) (&D_800FDBA0)) + 0))) == 0)
      {
        *((u16 *) (((char *) arg0) + 0x2C)) = 0;
      }
      else
      {
        *((u16 *) (((char *) arg0) + 0x2C)) = (s16) (((u32) (((u32) (*((s32 *) (((char *) arg0) + 0x28)))) >> 8)) / ((u32) (*((u32 *) (((char *) (&D_800FDBA0)) + 0)))));
      }
        goto block_60;

      case 0x39:
        temp_v1_12 = ((u16) D_800FDB9C) + (((u32) ((*((u16 *) (((char *) arg0) + 0x30))) * (*((u16 *) (((char *) (&D_800FDBA0)) + 2))))) >> 7);
        var_v0_6 = 0x75300000;
        if (temp_v1_12 <= 0xEA60U)
      {
        var_v0_6 = temp_v1_12 << 0xF;
      }
      {
        *((s32 *) (((char *) arg0) + 0x28)) = var_v0_6;
        goto block_60;
      }

      case 0x40:
        temp_a0_5 = *((s32 *) (((char *) arg0) + 0x24));
        temp_s2 = *((u8 *) (((char *) (&D_800FDBA0)) + 3));
        if ((((u32) (temp_a0_5 & 0x200000) - 1U) >> 31) | (temp_s2 == 0))
      {
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) (temp_a0_5 | 0x200000);
        *((u8 *) (((char *) arg0) + 0xD4)) = 0U;
      }
        temp_v1_13 = *((u8 *) (((char *) arg0) + 0xD4));
        temp_s0_2 = temp_v1_13 & 0xFF;
        temp_a0_6 = arg0 + 0xC4;
        if (temp_s0_2 < 4U)
      {
        u32 marker;
        *((u8 *) (((char *) arg0) + 0xD4)) = (u8) (temp_v1_13 + 1);
        marker = func_80096E1C(D_800FDB9E);
        temp_a0_6 = inline_fn2(temp_a0_6, temp_s0_2);
        *((s8 *) (((char *) temp_a0_6) + 0)) = marker;
        *((u8 *) (((char *) temp_a0_6) + 1)) = temp_s2;
        {
          s32 scaled = (*((s16 *) (&D_800FDB9C))) * 256;
          *((u16 *) (((char *) temp_a0_6) + 2)) = (s16) (((((s64) scaled) * divisorReciprocal) >> 37) - (scaled >> 31));
        }
      }
        goto block_60;

      case 0x41:
        temp_a0_7 = *((s32 *) (((char *) arg0) + 0x24));
        temp_s2_2 = *((u8 *) (((char *) (&D_800FDBA0)) + 3));
        if ((((u32) (temp_a0_7 & 0x400000) - 1U) >> 31) | (!temp_s2_2))
      {
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) (temp_a0_7 | 0x400000);
        *((u8 *) (((char *) arg0) + 0xE6)) = 0U;
      }
        temp_v1_14 = *((u8 *) (((char *) arg0) + 0xE6));
        temp_s0_3 = temp_v1_14 & 0xFF;
        temp_a0_8 = arg0 + 0xD6;
        if (temp_s0_3 < 4U)
      {
        unsigned int marker;
        *((u8 *) (((char *) arg0) + 0xE6)) = (u8) (temp_v1_14 + 1);
        marker = func_80096E1C(D_800FDB9E);
        temp_a0_8 = inline_fn2(temp_a0_8, temp_s0_3);
        *((s8 *) (((char *) temp_a0_8) + 0)) = marker;
        *((u8 *) (((char *) temp_a0_8) + 1)) = temp_s2_2;
        {
          s32 scaled = (*((s16 *) (&D_800FDB9C))) * 256;
          *((u16 *) (((char *) temp_a0_8) + 2)) = (s16) (((((s64) scaled) * divisorReciprocal) >> 37) - (scaled >> 31));
        }
      }
        goto block_60;

      case 0x42:
        temp_a0_9 = *((s32 *) (((char *) arg0) + 0x24));
        temp_s2_3 = *((u8 *) (((char *) (&D_800FDBA0)) + 3));
        if ((((u32) (temp_a0_9 & 0x800000) - 1U) >> 31) | (temp_s2_3 == 0))
      {
        *((s32 *) (0x24 + ((char *) arg0))) = (s32) (temp_a0_9 | 0x800000);
        *((u8 *) (inline_fn(arg0) + 0x10A)) = 0U;
      }
        temp_v1_15 = *((u8 *) (((char *) arg0) + 0x10A));
        temp_s0_4 = temp_v1_15 & 0xFF;
        temp_a0_10 = arg0 + 0xFA;
        if (4U > temp_s0_4)
      {
        s32 marker;
        *((u8 *) (((char *) arg0) + 0x10A)) = (u8) (temp_v1_15 + 1);
        marker = func_80096E1C(D_800FDB9E);
        temp_a0_10 = inline_fn2(temp_a0_10, temp_s0_4);
        *((s8 *) (((char *) temp_a0_10) + 0)) = marker;
        *((u8 *) (((char *) temp_a0_10) + 1)) = temp_s2_3;
        {
          s32 scaled = (*((s16 *) (&D_800FDB9C))) * 256;
          *((u16 *) (((char *) temp_a0_10) + 2)) = (s16) (((((s64) scaled) * divisorReciprocal) >> 37) - (scaled >> 31));
        }
      }
        goto block_60;

      case 0x43:
        temp_a0_11 = *((s32 *) (((char *) arg0) + 0x24));
        temp_s2_4 = *((u8 *) (((char *) (&D_800FDBA0)) + 3));
        if ((((u32) (temp_a0_11 & 0x01000000) - 1U) >> 31) | (temp_s2_4 == 0))
      {
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) (temp_a0_11 | 0x01000000);
        *((u8 *) (((char *) arg0) + 0x12E)) = 0U;
      }
        temp_v1_16 = *((u8 *) (((char *) arg0) + 0x12E));
        temp_s0_5 = temp_v1_16 & 0xFF;
        temp_a0_12 = arg0 + 0x11E;
        if (temp_s0_5 < 4U)
      {
        s32 marker;
        *((u8 *) (((char *) arg0) + 0x12E)) = (u8) (temp_v1_16 + 1);
        marker = func_80096E1C(D_800FDB9E);
        temp_a0_12 = inline_fn2(temp_a0_12, temp_s0_5);
        *((s8 *) (((char *) temp_a0_12) + 0)) = marker;
        *((u8 *) (((char *) temp_a0_12) + 1)) = temp_s2_4;
        {
          s32 scaled = (*((s16 *) (&D_800FDB9C))) * 256;
          *((u16 *) (((char *) temp_a0_12) + 2)) = (s16) (((((s64) scaled) * divisorReciprocal) >> 37) - (scaled >> 31));
        }
      }
        goto block_60;

      case 0x44:
        temp_a0_13 = *((s32 *) (((char *) arg0) + 0x24));
        temp_s2_5 = *((u8 *) (((char *) (&D_800FDBA0)) + 3));
        if ((((u32) (temp_a0_13 & 0x08000000) - 1U) >> 31) | (temp_s2_5 == 0))
      {
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) (temp_a0_13 | 0x08000000);
        *((u8 *) (((char *) arg0) + 0x140)) = 0U;
      }
        temp_v1_17 = *((u8 *) (((char *) arg0) + 0x140));
        temp_s0_6 = temp_v1_17 & 0xFF;
        temp_a0_14 = arg0 + 0x130;
        if (temp_s0_6 < 4U)
      {
        s32 marker;
        *((u8 *) (((char *) arg0) + 0x140)) = (u8) (temp_v1_17 + 1);
        marker = func_80096E1C(D_800FDB9E);
        temp_a0_14 = inline_fn2(temp_a0_14, (u32) temp_s0_6);
        *((s8 *) (((char *) temp_a0_14) + 0)) = marker;
        *((u8 *) (((char *) temp_a0_14) + 1)) = temp_s2_5;
        {
          s32 scaled = (*((s16 *) (&D_800FDB9C))) * 256;
          *((u16 *) (((char *) temp_a0_14) + 2)) = (s16) (((((s64) scaled) * divisorReciprocal) >> 37) - (scaled >> 31));
        }
      }
        goto block_60;

      case 0x45:
        temp_a0_15 = *((s32 *) (((char *) arg0) + 0x24));
        temp_s2_6 = *((u8 *) (((char *) (&D_800FDBA0)) + 3));
        if ((((u32) (temp_a0_15 & 0x04000000) - 1U) >> 31) | (!temp_s2_6))
      {
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) (temp_a0_15 | 0x04000000);
        *((u8 *) (((char *) arg0) + 0x152)) = 0U;
      }
        temp_v1_18 = *((u8 *) (((char *) arg0) + 0x152));
        temp_s0_7 = temp_v1_18 & 0xFF;
        temp_a0_16 = arg0 + 0x142;
        if (temp_s0_7 < 4U)
      {
        s32 marker;
        *((u8 *) (((char *) arg0) + 0x152)) = (u8) (temp_v1_18 + 1);
        marker = func_80096E1C(D_800FDB9E);
        temp_a0_16 = inline_fn2(temp_a0_16, temp_s0_7);
        *((s8 *) (((char *) temp_a0_16) + 0)) = marker;
        *((u8 *) (((char *) temp_a0_16) + 1)) = temp_s2_6;
        {
          s32 scaled = (*((s16 *) (&D_800FDB9C))) * 256;
          *((u16 *) (((char *) temp_a0_16) + 2)) = (s16) (((((s64) scaled) * divisorReciprocal) >> 37) - (scaled >> 31));
        }
      }
        goto block_60;

      case 0x46:
        temp_a0_17 = *((s32 *) (((char *) arg0) + 0x24));
        temp_s2_7 = *((u8 *) (((char *) (&D_800FDBA0)) + 3));
        if ((((u32) (temp_a0_17 & 0x02000000) - 1U) >> 31) | (temp_s2_7 == 0))
      {
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) (temp_a0_17 | 0x02000000);
        *((u8 *) (((char *) arg0) + 0x164)) = 0U;
      }
        temp_v1_19 = *((u8 *) (((char *) arg0) + 0x164));
        temp_s0_8 = temp_v1_19 & 0xFF;
        temp_a0_18 = arg0 + 0x154;
        if (temp_s0_8 < 4U)
      {
        s32 marker;
        *((u8 *) (((char *) arg0) + 0x164)) = (u8) (temp_v1_19 + 1);
        marker = func_80096E1C(D_800FDB9E);
        temp_a0_18 = inline_fn2(temp_a0_18, temp_s0_8);
        *((s8 *) (((char *) temp_a0_18) + 0)) = marker;
        *((u8 *) (((char *) temp_a0_18) + 1)) = temp_s2_7;
        {
          s32 scaled = (*((s16 *) (&D_800FDB9C))) * 256;
          *((u16 *) (((char *) temp_a0_18) + 2)) = (s16) (((((s64) scaled) * divisorReciprocal) >> 37) - (scaled >> 31));
        }
      }
        goto block_60;

      case 0x47:
        temp_a0_19 = *((s32 *) (((char *) arg0) + 0x24));
        temp_s2_8 = *((u8 *) (((char *) (&D_800FDBA0)) + 3));
        if ((((u32) (temp_a0_19 & 0x10000000) - 1U) >> 31) | (temp_s2_8 == 0))
      {
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) (temp_a0_19 | 0x10000000);
        *((u8 *) (((char *) arg0) + 0xF8)) = 0U;
      }
        temp_v1_20 = *((u8 *) (((char *) arg0) + 0xF8));
        temp_s0_9 = temp_v1_20 & 0xFF;
        temp_a0_20 = arg0 + 0xE8;
        if (temp_s0_9 < 4U)
      {
        s32 marker;
        *((u8 *) (((char *) arg0) + 0xF8)) = (u8) (temp_v1_20 + 1);
        marker = func_80096E1C(D_800FDB9E);
        temp_a0_20 = inline_fn2(temp_a0_20, temp_s0_9);
        *((s8 *) (((char *) temp_a0_20) + 0)) = marker;
        *((u8 *) (((char *) temp_a0_20) + 1)) = temp_s2_8;
        {
          s32 scaled = (*((s16 *) (&D_800FDB9C))) * 256;
          *((u16 *) (((char *) temp_a0_20) + 2)) = (s16) (((((s64) scaled) * divisorReciprocal) >> 37) - (scaled >> 31));
        }
      }
        goto block_60;

      case 0x48:
        temp_a0_21 = *((s32 *) (((char *) arg0) + 0x24));
        temp_s2_9 = *((u8 *) (((char *) (&D_800FDBA0)) + 3));
        if ((((u32) (temp_a0_21 & 0x20000000) - 1U) >> 31) | (temp_s2_9 == 0))
      {
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) (temp_a0_21 | 0x20000000);
        *((u8 *) (((char *) arg0) + 0x11C)) = 0U;
      }
        temp_v1_21 = *((u8 *) (((char *) arg0) + 0x11C));
        temp_s0_10 = temp_v1_21 & 0xFF;
        temp_a0_22 = arg0 + 0x10C;
        if (temp_s0_10 < 4U)
      {
        s32 marker;
        *((u8 *) (((char *) arg0) + 0x11C)) = (u8) (temp_v1_21 + 1);
        marker = func_80096E1C(D_800FDB9E);
        temp_a0_22 = inline_fn2(temp_a0_22, temp_s0_10);
        *((s8 *) (((char *) temp_a0_22) + 0)) = marker;
        *((u8 *) (((char *) temp_a0_22) + 1)) = temp_s2_9;
        {
          s32 scaled = (*((s16 *) (&D_800FDB9C))) * 256;
          *((u16 *) (((char *) temp_a0_22) + 2)) = (s16) (((((s64) scaled) * divisorReciprocal) >> 37) - (scaled >> 31));
        }
      }
        goto block_60;

      case 0x50:
        temp_s0_11 = ((u32) D_800FDB9C) >> 8;
        scratch.value = ((u32) D_800FDB9C) >> 0x10;
        func_800957A8(&scratch.value);
        var_a2_2 = ((temp_s0_11 & 0xFF) * 0xC); temp_v1_22 = arg0 + var_a2_2;
        if ((*((s32 *) (((char *) temp_v1_22) + 0x16C))) != 0)
      {
        *((s32 *) (((char *) temp_v1_22) + 0x168)) = 0;
      }
        commandResult = 0;
        *((s32 *) (((char *) temp_v1_22) + 0x16C)) = scratch.value;
        break;

      case 0x60:
        commandResult = func_8009ABD4(arg0, &D_800FDB9C, 0);
        break;

      case 0x61:
        commandResult = func_8009ABD4(arg0, &D_800FDB9C, 1);
        break;

      case 0x62:
        commandResult = func_8009ABD4(arg0, &D_800FDB9C, 2);
        break;

      case 0x63:
        commandResult = func_8009ABD4(arg0, &D_800FDB9C, 3);
        break;

      case 0x64:
        commandResult = func_8009ABD4(arg0, &D_800FDB9C, 4);
        break;

      case 0x65:
        temp_v1_23 = ((u32) D_800FDB9C) >> 0x10;
        temp_a0 = D_800FDBA0;
        if ((((u32) D_800FDB9C) >> 8) & 0xFF)
      {
        func_80096F44(arg0, temp_v1_23 & 0xFF, (s16) temp_a0);
        commandResult = 0;
      }
      else
      {
        temp_v1_23 = temp_v1_23 & 0x1F;
        temp_v0_21 = temp_v1_23 * 2;
        if (temp_v1_23 < 0x10U)
        {
          *((u16 *) (((char *) (temp_v0_21 + arg0)) + 0x180)) = (u16) temp_a0;
          goto block_60;
        }
        *((s16 *) (((char *) (&D_80112E9E)) + temp_v0_21)) = (s16) temp_a0;
        commandResult = 0;
      }
        break;

      case 0x70:
        commandResult = func_8009AE24(arg0, &D_800FDB9C, 0);
        break;

      case 0x71:
        commandResult = func_8009AE24(arg0, &D_800FDB9C, 1);
        break;

    }

    goto command_complete;
    release_command:
    voiceListRemove(arg0);
    releaseAudioVoice(arg0);
    commandResult = 1;
    command_complete:
    if (!(commandResult & 0xFF))
    {
      temp_v0_22 = D_80100868 + 1;
      D_80100868 = temp_v0_22;
      if (((u32) (temp_v0_22 & 0xFF)) < 0x21U)
      {
        goto loop_25;
      }
    }
    *((s32 *) (((char *) arg0) + 0xA4)) = (u32) ((*((s32 *) (((char *) arg0) + 0xA4))) + D_80109680);
    return;
  }
  temp_a0_23 = *((s32 *) (((char *) arg0) + 0x24));
  *((s32 *) (((char *) arg0) + 0xA4)) = (u32) ((*((s32 *) (((char *) arg0) + 0xA4))) + D_80109680);
  if ((((*((s32 *) (((char *) arg0) + 0x24))) & 4) && (!(temp_a0_23 & 0x40000000))) && ((*((s32 *) (((char *) arg0) + 0x24))) & 8))
  {
    *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) & (~4));
    *((s32 *) (((char *) arg0) + 0x9C)) = 0U;
    *((s32 *) (((char *) arg0) + 0xA0)) = (u32) (*((s32 *) (((char *) arg0) + 0xA4)));
  }
  if (((*((s32 *) (((char *) arg0) + 0x24))) & 0x100000) && (!(audioVoiceIsActive(*((u8 *) (((char *) arg0) + 0x63))) & 0xFF)))
  {
    *((s32 *) (((char *) arg0) + 0x9C)) = 0U;
    *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) & 0xFFEFFFFF);
    *((s32 *) (((char *) arg0) + 0xA0)) = (u32) (*((s32 *) (((char *) arg0) + 0xA4)));
  }
  temp_v1_25 = *((s32 *) (((char *) arg0) + 0x9C));
  if ((temp_v1_25 != (-1U)) && (((u32) (*((s32 *) (((char *) arg0) + 0xA4)))) >= temp_v1_25))
  {
    *((s32 *) (((char *) arg0) + 0xA0)) = temp_v1_25;
    *((s32 *) (((char *) arg0) + 0x9C)) = 0U;
  }
}







