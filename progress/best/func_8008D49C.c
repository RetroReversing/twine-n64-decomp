typedef struct 
{
  u16 id;
  s8 note;
  u8 velocity;
  s16 adjustment;
  u16 pad;
} SoundMapping;
extern s32 func_8008CEB0(s32, s32, s32);
extern s32 func_8008D138(u32, u32, s32, u8, s32, s32, s32, u16, u16, u8);
extern s32 func_80096970(s32, s32);
extern const SoundMapping *func_800984CC(u32);
extern s32 func_8009C420(u32, u32, s32, u8, s32, s32, s32, u16, u16, s32, u8);
inline static s32 tryMappedBank(s32 key, u8 bank, u8 channel)
{
  s32 bankIndex = bank & 0xff;
  s32 channelIndex;
  s32 result;
  if (bankIndex != 255)
  {
    channelIndex = channel & 0xff;
    if (func_80096970(bankIndex, channelIndex) & 0xff)
    {
      result = func_8008CEB0(key & 0x7f, bankIndex, channelIndex);
      if (result != (-1))
        return result;
    }
  }
  return -1;
}

s32 func_8008D49C(u32 packed, s32 key, u8 mode, s32 velocity, u8 bank, u8 channel, u16 param6, u16 param7, u8 param8, s16 adjustment)
{
  u32 originalId = ((unsigned short) packed) >> 16;
  s32 level = ((packed >> 8) & 0xff) + adjustment;
  s32 result;
  s32 clampedLevel;
  s32 clampedLevel_arm;
  s32 clampedKey;
  s32 adjustedVelocity;
  s32 loadedId;
  s32 mappedKey;
  s32 index;
  u16 mappedId;
  const SoundMapping *mapping;
  if (level >= 0)
  {
    clampedLevel = 255;
    if (level < 256)
    {
      clampedLevel = level;
    }
  }
  else
  {
    clampedLevel = 0;
  }
  level = clampedLevel;
  packed = (packed & 0xffff00ff) | (level << 8);
  switch ((s32) (originalId & 0xc000))
  {
    case 0:
      result = tryMappedBank(key, bank, channel);
      if (result != (-1))
    {
      goto done;
    }
      return func_8009C420(packed, packed >> 16, key & 0xff, mode, velocity & 0xff, bank, channel, param6, param7, 1, param8);

    case 0x4000:
      mapping = func_800984CC(originalId);
      index = key & 0x7f;
      if (!mapping)
    {
      return -1;
    }
      loadedId = mapping[index].id;
      if (loadedId == 0xffff)
    {
      return -1;
    }
      if (!(mapping[index].velocity & 0x80))
    {
      adjustedVelocity = mapping[key & 0xff].velocity - 0x40;
      adjustedVelocity += velocity & 0xff;
      if (adjustedVelocity < 0)
      {
        velocity = 0;
      }
      else
        if (adjustedVelocity < 0x80)
      {
        velocity = adjustedVelocity;
      }
      else
      {
        velocity = 0x7f;
      }
    }
    else
    {
      velocity = 0x80;
    }
      mappedKey = (key & 0x7f) + mapping[index].note;
      if (mappedKey < 0x80)
    {
      clampedKey = mappedKey & ((~mappedKey) >> 31);
    }
    else
    {
      clampedKey = 0x7f;
    }
      mappedKey = clampedKey;
      level += mapping[index].adjustment;
      if (level < 0x100)
    {
      clampedLevel_arm = level & ((~level) >> 31);
    }
    else
    {
      clampedLevel_arm = 0xff;
    }
      packed &= 0xff;
      mappedId = *((const volatile u16 *) (&mapping[index].id));
      packed |= clampedLevel_arm << 8;
      packed |= ((u32) mappedId) << 16;
      if (!(mappedId & 0xc000))
    {
      result = tryMappedBank(mappedKey, bank, channel);
      if (result != (-1))
      {
        goto done;
      }
      return func_8009C420(packed, originalId, (mappedKey | (key & 0x80)) & 0xff, mode, velocity & 0xff, bank, channel, param6, param7, 1, param8);
    }
      return func_8008D138(packed, originalId, (mappedKey | (key & 0x80)) & 0xff, mode, velocity & 0xff, bank, channel, param6, param7, param8);

    case 0x8000:
      return func_8008D138(packed, packed >> 16, key & 0xff, mode, velocity & 0xff, bank, channel, param6, param7, param8);

    default:
      return -1;

  }

  done:
  return result;

}

