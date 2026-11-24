extern u8 gMidiBankControllers[][16][0x86];
extern u8 gMidiGlobalControllers[][0x86];

/* Stores a 7-bit controller value for a channel in the given bank's table, or in the global table when bank is 0xFF. */ void voiceStoreParam(u8 param, u8 channel, u8 bank, u8 value) {
    if (bank != 0xFF) {
        gMidiBankControllers[bank][channel][param] = value & 0x7F;
    } else {
        gMidiGlobalControllers[channel][param] = value & 0x7F;
    }
}
