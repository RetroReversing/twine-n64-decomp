extern s32 func_800989B8(u32);
extern s32 func_80095A80(s32, s32, u8, s32);
extern s32 D_8010D734, D_8010D748, D_8010D784;
extern u8 D_8010D76F, D_8010D779;
s32 func_8008E96C(u32 arg0, s32 arg1) {
    s32 index, offset, handle, result, ret, end;
    result = -1;
    handle = func_800989B8(arg0);
    if (handle == result) goto done;
    end = -1;
    {
again:
        index = handle & 0xff;
        offset = index * 0x1a0;
        if (*(s32 *)((s8 *)&D_8010D784 + offset) != handle) goto done;
        {
            if (*(s32 *)((s8 *)&D_8010D748 + offset) & 2) {
                func_80095A80(7, index, *(&D_8010D779 + offset), arg1 & 0xff);
            } else {
                func_80095A80(7, index, *(&D_8010D76F + offset), arg1 & 0xff);
            }
            handle = *(s32 *)((s8 *)&D_8010D734 + index * 0x1a0);
            result = 0;
            if (handle != end) goto again;
        }
    }
done:
    return result;
}
