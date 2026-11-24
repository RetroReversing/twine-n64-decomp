extern s32 evalMidiModulatorChain(s32, s32);
extern f64 libmAtan2(f64, f64);
extern void registerWorkerEntry(s32, void *, s32);
extern void (*gDataBankFree)(void);
/* Evaluates the MIDI modulator chain stored at offset 340 of the voice; returns the low 16 bits. */
s32 evalVoiceModulator(s32 voice) { return evalMidiModulatorChain(voice, voice + 340) & 0xffff; }
f32 atan2f32(f32 x, f32 y) { return libmAtan2(x, y); }
void registerWorkerFromRecord(s32 x, u16 *p) { registerWorkerEntry(x & 0xffff, p + 2, *p); }
void callDataBankFreeHandler(void) { gDataBankFree(); }
