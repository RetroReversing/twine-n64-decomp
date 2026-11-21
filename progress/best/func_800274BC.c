typedef struct {
    u32 value __attribute__((packed));
} MenuSelectionWord;
typedef struct { u8 pad[0x13]; u8 low; } MenuItemParams;
typedef struct {
    u8 pad[8];
    MenuItemParams *params;
    u16 flags;
    u8 rest[0x16];
    MenuSelectionWord link;
} SaveMenuItem;
typedef struct { SaveMenuItem *items; u8 pad; u8 count; } SaveMenuList;
typedef struct {
    u8 pad[7];
    u8 previous;
    u8 selected;
    u8 pad9[7];
    SaveMenuList *list;
    u8 pad14[4];
    SaveMenuItem *active;
    s32 textBox;
    u8 pad20[14];
    u8 redraw;
    u8 pad2F;
    u8 param;
} SaveMenu;
extern SaveMenu *gSaveMenuState;
extern void *sActiveMenu;
extern MenuSelectionWord D_801002E6;
extern u32 D_80102EC0, gMenuSoundParams, sMenuDefaultSoundParams, sMenuItemParamTable[];
void func_8000A894(s32);
void layoutTextBox(s32, void *, s32);

void func_800274BC(s32 command, s32 direction)
{
    SaveMenuItem *active;
    SaveMenuList *list;
    union { SaveMenuItem * pointer; s32 value; } __repair_phase_storage;
    MenuItemParams *params;
    u8 selected;
    u8 previous;
    u8 low;
    u16 flags;
    
    u32 word;

    if (gSaveMenuState == NULL)
        return;
    active = gSaveMenuState->active;
    list = gSaveMenuState->list;
    previous = gSaveMenuState->selected;
    if (!gSaveMenuState->textBox)
        return;
    if (list == NULL)
        return;
    if (active == NULL)
        return;

    selected = previous;
    if (command == 0x100)
        goto move;
    if (command == 0x101)
        goto scan;
    goto update;
move: {
        s8 index;
        if (direction == 0xFF)
            return;
        index = ((s8 *)&active->link)[direction];
        if (index < 0)
            return;
        if ((u8)index == selected)
            return;
        selected = index;
        active->link = D_801002E6;
        __repair_phase_storage.pointer = &list->items[(u8)index];
        if (__repair_phase_storage.pointer != NULL)
            D_801002E6 = __repair_phase_storage.pointer->link;
        goto update;
    }
scan: {
        u8 index = selected;
        u8 count = list->count;
        if (index < count) {
            SaveMenuItem *items = list->items;
            do {
                if (items[index].flags & 0x80) {
                    selected = index;
                    break;
                }
                index++;
            } while (index < count);
        }
        __repair_phase_storage.pointer = &list->items[selected];
        if (__repair_phase_storage.pointer != NULL)
            D_801002E6 = __repair_phase_storage.pointer->link;
    }
update:
    if (selected != previous && *(s16 *)((u8 *)sActiveMenu + 0x7A) != 0x14)
        func_8000A894(0xED);
    if (gSaveMenuState->previous != gSaveMenuState->selected)
        gSaveMenuState->previous = gSaveMenuState->selected;
    gSaveMenuState->redraw = 1;

    flags = active->flags;
    __repair_phase_storage.value = flags & 0xF;
    if (__repair_phase_storage.value != 0) {
        params = active->params;
        word = sMenuItemParamTable[__repair_phase_storage.value];
        low = gSaveMenuState->param;
    } else {
        if (flags & 0x80) {
            params = active->params;
            word = gMenuSoundParams;
        } else {
            params = active->params;
            word = sMenuDefaultSoundParams;
        }
        low = params->low;
    }
    *(u32 *)((u8 *)params + 0x10) = (word & ~0xFF) | low;

    gSaveMenuState->selected = selected;
    active = &list->items[selected];
    gSaveMenuState->active = active;
    params = active->params;
    if (params != NULL) {
        __repair_phase_storage.value = active->flags & 0xF;
        if (__repair_phase_storage.value != 0) {
            word = sMenuItemParamTable[__repair_phase_storage.value];
            low = gSaveMenuState->param;
        } else {
            word = D_80102EC0;
            low = params->low;
        }
        *(u32 *)((u8 *)params + 0x10) = (word & ~0xFF) | low;
    }
    layoutTextBox(gSaveMenuState->textBox, active, 0);
}
