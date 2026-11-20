#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
s32 func_80096E7C(void *, s32); void func_80096F44(void *, s32, s32); extern char D_80112E9E[];
s32 func_8009ABD4(s32 arg0, void *arg1, s32 arg2) {
 s16 var_s1; s32 temp_v0,temp_v0_2,temp_v0_4; short var_a2; u32 temp_v0_3,temp_v1,temp_v1_3,temp_v1_6,var_a0,var_v1;
 temp_v1=*(volatile u32 *)((s8 *)arg1+4);
 if(*(volatile u8 *)arg1!=0) var_s1=func_80096E7C((void *)arg0,temp_v1&0xFF);
 else { temp_v1&=0x1F; temp_v0=temp_v1*2; if(temp_v1<0x10U)var_s1=M2C_FIELD((temp_v0+arg0),s16 *,0x180); else var_s1=*(s16 *)(D_80112E9E+temp_v0); }
 var_v1=arg2&0xFF;
 if(var_v1==4) var_a0=(u32)M2C_FIELD(arg1,u32 *,4)>>8;
 else { temp_v1_3=M2C_FIELD(arg1,u32 *,4); temp_v0_3=temp_v1_3>>0x10; if((temp_v1_3>>8)&0xFF)var_a0=func_80096E7C((void *)arg0,temp_v0_3&0xFF); else {temp_v1=temp_v0_3&0x1F;temp_v0_2=temp_v1*2;if(temp_v1<0x10U)var_a0=(u32)M2C_FIELD((temp_v0_2+arg0),s16 *,0x180);else var_a0=(u32)*(s16 *)(D_80112E9E+temp_v0_2);} var_v1=arg2&0xFF; }
 switch(var_v1){case 0:case 4:temp_v0_4=var_s1+(s16)var_a0;break;case 1:temp_v0_4=var_s1-(s16)var_a0;break;case 2:temp_v0_4=var_s1*(s16)var_a0;break;case 3:if((s16)var_a0!=0)temp_v0_4=var_s1/(s16)var_a0;else temp_v0_4=0;break;}
 temp_v0_3=M2C_FIELD(arg1,u32 *,0); temp_v1_6=temp_v0_3>>0x10;
 if(temp_v0_4 < -0x8000)var_a2=-0x8000;else{var_a2=0x7FFF;if(temp_v0_4<=0x7FFF)var_a2=temp_v0_4;}
 if((temp_v0_3>>8)&0xFF){func_80096F44((void *)arg0,temp_v1_6&0xFF,(s16)var_a2);return 0;}
 temp_v1_6=(temp_v0_3>>0x10)&0x1F;temp_v0_4=temp_v1_6*2;
 if(temp_v1_6<0x10U)M2C_FIELD((temp_v0_4+arg0),s16 *,0x180)=(s16)var_a2;else *(s16 *)(D_80112E9E+temp_v0_4)=(s16)var_a2;
 return 0;
}
