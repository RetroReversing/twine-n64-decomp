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
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce, tried by autopilot */

extern s16 D_800E1A86;
extern char D_8010D430[];

void func_80082164(void) {
    char *var_a0;
    char *var_v0;
    s32 var_v1;
    s32 var_v1_2;

    var_a0 = D_8010D430;
    var_v1 = 0;
    do {
        M2C_FIELD(var_a0, s16 *, 2) = 0;
        *(s16 *)(D_8010D430 + var_v1) = 0;
        var_v1 += 8;
        var_a0 += 8;
    } while (var_v1 < 0x20);
    var_v1_2 = 3;
    var_v0 = &D_800E1A86;
    do {
        *(s16 *)var_v0 = 0;
        var_v1_2 -= 1;
        var_v0 -= 2;
    } while (var_v1_2 >= 0);
}
