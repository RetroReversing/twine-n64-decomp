static __inline__ int __repair_inline(s32 a, s32 b) { return a > b; }
typedef struct 
{
  s16 frameCount;
  s16 shape;
  s32 romOffset;
  f32 scale[3];
  f32 offset[3];
} FrameCache;
typedef struct 
{
  s16 count;
  s16 rest[3];
} ShapeEntry;
void *findOrLoadCacheBlock(s32);
void romDmaRead(s32, s32, u32);
extern ShapeEntry D_800C3928[];
extern s32 (*D_800D9424)(f32 *, void *);
extern char D_000F8D70[];
void func_800055CC(s32 *out, u32 id, u32 frame, s32 expand)
{
  f32 decoded[3];
  u32 scratch[6];
  FrameCache *cache;
  u32 shape;
  s32 count;
  s32 coordWords;
  s32 totalWords;
  s32 vectors;
  s32 packedWords;
  s32 packedBytes;
  u32 header;
  s32 i;
  s32 dstIndex;
  u16 *packed;
  f32 *coords;
  u16 *packedStart;
  char *romBase = D_000F8D70;
  s32 validFrame;
  if (id >= 0x40b)
  {
    id = 0x71;
  }
  cache = findOrLoadCacheBlock(id);
  validFrame = frame < ((u32) cache->frameCount);
  shape = cache->shape;
  count = D_800C3928[shape & 0x7fff].count;
  frame &= -validFrame;
  shape &= 0x8000;
  header = ((u32) count) << 16;
  if (shape)
  {{ s32 __repair_value; __repair_value = count * 3; coordWords = __repair_value; }
    if (expand)
    {
      header |= 3;
    }
    else
    {
      header |= 2;
    }
  }
  else
  {
    coordWords = 3;
    if (expand)
    {
      header |= 1;
    }
  }
  *out = header;
  out += 2;
  vectors = 1;
  totalWords = coordWords + count;
  if (shape)
  {
    vectors = count;
  }
  packedWords = vectors * 3;
  packedBytes = packedWords * 2;
  validFrame = (cache->romOffset + (((packedWords + (count * 2)) * frame) * 2)) - packedBytes;
  i = 0;
  romDmaRead((s32) out, (s32) (romBase + validFrame), totalWords * 4);
  packedStart = (u16 *) (((char *) out) + packedBytes);
  if (__repair_inline(vectors, 0))
  {
    coords = (f32 *) out;
    packed = packedStart;
    __repair_rows:
    {
      f32 z;
      coords[0] = (packed[0] * cache->scale[0]) + cache->offset[0];
      coords[1] = (packed[1] * cache->scale[1]) + cache->offset[1];
      z = (packed[2] * cache->scale[2]) + cache->offset[2];
      i++;
      packed += 3;
      coords[2] = z;
      coords += 3;
    }

    if (i < vectors)
    {
      goto __repair_rows;
    }
  }
  if (expand)
  {
    i = 0;
    if (0 < count)
    {
      dstIndex = totalWords;
      do
      {
        do
        {
          u32 word = out[coordWords + i];
          decoded[0] = (f32) ((f64) ((word >> 22) * 4U)); decoded[1] = (f32) ((f64) ((word >> 10) & 0xffeU)); decoded[2] = (f32) ((f64) ((word << 1) & 0xffeU));
          D_800D9424(decoded, out + dstIndex);
          dstIndex += 4;
          i++;
        }
        while (i < count);
      }
      while (0);
    }
  }
}

