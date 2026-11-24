typedef struct { u8 pad0[0x18]; char *text; u16 len; } Txt4D78;
typedef struct { Txt4D78 *txt; s32 f4; } Item4D78;
typedef struct { u8 pad0[0x10]; s32 f10; } Sys4D78;
extern s32 gSaveMenuObjectPool;
extern char D_800D2AD0[];
extern char D_800D2AE0[];
extern Sys4D78 *gSaveMenuState;
Item4D78 **getMenuEntry(s32 *, s8);
s8 getDataEntryByte(u16);
s32 touchSaveSlotEntry(u16);
u16 getSaveSlotValue16(u16);
u16 isSaveSlotUsed16(u16);
u16 getGlobalValueHigh16Masked(void);
s32 initObjectFromBankEntry(s32, s32, s32);
s32 findEntryById(s32, s32);
s32 lookupDataEntry(s32);
void formatTextEntry(s32, char *, s32, u16);
s32 sprintf(char *, const char *, ...);
s16 strlen(const char *);

/* Rebuilds the text of each slot menu entry (number, marker, slot info) and refreshes the footer label. */ void refreshSlotMenuLabels(void) {
    u16 slotIdx;
    Item4D78 **entryPtr;
    Item4D78 *entry;
    char marker[3];
    s32 footerId;
    Txt4D78 *label;
    s32 footerEntry;

    for (slotIdx = 0; slotIdx < 16; slotIdx++) {
        entryPtr = getMenuEntry(&gSaveMenuObjectPool, slotIdx);
        if (entryPtr == NULL) {
            continue;
        }
        entry = *entryPtr;
        if (entry == NULL) {
            continue;
        }
        if (entry->txt->text == NULL) {
            continue;
        }
        marker[2] = 0;
        marker[1] = 0;
        marker[0] = 0;
        marker[1] = getDataEntryByte(slotIdx);
        if (marker[1]) {
            marker[0] = '.';
        } else {
            marker[0] = ' ';
        }
        sprintf(entry->txt->text, D_800D2AD0, slotIdx + 1, touchSaveSlotEntry(slotIdx), marker, getSaveSlotValue16(slotIdx));
        label = entry->txt;
        label->len = strlen(label->text);
        if (isSaveSlotUsed16(slotIdx)) {
            initObjectFromBankEntry(entry->f4, 0xF, 0x24);
        } else {
            initObjectFromBankEntry(entry->f4, 0x10, 0x24);
        }
    }
    footerEntry = findEntryById(gSaveMenuState->f10, 0x4010);
    if (footerEntry != 0) {
        footerId = lookupDataEntry(0x300E);
        formatTextEntry(footerEntry, D_800D2AE0, footerId, getGlobalValueHigh16Masked());
    }
}
