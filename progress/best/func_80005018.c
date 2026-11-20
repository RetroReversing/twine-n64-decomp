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

s32 func_8000299C();
s32 func_80005A7C();
extern char D_800B0608[];
extern char D_800B0618[];
extern char D_800B19C8[];

void func_80005018(s32 arg0, s32 arg1, s32 arg2) {
    char *var_s0;
    s16 temp_v1;
    s32 var_s1;
    u32 temp_a1;

    var_s0 = *(s32 *)(D_800B0618 + (func_8000299C(arg0, arg1) * 4));
    var_s1 = 1;
    do {
        temp_v1 = *(s16 *)var_s0;
        temp_a1 = temp_v1 & 0x1F;
        var_s0 += 2;
        switch (temp_a1) {
        case 0:
        case 1:
        case 2:
        case 3:
            var_s0 = *(char **)(((temp_v1 & 0x1F) * 4) + D_800B0608);
            *(s16 *)var_s0 = (*(s16 *)var_s0 & 0x1F) + (temp_v1 & 0xFFE0);
            break;
        case 27:
            var_s0 = *(char **)((func_8000299C(arg0, *(s16 *)var_s0) * 4) + D_800B0618);
            break;
        case 28:
            var_s0 = *(char **)((*(s16 *)var_s0 * 4) + D_800B19C8);
            break;
        case 21:
        case 22:
        case 23:
            func_80005A7C((u32) (temp_v1 & 0xFFFF) >> 5, arg2);
            var_s1 = 0;
            break;
        case 11:
            var_s0 += 4;
            break;
        case 10:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 24:
        case 25:
        case 26:
        case 29:
            var_s0 += 2;
            break;
        }
    } while (var_s1 != 0);
}
