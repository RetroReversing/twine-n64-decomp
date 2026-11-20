s32 func_80002BD0(void *, void *, u16); u32 func_80045CF8(void *); s32 func_8007ADD0(void *);
s32 func_8007AEA4(void *arg0, void *arg1, s32 arg2) {
 void *temp_fp; volatile s32 saved; volatile s32 pad[2]; unsigned temp_v0,var_s1,temp_s5,var_s3; u16 temp_a1; register void *var_s0;
 temp_fp=*(void **)((char *)arg0+0x6C); var_s3=0; saved=*(u8 *)((char *)arg1+arg2*4-4);
loop_1: temp_v0=arg2-1; temp_s5=func_80045CF8((void *)saved);
 if(arg2-1!=0){var_s1=0;var_s0=arg1;
loop_3: if(*(u8 *)((char *)var_s0+4)<temp_s5){var_s1++;goto block_9;}
 temp_a1=*(u16 *)((char *)var_s0+2); if(temp_a1!=0){++var_s1;
 if((func_8007ADD0(arg0)<<24)!=0){*(u8 *)((char *)temp_fp+0x7F)=*(u8 *)((char *)var_s0+1);func_80002BD0(arg0,arg1,*(u16 *)((char *)var_s0+2));return 1;}
block_9: var_s0=(char *)var_s0+4;if(var_s1>=temp_v0)goto block_10;goto loop_3;} return 0;}
block_10: var_s3++;if(var_s3>=3U)return 0;goto loop_1;
}
