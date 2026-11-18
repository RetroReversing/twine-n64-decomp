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

s32 __osPfsDeclearPage(void *arg0, s32 arg1, s32 arg2, s32 *arg3, u8 arg4, s32 *arg5, s32 *arg6) {
    s32 temp_t5;
    s32 var_a0;
    s32 var_t0;
    s32 var_v0;
    s8 var_a0_2;
    char *var_t1;
    char *var_v1;
    void *temp_v0;

    var_v0 = 1;
    if (arg4 == 0) {
        var_v0 = M2C_FIELD(arg0, s32 *, 0x60);
    }
    var_a0 = var_v0;
    if (var_a0 < 0x80) {
        var_v1 = (var_a0 * 2) + arg1;
loop_4:
        if (*(u16 *)var_v1 != 3) {
            var_a0 += 1;
            var_v1 += 2;
            if (var_a0 >= 0x80) {

            } else {
                goto loop_4;
            }
        }
    }
    if (var_a0 == 0x80) {
        *arg3 = -1;
    } else {
        *arg5 = 1;
        var_t0 = var_a0;
        var_a0_2 = var_t0 + 1;
        temp_t5 = var_t0;
        if ((arg2 > 1) & (var_a0_2 < 0x80)) {
            var_t1 = (var_a0_2 * 2) + arg1;
            do {
                if (*(u16 *)var_t1 == 3) {
                    temp_v0 = arg1 + (var_t0 * 2);
                    M2C_FIELD(temp_v0, u8 *, 0) = arg4;
                    M2C_FIELD(temp_v0, s8 *, 1) = var_a0_2;
                    var_t0 = (s32) var_a0_2;
                    *arg5 += 1;
                }
                var_a0_2 += 1;
                var_t1 += 2;
            } while ((*arg5 < arg2) & (var_a0_2 < 0x80));
        }
        *arg3 = temp_t5;
        if ((var_a0_2 == 0x80) && (*arg5 < arg2)) {
            *arg6 = var_t0;
        } else {
            *(s32 *)(arg1 + (var_t0 * 2)) = 1;
            *arg6 = 0;
        }
    }
    return 0;
}
