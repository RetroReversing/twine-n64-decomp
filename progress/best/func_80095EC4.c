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

s32 func_800968A4();
s32 func_8009692C();
extern char D_800EE420[];
extern char D_800F2720[];
extern char D_800F2727[];
extern char D_800F272A[];
extern char D_800F2760[];
extern char D_800F2761[];
extern char D_800F277B[];
extern char D_800F27A0[];
extern char D_800F27A1[];
extern char D_800F27A3[];
extern char D_800F27A4[];
extern char D_800F27A5[];

void func_80095EC4(s32 arg0, s32 arg1) {
    s32 temp_a0;
    s32 temp_a0_10;
    s32 temp_a0_11;
    s32 temp_a0_12;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a0_7;
    s32 temp_a0_8;
    s32 temp_a0_9;
    s32 temp_s0;
    s32 temp_s1;
    s32 var_a0;
    char *var_v1;
    char *var_v1_2;
    void *temp_a0_2;
    void *temp_a0_3;

    temp_a0 = arg1 & 0xFF;
    if (temp_a0 != 0xFF) {
        var_v1 = D_800EE420;
        var_v1 += (temp_a0 * 0x860);
        var_v1 += ((arg0 & 0xFF) * 0x86);
        temp_a0_2 = var_v1 + 0x86;
        do {
            *(s8 *)var_v1 = 0;
            var_v1 += 1;
        } while ((u32) var_v1 < (u32) temp_a0_2);
        var_a0 = arg1 & 0xFF;
    } else {
        var_v1_2 = ((arg0 & 0xFF) * 0x86) + D_800F2720;
        temp_a0_3 = var_v1_2 + 0x86;
        do {
            *(s8 *)var_v1_2 = 0;
            var_v1_2 += 1;
        } while ((u32) var_v1_2 < (u32) temp_a0_3);
        var_a0 = arg1 & 0xFF;
    }
    if (var_a0 != 0xFF) {
        M2C_FIELD((((arg0 & 0xFF) * 0x86) + ((var_a0 * 0x860) + D_800EE420)), s8 *, 7) = 0x7F;
    } else {
        *(D_800F2727 + ((arg0 & 0xFF) * 0x86)) = 0x7F;
    }
    temp_a0_4 = arg1 & 0xFF;
    if (temp_a0_4 != 0xFF) {
        M2C_FIELD((((arg0 & 0xFF) * 0x86) + ((temp_a0_4 * 0x860) + D_800EE420)), s8 *, 0xA) = 0x40;
    } else {
        *(D_800F272A + ((arg0 & 0xFF) * 0x86)) = 0x40;
    }
    temp_a0_5 = arg1 & 0xFF;
    if (temp_a0_5 != 0xFF) {
        M2C_FIELD((((arg0 & 0xFF) * 0x86) + ((temp_a0_5 * 0x860) + D_800EE420)), s8 *, 0x80) = 0x40;
    } else {
        *(D_800F27A0 + ((arg0 & 0xFF) * 0x86)) = 0x40;
    }
    temp_a0_6 = arg1 & 0xFF;
    if (temp_a0_6 != 0xFF) {
        M2C_FIELD((((arg0 & 0xFF) * 0x86) + ((temp_a0_6 * 0x860) + D_800EE420)), s8 *, 0x81) = 0;
    } else {
        *(D_800F27A1 + ((arg0 & 0xFF) * 0x86)) = 0;
    }
    temp_a0_7 = arg1 & 0xFF;
    if (temp_a0_7 != 0xFF) {
        M2C_FIELD((((arg0 & 0xFF) * 0x86) + ((temp_a0_7 * 0x860) + D_800EE420)), s8 *, 0x40) = 0;
    } else {
        *(D_800F2760 + ((arg0 & 0xFF) * 0x86)) = 0;
    }
    temp_a0_8 = arg1 & 0xFF;
    if (temp_a0_8 != 0xFF) {
        M2C_FIELD((((arg0 & 0xFF) * 0x86) + ((temp_a0_8 * 0x860) + D_800EE420)), s8 *, 0x41) = 0;
    } else {
        *(D_800F2761 + ((arg0 & 0xFF) * 0x86)) = 0;
    }
    temp_a0_9 = arg1 & 0xFF;
    if (temp_a0_9 != 0xFF) {
        M2C_FIELD((((arg0 & 0xFF) * 0x86) + ((temp_a0_9 * 0x860) + D_800EE420)), s8 *, 0x5B) = 0;
    } else {
        *(D_800F277B + ((arg0 & 0xFF) * 0x86)) = 0;
    }
    temp_a0_10 = arg1 & 0xFF;
    if (temp_a0_10 != 0xFF) {
        M2C_FIELD((((arg0 & 0xFF) * 0x86) + ((temp_a0_10 * 0x860) + D_800EE420)), s8 *, 0x83) = 0;
    } else {
        *(D_800F27A3 + ((arg0 & 0xFF) * 0x86)) = 0;
    }
    temp_a0_11 = arg1 & 0xFF;
    if (temp_a0_11 != 0xFF) {
        M2C_FIELD((((arg0 & 0xFF) * 0x86) + ((temp_a0_11 * 0x860) + D_800EE420)), s8 *, 0x84) = 0x40;
    } else {
        *(D_800F27A4 + ((arg0 & 0xFF) * 0x86)) = 0x40;
    }
    temp_a0_12 = arg1 & 0xFF;
    if (temp_a0_12 != 0xFF) {
        M2C_FIELD((((arg0 & 0xFF) * 0x86) + ((temp_a0_12 * 0x860) + D_800EE420)), s8 *, 0x85) = 0;
    } else {
        *(D_800F27A5 + ((arg0 & 0xFF) * 0x86)) = 0;
    }
    temp_s1 = arg0 & 0xFF;
    temp_s0 = arg1 & 0xFF;
    func_800968A4(temp_s1, temp_s0, 0xFF);
    func_8009692C(temp_s1, temp_s0, 0);
}
