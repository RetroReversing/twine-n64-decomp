/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_8009846C();

s32 func_8009A70C(void *arg0, void *arg1) {
    s32 temp_a0;
    u32 temp_v0;
    unsigned long var_s0;
    void *temp_v0_2;
    u32 temp_v1;
    register u8 temp_v0_3;
    u32 temp_v1_2;

    if ((*(u8 *)((char *)(arg1) + 6)) == 0) {
        (*(u32 *)((char *)(arg0) + 0x30)) = (u32) ((u32) ((*(u32 *)((char *)(arg0) + 0x30)) * (*(u8 *)((char *)(arg1) + 2))) >> 7);
    } else {
        (*(u32 *)((char *)(arg0) + 0x30)) = (u32) ((u32) ((*(u32 *)((char *)(arg0) + 0x34)) * (*(u8 *)((char *)(arg1) + 2))) >> 7);
    }
    temp_v1 = (*(u32 *)((char *)(arg0) + 0x30)) + ((*(u8 *)((char *)(arg1) + 1)) << 0x10);
    (*(u32 *)((char *)(arg0) + 0x30)) = temp_v1;
    if (temp_v1 > 0x7F0000U) {
        (*(u32 *)((char *)(arg0) + 0x30)) = 0x7F0000U;
    }
    var_s0 = (*(u32 *)((char *)(arg0) + 0x30));
    temp_a0 = ((*(u8 *)((char *)(arg1) + 0)) | ((*(u8 *)((char *)(arg1) + 7)) << 8)) & 0xFFFF;
    if (temp_a0 != 0) {
        do { temp_v0 = func_8009846C(temp_a0); } while (0);
        temp_v1_2 = var_s0 >> 0x10;
        if (temp_v0 != 0) {
            if (temp_v1_2 < 0x7FU) {
u32 __repair_branch_temp_v0_0;

                __repair_branch_temp_v0_0 = var_s0 & 0xFFFF;
                temp_v0_2 = temp_v1_2 + __repair_branch_temp_v0_0;
                temp_v0_3 = (*(u8 *)((char *)(temp_v0_2) + 0));
    var_s0 = ((((*(u8 *)((char *)(temp_v0_2) + 1)) - temp_v0_3) * (__repair_branch_temp_v0_0))) + ((temp_v0_3 << 0x10));
            } else {
                var_s0 = *(u32 *)(temp_v0 + temp_v1_2) << 0x10;
            }
        }
    }
    (*(u32 *)((char *)(arg0) + 0x30)) = var_s0;
    return 0;
}
