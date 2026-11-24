#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef struct { s32 x,y,z; } Vec3Copy; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
M2C_UNK actorLinkToSurface(s32,void *,M2C_UNK); M2C_UNK effectSetAnimFrame(void *,u16,s16); void *spawnEffectObject(M2C_UNK); extern s32 *gDefaultOrderObj;
/* Spawns an effect object copying animation and parameters from a source object, with optional position/velocity, and links it to the surface. */ void *spawnImpactEffect(s32 owner,s32 unused1,s32 unused2,void *arg3_in,void *motion,u8 lifetime,u16 flags) {
f32 zero; s16 soundId; s32 temp_a0; u8 temp_v0_2; void *state; void *effect; void *source;
source=arg3_in;arg3_in=0;effect=spawnEffectObject(0x50);
if(effect!=NULL){state=M2C_FIELD(effect,void **,0x6C); effectSetAnimFrame(effect,M2C_FIELD(source,u16 *,0),*M2C_FIELD(source,s16 **,0x28));
temp_a0=M2C_FIELD(state,s32 *,0x4C)&~0x40; M2C_FIELD(state,s32 *,0x4C)=temp_a0;
if(M2C_FIELD(source,s32 *,0x3C)&0x200000) M2C_FIELD(state,s32 *,0x4C)=temp_a0|0x40;
M2C_FIELD(state,u8 *,0x4E)=M2C_FIELD(effect,u8 *,0x7E); M2C_FIELD(effect,s16 *,0x78)=0xB;
M2C_FIELD(state,u16 *,0x34)=M2C_FIELD(source,u16 *,0x2C); M2C_FIELD(state,s16 *,0x36)=M2C_FIELD(source,u8 *,0x2F);
M2C_FIELD(state,u16 *,0x38)=M2C_FIELD(source,u16 *,0x30); M2C_FIELD(state,u16 *,0x3A)=M2C_FIELD(source,u16 *,0x32);
M2C_FIELD(state,u16 *,0x3C)=M2C_FIELD(source,u16 *,0x34); M2C_FIELD(state,u16 *,0x3E)=M2C_FIELD(source,u16 *,0x36);
M2C_FIELD(state,u16 *,0x40)=M2C_FIELD(source,u16 *,0x38); M2C_FIELD(state,u16 *,0x42)=M2C_FIELD(source,u16 *,0x40);
M2C_FIELD(effect,s16 *,0x7A)=0; M2C_FIELD(state,f32 *,8)=0.0f; zero=M2C_FIELD(state,volatile f32 *,8);
M2C_FIELD(state,void **,4)=motion; M2C_FIELD(state,u16 *,0x44)=flags; M2C_FIELD(state,s8 *,0x4B)=0;
M2C_FIELD(state,s8 *,0x4C)=lifetime-1; M2C_FIELD(state,s8 *,0x4A)=owner;
M2C_FIELD(state,f32 *,0x24)=zero; M2C_FIELD(state,f32 *,0x20)=zero; M2C_FIELD(state,f32 *,0x1C)=zero; M2C_FIELD(state,f32 *,0x18)=zero; M2C_FIELD(state,f32 *,0x14)=zero; M2C_FIELD(state,f32 *,0x10)=zero;
if(motion!=NULL){M2C_FIELD(effect,f32 *,0x24)=M2C_FIELD(motion,f32 *,0); M2C_FIELD(effect,f32 *,0x28)=M2C_FIELD(motion,f32 *,4); M2C_FIELD(effect,f32 *,0x2C)=M2C_FIELD(motion,f32 *,8);
M2C_FIELD(effect,f32 *,0x3C)=M2C_FIELD(motion,f32 *,0xC)*0.0027777778f; M2C_FIELD(effect,f32 *,0x40)=M2C_FIELD(motion,f32 *,0x10)*0.0027777778f; M2C_FIELD(effect,f32 *,0x44)=M2C_FIELD(motion,f32 *,0x14)*0.0027777778f;}
M2C_FIELD(effect,Vec3Copy *,0x30)=M2C_FIELD(effect,Vec3Copy *,0x24);
M2C_FIELD(effect,Vec3Copy *,0x48)=M2C_FIELD(effect,Vec3Copy *,0x3C);
M2C_FIELD(state,s8 *,0x4D)=0; M2C_FIELD(state,s32 *,0)=0; M2C_FIELD(effect,s32 *,0x5C)|=0x600; M2C_FIELD(effect,s32 *,0x58)|=0x20000;
temp_v0_2=M2C_FIELD(M2C_FIELD(source,void **,0x24),u8 *,0x1E);
switch(temp_v0_2){default:soundId=-1;break;case 0xA1:case 0xA2:soundId=0x196;break;case 0xA3:case 0xA4:soundId=0x197;break;case 0x9F:case 0xA0:case 0xA5:case 0xA6:soundId=0x164;break;case 0xA7:case 0xA8:soundId=0x198;break;case 0xA9:case 0xAA:case 0xAB:case 0xAC:soundId=0x1AC;break;}
M2C_FIELD(state,s16 *,0x48)=soundId; actorLinkToSurface(*gDefaultOrderObj,effect,0);}
return effect;}
