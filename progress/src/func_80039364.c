typedef s32 M2C_UNK; typedef s8 M2C_UNK8; typedef s16 M2C_UNK16; typedef s32 M2C_UNK32;
#define M2C_FIELD(expr,type_ptr,offset) (*(type_ptr)((s8 *)(expr)+(offset)))
extern s8 D_800C4320[]; extern s16 D_801007BA;
void func_80039364(void *arg0) {
 s16 *var_a1; s32 var_a2,var_v0; s16 var_t0; s8 temp_v0_2; u32 temp_a0,temp_v1; void **temp_v0; void *var_a0,*var_a3;
 temp_v0=M2C_FIELD(arg0,void ***,0x3C); var_t0=0;
 if(temp_v0!=NULL) {
  s16 phase = D_801007BA;
  var_a3=*temp_v0;
  do {
   temp_a0=M2C_FIELD(var_a3,u32 *,0); temp_v1=temp_a0&0xFF000000;
   if(temp_v1==0xDF000000) goto finish;
   if(temp_v1>0xDF000000) goto block_10;
   if(temp_v1!=0x01000000) goto block_10;
   var_a2=(temp_a0>>0xC)&0xFF; var_a1=M2C_FIELD(var_a3,s32 *,4)-0x80000000;
   if(var_a2==0) goto block_10;
   var_a0=var_a1+1;
   do {
    temp_v0_2=D_800C4320[(phase+(*var_a1+M2C_FIELD(var_a0,s16 *,2)))&0x7F];
    var_a1+=8; var_a2-=1; M2C_FIELD(var_a0,s16 *,0)=(s16)(temp_v0_2*4); var_a0+=0x10;
   } while(var_a2!=0);
   var_v0=var_t0; goto loop_continue;
finish: var_t0=1;
block_10: var_v0=var_t0;
loop_continue: var_a3+=8;
  } while(var_v0==0);
 }
}
