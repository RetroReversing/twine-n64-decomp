extern s32 gScissorEnabled;
extern void *sDisplayListCursor;
/* Emits a G_SETSCISSOR command: object bounds (8px margin) intersected with the view clip rectangle. */ void emitClippedScissor(const void *obj, const void *view)
{
  f32 originX;
  f32 marginY;
  f32 originY;
  f32 marginX;
  f32 clipLeft;
  f32 clipBottom;
  f32 clipTop;
  f32 clipTopBase;
  f32 clipRight;
  f32 left;
  f32 right;
  f32 top;
  f32 bottom;
  void *cmd;
  void *bounds;
  originY = *((f32 *) (((char *) view) + 0x64));
  bounds = *((void **) (((char *) obj) + 0x20));
  originX = *((f32 *) (((char *) view) + 0x60));
  left = (*((f32 *) (((char *) bounds) + 0))) + originX;
  top = (*((f32 *) (((char *) bounds) + 8))) + originY;
  right = (*((f32 *) (((char *) bounds) + 4))) + originX;
  bottom = (*((f32 *) (((char *) bounds) + 0xC))) + originY;
  left -= 8.0f;
  top -= 8.0f;
  right += 8.0f;
  bottom += 8.0f;
  marginX = *((f32 *) (((char *) view) + 0x70));
  clipLeft = ((*((f32 *) (((char *) view) + 0x50))) + originX) + marginX;
  marginY = *((f32 *) (((char *) view) + 0x74));
  clipTopBase = (*((f32 *) (((char *) view) + 0x58))) + originY;
  clipTop = clipTopBase + marginY;
  clipRight = ((*((f32 *) (((char *) view) + 0x54))) + originX) - marginX;
  clipBottom = ((*((f32 *) (((char *) view) + 0x5C))) + originY) - marginY;
  if (left < clipLeft)
  {
    left = clipLeft;
  }
  if (clipRight < right)
  {
    right = clipRight;
  }
  if (top < clipTop)
  {
    top = clipTop;
  }
  if (clipBottom < bottom)
  {
    bottom = clipBottom;
  }
  if (gScissorEnabled != 0)
  {
    cmd = sDisplayListCursor;
    sDisplayListCursor = cmd + 8;
    {
      u32 x = (((s32) (left * 4.0f)) & 0xFFF) << 12;
      u32 y = ((s32) (top * 4.0f)) & 0xFFF;
      *((u32 *) cmd) = (0xED000000 | x) | y;
    }
    *((s32 *) (((char *) cmd) + 4)) = (s32) (((((s32) (right * 4.0f)) & 0xFFF) << 0xC) | (((s32) (bottom * 4.0f)) & 0xFFF));
  }
}
