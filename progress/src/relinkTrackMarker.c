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

void relinkTrackMarker(MarkerEventActor *actor, s32 slot) {
    s16 *last;
    MarkerNode *node;
    s32 marker;

    u16 selected = slot;
    requestSound(0x223);
    switch (selected) {
    case 1: {
        MarkerEventState *state = actor->state;
        last = &gMarkerLastIndex1;
        state->flags |= 1;
        unlinkNode(sBonusMarkerNodes, sTrackMarkerTable[*last], sTrackMarkerTable[actor->marker]);
        node = sBonusMarkerNodes;
        marker = (u32)(u8)actor->marker << 24;
        break;
    }
    case 2: {
        MarkerEventState *state = actor->state;
        last = &gMarkerLastIndex2;
        state->flags |= 2;
        unlinkNode(sMarkerTextNode2, sTrackMarkerTable[*last], sTrackMarkerTable[actor->marker]);
        node = sMarkerTextNode2;
        marker = (u32)(u8)actor->marker << 24;
        break;
    }
    default: {
        MarkerEventState *state = actor->state;
        last = &gMarkerLastIndex3;
        state->flags |= 4;
        unlinkNode(sMarkerTextNode3, sTrackMarkerTable[*last], sTrackMarkerTable[actor->marker]);
        node = sMarkerTextNode3;
        marker = (u32)(u8)actor->marker << 24;
        break;
    }
    }
    *last = marker >> 24;
    node->flags = (node->flags & ~0xFC) | 0xC;
}
