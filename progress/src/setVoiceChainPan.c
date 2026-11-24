extern s32 soundResolveHandle(u32);
extern void voiceStoreParam(u8, u8, u8, u8);
extern s32 gVoiceChannelTable, D_8010D748, D_8010D784;
extern u8 D_8010D76F, D_8010D779;

/* Resolves a sound key to a voice handle and sets parameter 10 (pan) on that voice and every voice linked after it; returns 0 if any voice was updated, else -1. */ s32 setVoiceChainPan(u32 soundKey, s32 pan)
{
    s32 index, offset, handle, result, end;
    result = -1;
    handle = soundResolveHandle(soundKey);
    if (handle == result) goto done;
    end = -1;
again:
    index = handle & 0xff;
    offset = index * 0x1a0;
    if (*(s32 *)((s8 *)&D_8010D784 + offset) != handle) goto done;
    if (*(s32 *)((s8 *)&D_8010D748 + offset) & 2) {
        voiceStoreParam(10, index, *(&D_8010D779 + offset), pan & 0xff);
    } else {
        voiceStoreParam(10, index, *(&D_8010D76F + index * 0x1a0), pan & 0xff);
    }
    handle = *(s32 *)((s8 *)&gVoiceChannelTable + index * 0x1a0);
    result = 0;
    if (handle != end) goto again;
done:
    return result;
}
