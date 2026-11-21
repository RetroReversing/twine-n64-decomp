/* Switches the active menu item set: runs the old set's leave hook, frees its item records,
   installs newSet, runs its enter hook and builds a record for each new item. */
typedef struct MenuItem {
    u8 pad00[8];
    s32 record;               /* 0x08 */
    u8 pad0C[0x28 - 0x0C];
} MenuItem;

typedef struct MenuItemSet {
    MenuItem *items;          /* 0x00 */
    u8 pad04;
    u8 itemCount;             /* 0x05 */
    u8 pad06[2];
    void (*enter)(void);      /* 0x08 */
    void (*leave)(void);      /* 0x0C */
} MenuItemSet;

typedef struct MenuState {
    u8 pad00[0x10];
    MenuItemSet *activeSet;   /* 0x10 */
} MenuState;

extern MenuState *gMenuItems;

s32 freeMenuItemRecord(s32);
s32 buildMenuItemRecord(void *, s32);

void switchActiveItemSet(MenuItemSet *newSet, s32 colorIndex) {
    MenuItemSet *oldSet;
    MenuState *menu;
    MenuItem *item;
    s16 itemIndex;

    oldSet = gMenuItems->activeSet;
    itemIndex = 0;
    if (oldSet != NULL) {
        if (oldSet->leave != NULL) {
            oldSet->leave();
        }
        menu = gMenuItems;
        if (menu->activeSet->itemCount != 0) {
            do {
                item = &menu->activeSet->items[itemIndex];
                if (item->record != 0) {
                    freeMenuItemRecord(item->record);
                    item->record = 0;
                }
                menu = gMenuItems;
                itemIndex = itemIndex + 1;
            } while (itemIndex < menu->activeSet->itemCount);
        }
    }
    gMenuItems->activeSet = newSet;
    if (newSet != NULL) {
        if (newSet->enter != NULL) {
            newSet->enter();
        }
        for (itemIndex = 0; itemIndex < newSet->itemCount; itemIndex++) {
            item = &newSet->items[itemIndex];
            item->record = buildMenuItemRecord(item, colorIndex);
        }
    }
}
