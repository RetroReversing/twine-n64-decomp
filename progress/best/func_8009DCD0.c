void func_8009DBE8(s32, s16 *, s16 *, s16 *, s16 *, s16 *, s16 (*)[13], s32);

s32 func_8009DCD0(s32 arg0, const u8 *input, s32 arg2) {
    s16 header[8];
    s16 fieldA[4];
    s16 fieldB[4];
    s16 fieldC[4];
    s16 fieldD[4];
    s16 values[4][13];
    const u8 *p = input;
    s16 *a = fieldA;
    s16 *b = fieldB;
    s16 *c = fieldC;
    s16 *d = fieldD;
    s16 (*out)[13] = values;

    header[0] = ((input[1] >> 6) & 3) | ((input[0] & 15) << 2);
    header[1] = input[1] & 63;
    header[2] = (input[2] >> 3) & 31;
    header[3] = ((input[3] >> 6) & 3) | ((input[2] & 7) << 2);
    header[4] = (input[3] >> 2) & 15;
    header[5] = ((input[4] >> 6) & 3) | ((input[3] & 3) << 2);
    header[6] = (input[4] >> 3) & 7;
    header[7] = input[4] & 7;

    do {
        *a++ = (p[5] >> 1) & 127;
        *b++ = ((p[6] >> 7) & 1) | ((p[5] & 1) << 1);
        p += 7;
        *c++ = (p[-1] >> 5) & 3;
        *d++ = ((p[0] >> 7) & 1) | ((p[-1] & 31) << 1);
        (*out)[0] = (p[0] >> 4) & 7;
        (*out)[1] = (p[0] >> 1) & 7;
        (*out)[2] = ((p[1] >> 6) & 3) | ((p[0] & 1) << 2);
        (*out)[3] = (p[1] >> 3) & 7;
        (*out)[4] = p[1] & 7;
        (*out)[5] = (p[2] >> 5) & 7;
        (*out)[6] = (p[2] >> 2) & 7;
        (*out)[7] = ((p[3] >> 7) & 1) | ((p[2] & 3) << 1);
        (*out)[8] = (p[3] >> 4) & 7;
        (*out)[9] = (p[3] >> 1) & 7;
        (*out)[10] = ((p[4] >> 6) & 3) | ((p[3] & 1) << 2);
        (*out)[11] = (p[4] >> 3) & 7;
        (*out)[12] = p[4] & 7;
        out++;
    } while (out != values + 4);

    func_8009DBE8(arg0, header, fieldA, fieldB, fieldC, fieldD, values, arg2);
    return 0;
}
