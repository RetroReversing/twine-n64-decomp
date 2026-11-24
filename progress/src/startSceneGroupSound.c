extern u8 gWorkerThreadActive;
extern s16 sSceneGroupStackCount;
extern char *sSceneGroupStack[];
void workerLockAcquire(void);
void workerLockRelease(void);
s32 startSoundEntity();
/* Finds the scene group with groupId on the stack, locates the entry matching entryId and starts its sound entity (taking the worker lock unless skipLock). Returns -1 if not found. */ s32 startSceneGroupSound(u16 groupId, u16 entryId, s32 param2, s32 param3, u8 skipLock)
{
  s32 groupIndex;
  s32 result;
  char *group;
  char *a;
  char *b;
  char *entry;
  u16 curEntryId;
  if (gWorkerThreadActive)
  {
    {
      for (groupIndex = 0; groupIndex < sSceneGroupStackCount; groupIndex++)
      {
        group = *((char **) (((char *) sSceneGroupStack) + (groupIndex << 2)));
        if ((*((u16 *) (group + 4))) == groupId)
        {
          if (*((u16 *) (group + 6)))
          {
            return -1;
          }
          entry = group + ((*((s32 *) (group + 0x24))) + 8);
          curEntryId = *((u16 *) entry);
          a = group + ((*((s32 *) (group + 0x1c))) + 8);
          b = group + ((*((s32 *) (group + 0x20))) + 8);
          while (curEntryId != 0xffff)
          {
            if (curEntryId == entryId)
            {
if (skipLock) { result = startSoundEntity(a, b, entry, param2, param3); } else { workerLockAcquire(); result = startSoundEntity(a, b, entry, param2, param3); workerLockRelease(); } return result;
            }
            entry += 0x84;
            curEntryId = *((u16 *) entry);
          }

          return -1;
        }
      }

    }
  }
  return -1;
}
