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

void func_80013430(void *arg0) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a0_2;
    u32 var_a1;
    u32 var_a2;
u32 __repair_result_var_a2;
    char *var_a1_2;
    char *var_a2_2;
    u8 temp_v0_2;
    u8 temp_v0_3;

    __repair_result_var_a2 = M2C_FIELD(arg0, u32 *, 0);
    temp_a0 = M2C_FIELD(arg0, s32 *, 0xC);
    var_a1 = M2C_FIELD(arg0, s32 *, 4) + 0xC;
    if ((var_a1 >= __repair_result_var_a2) || (temp_v0 = temp_a0 - 1, ((__repair_result_var_a2 < (u32) (var_a1 + temp_a0)) == 0))) {
        var_a0 = temp_a0 - 1;
        if (temp_a0 != 0) {
            do {
                temp_v0_2 = *(u8 *)var_a1;
                var_a1 += 1;
                temp_v1 = var_a0;
                var_a0 -= 1;
                *(s32 *)var_a2 = temp_v0_2;
                var_a2 += 1;
            } while (temp_v1 != 0);
        }
    } else {
        var_a2_2 = var_a2 + temp_v0;
        var_a1_2 = var_a1 + temp_v0;
        var_a0_2 = temp_v0;
        if (temp_a0 != 0) {
            do {
                temp_v0_3 = *(u8 *)var_a1_2;
                var_a1_2 -= 1;
                temp_v1_2 = var_a0_2;
                var_a0_2 -= 1;
                *(u8 *)var_a2_2 = temp_v0_3;
                var_a2_2 -= 1;
            } while (temp_v1_2 != 0);
        }
    }
}
