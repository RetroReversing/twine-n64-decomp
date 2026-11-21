typedef struct Obj {u8 pad0[0x11A0];s32 f11A0;u8 pad1[0x3D];u8 f11DD;u8 pad2[0x22];u8 status,c1,c2,c3;s32 c4,d4,ret,p10,p14;u8 cmd,d9;u8 pad3[2];s32 dc;f32 e0;s32 p24;} Obj;
extern u8 sDataBankEnabled; extern f64 D_800D66D0; extern u8 D_800E1AC0; extern volatile u8 D_800E2CC0[]; extern s32 D_800E3F30,D_800E3F2C; extern void (*gDataBankFree)(s32); extern s32 func_80088EE4;
void func_8008863C(void) {
Obj *o; volatile u64 stack_pad[0]; s32 i; f64 tmp; s32 ret,t;
    extern s32 startAudioVoice(u8,s32,s32,s32,u8,u8,u8,u8,s32,s32);
if(sDataBankEnabled){osRecvMesg(&D_800E3F30,0,1);for(i=0;i<2;i++){o=(Obj*)((u8*)&D_800E1AC0+i*0x1228);if(D_800E2CC0[i]!=0){t=D_800E2CC0[i];func_8009D5D4(o);if(t==1){if((s8)o->f11DD==2){t=o->d4;tmp=(f64)t;if(t<0)tmp+=D_800D66D0;o->dc=0;D_800E2CC0[i]=2;o->e0=((f32)o->f11A0*160.0f)/(f32)tmp;func_8009D9B8(o);ret=startAudioVoice(o->c4,o->p10,o->d4,o->d4,o->c1,o->c2,o->c3,o->d9,(s32)&func_80088EE4,i);o->ret=ret;if(ret==-1){func_8009D9D8(o);if(!(D_800E3F2C&1))gDataBankFree(o->p10);o->status=0;}}}else if(t==2){if((s8)o->f11DD==4){D_800E2CC0[i]=3;o->cmd=4;}}else if(t==3){if(o->cmd==0){if(!(D_800E3F2C&1))gDataBankFree(o->p10);o->status=0;}else{if(o->cmd==2){func_80093758(o->ret);o->ret=-1;}o->cmd=(s8)(o->cmd-1);}}}}
osSendMesg(&D_800E3F30,0,0);
}
}
