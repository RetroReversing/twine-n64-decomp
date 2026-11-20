s32 func_800A0220();
void func_8008C6F4(s32 a, s32 b) { func_800A0220(a,b*2); }
s32 func_8008C7D0();
void func_8009D0DC(void) { func_8008C7D0(); }
s32 rsp_set_pc_if_halted(s32);
void func_800A6790(void) { rsp_set_pc_if_halted(0); }
f64 twine_acos(f64);
f32 func_80082A0C(f32 a) { return (f32)twine_acos((f64)a); }
