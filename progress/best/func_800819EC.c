extern u8 D_80115094[];

s32 func_800819EC(s32 arg0, s32 arg1) {
    s32 off = arg0 * 0xA0;
    u8 *base = off + D_80115094;
    s32 v;
    u8 f;
    s32 hi;
    u8 *entry;

    if ((base + arg1 * 2)[1] != 0) {
        u8 *tbl = D_80115094 + 0x70;
        v = *(s32 *)((base + arg1 * 2)[1] * 4 + tbl + off);
        if (!((base + arg1 * 2)[0] & 0x40)) {
            if (v > 0) {
                return v;
            }
        } else if (v < 0) {
            return v;
        }
    }
    entry = base + arg1 * 2;
    f = *entry;
    if (!(f & 2)) {
        return 0;
    }
    if (f & 0x80) {
        *entry = f & 0x7f;
        return 0;
    }
    hi = -((f & 0x20) != 0);
    return (hi << 16) | 0x10000;
}
