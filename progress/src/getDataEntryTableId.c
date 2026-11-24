extern u16 gDataEntryTableId;
extern u8 gWorkerThreadActive;
extern s8 gStartupFlag;
s32 libmHandleException(void) { return 0; }
/* Returns the current data entry table id. */ u16 getDataEntryTableId(void) { return gDataEntryTableId; }
u8 isWorkerThreadActive(void) { return gWorkerThreadActive; }
void setStartupFlag(void) { gStartupFlag = 1; }
