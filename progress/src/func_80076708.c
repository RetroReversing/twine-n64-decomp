void *func_80016410(s32,s32,s32); s32 actorLinkToSurface(s32,void *,s32); s32 func_80047F50(void *,void *); s32 func_80076340(void *,s32,s32); extern s32 *gProbeObjectList; extern f64 D_800D4990; extern void *gTrackMarkerTable;
void *func_80076708(s32 arg0,s32 arg1,s32 arg2,u8 arg3,u8 arg4,u8 arg5,s32 arg6) {
f64 var_fv1; void *temp_s0; void *temp_v0;
temp_v0=func_80016410(0x18,arg0,arg1);
if(temp_v0!=NULL) {
temp_s0=*(void **)((s8 *)temp_v0+0x6C); var_fv1=(f64)arg6;
*(s16 *)((s8 *)temp_s0+0x10)=(s16)(arg3&0xFF);
*(s32 *)((s8 *)temp_s0+4)=arg2;
*(s16 *)((s8 *)temp_s0+0x12)=-1; *(s32 *)((s8 *)temp_s0+8)=0;
if(arg6<0) var_fv1+=D_800D4990;
*(f32 *)((s8 *)temp_s0+0xC)=(f32)(1.0f/(f32)var_fv1);
{ func_80076340((s8 *)temp_s0+4,0,0); }
*(s16 *)((s8 *)temp_v0+0x7A)=0; *(s16 *)((s8 *)temp_v0+0x78)=0x18;
*(u8 *)temp_s0=arg4; *((u8 *)temp_s0+1)=arg5;
if(arg2==0) { void *q; s32 *p; func_80047F50(temp_v0,gTrackMarkerTable); q=gTrackMarkerTable; p=gProbeObjectList; *(s32 *)((s8 *)q+0x100)=1; actorLinkToSurface(*p,temp_v0,0); }
} return temp_v0;
}
