/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O1, tried by autopilot */

extern s16 *D_800AE4DC;
extern s16 D_800AE53C;

s32 func_80001E28(s32 arg0) {
    s16 **__base_D_800AE4DC;
    s16 **var_a1;
    s16 *var_v0;
    char *var_v1;
    char *var_v1_2;
    s32 var_a0;

    if ((u32) (arg0 - 0x2B) < 0x5EU) {
        __base_D_800AE4DC = &D_800AE4DC;
        var_a1 = __base_D_800AE4DC;
        var_v1 = &D_800AE53C;
        if ((short)(*__base_D_800AE4DC) != NULL) {
            var_v0 = (*__base_D_800AE4DC);
            for (;;) {
                var_a1 += 4;
                if (*var_v0 == arg0) {
                    var_v1_2 = var_v1 + 6;
                    var_a0 = 1;
                    if ((*(s16 *)((char *)(var_v1) + 6)) == 0xE) {
                        __repair_rows: {
                            var_v1_2 += 6;/*__repair_loop_weight*/do {
                            var_a0 += 1;} while (0);
                        }
if (*(s16 *)var_v1_2 == 0xE) goto __repair_rows;
                    }
                    return var_a0;
                }
                for (;;) {
                    if (*(s16 *)var_v1 < 0) {
                        break;
                    }
                    var_v1 += 6;
                }
                var_v0 = *var_a1;
                var_v1 += 2;
                if (var_v0 == NULL) {
                    /* Duplicate return node #13. Try simplifying control flow for better match */
                    return 0;
                }
                continue;
                break;
            }
        }
    }
    return 0;
}
