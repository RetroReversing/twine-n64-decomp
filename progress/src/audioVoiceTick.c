s32 audioApplyVoiceConfig(void *, u32 *);
s32 audioCmdNoteOn(void *, u32 *);
s32 audioUpdateClipSelection(void *, void *);
s32 audioVoiceApplyEnvelope(void *, u32 *);
s32 audioVoiceIsActive(u8);
s32 audioVoiceStepTimer(u8 *, u8 *);
s32 resetAudioVoiceEnvelope(u8, s32);
s32 deactivateAudioVoice(u8);
s32 convertRateToFixedPitch(s32);
s32 updateAudioVoiceParams(void *);
s32 shiftLeft8InPlace(u32 *);
s32 scaleValueByOutputRate(u32 *, void *);
s32 setClipSlotValue(u8, u8, u8);
u8 getAudioControlValue(u8, u8);
s32 setAudioSlotValue(u8, u8, s32);
s32 func_800969B4(void *);
u32 evalVoiceModulator1(void *);
s32 remapSpecialChar(s32);
s32 seqWriteIndirectVar(void *, s32, s32);
s32 lookupSortedEntry(u32);
void *getCurveTable(s32);
s32 linkVoiceIntoGroup(void *, u8);
s32 adjustVoiceLevelAndRefreshClip(void *, u32 *);
s32 computeVoicePitchKey(void *, u32 *);
s32 updateVoiceLevelEnvelope(void *, u32 *);
s32 startVoiceParamRamp(void *, u32 *, s32);
s32 audioStartRandomizedNote(void *, u32 *);
s32 seqExecArithmetic(void *, u32 *, s32);
s32 seqCmdCompareBranch(void *, u32 *, s32);
s32 randomU16Next();
s32 releaseAudioVoice(void *);
s32 voiceListRemove(void *);
extern u32 gSeqCommandWord0;
extern u8 D_800FDB9D;
extern u8 D_800FDB9E;
extern s32 D_800FDBA0;
extern s32 gVoiceSlotTable;
extern u8 gSeqCommandsRun;
extern s32 gVoiceIdTable;
extern s32 gAudioTickStep;
extern s32 sSoundVoiceFlags;
extern s32 sSoundVoiceHandle;
extern s32 gSeqGlobalVars;
extern s32 gLockedSlotTable;
extern u8 sVoiceCount;
inline static char *inline_fn(void *arg0)
{
  return (char *) arg0;
}

inline static void *inline_fn2(void *arg0, unsigned int arg1)
{
  return arg0 + (arg1 * 4);
}

typedef struct { s32 w; } VoiceWord;
typedef struct { s8 id; u8 arg; s16 value; } Marker;
typedef struct { Marker m[4]; u8 count; } MarkerList;
static inline void addMarker(void *voice, MarkerList *list, u32 mask)
{
  u32 flags = *((s32 *) (((char *) voice) + 0x24));
  u8 arg = *((u8 *) (((char *) (&D_800FDBA0)) + 3));
  u8 n;
  if (!(flags & mask) || arg == 0)
  {
    *((s32 *) (((char *) voice) + 0x24)) = flags | mask;
    list->count = 0;
  }
  n = list->count;
  if (n < 4)
  {
    list->count = n + 1;
    list->m[n].id = remapSpecialChar(D_800FDB9E);
    list->m[n].arg = arg;
    list->m[n].value = ((*((s16 *) (&gSeqCommandWord0))) * 256) / 100;
  }
}

static inline void seqBranchAtLeast(void *voice, u16 value)
{
  u32 command = gSeqCommandWord0;
  s32 entry;
  if (value >= D_800FDB9E)
  {
    entry = lookupSortedEntry(command >> 0x10);
    if (entry != 0)
    {
      *((s32 *) (((char *) voice) + 0)) = entry;
      *((void **) (((char *) voice) + 4)) = (void *) (entry + ((*((u16 *) (((char *) (&D_800FDBA0)) + 2))) * 8));
    }
  }
}

static inline s32 voiceOwnsSlot(void *voice, s32 id)
{
  u8 channel;
  u8 bank;
  s32 x;
  s32 y;
  u8 slot;
  if (id != -1)
  {
    channel = *((u8 *) (((char *) voice) + 0x4A));
    if (channel != 0xFF)
    {
      bank = *((u8 *) (((char *) voice) + 0x4B));
      slot = id;
      if (bank == 0xFF)
      {
        if (((u8 *) (&gVoiceIdTable))[slot] == slot)
        {
          return 1;
        }
      }
      else
      {
        u8 (*rows)[16] = (u8 (*)[16]) &gVoiceSlotTable;
        if (rows[bank][channel] == slot)
        {
          return 1;
        }
      }
    }
  }
  return 0;
}

/* Per-tick update for one audio voice: handles start/stop flags, then runs sequence commands (switch on opcode) until one yields or the step budget is spent, and advances the voice timer. */ void audioVoiceTick(void *arg0, s32 arg1, s32 arg2)
{

  union 
  {
    u16 params[4];
    u32 value;
  } scratch;
  volatile u32 frameSpace[12];
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
  u32 v30;
  u32 v39;
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
      deactivateAudioVoice(*((u8 *) (((char *) arg0) + 0x63)));
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
    temp_v0 = getAudioControlValue(*((u8 *) (((char *) arg0) + 0x4A)), *((u8 *) (((char *) arg0) + 0x4B)));
    if ((temp_v0 & 0xFF) != 0xFF)
    {
      *((u8 *) (((char *) arg0) + 0xC1)) = temp_v0;
    }
    else
    {
      *((u8 *) (((char *) arg0) + 0xC1)) = (u8) (*((volatile u16 *) (((char *) arg0) + 0x4E)));
    }
    setClipSlotValue(*((u8 *) (((char *) arg0) + 0x4A)), *((u8 *) (((char *) arg0) + 0x4B)), *((u8 *) (((char *) arg0) + 0x4F)));
    temp_v1_3 = *((s32 *) (((char *) arg0) + 0x60));
    if ((temp_v1_3 != (-1)) && ((temp_a1 = *((u8 *) (((char *) arg0) + 0x4A)), temp_a1 != 0xFF)))
    {
      s8 value = temp_v1_3;
      temp_v0_2 = *((u8 *) (((char *) arg0) + 0x4B));
      if (temp_v0_2 == 0xFF)
      {
        ((s8 *) &gVoiceIdTable)[(u8) value] = value;
      }
      else
      {
        s8 (*rows)[16] = (s8 (*)[16]) &gVoiceSlotTable;
        rows[temp_v0_2][temp_a1] = value;
      }
    }
    *((s32 *) (((char *) arg0) + 0x8C)) = 0;
    var_a1 = *((u8 *) (((char *) arg0) + 0xBF));
    var_a2 = 0;
    *((s32 *) (((char *) arg0) + 0x90)) = 0x64U;
    *((u8 *) (((char *) arg0) + 0x6A)) = 2;
    *((u8 *) (((char *) arg0) + 0x6B)) = 2;
    *((u8 *) (((char *) arg0) + 0x99)) = 0x80;
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
    u8 done;
    gSeqCommandsRun = 1;
        do {
    {
    volatile u32 *commandWord = &gSeqCommandWord0;
    *commandWord = *((u32 *) (((char *) (*((void **) (((char *) arg0) + 4)))) + 0));

    *((u32 *) (((char *) (&D_800FDBA0)) + 0)) = (u32) (*((u32 *) (((char *) (*((void **) (((char *) arg0) + 4)))) + 4)));
    *((void **) (((char *) arg0) + 4)) = (void *) ((*((void **) (((char *) arg0) + 4))) + 8);
    temp_v1_5 = *commandWord & 0x7F;
    }
    switch (temp_v1_5)
    {
      case 0x1:
        if (D_800FDB9E && ((temp_v1_6 = *((s32 *) (((char *) arg0) + 8)), done = 0, temp_v1_6 != 0)))
      {
        *((s32 *) (((char *) arg0) + 0)) = temp_v1_6;
        *((void **) (((char *) arg0) + 4)) = (void *) (*((void **) (((char *) arg0) + 0xC)));
        goto command_test;
      }
      else
      {
        goto release_command;
      }

      case 0x2:
        seqBranchAtLeast(arg0, *((u16 *) (((char *) arg0) + 0x50)));
        commandResult = 0;
        break;

      case 0x3:
        seqBranchAtLeast(arg0, *((u16 *) (((char *) arg0) + 0x30)));
        commandResult = 0;
        break;

      case 0x4:
        commandResult = audioUpdateClipSelection(arg0, &gSeqCommandWord0);
        break;

      case 0x5:
        commandResult = audioVoiceStepTimer(arg0, (u8 *)&gSeqCommandWord0);
        break;

      case 0x6:
        temp_v0_6 = lookupSortedEntry((u32) (*((u16 *) (((char *) (&gSeqCommandWord0)) + 0))));
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
        case 0x0:
        release_command:
        voiceListRemove(arg0);
        releaseAudioVoice(arg0);
        commandResult = 1;
      }
        break;

      case 0x7:
        *((u8 *) (((char *) (&D_800FDBA0)) + 2)) = 1;
        commandResult = audioUpdateClipSelection(arg0, &gSeqCommandWord0);
        break;

      case 0x8:
        commandResult = audioCmdNoteOn(arg0, &gSeqCommandWord0);
        break;

      case 0x9:
      {
        u32 key;
        u32 i;
        u32 h;
        key = ((*((u16 *) (((char *) arg0) + 0x4E))) + D_800FDB9E) << 8;
        key |= (*((u16 *) (((char *) (&gSeqCommandWord0)) + 0))) << 16;
        for (i = 0; i < sVoiceCount; i++)
        {
          var_a2_2 = i * 0x1A0;
          h = *((s32 *) (((char *) (&sSoundVoiceHandle)) + var_a2_2));
          if (h == (key | i))
          {
            if ((s32) h != -1)
            {
              temp_s2_6 = (h & 0xFF); temp_v1_7 = temp_s2_6 * 0x1A0;
              if ((*((s32 *) (((char *) (&sSoundVoiceHandle)) + temp_v1_7))) == h)
              {
                ((VoiceWord *) (((char *) (&sSoundVoiceFlags)) + temp_v1_7))->w |= 8;
              }
            }
          }
        }
        commandResult = 0;
        break;
      }

      case 0xA:
        if ((*((u8 *) (((char *) arg0) + 0x4A))) != 0xFF)
        {
          seqBranchAtLeast(arg0, (evalVoiceModulator1(arg0) >> 7) & 0xFF);
        }
        commandResult = 0;
        break;

      case 0xB:
        temp_a0_2 = ((*((u16 *) (((char *) arg0) + 0x50))) - D_800FDB9D) << 0x10;
        temp_a0_2 = (temp_a0_2 * (((s32) (gSeqCommandWord0 << 0x10)) >> 0x18)) >> 7;
        temp_a0_2 += (((u32) gSeqCommandWord0) >> 0x18) << 0x10;
        var_v1 = (temp_a0_2 < 0) ? 0 : ((temp_a0_2 > 0x7F0000) ? 0x7F0000 : temp_a0_2);
        *((s32 *) (((char *) arg0) + 0x38)) = var_v1; 
        commandResult = 0;
        break;

      case 0xC:
        temp_v0_9 = getCurveTable((((u32) gSeqCommandWord0) >> 8) & 0xFFFF);
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
      }
        commandResult = 0;
        break;

      case 0xD:
        commandResult = updateVoiceLevelEnvelope(arg0, &gSeqCommandWord0);
        break;

      case 0xE:
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) | 0x10000);
        temp_s0 = *((u16 *) (((char *) (&gSeqCommandWord0)) + 0));
        *((s32 *) (((char *) arg0) + 0xA8)) = (s32) temp_s0;
        shiftLeft8InPlace(arg0 + 0xA8);
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
        commandResult = 0;
        break;

      case 0xF:
        var_a2_3 = *((s32 *) (((char *) arg0) + 0x30));
        commandResult = startVoiceParamRamp(arg0, &gSeqCommandWord0, var_a2_3);
        break;

      case 0x10:
        commandResult = audioVoiceApplyEnvelope(arg0, &gSeqCommandWord0);
        break;

      case 0x11:
        resetAudioVoiceEnvelope(*((u8 *) (((char *) arg0) + 0x63)), 1);
        commandResult = 0;
        break;

      case 0x12:
        commandResult = 0;
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) | 0x80);
        break;

      case 0x13:
        seqBranchAtLeast(arg0, randomU16Next() & 0xFF);
        commandResult = 0;
        break;

      case 0x14:
        var_a2_3 = 0;
        commandResult = startVoiceParamRamp(arg0, &gSeqCommandWord0, var_a2_3);
        break;

      case 0x17:
        commandResult = audioStartRandomizedNote(arg0, &gSeqCommandWord0);
        break;

      case 0x18:
        commandResult = adjustVoiceLevelAndRefreshClip(arg0, &gSeqCommandWord0);
        break;

      case 0x19:
      {
        u32 *cmd = &gSeqCommandWord0;
        temp_v1_9 = *((s32 *) (((char *) arg0) + 0x60));
        *((u16 *) (((char *) arg0) + 0x50)) = (u16) (((unsigned) D_800FDB9E) & 0x7F);
        *((u8 *) (((char *) arg0) + 0xC0)) = (s8) (gSeqCommandWord0 >> 16);
        var_v0_2 = voiceOwnsSlot(arg0, temp_v1_9);
        if (var_v0_2 & 0xFF)
      {
        setClipSlotValue(*((u8 *) (((char *) arg0) + 0x4A)), *((u8 *) (((char *) arg0) + 0x4B)), *((u8 *) (((char *) arg0) + 0x51)));
      }
        *cmd = 4;
        commandResult = audioUpdateClipSelection(arg0, &gSeqCommandWord0);
        break;
      }

      case 0x1A:
      {
        u32 *cmd = &gSeqCommandWord0;
        s16 sum;
        *((u16 *) (((char *) arg0) + 0x50)) = (*((u8 *) (((char *) arg0) + 0xC1))) + ((s8) (gSeqCommandWord0 >> 8));
        sum = *((u16 *) (((char *) arg0) + 0x50));
        if ((sum << 16) >= 0)
        {
          temp_v1_10 = sum;
          if (temp_v1_10 >= 0x80)
          {
            temp_v1_10 = 0x7F;
          }
        }
        else
        {
          temp_v1_10 = 0;
        }
        *((u16 *) (((char *) arg0) + 0x50)) = temp_v1_10;
        *((u8 *) (((char *) arg0) + 0xC0)) = (s8) (*((u16 *) (&gSeqCommandWord0)));
        temp_a0_3 = *((u8 *) (((char *) arg0) + 0x4A));
        if (temp_a0_3 != 0xFF)
      {
        setClipSlotValue(temp_a0_3, *((u8 *) (((char *) arg0) + 0x4B)), *((u8 *) (((char *) arg0) + 0x51)));
        *cmd = 4;
      }
      else
      {
        *cmd = 4;
      }
        commandResult = audioUpdateClipSelection(arg0, &gSeqCommandWord0);
        break;
      }

      case 0x1B:
        *((u8 *) (((char *) arg0) + 0x98)) = (s8) (*((u16 *) (&gSeqCommandWord0)));
        scratch.value = ((u32) (*((u32 *) (((char *) (&D_800FDBA0)) + 0)))) >> 0x10;
        if ((((u32) (*((u32 *) (((char *) (&D_800FDBA0)) + 0)))) >> 8) & 1)
      {
        shiftLeft8InPlace(&scratch.value);
      }
      else
      {
        scaleValueByOutputRate(&scratch.value, arg0);
      }
        *((s32 *) (((char *) arg0) + 0x90)) = scratch.value;
        switch (D_800FDB9E)
        {
          case 0:
            *((s32 *) (((char *) arg0) + 0x24)) = (s32) (((*((s32 *) (((char *) arg0) + 0x24))) & (~0x800)) | 0x1000);
            temp_a0_4 = *((u8 *) (((char *) arg0) + 0x4A));
            if (temp_a0_4 != 0xFF)
            {
              setAudioSlotValue(temp_a0_4, *((u8 *) (((char *) arg0) + 0x4B)), 0);
            }
            break;

          case 1:
            if (!((*((s32 *) (((char *) arg0) + 0x24))) & 0x800))
            {
              updateAudioVoiceParams(arg0);
            }
            *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) | 0x1800);
            commandResult = 0;
        break;
        }
        commandResult = 0;
        break;

      case 0x1C:
        commandResult = audioApplyVoiceConfig(arg0, &gSeqCommandWord0);
        break;

      case 0x1D:
        *((s32 *) (((char *) arg0) + 0x40)) = 0;
        temp_v0_17 = ((u32) gSeqCommandWord0) >> 8;
        *((u8 *) (((char *) arg0) + 0x48)) = (s8) temp_v0_17;
        *((u8 *) (((char *) arg0) + 0xB0)) = (s8) temp_v0_17;
      {
        var_v0_4 = *((s16 *) (&gSeqCommandWord0));
        if (var_v0_4 >= 0)
        {
          var_v0_4 = convertRateToFixedPitch(var_v0_4);
        }
        else
        {
          var_v0_4 = -convertRateToFixedPitch(-var_v0_4);
        }
      }
        *((s32 *) (((char *) arg0) + 0x7C)) = (s32) (var_v0_4 << 0x10);
        block_119:
      gSeqCommandWord0 = 0;

        commandResult = audioUpdateClipSelection(arg0, &gSeqCommandWord0);
        break;

      case 0x1E:
        *((s32 *) (((char *) arg0) + 0x44)) = 0;
        temp_v0_18 = ((u32) ((s32) gSeqCommandWord0)) >> 8;
        *((u8 *) (((char *) arg0) + 0x49)) = (s8) temp_v0_18;
        *((u8 *) (((char *) arg0) + 0xB1)) = (s8) temp_v0_18;
      {
        var_v0_5 = *((s16 *) (&gSeqCommandWord0));
        if (var_v0_5 >= 0)
        {
          var_v0_5 = convertRateToFixedPitch(var_v0_5);
        }
        else
        {
          var_v0_5 = -convertRateToFixedPitch(-var_v0_5);
        }
      }
        *((s32 *) (((char *) arg0) + 0x80)) = (s32) (var_v0_5 << 0x10);
      {
        gSeqCommandWord0 = 0;
        commandResult = audioUpdateClipSelection(arg0, &gSeqCommandWord0);
        break;
      }

      case 0x1F:
        commandResult = computeVoicePitchKey(arg0, &gSeqCommandWord0);
        break;

      case 0x28:
        temp_v0_19 = lookupSortedEntry((u32) (*((u16 *) (((char *) (&gSeqCommandWord0)) + 0))));
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
        temp_v1_11 = (((u32) (*((s32 *) (((char *) arg0) + 0x28)))) >> 0xF) + (*((s16 *) (((char *) (&gSeqCommandWord0)) + 0)));
        if (temp_v1_11 < 0)
      {
        *((s32 *) (((char *) arg0) + 0x28)) = 0U;
      }
      else
      {
        if (temp_v1_11 > 0xFFFF)
        {
          v30 = 0x7FFF8000;
        }
        else
        {
          v30 = temp_v1_11 << 0xF;
        }
        *((s32 *) (((char *) arg0) + 0x28)) = v30;
      }
        commandResult = 0;
        break;

      case 0x31:
        commandResult = 0;
        *((s32 *) (((char *) arg0) + 0x28)) = (u32) ((*((u16 *) (((char *) (&gSeqCommandWord0)) + 0))) << 0xF);
        break;

      case 0x32:
        *((s16 *) (((char *) (&gLockedSlotTable)) + (D_800FDB9E * 2))) = (s16) D_800FDB9D;
        commandResult = 0;
        break;

      case 0x33:
        *((u8 *) (((char *) arg0) + 0x6A)) = (s8) (*((u16 *) (&gSeqCommandWord0)));
        commandResult = 0;
        *((u8 *) (((char *) arg0) + 0x6B)) = (s8) (((u32) gSeqCommandWord0) >> 8);
        break;

      case 0x34:
        *((u8 *) (((char *) arg0) + 0x99)) = (s8) (((u32) gSeqCommandWord0) >> 8);
        commandResult = 0;
        *((u8 *) (((char *) arg0) + 0x9A)) = (s8) (*((u16 *) (&gSeqCommandWord0)));
        break;

      case 0x35:
        commandResult = 0;
        *((s32 *) (((char *) arg0) + 0x24)) = (s32) ((*((s32 *) (((char *) arg0) + 0x24))) | 0x40000);
        break;

      case 0x36:
        linkVoiceIntoGroup(arg0, D_800FDB9E);
        commandResult = 0;
        break;

      case 0x37:
      {
        u16 lv;
        temp_v0_20 = *((u16 *) (&gSeqCommandWord0));
        lv = (*((u8 *) (((char *) arg0) + 0x2E))) + temp_v0_20;
        temp_v0_20 = lv;
        if (temp_v0_20 >= 0)
        {
          if (temp_v0_20 >= 0x100)
          {
            lv = 0xFF;
          }
        }
        else
        {
          lv = 0;
        }
        linkVoiceIntoGroup(arg0, lv & 0xFF);
        commandResult = 0;
        break;
      }

      case 0x38:
        if ((*((u32 *) (((char *) (&D_800FDBA0)) + 0))) != 0)
      {
        *((u16 *) (((char *) arg0) + 0x2C)) = (s16) (((u32) (((u32) (*((s32 *) (((char *) arg0) + 0x28)))) >> 8)) / ((u32) (*((u32 *) (((char *) (&D_800FDBA0)) + 0)))));
      }
      else
      {
        *((u16 *) (((char *) arg0) + 0x2C)) = 0;
      }
        commandResult = 0;
        break;

      case 0x39:
        temp_v1_12 = (*((u16 *) (&gSeqCommandWord0))) + (((u32) ((*((u16 *) (((char *) arg0) + 0x30))) * (*((u16 *) (((char *) (&D_800FDBA0)) + 2))))) >> 7);
        if (temp_v1_12 <= 0xEA60U)
      {
        *((s32 *) (((char *) arg0) + 0x28)) = temp_v1_12 << 0xF;
      }
      else
      {
        *((s32 *) (((char *) arg0) + 0x28)) = 0x75300000;
      }
      {
        commandResult = 0;
        break;
      }

      case 0x40:
        addMarker(arg0, (MarkerList *) (((char *) arg0) + 0xC4), 0x200000);
        commandResult = 0;
        break;

      case 0x41:
        addMarker(arg0, (MarkerList *) (((char *) arg0) + 0xD6), 0x400000);
        commandResult = 0;
        break;

      case 0x42:
        addMarker(arg0, (MarkerList *) (((char *) arg0) + 0xFA), 0x800000);
        commandResult = 0;
        break;

      case 0x43:
        addMarker(arg0, (MarkerList *) (((char *) arg0) + 0x11E), 0x1000000);
        commandResult = 0;
        break;

      case 0x44:
        addMarker(arg0, (MarkerList *) (((char *) arg0) + 0x130), 0x8000000);
        commandResult = 0;
        break;

      case 0x45:
        addMarker(arg0, (MarkerList *) (((char *) arg0) + 0x142), 0x4000000);
        commandResult = 0;
        break;

      case 0x46:
        addMarker(arg0, (MarkerList *) (((char *) arg0) + 0x154), 0x2000000);
        commandResult = 0;
        break;

      case 0x47:
        addMarker(arg0, (MarkerList *) (((char *) arg0) + 0xE8), 0x10000000);
        commandResult = 0;
        break;

      case 0x48:
        addMarker(arg0, (MarkerList *) (((char *) arg0) + 0x10C), 0x20000000);
        commandResult = 0;
        break;

      case 0x50:
      {
        u8 slot = ((u32) gSeqCommandWord0) >> 8;
        scratch.value = ((u32) gSeqCommandWord0) >> 0x10;
        shiftLeft8InPlace(&scratch.value);
        var_a2_2 = (slot * 0xC); temp_v1_22 = arg0 + var_a2_2;
      }
        if ((*((s32 *) (((char *) temp_v1_22) + 0x16C))) != 0)
      {
        *((s32 *) (((char *) temp_v1_22) + 0x168)) = 0;
      }
        commandResult = 0;
        *((s32 *) (((char *) temp_v1_22) + 0x16C)) = scratch.value;
        break;

      case 0x60:
        commandResult = seqExecArithmetic(arg0, &gSeqCommandWord0, 0);
        break;

      case 0x61:
        commandResult = seqExecArithmetic(arg0, &gSeqCommandWord0, 1);
        break;

      case 0x62:
        commandResult = seqExecArithmetic(arg0, &gSeqCommandWord0, 2);
        break;

      case 0x63:
        commandResult = seqExecArithmetic(arg0, &gSeqCommandWord0, 3);
        break;

      case 0x64:
        commandResult = seqExecArithmetic(arg0, &gSeqCommandWord0, 4);
        break;

      case 0x65:
      {
        u16 data;
        u8 idx;
        u8 flag = ((u32) gSeqCommandWord0) >> 8;
        temp_v1_23 = ((u32) gSeqCommandWord0) >> 0x10;
        temp_a0 = D_800FDBA0;
        data = temp_a0;
        idx = temp_v1_23;
        if (flag)
      {
        seqWriteIndirectVar(arg0, idx & 0xFF, (s16) temp_a0);
        commandResult = 0;
      }
      else
      {
        temp_v1_23 = temp_v1_23 & 0x1F;
        if (temp_v1_23 < 0x10U)
        {
          ((u16 *) ((char *) arg0 + 0x180))[temp_v1_23] = data;
          commandResult = 0;
        break;
        }
        ((s16 *) &gSeqGlobalVars)[temp_v1_23] = data;
        commandResult = 0;
      }
        break;
      }

      case 0x70:
        commandResult = seqCmdCompareBranch(arg0, &gSeqCommandWord0, 0);
        break;

      case 0x71:
        commandResult = seqCmdCompareBranch(arg0, &gSeqCommandWord0, 1);
        break;

      default:
        done = 0;
        goto command_test;
    }
    done = commandResult;
    command_test:

    if (done & 0xFF)
      break;
    } while (++gSeqCommandsRun < 0x21);
    *((s32 *) (((char *) arg0) + 0xA4)) = (u32) ((*((s32 *) (((char *) arg0) + 0xA4))) + gAudioTickStep);
    return;
  }
  temp_a0_23 = *((s32 *) (((char *) arg0) + 0x24));
  *((s32 *) (((char *) arg0) + 0xA4)) = (u32) ((*((s32 *) (((char *) arg0) + 0xA4))) + gAudioTickStep);
  if (temp_a0_23 & 4)
  {
    if (!(temp_a0_23 & 0x40000000))
    {
      if (temp_a0_23 & 8)
      {
          *((s32 *) (((char *) arg0) + 0x24)) = temp_a0_23 & (~4);
          *((s32 *) (((char *) arg0) + 0x9C)) = 0U;
          *((s32 *) (((char *) arg0) + 0xA0)) = (u32) (*((s32 *) (((char *) arg0) + 0xA4)));
        }
    }
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








