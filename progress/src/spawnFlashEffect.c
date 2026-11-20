s32 func_8000A830(s32,s16,s32);
unsigned int func_80045CF8(s32);
f32 func_80045D2C(f32);
f32 func_80045D8C(f32,f32);
void *func_800617D8(s32,s32,s32,f32*,f32,s32,s32,s32,s32,s32,s32);
extern f64 D_800D4298,D_800D42A0,D_800D42A8;
extern s16 D_80109A58;
/* Spawns a timed flash effect owned by arg0, with a random scale and a colour cycled from a table. */ void spawnFlashEffect(void *owner,s32 unk) {
 f32 sp30[3];u32 colorBase;f64 yScale;s32 color; s32 sfxId;u32 colorIndex;void *effect;
 sp30[0]=func_80045D8C(0.4f,0.2f);
 sp30[1]=(f32)((f64)func_80045D2C(2.0f)+D_800D4298);
 sp30[2]=func_80045D8C(0.4f,0.2f);
 sfxId=0x234;yScale=(f64)sp30[1];
 if(yScale>D_800D42A0)sfxId=0x235;
 if(yScale<D_800D42A8)sfxId=0x233;
 func_8000A830(sfxId,D_80109A58,0xFF);
 colorIndex=func_80045CF8(0x17D);
 switch(colorIndex%=6){
 case 0:colorBase=0xFF0000;color=colorBase|0xFFFF;break;
 default:color=-1;break;
 case 2:color=0xFF0000FF;break;
 case 3:color=0xFFFF00FF;break;
 case 4:color=0xFF00FF;break;
 case 5:colorBase=0xFF000000;color=colorBase|0xFFFF;break;
 }
 effect=func_800617D8(*(s32*)((char*)owner+0x20),unk,0,sp30,1.0f,0,func_80045CF8(2)+0x17,0xFB,0x6B,color,4);
 *(f32*)((char*)effect+0x54)=*(f32*)((char*)effect+0x54)*8.0f;
}
