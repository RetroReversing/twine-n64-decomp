extern void workerLockAcquire(void);
extern void workerLockRelease(void);
extern s32 soundResolveHandle(s32);
extern void voiceStoreParam(u8, u8, u8, u8);
extern u8 gWorkerThreadActive;
extern s32 gVoiceChannelTable, sSoundVoiceFlags, sSoundVoiceHandle;
extern u8 D_8010D76F, D_8010D779;

s32 voiceSetParamForHandle(s32 arg0, s32 arg1) {
    register s32 index;
    s32 offset, handle, result, end, parameter;
    handle = arg0;
    result = -1;
    parameter = arg1;
    if (gWorkerThreadActive != 0) {
        workerLockAcquire();
        handle = soundResolveHandle(handle);
        if (handle == result) goto unlock;
        end = -1;
again:        {
            index = handle & 0xFF;
            offset = index * 0x1A0;
            if (*(s32 *)((s8 *)&sSoundVoiceHandle + offset) != handle) goto unlock;
            if (*(s32 *)((s8 *)&sSoundVoiceFlags + offset) & 2) {
                do { voiceStoreParam(0x5B, index, *(&D_8010D779 + offset), parameter); } while (0);
            } else {
                voiceStoreParam(0x5B, index, *(&D_8010D76F + index * 0x1A0), parameter);
            }
            handle = *(s32 *)((s8 *)&gVoiceChannelTable + index * 0x1A0);
            result = 0;
            if (handle != end) goto again;
        }
unlock:
        workerLockRelease();
    }
    return result;
}
