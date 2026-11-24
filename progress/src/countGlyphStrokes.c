extern s16 *D_800AE4DC[];
extern s16 D_800AE53C[];

/* Looks up a character code (0x2B..0x88) in the glyph tables and returns how many consecutive 0xE-tagged entries its glyph has, or 0 if not found. */ s32 countGlyphStrokes(s32 charCode) {
    s16 **t;
    s16 *r;
    s32 n;
    s16 *p;

    if ((u32)(charCode - 0x2B) < 0x5E) {
        t = D_800AE4DC;
        p = *t;
        r = D_800AE53C;
        if (p != NULL) do {
            if (**t++ == charCode) {
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
