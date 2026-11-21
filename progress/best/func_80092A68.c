typedef struct {
    s32 next;
    u16 key, kind;
    s32 offsets[6];
} SceneGroup;

typedef struct {
    s32 next;
    u16 key, field6, field8, extra;
} SceneEntry;

extern u8 gWorkerActive;
extern s16 sSceneGroupStackCount;
extern SceneGroup *sSceneGroupStack[];
extern s32 func_8008C758(s32);
extern void func_80097EF8(u16, void *);
extern s32 keyTableRegister(void *, s32);
extern void func_80097A40(u16, void *);
extern s32 insertOrRefSortedEntry(u16, s32);
extern s32 insertOrCountEntry(u16, s32);
extern s32 insertSortedKeyEntry(u16, const void *, u16);
extern void registerWorkerEntry(u16, void *, u16);

s32 func_80092A68(SceneGroup *initial, u16 id, s32 arg2, void *arg3, s32 *tables) {
    SceneGroup *group;
    if (!gWorkerActive || sSceneGroupStackCount >= 128) {
        return 0;
    }
    group = initial;
    if (group->next == -1) {
        return 0;
    }
    do {
        if (group->key == id) {
            sSceneGroupStack[sSceneGroupStackCount] = group;
            {
                u16 *keys = (u16 *)((u8 *)group + group->offsets[0] + 8);
                u32 key = *keys;
                while (key != 0xFFFF) {
                        SceneEntry *entry = (SceneEntry *)((u8 *)tables + tables[0]);
                        SceneEntry *found = NULL;
                        while (entry->next != -1) {
                                found = entry;
                                if (entry->key == (u16)key) {
                                    break;
                                }
                                entry = (SceneEntry *)((u8 *)entry + entry->next);
                                found = NULL;
                        }
                        if (found != NULL) {
                            key = *keys;
                            func_80097EF8(key, (u8 *)found + 8);
                        }
                        key = *++keys;
                }
            }
            {
                u16 *keys = (u16 *)((u8 *)group + group->offsets[1] + 8);
                if ((u8)keyTableRegister(arg3, func_8008C758(arg2))) {
                    u16 key = *keys++;
                    while (key != 0xFFFF) {
                            func_80097A40(key, arg3);
                            key = *keys++;
                    }
                }
            }
            {
                u16 *keys = (u16 *)((u8 *)group + group->offsets[2] + 8);
                u32 key = *keys;
                while (key != 0xFFFF) {
                        SceneEntry *entry = (SceneEntry *)((u8 *)tables + tables[1]);
                        SceneEntry *found = NULL;
                        while (entry->next != -1) {
                                found = entry;
                                if (entry->key == (u16)key) {
                                    break;
                                }
                                entry = (SceneEntry *)((u8 *)entry + entry->next);
                                found = NULL;
                        }
                        if (found != NULL) {
                            key = *keys;
                            insertOrRefSortedEntry(key, (s32)((u8 *)found + 8));
                        }
                        key = *++keys;
                }
            }
            {
                u16 *keys = (u16 *)((u8 *)group + group->offsets[3] + 8);
                u32 key = *keys;
                while (key != 0xFFFF) {
                        SceneEntry *entry = (SceneEntry *)((u8 *)tables + tables[2]);
                        SceneEntry *found = NULL;
                        while (entry->next != -1) {
                                found = entry;
                                if (entry->key == (u16)key) {
                                    break;
                                }
                                entry = (SceneEntry *)((u8 *)entry + entry->next);
                                found = NULL;
                        }
                        if (found != NULL) {
                            key = *keys;
                            insertOrCountEntry(key, (s32)((u8 *)found + 8));
                        }
                        key = *++keys;
                }
            }
            {
                u16 *keys = (u16 *)((u8 *)group + group->offsets[4] + 8);
                u32 key = *keys;
                while (key != 0xFFFF) {
                        SceneEntry *entry = (SceneEntry *)((u8 *)tables + tables[3]);
                        SceneEntry *found = NULL;
                        while (entry->next != -1) {
                                found = entry;
                                if (entry->key == (u16)key) {
                                    break;
                                }
                                entry = (SceneEntry *)((u8 *)entry + entry->next);
                                found = NULL;
                        }
                        if (found != NULL) {
                            key = *keys;
                            insertSortedKeyEntry(key, (u8 *)found + 12, found->extra);
                        }
                        key = *++keys;
                }
            }
            if (group->kind == 1) {
                u8 *data = (u8 *)group + group->offsets[5] + 8;
                registerWorkerEntry(id, data + 4, *(u16 *)data);
            }
            sSceneGroupStackCount++;
            return 1;
        }
        group = (SceneGroup *)((u8 *)group + group->next);
    } while (group->next != -1);
    return 0;
}
