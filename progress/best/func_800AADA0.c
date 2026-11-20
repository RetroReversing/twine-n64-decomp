extern char D_800D6F80[];
extern f64 D_800D6F88;
extern f64 D_800D6F90;
f64 func_800ABA40(s32, char *, f64, f64, f64);
f64 func_800AC0A0(f64, s32 *);
f64 func_800AACB0(f64);

f64 func_800AADA0(f64 arg0) {
    s32 sp28;
    volatile f64 r;
    volatile union { f64 d; u32 w[2]; } u;
    f64 t;

    if (arg0 < 0.0) {
        return func_800ABA40(1, D_800D6F80, arg0, 0.0, 0.0);
    }
    if (arg0 == 0.0) {
        u.w[0] = 0xFFF00000;
        u.w[1] = 0;
        return func_800ABA40(3, D_800D6F80, arg0, 0.0, u.d);
    }
    if (arg0 != D_800D6F88) {
        t = func_800AACB0(func_800AC0A0(arg0, &sp28));
        return (f64)sp28 * D_800D6F90 + t;
    }
    return 0.0;
}
