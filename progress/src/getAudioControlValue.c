extern u8 gClipSlotDefaultBank[];
extern u8 gClipSlotBanks[][16];
/* Returns a clip slot's value from the default bank (bank 0xFF) or from the given bank. */ u8 getAudioControlValue(u8 slot, u8 bank) {
    u8 value;
    if (bank == 0xFF) {
        value = gClipSlotDefaultBank[slot];
    } else {
        value = gClipSlotBanks[bank][slot];
    }
    return value;
}
