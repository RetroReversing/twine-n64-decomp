extern s16 sLargeCacheNextSlot, sLargeCacheLastSlot;
extern s32 sLargeCacheBlockIds[6];

/* Make blockId the current large-cache slot; if absent, insert it into the next ring-buffer slot. */ void selectLargeCacheBlock(s32 blockId) {
    s32 slot = sLargeCacheLastSlot;
    s32 startSlot = slot;
    u32 tableBase = (u32)sLargeCacheBlockIds;
    u32 entryAddr = tableBase + slot * sizeof(s32);
    do {
        if (*(s32 *)entryAddr == blockId) {
            goto done;
        }
        --slot;
        entryAddr -= sizeof(s32);
        if (slot < 0) {
            entryAddr = tableBase + 5 * sizeof(s32);
            slot = 5;
        }
    } while (slot != startSlot);

    slot = sLargeCacheNextSlot;
    --slot;
    if (slot < 0) {
        slot = 5;
    }
    sLargeCacheNextSlot = slot;
    sLargeCacheBlockIds[slot] = blockId;
done:
    sLargeCacheLastSlot = slot;
}
