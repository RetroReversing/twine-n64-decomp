typedef struct Node { struct Node *prev, *next; } Node;
typedef struct { Node node; u8 pad8[0x20]; u32 flags; } NodeEntry;
typedef struct { u8 pad0[0x10]; u8 flags; } EventState;
typedef struct { u8 pad0[0xB4]; EventState *event; u8 padB8[0xCA]; s8 index; } EventActor;
void func_8000A894(s32);
void func_80016624(Node *, Node *, void *);
extern Node *gAimAxisTable[];
extern s16 D_8011ED74, D_8011ED98, D_8011EDBC;
extern NodeEntry *D_8011F3C4, *D_8011F3C8, *D_8011F3CC;

void func_8011B460(EventActor *actor, u16 slot) {
    s16 *previous;
    NodeEntry *entry;
    u32 indexBits;

    func_8000A894(0x223);
    switch (slot) {
    case 1:
        previous = &D_8011ED74;
        actor->event->flags |= 1;
        func_80016624(&D_8011F3C4->node, gAimAxisTable[*previous], gAimAxisTable[actor->index]);
        entry = D_8011F3C4;
        indexBits = (u32)(u8)actor->index << 24;
        break;
    case 2:
        previous = &D_8011ED98;
        actor->event->flags |= 2;
        func_80016624(&D_8011F3C8->node, gAimAxisTable[*previous], gAimAxisTable[actor->index]);
        entry = D_8011F3C8;
        indexBits = (u32)(u8)actor->index << 24;
        break;
    default:
        previous = &D_8011EDBC;
        actor->event->flags |= 4;
        func_80016624(&D_8011F3CC->node, gAimAxisTable[*previous], gAimAxisTable[actor->index]);
        entry = D_8011F3CC;
        indexBits = (u32)(u8)actor->index << 24;
        break;
    }
    *previous = (s32)indexBits >> 24;
    entry->flags = (entry->flags & ~0xFC) | 0xC;
}
