typedef struct VoiceSlotRef {
    u8 pad0[0x4A];
    u8 column;
    u8 row;
    u8 pad4C[0x60 - 0x4C];
    s32 voiceId;
} VoiceSlotRef;

extern char gVoiceSlotTable[];
extern u8 gVoiceIdTable[];

/* Releases the voice's id from its slot table entry (or the id table when it has no row), if it still owns it. */
void voiceClearSlot(VoiceSlotRef *voice) {
    char *slotBase;
    s32 voiceId;
    u8 column, row, idByte, mappedId;
    u8 *slotEntry;

    voiceId = voice->voiceId;
    if ((voiceId != -1) && (column = voice->column, column != 0xFF)) {
        row = voice->row;
        idByte = voiceId;
        if (row == 0xFF) {
            mappedId = gVoiceIdTable[idByte];
            if (mappedId == idByte) {
                gVoiceIdTable[mappedId] = 0xFF;
            }
            return;
        }
        slotBase = gVoiceSlotTable;
        slotEntry = (u8 *)((row * 0x10) + slotBase + column);
        if (*slotEntry == idByte) {
            *slotEntry = 0xFF;
        }
    }
}
