extern s32 gVisibleSaveSlotCount;
extern TrackMarker *sBonusObjectTable[4];
typedef struct {
    u8 pad[0x20];
    u16 x, y;
} SaveSlotMarker;
extern SaveSlotMarker *sSaveSlotMarkerTable[];
extern u8 D_8011F108[];
void actorSteerTowardTarget(void *, void *, void *, s32);

void updateSaveSlotMarkers(void) {
    s32 i = 0;
    if (gVisibleSaveSlotCount > 0) {
        do {
            TrackMarker *target = sBonusObjectTable[(u16)i];
            if (target && target->trigger) {
                SaveSlotMarker *marker = sSaveSlotMarkerTable[(u16)i];
                if (marker) {
                    actorSteerTowardTarget(marker, target, D_8011F108, (u16)i);
                    marker->x -= 4;
                    marker->y -= 4;
                }
            }
            i++;
        } while ((u16)i < gVisibleSaveSlotCount);
    }
}
