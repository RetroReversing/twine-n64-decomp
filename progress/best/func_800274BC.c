typedef struct { u32 v; } __attribute__((packed)) U32U;
#define FLD(p, off, T) (*(T *)((u8 *)(p) + (off)))
extern void *gMenuState;
extern u8 D_801002E6;
extern u32 D_800BD640[];
extern s32 D_80102EBC;
extern s32 D_80102EC0;
extern s32 D_80102EC4;
extern void *sActiveMenu;
void requestSound(s32);
s32 layoutTextBox(s32, void *, s32);
void func_800274BC(s32 arg0, u8 arg1, void *arg2, void *arg3) {
u8 *__base_D_801002E6;
u8 *s0,*s2,*a2,*p; void *a3; volatile u32 frame[2];
u8 t0,s1,a1,a0,cnt,bb; u32 v0,val; u16 fl; s32 i; s32 __repair_phase_i; s32 tv;
a1=arg1; a2=arg2; a3=arg3;
if(gMenuState==NULL)return;
s0=FLD(gMenuState,0x18,u8 *); s2=FLD(gMenuState,0x10,u8 *); t0=FLD(gMenuState,8,u8);
if(FLD(gMenuState,0x1C,s32)==0)goto cleanup; if(s2==NULL)goto cleanup; if(s0==NULL)goto cleanup;
s1=t0;
if(arg0==0x100){if(a1==0xFF)return; tv=FLD(s0+a1,0x24,s8); if(tv<0)return; i=(u8)tv; if(i==(s1&0xFF))return; s1=(u8)tv; __base_D_801002E6=&D_801002E6; a3=__base_D_801002E6; *(U32U *)(s0+0x24)=*(U32U *)&D_801002E6; a2=FLD(s2,0,u8 *)+i*40; if(a2!=NULL)*(U32U *)&D_801002E6=*(U32U *)(a2+0x24); v0=s1&0xFF;}else{v0=s1&0xFF;if(arg0==0x101){cnt=FLD(s2,5,u8);a0=s1;if(v0<cnt){a1=cnt;cnt=0;do{p=FLD(s2,0,u8 *)+(a0&0xFF)*40;if(FLD(p,0xC,u16)&0x80){s1=a0;a0=0;break;}a0++;}while((u8)a0<a1);}v0=s1&0xFF;a2=FLD(s2,0,u8 *)+v0*40;if(a2!=NULL){*(U32U *)&D_801002E6=*(U32U *)(a2+0x24);v0=s1&0xFF;}}}
if(v0!=t0&&FLD(sActiveMenu,0x7A,s16)!=0x14)requestSound(0xED);
a0=FLD(gMenuState,8,u8);if(FLD(gMenuState,7,u8)!=a0)FLD(gMenuState,7,u8)=a0;FLD(gMenuState,0x2E,s8)=1;
fl=FLD(s0,0xC,u16);i=fl&0xF;if(i!=0){val=D_800BD640[i];bb=FLD(gMenuState,0x30,u8);}else{if(fl&0x80){val=D_80102EBC;bb=FLD(FLD(s0,8,u8 *),0x13,u8);}else{val=D_80102EC4;bb=FLD(FLD(s0,8,u8 *),0x13,u8);}}
FLD(FLD(s0,8,u8 *),0x10,u32)=(val&~0xFF)|bb;FLD(gMenuState,8,u8)=s1;p=FLD(s2,0,u8 *)+(s1&0xFF)*40;FLD(gMenuState,0x18,u8 *)=p;
if(FLD(p,8,u8 *)!=NULL){fl=FLD(p,0xC,u16);__repair_phase_i=fl&0xF;if(__repair_phase_i!=0){val=D_800BD640[__repair_phase_i];bb=FLD(gMenuState,0x30,u8);}else{val=D_80102EC0;bb=FLD(FLD(p,8,u8 *),0x13,u8);}FLD(FLD(p,8,u8 *),0x10,u32)=(val&~0xFF)|bb;}
layoutTextBox(FLD(gMenuState,0x1C,s32),p,0);
cleanup:return;
}
