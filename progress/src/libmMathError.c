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

s32 libmHandleException();
extern s32 gLibmErrno;

/* Math library error hook: fills an exception record and, if no handler consumes it, sets errno to EDOM (0x21) or ERANGE (0x22) for error types 3 and 4. */ f64 libmMathError(s32 errorType, s32 nameLo, s32 nameHi, s32 pad, f64 arg1Value, f64 result) {
    struct {
        s32 f10;
        s32 f14;
        s32 f18;
        s32 f1C;
        f64 f20;
        f64 f28;
    } __repair_frame;

    __repair_frame.f10 = errorType;
    __repair_frame.f14 = nameLo;
    __repair_frame.f18 = nameHi;
    __repair_frame.f1C = pad;
    __repair_frame.f20 = arg1Value;
    __repair_frame.f28 = result;
    if (libmHandleException(&__repair_frame) == 0) {
        gLibmErrno = ((u32) (errorType - 3) < 2U) ? 0x22 : 0x21;
    }
    return __repair_frame.f28;
}
