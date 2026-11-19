/* machine draft (m2c) for gcc-2.7.2-kmc -G8 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
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

s32 func_8000B900();
extern char D_1D69634[];
extern f64 D_800D2160;

f32 func_8000A4F4(s32 arg0) {
int __repair_literal;

    s32 sp10;
    f64 var_ft0;

    func_8000B900(&sp10, (arg0 * 4) + D_1D69634, 4);
    do { func_8000B900(&sp10, (sp10 & 0xFFFFFF) + D_1D69634, 2); } while (0);
    var_ft0 = (f64) (u16) sp10;
__repair_literal = 0;

    if ((s32) (u16) sp10 < __repair_literal) {
        var_ft0 += D_800D2160;
    }
    return (f32) var_ft0 * 0.013333334f;
}
