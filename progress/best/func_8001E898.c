typedef struct {
    char pad0[0x10];
    u32 color;
    char pad14[0xA];
    u16 size;
    u16 x;
    u16 y;
    char pad24[4];
    unsigned int flags;
} TextObject;

typedef struct {
    TextObject *object;
    u16 x;
    union { u16 y; struct { u8 high, low; } bytes; } position;
    u8 id;
} TextEntry;

typedef struct { char pad[0x30]; u8 alpha; } OpacityState;

s32 func_80018318(TextObject *);
void func_80022B60(s32);
void func_80022E5C(s32);
void func_80022E88(s32);
void func_80022EB8(u16, u8, u8);
extern u16 gMenuMode;
extern u32 D_800BD660;
extern u32 D_800BD664;
extern u8 gMenuSlot;
extern u16 D_800E0ECC[];
extern u16 D_800E0ED4[];
extern u32 D_80102EBC;
extern OpacityState *gMenuState;

void func_8001E898(TextEntry *entry, u8 dim, u8 draw) {
    u8 *__base_D_800BD68F;
    TextObject *object = entry->object;
    register u16 selected;

    if (object != (u32)NULL) {
        object->flags = (object->flags & ~0xFC) | (-(dim == 0) & 0x1C);
        object->x = entry->x;
        object->y = entry->position.y;
        object->size = 0x40;
        func_80022B60(0);
        object->color = (D_80102EBC & ~0xFF) | gMenuState->alpha;
        func_80022E88(0);
        func_80022E5C(gMenuState->alpha);
        switch (gMenuMode) {
        case 0:
            if (!draw) {
                __base_D_800BD68F = &gMenuSlot;
                selected = D_800E0ECC[(*__base_D_800BD68F)];
                if (selected == entry->id) {
                    object->color = (D_800BD660 & ~0xFF) | gMenuState->alpha;
                }
                break;
            }
            func_80022EB8(entry->x - 2, entry->position.bytes.low - 4,
                          (func_80018318(object) * 12) & 0xFC);
            object->color = (D_800BD664 & ~0xFF) | gMenuState->alpha;
            break;
        case 1:
            if (draw) {
                func_80022EB8(entry->x - 2, entry->position.bytes.low - 4,
                              (func_80018318(object) * 12) & 0xFC);
                object->color = (D_800BD664 & ~0xFF) | gMenuState->alpha;
                break;
            }
            selected = D_800E0ED4[gMenuSlot];
            if ((unsigned)selected == entry->id) {
                object->color = (D_800BD660 & ~0xFF) | gMenuState->alpha;
            }
            break;
        }
        object->color = (object->color & ~0xFF) | gMenuState->alpha;
    }
}
