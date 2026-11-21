/* identical to func_8009846C (matched), with its names changed by decompdecomp */
extern u16 D_800F38C8[];
extern s32 *D_800F38CC;
extern volatile s32 gCountedEntryTotal;
extern s32 sCountedEntries;
extern s32 func_800986DC(s32, s32);
extern s32 binarySearchRecords(s32, s32, s32, s32, s32 (*)(s32, s32));

s32 func_800984CC(u16 key) {
    s32 count;
    s32 *result;
    s32 value;

    count = gCountedEntryTotal;
    D_800F38C8[0] = key;
    result = (s32 *)binarySearchRecords((s32)(D_800F38C8 - 2), (s32)&sCountedEntries, count, 8, func_800986DC);
    D_800F38CC = result;
    if (result == NULL) {
        value = 0;
    } else {
        value = *result;
    }
    return value;
}
