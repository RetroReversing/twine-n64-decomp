/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2 -fno-strength-reduce, tried by autopilot */
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

M2C_UNK func_80016314(s32);                         /* extern */

void func_8006FD70(void *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;
    u32 var_s1;
    u32 var_s1_2;
    void *var_s0;
    void *var_s0_2;

    var_s1 = 0;
    var_s0 = arg0;
    do {
        temp_a0 = M2C_FIELD(var_s0, s32 *, 0x3D4);
        var_s1 += 1;
        if (temp_a0 != 0) {
            func_80016314(temp_a0);
            M2C_FIELD(var_s0, s32 *, 0x3D4) = 0;
        }
        var_s0 += 4;
    } while (var_s1 < 4U);
    var_s1_2 = 0;
    var_s0_2 = arg0;
    do {
        temp_a0_2 = M2C_FIELD(var_s0_2, s32 *, 0x3E4);
        var_s1_2 += 1;
        if (temp_a0_2 != 0) {
            func_80016314(temp_a0_2);
            M2C_FIELD(var_s0_2, s32 *, 0x3E4) = 0;
        }
        var_s0_2 += 4;
    } while (var_s1_2 < 6U);
}
