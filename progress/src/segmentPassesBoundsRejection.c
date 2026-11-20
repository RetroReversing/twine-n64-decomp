#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
typedef struct { f32 f0,f4,f8,fC,f10,f14; } Bounds;
s32 segmentPassesBoundsRejection(void *a0, void *a1, void *a2, f32 a3) {
 f32 t0,t1,t2,t3,t4,t5; s32 result;
 f32 x = *(volatile f32*)a1;
 t0=((Bounds*)a0)->f0;
 if (x < t0) {
  result=0;
  if (!(*(f32*)a2 < t0)) {
   x = *(volatile f32*)a1;
   goto L1;
  }
 } else {
 L1:
  t1=((Bounds*)a0)->f4;
  if (!(t1 < x) || (result=0, !(t1 < *(f32*)a2))) {
   f32 z = *(volatile f32*)((u8*)a1+8);
   t2=((Bounds*)a0)->f10;
   if (z < t2) {
    result=0;
    if (!(*(f32*)((u8*)a2+8) < t2)) {
     z = *(volatile f32*)((u8*)a1+8);
     goto L2;
    }
   } else {
   L2:
    t3=((Bounds*)a0)->f14;
    if ((!(t3 < z) || (result=0, !(t3 < *(f32*)((u8*)a2+8)))) &&
        (((t4=((Bounds*)a0)->f8-a3), (*(f32*)((u8*)a1+4)<t4) && (*(f32*)((u8*)a2+4)<t4)) ||
         ((t5=((Bounds*)a0)->fC+a3, result=1), (t5<*(volatile f32*)((u8*)a1+4)) && (t5<*(f32*)((u8*)a2+4))))) {
      result=0;
    }
   }
  }
 }
 return result;
}
