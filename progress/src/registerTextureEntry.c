/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *heapAllocTagged();
extern s32 gTextureEntryCount;
extern char gTextureEntryTable[];
extern s32 gGfxPtr;

/* Allocates a 16-byte texture entry from the header, records it in the global table, and halves the size unless bit 0 of the header flags is set. */ void registerTextureEntry(void *texHeader) {
    s16 size;
    s32 heightPlus1;
    s32 widthPlus1;
    void *entry;

    widthPlus1 = (*(u16 *)((char *)(texHeader) + 2)) + 1;
    heightPlus1 = (*(u16 *)((char *)(texHeader) + 4)) + 1;
    entry = heapAllocTagged(0x10, 0x20);
    {
    s32 slot = gTextureEntryCount;
    s32 gfxData;
    s32 srcData;
    ((void **)gTextureEntryTable)[slot] = entry;
    gfxData = gGfxPtr;
    srcData = *(s32 *)((char *)texHeader + 8);
    size = widthPlus1 * heightPlus1;
    *(s32 *)((char *)entry) = gfxData + 4;
    *(s8 *)((char *)entry + 8) = 0;
    *(s8 *)((char *)entry + 0xA) = 0;
    *(s32 *)((char *)entry + 4) = srcData;
    }
    (*(u8 *)((char *)(entry) + 9)) = (u8) (*(u8 *)((char *)(texHeader) + 6));
    (*(u8 *)((char *)(entry) + 0xB)) = (u8) (*(u8 *)((char *)(texHeader) + 7));
    (*(s16 *)((char *)(entry) + 0xC)) = size;
    if (!((*(u8 *)((char *)(texHeader) + 0)) & 1)) {
        (*(s16 *)((char *)(entry) + 0xC)) = (s16) ((u32) ((unsigned)size & 0xFFFF) >> 1);
    }
    gTextureEntryCount += 1;
}
