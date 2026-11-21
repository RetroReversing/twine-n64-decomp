s32 menuSetItemLabelIndices(); s32 func_80025E9C(); s32 formatTextEntry(); void *findEntryPayload(); s8 findTableIndexById(); s32 lookupDataEntry();
extern char D_800D2A80[]; extern char D_800D2A84[]; extern s16 gExpansionPakPresent; extern void *gSaveMenuState; extern u8 D_8010A4C0, gOptionFlagA, D_8010A4FF;
void menuRefreshOptionRows(void) {
 s32 a,b; void *p,*q,*r,*x,*y,*z;
 p=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),0x1f);
 q=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),0x19);
 r=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),0x1c);
 if (r == NULL) r=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),3);
 if (((p != NULL)&(q != NULL)) && r != NULL) {
 formatTextEntry(q,D_800D2A80,!gOptionFlagA ? lookupDataEntry(0x1a):lookupDataEntry(0x1b));
 if (gExpansionPakPresent) {
 x=r-0x28; y=q-0x28; z=p-0x28;
 *(s16 *)(r-0x28)=3;
 func_80025E9C(x,r,y,z,1,9);
 formatTextEntry(r,D_800D2A84);
 menuSetItemLabelIndices(z,p,x,y,0x1f,1);
 x=*(void **)((char *)gSaveMenuState+0x10);
 *(s8 *)(*(char **)((char *)gSaveMenuState+0x10)+4)=findTableIndexById(x,0x1f);
 goto update;
 }
 *(s16 *)(r-0x28)=0x1c;
 menuSetItemLabelIndices(r-0x28,r,q-0x28,p-0x28,0x1c,1);
 a=0x1b3; if(D_8010A4FF) a=0x1d;
 formatTextEntry(r,D_800D2A80,lookupDataEntry(a));
 func_80025E9C(p-0x28,p,r-0x28,q-0x28,1,0xd);
 x=*(void **)((char *)gSaveMenuState+0x10);
 *(s8 *)(*(char **)((char *)gSaveMenuState+0x10)+4)=findTableIndexById(x,0x19);
 update:
 if(D_8010A4C0==0) b=lookupDataEntry(0x16); else if(D_8010A4C0==1) b=lookupDataEntry(0x17); else b=lookupDataEntry(0x16);
 formatTextEntry(p,D_800D2A80,b);
 }
}
