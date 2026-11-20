#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) 0
#endif
s32 formatTextEntry(); s32 findEntryById(); s32 func_80087100(); extern s8 D_800BD690; extern void *D_80109BB0; extern u8 D_80112F7B[]; extern s32 func_8001E5BC; extern s32 func_80022848; extern char D_800D2864[];
void func_8001ACCC(void){s32 *var_v1;s32 temp_a1,temp_s0,temp_v0,var_a2;u16 temp_v1,var_v0;temp_s0=findEntryById(M2C_FIELD(D_80109BB0,void **,0x10),0x4000);temp_v0=findEntryById(M2C_FIELD(D_80109BB0,void **,0x10),0x39);D_800BD690=1;if(temp_s0!=0){
void *temp_v0_2;
temp_v0_2=M2C_FIELD(D_80109BB0,void **,0x10);temp_v1=M2C_FIELD(temp_v0_2,u8 *,4);{ u8 *entries=M2C_FIELD(temp_v0_2,u8 **,0); u16 id=*(u16 *)(entries+(temp_v1*5)*8); s32 name=func_80087100(id); formatTextEntry(temp_s0,D_800D2864,name); }}var_a2=0;if(temp_v0!=0){
void *temp_v0_2;
temp_v0_2=temp_v0+0xC;__repair_rows: {
    {temp_a1=var_a2&0xFFFF;M2C_FIELD(temp_v0_2,u16 *,0)&=0xFFF0;var_v1=&func_80022848;if(*(D_80112F7B+temp_a1)!=0)var_v1=&func_8001E5BC;M2C_FIELD(temp_v0_2,s32 **,-8)=var_v1;{ u8 enabled=((volatile u8 *)D_80112F7B)[temp_a1]; temp_v1=M2C_FIELD(temp_v0_2,u16 *,0); var_v0=enabled ? temp_v1|1 : temp_v1|5; }M2C_FIELD(temp_v0_2,u16 *,0)=var_v0;var_a2++;temp_v0_2+=0x28;}
}
if ((u32)(var_a2&0xFFFF)<4U) goto __repair_rows;
}}
