/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 noopStubAudioB();
extern s32 sResourceTableCount;
extern s32 sortedEntryCount;
extern s32 gCountedEntryTotal;
extern s32 sLoadedSceneGroupCount;
extern s32 gEntryTableCount;
extern char gEntryBuckets[];
extern char gEntryBucketStarts[];
extern s32 D_800FD560;

/* Clears resource/entry counters and bucket tables, then reinitializes via noopStubAudioB. */ void resetAudioResourceTables(void) {
    s32 byteOffset;

    byteOffset = 0;
    sResourceTableCount = 0;
    sortedEntryCount = 0;
    gCountedEntryTotal = 0;
    sLoadedSceneGroupCount = 0;
    D_800FD560 = 0;
    gEntryTableCount = 0;
    do {
        *(s16 *)(gEntryBuckets + byteOffset) = 0;
        *(s16 *)(gEntryBucketStarts + byteOffset) = 0;
        byteOffset += 4;
    } while (byteOffset < 0x800);
    noopStubAudioB();
}
