s32 func_80082164();
extern char sBonusSlots[];
extern char D_80115091[];
extern char D_80115092[];
extern char D_80115094[];
extern char D_80115095[];

/* Stores a new state for bonus slot `slot` (records are 0xA0 bytes). On a change, sets the slot's
 * active flag from the state and clears the 0x3A two-byte entries that follow it; then records the state. */
void setBonusSlotState(s32 slot, s32 state, s32 arg2) {
    long offset;
    s32 counter;

    counter = arg2;
    offset = slot * 0xA0;
    if (*(s16 *)(D_80115092 + offset) != state) {
        *(s16 *)(D_80115092 + offset) = state;
        switch (state) {
        case 6:
        case 7:
        default:
            *(sBonusSlots + (slot * 0xA0)) = 0;
            counter = 0;
            break;
        case 0:
        case 1:
        case 4:
        case 5:
            *(sBonusSlots + (slot * 0xA0)) = 1;
            counter = 0;
            break;
        }
        offset = slot * 0xA0;
        do {
            counter += 1;
            *(D_80115095 + offset) = 0;
            *(D_80115094 + offset) = *(D_80115094 + offset) & 0x1D;
            offset += 2;
        } while (0x3A > counter);
    }
    *(D_80115091 + (slot * 0xA0)) = (s8) state;
    func_80082164(slot);
}
