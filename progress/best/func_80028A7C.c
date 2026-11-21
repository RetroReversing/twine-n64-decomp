#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
void func_800269B4(void **,s32,s32);
void func_8002778C(void);
void func_800278AC(u16,s32,s16);
s32 func_80027C60(s32);
void func_8002FBD4(void *,s16);
void func_80030644(void *,s32);
extern s32 sSaveMenuFlagsB,D_800BD64C,gMenuSoundParams;
extern M2C_UNK D_800BD8C4;
extern void *gMenuItems,*sActiveMenu;
void func_80028A7C(void) {
M2C_UNK a0; s16 v2,v4,v5,v12,v; s32 t14,a,b,c; u16 u3,u6; void *p0,*p7,*p,*p3;
if(func_80027C60(0x24)&0xFF){func_80030644(M2C_FIELD(gMenuItems,s32*,0x20),0xFF);M2C_FIELD(gMenuItems,M2C_UNK**,0xC)=&D_800BD8C4;func_800278AC(1,gMenuSoundParams,0xA);func_8002FBD4(M2C_FIELD(gMenuItems,s32*,0x20),4);func_800269B4(gMenuItems+0x1C,3,0x2A);p0=M2C_FIELD(gMenuItems,void**,0x1C);if(p0)M2C_FIELD(p0,s16*,0x26)=0;return;}
p=M2C_FIELD(gMenuItems,void**,0x1C);if(p){M2C_FIELD(p,s32*,0x10)=sSaveMenuFlagsB|0xFF;M2C_FIELD(p,u16*,0x22)=M2C_FIELD(gMenuItems,u16*,0x32);M2C_FIELD(p,s16*,0x20)=0;M2C_FIELD(p,s16*,0x26)=0x140;M2C_FIELD(p,s8*,0x29)=0x16;M2C_FIELD(p,s16*,0x1E)=0x102;}
v12=M2C_FIELD(sActiveMenu,s16*,0x7C);
if(v12==0){c=0;if((u32)v12<(u8)M2C_FIELD(M2C_FIELD(gMenuItems,s32**,0x10),u8*,5)){do{p3=((c&0xFFFF)*0x28)+M2C_FIELD(M2C_FIELD(gMenuItems,s32**,0x10),s32*,0);if(M2C_FIELD(p3,s32*,8)){v2=M2C_FIELD(gMenuItems,u16*,0x32)-M2C_FIELD(p3,u16*,0x1A);b=0;if(v2<=0){t14=v2*-0xE;if(t14>=0){a=0xFF;if(t14<0x100)a=t14;}else a=0;b=a;}M2C_FIELD(M2C_FIELD(((c&0xFFFF)*0x28)+*M2C_FIELD(gMenuItems,s32**,0x10),void**,8),s32*,0x10)=(D_800BD64C&~0xFF)|(b&0xFFFF);}c++;}while((u32)(c&0xFFFF)<(u8)M2C_FIELD(M2C_FIELD(gMenuItems,s32**,0x10),u8*,5));}
u3=M2C_FIELD(gMenuItems,u16*,0x32)+6;M2C_FIELD(gMenuItems,u16*,0x32)=u3;if((u32)(u3&0xFFFF)>=0xF6){v=1;if(M2C_FIELD(gMenuItems,u16*,0x14)==0x10)v=0x4B;M2C_FIELD(sActiveMenu,s16*,0x7C)=v;goto block_24;}
}else{
block_24:
if((u16)M2C_FIELD(gMenuItems,u16*,0x32)>=0xF6){v4=M2C_FIELD(sActiveMenu,s16*,0x7C);if(v4>0){v5=v4-1;M2C_FIELD(sActiveMenu,s16*,0x7C)=v5;if((v5<<16)==0){u6=M2C_FIELD(gMenuItems,u16*,0x14);switch(u6){case 1:a0=2;goto block_44;case 2:a0=3;goto block_44;case 3:a0=4;goto block_44;case 4:a0=5;goto block_44;case 5:a0=6;goto block_44;case 6:a0=7;goto block_44;case 7:a0=8;goto block_44;case 8:a0=9;goto block_44;case 9:a0=0xA;goto block_44;case 10:a0=0xB;goto block_44;case 11:a0=0xC;goto block_44;case 12:a0=0xD;goto block_44;case 13:a0=0xE;goto block_44;case 14:a0=0xF;goto block_44;case 15:a0=0x10;
block_44:func_800278AC(a0,gMenuSoundParams&~0xFF,0x16);break;
case 16:func_80030644(M2C_FIELD(gMenuItems,s32*,0x20),0xFF);M2C_FIELD(gMenuItems,M2C_UNK**,0xC)=&D_800BD8C4;func_800278AC(1,gMenuSoundParams,0xA);func_8002FBD4(M2C_FIELD(gMenuItems,s32*,0x20),4);func_800269B4(gMenuItems+0x1C,3,0x2A);p7=M2C_FIELD(gMenuItems,void**,0x1C);if(p7)M2C_FIELD(p7,s16*,0x26)=0;break;}
func_8002778C();M2C_FIELD(gMenuItems,u16*,0x32)=0;}}}}
}
