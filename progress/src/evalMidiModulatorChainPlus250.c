/* adapted from similar verified C in evalVoiceModulator in TWINE (matched), with its names changed by decompdecomp */
extern s32 evalMidiModulatorChain(s32, s32);
extern f64 libmAtan2(f64, f64);
extern void registerWorkerEntry(s32, void *, s32);
extern void (*gDataBankFree)(void);
/* Evaluates the MIDI modulator chain for x and x + 250, returning a 16-bit result. */ s32 evalMidiModulatorChainPlus250(s32 x) { return evalMidiModulatorChain(x, x + 250) & 0xffff; }
f32 atan2f32(f32 x, f32 y) { return libmAtan2(x, y); }
void registerWorkerFromRecord(s32 x, u16 *p) { registerWorkerEntry(x & 0xffff, p + 2, *p); }
void callDataBankFreeHandler(void) { gDataBankFree(); }
