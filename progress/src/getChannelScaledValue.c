extern s32 gAudioChannelScaledValues[];

/* Returns the scaled value for the channel's index (byte 0x4B), using slot 8 when the index is 0xFF. */ s32 getChannelScaledValue(u8 *channel) {
    s32 *scaledValues = gAudioChannelScaledValues;
    u8 index = channel[0x4B];
    s32 *entry;

    if (index != 0xFF) {
        entry = &scaledValues[index];
    } else {
        entry = &scaledValues[8];
    }
    return *entry;
}
