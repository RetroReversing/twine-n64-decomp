#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 switchActiveItemSet(); s32 func_800274BC(); s32 func_8002778C(); s32 func_80027848(); s32 layoutTextBox();
extern void *D_800E1090; extern s32 D_800E1094; extern char D_801002E6[]; extern void *sActiveMenu; extern void *gMenuState;
/* Per-frame update for menu state 20: ticks the state timer; when it runs out, fires the entry callback, otherwise refreshes the active item list. */
void menuStateTimedUpdate(void) {
 s32 (*callback)(); s32 (*itemCallback)(); u8 itemIndex, itemCount; void *entry, *itemDst;
 if(!(func_80027848(45)&0xff)){M2C_FIELD(gMenuState,s8 *,0x29)=0;if(gMenuState != NULL){entry=M2C_FIELD(gMenuState,void **,0x10);if(entry){callback=M2C_FIELD(entry,s32 (**)(),0x10);if(callback)callback();}}}
 else {if(M2C_FIELD(gMenuState,void **,0x10)){itemDst=M2C_FIELD(gMenuState,void **,0x18);if(itemDst != NULL) { __builtin_memcpy((char *)itemDst+0x24,D_801002E6,4); }}
 switchActiveItemSet(D_800E1090,D_800E1094&~0xff);
 if(D_800E1090){itemCount=M2C_FIELD(D_800E1090,u8 *,4);if((u8)M2C_FIELD(D_800E1090,u8 *,5)>=itemCount)M2C_FIELD(gMenuState,u8 *,8)=itemCount;else M2C_FIELD(gMenuState,u8 *,8)=0;
 itemIndex=M2C_FIELD(gMenuState,u8 *,8);M2C_FIELD(gMenuState,void **,0x18)=(void *)(M2C_FIELD(D_800E1090,s32 *,0)+(itemIndex*0x28));func_800274BC(0x101,0xff,itemIndex,gMenuState);
 itemCallback=M2C_FIELD(D_800E1090,s32 (**)(),0x10);if(itemCallback)itemCallback();M2C_FIELD(gMenuState,u8 *,7)=(u8)M2C_FIELD(gMenuState,u8 *,8);layoutTextBox(M2C_FIELD(gMenuState,s32 *,0x1c),M2C_FIELD(gMenuState,void **,0x18),0);
 }else func_8002778C(); M2C_FIELD(sActiveMenu,s16 *,0x7a)=0x15;}
}
