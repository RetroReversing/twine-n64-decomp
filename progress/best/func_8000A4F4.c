typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8*)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
void func_8000B900(s32,s32,u32); extern char D_1D69634[]; extern f64 D_800D2160;
f32 func_8000A4F4(s32 arg0){s32 sp10;f64 var_ft0;func_8000B900((s32)&sp10,(s32)((arg0*4)+D_1D69634),4);func_8000B900((s32)&sp10,(s32)((sp10&0xFFFFFF)+D_1D69634),2);var_ft0=(f64)sp10;if(sp10<0)var_ft0+=D_800D2160;return (f32)var_ft0*0.013333334f;}
