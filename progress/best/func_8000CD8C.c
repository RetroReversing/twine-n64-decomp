s32 func_8000C860();
extern void **D_800B2710;
extern s16 *D_800C3CF8[];
extern s16 D_800C4708[];
extern u16 D_800E0740;
extern s16 D_80100B60;
void func_8000CD8C(void) {
 s32 temp_v0; char *var_s2; s32 temp_a0; s32 var_s4; s32 var_a1; s32 var_s3; s32 temp_v1; s32 var_s0; void *temp_s1; void *var_s1;
 var_s3=0;var_s4=1;var_s2=(char*)&D_80100B60;D_800E0740=0xFFFF;var_s1=*D_800B2710;
 do { var_a1=-1;temp_v0=*(s32*)((char*)var_s1);var_s0=0;temp_s1=(char*)var_s1+4;temp_a0=temp_v0>>8;temp_v1=temp_v0&0x3F;
 switch(temp_v1) {
 case 35:var_s4=0;break;
 case 36:break;
 case 0:var_a1=**(u16**)((char*)var_s1+4);D_800E0740=var_a1;
 case 9:case 10:case 14:case 22:case 23:case 28:var_s0=1;break;
 case 26:var_s0=2;break;
 case 1:case 2:case 4:case 5:case 6:case 8:case 15:case 16:case 20:case 21:case 25:var_s0=3;break;
 case 17:var_s0=6;break;
 case 33:if((temp_a0&255)==0x69)var_a1=D_800C4708[func_8000C860((temp_a0>>8)&255)*116];break;
 case 18:case 19:var_a1=**(u16**)((char*)var_s1+4);var_s0=7;break;
 case 11:case 12:case 13:var_a1=D_800C3CF8[(*(u8*)((char*)temp_s1+3))*3][0];var_s0=7;break;
 case 3:case 7:case 24:var_s0=12;break;
 }
 if((s32)var_a1>=0){*(s16*)var_s2=(s16)var_a1;var_s2+=2;var_s3++;}
 var_s1=(char*)temp_s1+(var_s0*4);
 }while(var_s4);
 (&D_80100B60)[var_s3]=-1;
}
