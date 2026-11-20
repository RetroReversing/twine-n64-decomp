extern void func_80046EB8(void *, void *, void *, void *, f32, void *);
extern s32 D_800BF5B0, D_800E10C0;
s32 *func_8002B400(f32 a, s32 n, char *p) {
 f32 t; s32 i;
 if (n-3 <= 0) return &D_800BF5B0;
 t=0.0f;
 if (a < 0.0f) a=t;
 else {
   t=(f32)(n-3);
   if (a > 1.0f) a=t;
   else a=a*t;
 }
 i=(s32)a;
 if (i>=n-3) i=n-3;
 a -= (f32)i;
 p += i*12;
 func_80046EB8(p,p+12,p+24,p+36,a,&D_800E10C0);
 return &D_800E10C0;
}
