typedef struct { f32 minX, maxX, minY, maxY, minZ, maxZ; } Bounds;

/* Tests a segment (start p0, end p1, both as x/y/z triples) against a box grown by margin;
 * returns 1 if the segment is not rejected by the bounds test, 0 otherwise. */
s32 segmentPassesBoundsRejection(void *bounds, void *p0, void *p1, f32 margin) {
 f32 t0,t1,t2,t3,t4,t5; s32 result;
 f32 x = *(volatile f32*)p0;
 t0=((Bounds*)bounds)->minX;
 if (x < t0) {
  result=0;
  if (!(*(f32*)p1 < t0)) {
   x = *(volatile f32*)p0;
   goto L1;
  }
 } else {
 L1:
  t1=((Bounds*)bounds)->maxX;
  if (!(t1 < x) || (result=0, !(t1 < *(f32*)p1))) {
   f32 z = *(volatile f32*)((u8*)p0+8);
   t2=((Bounds*)bounds)->minZ;
   if (z < t2) {
    result=0;
    if (!(*(f32*)((u8*)p1+8) < t2)) {
     z = *(volatile f32*)((u8*)p0+8);
     goto L2;
    }
   } else {
   L2:
    t3=((Bounds*)bounds)->maxZ;
    if ((!(t3 < z) || (result=0, !(t3 < *(f32*)((u8*)p1+8)))) &&
        (((t4=((Bounds*)bounds)->minY-margin), (*(f32*)((u8*)p0+4)<t4) && (*(f32*)((u8*)p1+4)<t4)) ||
         ((t5=((Bounds*)bounds)->maxY+margin, result=1), (t5<*(volatile f32*)((u8*)p0+4)) && (t5<*(f32*)((u8*)p1+4))))) {
      result=0;
    }
   }
  }
 }
 return result;
}
