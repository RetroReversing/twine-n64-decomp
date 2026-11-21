extern void requestSound(int);
extern void func_80016624(void *, void *, void *);
extern void *gTrackMarkers[];
extern s16 D_8011ED74,D_8011ED98,D_8011EDBC;
typedef struct { char pad[0x28]; int flags; } Node;
extern Node *D_8011F3C4,*D_8011F3C8,*D_8011F3CC;
/* Relinks a track marker into one of three marker text nodes, flags the event, and records the marker index in the matching slot. */ void relinkTrackMarker(TwineSlotEventActor *a, u16 n) {
 s16 *lastIndexSlot; Node *textNode; int indexByte;
 requestSound(0x223);
 switch (n & 0xffff) {
 case 1:
 a->event->flags |= 1; lastIndexSlot=&D_8011ED74;
 func_80016624(D_8011F3C4,gTrackMarkers[*lastIndexSlot],gTrackMarkers[a->index]);
 textNode=D_8011F3C4; indexByte=(u8)a->index << 24; break;
 case 2:
 a->event->flags |= 2; lastIndexSlot=&D_8011ED98;
 func_80016624(D_8011F3C8,gTrackMarkers[*lastIndexSlot],gTrackMarkers[a->index]);
 textNode=D_8011F3C8; indexByte=(u8)a->index << 24; break;
 default:
 a->event->flags |= 4; lastIndexSlot=&D_8011EDBC;
 func_80016624(D_8011F3CC,gTrackMarkers[*lastIndexSlot],gTrackMarkers[a->index]);
 textNode=D_8011F3CC; indexByte=(u8)a->index << 24; break;
 }
 *lastIndexSlot=indexByte>>24;
 textNode->flags=(textNode->flags & ~0xfc)|0xc;
}
