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

s32 func_8008C0D4();
s32 func_8008C11C();
s32 func_8009959C();
extern u8 D_800CF540;
extern u8 D_801096E8[];

void func_80093758(s32 arg0) {
    s32 temp_a0;

    if (D_800CF540 != 0) {
        func_8008C0D4();
        temp_a0 = arg0 * 0x18;
        if (*(D_801096E8 + temp_a0) == 1) {
            *(D_801096E8 + temp_a0) = 0;
            func_8009959C(arg0);
        }
        func_8008C11C();
    }
}
