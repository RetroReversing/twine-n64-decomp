extern u16 D_800F38BC[];
extern s32 *D_800F38C0;
extern volatile s32 sortedEntryCount;
extern s32 sortedEntryValues;
extern s32 func_800986DC(s32, s32);
extern s32 binarySearchRecords(s32, s32, s32, s32, s32 (*)(s32, s32));

s32 func_8009846C(u16 key) {
    s32 count;
    s32 *result;
    s32 value;

    count = sortedEntryCount;
    D_800F38BC[0] = key;
    result = (s32 *)binarySearchRecords((s32)(D_800F38BC - 2), (s32)&sortedEntryValues, count, 8, func_800986DC);
    D_800F38C0 = result;
    if (result == NULL) {
        value = 0;
    } else {
        value = *result;
    }
    return value;
}
