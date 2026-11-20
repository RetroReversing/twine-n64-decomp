typedef union { f64 d; u32 w[2]; } DBits;
f64 func_800ABA40(s32,s32,s32,s32,f64,f64);
extern f64 D_800D7038,D_800D7040; extern char D_800D7030[];
f64 sqrt(f64 arg0) {
 DBits in, approx, initial; f64 v; f32 x,y,z; s32 exp,t,i; u32 hi,lo;
 in.d=arg0; hi=in.w[0]; lo=in.w[1];
 if((s32)hi<0) return func_800ABA40(1,(s32)D_800D7030,(s32)lo,(s32)hi,0.0,0.0);
 exp=(hi>>20)&0x7ff;
 if(exp==0) return 0.0;
 exp-=0x3ff;
 approx.w[0]=(hi&0x800fffff)|0x3fd00000; approx.w[1]=lo;
 x=(f32)approx.d;
 t=((s32)x&0xC07FFFFF)|0x3D000000;
 if(exp&1) y=(f32)((f64)(x+*(f32 *)&t)+D_800D7038);
 else y=(f32)((f64)(x-*(f32 *)&t)+D_800D7040);
 z=y+x/y;
 t=((s32)z&0xC07FFFFF)|((((s32)z&0x3F800000)+0xFF800000)&0x3F800000);
 *(f32 *)&t=(f32)t;
 initial.d=(f64)*(f32 *)&t; v=initial.d;
 i=0; do { v+=arg0/v; i++; } while(i<2);
 return v;
}
