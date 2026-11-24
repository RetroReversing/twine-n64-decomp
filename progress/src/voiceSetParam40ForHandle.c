extern void workerLockAcquire(void);
extern void workerLockRelease(void);
extern s32 soundResolveHandle(s32);
extern void voiceStoreParam(u8, u8, u8, u8);
extern u8 gWorkerThreadActive;
extern s32 gVoiceChannelTable, sSoundVoiceFlags, sSoundVoiceHandle;
extern u8 D_8010D76F, D_8010D779;

/* Sets parameter 0x40 on every voice in the chain that starts at the resolved handle; returns -1 if none. */
s32 voiceSetParam40ForHandle(s32 handle, s32 paramValue) {
    register s32 voiceIndex;
    s32 voiceOffset, voiceHandle, result, endHandle, value;

    voiceHandle = handle;
    result = -1;
    value = paramValue;
    if (gWorkerThreadActive != 0) {
        workerLockAcquire();
        voiceHandle = soundResolveHandle(voiceHandle);
        if (voiceHandle == result) goto unlock;
        endHandle = -1;
again:        {
            voiceIndex = voiceHandle & 0xFF;
            voiceOffset = voiceIndex * 0x1A0;
            if (*(s32 *)((s8 *)&sSoundVoiceHandle + voiceOffset) != voiceHandle) goto unlock;
            if (*(s32 *)((s8 *)&sSoundVoiceFlags + voiceOffset) & 2) {
                do { voiceStoreParam(64, voiceIndex, *(&D_8010D779 + voiceOffset), value); } while (0);
            } else {
                voiceStoreParam(64, voiceIndex, *(&D_8010D76F + voiceIndex * 0x1A0), value);
            }
            voiceHandle = *(s32 *)((s8 *)&gVoiceChannelTable + voiceIndex * 0x1A0);
            result = 0;
            if (voiceHandle != endHandle) goto again;
        }
unlock:
        workerLockRelease();
    }
    return result;
}
