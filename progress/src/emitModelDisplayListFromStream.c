typedef struct 
{
  s32 w0;
  u32 w1;
} GfxPair;
extern GfxPair *gGfxPtr;
extern s8 gTextureRegisterPending;
extern s32 gVertexRecordPtr;
extern void buildScaledVertexRecord(s32, s32, s32, s32, s32, s32, s32, f32);
extern void emitTextureLoadCommands(u8 *, s32, s32, s32, s32, s32 *);
extern void gfxAppendTexture(u8 *, s32 *, s32, s32, s32, s32, s32 *);
extern void osWritebackDCache(GfxPair **, s32);
inline static u32 inline_fn(const volatile u8 *arg0)
{
  return arg0[1];
}

/* Interprets a model command stream (vertex, texture and triangle opcodes until 12) and appends F3D display-list commands, or only counts them when enable is 0. */ void emitModelDisplayListFromStream(u8 *p, s32 model, s32 a2, s32 a3, s32 a4, register f32 scale, s32 a6, s32 a7, s32 enable, s32 *vertices, s32 *commands)
{
  struct 
  {
    s32 texture;
    GfxPair *start;

  } state;
  u8 emit;
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
  u32 n_2;
  u32 pairs;
  u32 advance;
  s8 draw;
  state.texture = -1;
  state.start = gGfxPtr;
  gTextureRegisterPending = 0;
  op = *p;
  emit = enable;
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
          {
            u8 x;
            u8 y;
            u8 z;
            q = p + 2;     first = gVertexRecordPtr;     for (i = 0; i < p[1]; i++) {         (x = q[i * 3], y = q[i * 3 + 1], z = q[i * 3 + 2]);         if (draw) {             buildScaledVertexRecord(gVertexRecordPtr, model, a2, a3, x, y, z, scale);             gVertexRecordPtr += 16;         } else {             ++*vertices;         }         }     if (draw) {         GfxPair *gfx;         u32 n;         gfx = gGfxPtr;         gGfxPtr = gfx + 1;         n = p[1];         gfx->w1 = first - 0x80000000U;         gfx->w0 = 0x01000000 | (n << 12) | ((n & 127) << 1);     } else {         ++*commands;     }     ++p;
            advance = (*p) * 3;
          }
            goto add_one;

          case 1:
          {
            u32 x;
            u32 y;
            u32 z;
            u32 xHigh;
            u32 xLow;
            u16 yHigh;
            u32 yLow;
            u32 zHigh;
            u32 zLow;
            q = p + 2;     first = gVertexRecordPtr;     for (i = 0; i < p[1]; i++) {         (xHigh = q[i * 6], xLow = ((u8 *) q)[i * 6 + 1], yHigh = q[i * 6 + 2], zLow = ((u8 *) q)[i * 6 + 5], xHigh <<= 8, x = xHigh + xLow, yLow = ((u8 *) q)[i * 6 + 3], zHigh = q[i * 6 + 4], yHigh <<= 8, y = yHigh + yLow, z = (zHigh << 8) + zLow);         if (draw) {             buildScaledVertexRecord(gVertexRecordPtr, model, a2, a3, x, y, z, scale);             gVertexRecordPtr += 16;         } else {             ++*vertices;         }         }     if (draw) {         GfxPair *gfx;         u32 n;         gfx = gGfxPtr;         gGfxPtr = gfx + 1;         n = p[1];         gfx->w1 = first - 0x80000000U;         gfx->w0 = 0x01000000 | (n << 12) | ((n & 127) << 1);     } else {         ++*commands;     }     ++p;
            advance = (*p) * 3;
            goto double_advance;
          }

          case 3:
          {
            u32 x;
            q = p + 2;     first = gVertexRecordPtr;     for (i = 0; i < p[1]; i++) {         x = ((u8 *) q)[i];         if (draw) {             buildScaledVertexRecord(gVertexRecordPtr, model, a2, a3, x, x, x, scale);             gVertexRecordPtr += 16;         } else {             ++*vertices;         }         }     if (draw) {         GfxPair *gfx;         u32 n;         gfx = gGfxPtr;         gGfxPtr = gfx + 1;         n = p[1];         gfx->w1 = first - 0x80000000U;         gfx->w0 = 0x01000000 | (n << 12) | ((n & 127) << 1);     } else {         ++*commands;     }     ++p;
            advance = (*p) + 1;
          }
            goto advance_stream;

          case 2:
          {
            u32 x;
            u32 y;
            u32 z;
            do
            {
              q = p + 2;     first = gVertexRecordPtr;     for (i = 0; i < p[1]; i++) {         { u32 hi; u32 lo; hi = ((u8 *) q)[i * 2]; lo = ((u8 *) q)[i * 2 + 1]; hi <<= 8; x = (y = (z = (hi + lo))); }         if (draw) {             buildScaledVertexRecord(gVertexRecordPtr, model, a2, a3, x, y, z, scale);             gVertexRecordPtr += 16;         } else {             ++*vertices;         }         }     if (draw) {         GfxPair *gfx;         u32 n;         gfx = gGfxPtr;         gGfxPtr = gfx + 1;         n = p[1];         gfx->w1 = first - 0x80000000U;         gfx->w0 = 0x01000000 | (n << 12) | ((n & 127) << 1);     } else {         ++*commands;     }     ++p;
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
            emitTextureLoadCommands(p, a4, a6, a7, draw, commands);
            ++p;
            goto triangles;

          case 7:
            emitTextureLoadCommands(p, a4, a6, a7, draw, commands);
            gfxAppendTexture(p, &state.texture, a4, a6, a7, draw, commands);
            ++p;
            goto triangles;

          case 8:
            p += 3;

          case 5:
            triangles:
          n_2 = p[1];

            p += 2;
            for (i = 0; i < (pairs = n_2 >> 1); p += 3, i++)
          {
            x = p[0];
            y = p[1];
            z = p[2];
            p += 3;
            a = p[0];
            b = p[1];
            c = p[2];
            if (draw)
            {
              GfxPair *gfx;
              gfx = gGfxPtr;
 gGfxPtr = gfx + 1;
              gfx->w0 = ((((((x)) * 2) & 255) << 16) | ((((y)) << 9) & 0xfe00) | ((((z)) * 2) & 255)) | 0x06000000;
              gfx->w1 = ((((((a)) * 2) & 255) << 16) | ((((b)) << 9) & 0xfe00) | ((((c)) * 2) & 255));
            }
            else
            {
              ++(*commands);
            }
          }

            if (n_2 & 1)
          {
            x = p[0];
            y = p[1];
            z = p[2];
            if (draw)
            {
              GfxPair *gfx;
              gfx = gGfxPtr;
 gGfxPtr = gfx + 1;
              gfx->w0 = ((((((x)) * 2) & 255) << 16) | ((((y)) << 9) & 0xfe00) | ((((z)) * 2) & 255)) | 0x05000000;
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
            while ((*p) == 4)
          {
            x = p[1];
            y = p[2];
            z = p[3];
            if (p[4] == 4)
            {
              a = p[5];
              b = p[6];
              c = p[7];
              if (draw)
              {
                GfxPair *gfx;
                gfx = gGfxPtr;
 gGfxPtr = gfx + 1;
                gfx->w0 = ((((((x)) * 2) & 255) << 16) | ((((y)) << 9) & 0xfe00) | ((((z)) * 2) & 255)) | 0x06000000;
                gfx->w1 = ((((((a)) * 2) & 255) << 16) | ((((b)) << 9) & 0xfe00) | ((((c)) * 2) & 255));
              }
              else
              {
                ++(*commands);
              }
              p += 8;
            }
            else
            {
              if (draw)
              {
                GfxPair *gfx;
                gfx = gGfxPtr;
 gGfxPtr = gfx + 1;
                gfx->w0 = ((((((x)) * 2) & 255) << 16) | ((((y)) << 9) & 0xfe00) | ((((z)) * 2) & 255)) | 0x05000000;
                gfx->w1 = 0;
              }
              else
              {
                ++(*commands);
              }
              p += 4;
            }
          }

            break;

          case 10:
            emitTextureLoadCommands(p, a4, a6, a7, draw, commands);
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
  if ((emit << 24) != 0)
  {
    s32 size;
    GfxPair *next;
    GfxPair *gfx;
    gfx = gGfxPtr;
    next = gfx + 1;
    gGfxPtr = next;
    size = ((u32) next) - ((u32) state.start);
    gfx->w0 = 0xdf000000;
    gfx->w1 = 0;
    osWritebackDCache(&state.start, size);
  }
  else
  {
    ++(*commands);
  }
}
