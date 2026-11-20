/* identical to viMgrMain in PENNY RACERS (local match library) (matched), with its names changed by decompdecomp */
extern u16 D_800FEE40; extern u32 D_80102F34,D_801002F8; extern u64 D_80108790;
void *func_800A9780(void); void vi_apply_context(void); u32 func_800A91F0(void); void __osTimerInterrupt(void); void osRecvMesg(s32,void*,s32);void osSendMesg(s32,s32,s32);
#define F(p,t,o) (*(t*)((u8*)(p)+(o)))
void viMgrMain(void *arg0){
 u16 *msg=NULL; s32 first=0; u32 count; void *ctx; void *q;
 ctx=arg0;
 D_800FEE40=F(func_800A9780(),u16,2); if(!D_800FEE40)D_800FEE40=1;
 first=0;
 q=ctx;
 for(;;){osRecvMesg(F(q,s32,12),&msg,1);switch(*msg){case 13:
 vi_apply_context(); if(--D_800FEE40==0){ctx=func_800A9780();if(F(ctx,s32,16))osSendMesg(F(ctx,s32,16),F(ctx,s32,20),0);D_800FEE40=F(ctx,u16,2);}
 D_80102F34++;if(first){first=0;count=func_800A91F0();D_80108790=count;}
 count=D_801002F8;D_801002F8=func_800A91F0();count=D_801002F8-count;D_80108790+=count;break;
 case 14:__osTimerInterrupt();break;}}}
