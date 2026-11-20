s32 func_8008C0D4(void);
s32 func_8008C11C(void);
void func_80095374(void *, void *, void *);
s32 invertAffineTransform(void *, f32 *);
extern u8 gWorkerActive;
typedef struct { s32 x,y,z; } Vec3s;
s32 func_800945C4(void *out, Vec3s *v1, Vec3s *v2, Vec3s *v3, f32 *neg, u8 scale) {
    s32 ret;
    f32 m[12];
    if (!gWorkerActive) {
        ret = 0;
    } else {
        func_8008C0D4();
        *(Vec3s *)((s8 *)out + 0xC) = *v1;
        *(Vec3s *)((s8 *)out + 0x18) = *v2;
        *(Vec3s *)((s8 *)out + 0x24) = *v3;
        *(f32 *)((s8 *)out + 0x3C) = -neg[0];
        *(f32 *)((s8 *)out + 0x40) = -neg[1];
        *(f32 *)((s8 *)out + 0x44) = -neg[2];
        func_80095374((s8 *)out + 0x30, (s8 *)out + 0x3C, (s8 *)out + 0x24);
        m[0] = *(f32 *)((s8 *)out + 0x30);
        m[3] = *(f32 *)((s8 *)out + 0x34);
        m[6] = *(f32 *)((s8 *)out + 0x38);
        m[1] = *(f32 *)((s8 *)out + 0x3C);
        m[4] = *(f32 *)((s8 *)out + 0x40);
        m[7] = *(f32 *)((s8 *)out + 0x44);
        m[2] = *(f32 *)((s8 *)out + 0x24);
        m[5] = *(f32 *)((s8 *)out + 0x28);
        m[8] = *(f32 *)((s8 *)out + 0x2C);
        m[9] = *(f32 *)((s8 *)out + 0xC);
        m[10] = *(f32 *)((s8 *)out + 0x10);
        m[11] = *(f32 *)((s8 *)out + 0x14);
        invertAffineTransform((s8 *)out + 0x48, m);
        *(f32 *)((s8 *)out + 0x84) = scale * 0.007874016f;
        func_8008C11C();
        ret = 1;
    }
    return ret;
}
