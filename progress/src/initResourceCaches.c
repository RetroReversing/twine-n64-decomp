extern s16 D_800D9428, D_800D942A, D_800D942C[6];
extern s16 D_800D94F8, D_800D94FA, D_800D9500[8];
extern s16 D_800DC710, D_800DC712;
extern s32 D_800DC718[6];

void initResourceCaches(void) {
    u32 i;
    s16 value, *out;
    s32 largeValue, *largeOut;

    i = 0;
    value = 0x7fff;
    out = D_800D942C;
    D_800D942A = 0;
    D_800D9428 = 0;
    do {
        *out++ = value;
        ++i;
    } while (i < 6);

    i = 0;
    value = 0x7fff;
    out = D_800D9500;
    D_800D94FA = 0;
    D_800D94F8 = 0;
    do {
        *out++ = value;
        ++i;
    } while (i < 8);

    i = 0;
    largeValue = 0x7fffffff;
    largeOut = D_800DC718;
    D_800DC712 = 0;
    D_800DC710 = 0;
    do {
        *largeOut++ = largeValue;
        ++i;
    } while (i < 6);
}
