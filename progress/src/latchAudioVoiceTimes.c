typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *gAudioVoiceTable;
extern u16 sAudioVoiceCount;
/* For each active audio voice, shifts the current time into prev and latches the new time (as u32). */ void latchAudioVoiceTimes(void) {
    s32 i;
    E8B1C0 *voice;
    for (i = 0; i < sAudioVoiceCount; i++) {
        if (gAudioVoiceTable[i].active != 0) {
            voice = &gAudioVoiceTable[i];
            voice->prev = voice->now;
            voice->now = voice->time;
        }
    }
}
