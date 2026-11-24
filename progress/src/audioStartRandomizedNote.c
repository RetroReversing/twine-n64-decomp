s32 randomU16Next();
void setClipSlotValue();
s32 audioUpdateClipSelection();
extern u8 gVoiceSlotTable[];
extern u8 gVoiceIdTable[];
inline static u8 isClipActive(u8 *voice, s32 curClip)
{
  u8 b4a;
  u8 b4b;
  u32 x;
  u32 y;
  if (curClip == (-1))
    return 0;
  b4a = voice[0x4A];
  if (b4a == 0xFF)
    return 0;
  b4b = voice[0x4B];
  y = curClip;
  curClip = 0;
  curClip = y;
  if (b4b == 0xFF)
  {
    if (gVoiceIdTable[(u8)y] != (u8)y)
      return 0;
    return 1;
  }
  else
  {
    u8 *t = gVoiceSlotTable;
    u32 off = b4b << 4;
    u8 *row = t + off;
    x = row[b4a];
    if (x == (u8)y)
      return 1;
    return 0;
  }
}

inline static s32 lowByte(u32 arg0)
{
  return (s32) (arg0 & 0xFF);
}

/* Picks a random key within the command's range (and random pitch if requested), stores it in the voice, re-triggers the clip if still selected, then updates the clip selection. */
s32 audioStartRandomizedNote(u8 *voice, u8 *cmd)
{
  volatile u64 pad;
  u16 maxKey;
  u16 minKey;
  s32 pitchOffset;
  s32 randOffset;
  s32 curClip;
  if (cmd[6] == 0)
  {
    u32 w = *((u32 *) cmd);
    minKey = (u16)(w >> 8);
    maxKey = (u16)(w >> 24);
    if ((u8)maxKey < (u8)minKey)
    {
      u16 tmp = minKey;
      minKey = maxKey; maxKey = tmp;
    }
  }
  else
  {
    u32 t = *((u16 *) (voice + 0x50));
    s32 a = t + cmd[0];
    unsigned short d = (unsigned short) (t - cmd[2]);
    if (((s16) d) >= 0)
    {
      minKey = 0x7F;
      if (((s16) d) < 0x80)
      {
        minKey = d;
      }
    }
    else
    {
      minKey = 0;
    }
    if (((s16) a) >= 0)
    {
      maxKey = 0x7F;
      if (((s16) a) < 0x80)
      {
        maxKey = a;
      }
    }
    else
    {
      maxKey = 0;
    }
  }
  if (cmd[7] != 0)
  {
    u32 x = randomU16Next() & 0xFFFF;
    pitchOffset = (x % 201) - 100;
  }
  else
  {
    pitchOffset = cmd[1];
  }
  randOffset = randomU16Next();
  randOffset = (u16)randOffset % ((((s32) (maxKey & 0xFF)) - lowByte(minKey)) + 1);
  *((s32 *) (cmd + 4)) = 0;
  {
    u32 q = ((lowByte(minKey) + randOffset) << 8) | 0x19;
    *((s32 *) cmd) = ((pitchOffset & 0xFF) << 16) | q;
  }
  curClip = *((s32 *) (voice + 0x60));
  *((s16 *) (voice + 0x50)) = cmd[2] & 0x7F;
  voice[0xC0] = *((u16 *) cmd);
  if (isClipActive(voice, curClip))
  {
    setClipSlotValue(voice[0x4A], voice[0x4B], voice[0x51]);
  }
  *((s32 *) cmd) = 4;
  audioUpdateClipSelection(voice, cmd);
  return 0;
}
