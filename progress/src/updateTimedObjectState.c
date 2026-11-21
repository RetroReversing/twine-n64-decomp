typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 randomU32Next();
M2C_UNK func_80054FEC(M2C_UNK, f32, f32, void *, void *, s32, s32);
M2C_UNK func_8005FBB8(s32 *);
s32 func_8005FD28(void *);
M2C_UNK actorRespawnAtRandomPoint(void *);
M2C_UNK objectUpdateAnimByState(void *);
M2C_UNK func_800624A8(void *, void *, f32, M2C_UNK);
M2C_UNK func_800643C8(void *);
M2C_UNK func_800643D8(void *);
M2C_UNK func_80073508(void *, f32);
M2C_UNK func_800853D4(void *);
/* Timed two-state object update: state 0 counts a 900-frame timer then re-arms it randomly; state 3 runs a triggered effect. */ void updateTimedObjectState(void *obj) {
s16 state; s32 *timer; s32 flags; void *effectPos;
state=M2C_FIELD(obj,s16 *,0x7A); timer=M2C_FIELD(obj,s32 **,0x6C);
switch(state) {
case 0:
M2C_FIELD(obj,s32 *,0x60)=M2C_FIELD(obj,s32 *,0x60)&~2;
*timer+=1; func_800643D8(obj);
if(*timer>=0x384) { objectUpdateAnimByState(obj); func_800643C8(obj); func_8005FBB8(timer); *timer=(u32)randomU32Next()%450U; M2C_FIELD(obj,s16 *,0x7A)=3; return; } return;
case 3:
flags=M2C_FIELD(obj,s32 *,0x60);
if(flags&2) { effectPos=obj+0x24; M2C_FIELD(obj,s32 *,0x60)=flags&~2;
func_80054FEC(0,250.0f,5.0f,obj,effectPos,0x20,0);
func_800624A8(obj,effectPos,1.0f,1); func_80073508(effectPos,0.001f); func_800853D4(effectPos); goto block_8;
}
if((func_8005FD28(obj)<<0x18)!=0) { block_8: actorRespawnAtRandomPoint(obj); }
break;
}
}
