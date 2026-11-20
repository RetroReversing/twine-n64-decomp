s32 ai_fifo_full(void) {
    s32 status = *(volatile s32 *)0xA450000C;
    return (status >> 31) != 0;
}
