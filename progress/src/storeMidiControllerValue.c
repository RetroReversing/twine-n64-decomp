extern u8 gMidiBankControllers[][16][0x86];
extern u8 gMidiGlobalControllers[][0x86];
inline static void St(u8 i, u8 r, u8 b, u8 v) {
    if (b != 0xFF) { gMidiBankControllers[b][r][i] = v & 0x7F; } else { gMidiGlobalControllers[r][i] = v & 0x7F; }
}

/* Stores a 14-bit controller value as MSB/LSB 7-bit halves for a channel in a bank (0xFF = global table). */ void storeMidiControllerValue(u8 controller, u8 channel, u8 bank, u16 value) {
    if (controller < 0x40) {
        St(controller & 0x1F, channel, bank, value >> 7);
        St((controller & 0x1F) | 0x20, channel, bank, value & 0x7F);
    } else if ((u8)(controller + 128) < 2) {
        St(controller & 0xFE, channel, bank, value >> 7);
        St(controller | 1, channel, bank, value & 0x7F);
    } else if ((u8)(controller + 124) < 2) {
        St(controller & 0xFE, channel, bank, value >> 7);
        St(controller | 1, channel, bank, value & 0x7F);
    } else {
        St(controller, channel, bank, value >> 7);
    }
}
