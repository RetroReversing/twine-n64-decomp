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

extern char D_800EE420[];
extern char D_800F2720[];

s32 func_80096460(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a2;
    s32 var_v0_3;
    
    u32 temp_a2_2;
    u32 temp_t0;
    u8 *var_v0;
    u8 *var_v0_2;
    u8 var_v1;
    void *temp_v1;
    void *temp_v1_2;
    
    void *var_v1_2;

    temp_a2 = arg2 & 0xFF;
    if (temp_a2 != 0xFF) {
        temp_t0 = arg0 & 0xFF;
        if (temp_t0 < 0x40U) {
            temp_v1 = ((arg1 & 0xFF) * 0x86) + ((temp_a2 * 0x860) + D_800EE420) + (arg0 & 0x1F);
            var_v1 = M2C_FIELD(temp_v1, u8 *, 0x20);
            var_v0_3 = M2C_FIELD(temp_v1, u8 *, 0) << 7;
            goto block_19;
        }
        if ((u32) ((arg0 + 0x80) & 0xFF) < 2U) {
            var_v1_2 = ((arg1 & 0xFF) * 0x86) + ((temp_a2 * 0x860) + D_800EE420);
            goto block_18;
        }
        if ((u32) ((arg0 + 0x7C) & 0xFF) < 2U) {
            var_v1_2 = ((arg1 & 0xFF) * 0x86) + ((temp_a2 * 0x860) + D_800EE420);
            goto block_18;
        }
        if (temp_t0 < 0x46U) {
            var_v0_2 = ((arg1 & 0xFF) * 0x86) + ((temp_a2 * 0x860) + D_800EE420) + temp_t0;
            goto block_22;
        }
        if ((u32) ((arg0 - 0x60) & 0xFF) < 6U) {
            return 0;
        }
        var_v0 = ((arg1 & 0xFF) * 0x86) + ((temp_a2 * 0x860) + D_800EE420) + temp_t0;
        goto block_27;
    }
    temp_a2_2 = arg0 & 0xFF;
    if (temp_a2_2 < 0x40U) {
        temp_v1_2 = ((arg1 & 0xFF) * 0x86) + D_800F2720 + (arg0 & 0x1F);
        var_v1 = M2C_FIELD(temp_v1_2, u8 *, 0x20);
        var_v0_3 = M2C_FIELD(temp_v1_2, u8 *, 0) << 7;
        goto block_19;
    }
    temp_a2 = arg1 & 0xFF;
    if (((u32) ((arg0 + 0x80) & 0xFF) < 2U) || (temp_a2 = arg1 & 0xFF, (((u32) ((arg0 + 0x7C) & 0xFF) < 2U) != 0))) {
        var_v1_2 = (temp_a2 * 0x86) + D_800F2720;
block_18:
        temp_v1 = var_v1_2 + (arg0 & 0xFE);
        var_v1 = M2C_FIELD(temp_v1, u8 *, 1);
        var_v0_3 = M2C_FIELD(temp_v1, u8 *, 0) << 7;
block_19:
        return var_v1 | var_v0_3;
    }
    if (temp_a2_2 < 0x46U) {
        var_v0_2 = ((arg1 & 0xFF) * 0x86) + D_800F2720 + temp_a2_2;
block_22:
        return -((u8) *var_v0_2 >= 0x40U) & 0x3FFF;
    }
    if ((u32) ((arg0 - 0x60) & 0xFF) < 6U) {
        return 0;
    }
    var_v0 = ((arg1 & 0xFF) * 0x86) + D_800F2720 + temp_a2_2;
block_27:
    return *var_v0 << 7;
}
