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
void func_8011CC3C(void)
{
    s32 slot = 0;
    u16 marker;
    s32 kind;
    s32 flag;
    s32 relaxed;
    SaveMarker *obj;
    if (gVisibleSaveSlotCount > 0) {
        do {
            flag = sSaveSlotInfo[slot & 0xffff].kind;
            switch (flag) {
            case 1: case 2: case 3: case 5:
                marker = 0;
                break;
            default:
                goto zero_markers;
            }
            kind = flag;
            do {
                if (kind == 2 && gSaveKeyRelaxed == 1) {
                    flag = sSaveSlotTable[getSaveSlotIndex(slot & 0xffff) & 0xffff].kind;
                    if ((!(marker & 1)) ? flag != 1 : flag != 0) { marker++; goto advance_marker; }
                }
type_three:
                if (kind == 3 && (relaxed = gSaveKeyRelaxed) == 1) {
                    flag = sSaveSlotTable[getSaveSlotIndex(slot & 0xffff) & 0xffff].kind;
                    if (marker & 1) {
                        if (flag == 0) { marker++; continue; }
                    } else if (flag == relaxed) { marker++; continue; }
                }
                obj = spawnTrackMarker(slot & 0xffff);
                if (obj != 0) {
                    u32 n = marker & 0xffff;
                    initObjectFromBankEntry(obj, (-(n < 2) & 0x13) | 0x12, 0xf4);
                    obj->flags = (obj->flags & ~0xfc) | 0x10;
                    if ((n & 1) == 0) {
                        obj->style = D_800BD678;
                    } else {
                        obj->style = D_800BD654;
                    }
                    sSaveSlotMarkerTable[marker & 0xffff][slot & 0xffff] = obj;
                }
                marker++;
advance_marker:
                ;
            } while ((marker & 0xffff) < 4);
            goto next;
zero_markers:
            marker = 0;
clear:
            do {
                sSaveSlotMarkerTable[marker & 0xffff][slot & 0xffff] = 0;
                marker++;
            } while ((marker & 0xffff) < 4);
next:
            slot++;
        } while ((slot & 0xffff) < gVisibleSaveSlotCount);
    }
}
