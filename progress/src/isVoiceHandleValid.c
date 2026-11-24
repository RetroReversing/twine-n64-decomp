extern char gVoiceSlotTable[];
extern u8 gVoiceIdTable[];
inline static int inline_fn(s32 arg0, u8 arg1) { return (arg0 & 0xFF) == arg1; }
/* Returns 1 if the voice's handle id still matches the id stored in the slot/id tables, else 0. */
s32 isVoiceHandleValid(u8 *voice) {
 s32 handleId = *((s32 *) (voice + 0x60)); u8 idByte; u8 slot; u8 bank; u8 stored;
 if (handleId != (-1)) { slot = voice[0x4A]; if (slot != 0xFF) { bank = voice[0x4B]; idByte = handleId;
 if (bank == 0xFF) { stored = gVoiceIdTable[idByte & 0xFF]; 
if (!inline_fn(idByte, stored)) goto __repair_compare_no;
}
 else { char *base = gVoiceSlotTable; stored = *((base + (bank * 16)) + slot); 
if (!inline_fn(stored, idByte)) goto __repair_compare_no;
}
return 1; __repair_compare_no:; } } return 0;
}
