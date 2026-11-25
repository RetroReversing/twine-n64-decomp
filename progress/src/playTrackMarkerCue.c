typedef struct { s32 x; f32 y; s32 z; } Vec3s;
s32 updateActorHeadLook(void *,Vec3s *,s32,s32); s32 absS32(s32); extern s8 gTrackCuePlayed; extern Vec3s *gTrackMarkerParents[];
/* Plays the track cue once, at the marker or fallback position; returns nonzero when the cue is in range. */ s8 playTrackMarkerCue(void * actor, void * marker, s32 fallbackPos) {
 Vec3s cuePos; register s32 effectResult; u16 markerMode; Vec3s *markerPos;
 if(gTrackCuePlayed!=0) goto block_6;
 {
  if(marker!=NULL) {
   markerMode=*(u16 *)((char *)marker+0x78);
   if((markerMode==2)|(markerMode==0x4d)) {
    markerPos=gTrackMarkerParents[*(s8 *)((char *)(*(void **)((char *)marker+0x6c))+0x182)];
    cuePos=*(Vec3s *)((char *)markerPos + 0x10); cuePos.y-=0.1f;
   } else {
    cuePos=*(Vec3s *)((char *)marker+0x24); cuePos.y+=0.5f;
   } goto block_8;
  }
  if(fallbackPos!=NULL) goto copy;
block_6: return 1;
copy: cuePos=*(Vec3s *)fallbackPos;
block_8:
  if(*(u8 *)((char *)(*(void **)((char *)actor+0x68))+0xb1)!=0x72) effectResult=updateActorHeadLook(actor,&cuePos,1,0x40); else effectResult=0;
  updateActorHeadLook(actor,&cuePos,0,0xfa); gTrackCuePlayed=1; return absS32(effectResult)<0x1aa;
 }
done: return effectResult;
}
