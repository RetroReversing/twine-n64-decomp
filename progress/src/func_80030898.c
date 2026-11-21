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

typedef struct { s16 v; s16 pad; s32 pad2; } R8;
extern R8 *gEntryTable;
extern u16 gEntryCount;

s16 func_80030898(void) {
    s16 i;
    s16 n;

    i = 0;
    if (gEntryTable == 0) {
        return 0;
    }
    n = 0;
    for (; i < gEntryCount; i++) {
        if (gEntryTable[i].v >= 0) {
            n++;
        }
    }
    return n;
}
