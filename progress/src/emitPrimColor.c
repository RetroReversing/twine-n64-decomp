extern u8 D_80107ECF;
extern u8 D_80109684;
extern u8 D_80109A34;
extern u8 D_8010A2CC;
extern u8 D_8010D2B8;
extern u8 D_80115318;
extern void *sDisplayListCursor;

void emitPrimColor(void *arg0, void *arg1) {
    s32 flags;
    s32 a1, a2, a3;
    u16 avg;
    
    void *cmd;

    flags = *(s32 *)((char *)arg1 + 0x100);
    if (flags & 2) {
u8 *p;

        p = *(u8 **)((char *)arg0 + 0x20);
        avg = (p[0x64] + p[0x65] + p[0x66]) / 3;
        a1 = (avg * D_80115318) >> 8;
        a2 = (avg * D_80109A34) >> 8;
        a3 = (avg * D_80109684) >> 8;
    } else if (flags & 4) {
u8 *p;

        p = *(u8 **)((char *)arg0 + 0x20);
        avg = (p[0x64] + p[0x65] + p[0x66]) / 3;
        a1 = (avg * D_80107ECF) >> 8;
        a2 = (avg * D_8010D2B8) >> 8;
        a3 = (avg * D_8010A2CC) >> 8;
    } else {
u8 *p;

        p = *(u8 **)((char *)arg0 + 0x20);
        a1 = p[0x64];
        a2 = p[0x65];
        a3 = p[0x66];
    }
    cmd = sDisplayListCursor;
    sDisplayListCursor = (u8 *)cmd + 8;
    ((s32 *)cmd)[0] = 0xFA000000;
    ((s32 *)cmd)[1] = (a1 << 24) | ((a2 & 0xFF) << 16) | ((a3 & 0xFF) << 8) | 0x80;
}
