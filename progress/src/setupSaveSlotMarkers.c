typedef struct { u8 type; u8 rest[23]; } SaveSlotInfo;
extern SaveSlotInfo sSaveSlotInfo[];
extern s32 sSaveMenuFlagsA; extern s32 gVisibleSaveSlots; extern u8 sMarkerTextArgs[]; extern void *sSaveSlotMarkers[3][4]; extern s32 sMarkerTextNode1, sMarkerTextNode2, sMarkerTextNode3;
s32 spawnTextNode(void *); void *spawnTrackMarker(s32); void initObjectFromBankEntry(void *, s32, s32);

/* Builds the three marker text nodes, then gives each marker row a track marker object for visible save slots of types 1, 2, 3 and 5; other slots get none. */
/* Builds the three marker text nodes, then gives each marker row a track marker for visible save slots of types 1, 2, 3 and 5. */ void setupSaveSlotMarkers(void) {
    u16 saveSlot; u16 markerRow; u8 saveType; s32 *trackMarker;
    sMarkerTextNode1 = spawnTextNode(sMarkerTextArgs);
    sMarkerTextNode2 = spawnTextNode(sMarkerTextArgs + 0x24);
    sMarkerTextNode3 = spawnTextNode(sMarkerTextArgs + 0x48);
    for (saveSlot = 0; saveSlot < gVisibleSaveSlots; saveSlot++) {
        saveType = sSaveSlotInfo[saveSlot].type;
        switch (saveType) {
        case 1: case 2: case 3: case 5:
            for (markerRow = 0; markerRow < 3; markerRow++) {
                trackMarker = spawnTrackMarker(saveSlot);
                if (trackMarker != 0) {
                    initObjectFromBankEntry(trackMarker, 0x13, 0xF4);
                    trackMarker[4] = sSaveMenuFlagsA;
                    sSaveSlotMarkers[markerRow][saveSlot] = trackMarker;
                }
            }
            break;
        default:
            for (markerRow = 0; markerRow < 3; markerRow++) sSaveSlotMarkers[markerRow][saveSlot] = 0;
            break;
        }
    }
}
