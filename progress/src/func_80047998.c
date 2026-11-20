s32 func_800476E0(void *, void *, void *, void *, f32);
s32 func_800477D0(void *, void *, void *, void *, f32);
void func_800478B4(void *, void *, void *, void *);
void func_80047948(void *, void *, void *);
s32 func_80047998(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5, f32 arg6, f32 arg7) {
 char sp18[16], sp28[16], sp38[16];
 register char *p = sp18;
 func_80047948(arg3,arg5,p);
 func_800478B4(sp28,p,arg3,arg2);
 func_800478B4(sp38,p,arg5,arg4);
 if ((func_800476E0(arg1,arg4,arg5,sp28,arg7)<<24)==0) goto fail;
 return (func_800477D0(arg0,arg2,arg3,sp38,arg6)<<24)!=0;
 fail: return 0;
}
