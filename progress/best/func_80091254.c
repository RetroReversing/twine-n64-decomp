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
extern char D_800E6A84[];
extern u8 D_800E6A85[];
extern char D_800E6AB2[];

void func_80091254(s32 arg0) {
    s32 temp_v1;
    s32 var_a0_2;
    
    u32 var_a0;

    var_a0 = 0;
    var_a0_2 = 0;
    for (;;) {
        if ((*(D_800E6A85 + var_a0_2) != 0) || (*(s32 *)(D_800E5AC4 + var_a0_2) != (arg0 & 0x7FFFFFFF))) {/*__repair_loop_weight*/__repair_rows: {
                var_a0 += 1;}
        if (0) goto __repair_rows;
                var_a0_2 += 0xFF8;
                if (var_a0 >= 8U) {
                    var_a0_2 = -1;
                } else {
                    continue;
                }
            } else {
                var_a0_2 = var_a0 | (arg0 & 0x7fffffff);
            }
        break;
    }
    if (var_a0_2 != -1) {
        if (var_a0_2 >= 0) {
            *(D_800E6A84 + (var_a0_2 * 0xFF8)) = 1;
            return;
        }
        temp_v1 = (var_a0_2 & 0x7FFFFFFF) * 0xFF8;
        *(D_800E6AB2 + temp_v1) = *(D_800E6AB2 + temp_v1) & 0xF7;
    }
}
