/* Returns the 16-bit byte sum of length bytes at data (libultra header checksum). */
u16 __osSumcalc(u8* data, int length) {
    int i;
    u32 sum = 0;
    u8* cursor = data;

    for (i = 0; i < length; i++) {
        sum += *cursor++;
    }

    return sum & 0xFFFF;
}
