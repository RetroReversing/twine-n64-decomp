extern s32 soundResolveHandle(u32);
extern void voiceStoreParam(u8, u8, u8, u8);
extern s32 gVoiceChannelTable, D_8010D748, D_8010D784;
extern u8 D_8010D76F, D_8010D779;

s32 func_8008E4A8(u32 key, s32 value)
{
    s32 index, offset, handle, result, end;
    result = -1;
    handle = soundResolveHandle(key);
    if (handle == result) goto done;
    end = -1;
again:
    index = handle & 0xff;
    offset = index * 0x1a0;
    if (*(s32 *)((s8 *)&D_8010D784 + offset) != handle) goto done;
    if (*(s32 *)((s8 *)&D_8010D748 + offset) & 2) {
        voiceStoreParam(10, index, *(&D_8010D779 + offset), value & 0xff);
    } else {
        voiceStoreParam(10, index, *(&D_8010D76F + index * 0x1a0), value & 0xff);
    }
    handle = *(s32 *)((s8 *)&gVoiceChannelTable + index * 0x1a0);
    result = 0;
    if (handle != end) goto again;
done:
    return result;
}
