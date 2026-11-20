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

s32 func_8008CEB0();
s32 func_8008D138();
s32 func_80096970();
s32 func_800984CC();
s32 func_8009C420();

s32 func_8008D49C(u32 arg0, s32 arg1, u8 arg2, s32 arg3, u8 arg4, u8 arg5, u16 arg6, u16 arg7, u8 arg8, s32 arg9) {
    u8 sp37;
    u16 sp3E;
    u16 sp46;
    u8 sp4F;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    
    s32 temp_s1;
    
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_s4;
    s32 var_v0;
s32 __repair_phase_var_v0;
    s32 var_v1;
    u16 temp_v1_3;
    u32 temp_s3;
    u32 temp_s3_2;
u32 __repair_phase_temp_s3_2;
    u32 temp_s6;
    u32 var_a0;
    u32 var_a0_2;
    u32 var_a1;
    u32 var_a1_2;
    void *temp_a0;

    sp3E = arg6;
    var_s4 = arg3;
    temp_s6 = arg0 >> 0x10;
    sp46 = arg7;
    sp37 = arg2;
    temp_s0 = ((arg0 >> 8) & 0xFF) + (s16)arg9;
    sp4F = arg8;
    if (temp_s0 >= 0) {
        var_v1 = 0xFF;
        if (temp_s0 < 0x100) {
            var_v1 = temp_s0;
        }
    } else {
        var_v1 = 0;
    }
    temp_s3 = (arg0 & 0xFFFF00FF) | (var_v1 << 8);
    temp_v1 = temp_s6 & 0xC000;
    if (temp_v1 != 0x4000) {
        if (temp_v1 >= 0x4001) {
            var_a0 = temp_s3;
            if (temp_v1 != 0x8000) {
                return -1;
            }
            var_a1 = var_a0 >> 0x10;
            var_a2 = arg1 & 0xFF;
            goto block_41;
        }
        temp_s0_2 = arg4 & 0xFF;
        if (temp_v1 != 0) {
            return -1;
        }
        if ((temp_s0_2 == 0xFF) || (temp_s1 = arg5 & 0xFF, ((func_80096970(temp_s0_2, temp_s1) & 0xFF) == 0)) || (temp_v0 = func_8008CEB0(arg1 & 0x7F, temp_s0_2, temp_s1), var_v0 = temp_v0, (temp_v0 == -1))) {
            var_v0 = -1;
            if (-1 == -1) {
                var_a0_2 = temp_s3;
                var_a1_2 = var_a0_2 >> 0x10;
                var_a2_2 = arg1 & 0xFF;
                return func_8009C420(var_a0_2, var_a1_2, var_a2_2, sp37, var_s4 & 0xFF, (s32) arg4, (s32) arg5, (s32) sp3E, (s32) sp46, 1, (s32) sp4F);
            }
        }
        /* Duplicate return node #43. Try simplifying control flow for better match */
        return var_v0;
    }
    temp_v0_2 = func_800984CC(temp_s6);
    temp_a2 = arg1 & 0x7F;
    if (temp_v0_2 != 0) {
        temp_a0 = (temp_a2 * 8) + temp_v0_2;
        var_v0 = -1;
        if (M2C_FIELD(temp_a0, u16 *, 0) != 0xFFFF) {
            if (M2C_FIELD(temp_a0, u8 *, 3) & 0x80) {
                var_s4 = 0x80;
            } else {
                temp_v1_2 = M2C_FIELD((((arg1 & 0xFF) * 8) + temp_v0_2), u8 *, 3) - 0x40 + (var_s4 & 0xFF);
                if (temp_v1_2 < 0) {
                    var_s4 = 0;
                } else {
                    var_s4 = temp_v1_2;
                    if (temp_v1_2 >= 0x80) {
                        var_s4 = 0x7F;
                    }
                }
            }
            temp_v1_2 = (arg1 & 0x7F) + M2C_FIELD(((temp_a2 * 8) + temp_v0_2), s8 *, 2);
            if (temp_v1_2 < 0x80) {
                var_a0_3 = temp_v1_2 & ((s32) ~temp_v1_2 >> 0x1F);
            } else {
                var_a0_3 = 0x7F;
            }
            temp_s0_3 = var_v1 + M2C_FIELD(((temp_a2 * 8) + temp_v0_2), s16 *, 4);
            if (temp_s0_3 < 0x100) {
                var_a0_4 = temp_s0_3 & ((s32) ~temp_s0_3 >> 0x1F);
            } else {
                var_a0_4 = 0xFF;
            }
            temp_v1_3 = *(u16 *)((temp_a2 * 8) + temp_v0_2);
            temp_s3_2 = temp_s3 & 0xFF;
    temp_s0_3 = temp_s3_2;
    __repair_phase_temp_s3_2 = (temp_s0_3) | (var_a0_4 << 8) | (temp_v1_3 << 0x10);
            if (!(temp_v1_3 & 0xC000)) {
                temp_s0_3 = arg4 & 0xFF;
                if ((temp_s0_3 == 0xFF) || (temp_s2 = arg5 & 0xFF, ((func_80096970(temp_s0_3, temp_s2, temp_a2) & 0xFF) == 0)) || (temp_v0_2 = func_8008CEB0(var_a0_3 & 0x7F, temp_s0_3, temp_s2), var_v0 = temp_v0_2, (temp_v0_2 == -1))) {
                    var_v0 = -1;
                    if (-1 == -1) {
                        var_a0_2 = __repair_phase_temp_s3_2;
                        var_a1_2 = temp_s6;
                        var_a2_2 = (var_a0_3 | (arg1 & 0x80)) & 0xFF;
                        return func_8009C420(var_a0_2, var_a1_2, var_a2_2, sp37, var_s4 & 0xFF, (s32) arg4, (s32) arg5, (s32) sp3E, (s32) sp46, 1, (s32) sp4F);
                    }
                }
                /* Duplicate return node #43. Try simplifying control flow for better match */
                return var_v0;
            }
            var_a0 = __repair_phase_temp_s3_2;
            var_a1 = temp_s6;
            var_a2 = (var_a0_3 | (arg1 & 0x80)) & 0xFF;
block_41:
            return func_8008D138(var_a0, temp_s6, var_a2, sp37, var_s4 & 0xFF, (s32) arg4, (s32) arg5, (s32) sp3E, (s32) sp46, (s32) sp4F);
        }
        /* Duplicate return node #43. Try simplifying control flow for better match */
        return var_v0;
    }
    __repair_phase_var_v0 = -1;
    return __repair_phase_var_v0;
}
