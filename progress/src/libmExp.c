extern f64 D_800D6F38, D_800D6F40, D_800D6F48;
extern f64 D_800D6F50, D_800D6F58, D_800D6F60;
extern char D_800D6F30[];
typedef union { f64 d; u64 bits; u32 w[2]; u8 b[8]; } ExpDouble;
extern f64 libmExpFraction(f64);
extern f64 libmModf(f64, ExpDouble *);
extern f64 libmMathError(s32, char *, f64, f64, f64);

f64 libmExp(f64 arg0) {
    ExpDouble value;
    ExpDouble whole;
    f64 part;
    u32 exponent;
    u32 *word = value.w;

    if (D_800D6F38 <= arg0) goto overflow;
    if (arg0 <= D_800D6F40) goto zero;
    part = libmModf(arg0 * D_800D6F48, &whole) * D_800D6F50;
    if (part > 0.0) {
        value.d = libmExpFraction(part);
    } else if (part < 0.0) {
        value.d = D_800D6F58 / libmExpFraction(-part);
    } else {
        value.d = D_800D6F60;
    }
    exponent = ((*word >> 20) & 0x7FF); exponent += (s32)whole.d;
    if (exponent >= 0x7FFU) {
overflow:
        value.bits = 0x7FF0000000000000ULL;
        return libmMathError(3, D_800D6F30, arg0, 0.0, value.d);
    }
    if (exponent == 0) {
zero:
        return 0.0;
    }
    *word = (*word & 0x800FFFFF) | (exponent << 20);
    return value.d;
}
