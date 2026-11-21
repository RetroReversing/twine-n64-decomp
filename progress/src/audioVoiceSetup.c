#ifndef M2C_DEFINES
#define M2C_DEFINES
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#endif

extern f64 D_800D67A0;
extern s32 gAudioVoiceTable;

/* Resets audio voice record voiceId and copies the sample descriptor (start, cursor, end, loop) into it; resetGain requests a gain reset. */
void audioVoiceSetup(s32 voiceId, void *desc, s32 resetGain) {
    f64 posFrac;
    s32 descCursor;
    s32 loopLen;
    s32 descEnd;
    u32 remainder;
    void *gainVoice;
    void *descVoice;
    void *remainVoice;
    void *voice;
    void *voiceFlags;
    s32 voiceOffset;

    voice = (void *)(gAudioVoiceTable + ((voiceId & 0xFFFF) * 0x68));
    M2C_FIELD(voice, s16 *, 4) = 0x1000;
    M2C_FIELD(voice, s8 *, 0) = 0;
    M2C_FIELD(voice, s16 *, 2) = 0;
    M2C_FIELD(voice, s8 *, 1) = 1;
    M2C_FIELD(voice, s16 *, 0x18) = 0;
    M2C_FIELD(voice, s16 *, 0x1A) = 0;
    M2C_FIELD(voice, s16 *, 0x1C) = 0;
    M2C_FIELD(voice, s16 *, 0x1E) = 0;
    M2C_FIELD(voice, s16 *, 0x40) = 0;
    M2C_FIELD(voice, s16 *, 0x42) = 0;
    M2C_FIELD(voice, s16 *, 0x44) = 0;
    M2C_FIELD(voice, s16 *, 0x46) = 0;
    if (resetGain & 0xFF) {
        s32 base = gAudioVoiceTable;
        gainVoice = (void *)((voiceId * 0x68) + base);
        M2C_FIELD(gainVoice, s16 *, 0x20) = 0;
        M2C_FIELD(gainVoice, s16 *, 0x22) = 0;
        M2C_FIELD(gainVoice, f32 *, 0x24) = 1.0f;
        M2C_FIELD(gainVoice, s16 *, 0x28) = 0x14;
    }
    {
        s32 base = gAudioVoiceTable;
        voiceOffset = voiceId * 0x68;
        descVoice = (void *)(voiceOffset + base);
    }
    M2C_FIELD(descVoice, s32 *, 0x2C) = (s32) M2C_FIELD(desc, s32 *, 4);
    descCursor = M2C_FIELD(desc, s32 *, 8);
    posFrac = (f64) descCursor;
    if (descCursor < 0) {
        posFrac += D_800D67A0;
    }
    M2C_FIELD(descVoice, f64 *, 8) = posFrac;
    descEnd = M2C_FIELD(desc, s32 *, 8);
    M2C_FIELD(descVoice, s32 *, 0x14) = descEnd;
    M2C_FIELD(descVoice, s32 *, 0x10) = descEnd;
    M2C_FIELD(descVoice, s32 *, 0x30) = (s32) M2C_FIELD(desc, s32 *, 0xC);
    M2C_FIELD(descVoice, s32 *, 0x34) = (s32) M2C_FIELD(desc, s32 *, 0x10);
    M2C_FIELD(descVoice, s32 *, 0x38) = (s32) M2C_FIELD(desc, s32 *, 0x14);
    M2C_FIELD(descVoice, u8 *, 0x5D) = (u8) M2C_FIELD(desc, u8 *, 0x18);
    remainVoice = (void *)(voiceOffset + gAudioVoiceTable);
    loopLen = M2C_FIELD(remainVoice, s32 *, 0x38);
    if ((loopLen == 0) || (remainder = M2C_FIELD(remainVoice, s32 *, 0x30) - (M2C_FIELD(remainVoice, s32 *, 0x34) + loopLen), M2C_FIELD(remainVoice, u32 *, 0x3C) = remainder, ((remainder < 0xAU) != 0))) {
        M2C_FIELD(remainVoice, u32 *, 0x3C) = 0U;
    }
    if ((M2C_FIELD(desc, s32 *, 4) & 0xF0000000) != 0x80000000) {
        s32 base = gAudioVoiceTable;
        s32 offset = voiceId * 0x68;
        voiceFlags = (void *)(offset + base);
        M2C_FIELD(voiceFlags, u16 *, 2) = (u16) (M2C_FIELD(voiceFlags, u16 *, 2) | 1);
    }
}
