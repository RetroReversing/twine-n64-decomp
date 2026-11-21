extern s32 lookupMenuItemIndex(u32);
extern u32 randomU32Next(void);
extern void updateSaveMenuRowEnabled(void);
extern u8 gMenuFlagItem20, gMenuFlagItem22, gMenuFlagItem27, sMenuRowEnabled;
extern u8 *gSaveMenuState;
void updateRandomMenuItem(void) {
    u32 r;
    s32 item;
    u32 key;
    if (*(gSaveMenuState + 0x2E) == 0) {
        r = randomU32Next();
        item = r % 13 + 14;
        key = item & 0xffff;
        if (key < 14) item = 14;
        if (key >= 28) item = 27;
        key = item & 0xffff;
        { u32 flag;
        switch ((s32)key) {
        case 27: flag = gMenuFlagItem27; break;
        case 22: flag = gMenuFlagItem22; break;
        case 20: flag = gMenuFlagItem20; break;
        case 17: flag = sMenuRowEnabled; break;
        default: goto done;
        }
        if (flag) goto done;
        item = (u16)(item - 1);
done: ; }
        *(s32 *)(*(void **)(gSaveMenuState + 0x18) + 0x14) =
            (lookupMenuItemIndex(item & 0xffff) & 0xffff) << 8 | 0xC;
    }
    updateSaveMenuRowEnabled();
}
