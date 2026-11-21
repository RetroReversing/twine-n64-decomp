typedef struct Node { struct Node *prev, *next; } Node;
typedef struct { Node node; u8 pad8[0x20]; u32 flags; } NodeEntry;
typedef struct { u8 pad0[0x10]; u8 flags; } EventState;
typedef struct { u8 pad0[0xB4]; EventState *event; u8 padB8[0xCA]; s8 index; } EventActor;
void requestSound(s32);
void unlinkNode(Node *, Node *, void *);
extern Node *gTrackMarkerTable[];
extern s16 gMarkerLastIndex1, gMarkerLastIndex2, gMarkerLastIndex3;
extern NodeEntry *sMarkerTextNode1, *gMarkerEntry2, *sMarkerTextNode3;

void relinkTrackMarker(EventActor *actor, u16 slot) {
    s16 *previous;
    NodeEntry *entry;
    u32 indexBits;

    requestSound(0x223);
    switch (slot) {
    case 1:
        previous = &gMarkerLastIndex1;
        actor->event->flags |= 1;
        unlinkNode(&sMarkerTextNode1->node, gTrackMarkerTable[*previous], gTrackMarkerTable[actor->index]);
        entry = sMarkerTextNode1;
        indexBits = (u32)(u8)actor->index << 24;
        break;
    case 2:
        previous = &gMarkerLastIndex2;
        actor->event->flags |= 2;
        unlinkNode(&gMarkerEntry2->node, gTrackMarkerTable[*previous], gTrackMarkerTable[actor->index]);
        entry = gMarkerEntry2;
        indexBits = (u32)(u8)actor->index << 24;
        break;
    default:
        previous = &gMarkerLastIndex3;
        actor->event->flags |= 4;
        unlinkNode(&sMarkerTextNode3->node, gTrackMarkerTable[*previous], gTrackMarkerTable[actor->index]);
        entry = sMarkerTextNode3;
        indexBits = (u32)(u8)actor->index << 24;
        break;
    }
    *previous = (s32)indexBits >> 24;
    entry->flags = (entry->flags & ~0xFC) | 0xC;
}
