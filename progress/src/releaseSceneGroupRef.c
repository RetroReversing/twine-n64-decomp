typedef struct { s32 data; u16 id; u16 pad; u16 ref; u16 pad2; } Entry;
typedef struct { u16 id; u16 a; u16 b; u16 c; u16 d; u16 e; } Entry2;
extern s32 sLoadedSceneGroupCount; extern Entry sLoadedSceneGroups[]; extern Entry2 sLoadedSceneGroupIds[];
void workerLockAcquire(void); void workerLockRelease(void);

/* Drops one reference to the loaded scene group with the given id; removes the group from the table when no references remain. Returns 1 if removed. */
s32 releaseSceneGroupRef(u16 groupId) {
 s32 idx, shiftIdx;
 workerLockAcquire();
 for (idx = 0; idx < sLoadedSceneGroupCount; idx++) if (sLoadedSceneGroupIds[idx].id == groupId) break;
 if (idx != sLoadedSceneGroupCount) {
  if (--sLoadedSceneGroups[idx].ref == 0) {
   for (shiftIdx = idx + 1; shiftIdx < sLoadedSceneGroupCount; shiftIdx++) sLoadedSceneGroups[shiftIdx - 1] = sLoadedSceneGroups[shiftIdx];
   sLoadedSceneGroupCount--; workerLockRelease(); return 1;
  }
 }
 workerLockRelease(); return 0;
}
