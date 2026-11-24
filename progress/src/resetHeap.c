/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce, tried by autopilot */

s32 memset();
extern char gHeapTags[];
extern s32 D_80100904;
extern s32 gHeapStart;
extern s32 gTopBumpAllocPtr;
extern s32 gBumpAllocPtr;
extern s32 gHeapEnd;

/* Clears all heap block tags and resets the bump allocator to span the whole heap, zeroing it. */ void resetHeap(void) {
    s32 tagOffset;
    register u32 tagIndex;

    tagIndex = 0;
    tagOffset = 0;
    do {
        *(s32 *)(gHeapTags + tagOffset) = 0;
        tagIndex += 1;
        tagOffset += 0xC;
    } while (tagIndex < 0x35U);
    D_80100904 = gHeapStart;
    gTopBumpAllocPtr = gHeapEnd;
    gBumpAllocPtr = gHeapStart;
    memset(gHeapStart, 0, gHeapEnd - gHeapStart);
}
