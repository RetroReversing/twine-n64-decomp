#define F(p,t,o) (*(t *)((char *)(p)+(o)))
void vec3Add(void *,void *,void *);
f32 randomFloatScaled(f32);
void func_80047B14(void *,f32,void *);
/* Moves a particle with random jitter, applies gravity and drag, and flags it for removal when its life runs out. */
void updateDriftingParticle(void *particle) {
 f32 jitterX; s32 lifeLeft; u8 life; void *posPtr; void *vel=F(particle,void *,0x6c);
 F(particle,f32,0x54)+=F(vel,f32,0x14);
 jitterX=randomFloatScaled(32.0f); posPtr=(char *)particle+0x24;
 F(particle,f32,0x44)+=jitterX-randomFloatScaled(16.0f);
 vec3Add(vel,posPtr,posPtr);
 F(vel,f32,4)-=0.0025520835f;
 life=F(particle,u8,0x82); func_80047B14(vel,0.95f,vel);
 lifeLeft=life-F(vel,u8,0x26);
 life=lifeLeft;
 if(lifeLeft<0) { F(particle,s32,0x60)|=1; return; }
 F(particle,u8,0x82)=life;
}
