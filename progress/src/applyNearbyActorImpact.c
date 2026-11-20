typedef struct { u32 x, y, z; } Vec;
f32 approxDistance(void *, void *);
void applyNearbyActorImpact(void *arg0, f32 arg1, f32 arg2) {
    void *node;
    u32 flag, mask, one;
    node = **(void ***)((char *)arg0 + 0x20);
    if (node != 0) {
    flag = 0x40000000; mask = 0xFFFF0FFF; one = 1;
    do {
        if (*(void **)((char *)node + 0x20) == *(void **)((char *)arg0 + 0x20) && approxDistance((char *)arg0 + 0x24, (char *)node + 0x24) < arg1) {
            if ((u32)(*(u16 *)((char *)node + 0x78) - 2) < 2) {
                char *dest = *(char **)((char *)node + 0x6C);
                *(u32 *)((char *)node + 0x60) |= flag;
                *(u32 *)(dest + 0x18C) = (*(u32 *)(dest + 0x18C) & mask) | 0x7000;
                { u32 a = *(u32 *)((char *)arg0 + 0x24), b = *(u32 *)((char *)arg0 + 0x28), c = *(u32 *)((char *)arg0 + 0x2c); *(u32 *)(dest + 0x1a0) = a; *(u32 *)(dest + 0x1a4) = b; *(u32 *)(dest + 0x1a8) = c; }
                do { *(f32 *)(dest + 0x1B0) = arg2; } while (0);
                *(u32 *)(dest + 0x1B4) = 0;
            }
            if (*(u16 *)((char *)node + 0x78) == 1 && *(s16 *)((char *)node + 0x7A) != 0x27) {
                char *dest = *(char **)((char *)node + 0x6C);
                u32 a, b, c;
                *(u32 *)((char *)node + 0x60) |= flag;
                *(u32 *)(dest + 0x88) = (*(u32 *)(dest + 0x88) & 0xFFE1FFFF) | 0xE0000;
                a = *(u32 *)((char *)arg0 + 0x24); b = *(u32 *)((char *)arg0 + 0x28); c = *(u32 *)((char *)arg0 + 0x2C);
                *(u32 *)(dest + 0x50) = a; *(u32 *)(dest + 0x54) = b; *(u32 *)(dest + 0x58) = c;
                do { *(f32 *)(dest + 0x60) = arg2; } while (0);
                *(u32 *)(dest + 0x64) = 0;
            }
        }
        node = *(void **)node;
    } while (node != 0);
    }
}
