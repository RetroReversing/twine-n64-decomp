
typedef struct MenuSprite22F {
    char pad[0x10];
    u32 color;
    char pad14[0xC];
    u16 x;
    volatile u16 y;
    u32 unk24;
    u32 highFlags:24;
    u32 mode:6;
    u32 lowFlags:2;
} MenuSprite22F;
typedef struct MenuPair22F { MenuSprite22F *first, *second; } MenuPair22F;
typedef struct MenuEntry22F { MenuPair22F *pair; u16 x, y; u8 slot; } MenuEntry22F;
extern void func_80022B60(s32);
extern s32 D_800BD650, D_800BD65C, sMenuItemParamTable, sSaveMenuColorActive, sSaveMenuColorIdle, sSaveSlotTable;
extern u8 gSaveKeyRelaxed;
extern void *gSaveMenuState;
#define SET_COLOR(member, value) pair->member->color = ((value) & ~0xFF) | ((u8 *)gSaveMenuState)[0x30]
void func_80022F10(MenuEntry22F *entry, u8 enabled) {
    u8 *__base_gSaveKeyRelaxed;
    MenuPair22F *pair;
    register MenuSprite22F *sprite;
    s32 *color;
    if (!entry) return;
    pair = entry->pair;
    if (!pair) return;
    sprite = pair->first;
    if (sprite) {
        sprite->mode = 1 | (-(enabled == 0) & 7);
        pair->first->x = entry->x;
        pair->first->y = entry->y;
        __base_gSaveKeyRelaxed = &gSaveKeyRelaxed;
        if ((*__base_gSaveKeyRelaxed)) {
            switch (entry->slot) {
            case 0: SET_COLOR(first, D_800BD65C); break;
            case 1: SET_COLOR(first, D_800BD650); break;
            case 255: SET_COLOR(first, sSaveMenuColorActive); break;
            default:
                {
                    s32 index = entry->slot - 1;
                    u8 used = ((u8 *)&sSaveSlotTable)[index * 24];
                    s32 *base = &sMenuItemParamTable;
                    MenuSprite22F *dest = pair->first;
                    color = used ? base + 4 : base + 7;
                    dest->color = (*color & ~0xFF) | ((u8 *)gSaveMenuState)[0x30];
                }
                break;
            }
        } else {
            SET_COLOR(first, sSaveMenuColorIdle);
        }
    }
    sprite = pair->second;
    if (sprite) {
        sprite->mode = 1 | (-(enabled == 0) & 7);
        if ((*__base_gSaveKeyRelaxed)) {
            switch (entry->slot) {
            case 0: SET_COLOR(second, D_800BD65C); break;
            case 1: SET_COLOR(second, D_800BD650); break;
            case 255: SET_COLOR(second, sSaveMenuColorActive); break;
            default:
                {
                    s32 index = entry->slot - 1;
                    u8 used = ((u8 *)&sSaveSlotTable)[index * 24];
                    s32 *base = &sMenuItemParamTable;
                    MenuSprite22F *dest = pair->second;
                    color = used ? base + 4 : base + 7;
                    dest->color = (*color & ~0xFF) | ((u8 *)gSaveMenuState)[0x30];
                }
                break;
            }
        } else {
            SET_COLOR(second, sSaveMenuColorIdle);
        }
        if (entry->slot == 255)
            pair->second->x = 160;
        else
            pair->second->x = entry->x + 144;
        pair->second->y = entry->y;
    }
    func_80022B60(1);
}
