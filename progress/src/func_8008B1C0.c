typedef struct { u8 active; u8 pad[7]; f64 time; u32 now; u32 prev; u8 rest[0x50]; } E8B1C0;
extern E8B1C0 *gAudioVoiceTable;
extern u16 sAudioVoiceCount;
void func_8008B1C0(void) {
    s32 i;
    E8B1C0 *p;
    for (i = 0; i < sAudioVoiceCount; i++) {
        if (gAudioVoiceTable[i].active != 0) {
            p = &gAudioVoiceTable[i];
            p->prev = p->now;
            p->now = p->time;
        }
    }
}
