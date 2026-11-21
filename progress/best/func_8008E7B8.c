extern s32 soundResolveHandle(u32);
extern s32 voiceStoreParam(s32, s32, u8, s32);
extern s32 gVoiceChannelTable, D_8010D748, D_8010D784;
extern u8 D_8010D76F, D_8010D779;
s32 func_8008E7B8(u32 arg0, s32 arg1) {
    s32 index, offset, handle, result;
    u32 high, low;
    result = -1;
    handle = soundResolveHandle(arg0);
    if (handle == result) goto done;
    high = (u32)(arg1 & 0xffff) >> 7;
    low = arg1 & 0x7f;
again:
    index = handle & 0xff;
    offset = index * 0x1a0;
    if (*(s32 *)((s8 *)&D_8010D784 + offset) != handle) goto done;
    if (*(s32 *)((s8 *)&D_8010D748 + offset) & 2) {
        voiceStoreParam(0x80, index, *(&D_8010D779 + offset), high & 0xff);
        offset = index * 0x1a0;
        do { voiceStoreParam(0x81, index, *(&D_8010D779 + offset), low); } while (0);
    } else {
        do { voiceStoreParam(0x80, index, *(&D_8010D76F + offset), high & 0xff); } while (0);
        offset = index * 0x1a0;
        voiceStoreParam(0x81, index, *(&D_8010D76F + offset), low);
    }
    handle = *(s32 *)((s8 *)&gVoiceChannelTable + index * 0x1a0);
    result = 0;
    if (handle != -1) goto again;
done:
    return result;
}
