#define F(p,t,o) (*(t *)((char *)(p)+(o)))
void func_800452AC(void *,void *,void *);
f32 randomFloatScaled(f32);
void func_80047B14(void *,f32,void *);
void func_80063098(void *arg0) {
 f32 x; s32 n; u8 a; void *pos; void *p=F(arg0,void *,0x6c);
 F(arg0,f32,0x54)+=F(p,f32,0x14);
 x=randomFloatScaled(32.0f); pos=(char *)arg0+0x24;
 F(arg0,f32,0x44)+=x-randomFloatScaled(16.0f);
 func_800452AC(p,pos,pos);
 F(p,f32,4)-=0.0025520835f;
 a=F(arg0,u8,0x82); func_80047B14(p,0.95f,p);
 n=a-F(p,u8,0x26);
 a=n;
 if(n<0) { F(arg0,s32,0x60)|=1; return; }
 F(arg0,u8,0x82)=a;
}
