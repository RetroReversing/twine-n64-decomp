#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) 0
#endif
s32 func_80002BD0(void *,s32); u32 func_80045CF8(s32); void func_80077960(void *,s32); s32 func_8007C094(void *,void *,f32); extern u8 gActorDoneFlags[];
s32 func_80078274(void *arg0){s32 temp_v1;void *var_s0;void *temp_s2;var_s0=*M2C_FIELD(arg0,void ***,0x20);temp_s2=M2C_FIELD(arg0,void **,0x6C);if(var_s0!=NULL){for(;;){temp_v1=M2C_FIELD(var_s0,u16 *,0x78);if(temp_v1<0x61){if(temp_v1>=0x5E){if(((func_8007C094(arg0,var_s0+0x24,1.0f)<<0x18)!=0)&&(*(gActorDoneFlags+M2C_FIELD(M2C_FIELD(var_s0,void **,0x6C),u16 *,0x34))==0)){M2C_FIELD(var_s0,s32 *,0x60)|=0x800;func_80002BD0(arg0,func_80045CF8(2)+0x2F1);M2C_FIELD(temp_s2,s32 *,0x88)&=0xFDFFFFFF;func_80077960(arg0,0x87);return 1;}}}var_s0=M2C_FIELD(var_s0,void **,0);if(var_s0==NULL)return 0;}}return 0;}
