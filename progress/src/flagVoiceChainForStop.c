extern s32 soundResolveHandle(void);
extern u8 gWorkerThreadActive;
extern s32 gVoiceChannelTable;
extern s32 sSoundVoiceFlags;
extern s32 sSoundVoiceHandle;
/* Walks the voice chain from the resolved sound handle and sets flag 8 on each matching voice; returns 0 if any matched, else -1. */
s32 flagVoiceChainForStop(void) {
    s32 handle, result;
    u32 byteOffset;
    result = -1;
    if (gWorkerThreadActive != 0) {
        handle = soundResolveHandle();
        if (handle != -1) {
            do {
                { u32 index = (u8)handle; byteOffset = (index * 13) << 5; }
                if (*(s32 *)((u8 *)&sSoundVoiceHandle + byteOffset) == handle) {
                    result = 0;
                    *(s32 *)((u8 *)&sSoundVoiceFlags + byteOffset) |= 8;
                }
                handle = *(s32 *)((u8 *)&gVoiceChannelTable + byteOffset);
            } while (handle != -1);
        }
    }
    return result;
}
