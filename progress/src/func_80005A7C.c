s16 *func_8000182C();
void func_80005A18(s32, s32, f32 *, s32);
void func_80005A7C(s32 arg0, f32 *out) {
 f32 buf[148]; f32 x,y,z;
 func_80005A18(arg0,*func_8000182C(arg0)-1,buf,1);
 x=buf[0]; y=buf[1]; z=buf[2];
 func_80005A18(arg0,0,buf,1);
 out[0]=x-buf[0]; out[1]=y-buf[1]; out[2]=z-buf[2];
}
