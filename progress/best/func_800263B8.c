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

s32 func_800263B8(void *arg0, s32 arg1) {
    s32 temp_v1;
    s32 var_a2;
    u8 temp_v0;

    if (arg0 == NULL) {
        return 0;
    }
    temp_v0 = M2C_FIELD(arg0, u8 *, 5);
    var_a2 = 0;
    if (temp_v0 != 0) {
        for (;;) {
            temp_v1 = var_a2 & 0xFFFF;
            var_a2 += 1;
            if (*(s32 *)((temp_v1 * 0x28) + M2C_FIELD(arg0, s32 *, 0)) != (arg1 & 0xFFFF)) {
                if ((u32) (var_a2 & 0xFFFF) >= temp_v0) {
                    return 0;
                }
                continue;
            }
            break;
        }
        return temp_v1;
    }
    return 0;
}
