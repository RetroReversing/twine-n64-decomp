#define M2C_FIELD(e,t,o) (*(t)((s8 *)(e)+(o)))
void *spawnEffectObject(); s32 objectListInsert(); void objectSetAnimFrame(void *,s32,s32); u32 randomIntBelow(s32); f32 randomFloatScaled(f32); extern f64 D_800D4130;
void func_8005D070(void *arg0,u32 arg1,void *arg2,void *arg3) {
 f32 sp10[3],t,r; f64 d; u32 i; void *s,*v;
 for(i=0;i<arg1;i++){r=randomFloatScaled(1.0f); t=r*(M2C_FIELD(arg3,f32*,4)-M2C_FIELD(arg2,f32*,4))+M2C_FIELD(arg2,f32*,4); sp10[1]=t;
 if(t<M2C_FIELD(M2C_FIELD(arg0,void**,0x20),f32*,0x5c)){sp10[0]=r*(M2C_FIELD(arg3,f32*,0)-M2C_FIELD(arg2,f32*,0))+M2C_FIELD(arg2,f32*,0);sp10[2]=r*(M2C_FIELD(arg3,f32*,8)-M2C_FIELD(arg2,f32*,8))+M2C_FIELD(arg2,f32*,8);v=spawnEffectObject(0x20,sp10,0);
 if(v){s=M2C_FIELD(v,void**,0x6c);objectSetAnimFrame(v,0,0x1b);M2C_FIELD(v,s16*,0x78)=9;M2C_FIELD(s,s16*,0x1c)=randomIntBelow(0xb4);d=(f64)randomFloatScaled(0.025f)-0.0125;M2C_FIELD(s,s32*,8)=0;M2C_FIELD(s,f32*,4)=(f32)d;M2C_FIELD(s,f32*,0xc)=(f32)((f64)randomFloatScaled(0.025f)-0.0125);M2C_FIELD(v,f32*,0x54)=(f32)((f64)randomFloatScaled(0.5f)+D_800D4130);objectListInsert(v,arg0);M2C_FIELD(v,s8*,0x7f)=0;M2C_FIELD(v,s8*,0x80)=0;M2C_FIELD(v,s8*,0x81)=0x55;}}}
}
