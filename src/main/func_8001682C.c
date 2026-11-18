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

void func_8001682C(void *arg0) {
    if (arg0 != NULL) {
        M2C_FIELD(arg0, s32 *, 0x58) = 0xF0;
        M2C_FIELD(arg0, u8 *, 0x81) = 0xFF;
        M2C_FIELD(arg0, u8 *, 0x80) = 0xFF;
        M2C_FIELD(arg0, u8 *, 0x7F) = 0xFF;
        M2C_FIELD(arg0, u8 *, 0x82) = 0xFF;
        M2C_FIELD(arg0, s32 *, 8) = 0;
        M2C_FIELD(arg0, s32 *, 0xC) = 0;
        M2C_FIELD(arg0, s32 *, 0) = 0;
        M2C_FIELD(arg0, s32 *, 4) = 0;
        M2C_FIELD(arg0, s32 *, 0x10) = 0;
        M2C_FIELD(arg0, s32 *, 0x14) = 0;
        M2C_FIELD(arg0, s32 *, 0x70) = 0;
        M2C_FIELD(arg0, s32 *, 0x60) = 0;
        M2C_FIELD(arg0, s32 *, 0x5C) = 0;
        M2C_FIELD(arg0, s32 *, 0x18) = 0;
        M2C_FIELD(arg0, s16 *, 0x7A) = 0;
        M2C_FIELD(arg0, s32 *, 0x68) = 0;
        M2C_FIELD(arg0, s16 *, 0x78) = 0;
        M2C_FIELD(arg0, s8 *, 0x7E) = 0xB;
        M2C_FIELD(arg0, s32 *, 0x20) = 0;
        M2C_FIELD(arg0, s32 *, 0x64) = 0;
        M2C_FIELD(arg0, f32 *, 0x54) = 1.0f;
    }
}
