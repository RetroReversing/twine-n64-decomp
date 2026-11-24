/* identical to memcpy in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
/* Copies n bytes from src to dst, one byte at a time. Returns dst. */
/* Copies n bytes from src to dst, one byte at a time. Returns dst. */ u8 *memcpy(u8 *dst, u8 *src, s32 n) {
    s32 remaining;
    u8 *s;
    u8 *d;
    u8 value;

    s = src;
    remaining = n;
    d = dst;
    if (remaining != 0) {
        do {
            value = *s;
            s += 1;
            remaining -= 1;
            *d = value;
            d += 1;
        } while (remaining != 0);
    }
    return dst;
}
