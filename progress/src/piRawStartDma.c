/* identical to piRawStartDma in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
extern s32 gRomBaseAddr;
extern s32 osVirtualToPhysical(void *);

#define PI_DRAM_ADDR_REG (*(vu32 *)0xA4600000)
#define PI_CART_ADDR_REG (*(vu32 *)0xA4600004)
#define PI_RD_LEN_REG    0xA4600008
#define PI_WR_LEN_REG    0xA460000C
#define PI_STATUS_REG    (*(vu32 *)0xA4600010)

/* Starts a raw cartridge DMA on the PI: waits until the PI is idle, sets the
 * RAM address (physical) and the cart address (ROM base | cartAddr, 28 bits),
 * then the length minus one. direction 0 writes to the cart, 1 reads from it;
 * any other value returns -1. */
/* Starts a raw PI cartridge DMA (direction 0 = write, 1 = read) after waiting for the PI to go idle; returns -1 for an invalid direction. */ s32 piRawStartDma(s32 direction, s32 cartAddr, void *ramAddr, s32 length)
{
    vu32 *lenReg;

    while (PI_STATUS_REG & 3) {}
    PI_DRAM_ADDR_REG = osVirtualToPhysical(ramAddr);
    PI_CART_ADDR_REG = (gRomBaseAddr | cartAddr) & 0x1fffffff;
    switch (direction) {
    case 0:
        lenReg = (vu32 *)PI_WR_LEN_REG;
        break;
    case 1:
        lenReg = (vu32 *)PI_RD_LEN_REG;
        break;
    default:
        return -1;
    }
    *lenReg = length - 1;
    return 0;
}
