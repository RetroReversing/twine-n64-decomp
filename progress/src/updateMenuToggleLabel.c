typedef struct {
    u8 pad[0x18];
    u8 *text;
    u8 gap[0x11];
    u8 active;
} SaveState223E4;

extern SaveState223E4 *gSaveMenuState;
extern u8 gBorderFlipFlag;
extern char sStringFormat[];
extern void *lookupDataEntry(s32);
extern void formatTextEntry(void *, s32, ...);
extern void updateActiveMenuState(void);

/* Updates the active menu state, then formats its toggle label (entry 0x68 if the flag is set, else 0x67) into the menu text. */ void updateMenuToggleLabel(void) {
    void *labelEntry;
    updateActiveMenuState();
    if (gSaveMenuState->active) {
        if (gBorderFlipFlag != 0) {
            labelEntry = lookupDataEntry(0x68);
        } else {
            labelEntry = lookupDataEntry(0x67);
        }
        formatTextEntry(gSaveMenuState->text + 0x28, (s32)sStringFormat, labelEntry);
    }
}
