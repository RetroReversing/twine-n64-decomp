typedef struct { u8 a; u8 pad[0x5F]; u8 b60; u8 b61; u8 pad2[6]; } Voice;
extern u32 (*gDataBankHandler)(s32, s32);
extern Voice *gAudioVoiceTable, *D_800E41E0;
extern u32 sMixBufferA, sMixBufferB, sAudioStateBlock;
extern u16 sAudioVoiceCount, sMixBufferUnits;
extern s16 D_800E4228, D_800E422A;
extern u8 sVoiceAllocCursor;
extern u8 D_8010086C;
extern int bzero();
extern int osWritebackDCache();

/* Allocates the voice table and mix buffers for voiceCount voices at the sample rate given by rateArg, then clears the audio state block. */
void audioInitVoices(u16 voiceCount, u32 rateArg) {
    u16 i;
    Voice *p;
    f32 f;

    sAudioVoiceCount = voiceCount;
    p = (Voice *)gDataBankHandler(voiceCount * 0x68, 0);
    D_800E41E0 = p;
    gAudioVoiceTable = p;
    sVoiceAllocCursor = 0;
    for (i = 0; i < sAudioVoiceCount; i++) {
        D_800E41E0[i].a = 0;
        D_800E41E0[i].b61 = 0;
        D_800E41E0[i].b60 = 0xff;
    }
    if (D_8010086C == 0) {
        f = rateArg * 0.000125f;
        sMixBufferUnits = (u32) f + 1;
    } else {
        f = rateArg * 0.00025f;
        sMixBufferUnits = (u32) f + 1;
    }
    {
        u32 (**al)(s32, s32) = &gDataBankHandler;
        sMixBufferA = (*al)(sMixBufferUnits * 0xA10, 0);
        sMixBufferB = (*al)(sMixBufferUnits * 0xA10, 0);
        D_800E422A = 0;
        D_800E4228 = 0;
        p = (Voice *)(*al)(0x298, 0);
    }
    sAudioStateBlock = (u32) p;
    bzero(p, 0x298);
    osWritebackDCache(sAudioStateBlock, 0x298);
}
