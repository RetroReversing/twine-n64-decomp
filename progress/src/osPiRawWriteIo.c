s32 osSiDeviceBusy(void);

s32 osPiRawReadIo(u32 devAddr, u32 *data) {
    if (osSiDeviceBusy()) {
        return -1;
    }
    *data = *(volatile u32 *)(devAddr | 0xA0000000);
    return 0;
}

/* Writes a word to a PI device address, or returns -1 if the PI is busy. */ s32 osPiRawWriteIo(u32 devAddr, u32 data) {
    if (osSiDeviceBusy()) {
        return -1;
    }
    *(volatile u32 *)(devAddr | 0xA0000000) = data;
    return 0;
}
