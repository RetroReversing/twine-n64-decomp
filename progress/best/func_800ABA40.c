/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */
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

s32 func_800AC100();
extern s32 D_80100960;

f64 func_800ABA40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f64 arg4, s32 arg5, f64 arg6) {
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    f64 sp20;
    f64 sp28;
    s32 var_v0;

    sp10 = arg0;
    sp14 = arg1;
    sp18 = arg2;
    sp1C = arg3;
    sp20 = arg4;
    sp28 = arg6;
    if (func_800AC100(&sp10) == 0) {
        var_v0 = 0x22;
        if ((u32) (arg0 - 3) >= 2U) {
            var_v0 = 0x21;
        }
        D_80100960 = var_v0;
    }
    return sp28;
}
