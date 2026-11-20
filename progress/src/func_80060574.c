#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_80045CC4();
s32 func_80054FEC(s32, f32, f32, void *, void *, s32, s32);
s32 func_8005FBB8(void *);
s32 func_8005FD28(void *);
s32 func_80060968(void *);
s32 func_80060AA8(void *);
s32 func_800624A8(void *, void *, f32, s32);
s32 func_800643C8(void *);
s32 func_800643D8(void *);
s32 func_80073508(void *, f32);
s32 func_800853D4(void *);
/* Per-frame state machine for one object: counts down a timer, falls, bounces or launches, and resets when finished. */ void func_80060574(void *obj) {
f32 temp_fv0,temp_fv0_2,temp_fv1,temp_fv1_2; s16 temp_v1; s32 temp_v1_2; void *temp_s0,*temp_s0_2,*temp_s0_3;
temp_v1=M2C_FIELD(obj,s16*,0x7A);temp_s0=M2C_FIELD(obj,void**,0x6C);
switch(temp_v1){
case 0:
M2C_FIELD(obj,s32*,0x60)=M2C_FIELD(obj,s32*,0x60)&~2;
M2C_FIELD(temp_s0,s32*,0)=M2C_FIELD(temp_s0,s32*,0)+1;
func_800643D8(obj);
if(M2C_FIELD(temp_s0,s32*,0)>=0x384){func_80060AA8(obj);func_800643C8(obj);func_8005FBB8(temp_s0);M2C_FIELD(temp_s0,f32*,0x2C)=-4.0f;M2C_FIELD(temp_s0,s32*,0)=(u32)func_80045CC4()%450;M2C_FIELD(obj,s16*,0x7A)=1;return;}
default:return;
case 1:
M2C_FIELD(obj,f32*,0x40)=M2C_FIELD(obj,f32*,0x40)+16.0f;
temp_fv0=M2C_FIELD(obj,f32*,0x28)+(M2C_FIELD(temp_s0,f32*,0x2C)*0.033333335f);
M2C_FIELD(obj,f32*,0x28)=temp_fv0;temp_fv1=M2C_FIELD(temp_s0,f32*,0x34);
if(temp_fv0<temp_fv1){M2C_FIELD(obj,f32*,0x28)=temp_fv1;M2C_FIELD(obj,s16*,0x7A)=3;func_80060AA8(obj);}
if(M2C_FIELD(obj,s32*,0x60)&2){M2C_FIELD(obj,s16*,0x7A)=2;func_80060AA8(obj);return;}break;
case 2:
M2C_FIELD(obj,f32*,0x40)=M2C_FIELD(obj,f32*,0x40)+32.0f;
temp_fv0_2=M2C_FIELD(temp_s0,f32*,0x2C)-0.32666668f;M2C_FIELD(temp_s0,f32*,0x2C)=temp_fv0_2;
M2C_FIELD(obj,f32*,0x28)=M2C_FIELD(obj,f32*,0x28)+(temp_fv0_2*0.033333335f);
if(M2C_FIELD(temp_s0,f32*,0x2C)>50.0f)M2C_FIELD(temp_s0,f32*,0x2C)=50.0f;
temp_fv1_2=M2C_FIELD(obj,f32*,0x28);
if(temp_fv1_2<M2C_FIELD(temp_s0,f32*,0x34)){M2C_FIELD(obj,f32*,0x28)=M2C_FIELD(temp_s0,f32*,0x34);
if(M2C_FIELD(temp_s0,f32*,0x2C)<-10.0f){temp_s0_2=obj+0x24;func_80054FEC(0,250.0f,5.0f,obj,temp_s0_2,0x20,0);func_800624A8(obj,temp_s0_2,1.0f,1);func_80073508(temp_s0_2,0.001f);func_800853D4(temp_s0_2);M2C_FIELD(obj,s16*,0x7A)=4;return;}
M2C_FIELD(obj,s16*,0x7A)=3;func_80060AA8(obj);return;}break;
case 3:
temp_v1_2=M2C_FIELD(obj,s32*,0x60);
if(temp_v1_2&2){temp_s0_3=obj+0x24;M2C_FIELD(obj,s32*,0x60)=temp_v1_2&~2;func_80054FEC(0,250.0f,5.0f,obj,temp_s0_3,0x20,0);func_800624A8(obj,temp_s0_3,1.0f,1);func_80073508(temp_s0_3,0.001f);func_800853D4(temp_s0_3);func_80060968(obj);break;}
if((func_8005FD28(obj)<<0x18)!=0){
case 4: func_80060968(obj);
}
break;
}
}
