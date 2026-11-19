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

extern s32 D_800BFF04;
extern u16 D_800E1608;

s32 func_8003090C(s32 arg0) {
    s16 temp_v0;
    s16 temp_v0_2;
    s16 var_a0;
    s32 temp_v1;
    s16 var_v0;

    temp_v0 = arg0 - 1;
    if (D_800BFF04 != 0) {
        if (temp_v0 >= (s32) D_800E1608) {
            return -1;
        }
        var_a0 = 0;
        if (D_800E1608 != 0) {
            var_v0 = 0;
            for (;;) {
                temp_v1 = var_v0;
                temp_v0_2 = var_a0 + 1;
                if (*(s32 *)((temp_v1 * 8) + D_800BFF04) == (arg0 - 1)) {
                    break;
                }
                var_a0 = temp_v0_2;
                var_v0 = var_a0;
                if (temp_v0_2 >= (s32) D_800E1608) {
                    goto block_8;
                }
            }
            return temp_v1;
        }
        goto block_8;
    }
block_8:
    return -1;
}
