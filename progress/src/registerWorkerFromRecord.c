extern s32 evalMidiModulatorChain(s32, s32);
extern f64 libmAtan2(f64, f64);
extern void registerWorkerEntry(s32, void *, s32);
extern void (*gDataBankFree)(void);
s32 evalVoiceModulator(s32 x) { return evalMidiModulatorChain(x, x + 340) & 0xffff; }
f32 atan2f32(f32 x, f32 y) { return libmAtan2(x, y); }
/* Registers a worker entry using a record whose first halfword is a size/count and payload starts at +4. */
void registerWorkerFromRecord(s32 id, u16 *record) { registerWorkerEntry(id & 0xffff, record + 2, *record); }
void stream_call_prev_handler(void) { gDataBankFree(); }
