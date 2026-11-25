#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) 0
#endif
s32 setActorCommandState(void *,s32); u32 randomIntBelow(s32); void setActorAnimation(void *,s32); s32 isTargetWithinReach(void *,void *,f32); extern u8 gTrackMarkerDone[];
/* Walks the actor's marker list and collects the first reachable, not-yet-done marker of type 0x5E-0x60; returns 1 if collected. */ s8 tryCollectTrackMarker(u8 * actor){s32 markerType;void *marker;void *actorState;marker=*M2C_FIELD(actor,void ***,0x20);actorState=M2C_FIELD(actor,void **,0x6C);if(marker!=NULL){for(;;){markerType=M2C_FIELD(marker,u16 *,0x78);if(markerType<0x61){if(markerType>=0x5E){if(((isTargetWithinReach(actor,marker+0x24,1.0f)<<0x18)!=0)&&(*(gTrackMarkerDone+M2C_FIELD(M2C_FIELD(marker,void **,0x6C),u16 *,0x34))==0)){M2C_FIELD(marker,s32 *,0x60)|=0x800;setActorCommandState(actor,randomIntBelow(2)+0x2F1);M2C_FIELD(actorState,s32 *,0x88)&=0xFDFFFFFF;setActorAnimation(actor,0x87);return 1;}}}marker=M2C_FIELD(marker,void **,0);if(marker==NULL)return 0;}}return 0;}
