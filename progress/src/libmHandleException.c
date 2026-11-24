extern u16 gDataEntryTableId;
extern u8 gWorkerThreadActive;
extern s8 gStartupFlag;
/* Libm exception handler stub; always returns 0 (not handled). */ s32 libmHandleException(void) { return 0; }
u16 getDataEntryTableId(void) { return gDataEntryTableId; }
u8 isWorkerThreadActive(void) { return gWorkerThreadActive; }
void setStartupFlag(void) { gStartupFlag = 1; }
