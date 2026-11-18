/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_800452AC();
s32 func_80045CF8();
f32 func_80045D2C();
s32 func_8005D444();
s32 func_800617D8();
extern f64 D_800D4150;
extern f64 D_800D4158;
extern f64 D_800D4160;

void func_8005D62C(void *arg0) {
    f32 temp_fv1;
    s16 temp_v0;
    u8 temp_a0;
    void *temp_s0;
    void *temp_s0_2;
    void *temp_s2;
    void *temp_s3;

    temp_s0 = M2C_FIELD(arg0, void **, 0x6C);
    temp_a0 = M2C_FIELD(arg0, u8 *, 0x81) - 1;
    M2C_FIELD(arg0, u8 *, 0x7F) += 1;
    M2C_FIELD(arg0, u8 *, 0x80) += 1;
    M2C_FIELD(arg0, u8 *, 0x81) = temp_a0;
    temp_v0 = M2C_FIELD(temp_s0, s16 *, 0x1C);
    temp_s3 = M2C_FIELD(arg0, void **, 0x20);
    if (temp_v0 > 0) {
        M2C_FIELD(temp_s0, s16 *, 0x1C) = (s16) (temp_v0 - 1);
        temp_fv1 = M2C_FIELD(M2C_FIELD(temp_s3, void **, 0x3C), f32 *, 0x20);
        if (M2C_FIELD(arg0, f32 *, 0x28) < temp_fv1) {
            M2C_FIELD(arg0, f32 *, 0x28) = temp_fv1;
            M2C_FIELD(temp_s0, f32 *, 4) = (f32) (M2C_FIELD(temp_s0, f32 *, 4) * (func_80045D2C(0x3F666666, temp_a0) - 0.45f));
            M2C_FIELD(temp_s0, f32 *, 8) = (f32) ((f64) M2C_FIELD(temp_s0, f32 *, 8) * D_800D4150);
            M2C_FIELD(temp_s0, f32 *, 0xC) = (f32) (M2C_FIELD(temp_s0, f32 *, 0xC) * (func_80045D2C(0x3F666666) - 0.45f));
            M2C_FIELD(arg0, f32 *, 0x54) = (f32) ((f64) M2C_FIELD(arg0, f32 *, 0x54) * D_800D4158);
        }
        M2C_FIELD(arg0, f32 *, 0x24) += (M2C_FIELD(temp_s0, f32 *, 4) * 0.033333335f);
        M2C_FIELD(arg0, f32 *, 0x28) += (M2C_FIELD(temp_s0, f32 *, 8) * 0.033333335f);
        M2C_FIELD(arg0, f32 *, 0x2C) += (M2C_FIELD(temp_s0, f32 *, 0xC) * 0.033333335f);
        temp_s2 = arg0 + 0x3C;
        M2C_FIELD(temp_s0, f32 *, 8) = (f32) ((f64) M2C_FIELD(temp_s0, f32 *, 8) - D_800D4160);
        func_800452AC(temp_s0 + 0x10, temp_s2, temp_s2);
        if (M2C_FIELD(arg0, f32 *, 0x28) < M2C_FIELD(M2C_FIELD(temp_s3, void **, 0x20), f32 *, 0x5C)) {
            temp_s0_2 = arg0 + 0x24;
            func_800617D8(M2C_FIELD(arg0, void **, 0x20), temp_s0_2, temp_s2, 0, 0.1f, 1.01f, 0x19, 0xFB, 0x17, 0x80, 0x80808002);
            func_800617D8(M2C_FIELD(arg0, void **, 0x20), temp_s0_2, NULL, 0, 0.25f, func_80045D2C(0x3D4CCCCD) + 1.05f, 0x1C, 0x1B, 0x2C, 0x40008080, 0x80808008);
            goto block_8;
        }
    } else {
        if (func_80045CF8(4) == 0) {
            func_8005D444(arg0, arg0 + 0x24, 0x40000000, 2, 0x16, 0xFB);
        }
block_8:
        M2C_FIELD(arg0, s32 *, 0x60) |= 1;
    }
}
