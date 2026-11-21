extern u8 sDataBankInitialised, sDataBankFlags[];
extern char sDataBankSlots[];
s32 isSlotActiveById(s32 i) {
    s32 key = i;
    s32 offset;
    if (sDataBankInitialised) {
        i = 0;
        offset = 0;
        do {
            if (sDataBankFlags[offset] && *(s32 *)(sDataBankSlots + offset) == key) goto found;
            offset += 0x1228;
        } while ((u32)++i < 2);
        i = -1;
found:
        key = i;
        if (key != -1) return sDataBankFlags[key * 0x1228] != 0;
    }
    return 0;
}
extern s32 formatTextEntry(s32, s32 *, s32);
extern s32 updateActiveMenuState();
extern s32 lookupDataEntry(s32);
extern void *gMenuItems;
extern u8 gBorderFlipFlag;
void func_800223E4(void) {
    s32 id;
    updateActiveMenuState();
    if (*((u8 *)gMenuItems + 0x2D) != 0) {
        id = 0x67;
        if (gBorderFlipFlag != 0) id = 0x68;
        formatTextEntry(*(s32 *)((u8 *)gMenuItems + 0x18) + 0x28, "%s", lookupDataEntry(id));
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
