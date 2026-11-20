extern u8 *D_800B2710;
typedef struct { f32 x, y, z; } TwineV3;
#define NEXT_F(dst) do { f32 *c_ = *(f32 **)base; *(f32 **)base = c_ + 1; dst = *c_; } while (0)
void func_8000D3AC(s32 arg0, u32 arg1) {
    u8 *base;
    u8 *obj;
    u32 off;
    void *a3;
    TwineV3 v;
    base = D_800B2710;
    off = (u32)((arg0 * 53) << 2);
    obj = base + off;
    a3 = *(void **)(obj + 0x68);
    *(s16 *)(obj + 0x80) = 0;
    *(s16 *)(obj + 0x82) = (s16)(arg1 >> 8);
    if (a3 != NULL) {
        *(TwineV3 *)((u8 *)a3 + 0x24) = *(TwineV3 *)(obj + 0x2C);
    }
    base = D_800B2710;
    NEXT_F(v.x); NEXT_F(v.y); NEXT_F(v.z); v.z = -v.z;
    *(TwineV3 *)(base + off + 0x38) = v;
    base = D_800B2710;
    NEXT_F(v.x); NEXT_F(v.y); NEXT_F(v.z); v.z = -v.z;
    *(TwineV3 *)(base + off + 0x20) = v;
    base = D_800B2710;
    NEXT_F(v.x); NEXT_F(v.y); NEXT_F(v.z); v.z = -v.z;
    *(TwineV3 *)(base + off + 0x2C) = v;
    base = D_800B2710;
    NEXT_F(v.x); NEXT_F(v.y); NEXT_F(v.z); v.z = -v.z;
    *(TwineV3 *)(base + off + 0x44) = v;
}
