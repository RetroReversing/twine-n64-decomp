/* identical to getAudioControlValue (matched), with its names changed by decompdecomp */
extern u8 gVoiceSlotDefault[];
extern u8 gAudioBankSlots[][16];
/* Looks up a voice's slot: from the default table if group is 0xFF, else from the group's table. */ u8 voiceLookupSlot(u8 voice, u8 group) {
    u8 slot;
    if (group == 0xFF) {
        slot = gVoiceSlotDefault[voice];
    } else {
        slot = gAudioBankSlots[group][voice];
    }
    return slot;
}
