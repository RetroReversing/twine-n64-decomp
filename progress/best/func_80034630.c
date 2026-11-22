extern s32 D_8010A4D4;
extern void *sDisplayListCursor;
void func_80034630(const void *arg0, const void *arg1)
{
  f32 fa, ox, oy, x0, y0, x1, y1, a, b, c, d, e, f;
  void *temp_a1;
  char *p;
fa = *((f32 *) (((char *) arg1) + 0x58));
  p = *((void **) (((char *) arg0) + 0x20));
  oy = *((f32 *) (((char *) arg1) + 0x64));
ox = *((f32 *) (((char *) arg1) + 0x60));
fa = fa + oy;
x0 = *(f32 *)(p + 0) + ox;
  y0 = *(f32 *)(p + 8) + oy;
if (arg0) { x1 = *(f32 *)(p + 4) + ox; } else { x1 = *(f32 *)(p + 4) + ox; }
  y1 = *(f32 *)(p + 0xC) + oy;
  x0 -= 8.0f; y0 -= 8.0f; x1 += 8.0f; y1 += 8.0f;
c = *(f32 *)((char *)arg1 + 0x70);
a = (*(f32 *)((char *)arg1 + 0x50) + ox) + c;
d = *(f32 *)((char *)arg1 + 0x74);
f = fa + d;
b = (*(f32 *)((char *)arg1 + 0x54) + ox) - c;
e = (*(f32 *)((char *)arg1 + 0x5C) + oy) - d;
  if (x0 < a) x0 = a;
  if (b < x1) x1 = b;
  if (y0 < f) y0 = f;
  if (e < y1) y1 = e;
  if (D_8010A4D4 != 0)
  {
    temp_a1 = sDisplayListCursor;
    sDisplayListCursor = temp_a1 + 8;
    {
      u32 x = (((s32) (x0 * 4.0f)) & 0xFFF) << 12;
      u32 y = ((s32) (y0 * 4.0f)) & 0xFFF;
      *((u32 *) temp_a1) = (0xED000000 | x) | y;
    }
    *((s32 *) (((char *) temp_a1) + 4)) = (s32) (((((s32) (x1 * 4.0f)) & 0xFFF) << 0xC) | (((s32) (y1 * 4.0f)) & 0xFFF));
  }
}
