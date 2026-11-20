f32 func_80045E34(void *, void *);
void func_80017EC0(void *arg0, f32 arg1, f32 arg2) {
    void *node;
    u32 flag, mask, one;
    flag = 0x40000000; mask = 0xFFFF0FFF; one = 1;
    node = *(void **)((char *)arg0 + 0x20);
    node = *(void **)node;
    if (node != 0) do {
        if (*(void **)((char *)node + 0x20) == *(void **)((char *)arg0 + 0x20) && func_80045E34((char *)arg0 + 0x24, (char *)node + 0x24) < arg1) {
            if ((u32)(*(u16 *)((char *)node + 0x78) - 2) < 2) {
                *(u32 *)((char *)node + 0x60) |= flag;
                *(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x18C) = (*(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x18C) & mask) | 0x7000;
                *(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x1A0) = *(u32 *)((char *)arg0 + 0x24);
                *(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x1A4) = *(u32 *)((char *)arg0 + 0x28);
                *(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x1A8) = *(u32 *)((char *)arg0 + 0x2C);
                *(f32 *)((char *)*(void **)((char *)node + 0x6C) + 0x1B0) = arg2;
                *(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x1B4) = 0;
            }
            if (*(u16 *)((char *)node + 0x78) == one && *(s16 *)((char *)node + 0x7A) != 0x27) {
                *(u32 *)((char *)node + 0x60) |= flag;
                *(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x88) = (*(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x88) & 0xFFE1FFFF) | 0xE0000;
                *(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x50) = *(u32 *)((char *)arg0 + 0x24);
                *(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x54) = *(u32 *)((char *)arg0 + 0x28);
                *(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x58) = *(u32 *)((char *)arg0 + 0x2C);
                *(f32 *)((char *)*(void **)((char *)node + 0x6C) + 0x60) = arg2;
                *(u32 *)((char *)*(void **)((char *)node + 0x6C) + 0x64) = 0;
            }
        }
        node = *(void **)node;
    } while (node != 0);
}
