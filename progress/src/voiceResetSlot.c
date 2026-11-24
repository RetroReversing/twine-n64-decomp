extern u8 *gAudioVoiceTable;
#define FIELD(p, T, off) (*(T *)((u8 *)(p) + (off)))
/* Resets an active audio voice slot: restarts its 0x14 counter, and either clears a pending flag or reinitializes its envelope state. */ void voiceResetSlot(s32 voiceIndex) {
    u8 *voiceTable;
    void *voice;
    voiceTable = gAudioVoiceTable;
    voice = (void *)((u32)(voiceIndex * 0x68) + (u32)voiceTable);
    if (FIELD(voice, u8, 0) != 0) {
        FIELD(voice, u16, 0x28) = 0x14U;
        if (FIELD(voice, u8, 1) != 0) {
            FIELD(voice, u8, 1) = 0U;
            return;
        }
        FIELD(voice, s8, 0x5C) = 3;
        FIELD(voice, s32, 0x54) = 0;
        FIELD(voice, s32, 0x50) = 0;
        FIELD(voice, f32, 0x58) = (f32) FIELD(voice, f32, 0x4C);
        FIELD(voice, u16, 0x48) = (u16) FIELD(voice, u16, 0x28);
    }
}
