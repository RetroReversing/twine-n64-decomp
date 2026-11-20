void *func_8002B850(void); extern s32 D_80102F40;
s32 func_8002BA9C(void) { f32 temp_fv1; register long ret; register unsigned long ret2; void *temp_v0;
temp_v0=func_8002B850(); D_80102F40=(s32)temp_v0;
if(temp_v0!=NULL){temp_fv1=(f32)(*(u16*)((char*)temp_v0+2));ret=(u16)temp_fv1;ret2=ret;}else ret2=0x64; return ret2;}
