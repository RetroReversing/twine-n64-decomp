extern s32 soundResolveHandle(u32);
extern s32 voiceStoreParam(s32, s32, u8, s32);
extern s32 gVoiceChannelTable, D_8010D748, D_8010D784;
extern u8 D_8010D76F, D_8010D779;
/* Walks the chain of linked voices from the sound's handle, storing param 0x83 (value) on each; returns 0 if any voice was updated, else -1. */
s32 setSoundChainRearMix(u32 soundId, s32 value) {
    s32 voiceIndex, voiceOffset, handle, result, ret, noHandle;
    result = -1;
    handle = soundResolveHandle(soundId);
    if (handle == result) goto done;
    noHandle = -1;
    {
again:
        voiceIndex = handle & 0xff;
        voiceOffset = voiceIndex * 0x1a0;
        if (*(s32 *)((s8 *)&D_8010D784 + voiceOffset) != handle) goto done;
        {
            if (*(s32 *)((s8 *)&D_8010D748 + voiceOffset) & 2) {
                voiceStoreParam(0x83, voiceIndex, *(&D_8010D779 + voiceOffset), value & 0xff);
            } else {
                voiceStoreParam(0x83, voiceIndex, *(&D_8010D76F + (handle & 0xff) * 0x1a0), value & 0xff);
            }
            handle = *(s32 *)((s8 *)&gVoiceChannelTable + voiceIndex * 0x1a0);
            result = 0;
            if (handle != noHandle) goto again;
        }
    }
done:
    return result;
}
