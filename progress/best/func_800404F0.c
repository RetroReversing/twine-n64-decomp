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

s32 func_800404D8();
extern u8 D_800CA338;
extern s32 D_800E19E0;
extern s32 D_800E19E4;
extern s32 D_800E19E8;

void func_800404F0(void *arg0, void *arg1, s32 *arg2, s8 *arg3) {
    s16 var_v0_6;
    s16 var_v0_7;
    s32 temp_a0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    u32 temp_v0_10;
    u32 temp_v0_11;
    u32 temp_v0_12;
    u32 temp_v0_13;
    u32 temp_v0_14;
    u32 temp_v0_15;
    u32 temp_v0_16;
    u32 temp_v0_17;
    u32 temp_v0_18;
    u32 temp_v0_19;
    u32 temp_v0_20;
    u32 temp_v0_21;
    u32 temp_v0_22;
    u32 temp_v0_23;
    u32 temp_v0_24;
    u32 temp_v0_25;
    u32 temp_v0_26;
    u32 temp_v0_27;
    u32 temp_v0_28;
    u32 temp_v0_29;
    u32 temp_v0_2;
    u32 temp_v0_3;
    u32 temp_v0_4;
    u32 temp_v0_5;
    u32 temp_v0_6;
    u32 temp_v0_7;
    u32 temp_v0_8;
    u32 temp_v0_9;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32 temp_v1_5;
    u32 temp_v1_8;
    u32 var_a0;
    u8 temp_v0;
    u8 temp_v1_6;
    u8 temp_v1_7;
    u8 var_v0;
    void *temp_a0_2;
    void *temp_a0_3;

    temp_a0 = D_800CA338 != 0;
    if (M2C_FIELD(arg0, s32 *, 0x3C) & 0x400000) {
        M2C_FIELD(arg1, s32 *, 0x50) |= 0x100;
    }
    temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), u8 *, 0x1E);
    switch (temp_v0) {
    case 0x3E:
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        M2C_FIELD(arg1, s32 *, 0x50) &= ~0x400;
        return;
    case 0x40:
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        temp_v0_2 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        temp_v1 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_2 & 0xFFFF0003) | ((((temp_v0_2 >> 2) & 0x3FFF) | 4) * 4));
        M2C_FIELD(arg1, u32 *, 0x5C) = (u32) ((temp_v1 & 0x7FFFFF) | (((temp_v1 >> 0x17) | 0x20) << 0x17));
        M2C_FIELD(arg1, s32 *, 0x50) &= ~0x400;
        *arg2 = 1;
        return;
    case 0x4D:
        var_v0 = 0x18;
block_70:
        M2C_FIELD(arg1, s16 *, 0x58) = (s16) var_v0;
        return;
    case 0x52:
    case 0xCB:
        temp_v0_3 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        var_v0 = 0x18;
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_3 & 0xFFFF0003) | ((((temp_v0_3 >> 2) & 0x3FFF) | 0x400) * 4));
        M2C_FIELD(arg1, s32 *, 0x50) &= ~0x200;
        goto block_70;
    case 0x1B:
        temp_v0_4 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        var_v0 = 0x18;
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_4 & 0xFFFF0003) | ((((temp_v0_4 >> 2) & 0x3FFF) | 8) * 4));
        goto block_70;
    case 0x99:
        temp_v0_5 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        var_a0 = (temp_v0_5 & 0xFF81FFFF) | ((((temp_v0_5 >> 0x11) & 0x3F) | 4) << 0x11);
        var_v0_2 = 0x02000000;
block_13:
        M2C_FIELD(arg1, u32 *, 0x5C) = var_a0;
        M2C_FIELD(arg1, s32 *, 0x50) |= var_v0_2;
        return;
    case 0x9A:
        temp_v0_6 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        var_a0 = (temp_v0_6 & 0xFF81FFFF) | ((((temp_v0_6 >> 0x11) & 0x3F) | 4) << 0x11);
        var_v0_2 = 0x04000000;
        goto block_13;
    case 0x9B:
        temp_v0_7 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        var_a0 = (temp_v0_7 & 0xFF81FFFF) | ((((temp_v0_7 >> 0x11) & 0x3F) | 4) << 0x11);
        var_v0_2 = 0x08000000;
        goto block_13;
    case 0x9C:
        temp_v0_8 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        var_a0 = (temp_v0_8 & 0xFF81FFFF) | ((((temp_v0_8 >> 0x11) & 0x3F) | 4) << 0x11);
        var_v0_2 = 0x10000000;
        goto block_13;
    case 0x8C:
        M2C_FIELD(arg1, s32 *, 0x50) |= 0x01000000;
        /* fallthrough */
    case 0x18:
        var_v0 = 0x18;
        goto block_70;
    case 0x9D:
        if (temp_a0 == 0) {
            M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
            return;
        }
        break;
    case 0x9E:
        temp_v0_9 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_9 & 0xFFFF0003) | ((((temp_v0_9 >> 2) & 0x3FFF) | 8) * 4));
        if (temp_a0 == 0) {
            var_v0 = 0x18;
            goto block_70;
        }
        break;
    case 0x19:
        temp_v1_2 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        var_v0_3 = temp_v1_2 & 0xFF81FFFF;
        var_v1 = ((temp_v1_2 >> 0x11) & 0x3F) | 4;
block_43:
        M2C_FIELD(arg1, u32 *, 0x5C) = (u32) (var_v0_3 | (var_v1 << 0x11));
        return;
    case 0x68:
        temp_v0_10 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, u32 *, 0x5C) = (u32) ((temp_v0_10 & 0x7FFFFF) | (((temp_v0_10 >> 0x17) | 0x10) << 0x17));
        /* fallthrough */
    case 0xC8:
        temp_v0_11 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        M2C_FIELD(arg1, u32 *, 0x5C) = (u32) ((temp_v0_11 & 0x7FFFFF) | (((temp_v0_11 >> 0x17) | 0x40) << 0x17));
        M2C_FIELD(arg1, s32 *, 0x50) &= ~0x400;
        *arg3 = 0;
        *arg2 = 0xB;
        return;
    case 0x50:
        temp_v0_12 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        var_v1_2 = temp_v0_12 & 0xFFFF0003;
        var_v0_4 = ((temp_v0_12 >> 2) & 0x3FFF) | 0x200;
block_33:
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) (var_v1_2 | (var_v0_4 * 4));
    case 0x42:
block_35:
        temp_v0_13 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x46;
        M2C_FIELD(arg1, u32 *, 0x5C) = (u32) ((temp_v0_13 & 0xFF81FFFF) | ((((temp_v0_13 >> 0x11) & 0x3F) | 4) << 0x11));
block_37:
        D_800E19E0 = M2C_FIELD(arg1, s32 *, 0x24);
        D_800E19E4 = M2C_FIELD(arg1, s32 *, 0x28);
        D_800E19E8 = M2C_FIELD(arg1, s32 *, 0x2C);
        M2C_FIELD(arg1, s32 *, 0x24) = 0;
        M2C_FIELD(arg1, s32 *, 0x28) = 0;
        M2C_FIELD(arg1, s32 *, 0x2C) = 0;
        if (M2C_FIELD(arg0, u16 *, 0x38) == 1) {
            var_v1_3 = M2C_FIELD(arg1, u32 *, 0x5C) & 0x7FFFFF;
block_39:
            M2C_FIELD(arg1, u32 *, 0x5C) = (u32) (var_v1_3 | (((M2C_FIELD(arg1, u32 *, 0x5C) >> 0x17) | 8) << 0x17));
            return;
        }
        break;
    case 0x4F:
        temp_v0_14 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        var_v1_4 = temp_v0_14 & 0xFFFF0003;
        var_v0_5 = ((temp_v0_14 >> 2) & 0x3FFF) | 0x200;
block_27:
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) (var_v1_4 | (var_v0_5 * 4));
    case 0x46:
block_29:
        temp_v0_15 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, u32 *, 0x5C) = (u32) ((temp_v0_15 & 0xFF81FFFF) | ((((temp_v0_15 >> 0x11) & 0x3F) | 4) << 0x11));
        temp_v0_16 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x46;
        M2C_FIELD(arg1, u32 *, 0x5C) = (u32) ((temp_v0_16 & 0x7FFFFF) | (((temp_v0_16 >> 0x17) | 4) << 0x17));
        D_800E19E0 = M2C_FIELD(arg1, s32 *, 0x24);
        D_800E19E4 = M2C_FIELD(arg1, s32 *, 0x28);
        D_800E19E8 = M2C_FIELD(arg1, s32 *, 0x2C);
        M2C_FIELD(arg1, s32 *, 0x2C) = 0;
        M2C_FIELD(arg1, s32 *, 0x28) = 0;
        M2C_FIELD(arg1, s32 *, 0x24) = 0;
        if (M2C_FIELD(arg0, u16 *, 0x38) == 1) {
            var_v1_3 = M2C_FIELD(arg1, u32 *, 0x5C) & 0x7FFFFF;
            goto block_39;
        }
        break;
    case 0x49:
        func_800404D8(arg1);
        temp_v0_17 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        var_v1_4 = temp_v0_17 & 0xFFFF0003;
        var_v0_5 = ((temp_v0_17 >> 2) & 0x3FFF) | 0x40;
        goto block_27;
    case 0x48:
        func_800404D8(arg1);
        temp_v0_18 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        var_v1_4 = temp_v0_18 & 0xFFFF0003;
        var_v0_5 = ((temp_v0_18 >> 2) & 0x3FFF) | 0x10;
        goto block_27;
    case 0x47:
        func_800404D8(arg1);
        temp_v0_19 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        temp_a0_2 = M2C_FIELD(arg1, void **, 0x20);
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_19 & 0xFFFF0003) | ((((temp_v0_19 >> 2) & 0x3FFF) | 0x20) * 4));
        M2C_FIELD(temp_a0_2, u8 *, 0x66) = 0x80;
        M2C_FIELD(temp_a0_2, u8 *, 0x65) = 0x80;
        M2C_FIELD(temp_a0_2, u8 *, 0x64) = 0x80;
        goto block_29;
    case 0x45:
        temp_v0_20 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        var_v1_2 = temp_v0_20 & 0xFFFF0003;
        var_v0_4 = ((temp_v0_20 >> 2) & 0x3FFF) | 0x40;
        goto block_33;
    case 0x44:
        temp_v0_21 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        var_v1_2 = temp_v0_21 & 0xFFFF0003;
        var_v0_4 = ((temp_v0_21 >> 2) & 0x3FFF) | 0x10;
        goto block_33;
    case 0x43:
        temp_v0_22 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        temp_a0_3 = M2C_FIELD(arg1, void **, 0x20);
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_22 & 0xFFFF0003) | ((((temp_v0_22 >> 2) & 0x3FFF) | 0x20) * 4));
        M2C_FIELD(temp_a0_3, u8 *, 0x66) = 0x80;
        M2C_FIELD(temp_a0_3, u8 *, 0x65) = 0x80;
        M2C_FIELD(temp_a0_3, u8 *, 0x64) = 0x80;
        goto block_35;
    case 0x22:
        M2C_FIELD(arg1, s16 *, 0x58) = 0x46;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x20), f32 *, 0x5C) = 65536.0f;
        goto block_37;
    case 0x21:
        temp_v1_3 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        var_v0_3 = temp_v1_3 & 0xFF81FFFF;
        var_v1 = ((temp_v1_3 >> 0x11) & 0x3F) | 1;
        goto block_43;
    case 0x3C:
        temp_v1_4 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        var_v0_3 = temp_v1_4 & 0xFF81FFFF;
        var_v1 = ((temp_v1_4 >> 0x11) & 0x3F) | 2;
        goto block_43;
    case 0x3D:
        temp_v1_5 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        var_v0_3 = temp_v1_5 & 0xFF81FFFF;
        var_v1 = ((temp_v1_5 >> 0x11) & 0x3F) | 8;
        goto block_43;
    case 0x1E:
    case 0x1F:
    case 0x84:
    case 0x85:
    case 0x88:
    case 0x89:
        *arg3 = 0;
        temp_v1_6 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), u8 *, 0x1E);
        if (temp_v1_6 == 0x84) {
            temp_v0_23 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
            M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_23 & 0xFFFF0003) | ((((temp_v0_23 >> 2) & 0x3FFF) | 0x2000) * 4));
            var_v0_6 = 0x84;
        } else if ((s32) temp_v1_6 < 0x85) {
            if (temp_v1_6 != 0x1E) {
                var_v0_6 = 0x1E;
            } else {
                temp_v0_24 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
                M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_24 & 0xFFFF0003) | ((((temp_v0_24 >> 2) & 0x3FFF) | 0x2000) * 4));
                var_v0_6 = 0x1E;
            }
        } else if (temp_v1_6 != 0x88) {
            if ((s32) temp_v1_6 < 0x89) {
                var_v0_6 = 0x84;
                if (temp_v1_6 != 0x85) {
                    var_v0_6 = 0x1E;
                }
            } else {
                var_v0_6 = 0x88;
                if (temp_v1_6 != 0x89) {
                    var_v0_6 = 0x1E;
                }
            }
        } else {
            temp_v0_25 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
            M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_25 & 0xFFFF0003) | ((((temp_v0_25 >> 2) & 0x3FFF) | 0x2000) * 4));
            var_v0_6 = 0x88;
        }
        M2C_FIELD(arg1, s16 *, 0x58) = var_v0_6;
        D_800E19E0 = M2C_FIELD(arg1, s32 *, 0x24);
        D_800E19E4 = M2C_FIELD(arg1, s32 *, 0x28);
        D_800E19E8 = M2C_FIELD(arg1, s32 *, 0x2C);
        M2C_FIELD(arg1, s32 *, 0x24) = 0;
        M2C_FIELD(arg1, s32 *, 0x28) = 0;
        M2C_FIELD(arg1, s32 *, 0x2C) = 0;
        M2C_FIELD(arg1, s8 *, 0x54) = (s8) M2C_FIELD(arg0, u16 *, 0x2C);
        M2C_FIELD(arg1, s8 *, 0x55) = (s8) M2C_FIELD(arg0, u16 *, 0x2E);
        return;
    case 0x27:
    case 0x86:
    case 0x8A:
        temp_v0_26 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_26 & 0xFFFF0003) | ((((temp_v0_26 >> 2) & 0x3FFF) | 0x1000) * 4));
        /* fallthrough */
    case 0x53:
    case 0x87:
    case 0x8B:
        temp_v1_7 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), u8 *, 0x1E);
        var_v0_7 = 0x1E;
        if ((s32) temp_v1_7 >= 0x86) {
            var_v0_7 = 0x84;
            if (((s32) temp_v1_7 >= 0x88) && (((s32) temp_v1_7 >= 0x8C) || (var_v0_7 = 0x88, (((s32) temp_v1_7 < 0x8A) != 0)))) {
                var_v0_7 = 0x1E;
            }
        }
        M2C_FIELD(arg1, s16 *, 0x58) = var_v0_7;
        temp_v0_27 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_27 & 0xFFFF0003) | ((((temp_v0_27 >> 2) & 0x3FFF) | 0x800) * 4));
        *arg2 = 1;
        D_800E19E0 = M2C_FIELD(arg1, s32 *, 0x24);
        D_800E19E4 = M2C_FIELD(arg1, s32 *, 0x28);
        D_800E19E8 = M2C_FIELD(arg1, s32 *, 0x2C);
        M2C_FIELD(arg1, s32 *, 0x24) = 0;
        M2C_FIELD(arg1, s32 *, 0x28) = 0;
        M2C_FIELD(arg1, s32 *, 0x2C) = 0;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x3C), s8 *, 0x47) = (s8) M2C_FIELD(arg0, u16 *, 0x2C);
        return;
    case 0x15:
        temp_v0_28 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_28 & 0xFFFF0003) | ((((temp_v0_28 >> 2) & 0x3FFF) | 2) * 4));
        /* fallthrough */
    case 0x14:
        M2C_FIELD(arg1, s16 *, 0x58) = 0x18;
        temp_v0_29 = (u32) M2C_FIELD(arg1, s16 *, 0x58);
        temp_v1_8 = M2C_FIELD(arg1, u32 *, 0x5C);
        M2C_FIELD(arg1, s16 *, 0x58) = (s32) ((temp_v0_29 & 0xFFFF0003) | ((((temp_v0_29 >> 2) & 0x3FFF) | 1) * 4));
        M2C_FIELD(arg1, s32 *, 0x50) &= ~0x600;
        M2C_FIELD(arg1, u32 *, 0x5C) = (u32) ((temp_v1_8 & 0x7FFFFF) | (((temp_v1_8 >> 0x17) | 0x10) << 0x17));
        M2C_FIELD(arg1, s8 *, 0x54) = (s8) M2C_FIELD(arg0, u16 *, 0x2C);
        M2C_FIELD(arg1, s8 *, 0x55) = (s8) M2C_FIELD(arg0, u16 *, 0x2E);
        *arg2 = 5;
        return;
    default:
        var_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x24), u8 *, 0x1E);
        goto block_70;
    }
}
