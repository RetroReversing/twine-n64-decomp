extern f32 gCosTable[];
#define COS(x) gCosTable[(x) & 0xFFF]
#define SIN(x) gCosTable[((x) - 0x400) & 0xFFF]
void func_80082FE4(const s16 *arg0, f32 *arg1) {
    s32 b = arg0[1];
    s32 c = arg0[2];
    f32 cb = COS(b);
    f32 cc = COS(c);
    f32 sb = SIN(b);
    s32 a = arg0[0];
    f32 ca = COS(a);
    f32 sc = SIN(c);
    f32 sa = SIN(a);
    arg1[0] = cc * cb;
    arg1[1] = cc * sb * sa - sc * ca;
    arg1[2] = cc * sb * ca + sc * sa;
    arg1[3] = sc * cb;
    arg1[4] = sc * sb * sa + cc * ca;
    arg1[5] = sc * sb * ca - cc * sa;
    arg1[6] = -sb;
    arg1[7] = cb * sa;
    arg1[8] = cb * ca;
}
