extern void *findEntryPayload(void *, int);
extern s8 findTableIndexById(void *, int);
extern int formatTextEntry(void *, const char *, ...);
extern int func_80025E9C(void *, void *, void *, void *, int, int);
extern int lookupDataEntry(int);
extern int menuSetItemLabelIndices(void *, void *, void *, void *, int, int);
extern void *D_800D2A80;
extern void *D_800D2A84;
extern u8 D_8010A4C0, D_8010A4FF;
extern s16 gExpansionPakPresent;
extern u8 gOptionFlagA;
extern void *gSaveMenuState;
void menuRefreshOptionRows(void) {
 void *temp_s5,*temp_s2,*var_s4;
 temp_s5=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),0x1f);
 temp_s2=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),0x19);
 var_s4=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),0x1c);
 if(var_s4==0) var_s4=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),3);
 if(temp_s5!=0 && temp_s2!=0 && var_s4!=0) {
  formatTextEntry(temp_s2,"%s",lookupDataEntry(gOptionFlagA ? 0x1b : 0x1a));
  if(gExpansionPakPresent!=0) {
   void *temp_s3=var_s4-0x28;
   void *temp_s2_2=temp_s2-0x28;
   void *temp_s0=temp_s5-0x28;
   *(s16 *)(var_s4-0x28)=3;
   func_80025E9C(temp_s3,var_s4,temp_s2_2,temp_s0,1,9);
   formatTextEntry(var_s4,D_800D2A80);
   menuSetItemLabelIndices(temp_s0,temp_s5,temp_s3,temp_s2_2,0x1f,1);
   *(s8 *)((char *)*(void **)((char *)gSaveMenuState+0x10)+4)=findTableIndexById(*(void **)((char *)gSaveMenuState+0x10),0x1f);
  } else {
   void *temp_s3=var_s4-0x28;
   *(s16 *)(var_s4-0x28)=0x1c;
   menuSetItemLabelIndices(temp_s3,var_s4,temp_s2-0x28,temp_s5-0x28,0x1c,1);
   formatTextEntry(var_s4,"%s",lookupDataEntry(D_8010A4FF ? 0x1d : 0x1b3));
   func_80025E9C(temp_s5-0x28,temp_s5,temp_s3,temp_s2-0x28,1,0xd);
   *(s8 *)((char *)*(void **)((char *)gSaveMenuState+0x10)+4)=findTableIndexById(*(void **)((char *)gSaveMenuState+0x10),0x19);
  }
  formatTextEntry(temp_s5,"%s",lookupDataEntry(D_8010A4C0==1 ? 0x17 : 0x16));
 }
}
