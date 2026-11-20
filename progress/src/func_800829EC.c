s32 func_80097E14(s32);
void func_80092A4C(s32 arg0) { func_80097E14(arg0 & 0xFFFF); }
s32 func_800A9280(s32);
void func_800A2270(void) { func_800A9280(0x400); }
s32 func_800821B4(void);
extern s16 D_800C9D40;
void func_8008188C(void) { D_800C9D40 = 0; func_800821B4(); }
f64 func_800AB3C8(f64);
f32 func_800829EC(f32 arg0) { return (f32)func_800AB3C8((f64)arg0); }
