extern s32 D_801002C0, D_8010A4E8;
extern u8 D_8010A4FD;
s32 func_80075570(s32,s32,s32,s32);
void func_80075EBC(void) {
 register f32 h, width;
 f32 full, half;
 int mode;
 h = 120.0f; full = 240.0f; mode = D_8010A4E8; half = 160.0f; width = 320.0f; if (mode) { h = 240.0f; full = 480.0f; }
 switch (D_801002C0) {
 case 2:
   if (D_8010A4FD == 1) func_80075570((u32)(half-1.0f),0,3,(u32)full);
   else func_80075570(0,(u32)(h-1.0f),(u32)width,3);
   break;
 case 3: case 4:
   func_80075570((u32)(half-1.0f),0,3,(u32)full);
   func_80075570(0,(u32)(h-1.0f),(u32)width,3);
   break;
 }
}
