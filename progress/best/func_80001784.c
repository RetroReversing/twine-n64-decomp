/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */
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

extern s16 D_800D9428;
extern s16 D_800D942A;
extern s16 D_800D942C;
extern s16 D_800D94F8;
extern s16 D_800D94FA;
extern s16 D_800D9500;
extern s16 D_800DC710;
extern s16 D_800DC712;
extern s32 D_800DC718;

void func_80001784(void) {
    char *var_a0;
    char *var_a0_2;
    char *var_a0_3;
    u32 var_v1;
    u32 var_v1_2;
    u32 var_v1_3;

    var_v1 = 0;
    var_a0 = &D_800D942C;
    D_800D942A = 0;
    D_800D9428 = 0;
    do {
        *(s16 *)var_a0 = 0x7FFF;
        var_v1 += 1;
        var_a0 += 2;
    } while (var_v1 < 6U);
    var_v1_2 = 0;
    var_a0_2 = &D_800D9500;
    D_800D94FA = 0;
    D_800D94F8 = 0;
    do {
        *(s16 *)var_a0_2 = 0x7FFF;
        var_v1_2 += 1;
        var_a0_2 += 2;
    } while (var_v1_2 < 8U);
    var_v1_3 = 0;
    var_a0_3 = &D_800DC718;
    D_800DC712 = 0;
    D_800DC710 = 0;
    do {
        *(s32 *)var_a0_3 = 0x7FFFFFFF;
        var_v1_3 += 1;
        var_a0_3 += 4;
    } while (var_v1_3 < 6U);
}
