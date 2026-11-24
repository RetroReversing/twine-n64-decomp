typedef struct { u8 active; u8 p0[0x5F]; u8 slot; u8 flag; u8 p1[6]; } Rec;
extern Rec *D_800E41DC;
extern u16 D_800E41E4;
extern u16 D_800E4216;
extern s32 gAudioFrameBuffers;
extern u16 *gAudioFrameIndexPtr;
extern s32 D_800E422C;
extern void *gAudioStreamInfo;
extern s32 gAudioStreamOffset;
extern s32 D_8010D378;
extern s32 D_8010D42C;
void updateAudioVoice(u8 *, s32, s32);

/* Updates active voices, then finalizes the current audio frame's entry (voice slot mask, stream chunk) and advances to the next frame buffer. */ void mixAudioBuffer(s32 cmdListEnd, u16 sampleCount) {
    volatile u64 scratch;
    s32 temp_a1;
    s32 nextOffset;
    s32 streamEnd;
    s32 tb;
    s32 idx;
    s32 voiceIdx;
    s32 activeCount;
    s32 slotMask;
    s32 var_v1;
    u16 entryCount;
    u16 temp_v1_3;
    u8 *temp_a0;
    u8 *frame;
    u8 *temp_v1;
    u8 *lastEntry;

    activeCount = 0;
    voiceIdx = 0;
    slotMask = 0;
    if (D_800E41E4 != 0) {
        do {
            if (D_800E41DC[voiceIdx & 0xFFFF].flag != 0) {
                D_800E41DC[voiceIdx & 0xFFFF].flag = 0;
                slotMask |= 1 << D_800E41DC[voiceIdx & 0xFFFF].slot;
            }
            if (D_800E41DC[voiceIdx & 0xFFFF].active != 0) {
                updateAudioVoice((u8 *)&D_800E41DC[voiceIdx & 0xFFFF], sampleCount & 0xFFFF, activeCount & 0xFF);
                activeCount += 1;
            }
            voiceIdx += 1;
        } while ((u32) (voiceIdx & 0xFFFF) < (u16) D_800E41E4);
    }
    frame = (u8 *)((*gAudioFrameIndexPtr * 0xA10) + gAudioFrameBuffers);
    entryCount = *(u16 *)frame;
    if (entryCount == 0) {
        *(s16 *)(frame + 0x3C) = 0;
        lastEntry = (u8 *)((*gAudioFrameIndexPtr * 0xA10) + gAudioFrameBuffers);
    } else {
        lastEntry = frame + ((entryCount - 1) * 0x50);
    }
    *(s32 *)(lastEntry + 0x54) = cmdListEnd;
    *(s32 *)(((*gAudioFrameIndexPtr * 0xA10) + gAudioFrameBuffers) + 8) = D_800E422C;
    *(s32 *)(((*gAudioFrameIndexPtr * 0xA10) + gAudioFrameBuffers) + 4) = slotMask;
    *(void **)(((*gAudioFrameIndexPtr * 0xA10) + gAudioFrameBuffers) + 0xC) = gAudioStreamInfo;
    if (gAudioStreamInfo != NULL) {
        *(s16 *)(((*gAudioFrameIndexPtr * 0xA10) + gAudioFrameBuffers) + 2) = gAudioStreamOffset / 192;
        nextOffset = gAudioStreamOffset + 0xC0;
        streamEnd = *(s32 *)((u8 *)gAudioStreamInfo + 4);
        gAudioStreamOffset = nextOffset;
        if (nextOffset == streamEnd) {
            gAudioStreamOffset = 0;
        }
    }
    *gAudioFrameIndexPtr += 1;
    temp_v1_3 = *gAudioFrameIndexPtr;
    if (temp_v1_3 < (u16) D_800E4216) {
        D_8010D378 = (gAudioFrameBuffers + (temp_v1_3 * 0xA10) + 0x10) & ~0xF;
        D_8010D42C = gAudioFrameBuffers + (*gAudioFrameIndexPtr * 0xA10) + 0x10;
        *(u16 *)((*gAudioFrameIndexPtr * 0xA10) + gAudioFrameBuffers) = 0;
    }
}
