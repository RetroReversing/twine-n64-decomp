s32 func_800957A8();
extern char D_80107ED4[]; extern s32 D_80107ED8; extern char D_80107EDC[]; extern char D_80107EE0[]; extern char D_80107EE4[]; extern char D_80107EE8[]; extern char D_80107EE9[];
void func_8008EB80(s32 arg0,s32 arg1,s32 arg2,s8 arg3,s32 arg4) {
s32 sp10,var_s1,temp_s0,temp_v1,var_a0,var_a0_2,var_a0_3,var_v0; char *var_a1,*var_a1_2,*var_a1_3; u32 var_a2,var_a2_2,var_a2_3;
var_s1=arg1;if(!(var_s1&0xFFFF))var_s1=arg1+1;temp_s0=var_s1&0xFFFF;sp10=temp_s0;func_800957A8(&sp10);
switch(arg2&0xFF){
case 0xFF: var_a2=0;var_a1=&D_80107ED8;var_a0=0;do{if((u8)*(D_80107EE8+var_a0)<2U){*(s32*)var_a1=(arg0&0xFF)<<16;*(D_80107EE0+var_a0)=sp10;*(D_80107EE4+var_a0)=-1;*(D_80107EDC+var_a0)=(s32)(*(s32*)var_a1-*(D_80107ED4+var_a0))/(s32)(var_s1&0xFFFF);}var_a1+=0x28;var_a2++;var_a0+=0x28;}while(var_a2<0x20U);return;
case 0xFC: var_a2_2=0;var_a1_2=&D_80107ED8;var_a0_2=0;do{if((u32)(*(D_80107EE8+var_a0_2)-2)<2U){*(s32*)var_a1_2=(arg0&0xFF)<<16;*(D_80107EE0+var_a0_2)=sp10;*(D_80107EE4+var_a0_2)=-1;*(D_80107EDC+var_a0_2)=(s32)(*(s32*)var_a1_2-*(D_80107ED4+var_a0_2))/(s32)(var_s1&0xFFFF);}var_a1_2+=0x28;var_a2_2++;var_a0_2+=0x28;}while(var_a2_2<0x20U);return;
case 0xFA:var_v0=2;goto block18;case 0xFB:var_v0=3;goto block18;case 0xFD:var_v0=0;goto block18;case 0xFE:var_v0=1;
block18:var_a2_3=0;var_a1_3=&D_80107ED8;var_a0_3=0;do{if(*(D_80107EE8+var_a0_3)==(var_v0&0xFF)){*(s32*)var_a1_3=(arg0&0xFF)<<16;*(D_80107EE0+var_a0_3)=sp10;*(D_80107EE4+var_a0_3)=-1;*(D_80107EDC+var_a0_3)=(s32)(*(s32*)var_a1_3-*(D_80107ED4+var_a0_3))/(s32)(var_s1&0xFFFF);}var_a1_3+=0x28;var_a2_3++;var_a0_3+=0x28;}while(var_a2_3<0x20U);return;
default:temp_v1=(arg2&0xFF)*0x28;*(s32*)(D_80107ED8+temp_v1)=(arg0&0xFF)<<16;*(D_80107EE9+temp_v1)=arg3;*(D_80107EE4+temp_v1)=arg4;*(D_80107EE0+temp_v1)=sp10;*(D_80107EDC+temp_v1)=(s32)(*(s32*)(D_80107ED8+temp_v1)-*(D_80107ED4+temp_v1))/temp_s0;return;
}}
