typedef struct {
    u8 pad0[2];
    u8 width;
    u8 pad3[2];
} Glyph18364;

typedef struct {
    u8 pad0[8];
    Glyph18364 *glyphs;
    u8 padC[4];
    u8 spaceWidth;
    s8 spacing;
} Font18364;

s32 *getFont(u32);
u16 getGlyphWidth(Font18364 *, char *);

s32 countTextLines(char *text, u16 size, u32 fontId) {
    u32 wrapWidth = 0;
    s32 width = 0;
    Font18364 *font = (Font18364 *)getFont(fontId);
    u16 length = size;
    s32 lines;
    u32 i;
    u8 symbol;

    if (font == NULL) {
        return 0;
    }
    lines = 1;
    if (length != 0) {
        i = 0;
        do {
            symbol = text[i];
            switch (symbol) {
            case 6:
                i++;
                break;
            case 3:
            case 4:
                i++;
                wrapWidth = (s8)text[i] * 2;
                break;
            case 9:
            case 32:
                width += font->spaceWidth;
                break;
            case 10:
                lines++;
                break;
            case 1:
            case 2:
                break;
            default:
                if (wrapWidth != 0 && width + getGlyphWidth(font, text + i) >= wrapWidth) {
                    width = 0;
                    lines++;
                }
                width += (font->glyphs + symbol - 33)->width + font->spacing;
                break;
            }
            i++;
        } while (i < length);
    }
    return lines;
}
