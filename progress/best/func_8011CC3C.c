/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

void *func_800162BC(s32);                           /* extern */
s32 func_80022DBC(s32);                             /* extern */
s32 func_800448A4(void *, s32, s32);        /* extern */
extern s32 D_800BD654;
extern s32 D_800BD678;
extern u8 D_801001A1[];
extern s32 D_801001A2;
extern u8 D_801002A1;
extern s32 D_801002C0;
extern s32 D_8011F338;

void func_8011CC3C(void) {
int __repair_literal;

    s32 var_v0;
    s32 var_s2;
    s32 var_a0;
    int var_s3;
    
    u32 temp_s0_2;
    u8 temp_s0;
    u8 temp_v1;
    register u8 temp_v1_2;
    register u8 temp_v1_3;
    void *temp_v0;

    var_s3 = 0;
    if (D_801002C0 > 0) {
        var_a0 = 0 & 0xFFFF;
        do {
            temp_v1 = *(&D_801001A2 + var_a0 * 0x6);
            if (temp_v1) {
                register var_s2 = 0;
__repair_literal = 4;

                if ((s32) temp_v1 >= (s32)__repair_literal) {
                    var_v0 = var_s3 & 0xFFFF;
                    if (temp_v1 == 5) {
                        var_s2 = 0;
                        goto block_6;
                    }
                    goto block_29;
                }
block_6:
                do {
                    if ((temp_v1 == 2) && (D_801002A1 == 1)) {
                        register temp_v1_2 = *(D_801001A1 + ((func_80022DBC(var_s3 & 0xFFFF) & 0xFFFF) * 0x18));
                        if (!(var_s2 & 1)) {
                            if (temp_v1_2 == 1) {
                                goto block_14;
                            }
                            goto block_25;
                        }
                        if ((unsigned)temp_v1_2 == 0) {
                            goto block_14;
                        }
                        goto block_25;
                    }
block_14:
                    if ((temp_v1 == 3) && (temp_s0 = D_801002A1, (temp_s0 == 1))) {
                        temp_v1_3 = *(D_801001A1 + ((func_80022DBC(var_s3 & 0xFFFF) & 0xFFFF) * 0x18));
                        if (var_s2 & 1) {
                            if (temp_v1_3 == 0) {
                                var_s2 += 1;
                            } else {
                                goto block_20;
                            }
                        } else {
                            if (temp_v1_3 != (u32)temp_s0) {
                                goto block_20;
                            }
                            goto block_25;
                        }
                    } else {
block_20:
                        temp_v0 = func_800162BC(var_s3 & 0xFFFF);
                        if (temp_v0 != NULL) {
                            temp_s0_2 = var_s2 & 0xFFFF;
                            func_800448A4(temp_v0, (-(temp_s0_2 < 2U) & 0x13) | 0x12, 0xF4);
                            (*(s32 *)((char *)((u32)temp_v0) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_v0) + 0x28)) & ~0xFC) | 0x10);
                            if (!(temp_s0_2 & 1)) {
                                (*(s32 *)((char *)(temp_v0) + 0x10)) = (s32) D_800BD678;
                            } else {
                                (*(s32 *)((char *)(temp_v0) + 0x10)) = (s32) D_800BD654;
                            }
                            *(((short)var_a0 * 4) + (((var_s2 & 0xFFFF) * 0x10) + &D_8011F338)) = temp_v0;
                        }
block_25:
                        ++var_s2;
                    }
                } while ((u32) (var_s2 & 0xFFFF) < 4U);
            } else {
                var_s2 = 0;
                var_v0 = var_s3 & 0xFFFF;
block_29:
                var_a0 = 0 & 0xFFFF;
                __repair_rows: { {
                    *((var_v0 * 4) + ((var_a0 * 0x10) + &D_8011F338)) = 0;
                    ++var_s2;
                    var_a0 = var_s2 & 0xFFFF;
                }
}
if ((u32) (var_s2 & 0xFFFF) < 4U) goto __repair_rows;
            }
            var_a0 = var_s3 & 0xFFFF;
            var_s3 += 1;
        } while ((var_s3 & 0xFFFF) < D_801002C0);
    }
}
