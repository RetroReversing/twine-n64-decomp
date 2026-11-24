s32 getTrackTriggerMask(s32);
void *spawnEffectObject(s32, s32, s32, void *);
s32 actorLinkToSurface(s32,void *,s32);
void effectSetAnimFrame(void *,s32,s32);
extern s32 *gDefaultOrderObj;
extern f64 D_800D4170;
extern u8 gTrackMarkerDone[19];
extern s8 gTrackSpecialMarkerFlag;
typedef struct { s32 w[3]; } __repair_words3;
typedef struct { f32 v[3]; } __repair_vec3;
typedef struct { unsigned char pad0[36]; f32 x,y,z; unsigned char pad30[12]; f32 a,b,c; unsigned char pad48[20]; s32 flags; unsigned char pad60[12]; void *sub; unsigned char pad70[8]; s16 t,u,v; } R;
/* Spawns a trigger marker effect from a marker definition: sets its type, state and animation, copies position/rotation from the transform, and registers it. */
void *spawnTriggerMarkerEffect(s32 arg0,s32 arg1,void *markerDef,void *arg3) {
 s16 effectType; s32 markerType,frameX; u16 frameY,duration; void *effectState,*effect,*transform;
 effect=spawnEffectObject(0x50,arg0,arg1, arg3);
 if(effect!=NULL) {
  effectState=((R*)effect)->sub;
  (*(s32*)((char*)effectState+0x4C)) &= ~0x40;
  markerType=*(u8*)((char*)(*(void**)((char*)markerDef+0x24))+0x1E);
  transform=arg3;
  switch(markerType) {
  case 0x2D: effectType=0x11; goto set_type;
  case 0x2F: effectType=0x12; goto set_type;
  case 0x8E: gTrackSpecialMarkerFlag=1; effectType=0x5F; goto set_type;
  case 0x90: gTrackSpecialMarkerFlag=1; effectType=0x60;
  set_type: ((R*)effect)->t=effectType; break;
  }
  *(u16*)((char*)effectState+0x34)=*(u16*)((char*)markerDef+0x2C);
  *(u16*)((char*)effectState+0x40)=*(u16*)((char*)markerDef+0x2E);
  *(s32*)((char*)effectState+0x2C)=getTrackTriggerMask(*(u16*)((char*)markerDef+0x34));
  *(u16*)((char*)effectState+0x36)=*(u16*)((char*)markerDef+0x36);
  *(u16*)((char*)effectState+0x38)=*(u16*)((char*)markerDef+0x38);
  *(u16*)((char*)effectState+0x3A)=*(u16*)((char*)markerDef+0x30);
  *(u16*)((char*)effectState+0x3C)=*(u16*)markerDef;
  *(u16*)((char*)effectState+0x3E)=**(u16**)((char*)markerDef+0x28);
  *(s16*)((char*)effectState+0x42)=0;
  if(*(u16*)((char*)effectState+0x3A)==1) { frameY=*(u16*)((char*)effectState+0x3E); frameX=*(u16*)((char*)effectState+0x3C); frameX+=gTrackMarkerDone[*(u16*)((char*)effectState+0x34)]; effectSetAnimFrame(effect,frameX,frameY); }
  else { frameX=*(u16*)markerDef; effectSetAnimFrame(effect,frameX,**(s16**)((char*)markerDef+0x28)); }
  if(*(u16*)((char*)markerDef+0x40)==0) *(s32*)((char*)effectState+0x4C)|=0x80; else *(s32*)((char*)effectState+0x4C)&=~0x80;
  gTrackMarkerDone[*(u16*)((char*)effectState+0x34)]=(s8)*(u16*)((char*)markerDef+0x32);
  *(void**)((char*)effectState+4)=arg3;
  duration=*(u16*)((char*)markerDef+4); *(u16*)((char*)effectState+0x44)=duration; if(!duration) *(u16*)((char*)effectState+0x44)=0x3C;
  *(s8*)((char*)effectState+0x4B)=0;
  *(s8*)((char*)effectState+0x4C)=(s8)(*(u8*)((char*)markerDef+3)-1);
  *(f32*)((char*)effectState+8)=1.0f;
  if(transform!=NULL) { ((R*)effect)->x=*(f32*)transform; ((R*)effect)->y=*(f32*)((char*)transform+4); ((R*)effect)->z=*(f32*)((char*)transform+8); ((R*)effect)->a=(f32)((f64)*(f32*)((char*)transform+0xC)*D_800D4170); ((R*)effect)->b=(f32)((f64)*(f32*)((char*)transform+0x10)*D_800D4170); ((R*)effect)->c=(f32)((f64)*(f32*)((char*)transform+0x14)*D_800D4170); }
  *(__repair_words3*)((char*)effect+0x30)=*(__repair_words3*)((char*)effect+0x24);
  *(__repair_vec3*)((char*)effect+0x48)=*(__repair_vec3*)((char*)effect+0x3C);
  ((R*)effect)->u=0; ((R*)effect)->v=0; ((R*)effect)->flags|=0x600;
  actorLinkToSurface(*gDefaultOrderObj,effect,1);
 }
 return effect;
}
