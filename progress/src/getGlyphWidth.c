typedef struct { u8 pad0[2]; u8 width; u8 pad3[2]; } Glyph18578;
typedef struct { u8 pad0[8]; Glyph18578 *glyphs; u8 padC[5]; s8 spacing; } Font18578;

/* Returns the pixel width of text up to the first NUL, tab, newline or space, summing glyph widths plus font spacing. */ s32 getGlyphWidth(Font18578 *font, char *text) {
    u16 totalWidth = 0;
    u16 index;
    u8 ch;

    if (font == NULL || text == NULL) {
        return 0;
    }
    for (index = 0; text[index] != 0; index++) {
        ch = text[index];
        switch (ch) {
        case 0:
        case 9:
        case 10:
        case ' ':
            return totalWidth;
        }
        totalWidth += font->glyphs[ch - 0x21].width + font->spacing;
    }
    return totalWidth;
}
