#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) 0
#endif
typedef struct {u16 id;u8 pad[0x26];} Ent263B8; typedef struct {Ent263B8 *arr;u8 pad4;u8 count;} Tbl263B8;
void func_80026004(void *,s32,...); s32 func_800262A8(Tbl263B8 *,u16); s32 func_80087100(u16); void func_8001E5BC(void); void func_80022848(void); extern u8 D_800BD690; extern Tbl263B8 *D_80109BB0; extern u8 D_80112F7B[]; extern char D_800D2864[];
s32 func_8001ACCC(void){s32 *var_v1;s32 temp_a1,temp_s0,temp_v0,var_a2;u16 temp_v1,var_v0;u8 *temp_v0_2;temp_s0=func_800262A8(M2C_FIELD(D_80109BB0,void **,0x10),0x4000);temp_v0=func_800262A8(M2C_FIELD(D_80109BB0,void **,0x10),0x39);D_800BD690=1;if(temp_s0!=0){temp_v1=M2C_FIELD(M2C_FIELD(D_80109BB0,void **,0x10),u8 *,4);temp_a1=M2C_FIELD(M2C_FIELD(D_80109BB0,void **,0x10),s32 *,0);func_80026004((void *)temp_s0,D_800D2864,func_80087100(*(u16 *)((temp_v1*0x28)+temp_a1)));}var_a2=0;if(temp_v0!=0){temp_v0_2=(void *)(temp_v0+0xC);__repair_rows: {temp_a1=var_a2&0xFFFF;M2C_FIELD(temp_v0_2,u16 *,0)&=0xFFF0;var_v1=(s32 *)func_80022848;if(*(D_80112F7B+temp_a1)!=0)var_v1=(s32 *)func_8001E5BC;M2C_FIELD(temp_v0_2,s32 **,-8)=var_v1;temp_v1=M2C_FIELD(temp_v0_2,u16 *,0);var_v0=temp_v1|1;if(*(D_80112F7B+temp_a1)==0)var_v0=temp_v1|5;M2C_FIELD(temp_v0_2,u16 *,0)=var_v0;var_a2++;temp_v0_2=(void *)((s8 *)temp_v0_2+0x28);}
if ((u32)(var_a2&0xFFFF)<4U) goto __repair_rows;}}
