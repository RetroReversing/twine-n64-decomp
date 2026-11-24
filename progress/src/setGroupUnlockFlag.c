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

s32 findSpawnRecordIndex();
extern char gKeyEntryFlagsTable[];
extern char gGroupUnlockFlags[];

/* Stores value as the unlock flag for a group and copies its bit 0 into the key-entry flags of every record belonging to that group. */ void setGroupUnlockFlag(s32 group, s8 value) {
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
    s32 bit;
    s32 var_v1;
    u16 var_v0;
    u32 temp_v1;

    temp_v1 = group & 0xFF;
    switch (temp_v1) {
    case 1:
        temp_v1_2 = findSpawnRecordIndex(0x30) * 0xC;
        bit = value & 1;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_2) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_2) & 0xFFFE) | bit;
        temp_v1_3 = findSpawnRecordIndex(0x27) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_3) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_3) & 0xFFFE) | bit;
        temp_v1_4 = findSpawnRecordIndex(0xD) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_4) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_4) & 0xFFFE) | bit;
        temp_v1_5 = findSpawnRecordIndex(0x2C) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_5) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_5) & 0xFFFE) | bit;
        var_v1 = findSpawnRecordIndex(0x60) * 0xC;
        var_v0 = *(u16 *)(gKeyEntryFlagsTable + var_v1);
        var_a0 = 0x10;
        goto block_12;
    case 0:
        return;
    default:
        goto done;
    case 2:
        temp_v1_7 = findSpawnRecordIndex(0x59) * 0xC;
        bit = value & 1;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_7) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_7) & 0xFFFE) | bit;
        temp_v1_8 = findSpawnRecordIndex(0x72) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_8) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_8) & 0xFFFE) | bit;
        temp_v1_9 = findSpawnRecordIndex(0x5D) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_9) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_9) & 0xFFFE) | bit;
        var_v1 = findSpawnRecordIndex(0x5C) * 0xC;
        var_v0 = *(u16 *)(gKeyEntryFlagsTable + var_v1);
        var_a0 = 0x5E;
        goto block_12;
    case 3:
        temp_v1_10 = findSpawnRecordIndex(0x5A) * 0xC;
        bit = value & 1;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_10) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_10) & 0xFFFE) | bit;
        temp_v1_11 = findSpawnRecordIndex(0x6B) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_11) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_11) & 0xFFFE) | bit;
        temp_v1_12 = findSpawnRecordIndex(0x6A) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_12) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_12) & 0xFFFE) | bit;
        temp_v1_13 = findSpawnRecordIndex(0x70) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_13) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_13) & 0xFFFE) | bit;
        var_v1 = findSpawnRecordIndex(0xC) * 0xC;
        var_v0 = *(u16 *)(gKeyEntryFlagsTable + var_v1);
        var_a0 = 0xE;
        goto block_12;
    case 4:
        temp_v1_14 = findSpawnRecordIndex(0x12) * 0xC;
        bit = value & 1;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_14) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_14) & 0xFFFE) | bit;
        temp_v1_15 = findSpawnRecordIndex(0x38) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_15) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_15) & 0xFFFE) | bit;
        temp_v1_16 = findSpawnRecordIndex(0x5B) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_16) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_16) & 0xFFFE) | bit;
        var_v1 = findSpawnRecordIndex(9) * 0xC;
        var_v0 = *(u16 *)(gKeyEntryFlagsTable + var_v1);
        var_a0 = 0x4B;
        goto block_12;
    case 10:
        temp_v1_17 = findSpawnRecordIndex(0x18) * 0xC;
        bit = value & 1;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_17) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_17) & 0xFFFE) | bit;
        temp_v1_18 = findSpawnRecordIndex(0x6E) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_18) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_18) & 0xFFFE) | bit;
        temp_v1_19 = findSpawnRecordIndex(0x71) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_19) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_19) & 0xFFFE) | bit;
        var_v1 = findSpawnRecordIndex(0x75) * 0xC;
        var_v0 = *(u16 *)(gKeyEntryFlagsTable + var_v1);
        var_a0 = 0x41;
        goto block_12;
    case 5:
        temp_v1_20 = findSpawnRecordIndex(0x19) * 0xC;
        bit = value & 1;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_20) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_20) & 0xFFFE) | bit;
        temp_v1_21 = findSpawnRecordIndex(4) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_21) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_21) & 0xFFFE) | bit;
        temp_v1_22 = findSpawnRecordIndex(5) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_22) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_22) & 0xFFFE) | bit;
        temp_v1_23 = findSpawnRecordIndex(0x1E) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_23) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_23) & 0xFFFE) | bit;
        temp_v1_24 = findSpawnRecordIndex(0x22) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_24) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_24) & 0xFFFE) | bit;
        temp_v1_25 = findSpawnRecordIndex(0x20) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_25) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_25) & 0xFFFE) | bit;
        temp_v1_26 = findSpawnRecordIndex(0x21) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_26) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_26) & 0xFFFE) | bit;
        temp_v1_27 = findSpawnRecordIndex(0x1F) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_27) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_27) & 0xFFFE) | bit;
        temp_v1_28 = findSpawnRecordIndex(0x2D) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_28) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_28) & 0xFFFE) | bit;
        temp_v1_29 = findSpawnRecordIndex(8) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_29) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_29) & 0xFFFE) | bit;
        temp_v1_30 = findSpawnRecordIndex(7) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_30) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_30) & 0xFFFE) | bit;
        temp_v1_31 = findSpawnRecordIndex(0x42) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_31) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_31) & 0xFFFE) | bit;
        temp_v1_32 = findSpawnRecordIndex(0x57) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_32) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_32) & 0xFFFE) | bit;
        temp_v1_33 = findSpawnRecordIndex(0x15) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_33) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_33) & 0xFFFE) | bit;
        var_v1 = findSpawnRecordIndex(0x76) * 0xC;
        var_v0 = *(u16 *)(gKeyEntryFlagsTable + var_v1);
        var_a0 = 0x77;
        goto block_12;
    case 6:
        temp_v1_34 = findSpawnRecordIndex(0x24) * 0xC;
        bit = value & 1;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_34) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_34) & 0xFFFE) | bit;
        temp_v1_35 = findSpawnRecordIndex(0x25) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_35) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_35) & 0xFFFE) | bit;
        temp_v1_36 = findSpawnRecordIndex(0x17) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_36) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_36) & 0xFFFE) | bit;
        temp_v1_37 = findSpawnRecordIndex(0) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_37) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_37) & 0xFFFE) | bit;
        temp_v1_38 = findSpawnRecordIndex(0xA) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_38) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_38) & 0xFFFE) | bit;
        temp_v1_39 = findSpawnRecordIndex(0x32) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_39) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_39) & 0xFFFE) | bit;
        temp_v1_40 = findSpawnRecordIndex(0x1B) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_40) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_40) & 0xFFFE) | bit;
        temp_v1_41 = findSpawnRecordIndex(0x14) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_41) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_41) & 0xFFFE) | bit;
        temp_v1_42 = findSpawnRecordIndex(0x1D) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_42) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_42) & 0xFFFE) | bit;
        temp_v1_43 = findSpawnRecordIndex(0x1C) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_43) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_43) & 0xFFFE) | bit;
        var_v1 = findSpawnRecordIndex(0x23) * 0xC;
        var_v0 = *(u16 *)(gKeyEntryFlagsTable + var_v1);
        var_a0 = 0xB;
        goto block_12;
    case 7:
        temp_v1_44 = findSpawnRecordIndex(0xF) * 0xC;
        bit = value & 1;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_44) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_44) & 0xFFFE) | bit;
        temp_v1_45 = findSpawnRecordIndex(0x51) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_45) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_45) & 0xFFFE) | bit;
        temp_v1_46 = findSpawnRecordIndex(0x4A) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_46) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_46) & 0xFFFE) | bit;
        temp_v1_47 = findSpawnRecordIndex(0x53) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_47) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_47) & 0xFFFE) | bit;
        temp_v1_48 = findSpawnRecordIndex(0x68) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_48) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_48) & 0xFFFE) | bit;
        temp_v1_49 = findSpawnRecordIndex(0x69) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_49) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_49) & 0xFFFE) | bit;
        var_v1 = findSpawnRecordIndex(0x49) * 0xC;
        var_v0 = *(u16 *)(gKeyEntryFlagsTable + var_v1);
        var_a0 = 0x64;
        goto block_12;
    case 8:
        temp_v1_50 = findSpawnRecordIndex(0x2E) * 0xC;
        bit = value & 1;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_50) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_50) & 0xFFFE) | bit;
        temp_v1_51 = findSpawnRecordIndex(0x2F) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_51) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_51) & 0xFFFE) | bit;
        temp_v1_52 = findSpawnRecordIndex(0x3B) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_52) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_52) & 0xFFFE) | bit;
        temp_v1_53 = findSpawnRecordIndex(0x3A) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_53) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_53) & 0xFFFE) | bit;
        temp_v1_54 = findSpawnRecordIndex(0x44) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_54) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_54) & 0xFFFE) | bit;
        temp_v1_55 = findSpawnRecordIndex(6) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_55) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_55) & 0xFFFE) | bit;
        temp_v1_56 = findSpawnRecordIndex(0x61) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_56) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_56) & 0xFFFE) | bit;
        var_v1 = findSpawnRecordIndex(0x36) * 0xC;
        var_v0 = *(u16 *)(gKeyEntryFlagsTable + var_v1);
        var_a0 = 0x37;
        goto block_12;
    case 9:
        temp_v1_57 = findSpawnRecordIndex(2) * 0xC;
        bit = value & 1;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_57) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_57) & 0xFFFE) | bit;
        temp_v1_58 = findSpawnRecordIndex(0x29) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_58) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_58) & 0xFFFE) | bit;
        temp_v1_59 = findSpawnRecordIndex(0x28) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_59) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_59) & 0xFFFE) | bit;
        temp_v1_60 = findSpawnRecordIndex(0x58) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_60) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_60) & 0xFFFE) | bit;
        var_v1 = findSpawnRecordIndex(0x43) * 0xC;
        var_v0 = *(u16 *)(gKeyEntryFlagsTable + var_v1);
        var_a0 = 0x4E;
block_12:
        *(u16 *)(gKeyEntryFlagsTable + var_v1) = (var_v0 & 0xFFFE) | bit;
        temp_v1_6 = findSpawnRecordIndex(var_a0) * 0xC;
        *(u16 *)(gKeyEntryFlagsTable + temp_v1_6) = (*(u16 *)(gKeyEntryFlagsTable + temp_v1_6) & 0xFFFE) | bit;
    }
done:
    *(gGroupUnlockFlags + (group & 0xFF)) = value;
}
