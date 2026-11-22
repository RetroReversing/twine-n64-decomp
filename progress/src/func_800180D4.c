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
Font *func_80018510();
u16 func_80018578();
u32 func_800180D4(u8 *arg0, u16 arg1, s32 arg2, s32 arg3, u16 arg4)
{
  Font *font;
  u32 limit;
  u32 width;
  u32 total;
  u32 i;
  u32 c;
  s32 idx;
  u32 k;
  u8 *p;
  u8 ch;
  s32 off;
  u8 *kern;
  KernTab *kt;
  s32 adv;
  u8 *str;
  volatile u32 pad[1];
  total = 0;
  font = func_80018510(arg3);
  limit = arg4;
  if (font == 0)
  {
    return 0;
  }
  i = 0;
  width = 0;
  if (arg1 != 0)
  {
    str = arg0;
    do
    {
      do
      {
        ch = *str;
        switch (ch)
        {
          case 9:
            width = ((width >> 5) + 1) << 5;
            break;
            do
          {
            case 10:
              if (limit != 0)
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
              str++;





            i++;
            break;
            case 3:
              case 4:
              str++;


            i++;
            limit = (*((s8 *) str)) * 2;
            break;
            default:
              *str = ch;

            c = ch; idx = ch - 0x21;
            if ((limit != 0) && ((total + func_80018578(font, str)) >= limit))
            {
              return total;
            }
            if (font->kern != 0)
            {
                for (k = 0; k < ((KernTab *) font->kern)[idx].count; k++) {
                    if (((KernTab *) font->kern)[idx].pairs[k * 2] == ch) { width -= (s8) ((KernTab *) font->kern)[idx].pairs[k * 2 + 1]; break; }
                }
            }
do {
            adv = font->glyphs[(idx * 5) + 2] + font->extra; width += adv; total += adv;

} while (0);
            break;
          }
          while (0);

        }

        i++;
      }
      while (0);
      str++;
    }
    while (i < arg1);
  }
  if ((limit != 0) && (limit < width))
  {
    return limit;
  }
  return width;
}


