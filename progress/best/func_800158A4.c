extern u16 D_800B35B0;
s32 func_8004E6E4(void *, void *, f32 *, f32 *, f32 *, f32, s32, s32, s32);
s32 func_8004F990(void *, f32 *, f32 *, s32, f32 *, s32, s32, s32);
f32 func_80045540(f32 *, f32 *);
f32 func_80045764(f32 *, f32 *);
void *func_80047B44(void *, f32 *, f32 *, f32 *);
extern void *func_8004D910;
#define FIELD(p,t,o) (*(t *)((s8 *)(p)+(o)))
s32 func_800158A4(void *arg0, void *arg1, void *arg2, void *arg3, s32 *arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
 f32 p[3], d[3], q[3], r[3], out[3]; s32 mode=0; void *obj=arg2; f32 limit=65536.0f; f32 v;
 D_800B35B0++;
 d[0]=((f32*)arg1)[0];d[1]=((f32*)arg1)[1];d[2]=((f32*)arg1)[2]; q[0]=0.0f;
 p[0]=((f32*)arg0)[0];p[1]=((f32*)arg0)[1];p[2]=((f32*)arg0)[2];
 if(!obj){((f32*)arg3)[0]=p[0];((f32*)arg3)[1]=p[1];((f32*)arg3)[2]=p[2];__shared_return_0:
    return 0;}
 for (;;) {
  q[0]=d[0]-p[0];q[1]=d[1]-p[1];q[2]=d[2]-p[2];
  v=func_80045764(q,q);
  if(FIELD(obj,u16,0x58)==0x46){
   if(func_8004E6E4(func_8004D910,obj,p,q,r,v,arg5,(s8)arg7,arg8)){limit=func_80045540(p,r);mode=1;}
   if(arg6 && func_8004F990(obj,p,d,arg6,out,0,0,arg8) && (mode!=1 || func_80045540(p,out)<limit)) mode=2;
   if(mode==1){((f32*)arg3)[0]=r[0];((f32*)arg3)[1]=r[1];((f32*)arg3)[2]=r[2];}
   if(mode==2){((f32*)arg3)[0]=out[0];((f32*)arg3)[1]=out[1];((f32*)arg3)[2]=out[2];}
   if(arg4)*arg4=mode;
   goto __shared_return_0;
  }
  obj=func_80047B44(obj,p,d,out);
  if(obj == 0)return 1;
  p[0]=out[0];p[1]=out[1];p[2]=out[2];
  obj=FIELD(obj,void*,8);
  if(!obj)return 1;
 }
}
