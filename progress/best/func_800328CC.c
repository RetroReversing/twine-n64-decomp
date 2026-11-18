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

void func_800328CC(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7) {
    void *temp_a1;

    temp_a1 = arg1 + (arg4 * 0xC);
    M2C_FIELD(arg0, s16 *, 0) = (s16) (s32) (M2C_FIELD(temp_a1, f32 *, 0) * arg7 * 64.0f);
    M2C_FIELD(arg0, s16 *, 2) = (s16) (s32) (M2C_FIELD(temp_a1, f32 *, 4) * arg7 * 64.0f);
    M2C_FIELD(arg0, s16 *, 4) = (s16) (s32) (M2C_FIELD(temp_a1, f32 *, 8) * arg7 * 64.0f);
    M2C_FIELD(arg0, s32 *, 8) = (s32) *(s32 *)((arg5 * 4) + arg3);
    M2C_FIELD(arg0, s32 *, 0xC) = (s32) *(s32 *)(arg2 + (arg6 * 4));
}
