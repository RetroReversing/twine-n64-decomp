extern f32 D_8011F170[];
extern char D_8011EFE0[];
extern char D_8011EFEC[];
extern s32 D_8010969C;
extern u8 gSceneType;
extern s32 gTrackMarkerTable[];
extern void *gBonusSceneHandle[4];
extern u8 sProbeActive[];
extern s32 *sProbeFlags[];
extern s32 sProbeHandles[];
extern s32 sProbeObjects[];
extern f32 sProbePositions[4][3];
extern s32 D_8011ED10[];
extern u32 D_8011F278;
extern s32 D_8011F288[];
extern s32 D_8011F29C[];
extern s32 D_8011F2A0[];
extern s32 D_8011F2B0[];
extern u64 D_80102EFC;
extern s32 func_8002B278(void *);
extern s32 lookupDataEntry(s32);
extern s32 func_80073AF8(s32,s32,char*,s32,s32,s32,s32,s32,s32,s32,s32);
extern s32 requestSound(s32);
extern void actorUnlinkFromSurface(void *);
extern s32 objectListInsert(void *, s32);
extern f32 approxDistance(void *,void *);
extern s32 listUnlinkFree(s32);
extern s32 func_800643C8(s32);
extern void func_80064370(void *,s32);
extern void unlinkNode(void *,s32,s32);
extern s32 func_80016718(void *,s32);
extern s32 sprintf(char *,char *,...);
struct Vec3Words { s32 x,y,z; };
struct Obj { u8 pad0[0x20]; s32 list; u8 pad24[0x20]; s32 mode; u8 pad48[0x20]; s32 flags; u8 pad6c[0xc]; f32 distance; u8 pad7c[4]; u16 type; u8 pad7e[0x0e]; void *trigger; u8 padb4[0xce]; u8 index; };
void func_8011B5F0(struct Obj *arg0) {
 s32 i=0; s32 slot=*((u8 *)arg0+0x7b); s32 *flag=sProbeFlags[slot]; *(s32 *)((u8 *)arg0+0x58)|=1;
 if(flag) { if(*(f32 *)((u8 *)flag+0x74)>0.0f) { s32 *p=(s32*)flag[0x68/4]; s32 *q=(s32*)p[1]; s32 *dst=(s32 *)arg0; *(struct Vec3Words *)&dst[9]=*(struct Vec3Words *)&q[0x9c/4]; *(struct Vec3Words *)&dst[15]=*(struct Vec3Words *)&flag[15]; if (gSceneType != 3) *(f32 *)((u8 *)arg0+0x40) += 1024.0f; actorUnlinkFromSurface(arg0); objectListInsert(arg0,flag[0x20/4]); } return; }
 while(i<4) { void *o=gBonusSceneHandle[i]; if(o && *(u16 *)((u8 *)o+0x78)!=0x4d && *(u16 *)((u8 *)o+0x78)!=0x61 && approxDistance((u8*)o+0x24,(u8*)arg0+0x24)<2.0f) { void *p=*(void **)((u8 *)o+0x6c); if(p && *(u8 *)(*(u8 **)((u8 *)p+0xb4)+0x12)==slot && !sProbeActive[slot]) { s32 a=lookupDataEntry(slot ? 0x6f : 0x6e); s32 b=lookupDataEntry(0x28e); s32 c=lookupDataEntry(gSceneType==2 ? 0x28f : 0x290); sprintf((char *)D_8011F170,D_8011EFE0,slot ? 5 : 12,a,b,c); requestSound(0x219); func_80073AF8(0,D_8010969C,(char *)D_8011F170,-1,-1,1,0,0,6,0,60); sProbeActive[slot]=1; *(struct Vec3Words *)((u8 *)arg0+0x30)=*(struct Vec3Words *)&sProbePositions[slot]; *(struct Vec3Words *)((u8 *)arg0+0x24)=*(struct Vec3Words *)((u8 *)arg0+0x30); listUnlinkFree(sProbeHandles[slot]); sProbeHandles[slot]=0; actorUnlinkFromSurface(arg0); objectListInsert(arg0, *(s32 *)(sProbeObjects[slot]+0x20)); ((s32 *)arg0)[15]=0; ((s32 *)arg0)[16]=0; ((s32 *)arg0)[17]=0; func_800643C8(D_8011F2B0[slot]); *(s32 *)(D_8011F288[slot]+0x28)=(*(s32 *)(D_8011F288[slot]+0x28)&~0xfc)|0x1c; return; } else if(!p || *(u8 *)(*(u8 **)((u8 *)p+0xb4)+0x12)!=slot) { s32 a=lookupDataEntry(slot ? 0x6f : 0x6e); s32 b=lookupDataEntry(0x28c); s32 c=lookupDataEntry(slot ? 0x6f : 0x6e); s32 d=lookupDataEntry(gSceneType==2 ? 0x28f : 0x290); sprintf((char *)D_8011F170,D_8011EFEC,slot ? 12 : 5,a,b,slot ? 5 : 12,c,d); func_80073AF8(0,D_8010969C,(char *)D_8011F170,-1,-1,1,0,0,6,0,60); sProbeHandles[slot]=requestSound(0x21e); sProbeActive[slot]=0; sProbeObjects[slot]=(s32)o; func_80064370(arg0,i); *(s32 *)(D_8011F288[slot]+0x28)=(*(s32 *)(D_8011F288[slot]+0x28)&~0xfc)|0x10; unlinkNode((void *)D_8011F288[slot],gTrackMarkerTable[*(s16 *)((u8 *)D_8011ED10+slot*36)],gTrackMarkerTable[*(s8 *)((u8 *)p+0x182)]); *(s16 *)((u8 *)D_8011ED10+slot*36)=*(s8 *)((u8 *)p+0x182); return; } } i++; }
 if (!sProbeFlags[slot] && !sProbeActive[slot] && (u32)((s16)func_8002B278(&D_80102EFC)-((s32 *)&D_8011F278)[slot])>=10) { if (!sProbeActive[slot]) { s32 a=lookupDataEntry(slot?0x6f:0x6e); s32 b=lookupDataEntry(gSceneType==2?0x28f:0x290); s32 c=lookupDataEntry(0x291); sprintf((char *)D_8011F170,D_8011EFE0,slot?5:12,a,b,c); func_80073AF8(0,D_8010969C,(char *)D_8011F170,-1,-1,1,0,0,6,0,60); } *(struct Vec3Words *)((u8 *)arg0+0x24)=*(struct Vec3Words *)&sProbePositions[slot]; *(struct Vec3Words *)((u8 *)arg0+0x30)=*(struct Vec3Words *)&sProbePositions[slot]; sProbeActive[slot]=1; sProbeFlags[slot]=0; listUnlinkFree(sProbeHandles[slot]); sProbeHandles[slot]=0; actorUnlinkFromSurface(arg0); objectListInsert(arg0,*(s32 *)(sProbeObjects[slot]+0x20)); func_800643C8(D_8011F2B0[slot]); }
}
