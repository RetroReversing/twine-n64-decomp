s32 setMenuTextRequest(s32, s32);
extern u8 gMenuItemTable;
extern u8 D_800BD695[];
extern s8 D_800BD705;
extern void *sActiveMenu;
extern s16 gExpansionPakPresent;
/* Selects a menu item: records its linked entry and timer in the active menu and requests its text. */ void selectMenuItem(s32 itemId) {
    s32 unused;
    if (sActiveMenu != NULL) {
        if ((itemId & 0xFFFF) == 4) {
            if (gExpansionPakPresent == 0) {
                D_800BD705 = 5;
            } else {
                D_800BD705 = 3;
            }
        }
        *(s16 *)((s8 *)sActiveMenu + 0x7A) = *(u8 *)(D_800BD695 + ((itemId & 0xFFFF) * 0x1C));
        *(s16 *)((s8 *)sActiveMenu + 0x7C) = 0x78;
        setMenuTextRequest(*(s16 *)((s8 *)sActiveMenu + 0x7A) * 0x1C + (s32)&gMenuItemTable, itemId);
    }
}
