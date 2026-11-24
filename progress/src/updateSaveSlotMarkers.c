extern s32 gVisibleSaveSlotCount;
extern TrackMarker *sBonusObjectTable[4];
typedef struct {
    u8 pad[0x20];
    u16 x, y;
} SaveSlotMarker;
extern SaveSlotMarker *sSaveSlotMarkerTable[];
extern u8 D_8011F108[];
void actorSteerTowardTarget(void *, void *, void *, s32);

/* Steers each visible save-slot marker toward its triggered bonus object and nudges it by (-4,-4). */ void updateSaveSlotMarkers(void) {
    s32 slot = 0;
    if (gVisibleSaveSlotCount > 0) {
        do {
            TrackMarker *bonusObject = sBonusObjectTable[(u16)slot];
            if (bonusObject && bonusObject->trigger) {
                SaveSlotMarker *marker = sSaveSlotMarkerTable[(u16)slot];
                if (marker) {
                    actorSteerTowardTarget(marker, bonusObject, D_8011F108, (u16)slot);
                    marker->x -= 4;
                    marker->y -= 4;
                }
            }
            slot++;
        } while ((u16)slot < gVisibleSaveSlotCount);
    }
}
