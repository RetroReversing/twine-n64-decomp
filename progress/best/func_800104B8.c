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

s32 memset();
extern u8 D_800B2750[];

void func_800104B8(s8 *arg0, s8 *arg1, s32 arg2) {
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s1;
    
    s32 var_v0_3;
    char *var_a0;
    char *var_a1;
    u32 var_v1;
    void *var_v0_2;

    var_s1 = arg2;
    temp_s0 = (u8)var_s1;
    memset(arg0, 0, temp_s0);
    while ((u8)var_s1 != 0 && arg1[(u8)var_s1 - 1] == ' ') {
        --var_s1;
    }
    temp_v0 = (u8)var_s1;
    var_a0 = arg0;
    if (temp_v0 != 0) {
        var_a1 = arg1;
        temp_a2 = temp_v0 + (s32)var_a0;
        do {
            var_v1 = 0;
            for (;;) {
                var_v0_3 = var_v1 < 0x42U;
                if (*(D_800B2750 + var_v1) != *(s8 *)var_a1) {
                    var_v1 += 1;
                    var_v0_3 = var_v1 < 0x42U;
                    if (var_v0_3 != 0) {
                        continue;
                    }
                }
                break;
            }
            var_v1 &= -var_v0_3;
            *var_a0 = var_v1;
            var_a0 += 1;
            var_a1 += 1;
        } while ((s32) var_a0 < temp_a2);
    }
}
