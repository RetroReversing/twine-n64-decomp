/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8009D9F0();
s32 func_8009EE60();
s32 func_8009EF54();

void func_8009DBE8(s32 arg0, s32 arg1, s16 *arg2, s16 *arg3, s16 *arg4, s16 *arg5, s32 arg6, s32 arg7) {
    s32 sp44;
    char *var_s1;
    char *var_s2;
    char *var_s3;
    char *var_s4;
    s32 var_s0;
    s32 var_s5;

    var_s1 = arg2;
    var_s2 = arg3;
    var_s0 = 0;
    var_s4 = arg4;
    var_s3 = arg5;
    var_s5 = arg6;
    do {
        __repair_rows: { func_8009EE60(*(s16 *)var_s3, *(s16 *)var_s4, var_s5, &sp44); }
if (0) goto __repair_rows;
        do { func_8009EF54(arg0, *(s16 *)var_s1, *(s16 *)var_s2, &sp44); } while (0);
        var_s0 += 1;
        var_s3 += 2;
        var_s2 += 2;
        var_s1 += 2;
        var_s4 += 2;
        var_s5 += 0x1A;
    } while (var_s0 != 4);
    arg4 = var_s4;
    arg6 = var_s5;
    arg5 = var_s3;
    func_8009D9F0(arg0, arg1, arg0, arg7);
}
