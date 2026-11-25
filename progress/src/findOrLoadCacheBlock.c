extern void romDmaRead(void *, void *, s32);
extern s32 D_00437E38;
extern s16 sCacheNextSlot;
extern s16 sCacheLastSlot;
extern s16 sCacheBlockIds[6];
extern u8 sCacheBlockData[192];
extern u8 D_F8D70;

/* Returns the cached 32-byte block for blockId, searching from the last hit; on a miss, DMAs it into the next ring slot. */
s16 *findOrLoadCacheBlock(s32 blockId) {

    s16 *var_v1;
    s16 *table_base = sCacheBlockIds;
    u8 *cache_base = sCacheBlockData;
    s32 temp_a1;
    s32 var_s1;
    
    register void *temp_s0;

    var_s1 = sCacheLastSlot;
    temp_a1 = var_s1;
    var_v1 = table_base + var_s1;
do {
    if (*var_v1 == blockId) {
        sCacheLastSlot = var_s1;
        return (void *)((var_s1 << 5) + (u32)cache_base);
    }
    var_s1 -= 1;
    var_v1 -= 1;
    if (var_s1 < 0) {
        var_v1 = table_base + 5;
        var_s1 = 5;
    }
    } while (var_s1 != temp_a1);
    {
            void *src;
            var_s1 = sCacheNextSlot;
            var_s1 -= 1;
            if (var_s1 < 0) {
                var_s1 = 5;
            }
            temp_s0 = sCacheBlockData + (var_s1 << 5);
            src = (void *)((blockId << 5) + ((u32)&D_F8D70 + (u32)&D_00437E38));
            sCacheNextSlot = var_s1;
            romDmaRead(temp_s0, src, 0x20);
            sCacheBlockIds[var_s1] = blockId;
            sCacheLastSlot = var_s1;
            return temp_s0;
    }
}
