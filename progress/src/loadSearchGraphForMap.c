typedef struct 
{
  s32 rowOffset;
  s16 rowBytes;
  s16 pad;
  s32 edgeOffset;
  s16 edgeBytes;
  s16 pad2;
} SearchHeader;
typedef struct 
{
  s16 id;
  s16 pad;
  s32 offset;
} SearchMap;
typedef struct 
{
  s16 a;
  s16 b;
  s16 flags;
} SearchEdge;
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} SearchPoint;
typedef struct SearchRow
{
  u8 pad[16];
  SearchPoint *point;
  struct SearchRow *links[16];
  void *object;
} SearchRow;
extern SearchMap func_8011EB60[];
extern s16 D_8011EB60;
extern u8 D_54D910[];
extern SearchRow *gSearchNodes;
extern s32 sSearchEntryCount;
extern void dmaRomToRamUnaligned(u8 *, s32, u32);
extern void *heapAllocTagged(s32, s32);
extern void freeHeapBlock(void *, s32);
extern void *probeFindNearestObject(SearchPoint *);
inline static s16 inline_fn(s16 arg0)
{
  return arg0;
}

/* Loads the search graph (nodes and edges) for a map from ROM and links each node to its neighbours. */ void loadSearchGraphForMap(s32 mapId)
{
  SearchHeader header;
  u8 padding[8];
  s32 offset = 0;
  s32 base;
  SearchPoint *points;
  SearchEdge *edges;
  s16 pointCount;
  s16 edgeCount;
  s32 i;
  s32 j;
  sSearchEntryCount = 0;
  if (D_8011EB60 != (-1))
  {
    s32 key = (s16) mapId;
    s32 sentinel = -1;
    s16 *entry = (s16 *) func_8011EB60;
    mapId = 0;
    do
    {
      if (*entry == key)
      {
        offset = *((s32 *) (0x8011EB64 + mapId));
        goto found;
      }
      entry += 4;
      mapId += 8;
    }
    while (*entry != sentinel);
  }
  found:
  base = (s32) D_54D910;

  dmaRomToRamUnaligned((u8 *) (&header), offset + base, 16);
  *((SearchRow **) 0x8011F068) = heapAllocTagged(0xB000, 0x34);
  {
    SearchPoint *pointData = heapAllocTagged(header.rowBytes, 0x34);
    edges = heapAllocTagged(header.edgeBytes, 0x34);
    points = pointData;
  }
  dmaRomToRamUnaligned((u8 *) points, header.rowOffset + base, header.rowBytes);
  dmaRomToRamUnaligned((u8 *) edges, header.edgeOffset + base, header.edgeBytes);
  edgeCount = ((u32) header.edgeBytes) / 6;
  pointCount = ((u32) header.rowBytes) / 12;
  if (pointCount > 0)
  {
    i = 0;
    do
    {
      SearchRow *node = (SearchRow *) (i * sizeof(SearchRow) + (s32) gSearchNodes);
      u8 *cursor = ((u8 *) node) + 0x3C;
      void *object;
      node->point = points;
      j = 15;
      do
      {
        ((SearchRow *) cursor)->links[0] = 0;
        cursor -= 4;
      }
      while ((--j) >= 0);
      object = probeFindNearestObject(gSearchNodes[i].point);
      points++;
      gSearchNodes[i].object = object;
      sSearchEntryCount++;
      i++;
    }
    while (i < pointCount);
  }
  {
    s32 edgeIdx;
    do { do { do { edgeIdx = 0; } while (0); } while (0); } while (0);
    if (edgeCount > 0)
    {
      SearchRow *nodes = *((SearchRow **) 0x8011F068);
      do
      {
      s16 a = edges[edgeIdx].a;
      s16 b = edges[edgeIdx].b;
      for (j = 0; j < 16; j++)
      {
        if (nodes[a].links[j] == 0)
        {
          nodes[a].links[j] = &nodes[b];
          break;
        }
      }
      for (j = 0; j < 16; j++)
      {
        if (nodes[b].links[j] == 0)
        {
          nodes[b].links[j] = &nodes[a];
          break;
        }
      }
        edgeIdx++;
      }
      while (edgeIdx < edgeCount);
    }
  }
  freeHeapBlock(edges, 0x34);
}

