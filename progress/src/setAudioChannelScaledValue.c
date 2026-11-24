extern s32 gAudioChannelScaledValues;
/* Stores value scaled by 512/10 into the channel's slot; channel 255 maps to slot 8. */
void setAudioChannelScaledValue(s32 value, s32 channel) {
    unsigned int slot = channel;
    if ((slot & 255) == 255) slot = 8;
    *((s32 *)((s8 *)&gAudioChannelScaledValues + ((slot & 255) * 4))) = (((unsigned)value << 3) * 3 << 9) / 240;
}
