extern u8 D_800D1450[];

s32 textScanNextWordSpan(s8 *s) {
    s32 i = 0;
    s32 n = 0;
    s8 c;

    if (s[0] == 0) {
        return 0;
    }
    if (D_800D1450[(u8)s[0]] & 1) {
        do {
            if (s[i] == '\n') {
                s[i] = ' ';
            }
            n++;
            i++;
        } while (D_800D1450[(u8)s[i]] & 1);
    }
    if (s[i] != 0 && !(D_800D1450[(u8)s[i++]] & 1)) {
        s = (s8 *)((u32)i - (0U - (u32)s));
    loop:
        c = *s;
        n++;
        if (c != 0) {
            s++;
            if (!(D_800D1450[(u8)c] & 1)) {
                goto loop;
            }
        }
    }
    return n;
}
