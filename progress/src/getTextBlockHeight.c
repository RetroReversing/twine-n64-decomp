s32 countTextLines();
void *getFont();
/* Returns the pixel height of a text block: line count (clamped) times line pitch (font line height + 3) plus one line height. */ s32 getTextBlockHeight(s32 text, u16 textId, s32 fontId)
{
  u32 extraLines;
  u32 clampedExtraLines;
  s32 lineCount;
  u8 lineHeight;
  void *font;
  lineCount = countTextLines(text, textId & 0xFFFF);
  font = getFont(fontId);
  extraLines = lineCount - 1;
  clampedExtraLines = 0x7D00;
  if (extraLines < 0x7D01U)
  {
    clampedExtraLines = extraLines;
  }
  if (font || lineCount)
  {
    lineHeight = *((u8 *) (((char *) (*((void **) (((char *) font) + 8)))) + 0x148));
    return (clampedExtraLines * (lineHeight + 3)) + lineHeight;
  }
  else
  {
    lineHeight = *((u8 *) (((char *) (*((void **) (((char *) font) + 8)))) + 0x148));
    return (clampedExtraLines * (lineHeight + 3)) + lineHeight;
  }
}

