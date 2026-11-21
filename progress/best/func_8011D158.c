typedef struct { char pad[12]; u16 start, end; char pad2[2]; u8 kind; } Save;
typedef struct { char pad[0xB4]; Save *save; } Slot;
typedef struct { char pad[0x10]; u32 color; char pad2[0x14]; u32 flags; } Label;
extern Slot *D_80102CD0[];
extern s16 D_8011F15C[], D_8011F3E0[];
extern char D_8011F2B8[][12];
extern Label *D_8011F3E8[];
extern s32 gVisibleSaveSlotCount, gSaveTotalSlots;
extern void *lookupDataEntry(s32);
extern s32 sprintf(char *, const char *, ...);

void func_8011D158(s32 slot) {
    volatile s32 *count = &gVisibleSaveSlotCount;
    s32 index = (s16)slot;
    s32 id;
    s32 kind;
    Save *save;
    Slot **cursor;
    s32 temp;
    s32 unused[2];
    Label **label;
    if (index < *count) {
    save = D_80102CD0[index]->save;
    kind = save->kind;
    temp = kind;
    cursor = D_80102CD0;
    if (temp == 2) {
        s32 delta = save->start - save->end;
        s32 rank = gSaveTotalSlots;
        temp = 0;
        if (rank > 0) {
            s32 limit = rank;
            do {
                if (temp++ != index) {
                    Save *other = (*cursor)->save;
                    rank -= delta >= other->start - other->end;
                }
                cursor++;
            } while (temp < limit);
        }
        switch (rank) {
        case 1: id = 0x2E5; goto format;
        case 2: id = 0x2E6; goto format;
        case 3: id = 0x2E7; goto format;
        case 4: id = 0x2E8; goto format;
        format:
            sprintf(D_8011F2B8[(s16)slot], lookupDataEntry(id));
        }
        index = (s16)slot;
        label = (u32)D_8011F3E8 + index;
        (*label)->flags = ((*label)->flags & ~0xFC) | 0xC;
        (*label)->color = -1;
        D_8011F3E0[index] = 60;
    } else {
        id = 0x2E6;
        if (D_8011F15C[temp] >= D_8011F15C[1-temp])
            id = 0x2E5;
        sprintf(D_8011F2B8[index], lookupDataEntry(id));
        label = (Label **)((char *)D_8011F3E8 + ((s32)((u32)slot << 16) >> 14));
        (*label)->flags = ((*label)->flags & ~0xFC) | 0xC;
        if (kind == 0)
            (*label)->color = 0xFF2020FF;
        else
            (*label)->color = 0x2020FFFF;
        *(s16 *)((char *)D_8011F3E0 + ((s32)((u32)slot << 16) >> 15)) = 60;
    }
    }
}
