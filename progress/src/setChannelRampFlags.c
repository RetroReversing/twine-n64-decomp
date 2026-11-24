s32 workerLockAcquire();                            /* extern */
s32 workerLockRelease();                            /* extern */
s32 setSoundChannelRamp(s32, s32, s32, s32, s32); /* extern */
extern u8 gWorkerThreadActive;

/* Under the worker lock, sets sound channel ramp parameters 0x15 and/or 0x16 to 0 for the given channel and id, as selected by the two flags. */
void setChannelRampFlags(s32 channel, s32 id, s32 setParam15, s32 setParam16) {
    if (gWorkerThreadActive != 0) {
        workerLockAcquire();
        if (setParam15 & 0xFF) {
            setSoundChannelRamp(channel & 0xFF, id & 0xFFFF, 0x15, 0, 0);
        }
        if (setParam16 & 0xFF) {
            setSoundChannelRamp(channel & 0xFF, id & 0xFFFF, 0x16, 0, 0);
        }
        workerLockRelease();
    }
}
