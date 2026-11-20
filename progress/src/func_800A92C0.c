s32 func_800A9250(void);
s32 osVirtualToPhysical(s32);

s32 func_800A92C0(s32 direction, u32 spAddress, s32 dramAddress, u32 size) {
    volatile u32 *length;
    if (func_800A9250())
        return -1;
    *(volatile u32 *)0xA4040000 = spAddress;
    *(volatile u32 *)0xA4040004 = osVirtualToPhysical(dramAddress);
    switch (direction) {
        case 1: length = (volatile u32 *)0xA4040008; break;
        case 0: length = (volatile u32 *)0xA404000C; break;
    default: length = (volatile u32 *)0xA4040008; break;
        }
    *length = size - 1;
    return 0;
}
