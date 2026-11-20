s32 func_8000A18C(); s32 func_8000A22C(); s32 func_8000A6F4(); s32 func_8000B384(); s32 func_8000B534(); s32 func_8000B900(); s32 func_80088AC0(); s32 func_80088C50(); s32 func_80092A68(); s32 func_80095820(); s32 func_8009CE34(); s32 func_8009CF18(); s32 func_8009D030();
extern char D_14CD630[],D_14D0ED0[],D_14DDC00[],D_14E2500[],D_1D69630[],D_800B2488[],D_800B256C[],D_800DD7D0[];
extern s32 D_800B2480,D_800E06B0,D_800E06FC,D_800E0700,D_800E0704,D_800E0708; extern s32 *D_800E070C; extern s16 D_80108400;
s32 func_80009F04(void) {
s32 temp_s0; s32 temp_s2,temp_s2_2,temp_v0,temp_v0_2,temp_v0_3,var_s0,var_v0; u16 temp_a1;
var_v0=0;
if(func_80095820(0x5622,0x14,0xA,0xA,0xFA,-(D_80108400!=0)&0x140000)==0){
temp_s2=D_14D0ED0-D_14CD630; temp_v0=func_8000B384(temp_s2,0); D_800E06FC=temp_v0; func_8000B900(temp_v0,(s32)&D_14CD630&0x0FFFFFFF,temp_s2);
temp_s2_2=D_14DDC00-D_14D0ED0; temp_v0_2=func_8000B384(temp_s2_2,0); D_800E0700=temp_v0_2; func_8000B900(temp_v0_2,(s32)&D_14D0ED0&0x0FFFFFFF,temp_s2_2);
temp_s2_2=D_14DDC00-D_14DDC00; temp_v0_3=func_8000B384(temp_s2_2,0); D_800E0704=temp_v0_3; func_8000B900(temp_v0_3,(s32)&D_14DDC00&0x0FFFFFFF,temp_s2_2);
func_80092A68(D_800E06FC,0,D_14E2500,D_800E0704,D_800E0700); var_s0=0;
if(D_800B2480!=0){do{temp_a1=*(u16 *)(D_800B2488+var_s0);var_s0+=0xC;func_80092A68(D_800E06FC,temp_a1,D_14E2500,D_800E0704,D_800E0700);}while(*(s32 *)(D_800B2480+var_s0)!=0);}
func_8009CE34(0xE7,0);func_8009CE34(0xE8,0);func_8009CE34(0xE9,0);func_8009CE34(0xEA,0);func_8009CE34(0xEB,0);func_8009CE34(0xEC,0);func_8009CE34(0xED,0);func_8009CE34(0xEE,0);func_8009CF18(0x7F,0,0);func_8009CE34(0x1B8,1);func_80088C50(1);func_80088AC0(D_1D69630,0);func_8009D030(D_800B256C);D_800E0708=-1;D_800E070C=D_800DD7D0;func_8000A6F4();D_800E06B0=-1;temp_s0=func_8000B534();func_8000A18C(0xA);func_8000A22C(0xA);var_v0=temp_s0;
}
return temp_s0;
}
