void rampSoundChannelLocked(s32,s32,s32);
/* Scales a 0-10 volume level to 0-127 and ramps sound channels 0xFD and 1 to it. */ void setVolumeLevel(u32 level) { u8 volume = (level * 127) / 10; rampSoundChannelLocked(volume,0,0xfd); rampSoundChannelLocked(volume,0,1); }
