extern char D_801007D9[];
extern u8 D_80100C7C[];
s32 func_80099AF0(u8 *arg0) {
    s32 id = *(s32 *)(arg0 + 0x60);
    s32 id2;
    u8 a, b;
    u8 tbl;
    if (id != -1) {
        a = arg0[0x4A];
        if (a != 0xFF) {
            b = arg0[0x4B];
            id2 = id;
            if (b == 0xFF) {
                tbl = D_80100C7C[id2 & 0xFF];
            } else {
                char *base = D_801007D9;
                tbl = *(base + b * 16 + a);
            }
            if ((id2 & 0xFF) == tbl) return 1;
        }
    }
    return 0;
}
