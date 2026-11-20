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

s32 func_800158A4(void *, s32, s32, M2C_UNK *, s32, s32, s32, s32, s32); /* extern */
M2C_UNK func_80045514(f32 *, f32, f32);             /* extern */
s32 func_8008194C(s8, M2C_UNK);                     /* extern */
f32 func_800828D0(f32);                             /* extern */
M2C_UNK func_800839F0(void *, M2C_UNK32 *, f32 *);  /* extern */
extern f32 D_800C7C98;
extern s32 gUpdateGateWord;
extern s32 D_80108F78;

void func_8006F974(void *arg0, void *arg1) {
    M2C_UNK32 sp28;
    f32 sp2C;
    M2C_UNK32 sp30;
    f32 sp38;
    f32 sp3C;
    f32 sp40;
    M2C_UNK sp48;
    f32 temp_fv1;
    f32 var_fs0;
    f32 var_fs1;
    f32 var_fs2;
    f32 var_fs4;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0;
    u16 temp_a0;
    u8 temp_a0_2;
    u8 temp_v1_3;
    void *temp_a1;
    void *temp_s3;
    void *temp_v0;
    void *var_s2;

    temp_v1 = M2C_FIELD(arg1, s32 *, 0x58);
    if ((temp_v1 & 0x400) && !(temp_v1 & 0x1000) && (temp_s3 = M2C_FIELD(arg0, void **, 0x138), (temp_s3 != NULL))) {
        var_fs4 = 2.0f;
        var_fs1 = 1.0f;
        temp_a1 = M2C_FIELD(temp_s3, void **, 0x6C);
        var_s2 = NULL;
        if (D_80108F78 == 0x19) {
            var_fs0 = M2C_FIELD(arg0, f32 *, 0x58) * M2C_FIELD(temp_a1, f32 *, 0x20);
            var_fs1 = 8.0f;
            var_fs4 = 8.0f;
            var_fs2 = M2C_FIELD(arg0, f32 *, 0x50) * -M2C_FIELD(temp_a1, f32 *, 0x1C);
            goto block_7;
        }
        if (!(M2C_FIELD(M2C_FIELD(temp_s3, void **, 0x68), u16 *, 0xC) & 1)) {
            var_fs0 = 0.0f;
            var_fs2 = 0.0f;
block_7:
            temp_a0 = M2C_FIELD(arg1, u16 *, 0x78);
            if (((temp_a0 == 1) | (temp_a0 == 0x4C)) != 0) {
                var_s2 = M2C_FIELD(arg1, void **, 0x6C);
                if ((func_8008194C(M2C_FIELD(temp_a1, s8 *, 0x182), 0xE) == 0) && (M2C_FIELD(arg1, u16 *, 0x78) == 0x4C)) {
                    M2C_FIELD(arg1, f32 *, 0x74) = -30.0f;
                }
                if (!(M2C_FIELD(arg1, f32 *, 0x74) <= -30.0f) && (M2C_FIELD(arg1, s16 *, 0x7A) != 0x75)) {
                    goto block_16;
                }
            } else if ((temp_a0 != 0x4D) && (temp_a0 != 0x61)) {
block_16:
                if ((var_s2 == NULL) || (temp_v1_2 = ((u32) M2C_FIELD(var_s2, u32 *, 0x88) >> 0x15) & 0xF, (temp_v1_2 == 1)) || (temp_v1_2 == 4)) {
                    if (gUpdateGateWord != 0) {
                        if (((u32) (M2C_FIELD(arg1, u16 *, 0x78) - 2) < 2U) && (temp_a0_2 = M2C_FIELD(M2C_FIELD(M2C_FIELD(temp_s3, void **, 0x6C), void **, 0xB4), u8 *, 0x12), (temp_a0_2 != 2))) {
                            if (temp_a0_2 != M2C_FIELD(M2C_FIELD(M2C_FIELD(arg1, void **, 0x6C), void **, 0xB4), u8 *, 0x12)) {
                                goto block_29;
                            }
                        } else {
                            goto block_29;
                        }
                    } else {
                        temp_v1_3 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x68), u8 *, 0xB1);
                        if ((s32) temp_v1_3 < 0x3C) {
                            var_v0 = 6;
                            if ((s32) temp_v1_3 < 0x3A) {
                                goto block_28;
                            }
                        } else {
                            var_v0 = 0x61;
block_28:
                            if (temp_v1_3 != var_v0) {
block_29:
                                sp28 = M2C_FIELD(arg1, M2C_UNK32 *, 0x24);
                                temp_v0 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x68), void **, 0);
                                sp2C = (M2C_FIELD(temp_v0, f32 *, 0x58) + M2C_FIELD(temp_v0, f32 *, 0xAC)) * 0.5f;
                                sp30 = M2C_FIELD(arg1, M2C_UNK32 *, 0x2C);
                                func_800839F0(arg0 + 0x88, &sp28, &sp38);
                                __asm__dummy();
                                sp38 += M2C_FIELD(arg0, f32 *, 0xAC);
                                sp3C += M2C_FIELD(arg0, f32 *, 0xB0);
                                temp_fv1 = sp40 + M2C_FIELD(arg0, f32 *, 0xB4);
                                sp40 = temp_fv1;
                                if ((temp_fv1 > 0.0f) && (temp_fv1 < M2C_FIELD(arg0, f32 *, 0x11C)) && (func_80045514(&sp38, M2C_FIELD(arg0, f32 *, 0x68) / temp_fv1, M2C_FIELD(arg0, f32 *, 0x6C) / temp_fv1), (func_800828D0(sp38 - var_fs2) < (M2C_FIELD(arg0, f32 *, 0x54) / var_fs4))) && (func_800828D0(sp3C - var_fs0) < (M2C_FIELD(arg0, f32 *, 0x5C) / var_fs1)) && ((func_800158A4(arg0 + 0x10, M2C_FIELD(M2C_FIELD(arg1, void **, 0x68), s32 *, 4) + 0xA8, M2C_FIELD(arg0, s32 *, 0xF4), &sp48, 0, 0, 0, 1, 0) << 0x18) != 0)) {
                                    M2C_FIELD(arg0, f32 *, 0x11C) = sp40;
                                    M2C_FIELD(arg0, M2C_UNK32 *, 0x104) = sp28;
                                    M2C_FIELD(arg0, f32 *, 0x108) = sp2C;
                                    M2C_FIELD(arg0, M2C_UNK32 *, 0x10C) = sp30;
                                    M2C_FIELD(arg0, f32 *, 0x114) = sp3C;
                                    if (D_80108F78 != 0x19) {
                                        if (!(sp40 < D_800C7C98)) {
                                            M2C_FIELD(arg0, f32 *, 0x110) = 0.0f;
                                            return;
                                        }
                                        goto block_38;
                                    }
block_38:
                                    M2C_FIELD(arg0, f32 *, 0x110) = sp38;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
