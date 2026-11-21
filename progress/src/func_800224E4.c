typedef struct {
    u8 pad[0x18];
    u8 *text;
    u8 gap[0x11];
    u8 active;
} SaveState224E4;

extern SaveState224E4 *gSaveMenuState;
extern s16 D_80109B9C;
extern u8 D_8010A4FF;
extern char D_800D2AA0[];
extern void *lookupDataEntry(s32);
extern void formatTextEntry(void *, s32, ...);
extern void updateActiveMenuState(void);

void func_800224E4(void) {
    void *entry;
    updateActiveMenuState();
    if (gSaveMenuState->active) {
        D_80109B9C = D_8010A4FF == 0;
        if (D_8010A4FF != 0) {
            entry = lookupDataEntry(0x1D);
        } else {
            entry = lookupDataEntry(0x1B3);
        }
        formatTextEntry(gSaveMenuState->text + 0x28, (s32)D_800D2AA0, entry);
    }
}
