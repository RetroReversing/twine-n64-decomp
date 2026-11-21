s32 func_8008C758(); s32 keyTableRegister(); s32 func_80097A40();
void func_800929AC(u16 *arg0, s32 arg1, s32 arg2) { u16 var_a0; if (keyTableRegister(arg2, func_8008C758(arg1)) & 0xFF) { var_a0 = *arg0; if ((var_a0 & 0xFFFF) != 0xFFFF) { do { arg0++; func_80097A40(var_a0, arg2); var_a0 = *arg0; } while (var_a0 != 0xFFFF); } } }
