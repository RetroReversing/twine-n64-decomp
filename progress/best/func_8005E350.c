typedef int M2C_UNK;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((char *)(expr)+(offset)))
M2C_UNK func_8000A894(u16);
M2C_UNK func_80070664(void *,s32,s32,M2C_UNK);
M2C_UNK func_80073AF8(M2C_UNK,s32,s32,s16,s32,s32,s32,s32,s32,s32,s32);
M2C_UNK func_80084338(u16,void *);
s32 func_80087100(s32);
extern M2C_UNK D_800C4478,D_800C447A,D_800C447C,D_800C4484;
extern s32 D_8010302C,D_80109688[];
void func_8005E350(void *arg0,s32 arg1,s32 arg2) {
 M2C_UNK (*temp_v0)(void *);
 s32 var_s4,var_s7,temp_s0,temp_s1; void *temp_s6;
 temp_s6=M2C_FIELD(arg0,void **,0x6C);
 func_80070664(temp_s6,arg1&0xFF,arg2&0xFF,0);
 temp_s1=arg1&0xFFFF; temp_s0=temp_s1*4;
 temp_v0=*(M2C_UNK (**)(void *))((char *)&D_800C447C+temp_s0);
 var_s7=-1; var_s4=-1;
 if(temp_v0!=0) temp_v0(arg0);
 D_8010302C+=1;
 if(!((temp_s1==0x1A)&((arg2&0xFFFF)==1))) {
 var_s7=*(s16 *)((char *)&D_800C4478+temp_s0);
 var_s4=*(s16 *)((char *)&D_800C447A+temp_s0);
 }
 func_80073AF8(0,D_80109688[(s32)M2C_FIELD(temp_s6,s8 *,0x182)],func_80087100((arg1|0x7000)&0xFFFF),var_s7,var_s4,1,0,0,0,0,0);
 if(M2C_FIELD(arg0,u16 *,0x78)==3) {func_80084338(*(u16 *)((char *)&D_800C4484+temp_s0),(char *)arg0+0x24); return;}
 func_8000A894(*(u16 *)((char *)&D_800C4484+temp_s0));
}
