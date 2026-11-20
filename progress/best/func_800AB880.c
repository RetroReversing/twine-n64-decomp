u8 *func_800AB880(u8 *dst, u8 *src) {
    u8 *out = dst;
    u32 word;
    u8 ch;

    if ((((u32)src - (u32)dst) & 3) == 0)
        goto check_alignment;

    ch = *src;
    *out = ch;
    src++;
    out++;
    if (ch == 0)
        goto done;
    do {
        ch = *src;
        *out = ch;
        src++;
        out++;
    } while (ch != 0);
    goto done;

    do {
        ch = *src;
        *out = ch;
        src++;
        out++;
        if (ch == 0)
            goto done;
check_alignment:
        ;
    } while ((u32)out & 3);

word_copy:
    word = *(u32 *)src;
    src += 4;
    if (!(word & 0xFF000000U)) {
        *out = 0;
    } else if (!(word & 0xFF0000U)) {
        *(u16 *)out = word >> 16;
    } else if (word & 0xFF00U) {
        *(u32 *)out = word;
        out += 4;
        if (word & 0xFFU)
            goto word_copy;
    } else {
        *(u16 *)out = word >> 16;
        out[2] = 0;
    }
done:
    return dst;
}
