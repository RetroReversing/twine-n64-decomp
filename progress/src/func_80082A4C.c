extern s32 func_80096A70(s32, s32);
extern f64 func_800AA8B0(f64, f64);
extern void registerWorkerEntry(s32, void *, s32);
extern void (*gDataBankFree)(void);
s32 func_80096DFC(s32 x) { return func_80096A70(x, x + 340) & 0xffff; }
f32 func_80082A4C(f32 x, f32 y) { return func_800AA8B0(x, y); }
void func_80092A28(s32 x, u16 *p) { registerWorkerEntry(x & 0xffff, p + 2, *p); }
void stream_call_prev_handler(void) { gDataBankFree(); }
