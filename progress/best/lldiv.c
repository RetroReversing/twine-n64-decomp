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

s32 func_800ABCB0();

void *lldiv(void *arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4, u32 arg5) {
    s32 sp10;
    u32 sp14;
    s32 sp18;
    u32 sp1C;
    s32 temp_ret;
    s32 temp_t0;
    s32 temp_v0;
    u32 temp_lo;
    u32 temp_t1;
    u32 temp_v1;
    u32 temp_v1_2;

    temp_ret = func_800ABCB0(arg2, arg3, arg4, arg5);
    temp_v0 = temp_ret;
    temp_v1 = (u32) (u64) temp_ret;
    temp_lo = arg5 * temp_v1;
    sp10 = temp_v0;
    sp14 = temp_v1;
    temp_t1 = arg3 - temp_lo;
    temp_t0 = (arg2 - (MULTU_HI(arg5, temp_v1) + (arg5 * temp_v0) + (temp_v1 * arg4))) - (arg3 < temp_lo);
    sp18 = temp_t0;
    sp1C = temp_t1;
    if ((sp10 < 0) && ((sp18 > 0) || ((sp18 == 0) && (sp1C != 0)))) {
        temp_v1_2 = temp_v1 + 1;
        sp10 = temp_v0 + (temp_v1_2 == 0);
        sp14 = temp_v1_2;
        sp18 = (temp_t0 - arg4) - (temp_t1 < arg5);
        sp1C = temp_t1 - arg5;
    }
    M2C_FIELD(arg0, s32 *, 0) = sp10;
    M2C_FIELD(arg0, u32 *, 4) = sp14;
    M2C_FIELD(arg0, s32 *, 8) = sp18;
    M2C_FIELD(arg0, u32 *, 0xC) = sp1C;
    return arg0;
}
