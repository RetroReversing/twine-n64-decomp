f32 approxDistance(void *,void *); f32 absFloat(f32);
s32 func_80078114(void **arg0,void *arg1,void **arg2,f32 *arg3) {
 f32 temp_fv0; s32 temp_v1,var_s4; void *temp_s2,*var_s0;
 var_s0=*arg0;temp_s2=*(void **)((char *)arg1+0x6c);var_s4=0;
 if(var_s0!=NULL)do {
 if(*(u16 *)((char *)var_s0+0x78)==1) {
 if((var_s0!=arg1)&&(*(s32 *)((char *)var_s0+0x20)!=0)&&
 (((temp_v1=(*(s32 *)((char *)(*(void **)((char *)var_s0+0x6c))+0x88)&0x01e00000),(temp_v1==0x400000)&&((*(s32 *)((char *)temp_s2+0x88)&0x01e00000)==0x200000))||((temp_v1==0x200000)&&((*(s32 *)((char *)temp_s2+0x88)&0x01e00000)==0x400000)))&&((absFloat(*(f32 *)((char *)arg1+0x28)-*(f32 *)((char *)var_s0+0x28))<1.0f)||(*(s32 *)((char *)arg1+0x20)==*(s32 *)((char *)var_s0+0x20))))) {
 temp_fv0=approxDistance((char *)arg1+0x24,(char *)var_s0+0x24);
 if(temp_fv0<*arg3){var_s4=1;*arg3=temp_fv0;*arg2=var_s0;}
 }
 }
 var_s0=*(void **)var_s0;
 } while(var_s0!=NULL);
 return var_s4;
}
