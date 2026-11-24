extern unsigned char sOptionCursorIndex, sOptionReady7, sOptionReady8, sOptionReady9;
extern unsigned char *gSaveMenuState;
extern int sOptionEntryTable;
extern const char D_800D2864[];
extern void updateActiveMenuState(void);
extern int findEntryPayload(int, int);
extern int menuItemIsActive(int);
extern int lookupDataEntry(int);
extern void formatTextEntry(void *, int, ...);

/* Moves the option cursor on left/right input (cases 7-9), then redraws the option label and sub-label. */ void refreshOptionEntry(void) {
    unsigned char *cursor;
    unsigned char *cursorIdx;
    char *entry;
    char *subEntry;
    const char *fmt;
    int nameId;

    if (gSaveMenuState[0x2F] == 0)
        updateActiveMenuState();
    if (gSaveMenuState[0x2D] == 0)
        goto clear;
    entry = (char *)findEntryPayload((int)&sOptionEntryTable, 0x92);
    if (entry == 0)
        return;
    cursor = &sOptionCursorIndex;
    subEntry = entry + 0x28;
    switch (*cursor) {
    case 7:
        if (sOptionReady7 == 0) {
            gSaveMenuState[0x2F] = 1;
            if ((unsigned char)menuItemIsActive(0x21))
                ++*cursor;
            else
                --*cursor;
            refreshOptionEntry();
        }
        break;
    case 8:
        if (sOptionReady8 == 0) {
            gSaveMenuState[0x2F] = 1;
            if ((unsigned char)menuItemIsActive(0x21))
                ++*cursor;
            else
                --*cursor;
            refreshOptionEntry();
        }
        break;
    case 9:
        if (sOptionReady9 == 0) {
            gSaveMenuState[0x2F] = 1;
            if ((unsigned char)menuItemIsActive(0x21))
                *cursor = 0;
            else
                --*cursor;
            refreshOptionEntry();
        }
        break;
    }
    cursorIdx = &sOptionCursorIndex;
    nameId = lookupDataEntry(*cursorIdx + 0x16D);
    fmt = D_800D2864;
    formatTextEntry(entry, (int)fmt, nameId);
    formatTextEntry(subEntry, (int)fmt, lookupDataEntry(*cursorIdx + 0x177));
clear:
    gSaveMenuState[0x2F] = 0;
}
