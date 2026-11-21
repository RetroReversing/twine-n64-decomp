s32 actorSteerTowardTarget(s32, s32, void *, s32);
extern s32 gVisibleSaveSlotCount;
extern s32 sBonusObjectTable;
extern s32 sSteerOriginTable;
extern u8 sProbeOriginTable[];
extern s32 sSaveSlotMarkerTable;

/* Steers each marker actor of every visible save slot toward that slot's bonus object. */
void steerSaveSlotActors(void) {
    register s32 slot;
    s32 slotOffset;
    u32 var_v1;
    s32 markerActor;

    slot = 0;
    if (0 < gVisibleSaveSlotCount) {
        do {
            slotOffset = (slot & 0xFFFF) * 4;
{
    u16 row;
    for (row = 0; row < 4; row++) {
        { char *q = (row * 0x10) + (char *)&sSaveSlotMarkerTable; markerActor = *(s32 *)(slotOffset + (s32)q); }
        if (markerActor != 0) {
        actorSteerTowardTarget(markerActor, (&sBonusObjectTable)[slot & 0xFFFF], (2U > row) ? (void *) ((&sSteerOriginTable)[row]) : (void *) ((row * 0xC) + sProbeOriginTable), slot & 0xFFFF);
        }
    }
}
            ++slot;
        } while ((slot & 0xFFFF) < gVisibleSaveSlotCount);
    }
}
