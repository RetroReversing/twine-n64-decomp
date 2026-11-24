s32 menuSetItemLabelIndices(); s32 setupMenuItemPair(); s32 formatTextEntry(); void *findEntryPayload(); s8 findTableIndexById(); s32 lookupDataEntry();
extern char D_800D2A80[]; extern char D_800D2A84[]; extern s16 gExpansionPakPresent; extern void *gSaveMenuState; extern u8 gExpansionModeEnabled, gOptionFlagA, D_8010A4FF;
/* Refreshes the option menu rows (entries 0x1f, 0x19, 0x1c/3) and their text labels, depending on expansion pak presence and option flags. */
void menuRefreshOptionRows(void) {
 s32 labelId, labelId2; void *rowA,*rowB,*rowC,*prevC,*prevB,*prevA;
 rowA=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),0x1f);
 rowB=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),0x19);
 rowC=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),0x1c);
 if (rowC == NULL) rowC=findEntryPayload(*(void **)((char *)gSaveMenuState+0x10),3);
 if (((rowA != NULL)&(rowB != NULL)) && rowC != NULL) {
 formatTextEntry(rowB,D_800D2A80,!gOptionFlagA ? lookupDataEntry(0x1a):lookupDataEntry(0x1b));
 if (gExpansionPakPresent) {
 prevC=rowC-0x28; prevB=rowB-0x28; prevA=rowA-0x28;
 *(s16 *)(rowC-0x28)=3;
 setupMenuItemPair(prevC,rowC,prevB,prevA,1,9);
 formatTextEntry(rowC,D_800D2A84);
 menuSetItemLabelIndices(prevA,rowA,prevC,prevB,0x1f,1);
 prevC=*(void **)((char *)gSaveMenuState+0x10);
 *(s8 *)(*(char **)((char *)gSaveMenuState+0x10)+4)=findTableIndexById(prevC,0x1f);
 goto update;
 }
 *(s16 *)(rowC-0x28)=0x1c;
 menuSetItemLabelIndices(rowC-0x28,rowC,rowB-0x28,rowA-0x28,0x1c,1);
 labelId=0x1b3; if(D_8010A4FF) labelId=0x1d;
 formatTextEntry(rowC,D_800D2A80,lookupDataEntry(labelId));
 setupMenuItemPair(rowA-0x28,rowA,rowC-0x28,rowB-0x28,1,0xd);
 prevC=*(void **)((char *)gSaveMenuState+0x10);
 *(s8 *)(*(char **)((char *)gSaveMenuState+0x10)+4)=findTableIndexById(prevC,0x19);
 update:
 if(gExpansionModeEnabled==0) labelId2=lookupDataEntry(0x16); else if(gExpansionModeEnabled==1) labelId2=lookupDataEntry(0x17); else labelId2=lookupDataEntry(0x16);
 formatTextEntry(rowA,D_800D2A80,labelId2);
 }
}
