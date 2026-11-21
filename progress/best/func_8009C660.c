void workerLockAcquire(void);
void workerLockRelease(void);
s32 func_80095A80(s32, s32, u8, s32);
s32 func_800989B8(s32);
extern u8 gWorkerActive, D_8010D76F, D_8010D779;
extern s32 gVoiceChannelTable, D_8010D748, D_8010D784;

s32 func_8009C660(s32 handle, s32 original) {
    s32 index, result = -1;
    u32 high, low;
    s32 value = original;
    u8 channel;

    if (gWorkerActive != 0) {
        workerLockAcquire();
        handle = func_800989B8(handle);
        if (handle != result) {
            high = (u32)(value & 0xffff) >> 7;
            low = value & 0x7f;
        again:
            index = handle & 0xff;
            value = index * 0x1a0;
            if (*(s32 *)((char *)&D_8010D784 + value) != handle) goto done;
            if (*(s32 *)((char *)&D_8010D748 + value) & 2) {
                func_80095A80(1, (u8)index, *(&D_8010D779 + value), high & 0xff);
                func_80095A80(0x21, (u8)index, *(&D_8010D779 + value), low & 0xff);
            } else {
                func_80095A80(1, (u8)index, *(&D_8010D76F + value), high & 0xff);
                func_80095A80(0x21, (u8)index, *(&D_8010D76F + value), low & 0xff);
            }
            handle = *(s32 *)((char *)&gVoiceChannelTable + index * 0x1a0);
            result = 0;
            if (handle != -1) goto again;
        }
    done:
        workerLockRelease();
    }
    return result;
}
