#include "common.h"

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

void *func_80016410();
s32 func_80064318();

void *func_8006452C(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_80016410(0, 0, 0);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s16 *, 0x78) = 0x30;
        M2C_FIELD(temp_v0, s32 *, 0x18) = arg0;
        M2C_FIELD(temp_v0, u8 *, 0x7F) = 0x80;
        M2C_FIELD(temp_v0, s8 *, 0x80) = 0;
        M2C_FIELD(temp_v0, s8 *, 0x81) = 0;
        func_80064318(temp_v0, arg1);
    }
    return temp_v0;
}
