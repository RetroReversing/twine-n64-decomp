extern f32 D_800CA350[];
#define SINS(x) D_800CA350[(x) & 0xFFF]
#define COSS(x) D_800CA350[((x) - 0x400) & 0xFFF]

void func_80082D24(const s16 *ang, f32 *m) {
    s32 a = ang[0];
    s32 b = ang[1];
    s32 c = ang[2];
    f32 sb = SINS(b);
    f32 sc = SINS(c);
    f32 ca = COSS(a);
    f32 cb = COSS(b);
    f32 cc = COSS(c);
    f32 sa = SINS(a);
    f32 cacb = ca * cb;
    f32 sacb = sa * -cb;

    m[0] = sb * sc;
    m[1] = sb * -cc;
    m[2] = cb;
    m[3] = cacb * sc + sa * cc;
    m[4] = sa * sc - cacb * cc;
    m[5] = -ca * sb;
    m[6] = sacb * sc + ca * cc;
    m[7] = ca * sc - sacb * cc;
    m[8] = sa * sb;
}
