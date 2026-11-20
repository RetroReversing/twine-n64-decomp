typedef struct { s16 f0; u8 pad[6]; } PrioritySlot;
extern PrioritySlot D_800C3928[];
extern s16 D_800C3CF4;
s32 func_80006560(void) {
    s32 best = 0;
    s32 highest = 0;
    s32 position = 0;
    if (D_800C3CF4 >= 0) {
        char *cursor = (char *)&D_800C3CF4;
        s32 index = *(s16 *)cursor;
        do {
            s32 priority = D_800C3928[index].f0;
            cursor += 12;
            if (priority > highest) {
                highest = priority;
                best = position;
            }
            index = *(s16 *)cursor;
        } while (++position, index >= 0);
    }
    return best;
}

typedef struct { s32 address; u8 pad[21]; volatile u8 count; } IndexedList;
s32 func_8002A920(IndexedList *list, s32 index) {
    s32 selected = index;
    if (list == NULL) return 0;
    if ((s32)((u32)index << 24) < 0) selected = list->count - 1;
    return list->address + (s8)(selected & -((s8)selected < list->count)) * 12;
}

extern s32 func_80018364(s32, u16);
extern void *func_80018510(u32);
s32 func_800184AC(s32 arg0, s32 arg1, s32 arg2) {
    s32 scale = func_80018364(arg0, arg1);
    void *record = func_80018510(arg2);
    u32 reduced = scale - 1;
    u32 clamped = 0x7D00;
    u8 value;
    if (reduced <= 0x7D00U) clamped = reduced;
    value = *((u8 *)*(void **)((u8 *)record + 8) + 0x148);
    return clamped * (value + 3) + value;
}

extern s32 D_800E06B8[];
extern s32 D_800E06F8;
void func_8000A724(s32 arg0) {
    u32 index;
    s32 *base;
    u32 remaining;
    if (arg0 != -1) {
        index = D_800E06F8;
        remaining = 15;
        base = D_800E06B8;
        do {
            s32 value = base[index];
            u32 next = index + 1;
            if (value == -1) break;
            index = next & 15;
        } while (remaining--);
        base[index] = arg0;
        D_800E06F8 = (index + 1) & 15;
    }
}
