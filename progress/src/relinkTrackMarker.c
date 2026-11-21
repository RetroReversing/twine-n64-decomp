typedef struct Node { struct Node *prev, *next; } Node;
typedef struct { Node node; u8 pad8[0x20]; u32 flags; } NodeEntry;
typedef struct { u8 pad0[0x10]; u8 flags; } EventState;
typedef struct { u8 pad0[0xB4]; EventState *event; u8 padB8[0xCA]; s8 index; } EventActor;
void requestSound(s32);
void unlinkNode(Node *, Node *, void *);
extern Node *gTrackMarkerTable[];
extern s16 gMarkerLastIndex1, gMarkerLastIndex2, gMarkerLastIndex3;
extern NodeEntry *sMarkerTextNode1, *sMarkerTextNode2, *sMarkerTextNode3;
/* Moves a track marker's text entry to the list for its slot (1, 2 or other) and updates that list's last index. */
void relinkTrackMarker(EventActor *actor, u16 slot) {
 s16 *lastIndex; NodeEntry *textNode; u32 indexBits;
 requestSound(0x223);
 switch(slot) {
 case 1:
 lastIndex=&gMarkerLastIndex1; actor->event->flags |= 1;
 unlinkNode(&sMarkerTextNode1->node,gTrackMarkerTable[*lastIndex],gTrackMarkerTable[actor->index]);
 textNode=sMarkerTextNode1; indexBits=(u32)(u8)actor->index << 24; break;
 case 2:
 lastIndex=&gMarkerLastIndex2; actor->event->flags |= 2;
 unlinkNode(&sMarkerTextNode2->node,gTrackMarkerTable[*lastIndex],gTrackMarkerTable[actor->index]);
 textNode=sMarkerTextNode2; indexBits=(u32)(u8)actor->index << 24; break;
 default:
 lastIndex=&gMarkerLastIndex3; actor->event->flags |= 4;
 unlinkNode(&sMarkerTextNode3->node,gTrackMarkerTable[*lastIndex],gTrackMarkerTable[actor->index]);
 textNode=sMarkerTextNode3; indexBits=(u32)(u8)actor->index << 24; break;
 }
 *lastIndex=(s32)indexBits >> 24;
 textNode->flags=(textNode->flags & ~0xFC) | 0xC;
}
