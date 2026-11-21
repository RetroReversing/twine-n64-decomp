s32 cordicAtanVectoring(u64,u64,f64 *);
u64 f64ToFixed60(f64);
extern f64 D_800D6EC8,D_800D6ED0,D_800D6ED8,D_800D6EE0;
/* Arctangent of x: CORDIC vectoring on a range-reduced fixed-point ratio, then sign restored. */
f64 atan(f64 x) {
 f64 angle; s32 sign; u64 fixedX,fixedY; f64 threshold;
 if(x<0.0){x=-x;sign=-1;}else sign=1;
 threshold = D_800D6EC8;
 if(threshold<x){
 f64 ratio = D_800D6ED0;
 if(x>=ratio){ fixedY=0x1000000000000000ULL; ratio /= x; threshold = D_800D6ED8; fixedX=f64ToFixed60(ratio * threshold); }
 else {fixedX=0x1000000000000000ULL;fixedY=f64ToFixed60(x*D_800D6EE0);}
 cordicAtanVectoring(fixedX,fixedY,&angle);
 }else angle=x;
 { f64 result = angle; if(sign<0) result=-result; return result; }
}
