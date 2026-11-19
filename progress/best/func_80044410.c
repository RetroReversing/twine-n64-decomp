/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

s32 func_80084048(s8, s32, s32);                /* extern */
extern s32 D_800C0784;
extern s32 D_800C0788;
extern s32 D_800C078C;
extern u32 D_80100914;
extern u8 D_80109A35;

void func_80044410(s8 arg0) {
    s32 var_s2;
    u32 temp_v0_2;
    u32 var_s1;
    u32 var_s3;
    u8 temp_v0;
    u8 temp_v1;
    void *var_s0;

    if (D_80109A35 != 0) {
u32 __block_var_s3;

        __block_var_s3 = 0;
        if (D_80100914 != 0) {
            var_s2 = 0;
            do { {
                if (*((s32 *)((s8 *)&D_800C0784 + var_s2)) != 0) {
                    if (*((s32 *)((s8 *)&D_800C078C + (int)var_s2)) != 0) {
                        var_s0 = *((s32 *)((s8 *)&D_800C0788 + var_s2));
                        var_s1 = 0;
                        do { {
                            temp_v1 = (*(u8 *)((char *)(var_s0) + 0x46));
                            if (!(temp_v1 & 0x80)) {
                                temp_v0 = temp_v1 - 1;
                                if (temp_v1 != 0) {
                                    (*(u8 *)((char *)(var_s0) + 0x46)) = temp_v0;
                                    var_s3 = temp_v0 & 0xFF;
    temp_v0_2 = var_s3;
                                    if (temp_v0_2 == 0) {
                                        func_80084048(arg0, (*(s32 *)((char *)(var_s0) + 0)), 0x2E);
                                        (*(s32 *)((char *)(var_s0) + 0)) = 0;
                                    } else if ((arg0 != 0)) {
                                        if ((temp_v0_2 >= 5U)) {
                                            (*(u8 *)((char *)(var_s0) + 0x46)) = 0U;
                                        }
                                    }
                                }
                            }
                            var_s1 += 1;
                            var_s0 += 0x4C;
                        }
} while (var_s1 < (u32) *((s32 *)((s8 *)&D_800C078C + var_s2)));
                    }
                }
                __block_var_s3 += 1;
                var_s2 += 0x10;
            }
} while (__block_var_s3 < (u32) D_80100914);
        }
    }
}
