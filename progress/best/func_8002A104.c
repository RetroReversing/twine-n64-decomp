#define F(p,t,o) (*(t *)((char *)(p)+(o)))
extern void *D_80109BB0;
void *func_800262A8(s32, s32);
void func_8002A104(void *arg0) {
 void *p=func_800262A8(F(D_80109BB0,s32,0x10),4);
 if (p) { void *q=F(p,void *,8); if ((q != 0) & (arg0 != 0)) {
 F(q,u8,0x29)=(u32)(F(arg0,f32,12)*(f32)F(p,u32,0x14))+1;
 q=F(p,void *,8); if (F(p,u32,0x14)<F(q,u8,0x29)) F(q,u8,0x29)=F(p,u32,0x14);
 }}
}
