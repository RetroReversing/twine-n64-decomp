typedef struct { u8 type; u8 rest[23]; } SaveSlotInfo;
extern SaveSlotInfo sSaveSlotInfo[];
extern s32 sSaveMenuFlagsA; extern s32 gVisibleSaveSlots; extern u8 sMarkerTextArgs[]; extern void *sSaveSlotMarkers[3][4]; extern s32 sMarkerTextNode1, sMarkerTextNode2, sMarkerTextNode3;
s32 spawnTextNode(void *); void *spawnTrackMarker(s32); void initObjectFromBankEntry(void *, s32, s32);

/* Builds the three marker text nodes, then gives each marker row a track marker object for visible save slots of types 1, 2, 3 and 5; other slots get none. */
void setupSaveSlotMarkers(void) {
    u16 slot; u16 row; u8 slotType; s32 *marker;
    sMarkerTextNode1 = spawnTextNode(sMarkerTextArgs);
    sMarkerTextNode2 = spawnTextNode(sMarkerTextArgs + 0x24);
    sMarkerTextNode3 = spawnTextNode(sMarkerTextArgs + 0x48);
    for (slot = 0; slot < gVisibleSaveSlots; slot++) {
        slotType = sSaveSlotInfo[slot].type;
        switch (slotType) {
        case 1: case 2: case 3: case 5:
            for (row = 0; row < 3; row++) {
                marker = spawnTrackMarker(slot);
                if (marker != 0) {
                    initObjectFromBankEntry(marker, 0x13, 0xF4);
                    marker[4] = sSaveMenuFlagsA;
                    sSaveSlotMarkers[row][slot] = marker;
                }
            }
            break;
        default:
            for (row = 0; row < 3; row++) sSaveSlotMarkers[row][slot] = 0;
            break;
        }
    }
}
