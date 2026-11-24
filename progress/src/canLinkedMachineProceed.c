/* Returns 0 if the linked state machine (obj+0x1C) is in state 0xB and its type-specific sub-state is still busy; otherwise 1. */ s32 canLinkedMachineProceed(u8 *obj) {
    u8 *linked;
    u8 *data;

    if (*(u8 **)(obj + 0x1C) != NULL) {
        linked = *(u8 **)(obj + 0x1C);
        if (*(u16 *)(linked + 0x78) != 0xB) {
            return 1;
        }
        data = *(u8 **)(linked + 0x6C);
        switch (data[0x4A]) {
        case 4:
        case 5:
            if (*(u16 *)(data + 0x34) != 0 && *(s16 *)(linked + 0x7A) != 4) {
                return 0;
            }
            break;
        case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:
            break;
        case 16:
        case 17:
            if (*(u16 *)(data + 0x34) != 0 && *(s16 *)(linked + 0x7A) != 0) {
                return 0;
            }
            break;
        }
    }
    return 1;
}
