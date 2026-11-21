typedef s32 M2C_UNK;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
M2C_UNK func_8000A894(M2C_UNK,void*); M2C_UNK formatTextEntry(void*,M2C_UNK*,s32); s32 lookupDataEntry(M2C_UNK); extern f64 D_800D2CC0,D_800D2CC8; extern char D_800D2CB8[],D_800D2AF0[]; extern void*gMenuState;

/* Adds delta to the slider value, clamps it to the packed min/max range, stores it, and refreshes the label text. */
void adjustMenuSliderValue(s32 delta){M2C_UNK textId;f32*valuePtr;f32 valueF,clampedF,maxF,minF;f64 maxD,minD;s32 value;s32 minWord;u32 maxWord;u32 rangeWord;s8 changed;void *labelEntry,*slider;
slider=M2C_FIELD(gMenuState,void**,0x18);valuePtr=M2C_FIELD(slider,f32**,0x10);value=(s32)*valuePtr;labelEntry=(void *)((s8 *)*M2C_FIELD(gMenuState,s32**,0x10)+((M2C_FIELD(gMenuState,u8*,8)*0x28)+0x28));
if(M2C_FIELD(slider,u16*,0xc)&0x400){rangeWord=M2C_FIELD(slider,u32*,0x14);minWord=(u16)rangeWord;minD=(f64)minWord;if(minWord<0)minD+=D_800D2CC0;minF=(f32)minD;maxWord=rangeWord>>16;maxD=(f64)(s32)maxWord;if((s32)maxWord<0)maxD+=D_800D2CC8;maxF=(f32)maxD;}else{minF=1.0f;maxF=0.0f;}
func_8000A894(0xe8,slider);value+=(s16)delta;valueF=(f32)value;if(minF<valueF)value=(s32)maxF;else if(valueF<maxF)value=(s32)minF;
clampedF=(f32)value;changed=1;if(*M2C_FIELD(M2C_FIELD(gMenuState,void**,0x18),f32**,0x10)==clampedF)changed=0;M2C_FIELD(gMenuState,s8*,0x2d)=changed;*valuePtr=clampedF;
if(M2C_FIELD(M2C_FIELD(labelEntry,void**,8),s32*,0x18)!=0){if(M2C_FIELD(M2C_FIELD(gMenuState,void**,0x18),u16*,0xc)&0x400)formatTextEntry(labelEntry,(M2C_UNK*)D_800D2CB8,value);else{textId=10;if(value!=0)textId=9;formatTextEntry(labelEntry,(M2C_UNK*)D_800D2AF0,lookupDataEntry(textId));}}}
