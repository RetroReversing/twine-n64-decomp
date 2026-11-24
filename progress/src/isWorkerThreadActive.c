extern u16 gDataEntryTableId;
extern u8 gWorkerThreadActive;
extern s8 gStartupFlag;
s32 libmHandleException(void) { return 0; }
u16 getDataEntryTableId(void) { return gDataEntryTableId; }
/* Returns nonzero while the sound worker thread is active. */ u8 isWorkerThreadActive(void) { return gWorkerThreadActive; }
void setStartupFlag(void) { gStartupFlag = 1; }
