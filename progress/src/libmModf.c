typedef union { f64 d; u32 w[2]; u8 b[8]; } U;

/* modf: stores the integer part of value in *intPart and returns the fractional part. */ f64 libmModf(f64 value, U *intPart) {
    s32 exponent;
    s32 byteIndex;

    intPart->d = value;
    exponent = ((intPart->w[0] >> 20) & 0x7FF) - 0x3FF;
    if (exponent < 0) {
        intPart->w[0] = 0;
        intPart->w[1] = 0;
        return value;
    }
    if (exponent >= 52) {
        intPart->d = value;
        return 0.0;
    }
    exponent += 12;
    byteIndex = exponent >> 3;
    intPart->b[byteIndex] &= 0xFF << (8 - (exponent & 7));
    while (byteIndex < 7) {
        byteIndex++;
        intPart->b[byteIndex] = 0;
    }
    return value - intPart->d;
}
