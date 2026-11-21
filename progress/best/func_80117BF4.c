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
extern u8 D_0054D910[];
extern SearchRow *sSearchEntries;
extern s32 sSearchEntryCount;
extern void dmaRomToRamUnaligned(u8 *, s32, u32);
extern void *heapAllocTagged(s32, s32);
extern void func_80084048(void *, s32);
extern void *probeFindNearestObject(SearchPoint *);
inline static s16 inline_fn(s16 arg0)
{
  return arg0;
}

void func_80117BF4(s32 map)
{
  SearchHeader header;
  u8 padding[8];
  s32 offset = 0;
  s32 base;
  SearchPoint *points;
  volatile unsigned short pad;
  SearchEdge *edges;
  s16 pointCount;
  s16 edgeCount;
  s32 i;
  s32 j;
  sSearchEntryCount = 0;
  if (D_8011EB60 != (-1))
  {
    s32 key = (s16) map;
    s32 sentinel = -1;
    s16 *entry = (s16 *) func_8011EB60;
    s32 id;
    map = 0;
    id = *entry;
    do
    {
      entry += 4;
      if (key == id)
      {
        offset = *((s32 *) (0x8011EB64 + map));
        goto found;
      }
      id = *entry;
      map += 8;
    }
    while (id != sentinel);
  }
  found:
  base = (s32) D_0054D910;

  dmaRomToRamUnaligned((u8 *) (&header), offset + base, 16);
  *((SearchRow **) 0x8011F068) = heapAllocTagged(0xB000, 0x34);
  points = heapAllocTagged(header.rowBytes, 0x34);
  edges = heapAllocTagged(header.edgeBytes, 0x34);
  dmaRomToRamUnaligned((u8 *) points, header.rowOffset + base, header.rowBytes);
  dmaRomToRamUnaligned((u8 *) edges, header.edgeOffset + base, header.edgeBytes);
  edgeCount = ((u32) header.edgeBytes) / 6;
  pointCount = ((u32) header.rowBytes) / 12;
  if (pointCount > 0)
  {
    i = 0;
    do
    {
      SearchRow *row = (SearchRow *) (i + ((u8 *) sSearchEntries));
      u8 *cursor = ((u8 *) row) + 0x3C;
      void *object;
      row->point = points;
      j = 15;
      do
      {
        ((SearchRow *) cursor)->links[0] = 0;
        cursor -= 4;
      }
      while ((--j) >= 0);
      object = probeFindNearestObject(((SearchRow *) (i + ((u8 *) sSearchEntries)))->point);
      points++;
      ((SearchRow *) (i + ((u8 *) sSearchEntries)))->object = object;
      sSearchEntryCount++;
      i += sizeof(SearchRow);
    }
    while (i < (pointCount * ((s32) (sizeof(SearchRow)))));
  }
  {
    s32 k = 0;
    if (edgeCount > 0)
    {
      SearchRow *rows = *((SearchRow **) 0x8011F068);
      SearchEdge *edge = edges;
      do
      {
        s16 a = edge->a;
        s16 b = inline_fn(edge->b);
        SearchRow *to;
        u8 *cursor;
        j = 0;
        cursor = (u8 *) (&rows[a]);
        to = &rows[b];
        forward:
        j++;

        if (((SearchRow *) cursor)->links[0] == 0)
        {
          if (edge)
          {
            ((SearchRow *) cursor)->links[0] = to;
            goto forward_done;
          }
          else
          {
            ((SearchRow *) cursor)->links[0] = to;
            goto forward_done;
          }
        }
        cursor += 4;
        if (j < 16)
        {
          goto forward;
        }
        forward_done:
        j = 0;

        to = &rows[(s16) a];
        cursor = (u8 *) (&rows[(s16) b]);
        reverse:
        if (((SearchRow *) cursor)->links[0] == 0)
        {
          ((SearchRow *) cursor)->links[0] = to;
          goto reverse_done;
        }

        j++;
        cursor += 4;
        if (j < 16)
        {
          goto reverse;
        }
        reverse_done:
        edge++;

      }
      while ((++k) < edgeCount);
    }
  }
  func_80084048(edges, 0x34);
}

