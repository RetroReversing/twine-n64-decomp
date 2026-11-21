/* machine draft */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
#define M2C_BITWISE(type,expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif
extern s32 D_801002C0[1];
s32 lookupDataEntry(); s32 sprintf();
extern s32 D_801002B4; extern void *D_80102CD0;
extern s16 D_8011F15C[];
extern char D_8011F2B8[],D_8011F3E0[],D_8011F3E8[];
void func_8011D158(s16 arg0) {
int __repair_literal;

 s32 var_a0,var_a0_2,temp_a1,var_a1,var_a1_2,var_a2,var_v0;
 u8 temp_s2; void **temp_a0_2,**temp_a1_2;
 void *temp_a0,*temp_a0_3,*temp_a2,*temp_v1;
 if(arg0<D_801002C0[0]) {
 temp_a0=M2C_FIELD((&D_80102CD0)[arg0],void**,0xB4);
 temp_s2=M2C_FIELD(temp_a0,u8*,0x12); temp_a1_2=&D_80102CD0;
 if(temp_s2==2) {
 var_a2=D_801002B4; var_a1=0;
__repair_literal = 0;

 if(var_a2>__repair_literal) do { if(var_a1++!=arg0) { temp_v1=M2C_FIELD(*temp_a1_2,void**,0xB4); var_a2-=(M2C_FIELD(temp_a0,u16*,0xC)-M2C_FIELD(temp_a0,u16*,0xE)) >= (M2C_FIELD(temp_v1,u16*,0xC)-M2C_FIELD(temp_v1,u16*,0xE)); } temp_a1_2+=1; } while(var_a1<M2C_FIELD(&D_801002C0,s32*,-0xC));
 if(var_a2!=2) { if(var_a2<3) { var_a0=0x2E5; if(var_a2!=1) var_a1_2=arg0<<16; else goto block_16; } else if(var_a2!=3) { var_a0=0x2E8; if(var_a2!=4) var_a1_2=arg0<<16; else goto block_16; } else {var_a0=0x2E7; goto block_16;} } else {var_a0=0x2E6;
block_16: sprintf((arg0*0xC)+D_8011F2B8,lookupDataEntry(var_a0,(u8)var_a1,var_a2,temp_a1_2)); var_a1_2=arg0<<16; }
 temp_a1=var_a1_2>>16; temp_a0_2=(temp_a1*4)+D_8011F3E8; temp_a2=*temp_a0_2;
 M2C_FIELD(temp_a2,s32*,0x28)=(M2C_FIELD(temp_a2,s32*,0x28)&~0xFC)|0xC; M2C_FIELD(*temp_a0_2,s32*,0x10)=-1; *(s16*)(D_8011F3E0+temp_a1*2)=0x3C; return;
 }
 var_a0_2=0x2E6;
 if(D_8011F15C[temp_s2]>=D_8011F15C[1-temp_s2]) var_a0_2=0x2E5;
 sprintf((arg0*0xC)+D_8011F2B8,lookupDataEntry(var_a0_2,temp_s2,(s32)&D_80102CD0));
 temp_a1_2=((s32)(arg0<<16)>>14)+D_8011F3E8; temp_a0_3=*temp_a1_2;
 M2C_FIELD(temp_a0_3,s32*,0x28)=(M2C_FIELD(temp_a0_3,s32*,0x28)&~0xFC)|0xC;
 if(temp_s2==0) var_v0=0xFF2020FF; else var_v0=0x2020FFFF;
 M2C_FIELD(*temp_a1_2,s32*,0x10)=var_v0; *(s16*)(D_8011F3E0+((s32)(arg0<<16)>>15))=0x3C;
 }
}
