static __inline__ u16 __repair_inline(u16 a) { return a; }
s32 func_8008C758(); s32 func_80097020(); s32 func_800972A4(); s32 func_8009757C(); s32 func_80097814(); s32 func_80097A40(); s32 func_80097D0C(); s32 func_80097EF8();
extern u8 D_800CF540; extern s16 D_800EDAA0; extern char D_800EDAA4[];
s32 func_80092A68(s32 *arg0,u16 arg1,s32 arg2,s32 arg3,void *arg4) {
 char *__repair_addr; s32 *var_a1,*var_a1_3,*var_a1_4,*var_s1,*var_v0,*var_v0_2,*var_v0_3,*var_v0_4; u16 *temp_s0; char *var_s0,*var_s0_2,*var_s0_3,*var_s0_4,*var_s0_5; u16 var_a0,var_v1,var_v1_2,var_v1_3,var_v1_4; void *temp_a1,*temp_v0,*temp_v0_2,*temp_v0_3,*temp_v0_4;
 if(D_800CF540&&D_800EDAA0<0x80){var_s1=arg0;if(*arg0!=-1){__repair_addr=(char *)(var_s1+1);  for (;;) {
     if(*(u16 *)__repair_addr==(arg1&0xffff)){*((s32 *)((s8 *)D_800EDAA4+D_800EDAA0))=var_s1;
     temp_v0=(void *)(var_s1[2]+(s32)var_s1); var_s0=(char *)temp_v0+8; var_v1=*(u16 *)((char *)temp_v0+8);
     if(var_v1!=0xffff) do {var_a1=(s32 *)((char *)arg4+*(s32 *)arg4);var_v0=0;if(*var_a1!=-1){     for (;;) {
         var_v0=var_a1;if(*(u16 *)((char *)var_a1+4)!=(var_v1&0xffff)){var_v0=0;var_a1=(s32 *)((char *)var_a1+*var_a1);if(*var_a1!=-1)continue;}
         break;
     }
}if(var_v0)func_80097EF8(*(u16 *)var_s0,(s8 *)var_v0+8);var_s0+=2;var_v1=__repair_inline(*(u16 *)var_s0);}while(var_v1!=0xffff);
     temp_s0=(u16 *)((char *)var_s1+var_s1[3]+8);if(func_80097814(arg3,func_8008C758(arg2))&0xff){var_a0=*temp_s0;var_s0_2=(char *)temp_s0+2;if(var_a0!=0xffff)do{func_80097A40(var_a0,arg3);var_a0=*(u16 *)var_s0_2;var_s0_2+=2;}while(var_a0!=0xffff);}
     temp_v0_2=(void *)(var_s1[4]+var_s1);var_s0_3=(char *)temp_v0_2+8;var_v1_2=*(u16 *)((char *)temp_v0_2+8);if(var_v1_2!=0xffff)do{var_v0_2=0;var_a1=(s32 *)((char *)arg4+*(s32 *)((char *)arg4+4));if(*var_a1!=-1){     for (;;) {
         var_v0_2=var_a1;if(*(u16 *)((char *)var_a1+4)!=(var_v1_2&0xffff)){var_a1=(s32 *)((char *)var_a1+*var_a1);var_v0_2=0;if(*var_a1!=-1)continue;}
         break;
     }
}if(var_v0_2)func_8009757C(*(u16 *)var_s0_3,var_v0_2+8);var_s0_3+=2;var_v1_2=*(u16 *)var_s0_3;}while(var_v1_2!=0xffff);
     temp_v0_3=(void *)(var_s1[5]+(s32)var_s1);var_s0_4=(char *)temp_v0_3+8;var_v1_3=*(u16 *)((char *)temp_v0_3+8);if(var_v1_3!=0xffff)do{var_a1_3=(s32 *)((char *)arg4+*(s32 *)((char *)arg4+8));var_v0_3=0;if(*var_a1_3!=-1){     for (;;) {
         var_v0_3=var_a1_3;if(*(u16 *)((char *)var_a1_3+4)!=(var_v1_3&0xffff)){var_a1_3=(s32 *)((char *)var_a1_3+*var_a1_3);var_v0_3=0;if(*var_a1_3!=-1)continue;}
         break;
     }
}if(var_v0_3)func_80097020(*(u16 *)var_s0_4,(s8 *)var_v0_3+8);var_s0_4+=2;var_v1_3=*(u16 *)var_s0_4;}while(var_v1_3!=0xffff);
     temp_v0_4=(void *)(var_s1[6]+(s32)var_s1);var_s0_5=(char *)temp_v0_4+8;var_v1_4=*(u16 *)((char *)temp_v0_4+8);if(var_v1_4!=0xffff)do{var_a1_4=(s32 *)((char *)arg4+*(s32 *)((char *)arg4+12));var_v0_4=0;if(*var_a1_4!=-1){     for (;;) {
         var_v0_4=var_a1_4;if(*(u16 *)((char *)var_a1_4+4)!=(var_v1_4&0xffff)){var_a1_4=(s32 *)((char *)var_a1_4+*var_a1_4);var_v0_4=0;if(*var_a1_4!=-1)continue;}
         break;
     }
}if(var_v0_4)func_800972A4(*(u16 *)var_s0_5,(s8 *)var_v0_4+12,*(u16 *)((char *)var_v0_4+10));var_s0_5+=2;var_v1_4=*(u16 *)var_s0_5;}while(var_v1_4!=0xffff);
     if(*(u16 *)((char *)var_s1+6)==1){do { func_80097D0C(arg1&0xffff,temp_a1+12,*(u16 *)((char *)temp_a1+8)); } while (0);temp_a1=(void *)(var_s1[7]+(s32)var_s1);}D_800EDAA0=(u16)D_800EDAA0+1;return 1;}var_s1=(s32 *)((char *)var_s1+*var_s1);if(*var_s1==-1)goto block_49;continue;
     break;
 }
}return 0;}block_49:return 0;
}
