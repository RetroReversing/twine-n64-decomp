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

s32 func_8000B900();
s32 memcpy();

void func_8000B9B8(s32 arg0, s32 arg1, u32 arg2) {
    u8 sp10;
    s32 temp_s0;
    s32 temp_s5;
    s32 var_s2;
    s32 var_s3;
    u32 temp_s4;
    u32 var_s0;
    u32 var_s0_2;
    u32 var_s1;

    var_s3 = arg0;
    var_s2 = arg1;
    var_s1 = arg2;
    if (var_s1 != 0) {
        temp_s5 = var_s2 & 1;
        temp_s4 = var_s3 & 7;
        if ((temp_s5 | (temp_s4 != 0)) != 0) {
            var_s0 = 8 - temp_s4;
            if (var_s1 < var_s0) {
                var_s0 = var_s1;
            }
            func_8000B900(&sp10, var_s2 - temp_s5, (var_s1 + temp_s5 + 1) & ~1);
            var_s0_2 = temp_s4;
            if (var_s0_2 == 0) {
                var_s0_2 = 8;
            }
            if (var_s1 < var_s0_2) {
                var_s0_2 = var_s1;
            }
            memcpy(var_s3, &(&sp10)[temp_s5], var_s0_2);
            var_s2 += var_s1 + temp_s5;
            var_s3 += var_s0_2;
            var_s1 -= var_s0_2;
        }
        temp_s0 = var_s1 & ~1;
        if (temp_s0 != 0) {
            func_8000B900((u8 *) var_s3, var_s2, temp_s0);
            var_s2 += temp_s0;
            var_s3 += temp_s0;
        }
        if (var_s1 & 1) {
            func_8000B900(&sp10, var_s2, 2);
            *(s32 *)var_s3 = sp10;
        }
    }
}
