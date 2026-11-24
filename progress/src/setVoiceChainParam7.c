extern s32 soundResolveHandle(u32);
extern s32 voiceStoreParam(s32, s32, u8, s32);
extern s32 gVoiceChannelTable, D_8010D748, D_8010D784;
extern u8 D_8010D76F, D_8010D779;
/* Resolves a sound handle and writes parameter 7 on its voice and every voice linked after it, stopping when a handle no longer matches. */ s32 setVoiceChainParam7(u32 soundId, s32 value) {
    s32 index, offset, handle, result, ret, end;
    result = -1;
    handle = soundResolveHandle(soundId);
    if (handle == result) goto done;
    end = -1;
    {
again:
        index = handle & 0xff;
        offset = index * 0x1a0;
        if (*(s32 *)((s8 *)&D_8010D784 + offset) != handle) goto done;
        {
            if (*(s32 *)((s8 *)&D_8010D748 + offset) & 2) {
                voiceStoreParam(7, index, *(&D_8010D779 + offset), value & 0xff);
            } else {
                voiceStoreParam(7, index, *(&D_8010D76F + index * 0x1a0), value & 0xff);
            }
            handle = *(s32 *)((s8 *)&gVoiceChannelTable + index * 0x1a0);
            result = 0;
            if (handle != end) goto again;
        }
    }
done:
    return result;
}
