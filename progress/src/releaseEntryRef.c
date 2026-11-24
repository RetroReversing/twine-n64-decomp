typedef struct 
{
  u16 value;
  u16 pad;
} BucketField;
typedef struct 
{
  u16 value;
  u16 pad[3];
} EntryField;
typedef struct 
{
  u32 first;
  u32 second;
} TableEntry;
void func_8008C0D4(void);
void func_8008C11C(void);
extern s32 gEntryTableCount;
extern BucketField gEntryBuckets[];
extern BucketField gEntryBucketStarts[];
extern EntryField gEntryIds[];
extern EntryField gEntryRefCounts[];
extern TableEntry gSortedEntries[];
/* Drops one reference to the entry with this id; at zero, removes it from the sorted table and shifts bucket starts down. */ s32 releaseEntryRef(s32 entryId)
{
  f64 pad[2];
  u32 id;
  u32 bucketIndex;
  s32 i;
  s32 bucketCount;
  s32 bucketStart;
  s32 entryIndex;
  u16 refCount;
  TableEntry *srcEntry;
  TableEntry *dstEntry;
  TableEntry *entries;
  BucketField *p;
  s32 offset;
  s32 nextStart;
  func_8008C0D4();
  id = entryId & 0xffff;
  bucketIndex = id >> 6;
  bucketCount = gEntryBuckets[bucketIndex].value;
  if (bucketCount != 0)
  {
    bucketStart = gEntryBucketStarts[bucketIndex].value;
    i = 0;
    if (!(unsigned short)bucketCount) goto done;
    loop: if (gEntryIds[bucketStart + i].value == id) goto found;
    if (++i < bucketCount) goto loop;
    found: ;
    if (i < gEntryBuckets[bucketIndex].value)
    {
      entryIndex = bucketStart + i;
      refCount = gEntryRefCounts[entryIndex].value;
 do { entries = gSortedEntries; } while (0);
      refCount--;
      gEntryRefCounts[entryIndex].value = refCount;
      if (refCount == 0)
      {
        TableEntry *prev = entries - 1;
        i = entryIndex + 1;
        if (i < gEntryTableCount)
        {
          dstEntry = prev + i;
          srcEntry = entries + i;
          do
          {
            *dstEntry = *srcEntry;
            dstEntry++;
            i++;
            srcEntry++;
          }
          while (i < gEntryTableCount);
        }
        p = gEntryBuckets;
        offset = 0;
        do
        {
          nextStart = ((BucketField *) (((char *) gEntryBucketStarts) + offset))->value;
          if (bucketStart < nextStart)
          {
            p->pad = nextStart - 1;
          }
          offset += 4;
          p++;
        }
        while (offset < 0x800);
        gEntryBuckets[bucketIndex].value--;
        gEntryTableCount--;
      }
    }
  }
done: func_8008C11C();
  return 0;
}
