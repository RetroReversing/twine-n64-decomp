#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
M2C_UNK beginTransition(void *, void *);
extern void *gCutscene;
extern s8 gTransitionPhase;
extern void *gChasedObject;
extern void *sBonusObjectTable;
/* When the player record is in state 7 and the chased object (type 0x13) is ahead of the player's target, flag the bonus object, trigger the transition and set phase 2. */ void checkBonusObjectTrigger(void) {
 if ((M2C_FIELD(gCutscene,s16 *,0x10)==7) && gChasedObject != 0 &&
 (M2C_FIELD(M2C_FIELD(gChasedObject,void **,0x6C),u8 *,0x4A)==0x13) &&
 (M2C_FIELD(gChasedObject,f32 *,0x2C)>M2C_FIELD(M2C_FIELD(gCutscene,void **,0x3B8),f32 *,0x2C))) {
 M2C_FIELD(sBonusObjectTable,f32 *,0x74)=-1.0f;
 beginTransition(gChasedObject,gCutscene);
 gTransitionPhase=2;
 }
}
