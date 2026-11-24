extern u16 gUpdatePendingFlag;
u16 getUpdatePendingFlag(void) { return gUpdatePendingFlag; }
s32 offsetToDoubledIndex(s32 arg0) { return (arg0 + 4) * 2; }
extern s32 gViPendingContext;
/* Returns the pending VI context pointer. */ s32 getViPendingContext(void) { return gViPendingContext; }
