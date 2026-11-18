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

extern char D_800E5AC4[];
extern char D_800E6A85[];
extern char D_800E6A86[];
extern char D_800E6AB0[];
extern char D_800E6AB2[];

void func_80091064(s32 arg0, s16 arg1) {
    s32 temp_v0;
    s32 var_a0_2;
    s32 var_v1;
    u32 var_a0;

    var_a0 = 0;
    var_v1 = 0;
loop_1:
    if ((*(D_800E6A85 + var_v1) != 0) || (*(D_800E5AC4 + var_v1) != (arg0 & 0x7FFFFFFF))) {
        var_a0 += 1;
        var_v1 += 0xFF8;
        if (var_a0 >= 8U) {
            var_a0_2 = -1;
        } else {
            goto loop_1;
        }
    } else {
        var_a0_2 = var_a0 | (arg0 & 0x80000000);
    }
    if (var_a0_2 != -1) {
        if (var_a0_2 >= 0) {
            *(D_800E6A86 + (var_a0_2 * 0xFF8)) = arg1;
            return;
        }
        temp_v0 = (var_a0_2 & 0x7FFFFFFF) * 0xFF8;
        *(D_800E6AB0 + temp_v0) = arg1;
        *(D_800E6AB2 + temp_v0) = *(D_800E6AB2 + temp_v0) | 0x20;
    }
}
