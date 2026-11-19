extern u8 D_800CE354;
extern u8 D_800CE358;
extern s32 D_800CE570;
extern s8 D_800E1A90;
extern s32 D_800E1A9C;
extern s32 D_800E1AA0;
extern u8 *D_800E1AAC;
extern u8 *D_800E1AB0;
extern s32 D_80102CB8;
extern u32 D_80109A90;

#define AT(T, sym, off) (*(T *)((u8 *)&(sym) + (off)))

s32 func_80083E90(s32 arg0, s32 arg1) {
    u8 *a;
    u8 *b;
    s32 align;
    s32 t;
    u32 blk;
    s32 r2;
    s32 nv;

    if (D_800E1A90 == 0) {
        t = arg1 * 12;
        align = AT(u8, D_800CE358, t) - 1;
        if (arg1 == 0x2D) {
            s32 v = D_80102CB8 - arg0;
            s32 r = v - (v & align);
            s32 d = D_80102CB8 - r;
            D_80102CB8 = r;
            D_800CE570 += d;
            return r;
        }
        blk = D_80109A90;
        r2 = (blk + align) & ~align;
        nv = r2 + arg0;
        D_80109A90 = nv;
        AT(u32, D_800CE354, t) = AT(u32, D_800CE354, t) + (nv - blk);
        return r2;
    }
    if (arg0 != 0) {
        a = D_800E1AAC;
        if (a != NULL) {
            s32 base = arg1 * 12;
loop:
            blk = *(u32 *)(a + 8);
            b = a + blk;
            if (blk >= (u32)(arg0 + 0x18)) {
                s32 off = ((s32)b - arg0) & (AT(u8, D_800CE358, base) - 1);
                if (blk >= (u32)(arg0 + 0x18 + off)) {
                    s32 p = arg0 + off;
                    u8 *n = b - (p + 12);
                    AT(u32, D_800CE354, base) = AT(u32, D_800CE354, base) + 12 + p;
                    D_800E1A9C = (D_800E1A9C - 12) - p;
                    D_800E1AA0 = D_800E1AA0 + 12 + p;
                    *(u32 *)(a + 8) = (u32)((*(u32 *)(a + 8) - 12) - p);
                    *(void **)n = NULL;
                    *(u32 *)(n + 8) = (u32)(p + 12);
                    *(u8 **)(n + 4) = D_800E1AB0;
                    if (D_800E1AB0 != NULL) {
                        *(u8 **)D_800E1AB0 = n;
                    }
                    D_800E1AB0 = n;
                    return (s32)(n + 12);
                }
            }
            a = *(u8 **)(a + 4);
            if (a == NULL) {
                return 0;
            }
            goto loop;
        }
    }
    return 0;
}
