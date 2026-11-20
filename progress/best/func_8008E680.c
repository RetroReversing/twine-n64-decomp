void func_80095A80(u8,u8,u8,u8);
s32 func_800989B8(s32);
extern char D_8010D734[], D_8010D748[], D_8010D784[];
extern unsigned char D_8010D76F[], D_8010D779[];
s32 func_8008E680(s32 arg0, s32 arg1) {
    s32 index, result = -1, ret, handle;
    u32 high, low;
    handle = func_800989B8(arg0);
    if (handle != -1) {
        high = (u32)(arg1 & 0xffff) >> 7;
        low = arg1 & 0x7f;
    again:
        index = handle;
        arg1 = (u8)index * 0x1a0;
        if (*(s32 *)(D_8010D784 + arg1) != handle) goto done;
        if (*(s32 *)(D_8010D748 + arg1) & 2) {
            result = (u8)index;
            func_80095A80(0x84, result, D_8010D779[arg1], high & 0xff);
            func_80095A80(0x85, result, D_8010D779[arg1], low & 0xff);
        } else {
            result = (u8)index;
            func_80095A80(0x84, result, D_8010D76F[arg1], high & 0xff);
            func_80095A80(0x85, result, D_8010D76F[arg1], low & 0xff);
        }
        handle = *(s32 *)(D_8010D734 + (u8)index * 0x1a0);
        result = 0;
        if (handle == -1) goto done;
        goto again;
    } else {
    done:
        ret = result;
    }
    return ret;
}
