#define F(e,t,o) (*(t)((s8 *)(e)+(o)))
extern void formatTextEntry(void *, s32, ...);
extern void requestSound(s32);
extern void *lookupDataEntry(s32);
extern void *gSaveMenuState;
extern char D_800D2CB8[],D_800D2AF0[];
void func_800295F0(s32 arg0) {
 s16 x; u32 hi, raw; u16 lo; void *temp_a1,*temp_s3;
 temp_a1=F(gSaveMenuState,void **,0x18);
 x=*F(temp_a1,u8 **,0x10);
 temp_s3=(u8 *)*F(gSaveMenuState,s32 **,0x10)+((F(gSaveMenuState,u8 *,8)*0x28)+0x28);
 if(F(temp_a1,u16 *,0xC)&0x400){raw=F(temp_a1,u32 *,0x14);lo=raw;hi=raw>>0x10;}else{lo=1;hi=0;}
 requestSound(0xE8);
 x = x + arg0;
 if(x>lo)x=hi;else if(x<(s32)hi)x=lo;
 F(gSaveMenuState,s8 *,0x2D)=(s8)(*F(F(gSaveMenuState,void **,0x18),u8 **,0x10)!=(x & 0xff));
 *F(F(gSaveMenuState,void **,0x18),u8 **,0x10)=x;
 if(F(F(temp_s3,void **,8),s32 *,0x18)!=0){
  if(F(F(gSaveMenuState,void **,0x18),u16 *,0xC)&0x400)formatTextEntry(temp_s3,(s32)D_800D2CB8,x);
  else {s32 id=10;if(x!=0)id=9;formatTextEntry(temp_s3,(s32)D_800D2AF0,lookupDataEntry(id));}
 }
}
