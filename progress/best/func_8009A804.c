/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_800957A8();
s32 func_800957B8();
s32 func_80095818();
s32 func_8009846C();

typedef struct { unsigned char pad[180]; int value; } __repair_field_B4;
s32 func_8009A804(void *arg0, void *arg1, s32 arg2) {
    s32 temp_a0;
    register unsigned temp_v0;
s32 __repair_result_temp_v0;
    s32 var_s3;
    register u32 temp_v1;
    register u32 var_s0;
    u32 var_s1;
    u8 temp_v0_3;
    void *temp_v0_2;

    ((__repair_field_B4 *)arg0)->value = (s32) (*(u16 *)((char *)(arg1) + 4));
    if (((u32) (*(u16 *)((char *)(arg1) + 4)) >> 8) & 1) {
        do { func_800957A8(arg0 + 0xB4); } while (0);
    } else {
        func_800957B8(arg0 + 0xB4, arg0);
    }
    var_s3 = func_80095818(((__repair_field_B4 *)arg0)->value);
    if (var_s3 == 0) {
        var_s3 = 1;
    }
    var_s0 = ((u32) ((*(s32 *)((char *)(arg0) + 0x30)) * (*(u8 *)((char *)(arg1) + 2))) >> 7) + ((*(u8 *)((char *)(arg1) + 1)) << 0x10);
    if (var_s0 > 0x7F0000U) {
        var_s0 = 0x7F0000;
    }
    temp_a0 = (((u32) (*(u32 *)((char *)(arg1) + 0)) >> 0x18) | ((*(u8 *)((char *)(arg1) + 7)) << 8)) & 0xFFFF;
    var_s1 = var_s0;
    if (temp_a0 != 0) {
        __repair_result_temp_v0 = func_8009846C(temp_a0);
        temp_v1 = (unsigned)var_s0 >> 0x10;
        if (__repair_result_temp_v0 != 0) {
            if (temp_v1 < 0x7FU) {
                temp_v0_2 = temp_v1 + __repair_result_temp_v0;
                temp_v0 = (u8)((*(u8 *)((char *)(temp_v0_2) + 0)));
                var_s1 = (temp_v0 << 0x10) + (((*(u8 *)((char *)(temp_v0_2) + 1)) - (short)temp_v0) * (var_s0 & 0xFFFF));
            } else {
                var_s1 = *(u32 *)(temp_v0 + temp_v1) << 0x10;
            }
        }
    }
    (*(u32 *)((char *)(arg0) + 0x88)) = var_s1;
    (*(s32 *)((char *)(arg0) + 0x24)) |= 0x20000;
    (*(s32 *)((char *)(arg0) + 0x30)) = arg2;
    (*(s32 *)((char *)(arg0) + 0x84)) = (s32) ((s32) (var_s1 - arg2) / var_s3);
    return 0;
}
