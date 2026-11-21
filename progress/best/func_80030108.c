#define PTR(n) (*(void * volatile *)((char *)arg0 + (n)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))
#define H(p, o) (*(volatile u16 *)((char *)(p) + (o)))
#define W(p, o) (*(volatile u32 *)((char *)(p) + (o)))
s32 func_80030108(void *arg0)
{
  s32 ret, t; u32 p0, p1, p2, p3, p4, p5, p6, p7, p8, g, ee, xb; u16 h0, h1; u32 b0, b1, b2; void *q2, *q3, *q4;
  u8 pad[8];
  ret = 1;
  p3 = (u32)PTR(4);
  if (p3 != 0) {
    g = B((void *)p3, 0x11);
    p3 = W((void *)p3, 0x10);
    if (g != 0) {
      p3 = p3 >> 24;
      t = (s16)p3 - 0x20;
      if (t >= 0) { p3 = p3 - 0x20; if (t >= 37) p3 = 36; } else p3 = 0;
      h0 = H(PTR(4), 0x10);
      t = (h0 & 0xFF) - 0x20;
      if (t >= 0) { h0 = h0 - 0x20; if (t >= 108) h0 = 107; } else h0 = 0;
      ee = W(PTR(4), 0x10) >> 8;
      t = (ee & 0xFF) - 0x20;
      if (t >= 0) { p4 = ee - 0x20; if (t >= 97) p4 = 96; } else p4 = 0;
      q2 = PTR(4);
      W(q2, 0x10) = (p3 << 24) | ((h0 & 0xFF) << 16) | ((p4 & 0xFF) << 8) | B(q2, 0x13);
      p8 = B(PTR(0xC), 0x10);
      t = (s16)p8 - 0x20;
      if (t >= 0) { p8 = p8 - 0x20; if (t >= 256) p8 = 255; } else p8 = 0;
      p0 = B(PTR(0xC), 0x10);
      t = (s16)p0 - 0x20;
      if (t >= 0) { p0 = p0 - 0x20; if (t >= 256) p0 = 255; } else p0 = 0;
      p7 = B(PTR(0xC), 0x10);
      t = (s16)p7 - 0x20;
      if (t >= 0) { p4 = p7 - 0x20; if (t >= 256) p4 = 255; } else p4 = 0;
      ret = 0;
      q3 = PTR(0xC);
      W(q3, 0x10) = (p8 << 24) | ((p0 & 0xFF) << 16) | ((p4 & 0xFF) << 8) | B(q3, 0x10);
    }
  }
  q4 = PTR(0x10);
  if (q4 != NULL) {
    xb = *(u8 *)((char *)q4 + 0x10);
    if (xb != 0) {
      t = (s16)xb - 0x20;
      if (t >= 0) { p0 = xb - 0x20; if (t >= 256) p0 = 255; } else p0 = 0;
      p0 &= 0xFF;
      ee = (p0 << 24) | (p0 << 16) | (p0 << 8) | 0xFF;
      W(PTR(0x10), 0x10) = ee;
      W(PTR(0x14), 0x10) = ee;
      W(PTR(0x18), 0x10) = ee;
      W(PTR(0x1C), 0x10) = ee;
      W(PTR(0x20), 0x10) = ee;
      ret = 0;
      W(PTR(0x24), 0x10) = ee;
    }
  }
  return ret;
}
