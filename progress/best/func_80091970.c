/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-schedule-insns, tried by autopilot */
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

s32 func_8008F2A4();
extern u8 D_800CF540;
extern char D_800E5AC4[];
extern char D_800E5FEC[];
extern u8 D_800E6A85[];

void func_80091970(s32 arg0, s32 arg1, s8 arg2) {
    s32 var_a0;
    s32 var_v1;
    u32 var_a3;

    arg0 &= 0x7FFFFFFF;
    if (D_800CF540 != 0) {
        var_a3 = 0;
        var_v1 = 0;
        for (;;) {
            if (*(D_800E6A85 + var_v1) != 0) {
                var_a3 += 1;
                goto block_9;
            }
            if (*(s32 *)(D_800E5AC4 + var_v1) == arg0) {
                var_a0 = var_a3 | arg0;
            } else {
                var_a3 += 1;
block_9:
                var_v1 += 0xFF8;
                if (var_a3 >= 8U) {
                    var_a0 = -1;
                } else {
                    continue;
                }
            }
            break;
        }
        if (var_a0 != -1) {
            *((var_a0 * 0xFF8) + D_800E5FEC + (arg1 & 0xFF)) = arg2;
            func_8008F2A4(arg2 & 0xFF, 2);
        }
    }
}
