extern u16 gUpdatePendingFlag;
u16 getUpdatePendingFlag(void) { return gUpdatePendingFlag; }
/* Returns (index + 4) * 2, converting an index to a doubled offset. */ s32 offsetToDoubledIndex(s32 index) { return (index + 4) * 2; }
extern s32 gViPendingContext;
s32 getViPendingContext(void) { return gViPendingContext; }
