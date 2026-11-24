/* Comparator for sorted lookups: orders two u16 keys. */
s32 compareU16Key(const u16 *keyA, const u16 *keyB) {
    return *keyA - *keyB;
}
s32 compareCurveKey(const u16 *left, const u16 *right) {
    return left[2] - right[2];
}
s32 compareSoundRecordKey(const u16 *left, const u16 *right) {
    return *left - *right;
}
u32 readSpStatus(void) {
    return *(volatile u32 *)0xA4040010;
}
