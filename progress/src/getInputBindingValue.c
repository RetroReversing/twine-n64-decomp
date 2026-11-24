extern u8 gInputBindingTables[];

s32 getInputBindingValue(s32 arg0, s32 arg1) {
    s32 off = arg0 * 0xA0;
    u8 *base = off + gInputBindingTables;
    s32 v;
    u8 f;
    s32 hi;

    if ((base + arg1 * 2)[1] != 0) {
        u8 *tbl = gInputBindingTables + 0x70;
        v = *(s32 *)((base + arg1 * 2)[1] * 4 + tbl + off);
        if (!((base + arg1 * 2)[0] & 0x40)) {
            if (v > 0) {
                return v;
            }
        } else if (v < 0) {
            return v;
        }
    }
    f = *(base + arg1 * 2);
    if (!(f & 0x10)) {
        return 0;
    }
    hi = -((f & 0x20) != 0);
    return (hi << 16) | 0x10000;
}
