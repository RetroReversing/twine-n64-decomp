s32 func_800989B8(s32);
void func_80095A80(s32, s32, s32, s32);

typedef struct { s32 value; u8 pad[0x19C]; } AudioSlotWord;
extern AudioSlotWord D_8010D734[];
extern AudioSlotWord D_8010D748[];
extern AudioSlotWord D_8010D784[];
extern u8 D_8010D76F[];
extern u8 D_8010D779[];

s32 func_8008E680(s32 sound, s32 value) {
    s32 result, handle, index, low, high, field;
    result = -1;
    handle = func_800989B8(sound);
    if (handle == -1) {
        goto finish;
    }
    high = (u32)(value & 0xFFFF) >> 7;
    low = value & 0x7F;
next:
    index = handle & 0xFF;
    value = index * 0x1A0;
    if (*(s32 *)((u8 *)D_8010D784 + value) != handle) {
        return result;
    } else {
        if (*(s32 *)((u8 *)D_8010D748 + value) & 2) {
            result = index & 0xFF;
            func_80095A80(0x84, result, D_8010D779[value], high & 0xFF);
            field = D_8010D779[value];
        } else {
            result = index & 0xFF;
            func_80095A80(0x84, result, D_8010D76F[value], high & 0xFF);
            field = D_8010D76F[value];
        }
        func_80095A80(0x85, result, field, low & 0xFF);
        handle = D_8010D734[index].value;
        result = 0;
        if (handle != -1) {
            goto next;
        }
    }
finish:
    return result;
}
