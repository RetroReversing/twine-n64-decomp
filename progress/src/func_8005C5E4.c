/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_80015DAC();
s32 func_800175C0();
s32 func_8005B5A8();
s32 func_8005C508();
s32 func_8007092C();
extern u8 gActorFlagTable[];

void func_8005C5E4(s32 arg0) {
    s32 var_s0;
    u16 temp_a0;
    u16 temp_v0;
    void *temp_s0;
    void *temp_v1;
    void *var_s1;

    var_s1 = func_80015DAC();
    var_s0 = 0;
    if (var_s1 != NULL) {
        do {
            if (((*(u16 *)((char *)(var_s1) + 0x78)) == 0x24) && ((temp_v1 = (*(void **)((char *)(var_s1) + 0x6C)), temp_v0 = (*(u16 *)((char *)(temp_v1) + 0x24)), (temp_v0 == 0)) || (*(gActorFlagTable + temp_v0) != 0))) {
                temp_a0 = (*(u16 *)((char *)(temp_v1) + 0x26));
                if ((temp_a0 == 1) && ((*(u16 *)((char *)(temp_v1) + 0x28)) == 3)) {
                    temp_s0 = var_s1 + 0x24;
                    func_800175C0((*(s32 *)((char *)(var_s1) + 0x20)), 2, 0x10000, temp_s0, 0, (s32) temp_a0);
                    func_8005C508(var_s1, temp_s0);
                    var_s0 = 1;
                    (*(s32 *)((char *)(var_s1) + 0x60)) |= 1;
                    if (arg0 != 0) {
                        func_8007092C(arg0, 1);
                    }
                }
            }
            var_s1 = (*(void **)((char *)(var_s1) + 0x10));
        } while (var_s1 != NULL);
    }
    if ((short)var_s0 == 0) {
        func_8005B5A8();
    }
}
