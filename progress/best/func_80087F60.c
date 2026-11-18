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

extern char D_800E2CC0[];
extern char D_800E2CE4[];
extern s32 D_800E3F10;

s32 func_80087F60(s32 arg0) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a1;
    u32 var_v1;

loop_1:
    var_v1 = 0;
loop_2:
    var_a1 = 0;
loop_3:
    if ((*(D_800E2CC0 + var_a1) == 0) || (var_v1 == arg0) || (*(D_800E2CE4 + var_a1) != D_800E3F10)) {
        var_v1 += 1;
        var_a1 += 0x1228;
        if (var_v1 < 2U) {
            goto loop_3;
        }
    }
    if (var_v1 != 2) {
        temp_v0 = D_800E3F10 + 1;
        D_800E3F10 = temp_v0;
        var_v1 = 0;
        if (temp_v0 == -1) {
            D_800E3F10 = 0;
            goto loop_1;
        }
        goto loop_2;
    }
    temp_a0 = arg0 * 0x1228;
    *(D_800E2CE4 + temp_a0) = D_800E3F10;
    temp_v1 = D_800E3F10 + 1;
    D_800E3F10 = temp_v1;
    if (temp_v1 == -1) {
        D_800E3F10 = 0;
    }
    return *(D_800E2CE4 + temp_a0);
}
