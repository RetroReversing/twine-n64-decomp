typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 randomU32Next();
M2C_UNK applyBlastToNearbyObjects(M2C_UNK, f32, f32, void *, void *, s32, s32);
M2C_UNK objectUpdateHookStub(s32 *);
s32 triggerNearbyBonusObject(void *);
M2C_UNK actorRespawnAtRandomPoint(void *);
M2C_UNK objectUpdateAnimByState(void *);
M2C_UNK spawnImpactBurstEffect(void *, void *, f32, M2C_UNK);
M2C_UNK setActorStatusBits(void *);
M2C_UNK clearObjectStateBits(void *);
M2C_UNK updateTrackMarkerProximity(void *, f32);
M2C_UNK playFarMarkerSound(void *);
/* Timed two-state object update: state 0 counts a 900-frame timer then re-arms it randomly; state 3 runs a triggered effect. */ void updateTimedObjectState(void *obj) {
s16 state; s32 *timer; s32 flags; void *effectPos;
state=M2C_FIELD(obj,s16 *,0x7A); timer=M2C_FIELD(obj,s32 **,0x6C);
switch(state) {
case 0:
M2C_FIELD(obj,s32 *,0x60)=M2C_FIELD(obj,s32 *,0x60)&~2;
*timer+=1; clearObjectStateBits(obj);
if(*timer>=0x384) { objectUpdateAnimByState(obj); setActorStatusBits(obj); objectUpdateHookStub(timer); *timer=(u32)randomU32Next()%450U; M2C_FIELD(obj,s16 *,0x7A)=3; return; } return;
case 3:
flags=M2C_FIELD(obj,s32 *,0x60);
if(flags&2) { effectPos=obj+0x24; M2C_FIELD(obj,s32 *,0x60)=flags&~2;
applyBlastToNearbyObjects(0,250.0f,5.0f,obj,effectPos,0x20,0);
spawnImpactBurstEffect(obj,effectPos,1.0f,1); updateTrackMarkerProximity(effectPos,0.001f); playFarMarkerSound(effectPos); goto block_8;
}
if((triggerNearbyBonusObject(obj)<<0x18)!=0) { block_8: actorRespawnAtRandomPoint(obj); }
break;
}
}
