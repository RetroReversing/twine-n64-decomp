#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 switchActiveItemSet(); s32 moveMenuSelection(); s32 hideSaveMenu(); s32 fadeSaveMenuAlphaOut(); s32 layoutTextBox();
extern void *gSaveMenuPageEntry; extern s32 gSaveMenuPageParam; extern char D_801002E6[]; extern void *sActiveMenu; extern void *gSaveMenuState;
/* Per-frame update for menu state 20: ticks the state timer; when it runs out, fires the entry callback, otherwise refreshes the active item list. */
void menuStateTimedUpdate(void) {
 s32 (*callback)(); s32 (*itemCallback)(); u8 itemIndex, itemCount; void *entry, *itemDst;
 if(!(fadeSaveMenuAlphaOut(45)&0xff)){M2C_FIELD(gSaveMenuState,s8 *,0x29)=0;if(gSaveMenuState != NULL){entry=M2C_FIELD(gSaveMenuState,void **,0x10);if(entry){callback=M2C_FIELD(entry,s32 (**)(),0x10);if(callback)callback();}}}
 else {if(M2C_FIELD(gSaveMenuState,void **,0x10)){itemDst=M2C_FIELD(gSaveMenuState,void **,0x18);if(itemDst != NULL) { __builtin_memcpy((char *)itemDst+0x24,D_801002E6,4); }}
 switchActiveItemSet(gSaveMenuPageEntry,gSaveMenuPageParam&~0xff);
 if(gSaveMenuPageEntry){itemCount=M2C_FIELD(gSaveMenuPageEntry,u8 *,4);if((u8)M2C_FIELD(gSaveMenuPageEntry,u8 *,5)>=itemCount)M2C_FIELD(gSaveMenuState,u8 *,8)=itemCount;else M2C_FIELD(gSaveMenuState,u8 *,8)=0;
 itemIndex=M2C_FIELD(gSaveMenuState,u8 *,8);M2C_FIELD(gSaveMenuState,void **,0x18)=(void *)(M2C_FIELD(gSaveMenuPageEntry,s32 *,0)+(itemIndex*0x28));moveMenuSelection(0x101,0xff,itemIndex,gSaveMenuState);
 itemCallback=M2C_FIELD(gSaveMenuPageEntry,s32 (**)(),0x10);if(itemCallback)itemCallback();M2C_FIELD(gSaveMenuState,u8 *,7)=(u8)M2C_FIELD(gSaveMenuState,u8 *,8);layoutTextBox(M2C_FIELD(gSaveMenuState,s32 *,0x1c),M2C_FIELD(gSaveMenuState,void **,0x18),0);
 }else hideSaveMenu(); M2C_FIELD(sActiveMenu,s16 *,0x7a)=0x15;}
}
