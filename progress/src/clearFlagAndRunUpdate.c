s32 removeWorkerEntry(s32);
void removeWorkerEntryByHandle(s32 arg0) { removeWorkerEntry(arg0 & 0xFFFF); }
s32 __osSpSetStatus(s32);
void setRspSignal0(void) { __osSpSetStatus(0x400); }
s32 updateControllerInput(void);
extern s16 D_800C9D40;
void clearFlagAndRunUpdate(void) { D_800C9D40 = 0; updateControllerInput(); }
f64 tanDouble(f64);
f32 tanFloat(f32 arg0) { return (f32)tanDouble((f64)arg0); }
