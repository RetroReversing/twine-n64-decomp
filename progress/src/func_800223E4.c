typedef struct {
    u8 pad[0x18];
    u8 *text;
    u8 gap[0x11];
    u8 active;
} SaveState223E4;

extern SaveState223E4 *gSaveMenuState;
extern u8 gBorderFlipFlag;
extern char D_800D2AA0[];
extern void *lookupDataEntry(s32);
extern void formatTextEntry(void *, s32, ...);
extern void updateActiveMenuState(void);

void func_800223E4(void) {
    void *entry;
    updateActiveMenuState();
    if (gSaveMenuState->active) {
        if (gBorderFlipFlag != 0) {
            entry = lookupDataEntry(0x68);
        } else {
            entry = lookupDataEntry(0x67);
        }
        formatTextEntry(gSaveMenuState->text + 0x28, (s32)D_800D2AA0, entry);
    }
}
