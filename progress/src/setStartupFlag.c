extern u16 gDataEntryTableId;
extern u8 gWorkerThreadActive;
extern s8 gStartupFlag;
s32 libmHandleException(void) { return 0; }
u16 getDataEntryTableId(void) { return gDataEntryTableId; }
u8 isWorkerThreadActive(void) { return gWorkerThreadActive; }
/* Sets the startup flag to 1. */ void setStartupFlag(void) { gStartupFlag = 1; }
