#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s16 findEntryIndexById();
s32 *lookupDataEntry();
s32 sprintf();
extern s32 gEntryTable;
extern char D_800E1610[];

extern char D_800D2DD0[];

/* Builds the track marker label "<name> <letter> <text>" into a shared buffer and returns it; index 0 or 1 uses the raw index, others are looked up first */
s32 *formatTrackMarkerLabel(s16 markerIndex, s32 mode) {
    s32 *nameText;
    s16 entryIndex;
    s32 textId;
    s32 temp_a1;
    s32 temp_v1;
    s32 var_s0;

    temp_a1 = mode & 0xFFFF;
    if (temp_a1 == 1) {
        entryIndex = findEntryIndexById(markerIndex);
    } else {
        entryIndex = markerIndex - 1;
    }
    if (entryIndex < 0) {
        return lookupDataEntry(3);
    }
    temp_v1 = M2C_FIELD(((entryIndex * 8) + gEntryTable), u16 *, 2) & 0xF;
    if (temp_v1 == 1) {
        var_s0 = 0xA0;
    } else {
        var_s0 = (-(temp_v1 == 2) & 0x9F) | 0x9E;
    }
    nameText = lookupDataEntry(0xA4);
    sprintf(D_800E1610, D_800D2DD0, nameText, (s8) (M2C_FIELD((((s32) (entryIndex << 0x10) >> 0xD) + gEntryTable), u8 *, 1) + 0x41), lookupDataEntry(var_s0));
    return D_800E1610;
}
