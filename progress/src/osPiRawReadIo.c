s32 osSiDeviceBusy(void);
/* Reads one word from a PI device address via uncached KSEG1; returns -1 if the PI is busy, else 0. */ s32 osPiRawReadIo(s32 devAddr, s32 *data) {
    if (osSiDeviceBusy() != 0) return -1;
    *data = *(volatile s32 *)((u32)devAddr | 0xA0000000U);
    return 0;
}
