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

s32 func_80017EC0(void *, f32, f32);
s32 func_80061578();
s32 func_80085E30();
s32 func_80085E78();

void func_800614C8(void *arg0) {
    s32 temp_s2;
    s32 temp_v0;
    void *temp_s1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x6C);
    temp_s2 = temp_s1 + 0x2C;
    func_80085E78(arg0, temp_s2);
    if (!(M2C_FIELD(temp_s1, s32 *, 0xC) & 3)) {
        func_80061578(arg0, arg0 + 0x24);
    }
    temp_v0 = M2C_FIELD(temp_s1, s32 *, 0xC) - 1;
    M2C_FIELD(temp_s1, s32 *, 0xC) = temp_v0;
    if (temp_v0 < 0xF0) {
        func_80017EC0(arg0, 1.5f, 10.0f);
    }
    if ((M2C_FIELD(temp_s1, s32 *, 0xC) == 0) || !(M2C_FIELD(arg0, s32 *, 0x60) & 0x3000)) {
        func_80085E30(temp_s2);
        M2C_FIELD(arg0, s32 *, 0x60) |= 1;
    }
}
