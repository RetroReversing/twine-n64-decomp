extern s32 soundResolveHandle(u32);
extern s32 voiceStoreParam(s32, s32, u8, s32);
extern s32 gVoiceChannelTable, D_8010D748, D_8010D784;
extern u8 D_8010D76F, D_8010D779;
s32 func_8008E680(s32 arg0, s32 arg1) {
    s32 index, offset, handle, result, end;
    result = -1;
    handle = soundResolveHandle(arg0);
    if (handle == result) goto done;
    end = -1;
again:
    index = handle & 0xff;
    offset = index * 0x1a0;
    if (*(s32 *)((s8 *)&D_8010D784 + offset) != handle) goto done;
    if (*(s32 *)((s8 *)&D_8010D748 + offset) & 2) {
        voiceStoreParam(0x84, index, *(&D_8010D779 + offset), ((u32)(arg1 & 0xffff) >> 7));
        voiceStoreParam(0x85, index, *(&D_8010D779 + offset), arg1 & 0x7f);
    } else {
        voiceStoreParam(0x84, index, *(&D_8010D76F + offset), ((u32)(arg1 & 0xffff) >> 7));
        voiceStoreParam(0x85, index, *(&D_8010D76F + offset), arg1 & 0x7f);
    }
    handle = *(s32 *)((s8 *)&gVoiceChannelTable + index * 0x1a0);
    result = 0;
    if (handle != end) goto again;
done:
    return result;
}
