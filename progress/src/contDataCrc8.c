/* identical to contDataCrc8 in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
/* CRC-8 over the 32 data bytes of a controller pak block (polynomial 0x85), followed
 * by the 8 trailing bits; returns the checksum byte. */
/* CRC-8 (poly 0x85) over 32 controller pak data bytes plus 8 trailing zero bits; returns the checksum. */ u8 contDataCrc8(u8 *data)
{
    u32 crc = 0;
    u32 byteCount;
    u32 mask;

    for (byteCount = 0x20; byteCount; --byteCount) {
        for (mask = 0x80; mask; mask >>= 1) {
            crc <<= 1;

            if ((*data & mask) != 0) {
                if ((crc & 0x100) != 0) {
                    crc ^= 0x84;
                } else {
                    ++crc;
                }
            } else if (crc & 0x100) {
                crc ^= 0x85;
            }
        }

        data++;
    }
    do {
        crc <<= 1;

        if (crc & 0x100) {
            crc ^= 0x85;
        }
    } while (++byteCount < 8U);

    return crc;
}
