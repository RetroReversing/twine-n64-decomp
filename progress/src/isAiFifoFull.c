/* Returns nonzero if the AI DMA FIFO is full (bit 31 of AI_STATUS_REG). */ s32 isAiFifoFull(void) {
    s32 aiStatus = *(volatile s32 *)0xA450000C;
    return (aiStatus >> 31) != 0;
}
