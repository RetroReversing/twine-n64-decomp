/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80016410();
s32 func_80016990();
s32 func_80044670();
s32 func_80045CF8();
f32 func_80045D2C();
f32 func_80045D8C();

void func_80060D74(void *arg0) {
    f32 sp10;
    register unsigned long sp14;
    register f32 sp18;
    f32 temp_a0;
    void *temp_s0;
    register void *temp_s3;
    void *temp_v0;

    temp_s3 = (*(void **)((char *)(arg0) + 0x6C));
    if ((((*(s32 *)((char *)(arg0) + 0x58)) & 4) || ((*(s32 *)((char *)(arg0) + 0x60)) & 0x3000)) && (func_80045CF8((*(s16 *)((char *)(arg0) + 0x7C))) == 0)) {
        temp_a0 = (*(f32 *)((char *)(arg0) + 0x2C));
        sp10 = (*(f32 *)((char *)(arg0) + 0x24));
        sp14 = (*(s32 *)((char *)(arg0) + 0x28));
        sp10 += func_80045D8C(0x40000000) * (*(f32 *)((char *)(temp_s3) + 0));
        temp_v0 = func_80016410(0xC, &sp10, 0);
        sp18 = (u32)temp_a0;
        sp18 += func_80045D8C() * (*(f32 *)((char *)(temp_s3) + 0));
        if (temp_v0 != (int)NULL) {
            temp_s0 = (*(void **)((char *)(temp_v0) + 0x6C));
            func_80044670(temp_v0, 2, 0x1B);
            (*(f32 *)((char *)(temp_s0) + 4)) = (f32) (*(f32 *)((char *)(temp_s3) + 4));
            (*(f32 *)((char *)(temp_s0) + 8)) = (f32) -func_80045D2C(0x3EA740DB);
            (*(s16 *)((char *)(temp_v0) + 0x78)) = 0x65;
            (*(s8 *)((char *)(temp_v0) + 0x7F)) = 0;
            (*(s8 *)((char *)(temp_v0) + 0x80)) = 0;
            (*(s8 *)((char *)(temp_v0) + 0x81)) = 0;
            (*(s8 *)((char *)(temp_v0) + 0x82)) = 0x40;
            func_80016990(temp_v0, (*(s32 *)((char *)(arg0) + 0x20)));
        }
    }
    (*(s32 *)((char *)(arg0) + 0x60)) = 0;
}
