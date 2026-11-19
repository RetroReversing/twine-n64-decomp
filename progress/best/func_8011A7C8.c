/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern unsigned char D_801002A0;
extern int D_801002B4;
extern char D_80102CD0[];
extern char D_8010A500[];
extern s32 D_8011F3A8;

void func_8011A7C8(void) {
    s16 temp_v0_5;
    int var_a0;
    int var_a0_2;
    s16 var_a0_3;
    s16 var_a0_4;
    s16 var_t0;
    s16 var_v0_2;
    s16 var_v0_4;
    s16 var_v0_7;
    s16 var_v0_9;
    s32 temp_a1;
    s32 temp_v0_2;
    s32 temp_v0_6;
    s16 var_v0;
    s32 var_v0_3;
    s32 var_v0_5;
    s32 var_v0_6;
    s16 var_v0_8;
    void **temp_v1;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v0_4;
    void *temp_v1_2;
    void *temp_v1_3;

    var_t0 = -1;
    if ((D_801002A0 == 8) && (var_a0 = 0, (D_801002B4 > 0))) {
        var_v0 = 0;
loop_3:
        temp_a1 = var_v0;
        temp_v1 = (temp_a1 * 4) + D_80102CD0;
        temp_v0 = *temp_v1;
        if (temp_v0 == NULL) {
            var_v0_2 = var_a0 + 1;
            goto block_16;
        }
        var_v0_2 = var_a0 + 1;
        if ((*(u8 *)((char *)((*(void **)((char *)(temp_v0) + 0xB4))) + 0x10)) == 7) {
            var_t0 = var_a0;
            var_a0_2 = 0;
            if (D_801002B4 > 0) {
                var_v0_3 = 0 << 0x10;
                do {
                    temp_v0_2 = var_v0_3 >> 0x10;
                    if ((temp_v0_2 != temp_a1) && (temp_v0_3 = *((temp_v0_2 * 4) + D_80102CD0), (temp_v0_3 != NULL))) {
                        var_v0_4 = var_a0_2 + 1;
                        if ((*(u8 *)((char *)((*(void **)((char *)(temp_v0_3) + 0xB4))) + 0x11)) == 0) {
                            temp_v1_2 = (*(void **)((char *)(*temp_v1) + 0xB4));
                            (*(u16 *)((char *)(temp_v1_2) + 0xC)) += 1;
                            goto block_13;
                        }
                    } else {
block_13:
                        var_v0_4 = var_a0_2 + 1;
                    }
                    var_a0_2 = var_v0_4;
                    var_v0_3 = var_a0_2 << 0x10;
                } while (var_v0_4 < D_801002B4);
                var_v0_5 = var_t0 << 0x10;
            } else {
                goto block_17;
            }
        } else {
block_16:
            var_a0 = var_v0_2;
            var_v0 = var_a0;
            if (var_v0_2 >= D_801002B4) {
                goto block_17;
            }
            goto loop_3;
        }
    } else {
block_17:
        var_v0_5 = var_t0 << 0x10;
    }
    if ((var_v0_5 >> 0x10) == -1) {
        var_a0_3 = 0;
        if (D_801002B4 > 0) {
            var_v0_6 = 0 << 0x10;
loop_21:
            temp_v0_4 = *((var_v0_6 >> 0xE) + D_8010A500);
            if (temp_v0_4 == NULL) {
                var_v0_7 = var_a0_3 + 1;
                goto block_26;
            }
            temp_v0_5 = (*(s16 *)((char *)(temp_v0_4) + 0x7A));
            var_v0_7 = var_a0_3 + 1;
            if ((temp_v0_5 < 2) & (temp_v0_5 != 6)) {
                var_t0 = var_a0_3;
            } else {
block_26:
                var_v0_6 = var_a0_3 << 0x10;
                var_a0_3 = var_v0_7;
                if (var_v0_7 < D_801002B4) {
                    goto loop_21;
                }
            }
            goto block_27;
        }
    } else {
block_27:
        var_a0_4 = 0;
        if (D_801002B4 > 0) {
            var_v0_8 = 0;
            do {
                temp_v0_6 = var_v0_8;
                if (temp_v0_6 != var_t0) {
                    temp_v1_3 = *((temp_v0_6 * 4) + D_8010A500);
                    var_v0_9 = var_a0_4 + 1;
                    if (temp_v1_3 != NULL) {
                        if ((*(u16 *)((char *)(temp_v1_3) + 0x78)) == 2) {
                            (*(s16 *)((char *)(temp_v1_3) + 0x7A)) = 2;
                        } else {
                            (*(s16 *)((char *)(temp_v1_3) + 0x7A)) = 6;
                        }
                        goto block_35;
                    }
                } else {
block_35:
                    var_v0_9 = var_a0_4 + 1;
                }
                var_v0_8 = var_a0_4;
                var_a0_4 = var_v0_9;
            } while (var_v0_9 < D_801002B4);
        }
    }
    if (var_t0 & 0x8000) {
        D_8011F3A8 = 0;
    }
}
