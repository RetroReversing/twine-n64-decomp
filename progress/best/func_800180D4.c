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

void *func_80018510();
s32 func_80018578();

u32 func_800180D4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    s32 temp_a2;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_v1;
    
    u32 var_a0;
    u32 var_s1;
    u32 var_s4;
    u32 var_s5;
    u32 var_s7;
    u32 var_v0;
    union { u8 * pointer; s32 value; } __repair_phase_storage; volatile u32 __frame_pad[2];
    char *var_s0;
    u8 temp_a0;
    u8 temp_v0_2;
    void *temp_a1;
    void *temp_v0;

    var_s0 = arg0;
    var_s5 = 0;
    temp_v0 = func_80018510(arg3);
    var_s7 = arg4 & 0xFFFF;
    if (temp_v0 == NULL) {
        return 0U;
    }
    var_s4 = 0;
    var_s1 = 0;
    if (arg1 & 0xFFFF) {
        var_s0 = arg0;
loop_4:
        temp_a0 = *(u8 *)var_s0;
        switch (temp_a0) {
        case 9:
            var_s1 = ((var_s1 >> 5) + 1) << 5;
            goto block_21;
        case 10:
            var_v0 = var_s1;
            if (var_s7 != 0) {
                return var_s5;
            }
            /* Duplicate return node #24. Try simplifying control flow for better match */
            return var_v0;
        case 32:
            temp_s2 = (u8)(M2C_FIELD(temp_v0, u8 *, 0x10));
            var_s1 += temp_s2;
            var_s5 += temp_s2;
            goto block_21;
        case 1:
        case 2:
        case 5:
        case 6:
        case 7:
            var_s0 += 1;
            var_s4 += 1;
            goto block_21;
        case 3:
        case 4:
            var_s0 += 1;
            var_s4 += 1;
            var_s7 = *(s8 *)var_s0 * 2;
            goto block_21;
        default:
            *(u8 *)var_s0 = temp_a0;
            temp_s3 = temp_a0 & 0xFF;
            temp_s2 = temp_s3 - 0x21;
            if ((var_s7 == 0) || (var_v0 = var_s5, (((u32) (var_s5 + (func_80018578(temp_v0, var_s0) & 0xFFFF)) < var_s7) != 0))) {
                temp_v1 = M2C_FIELD(temp_v0, s32 *, 0xC);
                if (temp_v1 != 0) {
                    temp_a2 = temp_s2 * 8;
                    var_a0 = 0;
                    if (M2C_FIELD((temp_a2 + temp_v1), u8 *, 4) != 0) {
                        for (;;) {
                            temp_a1 = temp_a2 + temp_v1;
                            __repair_phase_storage.pointer = (var_a0 * 2) + M2C_FIELD(temp_a1, s32 *, 0);
                            var_a0 += 1;
                            if (M2C_FIELD(__repair_phase_storage.pointer, u8 *, 0) == temp_s3) {
                                var_s1 -= M2C_FIELD(__repair_phase_storage.pointer, s8 *, 1);
                            } else {
                                if (var_a0 < (u8) M2C_FIELD(temp_a1, u8 *, 4)) {
                                    continue;
                                }
                            }
                            break;
                        }
                    }
                }
                __repair_phase_storage.value = M2C_FIELD(((temp_s2 * 5) + M2C_FIELD(temp_v0, s32 *, 8)), u8 *, 2) + M2C_FIELD(temp_v0, s8 *, 0x11);
                var_s1 += __repair_phase_storage.value;
                var_s5 += __repair_phase_storage.value;
                goto block_21;
            }
            /* Duplicate return node #24. Try simplifying control flow for better match */
            return var_v0;
block_21:
            var_s4 += 1;
            var_s0 += 1;
            if (var_s4 >= (u32) (arg1 & 0xFFFF)) {
                goto block_22;
            }
            goto loop_4;
        }
    } else {
block_22:
        var_v0 = var_s7;
        if (!((var_v0 != 0) & (var_v0 < var_s1))) {
            var_v0 = var_s1;
        }
        return var_v0;
    }
}

