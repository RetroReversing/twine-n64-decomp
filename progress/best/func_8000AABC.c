s32 func_80000A30(s32,s32); s32 func_8000AA64(void*,s32,s32*); s32 func_8009C9F8(s32,s32); s32 func_8009CA5C(s32,s32); s32 func_8009CAC0(s32,s32); extern s32 D_801002EC; extern u8 D_801002F2[];
void func_8000AABC(s32 arg0,void *arg1,s32 arg2,f32 arg3) {
s32 sp10,temp_a1,var_a1,var_a1_2,var_s0,var_v0,var_v1; f32 temp_fv1,var_fs0;
var_fs0=arg3;
if(D_801002EC!=0) if(arg0!=-1) {
func_8000AA64(arg1,arg2,&sp10);
var_v0=func_80000A30(sp10,(s32)(*(f32*)((s8*)arg1+0x38)*651.8986f))*0x7F;
if(var_v0<0)var_v0+=0x7FF;
var_v1=var_v0>>11; temp_a1=var_v1;
if(var_v1>=0x40)var_v1=0x7F-var_v1;
if(var_v1< -0x3F)var_v1=-0x7F-var_v1;
if(temp_a1<=0)var_s0=-temp_a1; else var_s0=temp_a1;
if(D_801002F2[0]!=0){func_8009CAC0(arg0,(var_v1+0x40)&0xFF);if(D_801002F2[0]>=2U)var_a1=var_s0&0xFF;else goto block_15;}
else {func_8009CAC0(arg0,0x40); block_15: var_a1=0;}
func_8009C9F8(arg0,var_a1);
if(var_fs0>16.0f)var_fs0=16.0f;
temp_fv1=(var_fs0*512.0f)+8192.0f;
if(temp_fv1<2.1474836e9f)var_a1_2=(s32)temp_fv1;else var_a1_2=(s32)(temp_fv1-2.1474836e9f)|0x80000000;
func_8009CA5C(arg0,var_a1_2&0xFFFF);
}
}
