void *findEntryById(s32, s32);
s32 func_80027C60(s32);
extern u8 D_801002AC;
extern u8 gMenuUseTextList;
extern void *gSaveMenuState;

/* Per-frame save menu update: clears the menu's flag byte, optionally refreshes the current entry when the text list is in use, then calls the entry's two update callbacks. */
void runSaveMenuCallbacks(void) {
    void (*callback)();
    void (*callback2)();

    if (gSaveMenuState != NULL) {
        *(s8 *)((char *)gSaveMenuState + 0x2E) = 0;
        if ((gMenuUseTextList != 0) && (D_801002AC == 0)) {
            if (gSaveMenuState != NULL) {
                if (func_80027C60(0x23) & 0xFF) {
                    *(s8 *)((char *)gSaveMenuState + 0x2C) = 1;
                    if (*(void **)((char *)gSaveMenuState + 0x18) != NULL) {
                        *(void **)((char *)gSaveMenuState + 0x18) = findEntryById(*(s32 *)((char *)gSaveMenuState + 0xC), 0xE);
                    }
                }
                goto block_7;
            }
        } else {
block_7:
            if (gSaveMenuState != NULL) {
                callback = *(void (**)())((char *)(*(void **)((char *)gSaveMenuState + 0x18)) + 4);
                if (callback != NULL) {
                    callback();
                }
                if (gSaveMenuState != NULL) {
                    callback2 = *(void (**)())((char *)(*(void **)((char *)gSaveMenuState + 0x10)) + 0x10);
                    if (callback2 != NULL) {
                        callback2();
                    }
                }
            }
        }
    }
}
