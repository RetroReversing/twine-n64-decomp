extern s32 evalMidiModulatorChain(s32, s32);
extern f64 libmAtan2(f64, f64);
extern void registerWorkerEntry(s32, void *, s32);
extern void (*gDataBankFree)(void);
s32 evalVoiceModulator(s32 x) { return evalMidiModulatorChain(x, x + 340) & 0xffff; }
f32 atan2f32(f32 x, f32 y) { return libmAtan2(x, y); }
void registerWorkerFromRecord(s32 x, u16 *p) { registerWorkerEntry(x & 0xffff, p + 2, *p); }
/* Invokes the data bank free handler stored in gDataBankFree. */ void callDataBankFreeHandler(void) { gDataBankFree(); }
