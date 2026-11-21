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

f32 func_800461D4();
s32 func_80117784();
s32 findNearestSearchEntry();
s32 func_80117EC8();
s32 func_80117ED0();

void func_80118AE8(void *arg0) {
    s32 temp_s0;
    void *temp_s0_2;
    void *temp_s1;
    void *temp_s3;
    void *var_a1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    temp_s3 = temp_s1 + 0x110;
    temp_s0 = findNearestSearchEntry();
    temp_s0_2 = temp_s1 + 0x104;
    func_80117784(temp_s0, findNearestSearchEntry(M2C_FIELD(temp_s1, s32 *, 0xC0)), temp_s0_2, temp_s3);
    M2C_FIELD(temp_s1, f32 *, 0x84) = func_800461D4(arg0 + 0x24, temp_s0_2);
    M2C_FIELD(temp_s1, f32 *, 0x88) = func_800461D4(temp_s0_2, temp_s3);
    if (M2C_FIELD(temp_s1, f32 *, 0x84) < 1.0f) {
        func_80117EC8(arg0, 5);
        var_a1 = temp_s3;
        func_80117ED0(arg0, var_a1, temp_s1 + 0x88);
    } else {
        func_80117EC8(arg0, 4);
        var_a1 = temp_s0_2;
        func_80117ED0(arg0, var_a1, temp_s1 + 0x84);
    }
}
