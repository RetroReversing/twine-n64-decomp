static __inline__ int __repair_inline(s32 a, s32 b) { return a > b; }
/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */

extern int D_801002C0;
s32 func_80087100();
s32 sprintf();
extern s32 D_801002B4;
extern void *D_80102CD0;
extern char D_8011F15C[];
extern char D_8011F2B8[];
extern char D_8011F3E0[];
extern char D_8011F3E8[];

void func_8011D158(s16 arg0) {
short __repair_constant = 0x2E5;

    s32 var_a0;
    s32 var_a0_2;
    s32 temp_a1;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_v0;
    u8 temp_s2;
    void **temp_a1_2;
    void **temp_a0_2;
    
    void *temp_a0;
    void *temp_a0_3;
    void *temp_a2;
    void *temp_v1;

    if (arg0 < D_801002C0) {
        temp_a0 = (*(void **)((char *)((&D_80102CD0)[arg0]) + 0xB4));
        temp_s2 = (*(u8 *)((char *)(temp_a0) + 0x12));
        temp_a1_2 = &D_80102CD0;
        if (temp_s2 == 2) {
            var_a2 = D_801002B4;
            var_a1 = 0;
            if (__repair_inline(var_a2, 0)) {
                do {
                    var_a1 += 1;
                    if (var_a1 != arg0) {
                        temp_v1 = (*(void **)((char *)(*temp_a1_2) + 0xB4));
                        var_a2 -= ((*(u16 *)((char *)(temp_a0) + 0xC)) - (*(u16 *)((char *)(temp_a0) + 0xE))) >= ((*(u16 *)((char *)(temp_v1) + 0xC)) - (*(u16 *)((char *)(temp_v1) + 0xE)));
                    }
                    temp_a1_2 += 4;
                } while (var_a1 < (*(s32 *)((char *)(&D_801002C0) + -0xC)));
            }
            if (var_a2 != 2) {
                if (var_a2 < 3) {
                    var_a0 = __repair_constant;
                    if (var_a2 != 1) {
                        register var_a1_2 = arg0 << 0x10;
                    } else {
                        goto block_16;
                    }
                } else if (var_a2 != 3) {
                    var_a0 = 0x2E8;
                    if (var_a2 != 4) {
                        var_a1_2 = arg0 << 0x10;
                    } else {
                        goto block_16;
                    }
                } else {
                    var_a0 = 0x2E7;
                    goto block_16;
                }
            } else {
                var_a0 = 0x2E6;
block_16:
                sprintf((arg0 * 0xC) + D_8011F2B8, func_80087100(var_a0, (u8) var_a1, var_a2, temp_a1_2));
                var_a1_2 = arg0 << 0x10;
            }
            temp_a1 = var_a1_2 >> 0x10;
            temp_a0_2 = (temp_a1 * 4) + D_8011F3E8;
            temp_a2 = *temp_a0_2;
            (*(s32 *)((char *)(temp_a2) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_a2) + 0x28)) & ~0xFC) | 0xC);
            (*(s32 *)((char *)(*temp_a0_2) + 0x10)) = -1;
            *(s16 *)(D_8011F3E0 + (temp_a1 * 2)) = 0x3C;
            return;
        }
        var_a0_2 = 0x2E6;
        if (*((temp_s2 * 2) + D_8011F15C) >= *(((1 - temp_s2) * 2) + D_8011F15C)) {
            var_a0_2 = __repair_constant;
        }
        sprintf((arg0 * 0xC) + D_8011F2B8, func_80087100(var_a0_2, temp_s2, (s32) &D_80102CD0));
        temp_a1_2 = ((s32) (arg0 << 0x10) >> 0xE) + D_8011F3E8;
        temp_a0_3 = *temp_a1_2;
        (*(s32 *)((char *)(temp_a0_3) + 0x28)) = (s32) (((*(s32 *)((char *)(temp_a0_3) + 0x28)) & ~0xFC) | 0xC);
        if (temp_s2 == 0) {
            var_v0 = 0xFF2020FF;
        } else {
            register var_v0 = 0x2020FFFF;
        }
        (*(s32 *)((char *)(*temp_a1_2) + 0x10)) = var_v0;
        *(s16 *)(D_8011F3E0 + ((s32) (arg0 << 0x10) >> 0xF)) = 0x3C;
    }
}
