/* identical to osSpTaskStartGo in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 __osSpDeviceBusy(void);
void __osSpSetStatus(u32 value);

/* Starts the RSP: waits until it is no longer halted or busy, then writes 0x125 to SP_STATUS. */
/* Waits until the RSP device is not busy, then writes 0x125 to SP_STATUS to start the task. */ void osSpTaskStartGo(void) {
    do {

    } while (__osSpDeviceBusy() != 0);
    __osSpSetStatus(0x125);
}
