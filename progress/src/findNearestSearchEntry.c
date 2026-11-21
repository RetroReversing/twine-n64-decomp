f32 approxDistance(void *posA, void *posB);
extern s32 sSearchEntries;
extern u32 sSearchEntryCount;

/* Returns the index of the search entry nearest to the object's position (object pos at +0x24, lowered by a height offset in states 2 and 3). */
u32 findNearestSearchEntry(void *obj) {
    struct {
        s32 x;
        f32 y;
        s32 z;
    } objPos;
    volatile s32 reserve[2];
    void *objPosPtr;
    f32 dist;
    f32 bestDist = 65536.0f;
    u32 i = 0;
    u32 nearest = 0;
    s32 off;
    u32 count = sSearchEntryCount;

    if (count) {
        objPosPtr = &objPos;
        off = 0;
        do {
            objPos = *(typeof(objPos) *)((u8 *)obj + 0x24);
            if ((u32)(*(u16 *)((u8 *)obj + 0x78) - 2) < 2) {
                objPos.y -= *(f32 *)(*(u8 **)((u8 *)obj + 0x68) + 0x38);
            }
            dist = approxDistance(objPosPtr, *(s32 *)(off + sSearchEntries + 0x10));
            if (dist < bestDist) {
                bestDist = dist;
                nearest = i;
            }
            i++;
            off += 0x58;
        } while (i < sSearchEntryCount);
    }
    return nearest;
}
