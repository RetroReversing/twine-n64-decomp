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
extern ShapeEntry gShapeTable[];
extern s32 (*gTransformVertexFn)(f32 *, void *);
extern char D_000F8D70[];
/* Loads one animation frame of a mesh from ROM into outBuf: writes a header word, DMAs the packed data, dequantizes vertices to floats, and optionally expands packed points through gTransformVertexFn. */ void loadMeshFrame(s32 *outBuf, u32 meshId, u32 frame, s32 expandPoints)
{
  f32 unpackedPoint[3];
  u32 scratch[6];
  FrameCache *meshCache;
  u32 shape;
  s32 count;
  s32 coordWordCount;
  s32 totalWords;
  s32 vectors;
  s32 packedWords;
  s32 packedBytes;
  u32 header;
  s32 i;
  s32 dstIndex;
  u16 *packedCursor;
  f32 *coordCursor;
  u16 *packedStart;
  char *romBase = D_000F8D70;
  s32 validFrame;
  s32 romSrcAddr;
  if (meshId >= 0x40b)
  {
    meshId = 0x71;
  }
  meshCache = findOrLoadCacheBlock(meshId);
  do {
  validFrame = frame < ((u32) meshCache->frameCount);
  shape = meshCache->shape;
  } while (0);
  count = gShapeTable[shape & 0x7fff].count;
  do {
  frame &= -validFrame;
  } while (0);
  shape &= 0x8000;
  header = ((u32) count) << 16;
  if (shape)
  {
    coordWordCount = count * 3;
    if (expandPoints)
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
    coordWordCount = 3;
    if (expandPoints)
    {
      header |= 1;
    }
  }
  *outBuf = header;
  outBuf += 2;
  vectors = 1;
  totalWords = coordWordCount + count;
  if (shape)
  {
    vectors = count;
  }
  packedWords = vectors * 3;
  romSrcAddr = (meshCache->romOffset + (((packedWords + (count * 2)) * frame) * 2)) - (packedBytes = packedWords * 2);
  romDmaRead((s32) outBuf, (s32) (romSrcAddr + D_000F8D70), totalWords * 4);
  i = 0;
  packedStart = (u16 *) (((char *) outBuf) + packedBytes);
  if (vectors > 0)
  {
    coordCursor = (f32 *) outBuf;
    packedCursor = packedStart;
    do
    {
      coordCursor[0] = (packedCursor[0] * meshCache->scale[0]) + meshCache->offset[0];
      coordCursor[1] = (packedCursor[1] * meshCache->scale[1]) + meshCache->offset[1];
      coordCursor[2] = (packedCursor[2] * meshCache->scale[2]) + meshCache->offset[2];
      i++;
      packedCursor += 3;
      coordCursor += 3;
    }
    while (i < vectors);
  }
  if (expandPoints)
  {
    i = 0;
    if (0 < count)
    {
s32 dstWordIndex;

      f64 repair_conversion_bias = D_800D2008;
      dstWordIndex = totalWords;
      do
      {
        do
        {
          u32 word = outBuf[coordWordCount + i];
          unpackedPoint[0] = repair_unsigned_float((word >> 22) * 4U, repair_conversion_bias); unpackedPoint[1] = repair_unsigned_float((word >> 10) & 0xffeU, repair_conversion_bias); unpackedPoint[2] = repair_unsigned_float((word << 1) & 0xffeU, repair_conversion_bias);
          gTransformVertexFn(unpackedPoint, outBuf + dstWordIndex);
          dstWordIndex += 4;
          i++;
        }
        while (i < count);
      }
      while (0);
    }
  }
}


