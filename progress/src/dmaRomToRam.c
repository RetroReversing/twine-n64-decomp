/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 workerLockAcquire();
s32 workerLockRelease();
s32 flushDCacheRange();
s32 osCreateMesgQueue();
s32 osRecvMesg();
s32 osYieldThread();
extern volatile u8 dmaQueueCount;
extern char dmaQueueRomAddr[];
extern char dmaQueueRamAddr[];
extern char dmaQueueSize[];
extern char dmaMesgQueue[];
extern char dmaMesgBuf[];
extern s32 *dmaHandlerInit;
extern s32 func_8009D100;

/* Queues one ROM-to-RAM DMA request (romAddr -> ramAddr, size bytes) when a slot is free, then waits for it to finish. */
void dmaRomToRam(s32 romAddr, s32 ramAddr, s32 size) {
    workerLockAcquire(romAddr);
    if (dmaHandlerInit == NULL) {
        osCreateMesgQueue(dmaMesgQueue, dmaMesgBuf, 1);
        dmaQueueCount = 0;
        dmaHandlerInit = &func_8009D100;
    }
    if ((u8) dmaQueueCount < 4U) {
        *(s32 *)(dmaQueueRomAddr + (dmaQueueCount * 0xC)) = romAddr;
        *(s32 *)(dmaQueueRamAddr + (dmaQueueCount * 0xC)) = ramAddr;
        *(s32 *)(dmaQueueSize + (dmaQueueCount * 0xC)) = (size + 0xF) & ~0xF;
        dmaQueueCount++;
        flushDCacheRange(romAddr, size);
        workerLockRelease();
        osRecvMesg(dmaMesgQueue, 0, 1);
        osYieldThread();
        return;
    }
    workerLockRelease();
}
