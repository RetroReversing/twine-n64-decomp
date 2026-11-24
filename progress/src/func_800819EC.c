extern u8 gInputBindingTables[];

s32 func_800819EC(s32 arg0, s32 arg1) {
    s32 off = arg0 * 0xA0;
    u8 *base = off + gInputBindingTables;
    s32 v;
    u8 f;
    s32 hi;
    u8 *entry;

    if ((base + arg1 * 2)[1] != 0) {
        u8 *tbl = gInputBindingTables + 0x70;
        u8 *value = (base + arg1 * 2)[1] * 4 + tbl;
        u32 flags = (base + arg1 * 2)[0];
        v = *(s32 *)(value + off);
        if (!(flags & 0x40)) {
            if (v > 0) {
                return v;
            }
        } else if (v < 0) {
            return v;
        }
    }
    entry = (u8 *)((u32)(arg1 * 2) + (u32)base);
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
