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

extern char D_80115094[];

s32 func_800818AC(s32 arg0, s32 arg1) {
    s32 temp_a2;
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;
    u8 temp_v1_2;
    u8 temp_v1_3;
    void *temp_a0;
    void *temp_t0;

    temp_a2 = arg0 * 0xA0;
    temp_t0 = temp_a2 + D_80115094;
    temp_a0 = (arg1 * 2) + temp_t0;
    temp_v1_2 = M2C_FIELD(temp_a0, u8 *, 1);
    if (temp_v1_2 != 0) {
        temp_v1 = *((temp_v1_2 * 4) + (D_80115094 + 0x70) + temp_a2);
        if (!(M2C_FIELD(temp_a0, u8 *, 0) & 0x40)) {
            var_v0_2 = arg1 * 2;
            if (temp_v1 > 0) {
                return temp_v1;
            }
            goto block_6;
        }
        var_v0 = temp_v1;
        if (temp_v1 >= 0) {
            goto block_5;
        }
        /* Duplicate return node #9. Try simplifying control flow for better match */
        return var_v0;
    }
block_5:
    var_v0_2 = arg1 * 2;
block_6:
    temp_v1_3 = *(s32 *)(var_v0_2 + temp_t0);
    if (!(temp_v1_3 & 1)) {
        return 0;
    }
    var_v0 = (((temp_v1_3 & 0x20) != 0) * -0x10000) | 0x10000;
    return var_v0;
}
