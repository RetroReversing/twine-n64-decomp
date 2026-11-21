s32 func_80087F60(s32); s32 func_800936A8(s32); s32 func_8009D510(void *,s32,s32,s32,void *); s32 func_800A0170(s32,s32); s32 osCreateMesgQueue(void *,void *,s32); s32 osRecvMesg(void *,void *,s32); s32 osSendMesg(void *,s32,s32);
extern u8 D_800E1AC0; extern u8 D_800E2CC0; extern s32 D_800E3F24[2]; extern s32 D_800E3F2C; extern u8 D_800E3F30[24]; extern u8 D_8010086C; extern void *gDataBankAlloc; extern s32 sDataBankAux; extern u32 sDataBankCount; extern u8 sDataBankEnabled; extern s32 sDataBankTable[1]; extern s32 func_80088F6C;
s32 func_80088040(s32 arg0, void *arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6) {
s32 temp_a0,temp_v0,temp_v0_2,var_s2,var_v1,var_v1_2; void *temp_s1,*var_s0;
var_s0=arg1;
if(sDataBankEnabled){var_s2=0;if((u32)arg0<(u32)sDataBankCount){var_v1=0;loop_3: if(*((u8*)&D_800E2CC0+var_v1)!=0){var_s2++;var_v1+=0x1228;if(var_s2<2)goto loop_3;}
if(var_s2!=2){temp_s1=(void*)(var_s2*0x1228+(u8*)&D_800E1AC0);osCreateMesgQueue(temp_s1+0x11E0,temp_s1+0x11F8,2);var_v1_2=(s32)var_s0*8;if(!var_s0){var_s0=(void*)0x3E80;if(*((s32*)sDataBankTable+arg0)==0)var_s0=(void*)0x1F40;var_v1_2=(s32)var_s0*8;}
*((s8*)temp_s1+0x1204)=(s8)arg2;*((s8*)temp_s1+0x1201)=(s8)arg3;*((u8*)temp_s1+0x1202)=arg4;*((u8*)temp_s1+0x1203)=arg5;*((u8*)temp_s1+0x1219)=arg6;*((void**)((u8*)temp_s1+0x1208))=var_s0;
temp_a0=(((var_v1_2/30)+0x9F)/160)*0xA0;*((s32*)((u8*)temp_s1+0x1214))=temp_a0;
if(D_800E3F2C&1)*((s32*)((u8*)temp_s1+0x1210))=D_800E3F24[var_s2];else{temp_v0=func_800936A8(temp_a0);temp_v0_2=((s32(*)(s32,s32))gDataBankAlloc)(temp_v0,0);*((s32*)((u8*)temp_s1+0x1210))=temp_v0_2;func_800A0170(temp_v0_2,temp_v0);}
if(*((s32*)((u8*)temp_s1+0x1210))){osRecvMesg(D_800E3F30,0,1);func_8009D510(temp_s1,(*((s32*)sDataBankTable+arg0)&0xFFFFFF)+sDataBankAux,*((s32*)((u8*)temp_s1+0x1210)),*((s32*)((u8*)temp_s1+0x1214)),&func_80088F6C);if(D_8010086C)*((u8*)temp_s1+0x11DE)*=2;*((s32*)((u8*)temp_s1+0x120C))=-1;*((u8*)temp_s1+0x1200)=1;osSendMesg(D_800E3F30,0,0);return func_80087F60(var_s2);}goto done;}goto done;}}
done:return -1;}
