extern void romDmaRead(s32,s32,u32);
extern s32 sDataEntryBase,D_800CE804,D_80108F7C;
extern void *D_800CE808,*D_800CE80C,*D_800CE810,*D_800CE814,*D_800CE818,*D_800CE81C,*D_800CE820,*D_800CE824,*D_800CE828,*D_800CE82C;
extern s16 D_800CE830;
extern s32 D_00000000,D_00000BA8,D_00000DF0,D_00000EA0,D_00000F34,D_00000F90,D_0000106C,D_0000110C,D_000012B0,D_00001334,D_000013AC,D_014977A0,D_014A8380,D_014BA940;
s32 func_80086DA0(s32 arg0) {
 s32 temp_a0=arg0&0xffff; void *var_v1;
 switch(temp_a0) {
 case 5: D_800CE830=5; romDmaRead(sDataEntryBase,(s32)&D_014977A0,D_80108F7C); goto shared;
 case 2: D_800CE830=2; romDmaRead(sDataEntryBase,(s32)&D_014A8380,D_80108F7C); goto shared;
 default: D_800CE830=1; do { romDmaRead(sDataEntryBase,(s32)&D_014BA940,D_80108F7C); } while (0);
 }
shared:
 D_800CE804=(void *)(sDataEntryBase+(s32)&D_00000000); D_800CE808=(void *)(sDataEntryBase+(s32)&D_00000BA8); D_800CE80C=(void *)(sDataEntryBase+(s32)&D_00000DF0); D_800CE810=(void *)(sDataEntryBase+(s32)&D_00000EA0); D_800CE814=(void *)(sDataEntryBase+(s32)&D_00000F90); D_800CE818=(void *)(sDataEntryBase+(s32)&D_0000106C); D_800CE81C=(void *)(sDataEntryBase+(s32)&D_00001334); D_800CE820=(void *)(sDataEntryBase+(s32)&D_00000F34); D_800CE824=(void *)(sDataEntryBase+(s32)&D_000012B0); D_800CE828=(void *)(sDataEntryBase+(s32)&D_0000110C); var_v1=(void *)(sDataEntryBase+(s32)&D_000013AC); D_800CE82C=var_v1; return 1;
}
