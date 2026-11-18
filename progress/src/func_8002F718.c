/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8002E9D0();
s32 func_8002FBE4();
extern u16 D_800BFC92;
extern u16 D_800BFC98;
extern char D_800E1590[];
extern u8 D_80102EDE;

void func_8002F718(void *arg0) {
    f32 temp_fv0;
    u16 temp_v0;
    s32 var_v0;
    void *temp_v0_2;
    void *temp_a0;
    void *temp_a0_2;
    s32 var_s0;

    temp_a0 = (*(void **)((char *)(arg0) + 0x34));
    if (((*(u8 *)((char *)(temp_a0) + 0x13)) != 0) && (!D_80102EDE) && (D_800BFC92 & 1)) {
        func_8002FBE4(temp_a0, arg0 + 0x40, arg0 + 0x42);
    }
    temp_v0 = (*(u16 *)((char *)(arg0) + 0x40)) + 1;
    (*(u16 *)((char *)(arg0) + 0x40)) = temp_v0;
    if ((u32) (temp_v0 & 0xFFFF) >= 0x38U) {
        (*(u16 *)((char *)(arg0) + 0x42)) = (u16) ((*(u16 *)((char *)(arg0) + 0x42)) == 0);
        (*(u16 *)((char *)(arg0) + 0x40)) = 0U;
    }
    if ((D_800BFC98 & 0xFFFF) == 5) {
        var_s0 = 0;
        var_v0 = 0 & 0xFFFF;
        do {
            var_v0 = var_s0 & 0xFFFF;
            func_8002E9D0((var_v0 * 0xC) + D_800E1590, 0xB);
            ++var_s0;
        } while ((u32) (var_s0 & 0xFFFF) < 9U);
        D_800BFC98 = 0;
    } else {
        ++D_800BFC98;
    }
    temp_v0_2 = (*(void **)((char *)(arg0) + 0x30));
    if (temp_v0_2 != NULL) {
        (*(f32 *)((char *)(temp_v0_2) + 0x40)) += 2.0f;
        temp_a0_2 = (*(void **)((char *)(arg0) + 0x30));
        temp_fv0 = (*(f32 *)((char *)(temp_a0_2) + 0x40));
        if (temp_fv0 > 4095.0f) {
            (*(f32 *)((char *)(temp_a0_2) + 0x40)) = (f32) (temp_fv0 - 4095.0f);
        }
    }
}
