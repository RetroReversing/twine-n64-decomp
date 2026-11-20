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

    do {
        word = *(u32 *)src;
        src += 4;
        if ((word & 0xFF000000U) != 0)
            goto second;
        *out = 0;
        goto done;
second:
        if ((word & 0x00FF0000U) != 0)
            goto third;
        *(u16 *)out = word >> 16;
        goto done;
third:
        if ((word & 0x0000FF00U) == 0)
            goto three_bytes;
        *(u32 *)out = word;
        out += 4;
    } while (word & 0xFF);
    goto done;

three_bytes:
    *(u16 *)out = word >> 16;
    out[2] = 0;
done:
    return dst;
}
