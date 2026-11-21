extern s32 func_80030D40(void);
extern s32 gEntryTable, gEntryMode;
extern u16 gEntryCount;
void setEntryMode(s32 arg0) {
    u16 i;
    switch (arg0) {
    case 8: {
        u16 x, count;
        s32 base;
        u16 *p;
        count = gEntryCount;
        i = 0;
        if (count) {
        base = gEntryTable;
        do {
            p = (u16 *)(i * 8 + base + 2);
            x = *p;
            i++;
            if (((x & 0xF0) >> 4) == (x & 15))
                *p = (x & 0xFFF0) | 1;
        } while (i < count);
        }
        gEntryMode = func_80030D40();
        if (gEntryMode == 6) setEntryMode(4);
        break;
    }
    case 5: {
        s32 base;
        u16 *p;
        base = gEntryTable;
        gEntryMode = arg0;
        if (base) {
            u16 limit = gEntryCount;
            i = 0;
            if (limit) {
                s32 items = base;
                do {
                    p = (u16 *)(i * 8 + items + 2);
                    i++;
                    *p = (*p & 0xFFF0) | 1;
                } while (i < limit);
            }
        }
        break;
    }
    case 4:
    case 9: {
        u16 x, count;
        s32 base;
        u16 *p;
        count = gEntryCount;
        i = 0;
        if (count) {
        base = gEntryTable;
        do {
            p = (u16 *)(i * 8 + base + 2);
            x = *p;
            if ((x & 15) != 0) goto nonzero;
            if ((x & 0xF0) == 0) goto skip;
nonzero:
            if ((x & 15) != 1) *p = (x & 0xFFF0) | 2;
skip:;
            i++;
        } while (i < count);
        }
        gEntryMode = func_80030D40();
    }
    case 7:
        gEntryMode = arg0;
        break;
    }
}
