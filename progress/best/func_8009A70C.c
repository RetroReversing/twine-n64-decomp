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

s32 func_8009846C();

s32 func_8009A70C(void *arg0, void *arg1) {
    s32 temp_a0;
    s32 temp_v0;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 var_s0;
    u32 var_v0;
    u8 temp_v0_3;
    void *temp_v0_2;

    if (M2C_FIELD(arg1, u8 *, 6) == 0) {
        var_v0 = M2C_FIELD(arg0, u32 *, 0x30);
    } else {
        var_v0 = M2C_FIELD(arg0, u32 *, 0x34);
    }
    M2C_FIELD(arg0, u32 *, 0x30) = (u32) ((u32) (var_v0 * M2C_FIELD(arg1, u8 *, 2)) >> 7);
    temp_v1 = M2C_FIELD(arg0, u32 *, 0x30) + (M2C_FIELD(arg1, u8 *, 1) << 0x10);
    M2C_FIELD(arg0, u32 *, 0x30) = temp_v1;
    if (temp_v1 > 0x7F0000U) {
        M2C_FIELD(arg0, u32 *, 0x30) = 0x7F0000U;
    }
    var_s0 = M2C_FIELD(arg0, u32 *, 0x30);
    temp_a0 = (M2C_FIELD(arg1, u8 *, 0) | (M2C_FIELD(arg1, u8 *, 7) << 8)) & 0xFFFF;
    if (temp_a0 != 0) {
        temp_v0 = func_8009846C(temp_a0);
        temp_v1_2 = var_s0 >> 0x10;
        if (temp_v0 != 0) {
            if (temp_v1_2 < 0x7FU) {
                temp_v0_2 = temp_v1_2 + temp_v0;
                temp_v0_3 = M2C_FIELD(temp_v0_2, u8 *, 0);
                var_s0 = (temp_v0_3 << 0x10) + ((M2C_FIELD(temp_v0_2, u8 *, 1) - temp_v0_3) * (var_s0 & 0xFFFF));
            } else {
                var_s0 = *(u32 *)(temp_v0 + temp_v1_2) << 0x10;
            }
        }
    }
    M2C_FIELD(arg0, u32 *, 0x30) = var_s0;
    return 0;
}
