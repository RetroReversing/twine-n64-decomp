extern f32 gSinCosTable[];
#define SINS(x) gSinCosTable[(x) & 0xFFF]
#define COSS(x) gSinCosTable[((x) - 0x400) & 0xFFF]

void spherical_to_cartesian(f32 *arg0, f32 r, f32 y, f32 p) {
    s32 a = y * 651.8986206054688f;
    f32 pitch = p * 651.8986206054688f;
    f32 x0 = r * COSS(a);
    s32 b = pitch;
    f32 sb = SINS(b);
    f32 x2, x1;
    x0 *= sb;
    x2 = r * SINS(a);
    x1 = r * COSS(b);
    x2 *= sb;
    arg0[1] = x1;
    arg0[0] = x0;
    arg0[2] = x2;
}

u64 func_800ABAE8(u64, u64);
u64 func_800ABBE4(u64, u64);

u64 func_800ABE20(u64 dividend, u64 divisor) {
    if (divisor >> 32)
        return func_800ABAE8(dividend, divisor);
    return func_800ABBE4(dividend, divisor);
}

typedef struct {
    u8 pad[0x11DD];
    s8 state;
} StateRecord;

void func_8009D9B8(StateRecord *arg0) {
    if (arg0->state == 2)
        arg0->state = 3;
}

extern u8 D_80115094[];

void func_80081D20(s32 row, s32 col) {
    u8 *entry;
    row *= 0xA0;
    entry = D_80115094 + row;
    col *= 2;
    entry += col;
    *entry |= 0x80;
}
