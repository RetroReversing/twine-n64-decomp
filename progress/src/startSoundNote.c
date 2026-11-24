typedef struct 
{
  u16 id;
  s8 note;
  u8 velocity;
  s16 adjustment;
  u16 pad;
} SoundMapping;
extern s32 retargetMatchingVoices(s32, s32, s32);
extern s32 startSoundRegionVoices(u32, u32, s32, u8, s32, s32, s32, u16, u16, u8);
extern s32 voiceLookupSlot(s32, s32);
extern const SoundMapping *getSoundMappingTable(u32);
extern s32 startVoice(u32, u32, s32, u8, s32, s32, s32, u16, u16, s32, u8);
inline static s32 tryMappedBank(u8 key, u8 bank, u8 channel)
{
  s32 bankIndex = bank & 0xff;
  s32 channelIndex;
  s32 result;
  if (bankIndex != 255)
  {
    channelIndex = channel & 0xff;
    if (voiceLookupSlot(bankIndex, channelIndex) & 0xff)
    {
      result = retargetMatchingVoices(key & 0x7f, bankIndex, channelIndex);
      if (result != (-1))
        return result;
    }
  }
  return -1;
}

/* Starts a sound note: clamps volume, resolves layered key mappings by sound type, then plays it through a bank voice or a sequence player. */
s32 startSoundNote(u32 soundRef, u8 noteKey, u8 playMode, s32 velocity, u8 bank, u8 channel, u16 arg6, u16 arg7, u8 arg8, s16 adjustment)
{
  u16 soundId = soundRef >> 16;
  s32 volumeLevel = ((soundRef >> 8) & 0xff) + adjustment;
  s32 result;
  s32 clampedVolume;
  s32 clampedMappedVolume;
  s32 clampedKey;
  s32 mappedVelocity;
  s32 inRange;
  s32 mappingId;
  s32 mappedKey;
  s32 keyIndex;
  u16 mappedId;
  const SoundMapping *mappingTable;
  if (volumeLevel >= 0)
  {
    clampedVolume = 255;
    if (volumeLevel < 256)
    {
      clampedVolume = volumeLevel;
    }
  }
  else
  {
    clampedVolume = 0;
  }
  volumeLevel = clampedVolume;
  soundRef = (soundRef & 0xffff00ff) | (volumeLevel << 8);
  switch ((s32) (soundId & 0xc000))
  {
    case 0:
      result = tryMappedBank(noteKey, bank, channel);
      if (result != (-1))
    {
      goto done;
    }
      return startVoice(soundRef, soundRef >> 16, noteKey, playMode, velocity & 0xff, bank, channel, arg6, arg7, 1, arg8);

    case 0x4000:
      mappingTable = getSoundMappingTable(soundId);
      keyIndex = noteKey & 0x7f;
      if (!mappingTable)
    {
      return -1;
    }
      mappingId = mappingTable[keyIndex].id;
      if (mappingId == 0xffff)
    {
      return -1;
    }
      if (!(mappingTable[keyIndex].velocity & 0x80))
    {
      mappedVelocity = mappingTable[noteKey].velocity - 0x40;
      mappedVelocity += velocity & 0xff;
      inRange = mappedVelocity < 0x80; if (mappedVelocity < 0) velocity = 0; else if (!inRange) velocity = 0x7f; else velocity = mappedVelocity;
    }
    else
    {
      velocity = 0x80;
    }
      mappedKey = (noteKey & 0x7f) + mappingTable[keyIndex].note;
      if (mappedKey < 0x80)
    {
      clampedKey = mappedKey & ((~mappedKey) >> 31);
    }
    else
    {
      clampedKey = 0x7f;
    }
      mappedKey = clampedKey;
      volumeLevel += mappingTable[keyIndex].adjustment;
      if (volumeLevel < 0x100)
    {
      clampedMappedVolume = volumeLevel & ((~volumeLevel) >> 31);
    }
    else
    {
      clampedMappedVolume = 0xff;
    }
      soundRef &= 0xff;
      mappedId = *((const volatile u16 *) (&mappingTable[keyIndex].id));
      soundRef |= clampedMappedVolume << 8;
      soundRef |= ((u32) mappedId) << 16;
      if (!(mappedId & 0xc000))
    {
      result = tryMappedBank(mappedKey, bank, channel);
      if (result != (-1))
      {
        goto done;
      }
      return startVoice(soundRef, soundId, (mappedKey | (noteKey & 0x80)) & 0xff, playMode, velocity & 0xff, bank, channel, arg6, arg7, 1, arg8);
    }
      return startSoundRegionVoices(soundRef, soundId, (mappedKey | (noteKey & 0x80)) & 0xff, playMode, velocity & 0xff, bank, channel, arg6, arg7, arg8);

    case 0x8000:
      return startSoundRegionVoices(soundRef, soundRef >> 16, noteKey, playMode, velocity & 0xff, bank, channel, arg6, arg7, arg8);

    default:
      return -1;

  }

  done:
  return result;

}
