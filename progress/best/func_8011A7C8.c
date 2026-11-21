typedef struct SlotMeta {
    u8 pad[0xC];
    u16 count;
    u8 padE[2];
    u8 type;
    u8 disabled;
} SlotMeta;
typedef struct SaveSlot {
    u8 pad[0xB4];
    SlotMeta *meta;
} SaveSlot;
typedef struct BonusSlot {
    u8 pad[0x78];
    u16 type;
    s16 state;
} BonusSlot;
typedef struct SceneSlots {
    u8 type;
    u8 pad[0x13];
    s32 count;
} SceneSlots;
extern SceneSlots gSceneType;
extern s32 gSaveTotalSlots;
extern SaveSlot *D_80102CD0[];
extern BonusSlot *sBonusObjectTable[];
extern s32 D_8011F3A8;

void func_8011A7C8(void)
{
    s16 i;
    s16 chosen = -1;
    s32 index;
    SaveSlot **slot;
    SaveSlot *entry;
    BonusSlot *bonus;
    s32 count;
    s16 state;

    if (gSceneType.type == 8 && (i = 0, gSaveTotalSlots > 0)) {
        do {
            index = (s16)i;
            slot = &D_80102CD0[index];
            entry = *slot;
            if (entry != 0 && entry->meta->type == 7) {
                chosen = i;
                i = 0;
                if (i < gSceneType.count) {
                    do {
                        if (i == index) goto next_scene;
                        entry = D_80102CD0[i];
                        if (entry == 0 || entry->meta->disabled != 0) goto next_scene;
                        (*slot)->meta->count++;
next_scene:
                        i++;
                    } while ((s16)i < *(volatile s32 *)((u8 *)&gSceneType + ((u8 *)&gSaveTotalSlots - (u8 *)&gSceneType)));
                }
                break;
            }
            i++;
        } while ((s16)i < gSceneType.count);
    }
    if ((s16)chosen == -1) {
        i = 0;
        count = gSaveTotalSlots;
        if (count <= 0) goto done;
        do {
            bonus = sBonusObjectTable[(s16)i];
            if (bonus == 0) goto next_bonus;
            state = bonus->state;
            if (!((state < 2) & (state != 6))) goto next_bonus;
            chosen = i;
            goto update;
next_bonus:
            i++;
        } while ((s16)i < count);
        goto done;
    }
update:
    i = 0;
    if (*(volatile s32 *)&gSaveTotalSlots > 0) {
        do {
            if ((s16)i != (s16)chosen) {
                bonus = sBonusObjectTable[(s16)i];
                if (bonus != 0) {
                    if (bonus->type == 2) {
                        bonus->state = 2;
                    } else {
                        bonus->state = 6;
                    }
                }
            }
            i++;
        } while ((s16)i < *(volatile s32 *)&gSaveTotalSlots);
    }
done:
    if ((s16)chosen < 0) {
        D_8011F3A8 = 0;
    }
}
