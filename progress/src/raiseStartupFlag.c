s32 osWritebackDCache();
void writebackDCacheHalfwords(s32 a, s32 b) { osWritebackDCache(a,b*2); }
s32 setStartupFlag();
/* Sets the startup flag during boot, after the VI is blanked. */ void raiseStartupFlag(void) { setStartupFlag(); }
s32 rspSetPcIfHalted(s32);
void resetRspProgramCounter(void) { rspSetPcIfHalted(0); }
f64 libmAcos(f64);
f32 acosf(f32 a) { return (f32)libmAcos((f64)a); }
