typedef struct MarkerNode {
    u8 pad[0x28];
    u32 flags;
} MarkerNode;
typedef struct MarkerEventState {
    u8 pad[0x10];
    u8 flags;
} MarkerEventState;
typedef struct MarkerEventActor {
    u8 pad0[0xB4];
    MarkerEventState *state;
    u8 padB8[0xCA];
    s8 marker;
} MarkerEventActor;
void requestSound(s32);
void unlinkNode(MarkerNode *, MarkerNode *, void *);
extern MarkerNode *sTrackMarkerTable[];
extern s16 gMarkerLastIndex1, gMarkerLastIndex2, gMarkerLastIndex3;
extern MarkerNode *sBonusMarkerNodes, *sMarkerTextNode2, *sMarkerTextNode3;

/* Moves the actor's marker into one of three marker slots (selected by slot), unlinks the old marker node from that slot's list, and updates the slot's flags and the node's state. */
void relinkTrackMarkerSlot(MarkerEventActor *actor, s32 slot) {
    s16 *lastIndex;
    MarkerNode *listHead;
    s32 markerIndex;

    u16 slotIndex = slot;
    requestSound(0x223);
    switch (slotIndex) {
    case 1: {
        MarkerEventState *eventState = actor->state;
        lastIndex = &gMarkerLastIndex1;
        eventState->flags |= 1;
        unlinkNode(sBonusMarkerNodes, sTrackMarkerTable[*lastIndex], sTrackMarkerTable[actor->marker]);
        listHead = sBonusMarkerNodes;
        markerIndex = (u32)(u8)actor->marker << 24;
        break;
    }
    case 2: {
        MarkerEventState *eventState = actor->state;
        lastIndex = &gMarkerLastIndex2;
        eventState->flags |= 2;
        unlinkNode(sMarkerTextNode2, sTrackMarkerTable[*lastIndex], sTrackMarkerTable[actor->marker]);
        listHead = sMarkerTextNode2;
        markerIndex = (u32)(u8)actor->marker << 24;
        break;
    }
    default: {
        MarkerEventState *eventState = actor->state;
        lastIndex = &gMarkerLastIndex3;
        eventState->flags |= 4;
        unlinkNode(sMarkerTextNode3, sTrackMarkerTable[*lastIndex], sTrackMarkerTable[actor->marker]);
        listHead = sMarkerTextNode3;
        markerIndex = (u32)(u8)actor->marker << 24;
        break;
    }
    }
    *lastIndex = markerIndex >> 24;
    listHead->flags = (listHead->flags & ~0xFC) | 0xC;
}
