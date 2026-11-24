typedef struct {
    u8 pad[0x18];
    u8 *text;
    u8 gap[0x11];
    u8 active;
} SaveState22290;

extern SaveState22290 *gSaveMenuState;
extern u8 D_80109E20;
extern char sStringFormat[];
extern void *lookupDataEntry(s32);
extern void formatTextEntry(void *, s32, ...);
extern void updateActiveMenuState(void);

/* Updates the menu state, then if the save menu is active formats data entry 15 or 16 (by D_80109E20) into its text buffer. */ void updateSaveMenuHeaderText(void) {
    void *textEntry;
    updateActiveMenuState();
    if (gSaveMenuState->active) {
        if (D_80109E20 != 0) {
            textEntry = lookupDataEntry(15);
        } else {
            textEntry = lookupDataEntry(16);
        }
        formatTextEntry(gSaveMenuState->text + 0x28, (s32)sStringFormat, textEntry);
    }
}
