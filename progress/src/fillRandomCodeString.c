extern u32 randomU32Next(void);

/* Fills a string buffer of bufferSize bytes with '0' padding and, every third byte from a random
   start of 0 or 1, a random '2' or '7'; the last byte is the NUL terminator. */
void fillRandomCodeString(u8 *buffer, u32 bufferSize)
{
    u32 index;
    u32 offset;
    s32 limit;
    u32 length;
    buffer[0] = '0';
    length = bufferSize;
    buffer[1] = '0';
    buffer[2] = '0';
    index = randomU32Next() & 1;
    offset = (u16)index;
    if ((s32)offset < (s32)(u16)length - 3) {
        do {
            u8 *entry = buffer + offset;
            u32 random = randomU32Next();
            s32 flag;
            random %= 255U;
            flag = (random < 128U) ^ 1;
            index += 3;
            offset = (u16)index;
            entry[1] = '0';
            entry[2] = '0';
            entry[0] = ((-flag) & 0x37) | 0x32;
            limit = (s32)(u16)length - 3;
        } while ((s32)offset < limit);
    }
    buffer[(u16)length - 1] = 0;
}
