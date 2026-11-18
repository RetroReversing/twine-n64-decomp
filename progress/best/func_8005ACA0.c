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

extern char D_80109A60[];

void func_8005ACA0(void *arg0) {
    u8 temp_v0;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x6C);
    temp_v0 = M2C_FIELD(temp_a1, u8 *, 0xC);
    if ((temp_v0 == 0) || (*(D_80109A60 + temp_v0) == M2C_FIELD(temp_a1, u8 *, 0xD))) {
        M2C_FIELD(arg0, f32 *, 0x3C) += M2C_FIELD(temp_a1, f32 *, 0);
        M2C_FIELD(arg0, f32 *, 0x40) += M2C_FIELD(temp_a1, f32 *, 4);
        M2C_FIELD(arg0, f32 *, 0x44) += M2C_FIELD(temp_a1, f32 *, 8);
    }
}
