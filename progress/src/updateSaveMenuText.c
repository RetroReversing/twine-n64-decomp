typedef struct {
    u8 pad[0x18];
    u8 *text;
    u8 gap[0x11];
    u8 active;
} SaveState224E4;

extern SaveState224E4 *gSaveMenuState;
extern s16 D_80109B9C;
extern u8 D_8010A4FF;
extern char sStringFormat[];
extern void *lookupDataEntry(s32);
extern void formatTextEntry(void *, s32, ...);
extern void updateActiveMenuState(void);

/* Updates the active save menu and, if it is active, formats its text with one of two data entries chosen by D_8010A4FF. */ void updateSaveMenuText(void) {
    void *textEntry;
    updateActiveMenuState();
    if (gSaveMenuState->active) {
        D_80109B9C = D_8010A4FF == 0;
        if (D_8010A4FF != 0) {
            textEntry = lookupDataEntry(0x1D);
        } else {
            textEntry = lookupDataEntry(0x1B3);
        }
        formatTextEntry(gSaveMenuState->text + 0x28, (s32)sStringFormat, textEntry);
    }
}
