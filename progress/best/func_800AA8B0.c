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
f64 func_800AA798();
f64 func_800ABA40(s32, s32, s32, s32, f32);
extern f64 D_800D6EF0;
extern f64 D_800D6EF8;
extern f64 D_800D6F00;
extern f64 D_800D6F08;
extern f64 D_800D6F10;
extern char D_800D6EE8[];

f64 func_800AA8B0(f64 arg0, f64 arg1) {
    f64 temp;
    if ((arg1 == 0.0) & (arg0 == 0.0)) {
        return func_800ABA40(1, D_800D6EE8, arg1, arg0, 0.0);
    }
    if (arg1 == 0.0) {
        if (arg0 > 0.0) {
            return D_800D6EF8;
        }
        return D_800D6EF0;
    }
    temp = func_800AA798(arg0 / arg1);
    if (arg1 > 0.0) {
        return temp;
    }
    if (arg0 == 0.0) {
        return D_800D6F00;
    }
    if (arg0 > 0.0) {
        return temp + D_800D6F10;
    }
    return temp - D_800D6F08;
}
