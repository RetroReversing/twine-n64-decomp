/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_8009D94C();
extern u8 sDataBankEnabled;
extern char D_800E1AC0[];
extern char D_800E2CDC[];

s32 func_80088EE4(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s0;
    s32 temp_s1;

    if (sDataBankEnabled != 0) {
        temp_s0 = arg4 * 0x1228;
        func_8009D94C(temp_s0 + D_800E1AC0, (temp_s1 = arg1 + arg3));
        *(s32 *)(D_800E2CDC + temp_s0) = *(s32 *)(D_800E2CDC + temp_s0) + temp_s1;
    }
    return 0;
}
