s32 func_800AA5E0(u64,u64,f64 *);
u64 func_800ABE80(f64);
extern f64 D_800D6EC8,D_800D6ED0,D_800D6ED8,D_800D6EE0;
f64 func_800AA798(f64 x) {
 f64 out; s32 sign; u64 a,b;
 if(x<0.0){x=-x;sign=-1;}else sign=1;
 if(D_800D6EC8<x){
 if(x>=D_800D6ED0){ b=0x1000000000000000ULL; a=func_800ABE80((D_800D6ED0/x)*D_800D6ED8); }
 else {a=0x1000000000000000ULL;b=func_800ABE80(x*D_800D6EE0);}
 func_800AA5E0(a,b,&out);
 }else out=x;
 { f64 result = out; if(sign<0) result=-result; return result; }
}
