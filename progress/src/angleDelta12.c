/* Signed difference (to - from) of two 12-bit angles, wrapped to -2048..2047. */
s32 angleDelta12(s32 from, s32 to) {
    return (s32) ((to - from) << 0x14) >> 0x14;
}
