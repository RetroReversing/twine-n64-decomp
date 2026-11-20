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

s32 func_8002BC28();
extern char D_8010019C[];
extern char D_801001A1[];
extern u8 D_801002A1;
extern s32 D_801002B8;
extern s32 D_801002BC;

s32 func_80019B34(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a1;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;

    var_a2 = arg2;
    var_s0_3 = arg0 & 0xFFFF;
    var_a1 = D_801002B8;
    temp_a0 = *(D_8010019C + (var_s0_3 * 0x18));
    var_s0 = 0;
    if (var_a1 > 0) {
        var_a2 = var_s0_3;
        var_v1 = 0 & 0xFFFF;
loop_2:
        if ((var_v1 == var_a2) || (var_v0 = 0x15A, (*(D_8010019C + (var_v1 * 0x18)) != temp_a0))) {
            var_s0 += 1;
            var_v1 = var_s0 & 0xFFFF;
            if ((var_s0 & 0xFFFF) >= var_a1) {
                goto block_5;
            }
            goto loop_2;
        }
        /* Duplicate return node #26. Try simplifying control flow for better match */
        return var_v0;
    }
block_5:
    temp_v1_2 = D_801002BC; temp_v1_2 += 4;
    var_s0_2 = 4;
    if (temp_v1_2 > 4) {
        var_a2 = arg0 & 0xFFFF;
        var_a1 = 4 & 0xFFFF;
loop_7:
        if ((var_a1 == var_a2) || (var_v0 = 0x15A, (*(D_8010019C + (var_a1 * 0x18)) != temp_a0))) {
            var_s0_2 += 1;
            var_a1 = var_s0_2 & 0xFFFF;
            if ((var_s0_2 & 0xFFFF) >= temp_v1_2) {
                goto block_10;
            }
            goto loop_7;
        }
        /* Duplicate return node #26. Try simplifying control flow for better match */
        return var_v0;
    }
block_10:
    if (D_801002A1 != 0) {
        var_v0 = 0x159;
        if (!(func_8002BC28(temp_a0, var_a1, var_a2) & 0xFF)) {
            var_v0 = 0x159;
            if (*(D_801001A1 + ((arg0 & 0xFFFF) * 0x18)) == 0) {
                return 0x15A;
            }
        }
        /* Duplicate return node #26. Try simplifying control flow for better match */
        return var_v0;
    }
    temp_v1_3 = func_8002BC28(temp_a0, var_a1, var_a2) & 0xFF;
    var_v0 = 0x159;
    if (temp_v1_3 == 0) {
        var_s0_3 = 0;
        if (temp_v1_3 < D_801002B8) {
            var_v1_2 = 0 & 0xFFFF;
loop_17:
            if ((var_v1_2 == (arg0 & 0xFFFF)) || (var_v0 = 0x15A, ((func_8002BC28(*(D_8010019C + (var_v1_2 * 0x18))) & 0xFF) != 0))) {
                var_s0_3 += 1;
                var_v1_2 = var_s0_3 & 0xFFFF;
                if ((var_s0_3 & 0xFFFF) >= D_801002B8) {
                    goto block_20;
                }
                goto loop_17;
            }
        } else {
block_20:
            var_s0_4 = 4;
            if ((D_801002BC + 4) > 4) {
                var_v1_3 = 4 & 0xFFFF;
loop_22:
                if ((var_v1_3 == (arg0 & 0xFFFF)) || (var_v0 = 0x15A, ((func_8002BC28(*(D_8010019C + (var_v1_3 * 0x18))) & 0xFF) != 0))) {
                    var_s0_4 += 1;
                    var_v1_3 = var_s0_4 & 0xFFFF;
                    if ((var_s0_4 & 0xFFFF) >= (D_801002BC + 4)) {
                        goto block_25;
                    }
                    goto loop_22;
                }
            } else {
block_25:
                var_v0 = 0x159;
            }
        }
    }
    return var_v0;
}
