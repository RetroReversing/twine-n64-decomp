extern void requestSound(int);
extern void func_80016624(void *, void *, void *);
extern void *gTrackMarkers[];
extern s16 D_8011ED74,D_8011ED98,D_8011EDBC;
typedef struct { char pad[0x28]; int flags; } Node;
extern Node *D_8011F3C4,*D_8011F3C8,*D_8011F3CC;
void relinkTrackMarker(TwineSlotEventActor *a, u16 n) {
 s16 *slot; Node *node; int v;
 requestSound(0x223);
 switch (n & 0xffff) {
 case 1:
 a->event->flags |= 1; slot=&D_8011ED74;
 func_80016624(D_8011F3C4,gTrackMarkers[*slot],gTrackMarkers[a->index]);
 node=D_8011F3C4; v=(u8)a->index << 24; break;
 case 2:
 a->event->flags |= 2; slot=&D_8011ED98;
 func_80016624(D_8011F3C8,gTrackMarkers[*slot],gTrackMarkers[a->index]);
 node=D_8011F3C8; v=(u8)a->index << 24; break;
 default:
 a->event->flags |= 4; slot=&D_8011EDBC;
 func_80016624(D_8011F3CC,gTrackMarkers[*slot],gTrackMarkers[a->index]);
 node=D_8011F3CC; v=(u8)a->index << 24; break;
 }
 *slot=v>>24;
 node->flags=(node->flags & ~0xfc)|0xc;
}
