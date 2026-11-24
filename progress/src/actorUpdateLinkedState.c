#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
void *spawnLinkedEffect(s32,u8);
M2C_UNK spawnConfiguredEffect(s32,M2C_UNK,M2C_UNK,M2C_UNK,f32,f32,s32,s32,s32,s32,s32);
M2C_UNK playSoundAtPos(s32,s32);
extern void *gTrackedActor; extern void *gSweepHitActor; extern s32 gGameMode; extern u8 gTrackMarkerDone[]; extern void *gBonusObjects;
typedef struct { s32 w[3]; } __repair_words3;
/* Per-frame update for an actor: refreshes the player-linked state and, when the
 * tracked object gTrackedActor is active, copies its link data and clamps its position. */
/* Per-frame actor update: refreshes player-linked state and, when gTrackedActor is active, copies its link data and clamps its position. */ void actorUpdateLinkedState(void *actor, M2C_UNK unused, M2C_UNK arg2) {
 s32 temp_v1_3; s8 var_s0; u16 temp_v0,temp_v0_2,temp_v1; void *temp_t0,*temp_v1_2;
 spawnConfiguredEffect(M2C_FIELD(actor,s32 *,0x20),arg2,0,0,1.0f,1.0f,0xA,0x1B,0x22,0xFFFF0080,0x78748010);
 if(gSweepHitActor!=NULL) {
  temp_v1=M2C_FIELD(gSweepHitActor,u16 *,0x78); var_s0=temp_v1==0x60; if(temp_v1==0x5f)var_s0=1; if(temp_v1==0x5e)var_s0=1;
  if(temp_v1==0x12) if(M2C_FIELD(M2C_FIELD(gSweepHitActor,void **,0x6c),s32 *,0x2c)&2) { temp_v0=M2C_FIELD(gSweepHitActor,u16 *,0x7c)+1; M2C_FIELD(gSweepHitActor,u16 *,0x7c)=temp_v0; if((s16)temp_v0==5) { M2C_FIELD(gSweepHitActor,u16 *,0x7c)=6; M2C_FIELD(gSweepHitActor,s32 *,0x60)|=2; playSoundAtPos(0x117,(s32)arg2); } }
  if(var_s0) { if(gGameMode==0x1d) { temp_v0_2=M2C_FIELD(M2C_FIELD(gSweepHitActor,void **,0x6c),u16 *,0x34); if(temp_v0_2!=0) *(gTrackMarkerDone+temp_v0_2)=0; } M2C_FIELD(gSweepHitActor,u16 *,0x78)=0x5a; spawnLinkedEffect(arg2,0xF); }
 }
 { void *obj;
 if((gTrackedActor!=NULL)&&(M2C_FIELD(gTrackedActor,u16 *,0x78)==1)&&(M2C_FIELD(gTrackedActor,s16 *,0x7a)!=0x2d)) {
  obj=gTrackedActor;
  temp_t0=M2C_FIELD(obj,void **,0x6c); temp_v1_2=M2C_FIELD(actor,void **,0x6c);
  M2C_FIELD(temp_t0,__repair_words3 *,0x50)=*(__repair_words3 *)((s8 *)gBonusObjects+0x24);
  M2C_FIELD(temp_t0,f32 *,0x60)+=M2C_FIELD(M2C_FIELD(temp_v1_2,void **,0x2c),f32 *,0xc);
  M2C_FIELD(temp_t0,s32 *,0x64)=M2C_FIELD(M2C_FIELD(temp_v1_2,void **,0x2c),u8 *,1);
  M2C_FIELD(temp_t0,s32 *,0x68)=M2C_FIELD(temp_v1_2,s32 *,0x24);
  if(M2C_FIELD(temp_t0,f32 *,0x60)<0.0f) M2C_FIELD(temp_t0,f32 *,0x60)=0.0f;
  temp_v1_3=((u32)M2C_FIELD(temp_t0,u32 *,0x88)>>0x15)&0xf;
  if(temp_v1_3<4) if(temp_v1_3>=2) M2C_FIELD(temp_t0,f32 *,0x60)+=4.0f;
  M2C_FIELD(obj,s32 *,0x60)|=2;
 }
 }
}
