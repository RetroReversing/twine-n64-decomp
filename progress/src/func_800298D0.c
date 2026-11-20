typedef s32 M2C_UNK;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
M2C_UNK func_8000A894(M2C_UNK,void*); M2C_UNK formatTextEntry(void*,M2C_UNK*,s32); s32 func_80087100(M2C_UNK); extern f64 D_800D2CC0,D_800D2CC8; extern char D_800D2CB8[],D_800D2AF0[]; extern void*D_80109BB0;
void func_800298D0(s32 arg0){M2C_UNK*var_a1;M2C_UNK var_a0;f32*temp_s3;f32 temp_fv0,temp_fv1_2,var_fs0,var_fs1;f64 temp_fv1,var_fv1;s32 temp_s0;s32 temp_v0;s32 var_a2;s32 var_s0;s8 var_v0;u32 temp_v0_2;u32 temp_v1;void *temp_s1,*temp_a1;
temp_a1=M2C_FIELD(D_80109BB0,void**,0x18);temp_s3=M2C_FIELD(temp_a1,f32**,0x10);temp_s0=(s32)*temp_s3;temp_s1=(void *)((s8 *)*M2C_FIELD(D_80109BB0,s32**,0x10)+((M2C_FIELD(D_80109BB0,u8*,8)*0x28)+0x28));
if(M2C_FIELD(temp_a1,u16*,0xc)&0x400){temp_v1=M2C_FIELD(temp_a1,u32*,0x14);temp_v0=(u16)temp_v1;var_fv1=(f64)temp_v0;if(temp_v0<0)var_fv1+=D_800D2CC0;var_fs1=(f32)var_fv1;temp_v0_2=temp_v1>>16;temp_fv1=(f64)(s32)temp_v0_2;if((s32)temp_v0_2<0)temp_fv1+=D_800D2CC8;var_fs0=(f32)temp_fv1;}else{var_fs1=1.0f;var_fs0=0.0f;}
func_8000A894(0xe8,temp_a1);temp_s0+=(s16)arg0;temp_fv0=(f32)temp_s0;if(var_fs1<temp_fv0)temp_s0=(s32)var_fs0;else if(temp_fv0<var_fs0)temp_s0=(s32)var_fs1;
temp_fv1_2=(f32)temp_s0;var_v0=1;if(*M2C_FIELD(M2C_FIELD(D_80109BB0,void**,0x18),f32**,0x10)==temp_fv1_2)var_v0=0;M2C_FIELD(D_80109BB0,s8*,0x2d)=var_v0;*temp_s3=temp_fv1_2;
if(M2C_FIELD(M2C_FIELD(temp_s1,void**,8),s32*,0x18)!=0){if(M2C_FIELD(M2C_FIELD(D_80109BB0,void**,0x18),u16*,0xc)&0x400)formatTextEntry(temp_s1,(M2C_UNK*)D_800D2CB8,temp_s0);else{var_a0=10;if(temp_s0!=0)var_a0=9;formatTextEntry(temp_s1,(M2C_UNK*)D_800D2AF0,func_80087100(var_a0));}}}
