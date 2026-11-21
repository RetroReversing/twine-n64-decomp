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
extern s32 listUnlinkFree(s32,s32);
extern s32 func_800643C8(s32);
extern void func_80064370(void *,s32);
extern void unlinkNode(void *,s32,s32);
extern s32 func_80016718(void *,s32);
extern s32 sprintf(char *,char *,...);
struct Obj { u8 pad0[0x20]; s32 list; u8 pad24[0x20]; s32 mode; u8 pad48[0x20]; s32 flags; u8 pad6c[0xc]; f32 distance; u8 pad7c[4]; u16 type; u8 pad7e[0x0e]; void *trigger; u8 padb4[0xce]; u8 index; };
void func_8011B5F0(struct Obj *arg0) {
 s32 i=0; s32 slot=arg0->index; s32 *flag=sProbeFlags[slot]; arg0->flags|=1;
 if(flag) { if(flag[0x74/4]>0.0f) { s32 *p=(s32*)flag[0x68/4]; s32 *q=(s32*)p[1]; arg0->pad0[0]=0; (void)q; actorUnlinkFromSurface(arg0); objectListInsert(arg0,flag[0x20/4]); } return; }
 while(i<4) { void *o=gBonusSceneHandle[i]; if(o && approxDistance((u8*)o+0x24,(u8*)arg0+0x24)<2.0f) { } i++; }
}
