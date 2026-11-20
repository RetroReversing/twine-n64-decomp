extern u8 D_800C471C[];
extern s8 D_800C46A0[];
extern u8 D_800C469E[];
s16 func_80063C7C(s32 arg0) {
    s32 index = (s16)arg0;
    s32 offset = (index * 29) * 8;
    s32 present = D_800C46A0[offset];
    s32 next = *(u16 *)(D_800C469E + offset);
    if (present != 0) {
        s32 nextIndex = (s16)next;
        s32 nextOffset = (nextIndex * 29) * 8;
        if (D_800C471C[offset] == D_800C471C[nextOffset]) arg0 = next;
    }
    return (s16)arg0;
}
