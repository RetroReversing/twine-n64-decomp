typedef struct { u8 a; u8 pad[0x5F]; u8 b60; u8 b61; u8 pad2[6]; } Voice;
extern u32 (*gDataBankAlloc)(s32, s32);
extern Voice *gAudioVoiceTable, *D_800E41E0;
extern u32 D_800E4220, D_800E4224, D_800E422C;
extern u16 D_800E41E4, D_800E4216;
extern s16 D_800E4228, D_800E422A;
extern u8 D_800E41E6;
extern u8 D_8010086C;
extern f64 D_800D66F0, D_800D66F8;
extern u32 D_80000001;
extern int bzero();
extern int func_800A0220();
void func_80089384(u16 arg0, s32 arg1) {
 u16 i; Voice *p; f64 d; f32 f, x;
 D_800E41E4=arg0;
 p=(Voice *)gDataBankAlloc(arg0*0x68,0); D_800E41E0=p; gAudioVoiceTable=p; D_800E41E6=0;
 for(i=0;i<D_800E41E4;i++){ D_800E41E0[i].a=0; D_800E41E0[i].b61=0; D_800E41E0[i].b60=0xff; }
 if(D_8010086C==0){ d=(f64)arg1; if(arg1<0)d+=D_800D66F0; f=(f32)d*0.000125f;
  if(f>=2.1474836e9f){ x=f-2.1474836e9f; D_800E4216=(s32)x| (u32)&D_80000001; }
  else D_800E4216=(s32)f+1; }
 else { d=(f64)arg1; if(arg1<0)d+=D_800D66F8; f=(f32)d*0.00025f;
  if(f>=2.1474836e9f){ x=f-2.1474836e9f; D_800E4216=(s32)x| (u32)&D_80000001; }
  else D_800E4216=(s32)f+1; }
 D_800E4220=gDataBankAlloc(D_800E4216*0xA10,0);
 D_800E4224=gDataBankAlloc(D_800E4216*0xA10,0);
 D_800E422A=0; D_800E4228=0;
 p=(Voice *)gDataBankAlloc(0x298,0); D_800E422C=(u32)p; bzero(p,0x298); func_800A0220(D_800E422C,0x298);
}
