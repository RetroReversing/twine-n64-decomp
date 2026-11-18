#include "common_local_source_25769805642.h"

/* identical to osViSetEvent in V-RALLY-PAL (local match library) (matched), with its names changed by decompdecomp */
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

/* Stores the retrace message and count into the VI state block, with interrupts off. */
s32 func_8009F640();                                /* extern */
M2C_UNK func_8009F6B0(s32);                         /* extern */
extern void *D_800D1154;

void osViSetEvent(s32 mq, s32 msg, s16 retraceCount) {
    s32 saved;

    saved = func_8009F640();
    M2C_FIELD(D_800D1154, s32 *, 0x10) = mq;
    M2C_FIELD(D_800D1154, s32 *, 0x14) = msg;
    M2C_FIELD(D_800D1154, s16 *, 2) = retraceCount;
    func_8009F6B0(saved);
}
