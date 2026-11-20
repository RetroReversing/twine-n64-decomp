extern char D_A00FFFFC[];

static __inline__ u32 probe_memory(u32 off, u32 step, u32 last, volatile s32 *p) {
    do {
        s32 a = *p;
        s32 b = *(volatile s32 *)(D_A00FFFFC + off);
        s32 read;

        *p = ~*p;
        *(volatile s32 *)(D_A00FFFFC + off) = ~*(volatile s32 *)(D_A00FFFFC + off);
        read = *p;
        if (read != ~a) break;
        read = *(volatile s32 *)(D_A00FFFFC + off);
        if (read != ~b) break;
        *p = a;
        p = (volatile s32 *)((char *)p + step);
        *(volatile s32 *)(D_A00FFFFC + off) = b;
        off += step;
    } while (off <= last);
    return off;
}

u32 osGetMemSize(void) {
    return probe_memory(0x400000, 0x100000, 0x7fffff, (volatile s32 *)0xa0400000);
}
