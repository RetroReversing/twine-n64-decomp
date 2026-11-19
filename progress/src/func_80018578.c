typedef struct { u8 pad0[2]; u8 width; u8 pad3[2]; } Glyph18578;
typedef struct { u8 pad0[8]; Glyph18578 *glyphs; u8 padC[5]; s8 spacing; } Font18578;

u16 func_80018578(Font18578 *font, char *s) {
    u16 w = 0;
    u16 i;
    u8 c;

    if (font == NULL || s == NULL) {
        return 0;
    }
    for (i = 0; s[i] != 0; i++) {
        c = s[i];
        switch (c) {
        case 0:
        case 9:
        case 10:
        case ' ':
            return w;
        }
        w += font->glyphs[c - 0x21].width + font->spacing;
    }
    return w;
}
