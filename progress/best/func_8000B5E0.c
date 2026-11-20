typedef struct {
    s32 size;
    s32 rom;
    s32 ram;
} DmaEntry;
extern s32 osPiStartDma(u8 *, s32, s32, s32, s32, s32, s32);
extern u8 D_800DD7B8[];
extern u16 D_8010018A;
extern u16 D_8010018C;
extern DmaEntry *volatile D_80100190;
extern u8 D_80102CA0[];

s32 func_8000B5E0(void) {
    u16 *p = &D_8010018C;
    u32 index = *p;
    s32 ret;
    if (index >= D_8010018A) {
        ret = 0;
    } else {
        u32 next = index + 1;
        DmaEntry *entry;
        s32 ram;
        u32 reread;
        DmaEntry *base;
        *p = next;
        entry = D_80100190 + (u16)next;
        ram = *(volatile s32 *)&entry[-1].ram;
        reread = *(volatile u16 *)p;
        base = D_80100190;
        osPiStartDma(D_800DD7B8, 0, 0, entry[-1].rom, ram,
                     base[reread - 1].size, (s32)D_80102CA0);
        ret = 1;
    }
    return ret;
}
