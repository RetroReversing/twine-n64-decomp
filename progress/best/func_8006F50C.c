/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8004FF30();

void func_8006F50C(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    register f32 sp64;
    u8 sp30[0x10];
    f32 sp50;
    f32 sp28;
    f32 sp68;
    f32 sp20;
    register f32 sp48;
    register f32 temp_fv0;
    f32 sp54;
    f32 sp58;
    f32 sp60;
    f32 sp24;
    f32 sp44;
    register f32 temp_fv0_3;
    f32 temp_fv0_2;
    f32 sp40;

    sp40 = (*(f32 *)((char *)(arg1) + 0x24));
    sp44 = (*(f32 *)((char *)(arg1) + 0x28));
    sp48 = (*(f32 *)((char *)(arg1) + 0x2C));
    sp20 = 0.0f;
    sp24 = 0.0f;
    sp28 = 0.0f;
    temp_fv0 = (*(f32 *)((char *)(arg1) + 0x24));
    sp44 += 1.0f;
    sp60 = temp_fv0;
    sp50 = temp_fv0;
    temp_fv0_2 = (*(f32 *)((char *)(arg1) + 0x28));
    sp64 = temp_fv0_2;
    sp54 = temp_fv0_2;
    temp_fv0_3 = (*(f32 *)((char *)(arg1) + 0x2C));
    sp68 = temp_fv0_3;
    sp58 = temp_fv0_3;
    if ((func_8004FF30(arg0, arg1, &sp50, sp30, 0x3F400000, 0x10, arg2, arg3) << 0x18) != 0) {
        sp28 += sp58 - sp68;
        sp24 += sp54 - sp64;
        sp20 += sp50 - sp60;
    }
    (*(f32 *)((char *)(arg1) + 0x24)) += sp20;
    (*(f32 *)((char *)(arg1) + 0x28)) += sp24;
    (*(f32 *)((char *)(arg1) + 0x2C)) += sp28;
}
