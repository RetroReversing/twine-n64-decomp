s32 func_800AA5E0(u64,u64,f64 *);
u64 func_800ABE80(f64);
extern f64 D_800D6EC8,D_800D6ED0,D_800D6ED8,D_800D6EE0;
f64 atan(f64 x) {
 f64 out; s32 sign; u64 a,b; f64 scale;
 if(x<0.0){x=-x;sign=-1;}else sign=1;
 scale = D_800D6EC8;
 if(scale<x){
 f64 ratio = D_800D6ED0;
 if(x>=ratio){ b=0x1000000000000000ULL; ratio /= x; scale = D_800D6ED8; a=func_800ABE80(ratio * scale); }
 else {a=0x1000000000000000ULL;b=func_800ABE80(x*D_800D6EE0);}
 func_800AA5E0(a,b,&out);
 }else out=x;
 { f64 result = out; if(sign<0) result=-result; return result; }
}
