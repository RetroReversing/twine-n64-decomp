extern s16 sCacheNextSlot, sCacheLastSlot, sCacheBlockIds[6];
extern s16 sNextEvictSlot, sLastFoundSlot, sStreamSlotIds[8];
extern s16 sLargeCacheNextSlot, sLargeCacheLastSlot;
extern s32 sLargeCacheBlockIds[6];

/* Resets the block, stream-slot and large-block caches to empty: slot indices 0, all ids set to the "none" sentinel. */
void initResourceCaches(void) {
    u32 count;
    s16 emptyId, *idOut;
    s32 emptyLargeId, *largeIdOut;

    count = 0;
    emptyId = 0x7fff;
    idOut = sCacheBlockIds;
    sCacheLastSlot = 0;
    sCacheNextSlot = 0;
    do {
        *idOut++ = emptyId;
        ++count;
    } while (count < 6);

    count = 0;
    emptyId = 0x7fff;
    idOut = sStreamSlotIds;
    sLastFoundSlot = 0;
    sNextEvictSlot = 0;
    do {
        *idOut++ = emptyId;
        ++count;
    } while (count < 8);

    count = 0;
    emptyLargeId = 0x7fffffff;
    largeIdOut = sLargeCacheBlockIds;
    sLargeCacheLastSlot = 0;
    sLargeCacheNextSlot = 0;
    do {
        *largeIdOut++ = emptyLargeId;
        ++count;
    } while (count < 6);
}
