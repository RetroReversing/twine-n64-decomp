/* Copies byteCount bytes (a nonzero multiple of 4) from src to dst, one word at a time. */ void copyWords(s32 *dst, s32 *src, s32 byteCount) {
    char *dstCursor;
    char *srcCursor;
    s32 word;
    s32 remaining;
    dstCursor = dst;
    srcCursor = src;
    remaining = byteCount;
    if (remaining != 0) {
        do {
            word = *(s32 *)srcCursor;
            srcCursor += 4;
            remaining -= 4;
            *(s32 *)dstCursor = word;
            dstCursor += 4;
        } while (remaining != 0);
    }
}
