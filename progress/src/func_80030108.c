#define PTR(n) (*(void * volatile *)((char *)arg0 + (n)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))
#define H(p, o) (*(volatile u16 *)((char *)(p) + (o)))
#define W(p, o) (*(volatile u32 *)((char *)(p) + (o)))
s32 func_80030108(void *arg0)
{
  s32 ret, t; u32 v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, fx, fy; u16 h0, h1; u32 b0, b1, b2; void *q5, *q2, *q3, *q4;
  u8 pad[8];
  ret = 1;
  v3 = (u32)PTR(4);
  if (v3 != 0) {
    t = B((void *)v3, 0x11);
    v3 = W((void *)v3, 0x10);
    if (t != 0) {
      v3 = v3 >> 24;
      t = (s16)v3 - 0x20;
      if (t >= 0) { v3 = v3 - 0x20; if (t >= 37) v3 = 36; } else v3 = 0;
      h0 = H(PTR(4), 0x10);
      t = (h0 & 0xFF) - 0x20;
      if (t >= 0) { h0 = h0 - 0x20; if (t >= 108) h0 = 107; } else h0 = 0;
      v8 = W(PTR(4), 0x10) >> 8;
      t = (v8 & 0xFF) - 0x20;
      if (t >= 0) { v13 = v8 - 0x20; if (t >= 97) v13 = 96; } else v13 = 0;
      q2 = PTR(4);
      W(q2, 0x10) = (v3 << 24) | ((h0 & 0xFF) << 16) | ((v13 & 0xFF) << 8) | B(q2, 0x13);
      v3 = B(PTR(0xC), 0x10);
      t = (s16)v3 - 0x20;
      if (t >= 0) { v3 = v3 - 0x20; if (t >= 256) v3 = 255; } else v3 = 0;
      h0 = B(PTR(0xC), 0x10);
      t = (s16)h0 - 0x20;
      if (t >= 0) { h0 = h0 - 0x20; if (t >= 256) h0 = 255; } else h0 = 0;
      v10 = B(PTR(0xC), 0x10);
      t = (s16)v10 - 0x20;
      if (t >= 0) { v4 = v10 - 0x20; if (t >= 256) v4 = 255; } else v4 = 0;
      ret = 0;
      q3 = PTR(0xC);
      W(q3, 0x10) = (v3 << 24) | ((h0 & 0xFF) << 16) | ((v4 & 0xFF) << 8) | B(q3, 0x10);
    }
  }
  q4 = PTR(0x10);
  if (q4 != NULL) {
    v7 = *(u8 *)((char *)q4 + 0x10);
    if (v7 != 0) {
      t = (s16)v7 - 0x20;
      if (t >= 0) { if (t >= 256) v2 = 255; else v2 = v7 - 0x20; } else v2 = 0;
      q5 = PTR(0x10);
      v12 = v2 & 0xFF;
      v3 = (v12 << 24) | (v12 << 16) | (v12 << 8) | 0xFF;
      W(q5, 0x10) = v3;
      W(PTR(0x14), 0x10) = v3;
      W(PTR(0x18), 0x10) = v3;
      W(PTR(0x1C), 0x10) = v3;
      W(PTR(0x20), 0x10) = v3;
      ret = 0;
      W(PTR(0x24), 0x10) = v3;
    }
  }
  return ret;
}
