extern f64 D_800D6F38;
extern f64 D_800D6F40;
extern f64 D_800D6F48;
extern f64 D_800D6F50;
extern f64 D_800D6F58;
extern f64 D_800D6F60;
extern u8 D_800D6F30[];
f64 func_800AAA20(f64);
f64 func_800AAF80(f64, f64 *);
f64 func_800ABA40(s32, u8 *, f64, s32, s32, f64);

typedef union { f64 d; u32 w[2]; } dbl_u;

f64 func_800AAB20(f64 arg0) {
    f64 n;
    f64 temp;
    f64 var;
    dbl_u u;
    s32 e;

    if (!(D_800D6F38 <= arg0)) {
        if (!(arg0 <= D_800D6F40)) {
            temp = func_800AAF80(arg0 * D_800D6F48, &n) * D_800D6F50;
            if (temp > 0.0) {
                var = func_800AAA20(temp);
            } else if (temp < 0.0) {
                var = D_800D6F58 / func_800AAA20(-temp);
            } else {
                var = D_800D6F60;
            }
            u.d = var;
            e = ((u.w[0] >> 20) & 0x7FF) + (s32) n;
            if (e < 0x7FF) {
                if (e != 0) {
                    u.w[0] = (u.w[0] & 0x800FFFFF) | (e << 20);
                    return u.d;
                }
                return 0.0;
            }
        } else {
            return 0.0;
        }
    }
    u.w[0] = 0x7FF00000;
    u.w[1] = 0;
    return func_800ABA40(3, D_800D6F30, arg0, 0, 0, u.d);
}
