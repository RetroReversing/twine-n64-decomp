s32 compareU16Key(const u16 *left, const u16 *right) {
    return *left - *right;
}
s32 compareCurveKey(const u16 *left, const u16 *right) {
    return left[2] - right[2];
}
/* Comparator for sound records: orders by the leading u16 key. */ s32 compareSoundRecordKey(const u16 *left, const u16 *right) {
    return *left - *right;
}
u32 readSpStatus(void) {
    return *(volatile u32 *)0xA4040010;
}
