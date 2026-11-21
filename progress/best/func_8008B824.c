s32 func_80089384(s32,s32);
s32 audioSetupRateBuffer(s32,s32,s32);
s32 func_80054FEC(s32,s32,f32,void*,void*,s32,s32);
extern f64 D_800D6798;
extern char D_800D6780[];
extern s32 D_800E41E8,D_800E41EC,D_800E4230,D_800E4238,D_800E423C,D_801002D8,D_80103098,D_8010D428,dmaHandlerInit;
extern s8 sWorkerPendingCallback,D_8010309C;
extern u8 D_8010309D[0x101];
extern u8 D_8010319E[0x102];
extern s16 D_800E4268;
extern s32 (*gDataBankAlloc)(s32,s32,s32);
extern void (*D_8010016C)(void (*)(void));
extern void func_8008B25C(void);
void func_8008B824(s32 *arg0,s32 arg1,u16 arg2,s32 arg3){
f32 temp_fv1; f64 var_ft0; s32 temp_a2,temp_a2_2,temp_s0,temp_v0,var_a1,var_s0,var_v0,var_v0_2,var_v1;
var_s0=arg1;
if((u32)(var_s0&0xffff)>=0x21U)var_s0=0x20;
sWorkerPendingCallback=0; temp_s0=var_s0&0xffff;
func_80089384(temp_s0,*arg0);
audioSetupRateBuffer(temp_s0,*arg0,arg3&0xff);
temp_v0=*arg0; temp_a2=arg2&0xffff;
if(temp_a2!=0){u32 q=(u32)(temp_v0*temp_a2)/1000U;D_800E4230=0;temp_a2_2=((q/192U)*0xC0)+0xC0;D_800E423C=temp_a2_2;D_800E4238=gDataBankAlloc(temp_a2_2*2,0,temp_a2_2);}else{D_800E4238=0;}
(*(u16 *)&D_800E4268)=0xffff;dmaHandlerInit=0;D_8010D428=0;D_8010016C(&func_8008B25C);
temp_v0=*arg0;var_ft0=(f64)temp_v0;if(temp_v0<0)var_ft0+=D_800D6798;
temp_fv1=((f32)var_ft0*0.016666668f*0.0052083335f)+0.5f;
var_v1=(u32)temp_fv1;var_v0=var_v1*2;
D_800E41EC=var_v1;D_800E41E8=var_v1;D_801002D8=(var_v0+var_v1)<<6;D_8010309D[0]=0x10;D_8010309C=1;D_80103098=*arg0;
var_a1=0;if(D_800D6780[0]!=0){var_v0_2=0;do{var_a1+=1;D_8010319E[var_v0_2]=D_800D6780[var_v0_2];var_v0_2=var_a1&0xff;}while(D_800D6780[var_a1&0xff]!=0);}
D_8010319E[var_a1&0xff]=0;
}
