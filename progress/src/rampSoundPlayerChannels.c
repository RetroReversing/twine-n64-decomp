void setSoundChannelRamp(u8, u16, u8, u8, s32);
extern unsigned char gSoundEntities[];
extern unsigned char D_800E5FEC[];
extern unsigned char D_800E6A85[];
extern unsigned char D_800E6A88[];
extern unsigned char D_800E6AA4[];
extern unsigned char D_800E6AB2[];
extern unsigned char D_800E6AB4[];
/* Finds the sound player whose key matches playerKey and ramps its channels to the target volume (or, for keys with the high bit set, applies a mode-specific flag update). */ void rampSoundPlayerChannels(s32 targetVolume, s32 duration, s32 playerKey, s32 mode)
{
  s32 keyId;
  s32 __repair_phase_temp_a2_2;
  s32 __repair_phase_temp_a3;
  s32 originalKey = playerKey;
  s32 var_v0;
  s32 __repair_phase_var_v0;
  s8 var_v1_2;
  u32 playerIdx;
  u8 channelVol;
  void *channelEnd;
  s32 scanOffset;
  playerIdx = 0;
  keyId = playerKey & 0x7FFFFFFF;
  scanOffset = 0;
  do
  {
    if ((D_800E6A85[scanOffset] == 0) && ((*((s32 *) (gSoundEntities + scanOffset))) == keyId))
    {
      playerKey = playerIdx | (playerKey & 0x80000000);
      goto found;
    }
    playerIdx++;
    scanOffset += 0xFF8;
  }
  while (playerIdx < 8U);
  playerKey = -1;
  found:
  if (playerKey != (-1))
  {
    u32 firstSound = targetVolume & 0xFF;
    if (playerKey >= 0)
    {
      unsigned char *cursor;
      playerIdx = (u32)playerKey << 9;
      playerIdx -= playerKey;
      playerIdx <<= 3;
      setSoundChannelRamp(firstSound, duration & 0xFFFF, *(D_800E6A88 + playerIdx), mode & 0xFF, originalKey);
      do
      {
 do { __repair_phase_temp_a2_2 = playerIdx; cursor = D_800E5FEC + __repair_phase_temp_a2_2; } while (0);
        channelEnd = (void *) (cursor + 0x40);
      }
      while (0);
      do
      {
        channelVol = *cursor;
        if (channelVol != (*(D_800E6A88 + __repair_phase_temp_a2_2)))
        {
          setSoundChannelRamp(targetVolume & 0xFF, duration & 0xFFFF, channelVol, 0, 0);
        }
        cursor += 1;
      }
      while (((u32) cursor) < ((u32) channelEnd));
    }
    else
    {
      playerKey = playerKey & 0x7FFFFFFF;
      __repair_phase_temp_a3 = mode & 0xF;
      switch (__repair_phase_temp_a3)
      {
        case 0:
          *(D_800E6AA4 + (playerKey * 0xFF8)) = targetVolume;
          return;

        case 1:
          *((s32 *) (D_800E6AB4 + (playerKey * 0xFF8))) = 0;
          return;

        case 2:
          var_v0 = playerKey * 0xFF8;
          *(D_800E6AA4 + var_v0) = targetVolume;
          var_v1_2 = (*(D_800E6AB2 + var_v0)) | 8;
          *(D_800E6AB2 + var_v0) = var_v1_2;
          break;

        case 3:
          __repair_phase_var_v0 = playerKey * 0xFF8;
          *(D_800E6AA4 + __repair_phase_var_v0) = targetVolume;
          var_v1_2 = (*(D_800E6AB2 + __repair_phase_var_v0)) | 0x80;
          *(D_800E6AB2 + __repair_phase_var_v0) = var_v1_2;
          break;

      }

    }
  }

}



