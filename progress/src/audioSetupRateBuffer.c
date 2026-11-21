extern volatile u16 gAudioSampleCount;
extern u32 D_800E41F4;
extern char D_800E41F8[], D_800E4210[];
extern s8 sWorkerBusy;
extern s32 (*gDataBankAlloc)(s32,s32);
extern u8 D_8010086C;
extern s32 sSlotLog;
extern u16 D_800CEED0[];
extern f64 D_800D6700, D_800D6708, D_800D6710;
void func_80089C10(s32);
void audioInitBufferPool(u16);
void osCreateMesgQueue(void *, void *, s32);

/* Sets up the buffer sizing from a rate/count pair: derives the sample count and byte size, allocates the buffer through gDataBankAlloc and initialises its message queue. */
/* Sets up the audio buffer sizing from a rate/count pair: derives the sample count and byte size, allocates the buffer and initialises its message queue. */ void audioSetupRateBuffer(u16 rate, u32 freq, u8 index) {
    u32 count; u32 rate0;
    if (D_8010086C == 0) {
        rate0 = rate;
        count = (u32)((f32)freq * 0.000125f);
    } else {
        f64 d = (s32)freq;
        rate0 = rate;
        if ((s32)freq < 0) d += D_800D6708;
        count = (u32)((f32)d * 0.00025f);
    }
    gAudioSampleCount = rate0 * ((u16)count + 1);
    { u32 size = 0x310; u32 total = gAudioSampleCount * size; f64 d = (s32)total;
    D_800E41F4 = size;
    if ((s32)total < 0) d += D_800D6710;
    D_800E41F4 = (((((u32)((f32)d * 0.9f) + 63) >> 6) * 0x28) + 15) & 0xFFF0; }
    sSlotLog = gDataBankAlloc(gAudioSampleCount * 0x18, 0);
    osCreateMesgQueue(D_800E41F8, D_800E4210, 1);
    sWorkerBusy = 0;
    func_80089C10(gAudioSampleCount);
    audioInitBufferPool(D_800CEED0[index] * rate);
}
