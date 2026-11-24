s32 osWritebackDCache();
/* Writes back the data cache for a buffer sized in 16-bit units (byte length = count * 2). */ void writebackDCacheHalfwords(s32 a, s32 b) { osWritebackDCache(a,b*2); }
s32 setStartupFlag();
void raiseStartupFlag(void) { setStartupFlag(); }
s32 rspSetPcIfHalted(s32);
void resetRspProgramCounter(void) { rspSetPcIfHalted(0); }
f64 libmAcos(f64);
f32 acosf(f32 a) { return (f32)libmAcos((f64)a); }
