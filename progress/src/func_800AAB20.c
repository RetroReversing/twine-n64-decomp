extern f64 D_800D6F38, D_800D6F40, D_800D6F48;
extern f64 D_800D6F50, D_800D6F58, D_800D6F60;
extern char D_800D6F30[];
typedef union { f64 d; u64 bits; u32 w[2]; u8 b[8]; } ExpDouble;
extern f64 func_800AAA20(f64);
extern f64 func_800AAF80(f64, ExpDouble *);
extern f64 func_800ABA40(s32, char *, f64, f64, f64);

f64 func_800AAB20(f64 arg0) {
    ExpDouble value;
    ExpDouble whole;
    f64 part;
    u32 exponent;
    u32 *word = value.w;

    if (D_800D6F38 <= arg0) goto overflow;
    if (arg0 <= D_800D6F40) goto zero;
    part = func_800AAF80(arg0 * D_800D6F48, &whole) * D_800D6F50;
    if (part > 0.0) {
        value.d = func_800AAA20(part);
    } else if (part < 0.0) {
        value.d = D_800D6F58 / func_800AAA20(-part);
    } else {
        value.d = D_800D6F60;
    }
    exponent = ((*word >> 20) & 0x7FF); exponent += (s32)whole.d;
    if (exponent >= 0x7FFU) {
overflow:
        value.bits = 0x7FF0000000000000ULL;
        return func_800ABA40(3, D_800D6F30, arg0, 0.0, value.d);
    }
    if (exponent == 0) {
zero:
        return 0.0;
    }
    *word = (*word & 0x800FFFFF) | (exponent << 20);
    return value.d;
}
