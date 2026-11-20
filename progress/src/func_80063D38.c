extern u8 D_800C471C[];
extern s16 func_80063CFC(s32, s16);

s32 func_80063D38(s32 state, s16 index) {
    s32 offset = index * 0xE8;
    s32 slot = D_800C471C[offset];
    s32 result;

    if (*(s16 *)(state + (slot << 1) + 0x1BC) != 0
        || func_80063CFC(state, index) != 0) {
        result = 1;
    } else {
        result = D_800C471C[offset] == 0;
    }
    return result;
}
