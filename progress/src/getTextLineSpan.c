typedef struct {
    s8 *text;
    s16 length;
} TextLine30818;
void getTextLineSpan(TextLine30818 *out, s8 *start, u16 line) {
    u16 count = 0;
    s8 *end = start;
    if (start != 0) {
        do {
            s8 ch = *start;
            if (!ch) break;
            if (count == line) break;
            if (ch == '\n') count++;
            start++;
        } while (start != 0);
        end = start;
        if (end != 0) {
            do {
                s8 ch = *end;
                if (!ch || ((ch == '\n') | (ch == '\0'))) break;
                end++;
            } while (end != 0);
        }
    }
    out->text = start;
    out->length = end - start;
}

extern u8 gInputBindingTables[];
s32 func_800819EC(s32 player, s32 button) {
    s32 offset = player * 0xA0;
    u8 *base = gInputBindingTables + offset;
    u8 *slot = base + button * 2;
    u8 axis = slot[1];
    u8 flags;
    s32 value;
    if (axis) {
        value = *(s32 *)(gInputBindingTables + 0x70 + axis * 4 + offset);
        if (slot[0] & 0x40) {
            if (value < 0) return value;
        } else {
            if (value > 0) return value;
        }
    }
    slot = base + button * 2;
    flags = slot[0];
    if (!(flags & 2)) return 0;
    if (flags & 0x80) {
        slot[0] = flags & 0x7F;
        return 0;
    }
    return -((flags & 0x20) != 0) * 0x10000 | 0x10000;
}

typedef struct {
    u8 pad[0x1e];
    u16 scale, x, y, z;
    u16 pad26;
    union {
        u32 flags;
        u8 color;
    } state;
} Object22AD8;
extern Object22AD8 *D_800B7CF4;
extern u16 D_800E0EE0, D_800E0EE2, D_800E0EE4, D_800E0EE6;
extern s32 spawnTrackMarker(s32);
void updateTrackMarker(u8 index) {
    Object22AD8 *obj;
    u16 x, y, z, color;
    u32 flags;
    if (D_800B7CF4 == 0) {
        D_800B7CF4 = (Object22AD8 *)spawnTrackMarker(index);
        if (D_800B7CF4 == 0) return;
    }
    obj = D_800B7CF4;
    x = D_800E0EE0;
    y = D_800E0EE2;
    z = D_800E0EE4;
    flags = obj->state.flags;
    obj->x = x;
    color = D_800E0EE6;
    obj->scale = 0x1000;
    obj->y = y;
    obj->z = z;
    obj->state.flags = (flags & ~0xFC) | 0x1C;
    obj->state.color = color;
}

extern s32 gSaveSlotCount, gSaveExtraSlotCount;
extern s32 saveSlotKeyCheck(s32);
s32 areAllSaveSlotsValid(void) {
    u16 i = 0;
    if (gSaveSlotCount > 0) {
        do {
            if ((u16)saveSlotKeyCheck(i) != 0x159) return 0;
            i++;
        } while (i < gSaveSlotCount);
    }
    i = 4;
    if (gSaveExtraSlotCount + 4 > 4) {
        do {
            if ((u16)saveSlotKeyCheck(i) != 0x159) return 0;
            i++;
        } while (i < gSaveExtraSlotCount + 4);
    }
    return 1;
}
