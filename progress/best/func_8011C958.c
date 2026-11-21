typedef struct { u8 type; u8 rest[23]; } SlotEnt;
extern SlotEnt sSaveSlotInfo[];
extern s32 sSaveMenuFlagsA; extern s32 gVisibleSaveSlots; extern u8 D_8011EDC0[]; extern void *sSaveSlotMarkers[3][4]; extern s32 gMarkerEntry1,gMarkerEntry2,sMarkerTextNode3;
s32 spawnTextNode(void *); void *spawnTrackMarker(s32); void initObjectFromBankEntry(void *, s32, s32);
void func_8011C958(void) {
    u16 i; u16 j; u8 t; s32 *o;
    gMarkerEntry1 = spawnTextNode(D_8011EDC0);
    gMarkerEntry2 = spawnTextNode(D_8011EDC0 + 0x24);
    sMarkerTextNode3 = spawnTextNode(D_8011EDC0 + 0x48);
    for (i = 0; i < gVisibleSaveSlots; i++) {
        t = sSaveSlotInfo[i].type;
        switch (t) {
        case 1: case 2: case 3: case 5:
            for (j = 0; j < 3; j++) {
                o = spawnTrackMarker(i);
                if (o != 0) {
                    initObjectFromBankEntry(o, 0x13, 0xF4);
                    o[4] = sSaveMenuFlagsA;
                    sSaveSlotMarkers[j][i] = o;
                }
            }
            break;
        default:
            for (j = 0; j < 3; j++) sSaveSlotMarkers[j][i] = 0;
            break;
        }
    }
}
