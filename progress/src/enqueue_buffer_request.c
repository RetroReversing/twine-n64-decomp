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
extern volatile u8 D_800FDBB0;
extern char dmaQueueRomAddr[];
extern char dmaQueueRamAddr[];
extern char dmaQueueSize[];
extern char dmaMesgQueue[];
extern char dmaMesgBuf[];
extern s32 *dmaHandlerInit;
extern s32 func_8009D100;

void enqueue_buffer_request(s32 arg0, s32 arg1, s32 arg2) {
    workerLockAcquire(arg0);
    if (dmaHandlerInit == NULL) {
        osCreateMesgQueue(dmaMesgQueue, dmaMesgBuf, 1);
        D_800FDBB0 = 0;
        dmaHandlerInit = &func_8009D100;
    }
    if ((u8) D_800FDBB0 < 4U) {
        *(s32 *)(dmaQueueRomAddr + (D_800FDBB0 * 0xC)) = arg0;
        *(s32 *)(dmaQueueRamAddr + (D_800FDBB0 * 0xC)) = arg1;
        *(s32 *)(dmaQueueSize + (D_800FDBB0 * 0xC)) = (arg2 + 0xF) & ~0xF;
        D_800FDBB0++;
        flushDCacheRange(arg0, arg2);
    }
    workerLockRelease();
}
