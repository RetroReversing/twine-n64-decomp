typedef struct { u16 id; u16 flags; s32 data; } Ent8;
typedef struct { u16 id; u16 count; } Hdr;
typedef struct { u8 pad[8]; Hdr *a; Hdr *b; Hdr *c; } Tbl;
extern Ent8 *gEntryTable;
extern Tbl *D_800BFF08;
extern u16 gEntryCount;
extern u16 D_800E160A;

u16 func_80031028(u16 kind, u16 mode) {
    Hdr *h;
    u16 i;
    u16 n;

    switch (kind) {
    case 0:
        if (gEntryTable == NULL) {
            return 0;
        }
        if (mode == 1) {
            i = 0;
            n = 0;
            for (; i < gEntryCount; i++) {
                if (!(gEntryTable[i].flags & 0x200) && (gEntryTable[i].flags & 0xF000) <= D_800E160A) {
                    n++;
                }
            }
            return n;
        }
        return gEntryCount;
    case 2:
        h = D_800BFF08->b;
        break;
    case 3:
        h = D_800BFF08->c;
        break;
    case 1:
        h = D_800BFF08->a;
        break;
    default:
        return 0;
    }
    if (h == NULL) {
        return 0;
    }
    return h->count;
}
