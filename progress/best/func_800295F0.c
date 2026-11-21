#define F(e,t,o) (*(t)((s8 *)(e)+(o)))
extern void formatTextEntry(void *, s32, ...);
extern void requestSound(s32);
extern void *lookupDataEntry(s32);
extern void *gSaveMenuState;
extern char D_800D2CB8[],D_800D2AF0[];
void func_800295F0(s32 arg0) {
 s32 temp_s0,temp_v1; s16 var_s0; u32 temp_v0,var_s1; u16 var_s2; void *temp_a1,*temp_s3;
 temp_a1=F(gSaveMenuState,void **,0x18);
 temp_s0=*F(temp_a1,u8 **,0x10);
 temp_s3=(u8 *)*F(gSaveMenuState,s32 **,0x10)+((F(gSaveMenuState,u8 *,8)*0x28)+0x28);
 if(F(temp_a1,u16 *,0xC)&0x400){temp_v0=F(temp_a1,u32 *,0x14);var_s2=temp_v0;var_s1=temp_v0>>0x10;}else{var_s2=1;var_s1=0;}
 requestSound(0xE8);
 var_s0 = temp_s0 + arg0; temp_s0 = var_s0;temp_v1=var_s2&0xFFFF;
 if(temp_v1<var_s0)temp_s0=var_s1;else if(var_s0<(s32)var_s1)temp_s0=var_s2;
 var_s0=temp_s0;
 F(gSaveMenuState,s8 *,0x2D)=(s8)(*F(F(gSaveMenuState,void **,0x18),u8 **,0x10)!=(var_s0 & 0xff));
 *F(F(gSaveMenuState,void **,0x18),u8 **,0x10)=var_s0;
 if(F(F(temp_s3,void **,8),s32 *,0x18)!=0){
  if(F(F(gSaveMenuState,void **,0x18),u16 *,0xC)&0x400)formatTextEntry(temp_s3,(s32)D_800D2CB8,(s16)var_s0);
  else {s32 id=10;if(var_s0!=0)id=9;formatTextEntry(temp_s3,(s32)D_800D2AF0,lookupDataEntry(id));}
 }
}
