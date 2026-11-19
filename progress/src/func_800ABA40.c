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

f64 func_800ABA40(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f64 arg4, f64 arg6) {
    struct {
        s32 f10;
        s32 f14;
        s32 f18;
        s32 f1C;
        f64 f20;
        f64 f28;
    } __repair_frame;

    __repair_frame.f10 = arg0;
    __repair_frame.f14 = arg1;
    __repair_frame.f18 = arg2;
    __repair_frame.f1C = arg3;
    __repair_frame.f20 = arg4;
    __repair_frame.f28 = arg6;
    if (func_800AC100(&__repair_frame) == 0) {
        D_80100960 = ((u32) (arg0 - 3) < 2U) ? 0x22 : 0x21;
    }
    return __repair_frame.f28;
}
