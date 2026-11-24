typedef struct { u16 id; u8 pad[0x26]; } Ent263B8;
typedef struct { Ent263B8 *arr; u8 pad4; u8 count; } Tbl263B8;
typedef struct { u8 pad[16]; Tbl263B8 *table; } Root;
typedef struct { u8 pad[0x29]; u8 value; } Voice;
typedef struct { u8 pad[8]; Voice *voice; u8 padC[8]; u32 count; } Entry;
typedef struct { u8 pad[12]; f32 factor; } Scale;
extern Root *gSaveMenuState;
s32 findEntryById(Tbl263B8 *, u16);
/* Sets the voice value of entry id 4 to factor*count+1, clamped to the entry's count. */ void scaleVoiceValueByFactor(Scale *scaleInfo) {
    Entry *entry = (Entry *)findEntryById(gSaveMenuState->table, 4);
    if (entry) {
        Voice *voice = entry->voice;
        if ((voice != 0) & (scaleInfo != 0)) {
            voice->value = (u32)(scaleInfo->factor * (f32)entry->count) + 1;
            if (entry->count < entry->voice->value) {
                entry->voice->value = entry->count;
            }
        }
    }
}
