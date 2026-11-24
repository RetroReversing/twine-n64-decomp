s32 compareU16Key(const u16 *left, const u16 *right) {
    return *left - *right;
}
s32 compareCurveKey(const u16 *left, const u16 *right) {
    return left[2] - right[2];
}
s32 compareSoundRecordKey(const u16 *left, const u16 *right) {
    return *left - *right;
}
/* Reads the RSP status register (SP_STATUS_REG, 0xA4040010). */ u32 readSpStatus(void) {
    return *(volatile u32 *)0xA4040010;
}
