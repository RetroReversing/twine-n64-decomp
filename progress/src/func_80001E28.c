extern s16 *D_800AE4DC[];
extern s16 D_800AE53C[];

s32 func_80001E28(s32 c) {
    s16 **t;
    s16 *r;
    s32 n;
    s16 *p;

    if ((u32)(c - 0x2B) < 0x5E) {
        t = D_800AE4DC;
        p = *t;
        r = D_800AE53C;
        if (p != NULL) do {
            if (**t++ == c) {
                n = 1;
                r += 3;
                while (*r == 0xE) {
                    r += 3;
                    n++;
                }
                return n;
            }
            while (*r >= 0) {
                r += 3;
            }
            r++;
        } while (*t != NULL);
    }
    return 0;
}
