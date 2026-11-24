extern s32 getEntryStatus(void);
extern s32 gEntryTable, gEntryMode;
extern u16 gEntryCount;

/* Sets the current entry mode and updates the low state nibble of each table entry's flags. */
void setEntryMode(s32 mode) {
    u16 index;
    switch (mode) {
    case 8: {
        u16 flags, count;
        s32 base;
        u16 *flagsPtr;
        count = gEntryCount;
        index = 0;
        if (count) {
        base = gEntryTable;
        do {
            flagsPtr = (u16 *)(index * 8 + base + 2);
            flags = *flagsPtr;
            index++;
            if (((flags & 0xF0) >> 4) == (flags & 15))
                *flagsPtr = (flags & 0xFFF0) | 1;
        } while (index < count);
        }
        gEntryMode = getEntryStatus();
        if (gEntryMode == 6) setEntryMode(4);
        break;
    }
    case 5: {
        s32 base;
        u16 *flagsPtr;
        base = gEntryTable;
        gEntryMode = mode;
        if (base) {
            u16 limit = gEntryCount;
            index = 0;
            if (limit) {
                s32 items = base;
                do {
                    flagsPtr = (u16 *)(index * 8 + items + 2);
                    index++;
                    *flagsPtr = (*flagsPtr & 0xFFF0) | 1;
                } while (index < limit);
            }
        }
        break;
    }
    case 4:
    case 9: {
        u16 flags, count;
        s32 base;
        u16 *flagsPtr;
        count = gEntryCount;
        index = 0;
        if (count) {
        base = gEntryTable;
        do {
            flagsPtr = (u16 *)(index * 8 + base + 2);
            flags = *flagsPtr;
            if ((flags & 15) != 0) goto nonzero;
            if ((flags & 0xF0) == 0) goto skip;
nonzero:
            if ((flags & 15) != 1) *flagsPtr = (flags & 0xFFF0) | 2;
skip:;
            index++;
        } while (index < count);
        }
        gEntryMode = getEntryStatus();
    }
    case 7:
        gEntryMode = mode;
        break;
    }
}
