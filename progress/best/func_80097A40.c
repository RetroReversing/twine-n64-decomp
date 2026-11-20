#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) 0
#endif
void func_8008C7B8(); extern u32 D_800F38EC; extern char D_800F38F0[]; extern char D_800F38F4[];
s32 func_80097A40(s32 arg0,u16 *arg1){ void *sp10[3]; s32 var_v1; char *var_a1=(char *)arg1; u32 var_a2=0; u32 count=D_800F38EC; u32 var_a3; char *var_s0; s32 idx,table_off; if(count){var_v1=0;for(;;){if(*((void **)(D_800F38F0+var_v1))!=var_a1){var_a2++;var_v1+=0xC;if(var_a2<count)continue;}break;}} var_a3=*(u16 *)var_a1;if(var_a3!=0xFFFF){idx=var_a2*2; arg0 &= 0xFFFF; table_off=(idx+var_a2)*4; var_s0=var_a1+2;loop_6:if(var_a3==(u32)arg0){if(*(u16 *)var_s0==0){sp10[0]=var_a1+0xC;*(s32 *)(var_s0+6)=*(s32 *)(var_s0+2)+*(s32 *)(D_800F38F4+table_off);func_8008C7B8(&sp10,var_a1+8,var_a2,var_a3);}(*(u16 *)var_s0)++;}else{var_a1+=0x1C;var_a3=*(u16 *)var_a1;var_s0+=0x1C;if(var_a3!=0xFFFF)goto loop_6;}}return 1;}
