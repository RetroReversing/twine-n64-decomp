typedef struct SaveRowSprites {
    void *label;
    void *value;
} SaveRowSprites;
typedef struct SaveRow {
    SaveRowSprites *sprites;
    u16 x, y;
    u8 slot;
} SaveRow;
typedef struct SaveSlotRecord {
    u8 occupied;
    u8 rest[23];
} SaveSlotRecord;
extern SaveSlotRecord sSaveSlotTable[];
extern s32 sMenuItemParamTable[];
extern s32 D_800BD65C, D_800BD650;
extern s32 sSaveMenuColorActive, sSaveMenuColorIdle;
extern void *gSaveMenuState;
extern u8 gSaveKeyRelaxed;
extern void func_80022B60(s32);

#define FIELD(ptr, type, offset) (*(type *)((u8 *)(ptr) + (offset)))

void func_80022F10(SaveRow *row, u8 enabled) {
    SaveRowSprites *sprites;
    void *element, *menu, *destination;
    s32 color, flags, mode;
    s32 *selected;

    if (!row || !(sprites = row->sprites))
        return;
    element = sprites->label;
    if (element != NULL) {
        flags = FIELD(element, s32, 0x28) & ~0xFC;
        mode = (-(!enabled) & 7) | 1;
        FIELD(element, s32, 0x28) = flags | (mode << 2);
        FIELD(sprites->label, u16, 0x20) = row->x;
        FIELD(sprites->label, u16, 0x22) = row->y;
        if (gSaveKeyRelaxed) {
            switch (row->slot) {
            case 0:
                menu = gSaveMenuState;
                destination = sprites->label;
                color = D_800BD65C;
                goto apply_label;
            case 1:
                menu = gSaveMenuState;
                destination = sprites->label;
                color = D_800BD650;
                goto apply_label;
            case 255:
                menu = gSaveMenuState;
                destination = sprites->label;
                color = sSaveMenuColorActive;
                goto apply_label;
            default:
                {
                    s32 *table = sMenuItemParamTable;
                    u8 occupied = sSaveSlotTable[row->slot - 1].occupied;
                    destination = sprites->label;
                    selected = table + 4;
                    if (occupied == 0)
                        selected = table + 7;
                }

                menu = gSaveMenuState;
                color = *selected;
                goto apply_label;
            }
        }
        menu = gSaveMenuState;
        destination = sprites->label;
        color = sSaveMenuColorIdle;
    apply_label:
        FIELD(destination, s32, 0x10) = (color & ~0xFF) | FIELD(menu, u8, 0x30);
    }
    element = sprites->value;
    if (element != NULL) {
        flags = FIELD(element, s32, 0x28) & ~0xFC;
        mode = (-(!enabled) & 7) | 1;
        FIELD(element, s32, 0x28) = flags | (mode << 2);
        if (gSaveKeyRelaxed) {
            switch (row->slot) {
            case 0:
                menu = gSaveMenuState;
                destination = sprites->value;
                color = D_800BD65C;
                goto apply_value;
            case 1:
                menu = gSaveMenuState;
                destination = sprites->value;
                color = D_800BD650;
                goto apply_value;
            case 255:
                menu = gSaveMenuState;
                destination = sprites->value;
                color = sSaveMenuColorActive;
                goto apply_value;
            default:
                {
                    s32 *table = sMenuItemParamTable;
                    u8 occupied = sSaveSlotTable[row->slot - 1].occupied;
                    destination = sprites->value;
                    selected = table + 4;
                    if (occupied == 0)
                        selected = table + 7;
                }

                menu = gSaveMenuState;
                color = *selected;
                goto apply_value;
            }
        }
        menu = gSaveMenuState;
        destination = sprites->value;
        color = sSaveMenuColorIdle;
    apply_value:
        FIELD(destination, s32, 0x10) = (color & ~0xFF) | FIELD(menu, u8, 0x30);
        if (row->slot == 255)
            FIELD(sprites->value, u16, 0x20) = 160;
        else
            FIELD(sprites->value, u16, 0x20) = row->x + 144;
        FIELD(sprites->value, u16, 0x22) = row->y;
    }
    func_80022B60(1);
}
