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

extern f64 D_800D4480;
extern f64 D_800D4488;
extern f64 D_800D4490;
extern char D_80109688[];

void func_80067BB8(void *arg0) {
    f32 sp0;
    f32 sp4;
    s32 sp8;
    void **temp_v1;
    void *temp_a0;
    void *temp_v0;

    temp_a0 = M2C_FIELD(arg0, void **, 0x6C);
    temp_v1 = (M2C_FIELD(temp_a0, s8 *, 0x182) * 4) + D_80109688;
    sp0 = M2C_FIELD(*temp_v1, f32 *, 0x34);
    sp8 = 0;
    sp4 = M2C_FIELD(*temp_v1, f32 *, 0x38);
    M2C_FIELD(M2C_FIELD(temp_a0, void **, 0xA8), f32 *, 0x3C) = (f32) ((f64) (M2C_FIELD(temp_a0, f32 *, 0x74) * 651.8986f) + ((((f64) M2C_FIELD(temp_a0, f32 *, 0x28) * D_800D4480) / (f64) M2C_FIELD(*temp_v1, f32 *, 0x4C)) * D_800D4488));
    temp_v0 = *temp_v1;
    M2C_FIELD(M2C_FIELD(temp_a0, void **, 0xA8), f32 *, 0x40) = (f32) (D_800D4490 - ((f64) M2C_FIELD(temp_v0, f32 *, 0x80) * D_800D4488 * (((f64) M2C_FIELD(temp_a0, f32 *, 0x24) * D_800D4480) / (f64) M2C_FIELD(temp_v0, f32 *, 0x4C))));
    M2C_FIELD(M2C_FIELD(temp_a0, void **, 0xA8), f32 *, 0x44) = -2048.0f;
}
