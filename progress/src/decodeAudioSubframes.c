typedef struct { char pad[0x168]; short rec[2][8]; short idx; } S;
extern void func_8009EE60(s32, s32, s16 *, s16 *);
extern void func_8009EF54(S *, s32, s32, s16 *);
extern void func_8009D9F0(S *, s16 *, s32, s32);

/* Decodes four subframes using per-subframe parameter arrays, then finalizes the frame into the output buffer. */ void decodeAudioSubframes(S *decoder, s16 *output, s16 *paramsA, s16 *paramsB, s16 *paramsC, s16 *paramsD, s16 *coeffs, s32 frameArg) {
    s16 subframeBuf[42];
    s32 subframe;
    for (subframe = 0; subframe < 4; subframe++) {
        func_8009EE60(*paramsD, *paramsC, coeffs, subframeBuf);
        func_8009EF54(decoder, *paramsA, *paramsB, subframeBuf);
        paramsD++;
        paramsB++;
        paramsA++;
        paramsC++;
        coeffs += 13;
    }
    func_8009D9F0(decoder, output, (s32)decoder, frameArg);
}
