extern void bzero(void *, s32);
extern s32 osAiSetNextBuffer(s32, s32);
extern void osWritebackDCache(s32, s32);
extern s32 osRecvMesg(void *, u8 **, s32);
extern u8 gWorkerMsgQueue[24];
extern s32 gAudioBufferPtrs[24];
extern volatile u8 gAudioBufferIndex;
extern u32 gAudioSampleRate;
extern u8 gStartupFlag;
extern volatile u16 gAudioBufferCount;
extern s32 (*gDataBankHandler)(s32, s32);
extern u8 D_8010086C;

/* Audio worker thread: allocates a ring of 0x300-byte buffers and advances it on each queued message until shutdown */ void audioSilenceThread(void) {
    u8 *msg;
    s32 *prevBuf;
    s32 *nextBuf;
    s32 i;
    s32 ringCount;
    u32 bufferCount;
    u8 quit;

    bufferCount = (-(D_8010086C != 0) & 0x18) | 0x10;
    gAudioBufferCount = bufferCount;
    if (gAudioSampleRate < 0x5623U) {
        gAudioBufferCount = bufferCount >> 1;
    }
    gAudioBufferPtrs[0] = gDataBankHandler(gAudioBufferCount * 0x300, 0x80);
    ringCount = *(u16 *)&gAudioBufferCount;
    i = 1;
    if (i < ringCount) {
        s32 ringLimit = ringCount;
        do {
            gAudioBufferPtrs[i] = gAudioBufferPtrs[i - 1] + 0x300;
            i++;
        } while (i < ringLimit);
    }
    bzero((void *)gAudioBufferPtrs[0], gAudioBufferCount * 0x300);
    quit = 0;
    osWritebackDCache(gAudioBufferPtrs[0], gAudioBufferCount * 0x300);
    gAudioBufferIndex = 0;
    osAiSetNextBuffer(gAudioBufferPtrs[0], 0x300);
    do {
        osRecvMesg(gWorkerMsgQueue, &msg, 1);
        if (!gStartupFlag) {
            switch (*msg) {
            case 1:
                gAudioBufferIndex = (gAudioBufferIndex + 1) % (s32)gAudioBufferCount;
                osAiSetNextBuffer(gAudioBufferPtrs[gAudioBufferIndex], 0x300);
                break;
            case 255:
                quit = 1;
                break;
            }
        }
    } while (!quit);
}
