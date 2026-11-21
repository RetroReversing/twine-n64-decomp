typedef struct { u8 pad0[0xC]; u16 a; u16 b; u8 pad10[2]; u8 type; } SlotInfo;
typedef struct { u8 pad0[0xB4]; SlotInfo *info; } SlotActor;
typedef struct { u8 pad0[0x10]; s32 color; u8 pad14[0x14]; u32 flags; } SlotText;
extern s32 gVisibleSaveSlotCount;
extern s32 gSaveTotalSlots;
extern SlotActor *D_80102CD0[];
extern s16 D_8011F15C[];
extern char D_8011F2B8[];
extern s16 D_8011F3E0[];
extern SlotText *D_8011F3E8[];
char *lookupDataEntry();
int sprintf();
void func_8011D158(s16 arg0) {
    s32 idx = arg0;
    SlotInfo *info;
    u32 t;
    s32 id;
    s32 count;
    s32 i;
    if (idx < gVisibleSaveSlotCount) {
        info = D_80102CD0[idx]->info;
        t = info->type;
        if (t == 2) {
            s32 diff = info->a - info->b;
            count = gSaveTotalSlots;
            for (i = 0; i < gSaveTotalSlots; i++) {
                if (i != idx) {
                    SlotInfo *o = D_80102CD0[i]->info;
                    count -= (diff >= (s32)(o->a - o->b));
                }
            }
            switch (count) {
            case 1: id = 0x2E5; goto doit;
            case 2: id = 0x2E6; goto doit;
            case 3: id = 0x2E7; goto doit;
            case 4: id = 0x2E8;
            doit:
                sprintf(D_8011F2B8 + arg0 * 12, lookupDataEntry(id));
            }
            D_8011F3E8[arg0]->flags = (D_8011F3E8[arg0]->flags & ~0xFC) | 0xC;
            D_8011F3E8[arg0]->color = -1;
            D_8011F3E0[arg0] = 0x3C;
        } else {
            id = 0x2E6;
            if (D_8011F15C[t] >= D_8011F15C[1 - t]) id = 0x2E5;
            sprintf(D_8011F2B8 + idx * 12, lookupDataEntry(id));
            D_8011F3E8[arg0]->flags = (D_8011F3E8[arg0]->flags & ~0xFC) | 0xC;
            if (t == 0) D_8011F3E8[arg0]->color = 0xFF2020FF;
            else D_8011F3E8[arg0]->color = 0x2020FFFF;
            D_8011F3E0[arg0] = 0x3C;
        }
    }
}
