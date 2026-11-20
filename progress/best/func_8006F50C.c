/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8004FF30();

void func_8006F50C(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    register f32 sp64;
    f32 sp50[3];
    u8 sp30[0x10];
    register f32 sp68;
    f32 sp20[3];
    register f32 sp48;
    register f32 temp_fv0;
    f32 sp60;
    register f32 temp_fv0_3;
    register f32 temp_fv0_2;
    f32 sp40[2];

    sp40[0] = (*(f32 *)((char *)(arg1) + 0x24));
    sp40[1] = (*(f32 *)((char *)(arg1) + 0x28));
    sp20[0] = 0.0f;
    sp48 = (*(f32 *)((char *)(arg1) + 0x2C));
    sp20[1] = 0.0f;
    sp20[2] = 0.0f;
    sp60 = (temp_fv0 = (*(f32 *)((char *)(arg1) + 0x24)));
    sp40[1] += 1.0f;
    sp50[0] = temp_fv0;
    temp_fv0_2 = (*(f32 *)((char *)(arg1) + 0x28));
    sp50[1] = temp_fv0_2;
    sp64 = temp_fv0_2;
    temp_fv0_3 = (*(f32 *)((char *)(arg1) + 0x2C));
    sp50[2] = temp_fv0_3;
    sp68 = temp_fv0_3;
    if ((func_8004FF30(arg0, arg1, sp50, arg3, sp30, 0x3F400000, 0x10, arg2) << 0x18) != 0) {
        sp20[2] += sp50[2] - sp68;
        sp20[1] += sp50[1] - sp64;
        sp20[0] += sp50[0] - sp60;
    }
    (*(f32 *)((char *)(arg1) + 0x24)) += sp20[0];
    (*(f32 *)((char *)(arg1) + 0x28)) += sp20[1];
    (*(f32 *)((char *)(arg1) + 0x2C)) += sp20[2];
}
