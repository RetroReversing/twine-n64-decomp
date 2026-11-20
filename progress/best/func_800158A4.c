struct vec { f32 x,y,z; };
extern u16 D_800B35B0;
s8 Ray_CastObjects(void *, void *, f32 *, f32 *, f32 *, f32, s32, s32, s32);
s32 func_8004F990(void *, f32 *, f32 *, s32, f32 *, s32, s32, s32);
f32 Vec3_DistanceSq(f32 *, f32 *);
f32 func_80045764(f32 *, f32 *);
void *func_80047B44(void *, f32 *, f32 *, f32 *);
extern void func_8004D910(void);
#define FIELD(p,t,o) (*(t *)((s8 *)(p)+(o)))
s32 func_800158A4(void *arg0, void *arg1, void *arg2, void *arg3, s32 *arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
 volatile s32 padding[6]; f32 p[3], d[3], q[3], r[3], out[3]; s32 mode=0; void *obj=arg2; f32 limit=65536.0f; f32 v;
 D_800B35B0++;
 *(struct vec *)p=*(struct vec *)arg0;
 *(struct vec *)d=*(struct vec *)arg1; q[0]=0.0f;
 if(!obj){*(struct vec *)arg3=*(struct vec *)arg0;__shared_return_0:
    return 0;}
 for (;;) {
  q[0]=d[0]-p[0];q[1]=d[1]-p[1];q[2]=d[2]-p[2];
  v=func_80045764(q,q);
  if(FIELD(obj,u16,0x58)==0x46){
   if(Ray_CastObjects(func_8004D910,obj,p,q,r,v,arg5,(s8)arg7,arg8)){limit=Vec3_DistanceSq(p,r);mode=1;}
   if(arg6 && func_8004F990(obj,p,d,arg6,out,0,0,arg8) && (mode!=1 || Vec3_DistanceSq(p,out)<limit)) mode=2;
   if(mode) {
    if(mode==1){*(struct vec *)arg3=*(struct vec *)r;}
    if(mode==2){*(struct vec *)arg3=*(struct vec *)out;}
    if(arg4)*arg4=mode;
    goto __shared_return_0;
   }
  }
  obj=func_80047B44(obj,p,d,out);
  if(!obj)return 1;
  *(struct vec *)p=*(struct vec *)out;
  obj=FIELD(obj,void*,8);
  if(!obj)return 1;
 }
}
