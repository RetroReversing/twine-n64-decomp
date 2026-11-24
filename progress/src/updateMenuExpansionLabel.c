s32 setExpansionMode(u8);
s32 formatTextEntry(s32, s32 *, s32);
s32 updateActiveMenuState();
s32 lookupDataEntry(s32);
extern void *gSaveMenuState;
extern u8 gExpansionModeEnabled;
extern char D_800D2AA0[];

void updateMenuExpansionLabel(void) {
    s32 base;
    u8 *p;
    s32 v;
    s32 a;
    u8 *ctx;

    updateActiveMenuState();
    ctx = (u8 *)gSaveMenuState;
    if (ctx[0x2D] != 0) {
        base = *(s32 *)(ctx + 0x18) + 0x28;
        p = &gExpansionModeEnabled;
        a = setExpansionMode(*p);
        if ((a & 0xFF) == 0 || (v = *p) == 0) {
            formatTextEntry(base, (s32 *)D_800D2AA0, lookupDataEntry(0x16));
        } else if (v == 1) {
            formatTextEntry(base, (s32 *)D_800D2AA0, lookupDataEntry(0x17));
        }
    }
}
