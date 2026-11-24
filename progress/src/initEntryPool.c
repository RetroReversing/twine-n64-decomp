s32 listInsertAfter(s32 *, s32);              /* extern */
s32 heapAllocTagged(s32, s32);                /* extern */
s32 memset(s32, s32, s32);              /* extern */
extern s32 gNodeObjectCount;
extern s32 gEntryPoolBase;
extern s32 D_8010A3D0;
extern s32 D_8010A3D4;
extern s32 D_8010D268;
extern s32 D_8010D268;
extern s32 D_8010D26C;

/* Allocates the pool of 192 44-byte entries, clears it and adds each entry to the list at D_8010D268. */
void initEntryPool(void) {
    s32 pool;
    u32 index;
    s32 byteOffset;

    D_8010A3D0 = 0;
    D_8010A3D4 = 0;
    D_8010D268 = 0;
    D_8010D26C = 0;
    pool = heapAllocTagged(0x2C00, 0xD);
    gEntryPoolBase = pool;
    memset(pool, 0, 0x1640);
    index = 0;
    byteOffset = 0;
    do {
        listInsertAfter(&D_8010D268, gEntryPoolBase + byteOffset);
        index += 1;
        byteOffset += 44;
    } while (index < 192U);
    gNodeObjectCount = 0;
}
