s32 func_8008C1B0(s32);
s32 func_80095EC4(s32, s32);
s32 lookupSortedEntry(u32 arg0);
void func_8009876C(void *);
s32 allocVoiceSerial(void *);
void linkVoiceIntoGroup(void *, s32);
s32 allocVoiceSlot(s32, s32, s32, u32);
extern u8 D_8010D724[];
inline static int inline_fn(unsigned char arg0)
{
  return arg0 & 0xFF;
}

inline static int inline_fn2(s32 arg0)
{
  return arg0 & 0xFF;
}

/* Allocates a voice slot, initialises it from the sound data and parameters, and returns the voice id (or starts it immediately when playNow is set); returns -1 on failure. */ s32 startVoice(u32 arg0_in, s32 arg1_in, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u16 arg7, u16 arg8, u8 playNow, u8 arg10)
{
  s32 arg1;
  u32 arg0;
  u32 bankHi;
  unsigned char lo;
  s32 soundData;
  u8 volume;
  s32 var_v0;
  u32 bankId;
  unsigned char priority;
  s32 slotIdx;
  u8 *voice;
  s16 temp_v0_3;
  arg1 = arg1_in;
  arg0 = arg0_in;
  lo = arg0_in;
  volume = arg2;
  priority = (arg0 >> 1) >> 7;
  bankId = arg0 >> 0x10;
  soundData = lookupSortedEntry(bankId);
  if (soundData != 0)
  {
    {
      {
        slotIdx = allocVoiceSlot(inline_fn(priority), inline_fn(lo), arg1 & 0xFFFF, ((u32) inline_fn(volume)) >> 7);
        if (slotIdx != (-1))
        {
          voice = D_8010D724 + (slotIdx * 0x1A0);
          func_8009876C(voice);
          *((s32 *) (voice + 0x24)) = ((*((s32 *) (voice + 0x24))) & 0x10) | 2;
          if (func_8008C1B0(slotIdx) & 0xFF)
          {
            *((s32 *) (voice + 0x24)) = (*((s32 *) (voice + 0x24))) | 1;
          }
          *((s32 *) (voice + 0x9C)) = 0;
          if (arg2 & 0x80)
          {
            volume = arg2 & 0x7F;
            *((s8 *) (voice + 0x4C)) = 1;
            func_80095EC4(slotIdx & 0xFF, 0xFF);
            *((u8 *) (voice + 0x54)) = slotIdx;
            *((u8 *) (voice + 0x55)) = 0xFF;
          }
          else
          {
            *((s8 *) (voice + 0x4C)) = 0;
            *((u8 *) (voice + 0x54)) = arg5;
            *((u8 *) (voice + 0x55)) = arg6;
          }
          *((s32 *) (voice + 0x28)) = 0x75300000;
          *((s16 *) (voice + 0x64)) = bankId;
          *((s16 *) (voice + 0xBA)) = arg1;
          *((s16 *) (voice + 0x2C)) = 0x400;
          { *((s32 *) (voice + 0)) = soundData; }
          *((s32 *) (voice + 4)) = soundData + (arg7 * 8);
          ;
bankHi = bankId << 0x10;
*((s16 *) (voice + 0x4E)) = volume;
*((s16 *) (voice + 0x50)) = volume;
*((s8 *) (voice + 0xC0)) = 0;
*((u8 *) (voice + 0x52)) = arg3;
*((u8 *) (voice + 0x53)) = arg4;
*((u8 *) (voice + 0x56)) = inline_fn(arg8);
*((s32 *) (voice + 0x10)) = -1;
*((s32 *) (voice + 0x14)) = -1;
*((s32 *) (voice + 8)) = 0;
*((u8 *) (voice + 0xBF)) = arg10;
          *((s32 *) (voice + 0x60)) = (bankHi | (inline_fn(volume) << 8)) | slotIdx;
          {
            linkVoiceIntoGroup(voice, inline_fn(priority));
          }
          if (playNow != 0)
          {
            if (1)
            {
              return allocVoiceSerial(voice);
            }
          }
          return *((s32 *) (voice + 0x60));
        }
      }
    }
  }
  return -1;
}


