f32 approxDistance();
s8 func_8005EF84();
extern const f64 D_800D4190;
extern u8 gTrackMarkerDone[];
extern void *gBonusObjects;

/* Checks the four bonus object slots for one close to this actor and runs the pickup handler when the track allows it. */
s8 checkBonusObjectPickup(void *actor) {
    u32 i;
    void **slot;
    void *object;
    void *track;
    u16 trackId;

    track = *(void **)((s8 *)actor + 0x6C);
    trackId = *(u16 *)((s8 *)track + 0x24);
    if ((trackId != 0) && (*(gTrackMarkerDone + trackId) == 0)) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        slot = (void **) &gBonusObjects + i;
        object = *slot;
        if (object == NULL) {
            continue;
        }
        if (*(u16 *)((s8 *)object + 0x78) == 0x4D) {
            continue;
        }
        if (*(u16 *)((s8 *)object + 0x78) == 0x61) {
            continue;
        }
        if (*(s32 *)((s8 *)object + 0x78) == 0x20000) {
            continue;
        }
        if (*(s32 *)((s8 *)object + 0x20) != *(s32 *)((s8 *)actor + 0x20)) {
            continue;
        }
        if (approxDistance((u8 *) object + 0x24, (u8 *) actor + 0x24) < D_800D4190) {
            if (*(u16 *)((s8 *)track + 0x30) == 0) {
                return func_8005EF84(*slot, actor);
            }
            continue;
        }
        if (*(u16 *)((s8 *)track + 0x30) != 0) {
            *(u16 *)((s8 *)track + 0x30) -= 1;
        }
    }
    return 0;
}
