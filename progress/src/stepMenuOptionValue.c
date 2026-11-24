#define F(e,t,o) (*(t)((s8 *)(e)+(o)))
extern void formatTextEntry(void *, s32, ...);
extern void requestSound(s32);
extern void *lookupDataEntry(s32);
extern void *gSaveMenuState;
extern char gFmtDecimal[],gFmtString[];
/* Steps the selected menu option's value by delta, wrapping between its min and max, plays a sound and refreshes the label. */
void stepMenuOptionValue(s32 delta) {
 s16 value; u32 minValue, range; u16 maxValue; void *option,*menuItem;
 option=F(gSaveMenuState,void **,0x18);
 value=*F(option,u8 **,0x10);
 menuItem=(u8 *)*F(gSaveMenuState,s32 **,0x10)+((F(gSaveMenuState,u8 *,8)*0x28)+0x28);
 if(F(option,u16 *,0xC)&0x400){range=F(option,u32 *,0x14);maxValue=range;minValue=range>>0x10;}else{maxValue=1;minValue=0;}
 requestSound(0xE8);
 value = value + delta;
 if(value>maxValue)value=minValue;else if(value<(s32)minValue)value=maxValue;
 F(gSaveMenuState,s8 *,0x2D)=(s8)(*F(F(gSaveMenuState,void **,0x18),u8 **,0x10)!=(value & 0xff));
 *F(F(gSaveMenuState,void **,0x18),u8 **,0x10)=value;
 if(F(F(menuItem,void **,8),s32 *,0x18)!=0){
  if(F(F(gSaveMenuState,void **,0x18),u16 *,0xC)&0x400)formatTextEntry(menuItem,(s32)gFmtDecimal,value);
  else {s32 id=10;if(value!=0)id=9;formatTextEntry(menuItem,(s32)gFmtString,lookupDataEntry(id));}
 }
}
