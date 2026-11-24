typedef struct {
    u8 active;
    u8 pad[3];
    u8 (*fn)(u32, u32, u32, u32, u32);
    u32 buf;
    u32 size;
    u32 pos;
    u32 arg;
} AudioRingVoice;
extern AudioRingVoice gVoiceTable[];
extern u8 sVoiceCount;
s32 getVoiceField14(s32);
void writebackDCacheHalfwords(s32, s32);

/* For each active voice, feed the samples written since its last read position to its callback, handling ring wrap-around. */
void updateVoiceRingBuffers(void) {
    s32 i;
    u32 writePos, prevPos, bufBase;

    for (i = 0; i < sVoiceCount; i++) {
        if (gVoiceTable[i].active == 1) {
            writePos = getVoiceField14(i);
            prevPos = gVoiceTable[i].pos;
            if (prevPos != writePos) {
                if (prevPos < writePos) {
                    if (gVoiceTable[i].fn(gVoiceTable[i].buf + prevPos * 2, writePos - prevPos, 0, 0, gVoiceTable[i].arg)) {
                        writebackDCacheHalfwords(gVoiceTable[i].buf + gVoiceTable[i].pos * 2, writePos - gVoiceTable[i].pos);
                    }
                } else {
                    bufBase = gVoiceTable[i].buf;
                    if (gVoiceTable[i].fn(bufBase + prevPos * 2, gVoiceTable[i].size - prevPos, bufBase, writePos, gVoiceTable[i].arg)) {
                        writebackDCacheHalfwords(gVoiceTable[i].buf + gVoiceTable[i].pos * 2, gVoiceTable[i].size - gVoiceTable[i].pos);
                        writebackDCacheHalfwords(gVoiceTable[i].buf, writePos);
                    }
                }
            }
            gVoiceTable[i].pos = writePos;
        }
    }
}
