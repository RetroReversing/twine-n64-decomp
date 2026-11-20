void *func_80016410(s32, s32, s32); s32 func_80016990(void *, s32); s32 func_80044670(void *, s32, s32); s32 func_80045CF8(s32); f32 func_80045D2C(f32); f32 func_80045D8C(f32, f32); extern f64 D_800D4148;
void func_8005D444(void *arg0, s32 arg1, f32 arg2, u32 arg3, s32 arg4, s32 arg5) {
 f32 temp_fs2; volatile long long reserve_gap; f64 temp_fs1, var_fv0, var_fv0_2; register f64 var_fv0_3; unsigned int temp_v0_2; unsigned temp_v0_3; u32 temp_v0_4; register void *temp_v0; register void *temp_s1; u32 var_s2;
 var_s2=0; temp_fs2=arg2*0.5f;
 if(arg3!=0){temp_fs1=D_800D4148;do{temp_v0=func_80016410(0x20,arg1,0);if(temp_v0!=NULL){temp_s1=*(void **)((char *)temp_v0+0x6C);*(u16 *)((char *)temp_v0+0x78)=0x66;*(u16 *)((char *)temp_s1+0x1C)=0x3C;*(u16 *)((char *)temp_v0+0x7A)=0;*(f32 *)((char *)temp_v0+0x54)=(f32)(func_80045D2C(0.25f)+0.25f);*(f32 *)((char *)temp_s1+4)=func_80045D8C(arg2,temp_fs2);*(f32 *)((char *)temp_s1+8)=func_80045D8C(arg2,temp_fs2);*(f32 *)((char *)temp_s1+0xC)=func_80045D8C(arg2,temp_fs2);
 temp_v0_2=func_80045CF8(0x100)-0x80;var_fv0=(f64)temp_v0_2;if(temp_v0_2<0)var_fv0+=temp_fs1;*(f32 *)((char *)temp_s1+0x10)=(f32)var_fv0;
 temp_v0_3=func_80045CF8(0x100)-0x80;var_fv0_2=(f64)temp_v0_3;if(temp_v0_3<0)var_fv0_2+=temp_fs1;*(f32 *)((char *)temp_s1+0x14)=(f32)var_fv0_2;
 temp_v0_4=func_80045CF8(0x100)-0x80;var_fv0_3=(f64)temp_v0_4;if(temp_v0_4<0)var_fv0_3+=temp_fs1;*(f32 *)((char *)temp_s1+0x18)=(f32)var_fv0_3;
 *(u8 *)((char *)temp_v0+0x7F)=0;*(u8 *)((char *)temp_v0+0x81)=0xFF;*(u8 *)((char *)temp_v0+0x80)=0;*(s32 *)((char *)temp_v0+0x58)|=0x10000;func_80044670(temp_v0,arg4,arg5);func_80016990(temp_v0,*(s32 *)((char *)arg0+0x20));}++var_s2;}while(var_s2<arg3);}
}
