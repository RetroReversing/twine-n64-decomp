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
extern Entry156 *gPendingEntries[];
extern Bounds156 gPendingEntryBounds[];
extern Entry156 *gObjectListHead;
extern u32 gPendingEntryCount;

/* Merges pending bounds into each entry's data (once per stamp) and inserts each new entry into gObjectListHead, sorted by ascending depth. */ void buildDepthSortedObjectList(void) {
    u32 i;
    u32 count;
    s32 stamp;
    Bounds156 *pending;
    Entry156 *entry;
    Entry156 *node;
    Entry156 *prevNode;

    u32 newStamp = gSurfaceQueryStamp + 1;
    count = gPendingEntryCount;
    gSurfaceQueryStamp = newStamp;
    for (i = 0; i < gPendingEntryCount; i++) {
        entry = gPendingEntries[i];
        pending = &gPendingEntryBounds[i];
        if (entry->data->stamp != gSurfaceQueryStamp) {
            entry->data->stamp = gSurfaceQueryStamp;
            entry->data->bounds.minX = pending->minX;
            entry->data->bounds.minY = pending->minY;
            entry->data->bounds.maxX = pending->maxX;
            entry->data->bounds.maxY = pending->maxY;
        } else {
            if (pending->minX < entry->data->bounds.minX) entry->data->bounds.minX = pending->minX;
            if (pending->minY < entry->data->bounds.minY) entry->data->bounds.minY = pending->minY;
            if (entry->data->bounds.maxX < pending->maxX) entry->data->bounds.maxX = pending->maxX;
            if (entry->data->bounds.maxY < pending->maxY) entry->data->bounds.maxY = pending->maxY;
            continue;
        }
        prevNode = NULL;
        node = gObjectListHead;
        if (node == NULL) {
            entry->next = NULL; gObjectListHead = entry; continue;
        }
        do {
            if (entry->data->depth < node->data->depth) {
                if (prevNode == NULL) {
                    entry->next = node;
                    gObjectListHead = entry;
                    goto next;
                }
                entry->next = node;
                prevNode->next = entry;
                goto next;
            }
            prevNode = node;
            node = prevNode->next;
        } while (node != NULL);
        prevNode->next = entry;
        entry->next = NULL;
    next:;
    }
}
