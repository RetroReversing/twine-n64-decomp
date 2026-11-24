s32 setClipSlotValue();
s32 audioUpdateClipSelection();
extern char D_801007D9[];
extern u8 D_80100C7C[];
/* Adds the event's signed delta to the voice level (clamped 0..127), then refreshes the clip selection. */ s32 adjustVoiceLevelAndRefreshClip(void *voice, u32 *event)
{
  volatile s32 stack_pad[4];
  char *base;
  s32 temp_v0;
  s32 clipId;
  s32 signed_v;
  s16 level;
  u32 packed;
  u8 temp_a1;
  u8 temp_v0_2;
  s32 lookedUp;
  packed = *event;
  if ((packed >> 24) == 0)
  {
    level = *((u16 *) (((char *) voice) + 0x50));
  }
  else
  {
    level = *((u16 *) (((char *) voice) + 0x4E));
  }
  if (temp_a1)
  {
    level += ((s32) (packed << 16)) >> 24;
    *((volatile s16 *) (((char *) voice) + 0x50)) = level;
    temp_v0 = *((s16 *) (((char *) voice) + 0x50));
  }
  else
  {
    level += ((s32) (packed << 16)) >> 24;
    *((volatile s16 *) (((char *) voice) + 0x50)) = level;
    temp_v0 = *((s16 *) (((char *) voice) + 0x50));
  }
  if (temp_v0 >= 0)
  {
    level = temp_v0;
    if (((u32) level) >= 0x80U)
    {
      level = 0x7F;
      goto block_9;
    }
    *((u16 *) (((char *) voice) + 0x50)) = level;
  }
  else
  {
    level = 0;
    block_9:
    *((u16 *) (((char *) voice) + 0x50)) = level;

  }
  clipId = *((s32 *) (((char *) voice) + 0x60));
  *((s8 *) (((char *) voice) + 0xC0)) = (s8) (*((u16 *) event));
  if ((-1) != clipId)
  {
    do
    {
      temp_a1 = *((u8 *) (((char *) voice) + 0x4A)); temp_v0 = 0;
    }
    while (0);
    if (temp_a1 != 0xFF)
    {
      temp_v0_2 = *((u8 *) (((char *) voice) + 0x4B));
      {
        u8 clip = clipId;
        if (temp_v0_2 == 0xFF)
        {
          lookedUp = clip; temp_v0 = D_80100C7C[clip];
        }
        else
        {
          base = D_801007D9; lookedUp = (u8) *(((temp_v0_2 * 0x10) + base) + temp_a1); temp_v0 = clip;
        }
      }
      if (lookedUp == temp_v0)
      {
        temp_v0 = 1;
      }
      else
      {
        temp_v0 = 0;
      }
    }
  }
  else
  {
    temp_v0 = 0;
  }
  if (temp_v0 & 0xFF)
  {
    setClipSlotValue(*((u8 *) (((char *) voice) + 0x4A)), *((u8 *) (((char *) voice) + 0x4B)), *((u8 *) (((char *) voice) + 0x51)));
  }
  *event = 4;
  return audioUpdateClipSelection(voice, event) & 0xFF;
}


