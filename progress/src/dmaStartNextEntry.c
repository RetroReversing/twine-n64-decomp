typedef struct {
    s32 size;
    s32 rom;
    s32 ram;
} DmaEntry;
extern s32 osPiStartDma(u8 *, s32, s32, s32, s32, s32, s32);
extern u8 D_800DD7B8[];
extern u16 gDmaQueueCount;
extern u16 gDmaQueueIndex;
extern DmaEntry *volatile D_80100190;
extern u8 gDmaDoneMsgQueue[];

s32 dmaStartNextEntry(void) {
    u16 *p = &gDmaQueueIndex;
    u32 index = *p;
    s32 ret;
    if (index >= gDmaQueueCount) {
        ret = 0;
    } else {
        u32 next = index + 1;
        DmaEntry *entry;
        DmaEntry *b0;
        s32 ram;
        u32 reread;
        DmaEntry *base;
        next = (*p = next);
        b0 = D_80100190;
        entry = (DmaEntry *)((u32)(next * sizeof(DmaEntry)) + (u32)b0);
        ram = *(volatile s32 *)&entry[-1].ram;
        reread = *(volatile u16 *)p;
        base = D_80100190;
        osPiStartDma(D_800DD7B8, 0, 0, entry[-1].rom, ram,
                     base[reread - 1].size, (s32)gDmaDoneMsgQueue);
        ret = 1;
    }
    return ret;
}
