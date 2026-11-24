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

s32 flushDCacheRange();
s32 osPiStartDma();
s32 osRecvMesg();
s32 osYieldThread();
extern char gDmaIdleMsgQueue[];

/* Copies size bytes from ROM to RAM through PI DMA in chunks of at most 0x1000, waiting on each transfer. */ void romDmaRead(s32 ramAddr, s32 romAddr, u32 size) {
    u8 ioMsg[0x18];
    s32 ram;
    s32 rom;
    s32 fitsInChunk;
    u32 chunk;
    u32 remaining;

    ram = ramAddr;
    rom = romAddr;
    remaining = size;
    flushDCacheRange(ramAddr, remaining);
    fitsInChunk = remaining < 0x1001U;
    if (remaining != 0) {
        do {
            chunk = remaining;
            if (fitsInChunk == 0) {
                chunk = 0x1000;
            }
            osPiStartDma(ioMsg, 0, 0, rom, ram, chunk, gDmaIdleMsgQueue);
            rom += chunk;
            ram += chunk;
            remaining -= chunk;
            osRecvMesg(gDmaIdleMsgQueue, 0, 1);
            osYieldThread();
            fitsInChunk = remaining < 0x1001U;
        } while (remaining != 0);
    }
}
