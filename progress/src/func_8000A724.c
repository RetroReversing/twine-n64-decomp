extern u8 D_800CEEC0, D_800E2CC0[];
extern char D_800E2CE4[];
s32 isSlotActiveById(s32 i) {
    s32 key = i;
    s32 offset;
    if (D_800CEEC0) {
        i = 0;
        offset = 0;
        do {
            if (D_800E2CC0[offset] && *(s32 *)(D_800E2CE4 + offset) == key) goto found;
            offset += 0x1228;
        } while ((u32)++i < 2);
        i = -1;
found:
        key = i;
        if (key != -1) return D_800E2CC0[key * 0x1228] != 0;
    }
    return 0;
}
extern s32 func_80026004(s32, s32 *, s32);
extern s32 func_80029068();
extern s32 func_80087100(s32);
extern void *D_80109BB0;
extern u8 D_8010A4FD;
void func_800223E4(void) {
    s32 id;
    func_80029068();
    if (*((u8 *)D_80109BB0 + 0x2D) != 0) {
        id = 0x67;
        if (D_8010A4FD != 0) id = 0x68;
        func_80026004(*(s32 *)((u8 *)D_80109BB0 + 0x18) + 0x28, "%s", func_80087100(id));
    }
}
extern s32 D_800E06B8[];
extern s32 D_800E06F8;
void func_8000A724(s32 arg0) {
    u32 index;
    s32 *base;
    s32 remaining;
    if (arg0 != -1) {
        index = D_800E06F8;
        remaining = 15;
        base = D_800E06B8;
        do {
            s32 slot = base[index];
            if (slot == -1) break;
            slot = index + 1;
            index = slot & 15;
        } while (remaining--);
        base[index] = arg0;
        D_800E06F8 = (index + 1) & 15;
    }
}
