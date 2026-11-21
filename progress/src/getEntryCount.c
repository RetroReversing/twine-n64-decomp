typedef struct { u16 id; u16 flags; s32 data; } Ent8;
typedef struct { u16 id; u16 count; } Hdr;
typedef struct { u8 pad[8]; Hdr *a; Hdr *b; Hdr *c; } Tbl;
extern Ent8 *gEntryTable;
extern Tbl *gTextRefTable;
extern u16 gEntryCount;
extern u16 gEntryLevelLimit;

/* Returns the number of entries for a kind: the entry table count (or visible entries in mode 1), or the count stored in a text reference header. */ u16 getEntryCount(u16 kind, u16 countMode) {
    Hdr *hdr;
    u16 idx;
    u16 visibleCount;

    switch (kind) {
    case 0:
        if (gEntryTable == NULL) {
            return 0;
        }
        if (countMode == 1) {
            idx = 0;
            visibleCount = 0;
            for (; idx < gEntryCount; idx++) {
                if (!(gEntryTable[idx].flags & 0x200) && (gEntryTable[idx].flags & 0xF000) <= gEntryLevelLimit) {
                    visibleCount++;
                }
            }
            return visibleCount;
        }
        return gEntryCount;
    case 2:
        hdr = gTextRefTable->b;
        break;
    case 3:
        hdr = gTextRefTable->c;
        break;
    case 1:
        hdr = gTextRefTable->a;
        break;
    default:
        return 0;
    }
    if (hdr == NULL) {
        return 0;
    }
    return hdr->count;
}
