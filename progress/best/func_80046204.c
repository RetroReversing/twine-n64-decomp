extern f32 D_800CA350[];
#define SINS(x) D_800CA350[(x) & 0xFFF]
#define COSS(x) D_800CA350[((x) - 0x400) & 0xFFF]

void func_80046204(f32 *arg0, f32 r, f32 y, f32 p) {
    s32 a = y * 651.8986f;
    s32 b = p * 651.8986f;
    f32 sb;
    f32 x0, x1, x2;

    sb = SINS(b);
    x0 = r * COSS(a) * sb;
    x2 = r * SINS(a) * sb;
    x1 = r * COSS(b);
    arg0[1] = x1;
    arg0[0] = x0;
    arg0[2] = x2;
}
