#include "common_local_source_25769803974.h"

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

s32 func_80002D30();

void func_80002E80(void *arg0) {
    s16 temp_a1;

    temp_a1 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x68), s16 *, 0xA2);
    if (temp_a1 != 0) {
        func_80002D30(arg0, temp_a1);
    }
}
