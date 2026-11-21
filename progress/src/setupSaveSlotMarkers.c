extern s32 gVisibleSaveSlotCount, sSaveMenuFlagsA;
extern u8 sSaveSlotInfo[];
extern u8 sMarkerTextArgs[][36];
extern void *sMarkerTextNode1, *sMarkerTextNode2, *sMarkerTextNode3;
typedef struct {u8 pad[16]; s32 flags;} SaveMarker;
extern SaveMarker *sSaveSlotMarkerTable[][4];
void *spawnTextNode(void *);
s32 spawnTrackMarker(s32);
void initObjectFromBankEntry(void *, s32, s32);

void setupSaveSlotMarkers(void) {
    s32 i, j, special;
    sMarkerTextNode1 = spawnTextNode(sMarkerTextArgs[0]);
    sMarkerTextNode2 = spawnTextNode(sMarkerTextArgs[1]);
    sMarkerTextNode3 = spawnTextNode(sMarkerTextArgs[2]);
    if (gVisibleSaveSlotCount > 0) {
        i = 0;
        special = 5;
        do {
            s32 slot = (u16)i;
            s32 state = sSaveSlotInfo[(slot * 3) << 3];
            if (state != 0) {
                if (state < 4) {
                    j = 0;
                    goto fill;
                }
                if (state != special) {
                    j = 0;
                    goto clear;
                }
                j = 0;
fill:
                {
                    s32 markerSlot = slot;
                    do {
                        SaveMarker *marker = (SaveMarker *)spawnTrackMarker(markerSlot);
                        if (marker) {
                            do { initObjectFromBankEntry(marker, 0x13, 0xF4); } while (0);
                            marker->flags = sSaveMenuFlagsA;
                            sSaveSlotMarkerTable[(u16)j][markerSlot] = marker;
                        }
                        j++;
                    } while ((u16)j < 3U);
                    goto next;
                }
            }
            j = 0;
clear:
            do {
                sSaveSlotMarkerTable[(u16)j][(u16)i] = NULL;
                j++;
            } while ((u16)j < 3U);
next:
            i++;
        } while ((u16)i < gVisibleSaveSlotCount);
    }
}
