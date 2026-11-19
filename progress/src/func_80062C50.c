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

s32 func_80045CF8();
s32 func_800629E0(s32, s32, f32, s32);
extern u8 D_80109A60[];

void func_80062C50(void *arg0) {
    u16 temp_v0;

    if (*(D_80109A60 + (s16) (s32) M2C_FIELD(arg0, f32 *, 0x74)) != 0) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x7C) - 1;
        M2C_FIELD(arg0, u16 *, 0x7C) = temp_v0;
        if ((temp_v0 << 0x10) <= 0) {
            M2C_FIELD(arg0, u16 *, 0x7C) = (u16) (func_80045CF8(0x12C) + 1);
            func_800629E0(arg0, arg0 + 0x24, 1.0f, 0);
        }
    }
}
