/* machine draft (m2c) for gcc-2.7.2-kmc -G0 -mips3 -mgp32 -mfp32 -O2, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

s32 func_8008CDC0();
s32 func_8008EB80();
s32 func_8008F2A4();
s32 func_80095A80();
s32 func_80095EC4();
extern char D_800E5AC4[];
extern u8 D_800E6A85[];
extern s32 D_800EDA90;
extern char D_80102FDC[];

s32 func_8008F520(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    char *var_a1_3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_s0;
    s32 temp_s4;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 var_a0;
    u8 var_a0_4;
    s32 var_a0_7;
    s32 var_a3;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_s1_6;
    s32 var_s1_7;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_4;
    s8 var_a0_3;
    s8 var_a0_5;
    u32 var_a2_4;
    u32 var_s5;
    char *var_a2_3;
    u8 *var_v1_3;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a3_3;
    u8 temp_v0_6;
    u8 temp_v1_2;
    u8 temp_v1_4;
    u8 var_a1;
    u8 var_a1_2;
    void *temp_a1;
    void *temp_a3;
    void *temp_a3_2;
    void *temp_s2;
    void *temp_t0;
    void *temp_v0;
    void *temp_v0_3;
    void *temp_v0_5;
    void *temp_v1;
    void *temp_v1_3;
    void *temp_v1_5;
    void *var_a0_6;
    void *var_a2;
    void *var_a2_2;
    void *var_s3;
    void *var_t1;
    void *var_v0_3;
    void *var_v1_2;

    var_s3 = arg2;
    var_s5 = 0;
    var_v1 = 0;
    for (;;) {
        if (*(D_800E6A85 + var_v1) == 0) {
            var_s5 += 1;
            var_v1 += 0xFF8;
            if (var_s5 >= 8U) {

            } else {
                continue;
            }
        }
        break;
    }
    if (var_s5 != 8) {
        temp_s2 = (var_s5 * 0xFF8) + D_800E5AC4;
        temp_a3 = (void *) ((8) + (s32) temp_s2);
        M2C_FIELD(temp_s2, void **, 4) = arg0;
        var_a2 = M2C_FIELD(temp_s2, void **, 4);
        M2C_FIELD(temp_s2, s8 *, 0xFF4) = 0;
        M2C_FIELD(temp_s2, void **, 0x88) = arg1;
        M2C_FIELD(temp_s2, void **, 0x10C) = arg3;
        {
            u8 __repair_i;
            for (__repair_i = 0; __repair_i < 0x80; __repair_i++) {
                *(s8 *)(temp_a3 + __repair_i) = 0xFF;
            }
        }
        var_a1 = M2C_FIELD(var_a2, u8 *, 5);
        var_a0_3 = 0;
        if ((var_a1 & 0xFF) != 0xFF) {
            do {
                var_a2 += 8;
                *(s8 *)(var_a1 + temp_a3) = var_a0_3;
                var_a1 = M2C_FIELD(var_a2, u8 *, 5);
                var_a0_3 += 1;
            } while (var_a1 != 0xFF);
        }
        temp_a3_2 = (void *) ((0x8C) + (s32) temp_s2);
        var_a2_2 = M2C_FIELD(temp_s2, void **, 0x88);
        for (var_a0_4 = 0; var_a0_4 < 0x80; var_a0_4++) {
            *(s8 *)(temp_a3_2 + var_a0_4) = 0xFF;
        }
        var_a1_2 = M2C_FIELD(var_a2_2, u8 *, 5);
        var_a0_5 = 0;
        if ((var_a1_2 & 0xFF) != 0xFF) {
            do {
                var_a2_2 += 8;
                *(s8 *)(var_a1_2 + temp_a3_2) = var_a0_5;
                var_a1_2 = M2C_FIELD(var_a2_2, u8 *, 5);
                var_a0_5 += 1;
            } while (var_a1_2 != 0xFF);
        }
        M2C_FIELD(temp_s2, u8 *, 0xFC4) = (u8) (var_s5 + 0x17);
        var_s1 = 0;
        do {
            temp_v0 = (void *) ((var_s1) + (s32) temp_s2);
            var_s1 += 1;
            M2C_FIELD(temp_v0, u8 *, 0x528) = (u8) M2C_FIELD(temp_s2, u8 *, 0xFC4);
        } while (var_s1 < 0x40);
        if (arg4 == NULL) {
            M2C_FIELD(temp_s2, s32 *, 0x110) = -1;
            M2C_FIELD(temp_s2, s32 *, 0x114) = -1;
            M2C_FIELD(temp_s2, u16 *, 0xFC2) = 0x100U;
        } else {
            if (M2C_FIELD(arg4, s32 *, 0) & 1) {
                M2C_FIELD(temp_s2, s32 *, 0x110) = (s32) M2C_FIELD(arg4, s32 *, 4);
                M2C_FIELD(temp_s2, s32 *, 0x114) = (s32) M2C_FIELD(arg4, s32 *, 8);
            } else {
                M2C_FIELD(temp_s2, s32 *, 0x110) = -1;
                M2C_FIELD(temp_s2, s32 *, 0x114) = -1;
            }
            if (M2C_FIELD(arg4, s32 *, 0) & 2) {
                M2C_FIELD(temp_s2, u16 *, 0xFC2) = (u16) M2C_FIELD(arg4, u16 *, 0xC);
            } else {
                M2C_FIELD(temp_s2, u16 *, 0xFC2) = 0x100U;
            }
            if (M2C_FIELD(arg4, s32 *, 0) & 8) {
                var_s1_2 = 0;
                if ((s32) M2C_FIELD(arg4, u8 *, 0x12) > 0) {
                    do {
                        temp_a0 = var_s1_2 * 2;
                        temp_v1 = temp_a0 + M2C_FIELD(arg4, s32 *, 0x14);
                        M2C_FIELD((temp_s2 + M2C_FIELD(temp_v1, u8 *, 0)), u8 *, 0x528) = (u8) M2C_FIELD(temp_v1, u8 *, 1);
                        func_8008F2A4(M2C_FIELD((temp_a0 + M2C_FIELD(arg4, s32 *, 0x14)), u8 *, 1), 0);
                        var_s1_2 += 1;
                    } while (var_s1_2 < (s32) M2C_FIELD(arg4, u8 *, 0x12));
                }
            }
            if (M2C_FIELD(arg4, s32 *, 0) & 4) {
                func_8008EB80(M2C_FIELD(arg4, u8 *, 0x10), M2C_FIELD(arg4, u16 *, 0xE), M2C_FIELD(temp_s2, u8 *, 0xFC4), 0, 0);
                var_s1_3 = 0;
                if ((s32) M2C_FIELD(arg4, u8 *, 0x18) > 0) {
                    do {
                        func_8008EB80(M2C_FIELD(arg4, u8 *, 0x10), M2C_FIELD(arg4, u16 *, 0xE), *(s32 *)(M2C_FIELD(arg4, s32 *, 0x1C) + var_s1_3), 0, 0);
                        var_s1_3 += 1;
                    } while (var_s1_3 < (s32) M2C_FIELD(arg4, u8 *, 0x18));
                }
            }
        }
        temp_a0_2 = M2C_FIELD(arg3, s32 *, 0x10);
        M2C_FIELD(temp_s2, s32 *, 0x124) = temp_a0_2;
        func_8008CDC0(temp_a0_2, var_s5 & 0xFF);
        temp_v0_2 = M2C_FIELD(arg3, s32 *, 0xC);
        temp_v0_3 = (void *) ((temp_v0_2) + (s32) arg3);
        if (temp_v0_2 != 0) {
            M2C_FIELD(temp_s2, void **, 0xF68) = temp_v0_3;
            M2C_FIELD(temp_s2, void **, 0xF6C) = temp_v0_3;
            M2C_FIELD(temp_s2, s32 *, 0xF70) = 0;
            M2C_FIELD(temp_s2, s32 *, 0xF74) = 0;
        } else {
            M2C_FIELD(temp_s2, void **, 0xF68) = NULL;
        }
        var_s1_4 = 0;
        M2C_FIELD(temp_s2, s8 *, 0xFC5) = 0;
        var_a0_6 = temp_s2;
        var_v1_2 = temp_s2;
        var_a1_3 = M2C_FIELD(arg3, s32 *, 0) + arg3;
        do {
            *(D_80102FDC + var_s1_4) = 0x7F;
            M2C_FIELD(var_v1_2, s32 *, 0x130) = 0;
            M2C_FIELD(var_v1_2, s32 *, 0x134) = 0;
            M2C_FIELD(var_a0_6, s32 *, 0x574) = 0;
            M2C_FIELD(var_a0_6, s32 *, 0x578) = 0;
            M2C_FIELD(var_a0_6, s32 *, 0x57C) = 0;
            temp_v0_4 = *(s32 *)var_a1_3;
            temp_v0_5 = (void *) ((temp_v0_4) + (s32) arg3);
            if (temp_v0_4 != 0) {
                M2C_FIELD(var_v1_2, void **, 0x128) = temp_v0_5;
                M2C_FIELD(var_v1_2, void **, 0x12C) = temp_v0_5;
            } else {
                M2C_FIELD(var_v1_2, void **, 0x128) = NULL;
                M2C_FIELD(var_v1_2, void **, 0x12C) = NULL;
            }
            var_a1_3 += 4;
            var_a0_6 += 0x28;
            var_s1_4 += 1;
            var_v1_2 += 0x10;
        } while (var_s1_4 < 0x40);
        var_s1_5 = 0;
        M2C_FIELD(temp_s2, s32 *, 0xF78) = 0;
        M2C_FIELD(temp_s2, s32 *, 0xF7C) = 0;
        var_a0_7 = 0 & 0xFF;
        do {
            func_80095EC4(var_a0_7, var_s5 & 0xFF, 0x7F);
            var_s1_5 += 1;
            var_a0_7 = var_s1_5 & 0xFF;
        } while (var_s1_5 < 0x10);
        var_s1_6 = 0xF;
        var_v0_3 = (void *) ((0x3C) + (s32) temp_s2);
        do {
            M2C_FIELD(var_v0_3, s32 *, 0xF80) = -1;
            var_s1_6 -= 1;
            var_v0_3 -= 4;
        } while (var_s1_6 >= 0);
        var_t1 = M2C_FIELD(temp_s2, void **, 4);
        var_v1_3 = (void *) ((8) + (s32) temp_s2);
        var_a3 = 0;
        do {
            var_a2_3 = var_v1_3;
            temp_t0 = (void *) ((0x80) + (s32) var_a2_3);
loop_45:
            temp_v0_6 = *(u8 *)var_a2_3;
            if (temp_v0_6 != 0xFF) {
                temp_a1 = (void *) (((temp_v0_6 * 8)) + (s32) var_t1);
                temp_a0_3 = M2C_FIELD(temp_a1, u8 *, 4);
                if (temp_a0_3 != 0xFF) {
                    M2C_FIELD(((temp_a0_3 * 4) + temp_s2), s32 *, 0xF80) = (s32) ((M2C_FIELD(temp_a1, u16 *, 0) << 0x10) | (M2C_FIELD(temp_a1, u8 *, 2) << 8) | M2C_FIELD(temp_a1, u8 *, 3));
                }
            }
            var_a2_3 += 1;
            if ((s32) var_a2_3 < (s32) temp_t0) {
                goto loop_45;
            }
            var_t1 = M2C_FIELD(temp_s2, void **, 0x88);
            var_a3 += 1;
            var_v1_3 = (void *) ((0x8C) + (s32) temp_s2);
        } while (var_a3 < 2);
        if (var_s3 != NULL) {
            var_s1_7 = 0;
            temp_s4 = var_s5 & 0xFF;
            do {
                temp_a0_4 = M2C_FIELD(var_s3, u8 *, 4);
                temp_a1_2 = var_s1_7 & 0xFF;
                if (temp_a1_2 != 9) {
                    temp_v1_2 = M2C_FIELD((temp_a0_4 + temp_s2), u8 *, 8);
                    if (temp_v1_2 != 0xFF) {
                        temp_v1_3 = (temp_v1_2 * 8) + M2C_FIELD(temp_s2, void **, 4);
                        M2C_FIELD(((temp_a1_2 * 4) + temp_s2), s32 *, 0xF80) = (s32) ((M2C_FIELD(temp_v1_3, u16 *, 0) << 0x10) | (M2C_FIELD(temp_v1_3, u8 *, 2) << 8) | M2C_FIELD(temp_v1_3, u8 *, 3));
                    }
                } else {
                    temp_v1_4 = M2C_FIELD((temp_a0_4 + temp_s2), u8 *, 0x8C);
                    if (temp_v1_4 != 0xFF) {
                        temp_v1_5 = (temp_v1_4 * 8) + M2C_FIELD(temp_s2, void **, 0x88);
                        M2C_FIELD(temp_s2, s32 *, 0xFA4) = (s32) ((M2C_FIELD(temp_v1_5, u16 *, 0) << 0x10) | (M2C_FIELD(temp_v1_5, u8 *, 2) << 8) | M2C_FIELD(temp_v1_5, u8 *, 3));
                    }
                }
                temp_s0 = var_s1_7 & 0xFF;
                temp_a1_3 = temp_s0;
                var_s1_7 += 1;
                func_80095A80(7, temp_a1_3, temp_s4, M2C_FIELD(var_s3, u8 *, 5));
                func_80095A80(0xA, temp_s0, temp_s4, M2C_FIELD(var_s3, u8 *, 6));
                func_80095A80(0x5B, temp_s0, temp_s4, M2C_FIELD(var_s3, u8 *, 7));
                temp_a3_3 = M2C_FIELD(var_s3, u8 *, 8);
                var_s3 += 8;
                func_80095A80(0x5D, temp_s0, temp_s4, temp_a3_3);
            } while (var_s1_7 < 0x10);
        }
        M2C_FIELD(temp_s2, s16 *, 0xFC6) = 0;
        if ((arg4 == NULL) || !(M2C_FIELD(arg4, s32 *, 0) & 0x10)) {
            M2C_FIELD(temp_s2, s8 *, 0xFC0) = 1;
        }
        do {
            var_a2_4 = 0;
            var_v1_4 = 0;
            var_a0 = D_800EDA90;
            D_800EDA90 = (var_a0 + 1) & 0x7FFFFFFF;
loop_63:
            if (*(D_800E6A85 + var_v1_4) != 0) {
                var_a2_4 += 1;
                goto block_70;
            }
            if (*(s32 *)(D_800E5AC4 + var_v1_4) == var_a0) {
                var_a0 = -1;
            } else {
                var_a2_4 += 1;
block_70:
                var_v1_4 += 0xFF8;
                if (var_a2_4 < 8U) {
                    goto loop_63;
                }
            }
        } while (var_a0 == -1);
        *(s8 *)(D_800E5AC4 + (var_s5 * 0xFF8)) = var_a0;
        M2C_FIELD(temp_s2, s8 *, 0xFC1) = 0;
        return var_a0;
    }
    return -1;
}
