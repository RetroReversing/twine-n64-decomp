extern unsigned char sOptionCursor, sOptionReady7, sOptionReady8, sOptionReady9;
extern unsigned char *gMenuState;
extern int sOptionEntryTable;
extern const char D_800D2864[];
extern void updateActiveMenuState(void);
extern int findEntryPayload(int, int);
extern int func_80027CE0(int);
extern int lookupDataEntry(int);
extern void formatTextEntry(void *, int, ...);

void refreshOptionEntry(void) {
    unsigned char *index;
    unsigned char *index2;
    char *item;
    char *second;
    const char *format;
    int name;

    if (gMenuState[0x2F] == 0)
        updateActiveMenuState();
    if (gMenuState[0x2D] == 0)
        goto clear;
    item = (char *)findEntryPayload((int)&sOptionEntryTable, 0x92);
    if (item == 0)
        return;
    index = &sOptionCursor;
    second = item + 0x28;
    switch (*index) {
    case 7:
        if (sOptionReady7 == 0) {
            gMenuState[0x2F] = 1;
            if ((unsigned char)func_80027CE0(0x21))
                ++*index;
            else
                --*index;
            refreshOptionEntry();
        }
        break;
    case 8:
        if (sOptionReady8 == 0) {
            gMenuState[0x2F] = 1;
            if ((unsigned char)func_80027CE0(0x21))
                ++*index;
            else
                --*index;
            refreshOptionEntry();
        }
        break;
    case 9:
        if (sOptionReady9 == 0) {
            gMenuState[0x2F] = 1;
            if ((unsigned char)func_80027CE0(0x21))
                *index = 0;
            else
                --*index;
            refreshOptionEntry();
        }
        break;
    }
    index2 = &sOptionCursor;
    name = lookupDataEntry(*index2 + 0x16D);
    format = D_800D2864;
    formatTextEntry(item, (int)format, name);
    formatTextEntry(second, (int)format, lookupDataEntry(*index2 + 0x177));
clear:
    gMenuState[0x2F] = 0;
}
