extern f32 gSinCosTable[];
#define SINS(x) gSinCosTable[(x) & 0xFFF]
#define COSS(x) gSinCosTable[((x) - 0x400) & 0xFFF]
void func_80082E84(const s16 *ang, f32 *m) {
    s32 a=ang[0], b=ang[1], c=ang[2];
    s32 ai=(a-0x400)&0xFFF;
    f32 sb=SINS(b);
    f32 sc=SINS(c);
    f32 ca=gSinCosTable[ai];
    f32 first=sb*sc;
    f32 cb=COSS(b);
    f32 cacb=ca*cb;
    f32 cc=COSS(c);
    f32 sa=SINS(a);
    f32 second=sb*-cc;
    f32 fourth=cacb*sc+sa*cc;
    f32 sacb=sa*-cb;
    m[0]=first; m[1]=second; m[2]=cb;
    m[3]=fourth; m[4]=sa*sc-cacb*cc; m[5]=-ca*sb;
    m[6]=sacb*sc+ca*cc; m[7]=ca*sc-sacb*cc; m[8]=sa*sb;
}
