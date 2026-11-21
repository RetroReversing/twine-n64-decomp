typedef struct SaveMenuRow {
    u16 entryId;        /* 0x00 data entry key, looked up for the row text */
    u8 pad0[0x0C - 0x02];
    u16 flags;          /* 0x0C 0x800: store one byte of packedWord; otherwise store value */
    u8 pad1[0x10 - 0x0E];
    s8 *dest;           /* 0x10 where the row's setting is written */
    u8 packedWord[2];   /* 0x14 read as a u32 (0x14..0x17) when flags has 0x800 */
    u8 value;           /* 0x16 */
    u8 pad2[0x1C - 0x17];
    u8 rowFlags;        /* 0x1C bit 0x10 marks the row as enabled */
} SaveMenuRow;

typedef struct SaveMenuState {
    u8 pad0[0x10];
    s32 entryKey;       /* 0x10 */
    u8 pad1[0x18 - 0x14];
    SaveMenuRow *row;   /* 0x18 currently selected row */
    u8 pad2[0x2C - 0x1C];
    u8 refreshPending;  /* 0x2C */
} SaveMenuState;

s32 findEntryById(s32 key, s32 kind);
s32 formatTextEntry(s32 entry, const char *fmt, s32 arg);
s32 lookupDataEntry(u16 entryId);
s32 updateActiveMenuState(void);
s32 func_80027C60(s32 arg);
s32 func_800192E8(s8 *dest);
extern SaveMenuState *gSaveMenuState;

/* Marks the selected save-menu row enabled, refreshes its label, and writes its setting
   when a refresh is pending. */
void updateSaveMenuRowEnabled(void) {
    s32 entry;
    s8 *dest;
    SaveMenuRow *row;

    row = gSaveMenuState->row;
    row->rowFlags = (u8)(row->rowFlags | 0x10);
    entry = findEntryById(gSaveMenuState->entryKey, 0x4000);
    if (entry != 0) {
        formatTextEntry(entry, "%s", lookupDataEntry(gSaveMenuState->row->entryId));
    }
    updateActiveMenuState();
    if ((gSaveMenuState->refreshPending != 0) || (func_80027C60(0x23) & 0xFF)) {
        row = gSaveMenuState->row;
        dest = row->dest;
        if (dest != NULL) {
            if (row->flags & 0x800) {
                *dest = (s8)((*(u32 *)row->packedWord) >> 8);
            } else {
                *(s32 *)dest = row->value;
            }
        }
        func_800192E8(dest);
    }
}
