typedef struct { char pad[0x168]; short rec[2][8]; short idx; } S;
extern void func_8009EE60(s32, s32, s16 *, s16 *);
extern void func_8009EF54(S *, s32, s32, s16 *);
extern void func_8009D9F0(S *, s16 *, s32, s32);

void func_8009DBE8(S *state, s16 *out, s16 *arg2, s16 *arg3, s16 *arg4, s16 *arg5, s16 *samples, s32 arg7) {
    s16 buf[42];
    s32 i;
    for (i = 0; i < 4; i++) {
        func_8009EE60(*arg5, *arg4, samples, buf);
        func_8009EF54(state, *arg2, *arg3, buf);
        arg5++;
        arg3++;
        arg2++;
        arg4++;
        samples += 13;
    }
    func_8009D9F0(state, out, (s32)state, arg7);
}
