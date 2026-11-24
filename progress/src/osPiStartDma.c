/* identical to osPiStartDma in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
s32 osPiGetCmdQueue();
s32 osSendMesg();
s32 osJamMesg();
extern s32 gPiManagerInitialized;

/* Fills in a PI DMA request message (type, priority, device and DRAM addresses, size, handle) and
 * queues it on the PI command queue: a jam for high-priority requests (priority 1), a send
 * otherwise. Direction 0 is a read from the cartridge, anything else a write. Returns -1 when the
 * PI manager is not initialised. */
/* Fills in a PI DMA request (type, priority, addresses, size, handle) and queues it on the PI command queue: jam for priority 1, send otherwise. Returns -1 if the PI manager is not initialised. */ s32 osPiStartDma(u8 *msg, s32 priority, s32 direction, s32 devAddr, s32 dramAddr, s32 size, s32 handle) {
    s16 cmdType;

    if (gPiManagerInitialized == 0) {
        return -1;
    }
    cmdType = 0xC;
    if (direction == 0) {
        cmdType = 0xB;
    }
    *(s16 *)msg = cmdType;
    *(s8 *)(msg + 2) = priority;
    *(s32 *)(msg + 4) = handle;
    *(s32 *)(msg + 8) = dramAddr;
    *(s32 *)(msg + 0xC) = devAddr;
    *(s32 *)(msg + 0x10) = size;
    *(s32 *)(msg + 0x14) = 0;
    if (priority != 1) {
        return osSendMesg(osPiGetCmdQueue(dramAddr), msg, 0);
    }
    return osJamMesg(osPiGetCmdQueue(dramAddr), msg, 0);
}
