typedef struct { u8 pad[0x10]; u8 kind; } K11;
typedef struct { u8 pad[0xB4]; K11 *k; } B11;
typedef struct { u8 pad[0x6C]; B11 *b; } A11;
void releaseActorMarkers(A11 *, B11 *, s32);
extern s32 gSaveTotalSlots;
extern A11 *gBonusObjects[];

/* Finds the first bonus object whose info kind is 7 and releases its actor markers. */ void releaseFirstKind7Marker(void) {
    u16 slot;

    for (slot = 0; slot < gSaveTotalSlots; slot++) {
        A11 *a = gBonusObjects[slot];
        if (a != NULL) {
            B11 *b = a->b;
            if (b != NULL) {
                K11 *k = b->k;
                if (k != NULL && k->kind == 7) {
                    releaseActorMarkers(a, b, 0);
                    return;
                }
            }
        }
    }
}
