s32 osWritebackDCache();
void writebackDCacheHalfwords(s32 a, s32 b) { osWritebackDCache(a,b*2); }
s32 setStartupFlag();
void raiseStartupFlag(void) { setStartupFlag(); }
s32 rspSetPcIfHalted(s32);
/* Sets the RSP program counter to 0 if the RSP is halted. */ s32 resetRspProgramCounter(void) { return rspSetPcIfHalted(0); }
f64 libmAcos(f64);
f32 acosf(f32 a) { return (f32)libmAcos((f64)a); }
