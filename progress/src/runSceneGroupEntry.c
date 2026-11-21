typedef struct { u8 pad[4]; u16 id; u16 busy; u8 pad8[0x14]; s32 o1C; s32 o20; s32 o24; } Bank;
s32 workerLockAcquire();
s32 workerLockRelease();
s32 func_8008F520();
extern u8 gWorkerThreadActive;
extern s16 sSceneGroupStackCount;
extern u8 sSceneGroupStack[];

/* Finds the scene group with the given id and runs its entry with the given id under the worker lock; returns -1 if nothing ran. */
s32 runSceneGroupEntry(s32 groupId, s32 entryId, s32 arg2, s32 arg3) {
    s32 sub;
    s32 idx;
    s32 off;
    Bank *group;
    u8 *entry;
    u8 *dataBase1;
    u8 *dataBase2;
    s32 curEntryId;
    s32 result;

    if (gWorkerThreadActive != 0) {
        idx = 0;
        if (idx < sSceneGroupStackCount) {
        groupId &= 0xFFFF;
        do {
            group = *(Bank **)((idx << 2) + sSceneGroupStack);
            if (group->id == groupId) {
                if (group->busy != 0) {
                    return -1;
                }
                entry = (u8 *)group + (group->o24 + 8);
                dataBase2 = (u8 *)group + (group->o1C + 8);
                dataBase1 = (u8 *)group + (group->o20 + 8);
                while ((curEntryId = *(u16 *)entry) != 0xFFFF) {
                    if (curEntryId == (entryId & 0xFFFF)) {
                        workerLockAcquire(curEntryId);
                        result = func_8008F520(dataBase2, dataBase1, entry, arg2, arg3);
                        workerLockRelease();
                        return result;
                    }
                    entry += 0x84;
                }
                return -1;
                break;
            }
            idx++;
        } while (idx < sSceneGroupStackCount);
        }
    }
    return -1;
}
