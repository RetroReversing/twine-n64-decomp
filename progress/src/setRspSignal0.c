s32 removeWorkerEntry(s32);
void removeWorkerEntryByHandle(s32 arg0) { removeWorkerEntry(arg0 & 0xFFFF); }
s32 __osSpSetStatus(s32);
/* Sets RSP status signal 0 (SP_SET_SIG0, 0x400). */ void setRspSignal0(s32 arg0) { __osSpSetStatus(0x400); }
s32 updateControllerInput(void);
extern s16 gUpdatePendingFlag;
void clearFlagAndRunUpdate(void) { gUpdatePendingFlag = 0; updateControllerInput(); }
f64 tanDouble(f64);
f32 tanFloat(f32 arg0) { return (f32)tanDouble((f64)arg0); }
