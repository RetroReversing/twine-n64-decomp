extern const f64 D_800D2008;
static inline f32 repair_unsigned_float(u32 x, f64 bias) {
    f64 result = (s32)x;
    if ((s32)x < 0) result += bias;
    return (f32)result;
}
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
  s32 romAddr;
  if (id >= 0x40b)
  {
    id = 0x71;
  }
  cache = findOrLoadCacheBlock(id);
  do {
  validFrame = frame < ((u32) cache->frameCount);
  shape = cache->shape;
  } while (0);
  count = D_800C3928[shape & 0x7fff].count;
  do {
  frame &= -validFrame;
  } while (0);
  shape &= 0x8000;
  header = ((u32) count) << 16;
  if (shape)
  {
    coordWords = count * 3;
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
  romAddr = (cache->romOffset + (((packedWords + (count * 2)) * frame) * 2)) - (packedBytes = packedWords * 2);
  romDmaRead((s32) out, (s32) (romAddr + D_000F8D70), totalWords * 4);
  i = 0;
  packedStart = (u16 *) (((char *) out) + packedBytes);
  if (vectors > 0)
  {
    coords = (f32 *) out;
    packed = packedStart;
    do
    {
      coords[0] = (packed[0] * cache->scale[0]) + cache->offset[0];
      coords[1] = (packed[1] * cache->scale[1]) + cache->offset[1];
      coords[2] = (packed[2] * cache->scale[2]) + cache->offset[2];
      i++;
      packed += 3;
      coords += 3;
    }
    while (i < vectors);
  }
  if (expand)
  {
    i = 0;
    if (0 < count)
    {
s32 __block_dstIndex;

      f64 repair_conversion_bias = D_800D2008;
      __block_dstIndex = totalWords;
      do
      {
        do
        {
          u32 word = out[coordWords + i];
          decoded[0] = repair_unsigned_float((word >> 22) * 4U, repair_conversion_bias); decoded[1] = repair_unsigned_float((word >> 10) & 0xffeU, repair_conversion_bias); decoded[2] = repair_unsigned_float((word << 1) & 0xffeU, repair_conversion_bias);
          D_800D9424(decoded, out + __block_dstIndex);
          __block_dstIndex += 4;
          i++;
        }
        while (i < count);
      }
      while (0);
    }
  }
}


