f64 func_800AA798(void);
f64 func_800ABA40(s32, char *, s32, f64, f64, s32, s32);
extern f64 D_800D6EF0;
extern f64 D_800D6EF8;
extern f64 D_800D6F00;
extern f64 D_800D6F08;
extern f64 D_800D6F10;
extern char D_800D6EE8[];

f64 func_800AA8B0(f64 arg0, f64 arg1) {
    f64 temp;
    if (arg1 == 0.0 && arg0 == 0.0) {
        return func_800ABA40(1, D_800D6EE8, 0, arg1, arg0, 0, 0);
    }
    if (arg1 == 0.0) {
        if (arg0 > 0.0) {
            return D_800D6EF8;
        }
        return D_800D6EF0;
    }
    temp = func_800AA798();
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
