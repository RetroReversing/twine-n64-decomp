typedef union { f64 d; u32 w[2]; } DBits;
f64 func_800ABA40(s32,s32,s32,s32,f64,f64);
extern f64 D_800D7038,D_800D7040; extern char D_800D7030[];
f64 sqrt(f64 arg0) {
 register DBits tmp; f64 v; f32 x,y,z; s32 exp,t,i,scale; u32 hi,lo;
 tmp.d=arg0; hi=tmp.w[0]; lo=tmp.w[1];
 if((s32)hi<0) return func_800ABA40(1,(s32)D_800D7030,(s32)lo,(s32)hi,0.0,0.0);
 exp=(hi>>20)&0x7ff;
 if(exp==0) return 0.0;
 exp-=0x3ff;
 tmp.w[0]=(hi&0x800fffff)|0x3fd00000; tmp.w[1]=lo;
 x=(f32)tmp.d;
 t=((s32)x&0xC07FFFFF)|0x3D000000;
 if(exp&1) {
  scale=(exp-1)>>1;
  y=(f32)((f64)(x+*(f32 *)&t)+D_800D7038);
 } else {
  scale=exp>>1;
  y=(f32)((f64)(x-*(f32 *)&t)+D_800D7040);
 }
 z=y+x/y;
 t=((s32)z&0xC07FFFFF)|((((s32)z&0x3F800000)+0xFF800000)&0x3F800000);
 v=(f64)*(f32 *)&t;
 i=0; do {
  v+=arg0/v; tmp.d=v;
  tmp.w[0]=(tmp.w[0]&0x800fffff)|(((tmp.w[0]&0x7ff00000)-0x00100000)&0x7ff00000);
  v=tmp.d; i++;
 } while(i<2);
 tmp.d=v;
 tmp.w[0]=(tmp.w[0]&0x800fffff)|(((u32)(scale+0x3ff)&0x7ff)<<20);
 return tmp.d;
}
