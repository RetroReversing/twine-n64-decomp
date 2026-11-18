#include "common_local_source_25769805646.h"

/* identical to viSetSwapBuffer in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
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

s32 func_8009F640();                                /* extern */
M2C_UNK func_8009F6B0(s32);                         /* extern */
extern void *D_800D1154;

/* Points the current VI context at a new framebuffer and sets flag 0x10 in its control word, with interrupts masked meanwhile. */ void osViSwapBuffer(s32 framebuffer) {
    s32 int_state;

    int_state = func_8009F640();
    M2C_FIELD(D_800D1154, s32 *, 4) = framebuffer;
    M2C_FIELD(D_800D1154, u16 *, 0) = (u16) (M2C_FIELD(D_800D1154, u16 *, 0) | 0x10);
    func_8009F6B0(int_state);
}
