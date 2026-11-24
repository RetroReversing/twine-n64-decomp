typedef struct { s16 f0; u8 pad[6]; } PrioritySlot;
extern PrioritySlot gShapeTable[];
extern s16 D_800C3CF4;
/* Walks the 12-byte entry table (terminated by a negative shape index) and returns the position of the entry whose shape has the highest priority. */ s32 findHighestPriorityEntry(void) {
    s32 bestPosition = 0;
    s32 highestPriority = 0;
    s32 position = 0;
    if (D_800C3CF4 >= 0) {
        char *entryCursor = (char *)&D_800C3CF4;
        s32 index = *(s16 *)entryCursor;
        do {
            s32 priority = gShapeTable[index].f0;
            entryCursor += 12;
            if (priority > highestPriority) {
                highestPriority = priority;
                bestPosition = position;
            }
            index = *(s16 *)entryCursor;
        } while (++position, index >= 0);
    }
    return bestPosition;
}

typedef struct { s32 address; u8 pad[21]; volatile u8 count; } IndexedList;
s32 getMenuEntry(IndexedList *list, s32 index) {
    s32 selected = index;
    if (list == NULL) return 0;
    if ((s32)((u32)index << 24) < 0) selected = list->count - 1;
    return list->address + (s8)(selected & -((s8)selected < list->count)) * 12;
}

extern s32 func_80018364(s32, u16);
extern void *getFont(u32);
s32 getTextBlockHeight(s32 arg0, s32 arg1, s32 arg2) {
    s32 scale = func_80018364(arg0, arg1);
    void *record = getFont(arg2);
    u32 reduced = scale - 1;
    u32 clamped = 0x7D00;
    u8 value;
    if (reduced <= 0x7D00U) clamped = reduced;
    value = *((u8 *)*(void **)((u8 *)record + 8) + 0x148);
    return clamped * (value + 3) + value;
}

extern s32 gSoundRequestQueue[];
extern s32 gSoundRequestWriteIndex;
void enqueueSoundRequest(s32 arg0) {
    u32 index;
    s32 *base;
    u32 remaining;
    if (arg0 != -1) {
        index = gSoundRequestWriteIndex;
        remaining = 15;
        base = gSoundRequestQueue;
        do {
            s32 value = base[index];
            u32 next = index + 1;
            if (value == -1) break;
            index = next & 15;
        } while (remaining--);
        base[index] = arg0;
        gSoundRequestWriteIndex = (index + 1) & 15;
    }
}
