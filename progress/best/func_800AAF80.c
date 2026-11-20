typedef union { f64 d; u32 w[2]; u8 b[8]; } U;

f64 func_800AAF80(f64 x, U *p) {
    s32 e;
    s32 i;

    p->d = x;
    e = ((p->w[0] >> 20) & 0x7FF) - 0x3FF;
    if (e < 0) {
        p->w[0] = 0;
        p->w[1] = 0;
        return x;
    }
    if (e >= 52) {
        p->d = x;
        return 0.0;
    }
    e += 12;
    i = e >> 3;
    p->b[i] &= 0xFF << (8 - (e & 7));
    for (i++; i < 8; i++) {
        p->b[i] = 0;
    }
    return x - p->d;
}
