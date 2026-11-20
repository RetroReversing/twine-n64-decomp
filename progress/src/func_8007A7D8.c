s32 func_80000A30(s32, s16);
f32 func_80045E34(void *);
f32 approximate_hypot2(f32, f32);
f32 func_800828D0(f32);
f32 func_80082A70(f32, f32);
extern s32 gUpdateGateWord;
s32 func_8007A7D8(void *arg0, void *arg1, s32 *arg2, f32 arg3) {
 f32 dx,dy,dz,h,lim; s32 t;
 if (arg3 < func_80045E34((s8 *)arg0 + 0x24)) return 0;
 do { dx=*(f32 *)((s8 *)arg1)-*(f32 *)((s8 *)arg0+0x24); } while (0);
 { dz=*(f32 *)((s8 *)arg1+8)-*(f32 *)((s8 *)arg0+0x2c); }
 { dy=*(f32 *)((s8 *)arg1+4)-*(f32 *)((s8 *)arg0+0x28); }
 h=approximate_hypot2(dx,dz);
 if (gUpdateGateWord==0) {
   t=(s32)(func_80082A70(dy,h)*651.8986f);
   if(func_800828D0((f32)t)>512.0f) return 0;
 }
 t=(s32)(func_80082A70(dx,dz)*651.8986f);
 *arg2=t;
 t=func_80000A30(t,*(s16 *)((s8 *)*(void **)((s8 *)arg0+0x68)+0x8c));
 dx=gUpdateGateWord!=0?682.0f:910.0f;
 if(dx<func_800828D0((f32)t)) return 0;
 return 1;
}
