void workerLockAcquire(void);
void workerLockRelease(void);
s32 voiceStoreParam(s32, s32, u8, u8);
s32 soundResolveHandle(s32);
extern u8 gWorkerThreadActive;
extern char gVoiceChannelTable[];
extern char sSoundVoiceFlags[];
extern char sSoundVoiceHandle[];
extern unsigned char D_8010D76F[];
extern unsigned char D_8010D779[];

/* Walks the linked voices of a sound handle and sets the 14-bit modulation controller (MSB ctrl 1, LSB ctrl 0x21) on each; returns 0 if applied, -1 otherwise. */ s32 setVoiceChainModulation(s32 handle, s32 value) {
    s32 result = -1;
    s32 voiceIdx;
    s32 offset = value;
    s32 nextOffset;

    if (gWorkerThreadActive != 0) {
        workerLockAcquire();
        handle = soundResolveHandle(handle);
        if (handle != -1) {
            while (handle != -1) {
                voiceIdx = handle & 0xff;
                offset = voiceIdx * 0x1a0;
                if (*((s32 *)(sSoundVoiceHandle + offset)) != handle) {
                    goto done;
                }
                if (*((s32 *)(sSoundVoiceFlags + offset)) & 2) {
                    voiceStoreParam(1, (u8)voiceIdx, D_8010D779[offset], ((u32)(value & 0xffff)) >> 7);
                    voiceStoreParam(0x21, (u8)voiceIdx, D_8010D779[offset], value & 0x7f);
                } else {
                    voiceStoreParam(1, (u8)voiceIdx, D_8010D76F[offset], ((u32)(value & 0xffff)) >> 7);
                    voiceStoreParam(0x21, (u8)voiceIdx, D_8010D76F[offset], value & 0x7f);
                }
                nextOffset = voiceIdx * 0x1a0;
                handle = *((s32 *)(gVoiceChannelTable + nextOffset));
                result = 0;
            }
        }
    done:
        workerLockRelease();
    }
    return result;
}
