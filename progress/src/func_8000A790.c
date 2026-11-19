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

extern s32 D_800E06B8;

void func_8000A790(s32 arg0) {
    u32 i;
    if (arg0 != -1) {
        for (i = 0; i < 0x10; i++) {
            if (((s32 *)&D_800E06B8)[i] == arg0) { ((s32 *)&D_800E06B8)[i] = -1; return; }
        }
    }
}
