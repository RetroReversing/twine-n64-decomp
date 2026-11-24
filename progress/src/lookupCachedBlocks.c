typedef struct CacheBlock
{
  struct CacheBlock *prev;
  struct CacheBlock *next;
  s32 addr;
  s32 tag;
  s32 len;
  u32 data;
} CacheBlock;
typedef struct CacheLookupResult
{
  s32 data0;
  s32 data1;
  s16 len0;
  s16 len1;
} CacheLookupResult;
typedef struct CacheLoadEntry
{
  s32 length;
  s32 addr;
  s32 data;
} CacheLoadEntry;
s32 func_800CEEE0();
extern CacheBlock *gCacheLruTail;
extern CacheBlock *gCacheLruHead;
extern CacheBlock *gCacheFreeList;
extern CacheLoadEntry *sSlotLog;
extern u16 sSlotLogCount;
extern s32 D_80109BA0;
extern s32 D_80109BF8;
/* Looks up an address range in the 0x600-byte block LRU cache, loading missing blocks; outputs up to two (data, length) pieces ordered by address. */
void lookupCachedBlocks(CacheLookupResult *out, u32 addr, s32 length, s32 tag)
{
  u32 parts[3][2];
  u32 endAddr;
  u32 minAddr;
  CacheBlock *node;
  CacheBlock *next;
  u32 a0;
  u32 a1;
  s32 count;
  s32 t0;
  u32 offset;
  CacheBlock *t;
  s32 tmp;

  node = gCacheLruHead;
  endAddr = addr + length;
  minAddr = addr - 0x600;
  count = 0;
  if (node != NULL)
  {
    t0 = 0x600;
    do
    {
      next = node->next;
      if (node->tag == tag && (a0 = node->addr) < endAddr && minAddr < a0)
      {
        a1 = node->len;
        if (a1 != t0 && a0 + a1 < addr + length)
        {
          offset = addr + length;
          if (offset >= a0 + 0x600)
            offset = t0 - a1;
          else
            offset = ((offset - (a0 + a1)) + 0xFF) & ~0xFF;
          D_80109BF8 += 0xC;
          D_80109BA0 = func_800CEEE0(D_80109BA0, D_80109BF8);
          sSlotLog[sSlotLogCount].addr = node->addr + node->len;
          sSlotLog[sSlotLogCount].length = offset;
          sSlotLog[sSlotLogCount].data = node->data + node->len;
          sSlotLogCount++;
          node->len += offset;
        }
        if (node != gCacheLruHead)
        {
          if (node->prev != NULL)
            node->prev->next = node->next;
          if (node->next != NULL)
            node->next->prev = node->prev;
          else
            gCacheLruTail = node->prev;
          gCacheLruHead->prev = node;
          node->next = gCacheLruHead;
          gCacheLruHead = node;
          node->prev = NULL;
        }
        a1 = node->addr;
        if (addr < a1)
        {
          s32 n;
          parts[0][(u16) count] = node->data;
          parts[2][(u16) count] = node->addr;
          n = length - (node->addr - addr);
          parts[1][(u16) count] = n;
          count++;
          length -= n;
        }
        else if (a1 + node->len < addr + length)
        {
          u32 n;
          parts[0][(u16) count] = node->data + (addr - a1);
          parts[2][(u16) count] = addr;
          n = node->addr + node->len - addr;
          parts[1][(u16) count] = n;
          count++;
          length -= n;
          addr = node->addr + node->len;
        }
        else
        {
          parts[0][(u16) count] = node->data + (addr - a1);
          parts[1][(u16) count] = length;
          length = 0;
          parts[2][(u16) count] = addr;
          count++;
          break;
        }
      }
      node = next;
    }
    while (node != NULL);
  }
  if (length != 0)
  {
    offset = (addr - tag) % 0x600;
    do
    {
      if (gCacheFreeList != NULL)
      {
        t = gCacheFreeList;
        gCacheFreeList = t->prev;
        if (gCacheFreeList != NULL)
          gCacheFreeList->next = NULL;
        if (gCacheLruHead == NULL)
        {
          t->prev = gCacheLruTail;
          if (gCacheLruTail != NULL)
            gCacheLruTail->next = t;
          gCacheLruTail = t;
        }
        else
        {
          t->prev = NULL;
          t->next = gCacheLruHead;
          gCacheLruHead->prev = t;
        }
        gCacheLruHead = t;
        node = t;
      }
      else
      {
        CacheBlock *head;
        CacheBlock *prev;
        t = gCacheLruTail;
        t->prev->next = NULL;
        prev = t->prev;
        head = gCacheLruHead;
        node = t;
        gCacheLruHead = node;
        head->prev = node;
        node->next = head;
        node->prev = NULL;
        gCacheLruTail = prev;
      }
      node->addr = addr - offset;
      node->tag = tag;
      if (length + offset > 0x600)
      {
        u32 n;
        u32 m;
        node->len = 0x600;
        D_80109BF8 += 0xC;
        D_80109BA0 = func_800CEEE0(D_80109BA0, D_80109BF8);
        sSlotLog[sSlotLogCount].addr = node->addr;
        sSlotLog[sSlotLogCount].length = 0x600;
        sSlotLog[sSlotLogCount].data = node->data;
        sSlotLogCount++;
        parts[0][(u16) count] = node->data + offset;
        parts[2][(u16) count] = node->addr + offset;
        parts[1][(u16) count] = 0x600 - offset;
        count++;
        n = length - 0x600;
        length = n + offset;
        m = offset - 0x600;
        addr -= m;
      }
      else
      {
        node->len = (length + offset + 0xFF) & ~0xFF;
        D_80109BF8 += 0xC;
        tmp = func_800CEEE0(D_80109BA0, D_80109BF8);
        sSlotLog[sSlotLogCount].addr = node->addr;
        sSlotLog[sSlotLogCount].length = node->len;
        sSlotLog[sSlotLogCount].data = node->data;
        D_80109BA0 = tmp;
        parts[0][(u16) count] = node->data + offset;
        parts[2][(u16) count] = node->addr + offset;
        sSlotLogCount++;
        parts[1][(u16) count] = length;
        length = 0;
        count++;
      }
      offset = 0;
    }
    while (length != 0);
  }
  if ((count & 0xFFFF) == 1)
  {
    out->data0 = parts[0][0];
    out->len0 = parts[1][0];
    out->len1 = 0;
    return;
  }
  if (parts[2][0] < parts[2][1])
  {
    out->data0 = parts[0][0];
    out->data1 = parts[0][1];
    out->len0 = parts[1][0];
    out->len1 = parts[1][1];
    return;
  }
  out->data0 = parts[0][1];
  out->data1 = parts[0][0];
  out->len0 = parts[1][1];
  out->len1 = parts[1][0];
}
