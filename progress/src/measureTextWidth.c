typedef struct KernTab
{
  u8 *pairs;
  u8 count;
} KernTab;
typedef struct Font
{
  u8 pad0[8];
  u8 *glyphs;
  u8 *kern;
  u8 spaceW;
  s8 extra;
} Font;
Font *getFont();
u16 getGlyphWidth();
/* Measures the pixel width of a string using a font, handling tabs, spaces, color/control codes and kerning; stops at newline or when the width limit is reached. */ u32 measureTextWidth(u8 *text, u16 length, s32 unused, s32 fontId, u16 maxWidth)
{
  Font *font;
  u32 maxLimit;
  u32 width;
  u32 total;
  u32 charCount;
  u32 chr;
  s32 glyphIndex;
  u32 k;
  u8 *p;
  u8 ch;
  s32 off;
  u8 *kern;
  KernTab *kt;
  s32 advance;
  u8 *cursor;
  volatile u32 pad[1];
  total = 0;
  font = getFont(fontId);
  maxLimit = maxWidth;
  if (font == 0)
  {
    return 0;
  }
  charCount = 0;
  width = 0;
  if (length != 0)
  {
    cursor = text;
    do
    {
      do
      {
        ch = *cursor;
        switch (ch)
        {
          case 9:
            width = ((width >> 5) + 1) << 5;
            break;
            do
          {
            case 10:
              if (maxLimit != 0)
            {
              return total;
            }

            return width;
            case 32:
              width += font->spaceW;

            total += font->spaceW;
            break;
            case 1:
              case 2:
              case 5:
              case 6:
              case 7:
              cursor++;





            charCount++;
            break;
            case 3:
              case 4:
              cursor++;


            charCount++;
            maxLimit = (*((s8 *) cursor)) * 2;
            break;
            default:
              *cursor = ch;

            chr = ch; glyphIndex = ch - 0x21;
            if ((maxLimit != 0) && ((total + getGlyphWidth(font, cursor)) >= maxLimit))
            {
              return total;
            }
            if (font->kern != 0)
            {
                for (k = 0; k < ((KernTab *) font->kern)[glyphIndex].count; k++) {
                    if (((KernTab *) font->kern)[glyphIndex].pairs[k * 2] == ch) { width -= (s8) ((KernTab *) font->kern)[glyphIndex].pairs[k * 2 + 1]; break; }
                }
            }
do {
            advance = font->glyphs[(glyphIndex * 5) + 2] + font->extra; width += advance; total += advance;

} while (0);
            break;
          }
          while (0);

        }

        charCount++;
      }
      while (0);
      cursor++;
    }
    while (charCount < length);
  }
  if ((maxLimit != 0) && (maxLimit < width))
  {
    return maxLimit;
  }
  return width;
}


