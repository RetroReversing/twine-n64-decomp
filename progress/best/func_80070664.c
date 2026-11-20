extern s16 D_800C4486[];
s32 func_80070664(s32 arg0, u8 arg1, s32 arg2) {
int __repair_literal;

 u8 frame[16]; s16 temp_v0,temp_v1; int var_a1; s32 temp_a1,temp_a3,var_v0; u32 temp_a3_2;
 if (arg0 != 0) {
 temp_a3=arg1 & 255;
 if ((((u32)((arg1-0x17)&255)<2U)|(temp_a3==0x19))==0) {
 var_a1=1; var_v0=1<<16;
loop:
 temp_v0=var_a1+1;
 if (*(u8 *)((var_v0>>15)+arg0+0x139)!=temp_a3) {
 var_a1=temp_v0; var_v0=var_a1<<16;
 if (temp_v0>=30) {
 temp_a3_2=arg1&255; temp_v1=*(s16 *)((char *)D_800C4486+temp_a3_2*16);
__repair_literal = 8;

 if (temp_v1!=-1) *(s8 *)(arg0+temp_v1*__repair_literal+0x1fc)=1;
 temp_a1=arg1&255;
 if (temp_a3_2<31) { *(s16 *)(temp_a1*2+arg0+0x138)=temp_a1|((arg2&255)<<8); goto done; }
 return 0;
 }
 goto loop;
 }
done: return 1;
 }
 return 0;
 }
 return 0;
}
