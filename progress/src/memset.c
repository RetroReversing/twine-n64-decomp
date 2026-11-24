/* Sets n bytes at dst to the low byte of c. Writes the unaligned head and tail a byte or
   halfword at a time and the aligned middle a word at a time. Returns dst. */
#ifdef PORT
void *memset(void *dst, s32 c, u32 n)
#else
s32 memset(s32 dst, s32 c, u32 n)
#endif
{
    u32 fill;
#ifdef PORT
    u8 *p;
#else
    s32 p;
#endif
    u32 remaining;
    s32 wordCount;

    if (n != 0) {
        fill = c & 0xFF;
        fill = fill | (fill << 8);
        fill = fill | (fill << 16);
        p = dst;
        remaining = n;
#ifdef PORT
        if (((uintptr_t)p & 1)) {
#else
        if (p & 1) {
#endif
            *((s8 *)p) = fill;
            p += 1;
            remaining -= 1;
        }
        wordCount = remaining >> 2;
        if (remaining >= 2) {
#ifdef PORT
            if (((uintptr_t)p & 2)) {
#else
            if (p & 2) {
#endif
                *((s16 *)p) = fill;
                p += 2;
                remaining -= 2;
                wordCount = remaining >> 2;
            }
        }
        wordCount -= 1;
        if (wordCount != -1) {
            do {
                *((s32 *)p) = fill;
                wordCount -= 1;
                p += 4;
            } while (wordCount != -1);
        }
        if (remaining & 2) {
            *((s16 *)p) = fill;
            p += 2;
        }
        if (remaining & 1) {
            *((s8 *)p) = fill;
        }
    }
    return dst;
}
