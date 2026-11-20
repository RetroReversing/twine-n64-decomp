#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
void MatMul3x3InPlace(void *,void *);
void func_800839F0(void *,void *,void *);
extern M2C_UNK (*D_800D9420)(s16 *,void *);
void func_80005868(s16 *arg0,void *arg1,void *arg2,s32 arg3){
 f32 vec[3]; struct { s16 rot[3]; s16 pad; u8 matrices[0x930]; } local;
 f32 var_ft0,var_fv0,var_fv1; s16 *var_s2; s32 var_s6; u32 temp_v1; void *temp_s0,*temp_s1,*var_s3,*var_s5;
 var_s6=0; var_s5=arg1; { u8 *base=local.matrices;
 if(*arg0>=0){var_s3=arg2;var_s2=arg0;__repair_rows: {
 s32 index = *var_s2;
 temp_v1=M2C_FIELD(var_s5,u32 *,0x14);temp_s1=base+((index*3)*16);
 local.rot[0]=(temp_v1>>22)*4;local.rot[1]=(temp_v1>>10)&0xffe;local.rot[2]=(temp_v1*2)&0xffe;
 D_800D9420(&local.rot[0],temp_s1);
 if(var_s6==0){f32 x,y,z;x=M2C_FIELD(arg1,f32 *,8);y=M2C_FIELD(arg1,f32 *,0xc);z=M2C_FIELD(arg1,f32 *,0x10);
 if(arg3==0){z=0.0f;y=0.0f;x=0.0f;}
 M2C_FIELD(temp_s1,f32 *,0x24)=x;M2C_FIELD(temp_s1,f32 *,0x28)=y;M2C_FIELD(temp_s1,f32 *,0x2c)=z;
 } else {temp_s0=base+(M2C_FIELD(var_s2,s16 *,2)*0x30);var_fv0=M2C_FIELD(var_s2,f32 *,4);var_fv1=M2C_FIELD(var_s2,f32 *,8);var_ft0=M2C_FIELD(var_s2,f32 *,0xc);vec[0]=var_fv0;vec[1]=var_fv1;vec[2]=var_ft0;
 func_800839F0(temp_s0,&vec[0],temp_s1+0x24);
 M2C_FIELD(temp_s1,f32 *,0x24)+=M2C_FIELD(temp_s0,f32 *,0x24);M2C_FIELD(temp_s1,f32 *,0x28)+=M2C_FIELD(temp_s0,f32 *,0x28);M2C_FIELD(temp_s1,f32 *,0x2c)+=M2C_FIELD(temp_s0,f32 *,0x2c);MatMul3x3InPlace(temp_s0,temp_s1);}
 var_s2+=0x10;M2C_FIELD(var_s3,f32 *,0)=M2C_FIELD(temp_s1,f32 *,0x24);M2C_FIELD(var_s3,f32 *,4)=M2C_FIELD(temp_s1,f32 *,0x28);var_s6++;var_s5+=4;M2C_FIELD(var_s3,f32 *,8)=M2C_FIELD(temp_s1,f32 *,0x2c);var_s3+=0xc;
 }
if (*var_s2<0) goto __done; goto __repair_rows; __done:;}
}}
