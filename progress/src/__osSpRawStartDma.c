s32 __osSpDeviceBusy(void);
s32 osVirtualToPhysical(s32);

/* Starts an RSP DMA transfer between SP memory and DRAM (direction 0 = write length reg 0x0C, otherwise read); returns -1 if the SP DMA is busy. */ s32 __osSpRawStartDma(s32 direction, u32 spAddr, s32 dramAddr, u32 size) {
    volatile u32 *lengthReg;
    if (__osSpDeviceBusy())
        return -1;
    *(volatile u32 *)0xA4040000 = spAddr;
    *(volatile u32 *)0xA4040004 = osVirtualToPhysical(dramAddr);
    switch (direction) {
        case 1: lengthReg = (volatile u32 *)0xA4040008; break;
        case 0: lengthReg = (volatile u32 *)0xA404000C; break;
    default: lengthReg = (volatile u32 *)0xA4040008; break;
        }
    *lengthReg = size - 1;
    return 0;
}
