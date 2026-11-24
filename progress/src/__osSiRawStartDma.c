/* identical to __osSiRawStartDma in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
#define SI_DRAM_ADDR (*(vu32 *)0xA4800000)
#define SI_PIF_ADDR_RD64B (*(vu32 *)0xA4800004)
#define SI_PIF_ADDR_WR64B (*(vu32 *)0xA4800010)
#define SI_STATUS (*(vu32 *)0xA4800018)
#define PIF_RAM_PHYS 0x1FC007C0

s32 osVirtualToPhysical(void *);
void osWritebackDCache(void *, s32);
void flushDCacheRange(void *, s32);

/* Starts an SI DMA of 64 bytes between buf and PIF RAM. dir 1 writes buf back to memory
 * first and sends it to the PIF; dir 0 reads PIF RAM into buf and invalidates the cache
 * after. Returns -1 if the SI is busy, otherwise 0. */
/* Starts a 64-byte SI DMA between dramBuf and PIF RAM (direction 1 = write to PIF, 0 = read from PIF); returns -1 if the SI is busy, else 0. */ s32 __osSiRawStartDma(s32 direction, void *dramBuf) {
    if (SI_STATUS & 3) {
        return -1;
    }
    if (direction == 1) {
        osWritebackDCache(dramBuf, 0x40);
    }
    SI_DRAM_ADDR = osVirtualToPhysical(dramBuf);
    if (direction == 0) {
        SI_PIF_ADDR_RD64B = PIF_RAM_PHYS;
    } else {
        SI_PIF_ADDR_WR64B = PIF_RAM_PHYS;
    }
    if (direction == 0) {
        flushDCacheRange(dramBuf, 0x40);
    }
    return 0;
}
