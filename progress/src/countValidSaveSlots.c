extern u16 gSaveSlotFlags[];
extern u16 gSaveSlotAltFlags[];
extern u16 gSaveSlotValid[];

/* Counts save slots (of 4) set in the table selected by listType; for 0xA3 it stops at the first unset slot. */ u16 countValidSaveSlots(u16 listType) {
    u16 count = 0;
    u16 slot;

    slot = count;
    while (slot < 4) {
        break;
    }
    for (slot = count; slot < 4; slot++) {
        switch (listType) {
        case 0xA5:
            if (gSaveSlotValid[slot] != 0) {
                count++;
            }
            break;
        case 0xA6:
            if (gSaveSlotAltFlags[slot] != 0) {
                count++;
            }
            break;
        case 0xA3:
            if (gSaveSlotFlags[slot] != 0) {
                count++;
            } else {
                slot = 5;
            }
            break;
        }
    }
    return count;
}
