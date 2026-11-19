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

s32 func_8002B9FC();
extern char D_800BF686[];
extern char D_80112F70[];

void func_8002BC68(s32 arg0, s8 arg1) {
    s32 var_a0;
    s32 temp_v1_10;
    s32 temp_v1_11;
    s32 temp_v1_12;
    s32 temp_v1_13;
    s32 temp_v1_14;
    s32 temp_v1_15;
    s32 temp_v1_16;
    s32 temp_v1_17;
    s32 temp_v1_18;
    s32 temp_v1_19;
    s32 temp_v1_20;
    s32 temp_v1_21;
    s32 temp_v1_22;
    s32 temp_v1_23;
    s32 temp_v1_24;
    s32 temp_v1_25;
    s32 temp_v1_26;
    s32 temp_v1_27;
    s32 temp_v1_28;
    s32 temp_v1_29;
    s32 temp_v1_2;
    s32 temp_v1_30;
    s32 temp_v1_31;
    s32 temp_v1_32;
    s32 temp_v1_33;
    s32 temp_v1_34;
    s32 temp_v1_35;
    s32 temp_v1_36;
    s32 temp_v1_37;
    s32 temp_v1_38;
    s32 temp_v1_39;
    s32 temp_v1_3;
    s32 temp_v1_40;
    s32 temp_v1_41;
    s32 temp_v1_42;
    s32 temp_v1_43;
    s32 temp_v1_44;
    s32 temp_v1_45;
    s32 temp_v1_46;
    s32 temp_v1_47;
    s32 temp_v1_48;
    s32 temp_v1_49;
    s32 temp_v1_4;
    s32 temp_v1_50;
    s32 temp_v1_51;
    s32 temp_v1_52;
    s32 temp_v1_53;
    s32 temp_v1_54;
    s32 temp_v1_55;
    s32 temp_v1_56;
    s32 temp_v1_57;
    s32 temp_v1_58;
    s32 temp_v1_59;
    s32 temp_v1_5;
    s32 temp_v1_60;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 temp_v1_9;
    s32 var_s0;
    s32 var_v1;
    u16 var_v0;
    u32 temp_v1;

    temp_v1 = arg0 & 0xFF;
    switch (temp_v1) {
    case 1:
        temp_v1_2 = func_8002B9FC(0x30) * 0xC;
        var_s0 = arg1 & 1;
        *(u16 *)(D_800BF686 + temp_v1_2) = (*(u16 *)(D_800BF686 + temp_v1_2) & 0xFFFE) | var_s0;
        temp_v1_3 = func_8002B9FC(0x27) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_3) = (*(u16 *)(D_800BF686 + temp_v1_3) & 0xFFFE) | var_s0;
        temp_v1_4 = func_8002B9FC(0xD) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_4) = (*(u16 *)(D_800BF686 + temp_v1_4) & 0xFFFE) | var_s0;
        temp_v1_5 = func_8002B9FC(0x2C) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_5) = (*(u16 *)(D_800BF686 + temp_v1_5) & 0xFFFE) | var_s0;
        var_v1 = func_8002B9FC(0x60) * 0xC;
        var_v0 = *(u16 *)(D_800BF686 + var_v1);
        var_a0 = 0x10;
block_12:
        *(u16 *)(D_800BF686 + var_v1) = (var_v0 & 0xFFFE) | var_s0;
        temp_v1_6 = func_8002B9FC(var_a0) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_6) = (*(u16 *)(D_800BF686 + temp_v1_6) & 0xFFFE) | var_s0;
    default:
        *(D_80112F70 + (arg0 & 0xFF)) = arg1;
        break;
    case 2:
        temp_v1_7 = func_8002B9FC(0x59) * 0xC;
        var_s0 = arg1 & 1;
        *(u16 *)(D_800BF686 + temp_v1_7) = (*(u16 *)(D_800BF686 + temp_v1_7) & 0xFFFE) | var_s0;
        temp_v1_8 = func_8002B9FC(0x72) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_8) = (*(u16 *)(D_800BF686 + temp_v1_8) & 0xFFFE) | var_s0;
        temp_v1_9 = func_8002B9FC(0x5D) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_9) = (*(u16 *)(D_800BF686 + temp_v1_9) & 0xFFFE) | var_s0;
        var_v1 = func_8002B9FC(0x5C) * 0xC;
        var_v0 = *(u16 *)(D_800BF686 + var_v1);
        var_a0 = 0x5E;
        goto block_12;
    case 3:
        temp_v1_10 = func_8002B9FC(0x5A) * 0xC;
        var_s0 = arg1 & 1;
        *(u16 *)(D_800BF686 + temp_v1_10) = (*(u16 *)(D_800BF686 + temp_v1_10) & 0xFFFE) | var_s0;
        temp_v1_11 = func_8002B9FC(0x6B) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_11) = (*(u16 *)(D_800BF686 + temp_v1_11) & 0xFFFE) | var_s0;
        temp_v1_12 = func_8002B9FC(0x6A) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_12) = (*(u16 *)(D_800BF686 + temp_v1_12) & 0xFFFE) | var_s0;
        temp_v1_13 = func_8002B9FC(0x70) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_13) = (*(u16 *)(D_800BF686 + temp_v1_13) & 0xFFFE) | var_s0;
        var_v1 = func_8002B9FC(0xC) * 0xC;
        var_v0 = *(u16 *)(D_800BF686 + var_v1);
        var_a0 = 0xE;
        goto block_12;
    case 4:
        temp_v1_14 = func_8002B9FC(0x12) * 0xC;
        var_s0 = arg1 & 1;
        *(u16 *)(D_800BF686 + temp_v1_14) = (*(u16 *)(D_800BF686 + temp_v1_14) & 0xFFFE) | var_s0;
        temp_v1_15 = func_8002B9FC(0x38) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_15) = (*(u16 *)(D_800BF686 + temp_v1_15) & 0xFFFE) | var_s0;
        temp_v1_16 = func_8002B9FC(0x5B) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_16) = (*(u16 *)(D_800BF686 + temp_v1_16) & 0xFFFE) | var_s0;
        var_v1 = func_8002B9FC(9) * 0xC;
        var_v0 = *(u16 *)(D_800BF686 + var_v1);
        var_a0 = 0x4B;
        goto block_12;
    case 10:
        temp_v1_17 = func_8002B9FC(0x18) * 0xC;
        var_s0 = arg1 & 1;
        *(u16 *)(D_800BF686 + temp_v1_17) = (*(u16 *)(D_800BF686 + temp_v1_17) & 0xFFFE) | var_s0;
        temp_v1_18 = func_8002B9FC(0x6E) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_18) = (*(u16 *)(D_800BF686 + temp_v1_18) & 0xFFFE) | var_s0;
        temp_v1_19 = func_8002B9FC(0x71) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_19) = (*(u16 *)(D_800BF686 + temp_v1_19) & 0xFFFE) | var_s0;
        var_v1 = func_8002B9FC(0x75) * 0xC;
        var_v0 = *(u16 *)(D_800BF686 + var_v1);
        var_a0 = 0x41;
        goto block_12;
    case 5:
        temp_v1_20 = func_8002B9FC(0x19) * 0xC;
        var_s0 = arg1 & 1;
        *(u16 *)(D_800BF686 + temp_v1_20) = (*(u16 *)(D_800BF686 + temp_v1_20) & 0xFFFE) | var_s0;
        temp_v1_21 = func_8002B9FC(4) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_21) = (*(u16 *)(D_800BF686 + temp_v1_21) & 0xFFFE) | var_s0;
        temp_v1_22 = func_8002B9FC(5) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_22) = (*(u16 *)(D_800BF686 + temp_v1_22) & 0xFFFE) | var_s0;
        temp_v1_23 = func_8002B9FC(0x1E) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_23) = (*(u16 *)(D_800BF686 + temp_v1_23) & 0xFFFE) | var_s0;
        temp_v1_24 = func_8002B9FC(0x22) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_24) = (*(u16 *)(D_800BF686 + temp_v1_24) & 0xFFFE) | var_s0;
        temp_v1_25 = func_8002B9FC(0x20) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_25) = (*(u16 *)(D_800BF686 + temp_v1_25) & 0xFFFE) | var_s0;
        temp_v1_26 = func_8002B9FC(0x21) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_26) = (*(u16 *)(D_800BF686 + temp_v1_26) & 0xFFFE) | var_s0;
        temp_v1_27 = func_8002B9FC(0x1F) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_27) = (*(u16 *)(D_800BF686 + temp_v1_27) & 0xFFFE) | var_s0;
        temp_v1_28 = func_8002B9FC(0x2D) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_28) = (*(u16 *)(D_800BF686 + temp_v1_28) & 0xFFFE) | var_s0;
        temp_v1_29 = func_8002B9FC(8) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_29) = (*(u16 *)(D_800BF686 + temp_v1_29) & 0xFFFE) | var_s0;
        temp_v1_30 = func_8002B9FC(7) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_30) = (*(u16 *)(D_800BF686 + temp_v1_30) & 0xFFFE) | var_s0;
        temp_v1_31 = func_8002B9FC(0x42) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_31) = (*(u16 *)(D_800BF686 + temp_v1_31) & 0xFFFE) | var_s0;
        temp_v1_32 = func_8002B9FC(0x57) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_32) = (*(u16 *)(D_800BF686 + temp_v1_32) & 0xFFFE) | var_s0;
        temp_v1_33 = func_8002B9FC(0x15) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_33) = (*(u16 *)(D_800BF686 + temp_v1_33) & 0xFFFE) | var_s0;
        var_v1 = func_8002B9FC(0x76) * 0xC;
        var_v0 = *(u16 *)(D_800BF686 + var_v1);
        var_a0 = 0x77;
        goto block_12;
    case 6:
        temp_v1_34 = func_8002B9FC(0x24) * 0xC;
        var_s0 = arg1 & 1;
        *(u16 *)(D_800BF686 + temp_v1_34) = (*(u16 *)(D_800BF686 + temp_v1_34) & 0xFFFE) | var_s0;
        temp_v1_35 = func_8002B9FC(0x25) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_35) = (*(u16 *)(D_800BF686 + temp_v1_35) & 0xFFFE) | var_s0;
        temp_v1_36 = func_8002B9FC(0x17) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_36) = (*(u16 *)(D_800BF686 + temp_v1_36) & 0xFFFE) | var_s0;
        temp_v1_37 = func_8002B9FC(0) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_37) = (*(u16 *)(D_800BF686 + temp_v1_37) & 0xFFFE) | var_s0;
        temp_v1_38 = func_8002B9FC(0xA) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_38) = (*(u16 *)(D_800BF686 + temp_v1_38) & 0xFFFE) | var_s0;
        temp_v1_39 = func_8002B9FC(0x32) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_39) = (*(u16 *)(D_800BF686 + temp_v1_39) & 0xFFFE) | var_s0;
        temp_v1_40 = func_8002B9FC(0x1B) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_40) = (*(u16 *)(D_800BF686 + temp_v1_40) & 0xFFFE) | var_s0;
        temp_v1_41 = func_8002B9FC(0x14) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_41) = (*(u16 *)(D_800BF686 + temp_v1_41) & 0xFFFE) | var_s0;
        temp_v1_42 = func_8002B9FC(0x1D) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_42) = (*(u16 *)(D_800BF686 + temp_v1_42) & 0xFFFE) | var_s0;
        temp_v1_43 = func_8002B9FC(0x1C) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_43) = (*(u16 *)(D_800BF686 + temp_v1_43) & 0xFFFE) | var_s0;
        var_v1 = func_8002B9FC(0x23) * 0xC;
        var_v0 = *(u16 *)(D_800BF686 + var_v1);
        var_a0 = 0xB;
        goto block_12;
    case 7:
        temp_v1_44 = func_8002B9FC(0xF) * 0xC;
        var_s0 = arg1 & 1;
        *(u16 *)(D_800BF686 + temp_v1_44) = (*(u16 *)(D_800BF686 + temp_v1_44) & 0xFFFE) | var_s0;
        temp_v1_45 = func_8002B9FC(0x51) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_45) = (*(u16 *)(D_800BF686 + temp_v1_45) & 0xFFFE) | var_s0;
        temp_v1_46 = func_8002B9FC(0x4A) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_46) = (*(u16 *)(D_800BF686 + temp_v1_46) & 0xFFFE) | var_s0;
        temp_v1_47 = func_8002B9FC(0x53) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_47) = (*(u16 *)(D_800BF686 + temp_v1_47) & 0xFFFE) | var_s0;
        temp_v1_48 = func_8002B9FC(0x68) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_48) = (*(u16 *)(D_800BF686 + temp_v1_48) & 0xFFFE) | var_s0;
        temp_v1_49 = func_8002B9FC(0x69) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_49) = (*(u16 *)(D_800BF686 + temp_v1_49) & 0xFFFE) | var_s0;
        var_v1 = func_8002B9FC(0x49) * 0xC;
        var_v0 = *(u16 *)(D_800BF686 + var_v1);
        var_a0 = 0x64;
        goto block_12;
    case 8:
        temp_v1_50 = func_8002B9FC(0x2E) * 0xC;
        var_s0 = arg1 & 1;
        *(u16 *)(D_800BF686 + temp_v1_50) = (*(u16 *)(D_800BF686 + temp_v1_50) & 0xFFFE) | var_s0;
        temp_v1_51 = func_8002B9FC(0x2F) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_51) = (*(u16 *)(D_800BF686 + temp_v1_51) & 0xFFFE) | var_s0;
        temp_v1_52 = func_8002B9FC(0x3B) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_52) = (*(u16 *)(D_800BF686 + temp_v1_52) & 0xFFFE) | var_s0;
        temp_v1_53 = func_8002B9FC(0x3A) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_53) = (*(u16 *)(D_800BF686 + temp_v1_53) & 0xFFFE) | var_s0;
        temp_v1_54 = func_8002B9FC(0x44) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_54) = (*(u16 *)(D_800BF686 + temp_v1_54) & 0xFFFE) | var_s0;
        temp_v1_55 = func_8002B9FC(6) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_55) = (*(u16 *)(D_800BF686 + temp_v1_55) & 0xFFFE) | var_s0;
        temp_v1_56 = func_8002B9FC(0x61) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_56) = (*(u16 *)(D_800BF686 + temp_v1_56) & 0xFFFE) | var_s0;
        var_v1 = func_8002B9FC(0x36) * 0xC;
        var_v0 = *(u16 *)(D_800BF686 + var_v1);
        var_a0 = 0x37;
        goto block_12;
    case 9:
        temp_v1_57 = func_8002B9FC(2) * 0xC;
        var_s0 = arg1 & 1;
        *(u16 *)(D_800BF686 + temp_v1_57) = (*(u16 *)(D_800BF686 + temp_v1_57) & 0xFFFE) | var_s0;
        temp_v1_58 = func_8002B9FC(0x29) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_58) = (*(u16 *)(D_800BF686 + temp_v1_58) & 0xFFFE) | var_s0;
        temp_v1_59 = func_8002B9FC(0x28) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_59) = (*(u16 *)(D_800BF686 + temp_v1_59) & 0xFFFE) | var_s0;
        temp_v1_60 = func_8002B9FC(0x58) * 0xC;
        *(u16 *)(D_800BF686 + temp_v1_60) = (*(u16 *)(D_800BF686 + temp_v1_60) & 0xFFFE) | var_s0;
        var_v1 = func_8002B9FC(0x43) * 0xC;
        var_v0 = *(u16 *)(D_800BF686 + var_v1);
        var_a0 = 0x4E;
        goto block_12;
    }
}
