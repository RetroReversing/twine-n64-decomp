#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#endif
typedef struct { s16 f0; u8 pad[230]; } Slot_800C469E;
s32 func_80022DBC(s32);
s32 func_80063D38(void *,u32);
void func_8007089C(void *,s32,s32);
extern u8 D_800BF68A[];
extern Slot_800C469E D_800C469E[];
extern s32 gSaveSlotInfo;
extern u8 *D_8011ECC0[];
void func_80119AF4(void *arg0) {
 int __repair_literal;
 u8 temp_s0; u8 *var_s1; void *temp_s3; register u8 *temp_s5; register s32 var_s2;
 temp_s3=M2C_FIELD(arg0,void**,0x6C);
 var_s1=D_8011ECC0[*(D_800BF68A+(*((s32*)((s8*)&gSaveSlotInfo+(((func_80022DBC(((s32)(s8)M2C_FIELD(temp_s3,volatile u8*,0x182)) & 0xFFFF) & 0xFFFF))*0x18)))*0xC))];
 var_s2=-1U; temp_s5=var_s1+0x3B;
 for(;;){ temp_s0=*var_s1; __repair_literal=8;
 if((*(u8*)((char*)(temp_s3+(D_800C469E[temp_s0].f0*__repair_literal))+(unsigned short)0x1FC)!=0)&&((func_80063D38(temp_s3,temp_s0)<<0x18)!=0)) var_s2=temp_s0;
 else {var_s1+=1;if(var_s1<temp_s5)continue;} break;}
 if(((u32)var_s2!=-1U)&&((*(s8*)((char*)M2C_FIELD(arg0,void**,0x68)+0xE))!=(short)var_s2))func_8007089C(arg0,0,var_s2&0xFFFF);
}
