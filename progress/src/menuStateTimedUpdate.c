#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 switchActiveItemSet(); s32 func_800274BC(); s32 func_8002778C(); s32 func_80027848(); s32 layoutTextBox();
extern void *D_800E1090; extern s32 D_800E1094; extern char D_801002E6[]; extern void *sActiveMenu; extern void *gMenuState;
void func_800285D4(void) {
 s32 (*f)(); s32 (*g)(); u8 n,x; void *p,*q;
 if(!(func_80027848(45)&0xff)){M2C_FIELD(gMenuState,s8 *,0x29)=0;if(gMenuState != NULL){p=M2C_FIELD(gMenuState,void **,0x10);if(p){f=M2C_FIELD(p,s32 (**)(),0x10);if(f)f();}}}
 else {if(M2C_FIELD(gMenuState,void **,0x10)){q=M2C_FIELD(gMenuState,void **,0x18);if(q != NULL) { __builtin_memcpy((char *)q+0x24,D_801002E6,4); }}
 switchActiveItemSet(D_800E1090,D_800E1094&~0xff);
 if(D_800E1090){x=M2C_FIELD(D_800E1090,u8 *,4);if((u8)M2C_FIELD(D_800E1090,u8 *,5)>=x)M2C_FIELD(gMenuState,u8 *,8)=x;else M2C_FIELD(gMenuState,u8 *,8)=0;
 n=M2C_FIELD(gMenuState,u8 *,8);M2C_FIELD(gMenuState,void **,0x18)=(void *)(M2C_FIELD(D_800E1090,s32 *,0)+(n*0x28));func_800274BC(0x101,0xff,n,gMenuState);
 g=M2C_FIELD(D_800E1090,s32 (**)(),0x10);if(g)g();M2C_FIELD(gMenuState,u8 *,7)=(u8)M2C_FIELD(gMenuState,u8 *,8);layoutTextBox(M2C_FIELD(gMenuState,s32 *,0x1c),M2C_FIELD(gMenuState,void **,0x18),0);
 }else func_8002778C(); M2C_FIELD(sActiveMenu,s16 *,0x7a)=0x15;}
}
