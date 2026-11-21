#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
M2C_UNK formatTextEntry(void *, M2C_UNK *, s32); M2C_UNK func_8000A894(M2C_UNK,void *); s32 func_80087100(M2C_UNK); extern void *gSaveMenuState;
void func_80029768(s16 arg0){M2C_UNK *var_a1; M2C_UNK var_a0; s32 temp_s0,temp_v1,var_a2,var_s0; u32 temp_v0,var_s1; u16 var_s2; void *temp_a1,*temp_s3;
temp_a1=M2C_FIELD(gSaveMenuState,void **,0x18);temp_s0=*M2C_FIELD(temp_a1,s32 **,0x10);temp_s3=(u8 *)*M2C_FIELD(gSaveMenuState,s32 **,0x10)+((M2C_FIELD(gSaveMenuState,u8 *,8)*0x28)+0x28);
if(M2C_FIELD(temp_a1,u16 *,0xC)&0x400){temp_v0=M2C_FIELD(temp_a1,u32 *,0x14);var_s2=temp_v0;var_s1=temp_v0>>0x10;}else{var_s2=1;var_s1=0;}func_8000A894(0xE8,temp_a1);temp_s0+=arg0;temp_v1=var_s2&0xFFFF;if(temp_v1<temp_s0)temp_s0=var_s1&0xFFFF;else if(temp_s0<(s32)var_s1)temp_s0=temp_v1;var_s0=temp_s0;
M2C_FIELD(gSaveMenuState,s8 *,0x2D)=(s8)(*M2C_FIELD(M2C_FIELD(gSaveMenuState,void **,0x18),s32 **,0x10)!=var_s0);*M2C_FIELD(M2C_FIELD(gSaveMenuState,void **,0x18),s32 **,0x10)=var_s0;
if(M2C_FIELD(M2C_FIELD(temp_s3,void **,8),s32 *,0x18)!=0){extern char D_800D2CB8[], D_800D2AF0[]; if(M2C_FIELD(M2C_FIELD(gSaveMenuState,void **,0x18),u16 *,0xC)&0x400)formatTextEntry(temp_s3,(M2C_UNK *)D_800D2CB8,var_s0);else{var_a0=0xA;if(var_s0!=0)var_a0=9;var_a2=func_80087100(var_a0);formatTextEntry(temp_s3,(M2C_UNK *)D_800D2AF0,var_a2);}}}
