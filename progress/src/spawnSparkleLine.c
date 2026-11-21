#define M2C_FIELD(e,t,o) (*(t)((s8 *)(e)+(o)))
void *spawnEffectObject(); s32 objectListInsert(); void effectSetAnimFrame(void *,s32,s32); u32 randomIntBelow(s32); f32 randomFloatScaled(f32); extern f64 kSparkFallSpeedBase;

/* Spawns 'count' sparkle effects at random points on the segment from 'from' to 'to', each with a random drift and fall speed, skipping points above the owner's limit height. */
void spawnSparkleLine(void *owner,u32 count,void *from,void *to) {
 f32 pos[3],t,r; f64 d; u32 i; void *sparkle,*state;
 for(i=0;i<count;i++){r=randomFloatScaled(1.0f); t=r*(M2C_FIELD(to,f32*,4)-M2C_FIELD(from,f32*,4))+M2C_FIELD(from,f32*,4); pos[1]=t;
 if(t<M2C_FIELD(M2C_FIELD(owner,void**,0x20),f32*,0x5c)){pos[0]=r*(M2C_FIELD(to,f32*,0)-M2C_FIELD(from,f32*,0))+M2C_FIELD(from,f32*,0);pos[2]=r*(M2C_FIELD(to,f32*,8)-M2C_FIELD(from,f32*,8))+M2C_FIELD(from,f32*,8);sparkle=spawnEffectObject(0x20,pos,0);
 if(sparkle){state=M2C_FIELD(sparkle,void**,0x6c);effectSetAnimFrame(sparkle,0,0x1b);M2C_FIELD(sparkle,s16*,0x78)=9;M2C_FIELD(state,s16*,0x1c)=randomIntBelow(0xb4);d=(f64)randomFloatScaled(0.025f)-0.0125;M2C_FIELD(state,s32*,8)=0;M2C_FIELD(state,f32*,4)=(f32)d;M2C_FIELD(state,f32*,0xc)=(f32)((f64)randomFloatScaled(0.025f)-0.0125);M2C_FIELD(sparkle,f32*,0x54)=(f32)((f64)randomFloatScaled(0.5f)+kSparkFallSpeedBase);objectListInsert(sparkle,owner);M2C_FIELD(sparkle,s8*,0x7f)=0;M2C_FIELD(sparkle,s8*,0x80)=0;M2C_FIELD(sparkle,s8*,0x81)=0x55;}}}
}
