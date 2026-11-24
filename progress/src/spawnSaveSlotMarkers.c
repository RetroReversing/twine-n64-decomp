typedef struct SaveMarkerSlot {
    u8 kind;
    u8 pad[23];
} SaveMarkerSlot;
typedef struct SaveMarker {
    u8 pad[16];
    s32 style;
    u8 pad14[20];
    u32 flags;
} SaveMarker;
extern s32 gVisibleSaveSlotCount;
extern SaveMarkerSlot sSaveSlotTable[];
extern SaveMarkerSlot sSaveSlotInfo[];
extern SaveMarker *sSaveSlotMarkerTable[4][4];
extern u8 gSaveKeyRelaxed;
extern s32 D_800BD678, D_800BD654;
extern s32 getSaveSlotIndex(s32);
extern SaveMarker *spawnTrackMarker(s32);
extern void initObjectFromBankEntry(SaveMarker *, s32, s32);
/* For each visible save slot, spawns up to four marker objects (skipping some per slot state) and stores them in the marker table; clears the row for unsupported slot kinds. */ void spawnSaveSlotMarkers(void)
{
    s32 slotIdx = 0;
    u16 markerIdx;
    s32 kind;
    s32 flag;
    s32 relaxed;
    SaveMarker *markerObj;
    if (gVisibleSaveSlotCount > 0) {
        do {
            flag = sSaveSlotInfo[slotIdx & 0xffff].kind;
            switch (flag) {
            case 1: case 2: case 3: case 5:
                markerIdx = 0;
                break;
            default:
                goto zero_markers;
            }
            kind = flag;
            do {
                if (kind == 2 && gSaveKeyRelaxed == 1) {
                    flag = sSaveSlotTable[getSaveSlotIndex(slotIdx & 0xffff) & 0xffff].kind;
                    if ((!(markerIdx & 1)) ? flag != 1 : flag != 0) { markerIdx++; goto advance_marker; }
                }
type_three:
                if (kind == 3 && (relaxed = gSaveKeyRelaxed) == 1) {
                    flag = sSaveSlotTable[getSaveSlotIndex(slotIdx & 0xffff) & 0xffff].kind;
                    if (markerIdx & 1) {
                        if (flag == 0) { markerIdx++; continue; }
                    } else if (flag == relaxed) { markerIdx++; continue; }
                }
                markerObj = spawnTrackMarker(slotIdx & 0xffff);
                if (markerObj != 0) {
                    u32 n = markerIdx & 0xffff;
                    initObjectFromBankEntry(markerObj, (-(n < 2) & 0x13) | 0x12, 0xf4);
                    markerObj->flags = (markerObj->flags & ~0xfc) | 0x10;
                    if ((n & 1) == 0) {
                        markerObj->style = D_800BD678;
                    } else {
                        markerObj->style = D_800BD654;
                    }
                    sSaveSlotMarkerTable[markerIdx & 0xffff][slotIdx & 0xffff] = markerObj;
                }
                markerIdx++;
advance_marker:
                ;
            } while ((markerIdx & 0xffff) < 4);
            goto next;
zero_markers:
            markerIdx = 0;
clear:
            do {
                sSaveSlotMarkerTable[markerIdx & 0xffff][slotIdx & 0xffff] = 0;
                markerIdx++;
            } while ((markerIdx & 0xffff) < 4);
next:
            slotIdx++;
        } while ((slotIdx & 0xffff) < gVisibleSaveSlotCount);
    }
}
