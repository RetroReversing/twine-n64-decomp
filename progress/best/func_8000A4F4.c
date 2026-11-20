void func_8000B900(s32,s32,u32); extern char D_1D69634[]; extern f64 D_800D2160;
f32 func_8000A4F4(s32 arg0){s32 sp10[3];f64 var_ft0;func_8000B900((s32)&sp10,(s32)((arg0*4)+D_1D69634),4);func_8000B900((s32)&sp10,(s32)((sp10[0]&0xFFFFFF)+D_1D69634),2);{ u32 value=*(volatile u16 *)&sp10; var_ft0=(f64)(s32)value; if((s32)value<0)var_ft0+=D_800D2160; }return (f32)var_ft0*0.013333334f;}
