void workerLockAcquire(void);
void workerLockRelease(void);
s32 voiceStoreParam(s32, s32, u8, u8);
s32 soundResolveHandle(s32);
extern u8 gWorkerThreadActive;
extern char gVoiceChannelTable[];
extern char D_8010D748[];
extern char D_8010D784[];
extern unsigned char D_8010D76F[];
extern unsigned char D_8010D779[];

s32 func_8009C660(s32 handle, s32 original) {
    s32 result = -1;
    s32 idx;
    s32 off = original;
    s32 t;

    if (gWorkerThreadActive != 0) {
        workerLockAcquire();
        handle = soundResolveHandle(handle);
        if (handle != -1) {
            while (handle != -1) {
                idx = handle & 0xff;
                off = idx * 0x1a0;
                if (*((s32 *)(D_8010D784 + off)) != handle) {
                    goto done;
                }
                if (*((s32 *)(D_8010D748 + off)) & 2) {
                    voiceStoreParam(1, (u8)idx, D_8010D779[off], ((u32)(original & 0xffff)) >> 7);
                    voiceStoreParam(0x21, (u8)idx, D_8010D779[off], original & 0x7f);
                } else {
                    voiceStoreParam(1, (u8)idx, D_8010D76F[off], ((u32)(original & 0xffff)) >> 7);
                    voiceStoreParam(0x21, (u8)idx, D_8010D76F[off], original & 0x7f);
                }
                t = idx * 0x1a0;
                handle = *((s32 *)(gVoiceChannelTable + t));
                result = 0;
            }
        }
    done:
        workerLockRelease();
    }
    return result;
}
