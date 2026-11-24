extern s32 gMenuSoundParams;
extern void *gSaveMenuState;
extern s32 sMenuDefaultSoundParams;
extern s32 sMenuItemParamTable;
#define F(p,t,o) (*(t *)((s8 *)(p)+(o)))
void setMenuItemState(void *arg0, u16 arg1) {
 u16 temp_v1; void *temp_a2;
 if (arg0 != NULL && (temp_a2=F(arg0,void *,8), temp_v1=F(arg0,u16,0xC), temp_v1 &= 0xFFF0, temp_v1 |= arg1, F(arg0,u16,0xC)=temp_v1, temp_a2 != NULL)) {
  if (!(arg1 & 0xFFFF)) {
   if (temp_v1 & 0x80) { F(temp_a2,s32,0x10)=gMenuSoundParams; return; }
   F(temp_a2,s32,0x10)=sMenuDefaultSoundParams; return;
  }
  F(temp_a2,s32,0x10)=(*(&sMenuItemParamTable+(arg1&0xF)) & ~0xFF) | F(gSaveMenuState,u8,0x30);
 }
}
