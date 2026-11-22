#define TRI(a,b,c) (((((a) * 2) & 255) << 16) | (((b) << 9) & 0xfe00) | (((c) * 2) & 255))
#define WORD(p) (((p)[0] << 8) + (p)[1])
#define VERTICES(step, read)     q = p + 2;     first = D_8010D2B4;     i = 0;     if (p[1]) do {         read;         if (draw) {             func_800328CC(D_8010D2B4, model, a2, state.vertexTransform, x, y, z, scale);             D_8010D2B4 += 16;         } else {             ++*vertices;         }         ++i;         q += step;     } while (i < p[1]);     if (draw) {         gfx = gGfxPtr;         gGfxPtr = gfx + 1;         n = p[1];         gfx->w1 = first - 0x80000000U;         gfx->w0 = (n << 12) | (((n & 127) << 1) | 0x01000000);     } else {         ++*commands;     }     ++p
typedef struct 
{
  u32 w0;
  u32 w1;
} GfxPair;
extern GfxPair *gGfxPtr;
extern s8 D_80109A94;
extern s32 D_8010D2B4;
extern void func_800328CC(s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_80032978(u8 *, s32, s32, s32, s32, s32 *);
extern void gfxAppendTexture(u8 *, s32 *, s32, s32, s32, s32, s32 *);
extern void func_800A0220(GfxPair **, s32);
void func_800336FC(u8 *p, s32 model, s32 a2, s32 a3, s32 a4, register f32 scale, s32 a6, s32 a7, s32 enable, s32 *vertices, s32 *commands)
{
  struct 
  {
    s32 texture;
    GfxPair *start;
    s32 unused;
    volatile s32 vertexTransform;
    u8 padding[7];
    volatile u8 emit;
  } state;
  u32 savedSpace[6];
  GfxPair *gfx;
  const volatile u8 *q;
  s32 first;
  u8 x;
  u8 y;
  u8 z;
  u8 a;
  u8 b;
  u8 c;
  u8 op;
  u32 i;
  u32 n;
  u32 pairs;
  u32 advance;
  s8 draw;
  state.vertexTransform = a3;
  state.texture = -1;
  state.start = gGfxPtr;
  D_80109A94 = 0;
  op = *p;
  state.emit = enable;
  if (op != 12)
  {
    draw = (s8) enable;
    do
    {
      if (op < 12)
      {
        switch (op)
        {
          case 9:
            p += 4;
            break;

          case 0:
            VERTICES(3, (x = q[0], y = q[1], z = q[2]));
            advance = (*p) * 3;
            goto add_one;

          case 1:
          {
            u32 x;
            u32 y;
            u32 z;
            u32 xHigh;
            volatile unsigned int xLow;
            u32 yHigh;
            u32 yLow;
            u32 zHigh;
            u32 zLow;
            VERTICES(6, (xHigh = q[0], xLow = q[1], (double) (yHigh = q[2]), zLow = q[5], x = (xHigh << 8) + xLow, yLow = q[3], zHigh = q[4], y = (yHigh << 8) + yLow, z = (zHigh << 8) + zLow));
            advance = (*p) * 3;
            goto double_advance;
          }

          case 3:
            VERTICES(1, x = (y = (z = q[0])));
            advance = (*p) + 1;
            goto advance_stream;

          case 2:
          {
            u32 x;
            u32 y;
            u32 z;
            do
            {
              VERTICES(2, x = (y = (z = WORD(q))));
            }
            while (0);
          }
            advance = *p;
            double_advance:
          advance *= 2;

            add_one:
          advance++;

            advance_stream:
          p += advance;

            break;

          case 6:
            gfxAppendTexture(p, &state.texture, a4, a6, a7, draw, commands);
            ++p;
            func_80032978(p, a4, a6, a7, draw, commands);
            ++p;
            goto triangles;

          case 7:
            func_80032978(p, a4, a6, a7, draw, commands);
            gfxAppendTexture(p, &state.texture, a4, a6, a7, draw, commands);
            ++p;
            goto triangles;

          case 8:
            p += 3;

          case 5:
            triangles:
          n = p[1];

            p += 2;
            q = p + 2;
            for (i = 0; i < (pairs = n >> 1); i++, q += 3, p += 3)
          {
            x = p[0];
            y = q[-1];
            z = q[0];
            q += 3;
            p += 3;
            a = p[0];
            b = q[-1];
            c = q[0];
            if (draw)
            {
              gfx = gGfxPtr++;
              gfx->w0 = TRI(x, y, z) | 0x06000000;
              gfx->w1 = TRI(a, b, c);
            }
            else
            {
              ++(*commands);
            }
          }

            if (n & 1)
          {
            x = p[0];
            y = p[1];
            z = p[2];
            if (draw)
            {
              gfx = gGfxPtr++;
              gfx->w0 = TRI(x, y, z) | 0x05000000;
              gfx->w1 = 0;
            }
            else
            {
              ++(*commands);
            }
            p += 3;
          }
            break;

          case 4:
            q = p + 7;
            while ((*p) == 4)
          {
            x = q[-6];
            y = q[-5];
            z = q[-4];
            if (q[-3] == 4)
            {
              a = q[-2];
              b = q[-1];
              c = q[0];
              if (draw)
              {
                gfx = gGfxPtr++;
                gfx->w0 = TRI(x, y, z) | 0x06000000;
                gfx->w1 = TRI(a, b, c);
              }
              else
              {
                ++(*commands);
              }
              q += 8;
              p += 8;
            }
            else
            {
              if (draw)
              {
                gfx = gGfxPtr++;
                gfx->w0 = TRI(x, y, z) | 0x05000000;
                gfx->w1 = 0;
              }
              else
              {
                ++(*commands);
              }
              q += 4;
              p += 4;
            }
          }

            break;

          case 10:
            func_80032978(p, a4, a6, a7, draw, commands);
            p += 2;
            break;

          case 11:
            gfxAppendTexture(p, &state.texture, a4, a6, a7, draw, commands);
            p += 2;
            break;

        }

      }
      op = *p;
    }
    while (op != 12);
  }
  if ((state.emit << 24) != 0)
  {
    s32 size;
    GfxPair *next;
    gfx = gGfxPtr;
    next = gfx + 1;
    gGfxPtr = next;
    size = ((u32) next) - ((u32) state.start);
    gfx->w0 = 0xdf000000;
    gfx->w1 = 0;
    func_800A0220(&state.start, size);
  }
  else
  {
    ++(*commands);
  }
}


