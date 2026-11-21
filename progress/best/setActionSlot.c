typedef struct { s16 index; u8 pad[14]; } ActionRecord706;
extern ActionRecord706 gPhaseSlotIds[];
s32 setActionSlot(u8 *object, u8 action, s32 value) {
    u8 frame[16];
    s16 i;
    s16 index;
    u8 id;
    if (object != 0) {
        id = action;
        if (((u8)(action - 23) < 2) | (id == 25)) {
            return 0;
        }
        i = 1;
        do {
            if (object[0x139 + i * 2] == id) {
                goto found;
            }
            i++;
        } while (i < 30);
        index = gPhaseSlotIds[action].index;
        if (index != -1) {
            object[0x1fc + index * 8] = 1;
        }
        if (action < 31) {
            *(u16 *)(object + 0x138 + action * 2) = action | (value << 8);
found:
            return 1;
        }
    }
    return 0;
}
