#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
extern char gMidiBankControllers[];
extern char gMidiGlobalControllers[];

/* Returns the 14-bit value (MSB<<7 | LSB) of a MIDI controller for a channel, from a bank's controller table or the global one when bankIdx is 0xFF. */
u16 getMidiControllerValue(s32 controller, s32 channel, s32 bankIdx) {
    s32 bankSel;
    s32 msb;
    u32 ctrl;
    u8 *var_v0;
    u8 *var_v0_2;
    u8 *var_v0b;
    u32 var_t;
    u32 lsb;
    void *temp_v1;
    void *temp_v1_2;
    void *var_v1_2;
    void *var_a2;
    void *var_a3;
    void *var_b2;
    void *tmp_a2;
    void *tmp_a3;
    void *tmp_b2;
    u8 cmd;
    u32 tb;
    u32 temp_a2_2;

    cmd = controller;
    bankSel = bankIdx & 0xFF;
    if (bankSel != 0xFF) {
        ctrl = cmd & 0xFF;
        if (ctrl < 0x40U) {
            { u8 *bp = gMidiBankControllers; u8 *bank; do { bank = bp + bankSel * 0x860; } while (0); temp_v1 = (u8 *)((channel & 0xFF) * 0x86) + (s32)bank + (controller & 0x1F); }
            lsb = M2C_FIELD(temp_v1, u8 *, 0x20);
            msb = M2C_FIELD(temp_v1, u8 *, 0) << 7;
            goto block_19;
        }
        if ((u32) ((controller + 0x80) & 0xFF) < 2U) {
            { u8 *bp = gMidiBankControllers; u8 *bank; do { bank = bp + bankSel * 0x860; } while (0); var_v1_2 = (u8 *)((channel & 0xFF) * 0x86) + (s32)bank; }
            do { temp_v1 = var_v1_2 + (controller & 0xFE); } while (0);
            msb = M2C_FIELD(temp_v1, u8 *, 0);
            lsb = M2C_FIELD(temp_v1, u8 *, 1);
            msb = msb << 7;
            goto block_19;
        }
        if ((u32) ((controller + 0x7C) & 0xFF) < 2U) {
            { u8 *bp = gMidiBankControllers; u8 *bank; do { bank = bp + bankSel * 0x860; } while (0); var_v1_2 = (u8 *)((channel & 0xFF) * 0x86) + (s32)bank; }
            do { temp_v1 = var_v1_2 + (controller & 0xFE); } while (0);
            msb = M2C_FIELD(temp_v1, u8 *, 0);
            lsb = M2C_FIELD(temp_v1, u8 *, 1);
            msb = msb << 7;
            goto block_19;
        }
        if (ctrl < 0x46U) {
            { u8 *bp = gMidiBankControllers; u8 *bank = bp + bankSel * 0x860; var_v0_2 = (u8 *)((channel & 0xFF) * 0x86) + (s32)bank + ctrl; }
            goto block_22;
        }
        if ((u32) ((controller - 0x60) & 0xFF) < 6U) {
            return 0;
        }
            { u8 *bp = gMidiBankControllers; u8 *bank = bp + bankSel * 0x860; var_v0 = (u8 *)((channel & 0xFF) * 0x86) + (s32)bank + ctrl; }
        return *var_v0 << 7;
    }
    bankSel = cmd & 0xFF;
    if (bankSel < 0x40U) {
        { u8 *bp = gMidiGlobalControllers; u32 bb; u8 *sm; bb = (channel & 0xFF); sm = bp + bb * 0x86; do { temp_v1_2 = sm + (controller & 0x1F); } while (0); }
        msb = M2C_FIELD(temp_v1_2, u8 *, 0) << 7;
        lsb = M2C_FIELD(temp_v1_2, u8 *, 0x20);
        goto block_19;
    }
    if (((u32) ((controller + 0x80) & 0xFF) < 2U) || (((u32) ((controller + 0x7C) & 0xFF) < 2U) != 0)) {
        { u32 bb; u8 *bp; do { bb = (channel & 0xFF); } while (0); bp = gMidiGlobalControllers; var_b2 = bp + bb * 0x86; }
block_18:
        do { tmp_b2 = var_b2 + (controller & 0xFE); } while (0);
        msb = M2C_FIELD(tmp_b2, u8 *, 0);
        lsb = M2C_FIELD(tmp_b2, u8 *, 1);
        msb = msb << 7;
block_19:
        return lsb | msb;
    }
    if (bankSel < 0x46U) {
        { u8 *bp = gMidiGlobalControllers; u32 bb; do { bb = (channel & 0xFF); } while (0); var_v0_2 = bp + bb * 0x86 + bankSel; }
block_22:
        return -((u8) *var_v0_2 >= 0x40U) & 0x3FFF;
    }
    if ((u32) ((controller - 0x60) & 0xFF) < 6U) {
        return 0;
    }
        { u32 bb; u8 *bp; bb = (channel & 0xFF); bp = gMidiGlobalControllers; var_v0b = bp + bb * 0x86 + bankSel; }
    return *var_v0b << 7;
}
