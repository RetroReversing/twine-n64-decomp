extern void *D_80102CD0[];
extern void *sBonusObjectTable[];
extern s32 gSceneType;
extern s32 gSaveTotalSlots;
extern s32 D_8011F3A8;

#define FIELD(p, T, off) (*(T *)((u8 *)(p) + (off)))

void func_8011A7C8(void) {
    s16 chosen = -1;
    s16 index;
    s32 signedIndex;
    s32 chosenIndex;
    s32 limit;
    u8 *scene = (u8 *)&gSceneType;
    volatile s32 *sceneLimit;
    volatile s32 *slots;
    void **entry;
    void *object;
    void *info;
    s16 state;

    if (*scene != 8) goto check_chosen;
    index = 0;
    if (gSaveTotalSlots > 0) {
        sceneLimit = (volatile s32 *)(scene + 0x14);
        do {
            signedIndex = index;
            entry = &D_80102CD0[signedIndex];
            object = *entry;
            if (object == NULL) goto next_scene_entry;
            if (FIELD(FIELD(object, void *, 0xB4), u8, 0x10) != 7) goto next_scene_entry;
            chosen = index;
            index = 0;
            if (*sceneLimit <= index) goto check_chosen;
            chosenIndex = signedIndex;
            slots = &gSaveTotalSlots;
            do {
                signedIndex = index;
                if (signedIndex == chosenIndex) goto next_slot;
                object = D_80102CD0[signedIndex];
                if (object == NULL) goto next_slot;
                if (FIELD(FIELD(object, void *, 0xB4), u8, 0x11) != 0) goto next_slot;
                info = FIELD(*entry, void *, 0xB4);
                FIELD(info, u16, 0xC)++;
next_slot:
                index++;
            } while (index < *slots);
            goto check_chosen;
next_scene_entry:
            index++;
        } while (index < *sceneLimit);
    }
check_chosen:
    if (chosen == -1) {
        limit = gSaveTotalSlots;
        if (limit <= 0) goto done;
        index = 0;
        do {
            object = *(void **)((u8 *)sBonusObjectTable + ((index << 16) >> 14));
            if (object == NULL) goto next_bonus;
            state = FIELD(object, s16, 0x7A);
            if (!((state < 2) & (state != 6))) goto next_bonus;
            chosen = index;
            goto update_slots;
next_bonus:
            index++;
        } while (index < limit);
    }
update_slots:
    slots = &gSaveTotalSlots;
    if (*slots > 0) {
        index = 0;
        do {
            signedIndex = index;
            if (signedIndex != chosen) {
                object = sBonusObjectTable[signedIndex];
                if (object != NULL) {
                    if (FIELD(object, u16, 0x78) == 2) {
                        FIELD(object, s16, 0x7A) = 2;
                    } else {
                        FIELD(object, s16, 0x7A) = 6;
                    }
                }
            }
            index++;
        } while (index < *slots);
    }
done:
    if (chosen < 0) {
        D_8011F3A8 = 0;
    }
}

