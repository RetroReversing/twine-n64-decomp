extern u8 D_0[], func_00000000[];
extern u8 D_00000BA8[], func_00000BA8[];
extern u8 D_00000DF0[], func_00000DF0[];
extern u8 D_00000EA0[], func_00000EA0[];
extern u8 D_00000F90[], func_00000F90[];
extern u8 D_0000106C[], func_0000106C[];
extern u8 D_00001334[], func_00001334[];
extern u8 D_00000F34[], func_00000F34[];
extern u8 D_000012B0[], func_000012B0[];
extern u8 D_0000110C[], func_0000110C[];
extern u8 *sDataEntryBase;
extern s16 D_800CE830;
extern s32 D_80108F7C;
extern void romDmaRead(s32, s32, u32);
extern u8 D_14977A0[], D_14A8380[], D_14BA940[];
extern u8 *volatile sDataEntryOffsets0;
extern u8 D_00000000[];
extern u8 *volatile sDataEntryOffsets1;
extern u8 D_BA8[];
extern u8 *volatile sDataEntryOffsets2;
extern u8 D_DF0[];
extern u8 *volatile sDataEntryOffsets3;
extern u8 D_EA0[];
extern u8 *volatile sDataEntryOffsets6;
extern u8 D_F90[];
extern u8 *volatile sDataEntryOffsetsA;
extern u8 D_106C[];
extern u8 *volatile sDataEntryOffsets7;
extern u8 D_1334[];
extern u8 *volatile sDataEntryOffsets8;
extern u8 D_F34[];
extern u8 *volatile sDataEntryOffsets9;
extern u8 D_12B0[];
extern u8 *volatile sDataEntryOffsetsB, *volatile D_800CE828, *volatile func_800CE828;
extern u8 D_110C[];
extern u8 *volatile sDataEntryOffsetsC;
extern u8 D_13AC[], D_000013AC[], func_000013AC[];
s32 func_80086DA0(u16 language)
{
    u8 *base;
    switch (language) {
    case 1:
    default:
        D_800CE830 = 1;
        romDmaRead((s32)sDataEntryBase, (s32)D_14977A0, D_80108F7C);
        base = sDataEntryBase;
        sDataEntryOffsets0 = base + (u32)D_00000000;
        sDataEntryOffsets1 = base + (u32)D_BA8;
        sDataEntryOffsets2 = base + (u32)D_DF0;
        sDataEntryOffsets3 = base + (u32)D_EA0;
        sDataEntryOffsets6 = base + (u32)D_F90;
        sDataEntryOffsetsA = base + (u32)D_106C;
        sDataEntryOffsets7 = base + (u32)D_1334;
        sDataEntryOffsets8 = base + (u32)D_F34;
        sDataEntryOffsets9 = base + (u32)D_12B0;
        sDataEntryOffsetsB = base + (u32)D_110C;
        sDataEntryOffsetsC = base + (u32)D_13AC;
        break;
    case 2:
        D_800CE830 = 2;
        romDmaRead((s32)sDataEntryBase, (s32)D_14A8380, D_80108F7C);
        base = sDataEntryBase;
        sDataEntryOffsets0 = base + (u32)D_0;
        sDataEntryOffsets1 = base + (u32)D_00000BA8;
        sDataEntryOffsets2 = base + (u32)D_00000DF0;
        sDataEntryOffsets3 = base + (u32)D_00000EA0;
        sDataEntryOffsets6 = base + (u32)D_00000F90;
        sDataEntryOffsetsA = base + (u32)D_0000106C;
        sDataEntryOffsets7 = base + (u32)D_00001334;
        sDataEntryOffsets8 = base + (u32)D_00000F34;
        sDataEntryOffsets9 = base + (u32)D_000012B0;
        D_800CE828 = base + (u32)D_0000110C;
        sDataEntryOffsetsC = base + (u32)D_000013AC;
        break;
    case 5:
        D_800CE830 = 5;
        romDmaRead((s32)sDataEntryBase, (s32)D_14BA940, D_80108F7C);
        base = sDataEntryBase;
        sDataEntryOffsets0 = base + (u32)func_00000000;
        sDataEntryOffsets1 = base + (u32)func_00000BA8;
        sDataEntryOffsets2 = base + (u32)func_00000DF0;
        sDataEntryOffsets3 = base + (u32)func_00000EA0;
        sDataEntryOffsets6 = base + (u32)func_00000F90;
        sDataEntryOffsetsA = base + (u32)func_0000106C;
        sDataEntryOffsets7 = base + (u32)func_00001334;
        sDataEntryOffsets8 = base + (u32)func_00000F34;
        sDataEntryOffsets9 = base + (u32)func_000012B0;
        func_800CE828 = base + (u32)func_0000110C;
        sDataEntryOffsetsC = base + (u32)func_000013AC;
        break;
    }
    return 1;
}
