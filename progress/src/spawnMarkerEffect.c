void *spawnEffectObject(s32,s32,s32); s32 actorLinkToSurface(s32,void *,s32); s32 func_80047F50(void *,void *); s32 func_80076340(void *,s32,s32); extern s32 *gProbeObjectList; extern f64 D_800D4990; extern void *sTrackMarkerTable;
/* Spawns a type-0x18 effect object with a marker record, sets its lifetime rate, and links it to the surface list when markerValue is 0. */ void *spawnMarkerEffect(s32 srcA,s32 srcB,s32 markerValue,u8 markerKind,u8 stateA,u8 stateB,s32 lifetime) {
f64 lifetimeF; void *marker; void *effect;
effect=spawnEffectObject(0x18,srcA,srcB);
if(effect!=NULL) {
marker=*(void **)((s8 *)effect+0x6C); lifetimeF=(f64)lifetime;
*(s16 *)((s8 *)marker+0x10)=(s16)(markerKind&0xFF);
*(s32 *)((s8 *)marker+4)=markerValue;
*(s16 *)((s8 *)marker+0x12)=-1; *(s32 *)((s8 *)marker+8)=0;
if(lifetime<0) lifetimeF+=D_800D4990;
*(f32 *)((s8 *)marker+0xC)=(f32)(1.0f/(f32)lifetimeF);
{ func_80076340((s8 *)marker+4,0,0); }
*(s16 *)((s8 *)effect+0x7A)=0; *(s16 *)((s8 *)effect+0x78)=0x18;
*(u8 *)marker=stateA; *((u8 *)marker+1)=stateB;
if(markerValue==0) { void *q; s32 *p; func_80047F50(effect,sTrackMarkerTable); q=sTrackMarkerTable; p=gProbeObjectList; *(s32 *)((s8 *)q+0x100)=1; actorLinkToSurface(*p,effect,0); }
} return effect;
}
