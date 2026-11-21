s32 randomU16Next();
void func_800968A4();
s32 audioUpdateClipSelection();
extern u8 D_801007D9[];
extern u8 D_80100C7C[];
static inline u8 chk(u8 *obj, s32 cur) {
    u8 b4a, b4b; u32 x;
    if (cur == -1) return 0;
    b4a = obj[0x4A];
    if (b4a == 0xFF) return 0;
    b4b = obj[0x4B];
    if (b4b == 0xFF) x = D_80100C7C[(u8)cur];
    else x = (D_801007D9 + b4b * 0x10)[b4a];
    if (x == (u8)cur) return 1;
    return 0;
}
s32 func_8009A990(u8 *obj, u8 *p) {
    volatile u64 pad;
    u32 hi, lo;
    s32 pitch, r, cur;
    if (p[6] == 0) {
        u32 w = *(u32 *)p;
        lo = w >> 8;
        hi = w >> 24;
        if (hi < (lo & 0xFF)) { u32 tmp = lo; lo = hi; hi = tmp; }
    } else {
        u32 t = *(u16 *)(obj + 0x50);
        s32 a = t + p[0];
        s32 d = t - p[2];
        if ((s16)d >= 0) { lo = 0x7F; if ((s16)d < 0x80) lo = d; } else lo = 0;
        if ((s16)a >= 0) { hi = 0x7F; if ((s16)a < 0x80) hi = a; } else hi = 0;
    }
    if (p[7] != 0) {
        u32 x = randomU16Next() & 0xFFFF;
        pitch = x % 201 - 100;
    } else {
        pitch = p[1];
    }
    r = randomU16Next() & 0xFFFF;
    r = r % ((s32)(hi & 0xFF) - (s32)(lo & 0xFF) + 1);
    *(s32 *)(p + 4) = 0;
    *(s32 *)p = ((pitch & 0xFF) << 16) | (((lo & 0xFF) + r) << 8) | 0x19;
    cur = *(s32 *)(obj + 0x60);
    *(s16 *)(obj + 0x50) = p[2] & 0x7F;
    obj[0xC0] = *(u16 *)p;
    if (chk(obj, cur)) func_800968A4(obj[0x4A], obj[0x4B], obj[0x51]);
    *(s32 *)p = 4;
    audioUpdateClipSelection(obj, p);
    return 0;
}
