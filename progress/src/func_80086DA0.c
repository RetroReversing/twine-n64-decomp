extern s32 D_0000,D_0BA8,D_0DF0,D_0EA0,D_0F34,D_0F90,D_106C,D_110C,D_12B0,D_1334,D_13AC;
extern s32 D_00000,D_00BA8,D_00DF0,D_00EA0,D_00F34,D_00F90,D_0106C,D_0110C,D_012B0,D_01334,D_013AC;
void romDmaRead(s32,s32,u32);
extern s32 D_00000000,D_00000BA8,D_00000DF0,D_00000EA0,D_00000F34,D_00000F90,D_0000106C,D_0000110C,D_000012B0,D_00001334,D_000013AC;
extern s32 D_014977A0,D_014A8380,D_014BA940;
extern s16 D_800CE830;
extern s32 D_80108F7C,sDataEntryBase,sDataEntryOffsets0,sDataEntryOffsets1,sDataEntryOffsets2,sDataEntryOffsets3,sDataEntryOffsets6,sDataEntryOffsets7,sDataEntryOffsets8,sDataEntryOffsets9,sDataEntryOffsetsA,sDataEntryOffsetsB,sDataEntryOffsetsC;
#define INIT_DEFAULT() do { \
 sDataEntryOffsets0=sDataEntryBase+(s32)&D_0000; \
 sDataEntryOffsets1=sDataEntryBase+(s32)&D_0BA8; \
 sDataEntryOffsets2=sDataEntryBase+(s32)&D_0DF0; \
 sDataEntryOffsets3=sDataEntryBase+(s32)&D_0EA0; \
 sDataEntryOffsets6=(unsigned)sDataEntryBase+(s32)&D_0F90; \
 sDataEntryOffsetsA=sDataEntryBase+(s32)&D_106C; \
 sDataEntryOffsets7=sDataEntryBase+(s32)&D_1334; \
 sDataEntryOffsets8=sDataEntryBase+(s32)&D_0F34; \
 sDataEntryOffsets9=sDataEntryBase+(s32)&D_12B0; \
 sDataEntryOffsetsB=sDataEntryBase+(s32)&D_110C; \
 sDataEntryOffsetsC=sDataEntryBase+(s32)&D_13AC; \
} while (0)
#define INIT_TWO() do { \
 sDataEntryOffsets0=sDataEntryBase+(s32)&D_00000; \
 sDataEntryOffsets1=sDataEntryBase+(s32)&D_00BA8; \
 sDataEntryOffsets2=sDataEntryBase+(s32)&D_00DF0; \
 sDataEntryOffsets3=sDataEntryBase+(s32)&D_00EA0; \
 sDataEntryOffsets6=(unsigned)sDataEntryBase+(s32)&D_00F90; \
 sDataEntryOffsetsA=sDataEntryBase+(s32)&D_0106C; \
 sDataEntryOffsets7=sDataEntryBase+(s32)&D_01334; \
 sDataEntryOffsets8=sDataEntryBase+(s32)&D_00F34; \
 sDataEntryOffsets9=sDataEntryBase+(s32)&D_012B0; \
 sDataEntryOffsetsB=sDataEntryBase+(s32)&D_0110C; \
 sDataEntryOffsetsC=sDataEntryBase+(s32)&D_013AC; \
} while (0)
#define INIT_FIVE() do { \
 sDataEntryOffsets0=sDataEntryBase+(s32)&D_00000000; \
 sDataEntryOffsets1=sDataEntryBase+(s32)&D_00000BA8; \
 sDataEntryOffsets2=sDataEntryBase+(s32)&D_00000DF0; \
 sDataEntryOffsets3=sDataEntryBase+(s32)&D_00000EA0; \
 sDataEntryOffsets6=(unsigned)sDataEntryBase+(s32)&D_00000F90; \
 sDataEntryOffsetsA=sDataEntryBase+(s32)&D_0000106C; \
 sDataEntryOffsets7=sDataEntryBase+(s32)&D_00001334; \
 sDataEntryOffsets8=sDataEntryBase+(s32)&D_00000F34; \
 sDataEntryOffsets9=sDataEntryBase+(s32)&D_000012B0; \
 sDataEntryOffsetsB=sDataEntryBase+(s32)&D_0000110C; \
 sDataEntryOffsetsC=sDataEntryBase+(s32)&D_000013AC; \
} while (0)
s32 func_80086DA0(u16 arg0) {
 switch (arg0) {
 case 1:
 default:
   D_800CE830=1;
   romDmaRead(sDataEntryBase,(s32)&D_014977A0,D_80108F7C);
   INIT_DEFAULT();
   break;
 case 2:
   D_800CE830=2;
   romDmaRead(sDataEntryBase,(s32)&D_014A8380,D_80108F7C);
   INIT_TWO();
   break;
 case 5:
   D_800CE830=5;
   romDmaRead(sDataEntryBase,(s32)&D_014BA940,D_80108F7C);
   INIT_FIVE();
   break;
 }
 return 1;
}
