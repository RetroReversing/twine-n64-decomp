typedef struct { u8 a; u8 pad[0x5F]; u8 b60; u8 b61; u8 pad2[6]; } Voice;
extern u32 (*gDataBankAlloc)(s32, s32);
extern Voice *gAudioVoiceTable, *D_800E41E0;
extern u32 D_800E4220, D_800E4224, D_800E422C;
extern u16 D_800E41E4, D_800E4216;
extern s16 D_800E4228, D_800E422A;
extern u8 D_800E41E6;
extern u8 D_8010086C;
extern int bzero();
extern int func_800A0220();
void func_80089384(u16 arg0, u32 arg1) {
 u16 i; Voice *p; f32 f;
 D_800E41E4=arg0;
 p=(Voice *)gDataBankAlloc(arg0*0x68,0); D_800E41E0=p; gAudioVoiceTable=p; D_800E41E6=0;
 for(i=0;i<D_800E41E4;i++){ D_800E41E0[i].a=0; D_800E41E0[i].b61=0; D_800E41E0[i].b60=0xff; }
 if(D_8010086C==0){ f=arg1*0.000125f; D_800E4216=(u32)f+1; }
 else { f=arg1*0.00025f; D_800E4216=(u32)f+1; }
 D_800E4220=gDataBankAlloc(D_800E4216*0xA10,0);
 D_800E4224=gDataBankAlloc(D_800E4216*0xA10,0);
 D_800E422A=0; D_800E4228=0;
 p=(Voice *)gDataBankAlloc(0x298,0); D_800E422C=(u32)p; bzero(p,0x298); func_800A0220(D_800E422C,0x298);
}
