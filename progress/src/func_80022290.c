typedef struct {
    u8 pad[0x18];
    u8 *text;
    u8 gap[0x11];
    u8 active;
} SaveState22290;

extern SaveState22290 *gSaveMenuState;
extern u8 D_80109E20;
extern char D_800D2AA0[];
extern void *lookupDataEntry(s32);
extern void formatTextEntry(void *, s32, ...);
extern void updateActiveMenuState(void);

void func_80022290(void) {
    void *entry;
    updateActiveMenuState();
    if (gSaveMenuState->active) {
        if (D_80109E20 != 0) {
            entry = lookupDataEntry(15);
        } else {
            entry = lookupDataEntry(16);
        }
        formatTextEntry(gSaveMenuState->text + 0x28, (s32)D_800D2AA0, entry);
    }
}
