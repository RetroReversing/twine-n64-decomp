/* identical to getCurveTable (matched), with its names changed by decompdecomp */
extern u16 D_800F38C8[];
extern s32 *D_800F38CC;
extern volatile s32 gCountedEntryTotal;
extern s32 sCountedEntries;
extern s32 compareCurveKey(s32, s32);
extern s32 binarySearchRecords(s32, s32, s32, s32, s32 (*)(s32, s32));

/* Looks up a sound key in the sorted mapping table and returns the record's first word, or 0 if absent. */ s32 getSoundMappingTable(u16 soundKey) {
    s32 entryCount;
    s32 *record;
    s32 mapping;

    entryCount = gCountedEntryTotal;
    D_800F38C8[0] = soundKey;
    record = (s32 *)binarySearchRecords((s32)(D_800F38C8 - 2), (s32)&sCountedEntries, entryCount, 8, compareCurveKey);
    D_800F38CC = record;
    if (record == NULL) {
        mapping = 0;
    } else {
        mapping = *record;
    }
    return mapping;
}
