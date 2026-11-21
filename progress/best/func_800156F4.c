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

extern u16 D_800B35B0;
extern Entry156 *D_80102D68[];
extern Bounds156 D_80103F10[];
extern Entry156 *gObjectListHead;
extern u32 D_80109E1C;

void func_800156F4(void) {
    u8 frame[8];
    u32 count;
    u32 i;
    s32 stamp;
    Bounds156 *bounds;
    Entry156 **entries;
    Entry156 *entry;
    Entry156 *current;
    Entry156 *previous;
    EntryData156 *data;
    EntryData156 *minYData;
    EntryData156 *maxXData;
    EntryData156 *maxYData;
    f32 value;

    stamp = D_800B35B0 + 1;
    D_800B35B0 = stamp;
    count = D_80109E1C;
    i = 0;
    if (count != 0) {
        bounds = D_80103F10;
        entries = D_80102D68;
        do {
            entry = *entries;
            data = entry->data;
            if (data->stamp != (u16)stamp) {
                data->stamp = stamp;
                entry->data->bounds.minX = bounds->minX;
                entry->data->bounds.minY = bounds->minY;
                entry->data->bounds.maxX = bounds->maxX;
                entry->data->bounds.maxY = bounds->maxY;
            } else {
                value = bounds->minX;
                if (value < data->bounds.minX) data->bounds.minX = value;
                minYData = entry->data;
                value = bounds->minY;
                if (value < minYData->bounds.minY) minYData->bounds.minY = value;
                maxXData = entry->data;
                value = bounds->maxX;
                if (maxXData->bounds.maxX < value) maxXData->bounds.maxX = value;
                maxYData = entry->data;
                value = bounds->maxY;
                if (maxYData->bounds.maxY < value) maxYData->bounds.maxY = value;
                goto advance;
            }

            current = gObjectListHead;
            previous = NULL;
            if (current == NULL) {
                entry->next = NULL;
                ++bounds;
                gObjectListHead = entry;
                goto nextEntry;
            } else {
                do {
                    if (entry->data->depth < current->data->depth) {
                        entry->next = current;
                        if (previous == NULL) {
                            gObjectListHead = entry;
                            goto advance;
                        }
                        previous->next = entry;
                        goto advance;
                    }
                    previous = current;
                    current = previous->next;
                } while (current != NULL);
                previous->next = entry;
                entry->next = NULL;
            }
advance:
            ++bounds;
nextEntry:
            ++i;
            ++entries;
        } while (i < count);
    }
}
