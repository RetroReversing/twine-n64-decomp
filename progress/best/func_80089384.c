extern u32 (*gDataBankAlloc)(s32, s32);
extern u32 gAudioVoiceTable, D_800E41E0, D_800E4220, D_800E4224, D_800E422C;
extern u16 D_800E41E4, D_800E4216;
extern s16 D_800E4228, D_800E422A;
extern u8 D_800E41E6;
extern u8 D_8010086C;
extern f64 D_800D66F0, D_800D66F8;
extern u32 D_80000001;
extern int bzero();
extern int func_800A0220();
void func_80089384(u16 arg0, s32 arg1) {
 s32 i; u32 p; f64 d; f32 f, x; s32 n;
 D_800E41E4=arg0;
 p=gDataBankAlloc(arg0*0x68,0); D_800E41E0=p; gAudioVoiceTable=p; D_800E41E6=0;
 for(i=0;i<D_800E41E4;i++){ n=i*0x68; *(u32 *)(p+n)=0; *(u8 *)(p+n+0x61)=0; *(u8 *)(p+n+0x60)=0xff; }
 if(D_8010086C==0){ d=(f64)arg1; if(arg1<0)d+=D_800D66F0; f=(f32)d*0.000125f; }
 else { d=(f64)arg1; if(arg1<0)d+=D_800D66F8; f=(f32)d*0.00025f; }
 if(f>=2.1474836e9f){ x=f-2.1474836e9f; D_800E4216=(s32)x| (u32)&D_80000001; }
 else D_800E4216=(s32)f+1;
 D_800E4220=gDataBankAlloc(D_800E4216*0xA10,0);
 D_800E4224=gDataBankAlloc(D_800E4216*0xA10,0);
 D_800E422A=0; D_800E4228=0;
 p=gDataBankAlloc(0x298,0); D_800E422C=p; bzero(p,0x298); func_800A0220(D_800E422C,0x298);
}
