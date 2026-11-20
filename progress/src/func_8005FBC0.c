typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_80045CC4();
M2C_UNK func_80054FEC(M2C_UNK, f32, f32, void *, void *, s32, s32);
M2C_UNK func_8005FBB8(s32 *);
s32 func_8005FD28(void *);
M2C_UNK func_80060968(void *);
M2C_UNK func_80060AA8(void *);
M2C_UNK func_800624A8(void *, void *, f32, M2C_UNK);
M2C_UNK func_800643C8(void *);
M2C_UNK func_800643D8(void *);
M2C_UNK func_80073508(void *, f32);
M2C_UNK func_800853D4(void *);
void func_8005FBC0(void *arg0) {
s16 temp_v1; s32 *temp_s0; s32 temp_v1_2; void *temp_s0_2;
temp_v1=M2C_FIELD(arg0,s16 *,0x7A); temp_s0=M2C_FIELD(arg0,s32 **,0x6C);
switch(temp_v1) {
case 0:
M2C_FIELD(arg0,s32 *,0x60)=M2C_FIELD(arg0,s32 *,0x60)&~2;
*temp_s0+=1; func_800643D8(arg0);
if(*temp_s0>=0x384) { func_80060AA8(arg0); func_800643C8(arg0); func_8005FBB8(temp_s0); *temp_s0=(u32)func_80045CC4()%450U; M2C_FIELD(arg0,s16 *,0x7A)=3; return; } return;
case 3:
temp_v1_2=M2C_FIELD(arg0,s32 *,0x60);
if(temp_v1_2&2) { temp_s0_2=arg0+0x24; M2C_FIELD(arg0,s32 *,0x60)=temp_v1_2&~2;
func_80054FEC(0,250.0f,5.0f,arg0,temp_s0_2,0x20,0);
func_800624A8(arg0,temp_s0_2,1.0f,1); func_80073508(temp_s0_2,0.001f); func_800853D4(temp_s0_2); goto block_8;
}
if((func_8005FD28(arg0)<<0x18)!=0) { block_8: func_80060968(arg0); }
break;
}
}
