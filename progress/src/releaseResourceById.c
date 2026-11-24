void workerLockAcquire(s32, u16 *);
void workerLockRelease(void);
void releaseResourceHook(void *, s32);
extern char D_800F38E4[];
extern s32 sResourceTableCount;
extern char sResourceTableSlots[];
typedef struct 
{
  s32 w[3];
} __repair_words3;
/* Drops one reference to resource `id` in every resource table; unloads at zero and removes tables whose entries are all unreferenced. */ s32 releaseResourceById(s32 id)
{
  s32 unused[4];
  s32 temp_v0_2;
  s32 released;
  s32 var_a2;
  s32 slotIdx;
  s32 anyLive;
  s32 result;
  s32 var_v1;
  u16 **tablePtr;
  u16 *table;
  char *entry;
  u16 temp_v0;
  u16 entryId;
  u32 tableIdx;
  void *var_a3;
  void *var_s0;
  void *var_t0;
  released = 0;
  tableIdx = 0;
  if (sResourceTableCount != 0)
  {
    s32 count;
    char *base;
    s32 wanted = (u16) id;
    base = D_800F38E4;
    tablePtr = (u16 **) (base + 0xC);
    loop_2:
    entry = (char *) (*tablePtr);

    entryId = *((u16 *) entry);
    anyLive = 0;
    if (((u16) entryId) != 0xFFFF)
    {
      do {
      do
      {
        if (entryId == wanted)
        {
          temp_v0 = (*((u16 *) (entry + 2))) - 1;
          *((u16 *) (entry + 2)) = temp_v0;
          if (temp_v0 & 0xFFFF)
          {
            released = 1;
          }
          else
          {
            releaseResourceHook(entry + 0xC, *((s32 *) (entry + 4)));
            released = 1;
          }
        }
        if ((*((u16 *) (entry + 2))) != 0)
        {
          anyLive = 1;
        }
        entry += 0x1C;
        entryId = *((u16 *) entry);
      }
      while (entryId != 0xFFFF);
      } while (0);
    }
    do
    {
      if (released & 0xFF)
      {
        if (anyLive & 0xFF)
        {
          goto success;
        }
        count = sResourceTableCount; table = *tablePtr; slotIdx = 0;
        if (count > 0)
        {
          var_v1 = 0;
          loop_16:
          if ((*((u16 **) (sResourceTableSlots + var_v1))) != table)
          {
            slotIdx += 1; var_v1 += 0xC;
            if (slotIdx < count)
            {
              goto loop_16;
            }
          }

        }
        result = 1;
        if (slotIdx != sResourceTableCount)
        {
          workerLockAcquire(count, table);
          var_a2 = slotIdx + 1;
          if (var_a2 < sResourceTableCount)
          {
            temp_v0_2 = var_a2 * 0xC; var_t0 = (void *) (((u32) temp_v0_2) + ((u32) base)); var_a3 = temp_v0_2 + sResourceTableSlots;
            do
            {
              *((__repair_words3 *) (((char *) var_t0) + 0x0)) = *((__repair_words3 *) (((s8 *) var_a3) + 0x0)); var_t0 += 0xC; var_a2 += 1; var_a3 += 0xC;
            }
            while (var_a2 < sResourceTableCount);
          }
          sResourceTableCount -= 1;
          workerLockRelease();
        }
        success:
        return 1;

      }
      result = sResourceTableCount;
      do { tableIdx += 1; tablePtr += 3; } while (0);
      if (tableIdx >= ((u32) result))
      {
        goto block_24;
      }
      goto loop_2;
    }
    while (0);
  }
  block_24:
  result = 0;

  return result;
}


