extern u16 gUpdatePendingFlag;
/* Returns whether an update is pending. */
u16 getUpdatePendingFlag(void) { return gUpdatePendingFlag; }
s32 offsetToDoubledIndex(s32 base) { return (base + 4) * 2; }
extern s32 gViPendingContext;
s32 getViPendingContext(void) { return gViPendingContext; }
