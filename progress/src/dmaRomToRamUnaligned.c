void romDmaRead();
void *memcpy();
void dmaRomToRamUnaligned(u8 *dst, s32 src, u32 len) {
    u8 buf[32];
    u32 n, align;
    s32 odd;
    if (len) {
        odd = src & 1;
        align = (u32)dst & 7;
        if ((src & 1) | ((u32)dst % 8 != 0)) {
            n = 8 - align;
            { s32 aligned_src = src - odd;
            if (len < n) n = len;
            romDmaRead(buf, aligned_src, (n + odd + 1) & ~1); }
            n = align;
            if (n == 0) n = 8;
            if (len < n) n = len;
            memcpy(dst, buf + odd, n);
            src += n + odd;
            dst += n;
            len -= n;
        }
        n = len & ~1;
        if (n) {
            romDmaRead(dst, src, n);
            src += n;
            dst += n;
        }
        if (len & 1) {
            romDmaRead(buf, src, 2);
            *dst = buf[0];
        }
    }
}
