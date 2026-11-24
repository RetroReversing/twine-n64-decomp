void rampSoundChannelLocked(s32, s32, s32);
/* Sets the sound channel volume from a 0-10 level, scaled to 0-127. */ void setSoundVolumeTenths(s32 volumeTenths) {
    u32 scaledVolume = (u32)(volumeTenths * 127);
    rampSoundChannelLocked((scaledVolume / 10) & 0xFF, 0, 0);
}
