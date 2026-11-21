extern s32 gVisibleSaveSlotCount, sSaveMenuFlagsA;
extern u8 sSaveSlotInfo[];
extern u8 sMarkerTextArgs[][36];
extern void *sMarkerTextNode1, *sMarkerTextNode2, *sMarkerTextNode3;
typedef struct {u8 pad[16]; s32 flags;} SaveMarker;
extern SaveMarker *sSaveSlotMarkerTable[][4];
void *spawnTextNode(void *);
s32 spawnTrackMarker(s32);
void initObjectFromBankEntry(void *, s32, s32);

/* Spawns the three save-menu text nodes, then fills or clears the marker table for each visible save slot. */
void setupSaveSlotMarkers(void) {
    s32 slotIndex, markerRow, specialState;
    sMarkerTextNode1 = spawnTextNode(sMarkerTextArgs[0]);
    sMarkerTextNode2 = spawnTextNode(sMarkerTextArgs[1]);
    sMarkerTextNode3 = spawnTextNode(sMarkerTextArgs[2]);
    if (gVisibleSaveSlotCount > 0) {
        slotIndex = 0;
        specialState = 5;
        do {
            s32 slotColumn = (u16)slotIndex;
            s32 slotState = sSaveSlotInfo[(slotColumn * 3) << 3];
            if (slotState != 0) {
                if (slotState < 4) {
                    markerRow = 0;
                    goto fill;
                }
                if (slotState != specialState) {
                    markerRow = 0;
                    goto clear;
                }
                markerRow = 0;
fill:
                {
                    s32 markerColumn = slotColumn;
                    do {
                        SaveMarker *marker = (SaveMarker *)spawnTrackMarker(markerColumn);
                        if (marker) {
                            do { initObjectFromBankEntry(marker, 0x13, 0xF4); } while (0);
                            marker->flags = sSaveMenuFlagsA;
                            sSaveSlotMarkerTable[(u16)markerRow][markerColumn] = marker;
                        }
                        markerRow++;
                    } while ((u16)markerRow < 3U);
                    goto next;
                }
            }
            markerRow = 0;
clear:
            do {
                sSaveSlotMarkerTable[(u16)markerRow][(u16)slotIndex] = NULL;
                markerRow++;
            } while ((u16)markerRow < 3U);
next:
            slotIndex++;
        } while ((u16)slotIndex < gVisibleSaveSlotCount);
    }
}
