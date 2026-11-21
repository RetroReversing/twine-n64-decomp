extern void initObjectFromBankEntry(void *, s32, s32);
extern s32 spawnTextNode(void *);
extern s32 spawnTrackMarker(s32);
extern s32 gVisibleSaveSlotCount, sSaveMenuColorActive;
extern u8 sMarkerTextArgs[], sSaveSlotInfo[];
extern s32 sMarkerTextNode1, sMarkerTextNode2, sMarkerTextNode3;
extern u8 sSaveSlotMarkerTable[];

void setupSaveSlotMarkers(void) {
    s32 slot, idx, marker, clearSlot, clearMarker, object;
    s32 state;
    u8 *table;
    sMarkerTextNode1 = spawnTextNode(sMarkerTextArgs);
    sMarkerTextNode2 = spawnTextNode(sMarkerTextArgs + 0x24);
    sMarkerTextNode3 = spawnTextNode(sMarkerTextArgs + 0x48);
    slot = 0;
    if (gVisibleSaveSlotCount <= 0)
        return;
    table = sSaveSlotMarkerTable;
    do {
        idx = (u16)slot;
        state = ((u8 (*)[24])sSaveSlotInfo)[idx][0];
        if (state != 0) {
            marker = 0;
            if (state >= 4) {
                clearSlot = (u16)slot;
                if (state == 5) {
                    marker = 0;
                    goto spawn;
                }
                goto clear;
            }
        spawn:
            clearMarker = idx * 4;
        again:
            object = spawnTrackMarker((u16)slot);
            if (object != 0) {
                initObjectFromBankEntry((void *)object, 0x13, 0xF4);
                *(s32 *)((u8 *)object + 0x10) = sSaveMenuColorActive;
                *(s32 *)(clearMarker + (table + (u16)marker * 16)) = object;
            }
            marker++;
            if ((u16)marker < 3U)
                goto again;
        } else {
            marker = 0;
            clearSlot = (u16)slot;
        clear:
            clearMarker = (u16)marker;
            do {
                *(s32 *)(clearSlot * 4 + (table + clearMarker * 16)) = 0;
                marker++;
                clearMarker = (u16)marker;
            } while ((u16)marker < 3U);
        }
        slot++;
    } while ((s32)(u16)slot < gVisibleSaveSlotCount);
}
