typedef struct {
    f32 minX, maxX, minY, maxY;
} Bounds156;

typedef struct {
    Bounds156 bounds;
    u8 pad10[0x44];
    f32 depth;
    u8 pad58[8];
    u16 stamp;
} EntryData156;

typedef struct Entry156 {
    u8 pad0[0x1C];
    struct Entry156 *next;
    EntryData156 *data;
} Entry156;

extern u16 gSurfaceQueryStamp;
extern Entry156 *D_80102D68[];
extern Bounds156 D_80103F10[];
extern Entry156 *gObjectListHead;
extern u32 D_80109E1C;

void func_800156F4(void) {
    u32 i;
    u32 count;
    s32 stamp;
    Bounds156 *b;
    Entry156 *entry;
    Entry156 *cur;
    Entry156 *prev;

    u32 s0 = gSurfaceQueryStamp + 1;
    count = D_80109E1C;
    gSurfaceQueryStamp = s0;
    for (i = 0; i < D_80109E1C; i++) {
        entry = D_80102D68[i];
        b = &D_80103F10[i];
        if (entry->data->stamp != gSurfaceQueryStamp) {
            entry->data->stamp = gSurfaceQueryStamp;
            entry->data->bounds.minX = b->minX;
            entry->data->bounds.minY = b->minY;
            entry->data->bounds.maxX = b->maxX;
            entry->data->bounds.maxY = b->maxY;
        } else {
            if (b->minX < entry->data->bounds.minX) entry->data->bounds.minX = b->minX;
            if (b->minY < entry->data->bounds.minY) entry->data->bounds.minY = b->minY;
            if (entry->data->bounds.maxX < b->maxX) entry->data->bounds.maxX = b->maxX;
            if (entry->data->bounds.maxY < b->maxY) entry->data->bounds.maxY = b->maxY;
            continue;
        }
        prev = NULL;
        cur = gObjectListHead;
        if (cur == NULL) {
            entry->next = NULL; gObjectListHead = entry; continue;
        }
        do {
            if (entry->data->depth < cur->data->depth) {
                if (prev == NULL) {
                    entry->next = cur;
                    gObjectListHead = entry;
                    goto next;
                }
                entry->next = cur;
                prev->next = entry;
                goto next;
            }
            prev = cur;
            cur = prev->next;
        } while (cur != NULL);
        prev->next = entry;
        entry->next = NULL;
    next:;
    }
}
