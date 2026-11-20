extern char D_A00FFFFC[];
extern s32 D_A0400000;
u32 func_800A67B0(void) {
    volatile s32 *p;
    s32 a, b;
    u32 off;
    p = (volatile s32 *)0xa0400000;
    off = 0x400000;
    for (;;) {
        a = *p;
        b = *(volatile s32 *)(D_A00FFFFC + off);
        *p = ~*p;
        *(volatile s32 *)(D_A00FFFFC + off) = ~*(volatile s32 *)(D_A00FFFFC + off);
        if (~(*p) == a && ~*(volatile s32 *)(D_A00FFFFC + off) == b) {
            *p = a;
            p = (volatile s32 *)((char *)p + 0x100000);
            *(volatile s32 *)(D_A00FFFFC + off) = b;
            off += 0x100000;
            if (off <= 0x7fffffU) continue;
        }
        break;
    }
    return off;
}
