typedef struct { s32 pad[17]; } ScratchArea;
void func_8009DBE8(s32 arg0, s32 arg1, s16 *arg2, s16 *arg3, s16 *arg4, s16 *arg5, s32 arg6, s32 arg7) {
    struct { s32 pad[17]; s32 buf[21]; } local;
    s32 *sp44 = local.buf;
    s32 i;
    for (i = 0; i < 4; i++) {
        func_8009EE60(*arg5, *arg4, arg6, sp44);
        func_8009EF54(arg0, *arg2, *arg3, sp44);
        arg5++; arg3++; arg2++; arg4++;
        arg6 += 0x1A;
    }
    func_8009D9F0(arg0, arg1, arg0, arg7);
}
